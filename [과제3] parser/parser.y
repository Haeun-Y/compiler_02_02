/*
* parser.y
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "glob.h"

extern yylex();
extern char* yytext;
extern SymbolTableUpdate();

void semantic(int);
char identifierName[100];
char returnType[100];
char type[100];
char name[10];
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
		  	| TIDENT error					{yyerrok; PrintError("Missing semicolon");}; //const int y = 10;
function_def 		: function_header compound_st
			| function_header TSEMI
			| function_header error				{yyerrok; PrintError("Missing semicolon");}
			| error compound_st				{yyerrok; PrintError("No function header");};
function_header 	: dcl_spec function_name formal_param	{strcpy(returnType,$1); strcpy(identifierName, $2); semantic(3);};
dcl_spec 		: dcl_specifiers				;
dcl_specifiers 		: dcl_specifier			{strcpy(name, "scalar variable");};				
		 	| dcl_specifiers dcl_specifier		{strcpy(name, "scalar const");};
dcl_specifier 		: type_qualifier
			| type_specifier				
type_qualifier 		: TCONST				 ;       
type_specifier 		: TINT						{type=$$}
		 	| TVOID						{type=$$};
function_name 		: TIDENT					;
formal_param 		: TLPAREN opt_formal_param TRPAREN
			| TLPAREN opt_formal_param {yyerrok; PrintError("Not closed small bracket");}
			;
opt_formal_param 	: formal_param_list
		   	|						;
formal_param_list 	: param_dcl					
		    	| formal_param_list TCOMMA param_dcl 		
		    	| formal_param_list param_dcl			{yyerrok; PrintError("Missing comma");}
param_dcl 		: dcl_spec declarator				{strcpy(identifierName,$2); semantic(1);};
compound_st 		: TLBRACE opt_dcl_list opt_stat_list TRBRACE
			| TLBRACE opt_dcl_list opt_stat_list error   {yyerrok; PrintError("Not closed medium bracket");};
opt_dcl_list 		: declaration_list
			|						;
declaration_list 	: declaration
			| declaration_list declaration 			;
declaration 		: dcl_spec init_dcl_list TSEMI			{semantic(1);}
			| dcl_spec init_dcl_list error 			{yyerrok; PrintError("Missing semicolon");};
init_dcl_list 		: init_declarator				
			| init_dcl_list TCOMMA init_declarator
			| init_dcl_list init_declarator			{yyerrok; PrintError("Missing comma");};
init_declarator 	: declarator					
		 	| declarator TASSIGN TNUMBER			
		 	| declarator TEQUAL TNUMBER			{yyerrok; PrintError("Declaring error");};
declarator 		: TIDENT					{strcpy(identifierName,$$);}
           		| TIDENT TLBRACKET opt_number TRBRACKET	{strcpy(name, "array variable"); strcpy(identifierName,$1);}
           		| TIDENT TLBRACKET opt_number error	{yyerrok; PrintError("Not closed large bracket");};
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
			| expression error 				{yyerrok; PrintError("Missing semicolon");};
opt_expression 		: expression
		 	|						;
if_st 			: TIF TLPAREN expression TRPAREN statement %prec UIF
			| TIF TLPAREN TRPAREN statement            %prec TIF_CONDITION_ERROR {yyerrok; PrintError("No condition");}
			| TIF TLPAREN expression error statement   %prec TIF_ERROR {yyerrok; PrintError("Not closed");}
			| TIF TLPAREN expression TRPAREN statement TELSE statement
			| TIF TLPAREN TRPAREN statement TELSE statement  %prec TELSE_CONDITION_ERROR {yyerrok; PrintError("No condition");} //
			| TIF TLPAREN expression error statement TELSE statement %prec TELSE_ERROR {yyerrok; PrintError("Not closed");}; //
while_st 		: TWHILE TLPAREN expression TRPAREN statement
			| TWHILE TLPAREN expression error statement	{yyerrok; PrintError("Not closed");}
			| TWHILE TLPAREN TRPAREN statement		{yyerrok; PrintError("No condition");}
			;
return_st 		: TRETURN opt_expression TSEMI			
			| TRETURN opt_expression error        		{yyerrok; PrintError("Missing semicolon");};
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
			| additive_exp TADD error 		{yyerrok; PrintError("illegal end");}
			| additive_exp TSUB multiplicative_exp
			| additive_exp TSUB error		{yyerrok; PrintError("illegal end");}
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
	      		| postfix_exp TLBRACKET expression error	{yyerrok; PrintError("Not closed large bracket");}
	      		| postfix_exp TLPAREN opt_actual_param TRPAREN
	      		| postfix_exp TLPAREN opt_actual_param error    {yyerrok; PrintError("Not closed small bracket");}
	      		| postfix_exp TINC
	      		| postfix_exp TDEC	;
opt_actual_param 	: actual_param
		  	|			;
actual_param 		: actual_param_list     ;
actual_param_list 	: assignment_exp
		   	| actual_param_list TCOMMA assignment_exp	;
primary_exp 		: TIDENT						
	     		| TNUMBER
	     		| TLPAREN expression TRPAREN
	     		| TLPAREN expression error 			{yyerrok; PrintError("Not closed small bracket");}
%%

void semantic(int n)
{
	switch(n){
	//정의한 타입들은 symtable에서 처리
		case 1: SymbolTableUpdate(identifierName, name, type, "\0"); break;	//scalar variable, function parameter
		case 3: SymbolTableUpdate(identifierName, "function", identifierName, returnType); break;		//function name
	}
}
