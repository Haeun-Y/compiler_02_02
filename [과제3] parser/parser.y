/* 2조 윤하은, 권영경, 옥진주, 최예원 */

%{
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
//#include "glob.h"

extern yylex();
extern yyerror();
void semantic(int);
%}

%token TIDENT TNUMBER TCONST TELSE TIF TEIF TINT TRETURN TVOID TWHILE
%token TADD TSUB TMUL TDIV TMOD TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TOR TAND TEQUAL TNOTEQU TGREATE TLESSE TGREAT TLESS TINC TDEC
%token TLPAREN TRPAREN TLBRACE TRBRACE TLBRACKET TRBRACKET
%token TCOMMA TSEMI TCOMMENT TERROR

%nonassoc TIF_ERROR TIF_CONDITON_ERROR
%nonassoc TELSE_ERROR TELSE_CONDITION_ERROR
%nonassoc UIF
%nonassoc TELSE

%%
mini_c 			: translation_unit				;
translation_unit 	: external_dcl
			| translation_unit external_dcl		        ;
external_dcl 		: function_def
		  	| declaration
		  	| TIDENT TSEMI
		  	| TIDENT error					{yyerrok; id_type=0; PrintError("Missing semicolon", linenum);}; //const int y = 10;
function_def 		: function_header compound_st
			| function_header TSEMI
			| function_header error				{yyerrok; id_type=0; PrintError("Missing semicolon", linenum);}
			| error compound_st				{yyerrok; PrintError("No function header", linenum);};
function_header 	: dcl_spec function_name formal_param	;
dcl_spec 		: dcl_specifiers				;
dcl_specifiers 		: dcl_specifier
		 	| dcl_specifiers dcl_specifier			;
dcl_specifier 		: type_qualifier
			| type_specifier				;
type_qualifier 		: TCONST				        {id_type=4;}
type_specifier 		: TINT						{id_type=1;}
			| TFLOAT					{id_type=2;}
		 	| TVOID						{id_type=3;};
function_name 		: TIDENT					{id=1;};
formal_param 		: TLPAREN opt_formal_param TRPAREN
			| TLPAREN opt_formal_param {yyerrok; PrintError("Not closed small bracket", linenum);}
			;
opt_formal_param 	: formal_param_list
		   	|						;
formal_param_list 	: param_dcl					{semantic(7);}
		    	| formal_param_list TCOMMA param_dcl 		{semantic(7);}
		    	| formal_param_list param_dcl			{yyerrok; id_type=0; PrintError("Missing comma", linenum);};
param_dcl 		: dcl_spec declarator				;
compound_st 		: TLBRACE opt_dcl_list opt_stat_list TRBRACE
			| TLBRACE opt_dcl_list opt_stat_list error   {yyerrok; PrintError("Not closed medium bracket", linenum);};
opt_dcl_list 		: declaration_list
			|						;
declaration_list 	: declaration
			| declaration_list declaration 			;
declaration 		: dcl_spec init_dcl_list TSEMI
			| dcl_spec init_dcl_list error 			{yyerrok; id_type=0; PrintError("Missing semicolon", linenum);};
init_dcl_list 		: init_declarator
			| init_dcl_list TCOMMA init_declarator
			| init_dcl_list init_declarator			{yyerrok; id_type=0; PrintError("Missing comma", linenum);};
init_declarator 	: declarator
		 	| declarator TIS TNUMBER
		 	| declarator TEQUAL TNUMBER			{yyerrok; id_type=0; PrintError("Declaring error", linenum);};
declarator 		: TIDENT					{semantic(5);}
           		| TIDENT TLBRACKET opt_number TRBRACKET		{semantic(6);}
           		| TIDENT TLBRACKET opt_number error		{yyerrok; id_type=0; PrintError("Not closed large bracket", linenum);}
           		| TINT TIDENT                                	{id=2;}  // 스칼라 int 변수
           		| TINT TIDENT TLBRACKET opt_number TRBRACKET  	{id=3;}  // int 배열 변수
           		| TFLOAT TIDENT                              	{id=4;}  // 스칼라 float 변수
           		| TFLOAT TIDENT TLBRACKET opt_number TRBRACKET 	{id=5;};  // float 배열 변수
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
			| expression error 				{yyerrok; id_type=0; PrintError("Missing semicolon", linenum);};
opt_expression 		: expression
		 	|						;
if_st 			: TIF TLPAREN expression TRPAREN statement %prec UIF
			| TIF TLPAREN TRPAREN statement            %prec TIF_CONDITION_ERROR {yyerrok; PrintError("No condition", linenum);}
			| TIF TLPAREN expression error statement   %prec TIF_ERROR {yyerrok; PrintError("Not closed", linenum);}
			| TIF TLPAREN expression TRPAREN statement TELSE statement
			| TIF TLPAREN TRPAREN statement TELSE statement  %prec TELSE_CONDITION_ERROR {yyerrok; PrintError("Not closed", linenum);} //
			| TIF TLPAREN expression error statement TELSE statement %prec TELSE_ERROR {yyerrok; PrintError("Not closed", linenum);}; //
while_st 		: TWHILE TLPAREN expression TRPAREN statement
			| TWHILE TLPAREN expression error statement	{yyerrok; PrintError("Not closed", linenum);}
			| TWHILE TLPAREN TRPAREN statement		{yyerrok; PrintError("No condition", linenum);}
			;
return_st 		: TRETURN opt_expression TSEMI
			| TRETURN opt_expression error        		{yyerrok; id_type=0; PrintError("Missing semicolon", linenum);};
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
			| additive_exp TADD error 		{yyerrok; PrintError("illegal end", linenum);}
			| additive_exp TSUB multiplicative_exp
			| additive_exp TSUB error		{yyerrok; PrintError("illegal end", linenum);}
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
	      		| postfix_exp TLBRACKET expression error	{yyerrok; PrintError("Not closed large bracket", linenum);}
	      		| postfix_exp TLPAREN opt_actual_param TRPAREN
	      		| postfix_exp TLPAREN opt_actual_param error    {yyerrok; PrintError("Not closed small bracket", linenum);}
	      		| postfix_exp TINC
	      		| postfix_exp TDEC	;
opt_actual_param 	: actual_param
		  	|			;
actual_param 		: actual_param_list     ;
actual_param_list 	: assignment_exp
		   	| actual_param_list TCOMMA assignment_exp	;
primary_exp 		: TIDENT						{semantic(5);}
	     		| TNUMBER
	     		| TLPAREN expression TRPAREN
	     		| TLPAREN expression error 			{yyerrok; PrintError("Not closed small bracket", linenum);}
%%

void semantic(int n)
{
	switch(n){
	//정의한 타입들은 symtable에서 처리
		case 1: id_type=1; break;	//int
		case 2: id_type=2; break; 	//float
		case 3: id_type=3; break;	//void
		case 4: id_type=4; break;	//const

		case 4: id=1; break;		//function name
		case 5: id=2; break;		//integer scalar variable
		case 6: id=3; break;		//integer array variable
		case 7: id=4; break;		//float scalar variable
		case 8: id=5; break;		//float array variable
	}
}


