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
extern yyerror();
extern char* yytext;

int type_int=0;
int type_void=0;
int param_int=0;
%}

%token TIDENT TNUMBER TCONST TELSE TIF TEIF TINT TRETURN TVOID TWHILE
%token TADD TSUB TMUL TDIV TMOD TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TOR TAND TEQUAL TNOTEQU TGREATE TLESSE TGREAT TLESS TINC TDEC
%token TLPAREN TRPAREN TLBRACE TRBRACE TLBRACKET TRBRACKET
%token TCOMMA TSEMI TCOMMENT TERROR

%nonassoc UIF
%nonassoc TIF_CONDITION_ERROR
%nonassoc TIF_ERROR
%nonassoc TELSE
%nonassoc TELSE_CONDITION_ERROR
%nonassoc TELSE_ERROR


%%
mini_c 			: translation_unit				;
translation_unit 	: external_dcl
			| translation_unit external_dcl		        ;
external_dcl 		: function_def
		  	| declaration
		  	| TIDENT TSEMI
		  	| TIDENT error					{yyerrok; printError(nosemi);}; //const int y = 10;
function_def 		: function_header compound_st
			| function_header TSEMI
			| function_header error				{cur_tmp->type=0; yyerrok; printError(nosemi);}
			| error compound_st				{yyerrok; printError(wrongfdef);};
function_header 	: dcl_spec function_name formal_param;
dcl_spec 		: dcl_specifiers				;
dcl_specifiers 		: dcl_specifier
		 	| dcl_specifiers dcl_specifier			;
dcl_specifier 		: type_qualifier
			| type_specifier				;
type_qualifier 		: TCONST				 ;       
type_specifier 		: TINT {type_int = 1;}									
		 	| TVOID		{type_void=1;}			;	
function_name 		: TIDENT
						{
							//type 0 : type이 지정되지 않은 상태
							if(cur->type==0){
								if(type_void==1){
									  cur->type=3; /* function, return type=void */
								}else if(type_int==1){
									  cur->type=4; /* function, return type=int */
								}
                    
								type_int=0;
								type_void=0;
								cur_tmp=cur;
							}
						}		;
formal_param 		: TLPAREN opt_formal_param TRPAREN
			| TLPAREN opt_formal_param {yyerrok; printError(noparen);}
			;
opt_formal_param 	: formal_param_list
		   	|						;
formal_param_list 	: param_dcl	
		    	| formal_param_list TCOMMA param_dcl 
		    	| formal_param_list param_dcl			{yyerrok; printError(nocomma);};
param_dcl 		: dcl_spec declarator				
					{
						if(type_int==1){ /* int로 설정된 경우 */
							param_int=1; 
							cur->type=5;  /* integer scalar parameter */
						  }
						  type_int=0;
						  type_void=0;
						  param_int=0;
					};
compound_st 		: TLBRACE opt_dcl_list opt_stat_list TRBRACE
			| TLBRACE opt_dcl_list opt_stat_list error   {yyerrok; printError(nobrace);};
opt_dcl_list 		: declaration_list
			|						;
declaration_list 	: declaration
			| declaration_list declaration 			;
declaration 		: dcl_spec init_dcl_list TSEMI{
							type_int=0;
							type_void=0;
						}
			| dcl_spec init_dcl_list error 			{
					cur->type=0;
					yyerrok; 
					type_int=0;
					type_void=0;
					printError(nosemi);
					};
init_dcl_list 		: init_declarator
			| init_dcl_list TCOMMA init_declarator
			| init_dcl_list init_declarator			{yyerrok; printError(nocomma);};
init_declarator 	: declarator
		 	| declarator TASSIGN TNUMBER
		 	| declarator TEQUAL TNUMBER			{yyerrok; printError(wrongdec);};
declarator 		: TIDENT {
					  if(cur->type==0){
							if(type_int==1){
								  cur->type=1; /* integer scalar variable */
							}    
					  }
					  cur_tmp=cur;
				}				
           		| TIDENT TLBRACKET opt_number TRBRACKET	{
					//array 변수
					if(cur->type==0){
                        if(type_int==1)cur->type=2; /* array integer variable */
					}
					   cur_tmp=cur;
				}
           		| TIDENT TLBRACKET opt_number error	{yyerrok; printError(nobrack);};
opt_number 		: TNUMBER
	     		|						;
opt_stat_list 		: statement_list
		 	|						;
statement_list 		: statement
		 	| statement_list statement
                        | statement_list declaration			;
statement 		: compound_st
	   		| expression_st
	   		| if_st
	   		| while_st
	   		| return_st
	   		;
expression_st 		: opt_expression TSEMI
			| expression error 				{yyerrok; printError(nosemi);};
opt_expression 		: expression
		 	|						;
if_st 			: TIF TLPAREN expression TRPAREN statement %prec UIF
			| TIF TLPAREN TRPAREN statement            %prec TIF_CONDITION_ERROR {yyerrok; printError(nocondition);}
			| TIF TLPAREN expression error statement   %prec TIF_ERROR {yyerrok; printError(noparen);}
			| TIF TLPAREN expression TRPAREN statement TELSE statement
			| TIF TLPAREN TRPAREN statement TELSE statement  %prec TELSE_CONDITION_ERROR {yyerrok; printError(nocondition);} //
			| TIF TLPAREN expression error statement TELSE statement %prec TELSE_ERROR {yyerrok; printError(noparen);}; //
while_st 		: TWHILE TLPAREN expression TRPAREN statement
			| TWHILE TLPAREN expression error statement	{yyerrok; printError(noparen);}
			| TWHILE TLPAREN TRPAREN statement		{yyerrok; printError(nocondition);}
			;
return_st 		: TRETURN opt_expression TSEMI			
			| TRETURN opt_expression error        		{yyerrok; printError(nosemi);};
expression 		: assignment_exp				;
assignment_exp 		: logical_or_exp
			| unary_exp TASSIGN assignment_exp
			| unary_exp TADDASSIGN assignment_exp
			| unary_exp TSUBASSIGN assignment_exp
			| unary_exp TMULASSIGN assignment_exp
			| unary_exp TDIVASSIGN assignment_exp
			| unary_exp TMODASSIGN assignment_exp
			;
logical_or_exp 		: logical_and_exp
			| logical_or_exp TOR logical_and_exp 	;
logical_and_exp 	: equality_exp
		 	| logical_and_exp TAND equality_exp 	;
equality_exp 		: relational_exp
			| equality_exp TEQUAL relational_exp
			| equality_exp TNOTEQU relational_exp 	;
relational_exp 		: additive_exp
			| relational_exp TGREAT additive_exp
			| relational_exp TLESS additive_exp
			| relational_exp TGREATE additive_exp
			| relational_exp TLESSE additive_exp	;
additive_exp 		: multiplicative_exp
			| additive_exp TADD multiplicative_exp
			| additive_exp TSUB multiplicative_exp;
multiplicative_exp 	: unary_exp
		    	| multiplicative_exp TMUL unary_exp
		    	| multiplicative_exp TDIV unary_exp
		    	| multiplicative_exp TMOD unary_exp	;
unary_exp 		: postfix_exp
	   		| TSUB unary_exp
	   		| TNOT unary_exp
	   		| TINC unary_exp
	   		| TDEC unary_exp			;
postfix_exp 		: primary_exp
	      		| postfix_exp TLBRACKET expression TRBRACKET
	      		| postfix_exp TLBRACKET expression error	{yyerrok; printError(nobrack);}
	      		| postfix_exp TLPAREN opt_actual_param TRPAREN
	      		| postfix_exp TLPAREN opt_actual_param error    {yyerrok; printError(noparen);}
	      		| postfix_exp TINC
	      		| postfix_exp TDEC	;
opt_actual_param 	: actual_param
		  	|			;
actual_param 		: actual_param_list     ;
actual_param_list 	: assignment_exp
		   	| actual_param_list TCOMMA assignment_exp	;
primary_exp 		: TIDENT{
						if(cur->type==0){
							 cur->type=7;
						}
					}					
	     		| TNUMBER
	     		| TLPAREN expression TRPAREN
	     		| TLPAREN expression error 			{yyerrok; printError(noparen);};
%%