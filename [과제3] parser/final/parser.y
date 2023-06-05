/*
* parser.y
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

%{
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

extern yylex();
extern yyerror(s);

int type_int = 0;
int type_void = 0;
int type_param = 0;
int type_const = 0;

%}

%token TIDENT TNUMBER TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TOR TAND TEQUAL TNOTEQU TGREATE TLESSE TLESS TGREAT TINC TDEC
%token TSEMI TPLUS TMINUS TSTAR TSLASH TMOD TNOT
%token TLPAREN TRPAREN TLBRACE TRBRACE TLBRACKET TRBRACKET TCOMMA 
%token TERROR TCOMMENT
%nonassoc LOWER_THEN_ELSE
%nonassoc TELSE 
%nonassoc LOW
%nonassoc HIGH

%%
mini_c             : translation_unit   
               ;

translation_unit    : external_dcl         
               | translation_unit external_dcl
               ;

external_dcl       : function_def            
                 | declaration
                    | TCOMMENT      //함수 밖 주석을 인식한다.
               ;

function_def       : function_header compound_st   
                    | function_header TSEMI
                    | function_header error {yyerrok; printError(wrongst);} //compound_st에 에러가 있거나 semicoloin이 없는 경우 모두 wrongst로 처리한다.
               ;

function_header    : dcl_spec function_name {type_param = 1;} formal_param //formal_param으로 넘어오기 전에 type_param 임을 명시한다.
               | TIDENT function_name formal_param {yyerrok; printError(wrongreturntype);}
               ;

dcl_spec          : dcl_specifiers
               ;      

dcl_specifiers       : dcl_specifier            
                | dcl_specifiers dcl_specifier
               ;   

dcl_specifier       : type_qualifier            
               | type_specifier
               ;      

type_qualifier       : TCONST {type_const = 1;} //TCONST 토큰이 존재하는 경우 type_const 임을 명시한다.
               ;
               
type_specifier       : TINT {type_int = 1; type_void = 0;} //type_void는 0으로 초기화한다.
                | TVOID {type_void = 1; type_int = 0;} //type_int는 0으로 초기화한다.      
               ;      

function_name        : TIDENT
                  {   //identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
                     if (!found){ 
                        if(type_void == 1){
                           idttype = 3; //fuction name, return type = void
                                    HT[hashcode]->type = idttype;
                           type_void = 0;
                        }
                        if(type_int == 1){
                           idttype = 4; //fuction name, return type = int
                           HT[hashcode]->type = idttype;
                           type_int = 0;
                        }
                     }
                  }
               ;
                                   
formal_param       : TLPAREN opt_formal_param TRPAREN {type_param = 0;}
                    | TLPAREN opt_formal_param error {yyerrok;printError(noparen);}
               ;

opt_formal_param    : formal_param_list
                  |               
               ;

formal_param_list    : param_dcl          
                | formal_param_list TCOMMA param_dcl
               | formal_param_list param_dcl error {yyerrok; printError(nocomma);}
               ;

param_dcl 			: TVOID {type_void = 0;} //void 파라미터의 경우 declarator가 오지 않는다. ex) void (0), void hello (x)
					| TINT declarator {type_param = 1; idttype = 5; HT[hashcode]->type=idttype;} 
					| declarator error {yyerrok; printError(wrongparam);} //declarator만 있는 경우 에러 처리한다.
					;	 
               
compound_st       : TLBRACE opt_dcl_list opt_stat_list TRBRACE
               | TLBRACE opt_dcl_list opt_stat_list error {yyerrok; printError(nobrace);}
               ;

opt_dcl_list       : declaration_list      
               |
               ;   

declaration_list    : declaration      
               | declaration_list declaration 
                ;

declaration       : dcl_spec init_dcl_list TSEMI
               | dcl_spec init_dcl_list error {yyerrok; printError(nosemi);}
               ;

init_dcl_list       : init_declarator       
               | init_dcl_list TCOMMA init_declarator
               | init_dcl_list init_declarator {yyerrok; printError(nocomma);}
               ;
init_declarator    : declarator               
                | declarator TASSIGN TNUMBER
               | declarator TASSIGN TERROR //'int a = 0.2'와 같이 실수가 적힌 경우 scanner에서 TERROR 토큰을 반환받는다.
               ;

declarator          : TIDENT
               {
                  //identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
                  if (!found){
                     if(type_param == 1){
                        if(type_int == 1){
                           idttype = 5; //integer scalar fuction parameter
                           HT[hashcode]->type = idttype;
                           type_int = 0;
                        }
                        type_param = 0;
                      }
                     else{
                        if(type_int == 1){
                           idttype = 1; //integer scalar variable
                            HT[hashcode]->type = idttype;

                           if(type_const ==1){
                              idttype = 8; //integer scalar const
                              HT[hashcode]->type = idttype;
                              type_const = 0;
                           }
                           }
                     }
                  }
               }
                 | TIDENT TLBRACKET opt_number TRBRACKET      
               { 
                  //identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
                  if (!found){
                     if(type_param == 1 && type_int == 1){
                        idttype = 6; //integer array fuction parameter
                        HT[hashcode]->type = idttype;
                        type_param = 0;
                        type_int = 0;
                     }
                     else{
                        if(type_int == 1){
                           idttype = 2; //integer array variable
                           HT[hashcode]->type = idttype;

                           if(type_const ==1){
                              idttype = 9; //integer array const
                              HT[hashcode]->type = idttype;
                              type_const = 0;
                           }
                        }
                     }
                  }
               }
               | TIDENT TLBRACKET opt_number error {yyerrok; printError(nobrack);}
               | TERROR //허용되지 않는 identifier가 적힌 경우 scanner에서 TERROR 토큰을 반환받는다.
               ;

opt_number          : TNUMBER            
                 |          
               ;
               
opt_stat_list       : statement_list     
                |      
               ;
               
statement_list       : statement            
                | statement_list statement    
               | statement_list declaration    
               ;
               
statement          : compound_st         
                  | expression_st      
                  | if_st               
                  | while_st            
                  | return_st   
               | TCOMMENT //함수 내 주석을 인식한다.
                  ;

expression_st       : opt_expression TSEMI
               | expression error {yyerrok; printError(nosemi);};      
opt_expression       : expression 
               | opt_expression TCOMMA expression //'a, b, c;' 와 같은 문장을 인식한다.
                |         
               ;
            
if_st             : TIF TLPAREN expression TRPAREN statement %prec LOWER_THEN_ELSE
               | TIF TLPAREN expression TRPAREN statement TELSE statement    
               | TIF TLPAREN error TRPAREN {yyerrok; printError(nocondition);}
                | TIF TLPAREN expression error {yyerrok; printError(noparen);}
               ;

while_st          : TWHILE TLPAREN expression TRPAREN statement 
               | TWHILE TLPAREN expression error statement {yyerrok; printError(noparen);}
               | TWHILE TLPAREN error TRPAREN {yyerrok; printError(nocondition);}
               ;

return_st          : TRETURN opt_expression TSEMI
               | TRETURN opt_expression error {yyerrok; printError(nosemi);}
               ;

expression          : assignment_exp         
               ;

assignment_exp       : logical_or_exp         
               | unary_exp TASSIGN assignment_exp    
               | unary_exp TASSIGN error    {yyerrok; printError(noop);}
               | unary_exp TADDASSIGN assignment_exp    
               | unary_exp TADDASSIGN error {yyerrok; printError(noop);}
               | unary_exp TSUBASSIGN assignment_exp    
               | unary_exp TSUBASSIGN error {yyerrok; printError(noop);}
               | unary_exp TMULASSIGN assignment_exp 
               | unary_exp TMULASSIGN error {yyerrok; printError(noop);}
               | unary_exp TDIVASSIGN assignment_exp    
               | unary_exp TDIVASSIGN error {yyerrok; printError(noop);}
               | unary_exp TMODASSIGN assignment_exp 
               | unary_exp TMODASSIGN error {yyerrok; printError(noop);}
               ;
   
logical_or_exp      : logical_and_exp         
               | logical_or_exp TOR logical_and_exp    
               | logical_or_exp TOR error {yyerrok; printError(noop);}
               ;

logical_and_exp    : equality_exp            
                | logical_and_exp TAND equality_exp    
               | logical_and_exp TAND error {yyerrok; printError(noop);} 
               ;

equality_exp       : relational_exp         
               | equality_exp TEQUAL relational_exp 
               | equality_exp TEQUAL error {yyerrok; printError(noop);}
               | equality_exp TNOTEQU relational_exp    
               | equality_exp TNOTEQU error {yyerrok; printError(noop);}
               ;

relational_exp      : additive_exp          
               | relational_exp TLESS additive_exp    
               | relational_exp TLESS error {yyerrok; printError(noop);}
               | relational_exp TGREAT additive_exp 
               | relational_exp TGREAT error {yyerrok; printError(noop);}
               | relational_exp TGREATE additive_exp 
               | relational_exp TGREATE error {yyerrok; printError(noop);}
               | relational_exp TLESSE additive_exp    
               | relational_exp TLESSE error {yyerrok; printError(noop);}
               ;

additive_exp       : multiplicative_exp         
               | additive_exp TPLUS multiplicative_exp 
               | additive_exp TPLUS error {yyerrok; printError(noop);}
               | additive_exp TMINUS multiplicative_exp    
               | additive_exp TMINUS error {yyerrok; printError(noop);}
               ; 

multiplicative_exp    : unary_exp            
                | multiplicative_exp TSTAR unary_exp 
               | multiplicative_exp TSTAR error {yyerrok; printError(noop);}
                | multiplicative_exp TSLASH unary_exp 
               | multiplicative_exp TSLASH error {yyerrok; printError(noop);}
                | multiplicative_exp TMOD unary_exp 
               | multiplicative_exp TMOD error {yyerrok; printError(noop);}
               ;

unary_exp          : postfix_exp            
                  | TMINUS unary_exp   
               | TMINUS error {yyerrok; printError(noop);}
                  | TNOT unary_exp
               | TNOT error {yyerrok; printError(noop);}
                  | TINC unary_exp   
               | TINC error {yyerrok; printError(noop);}
                  | TDEC unary_exp   
               | TDEC error {yyerrok; printError(noop);}
               ;

postfix_exp       : primary_exp %prec LOW
               | TIDENT TIDENT {yyerrok; printError(nocomma);} %prec HIGH   //'float a;'와 같이 TIDENT가 연달아 오는 경우 에러 처리한다.         
                  | postfix_exp TLBRACKET expression TRBRACKET
                    | postfix_exp TLBRACKET expression error {yyerrok; printError(nobrack);}
                  | postfix_exp TLPAREN opt_actual_param TRPAREN
                  | postfix_exp TLPAREN opt_actual_param error {yyerrok; printError(noparen);}
                  | postfix_exp TINC         
                  | postfix_exp TDEC      
               ;   

opt_actual_param    : actual_param      
                 |         
               ;

actual_param       : actual_param_list      
               ;   

actual_param_list    : assignment_exp         
               | actual_param_list TCOMMA assignment_exp
               ;

primary_exp       : TIDENT
                  {
                     //identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
                     if (!found){
                        idttype = 10;
                                HT[hashcode]->type = idttype;
                        yyerrok; printError(notdefined);
                     }
                  }
                 | TNUMBER
                 | TLPAREN expression TRPAREN 
               | TLPAREN expression error {yyerrok; printError(noparen);} 
               | TERROR //'a = 0.2'와 같이 실수가 적힌 경우 scanner에서 TERROR 토큰을 반환받는다. 
               ;      
%%