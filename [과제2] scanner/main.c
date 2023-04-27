/* 
* main.c - 각 token에 대한 출력
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/04/27
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"

extern yylex();
extern char* yytext;
extern int lineNumber;
//extern int cErrors; 

void PrintHeading()
{
	printf("\n\n");
	printf("  -----------      ------------       ------------       ------------ \n");
	printf("  line Number       Token type            Token            ST-index   \n");
	printf("  -----------      ------------       ------------       ------------ \n");
	printf("\n");
}

/* Token의 Line number, type, 문자열을 출력하는 함수
	identifier의 경우 String Table에서의 index도 출력함 */
void PrintToken(enum tnumber tn)
{
	switch (tn) {
		printf("%5d", lineNumber);
		case TCONST: printf("%-20s %s\n", "const", yytext);  break;
		case TELSE: printf("%-20s %s\n", "else", yytext);  break;
        	case TIF: printf("%-20s %s\n", "if", yytext); break;
        	case TINT: printf("%-20s %s\n", "int", yytext); break;
        	case TRETURN: printf("%-20s %s\n", "return", yytext);  break;
        	case TVOID: printf("%-20s %s\n", "void", yytext);  break;
        	case TWHILE: printf("%-20s %s\n", "while", yytext); break;
        	case TADD: printf("%-20s %s\n", "add", yytext); break;
        	case TSUB: printf("%-20s %s\n", "subtract", yytext); break;
        	case TMUL: printf("%-20s %s\n", "multiply", yytext); break;
        	case TDIV: printf("%-20s %s\n", "divide", yytext); break;
        	case TMOD: printf("%-20s %s\n", "mod", yytext); break;
		case TNOT: printf("%-20s %s\n", "not", yytext); break;
		case TAND: printf("%-20s %s\n", "and", yytext);   break;
		case TOR: printf("%-20s %s\n", "or", yytext);   break;
        	case TEQUAL: printf("%-20s %s\n", "equal", yytext); break;
        	case TNOTEQU: printf("%-20s %s\n", "not_equal", yytext);   break;
		case TLESSE: printf("%-20s %s\n", "less_than", yytext);   break;
		case TGREATE: printf("%-20s %s\n", "greater_than", yytext);   break;
		case TINC: printf("%-20s %s\n", "increment", yytext);   break;
		case TDEC: printf("%-20s %s\n", "decrement", yytext);   break;
		case TASSIGN: printf("%-20s %s\n", "assign", yytext);   break;
		case TADDASSIGN: printf("%-20s %s\n", "add_assign", yytext);   break;
		case TSUBASSIGN: printf("%-20s %s\n", "sub_assign", yytext);   break;
		case TMULASSIGN: printf("%-20s %s\n", "mul_assign", yytext);   break;
		case TDIVASSIGN: printf("%-20s %s\n", "div_assign", yytext);   break;
		case TMODASSIGN: printf("%-20s %s\n", "mod_assign", yytext);   break;
		case TLPAREN: printf("%-20s %s\n", "left parenthesis", yytext);   break;
		case TRPAREN: printf("%-20s %s\n", "right parenthesis", yytext);   break;
		case TCOMMA: printf("%-20s %s\n", "comma", yytext);   break;
		case TLBRACE: printf("%-20s %s\n", "left brace", yytext);   break;
		case TRBRACE: printf("%-20s %s\n", "right brace", yytext);   break;
		case TLBRACKET: printf("%-20s %s\n", "left bracket", yytext);   break;
		case TRBRACKET: printf("%-20s %s\n", "right bracket", yytext);   break;
		case SEMI: printf("%-20s %s\n", "semicolon", yytext);   break;
		case TNUMBER: printf("%-20s %s\n", "number", yytext);   break;
        
		//TODO: overst 처리 논의
		case TIDENT: printf("%-20s %s %s\n", "identifier", yytext, nextid);   break;
		case TERROR: printf("%-20s %s\n", "**Error**", error_message);   break;
	}
}

//Token 인식하여 Token 및 에러 출력
void main()
{
	enum tnumber tn;
	
	PrintHeading();

	while ((tn=yylex()!=TEOF)) {
		//Token 출력
		printToken(tn);
	}

	if (cErros==0)
		printf("No errors detected \n");
	else
		printf("%d errors detected \n", cErrors);

	printf("================================================\n");
}
