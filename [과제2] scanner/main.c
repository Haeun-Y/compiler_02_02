#include <stdio.h>
#include <stdlib.h>
#include "tn.h"

extern yylex();
extern char* yytext;
extern int line;

//tn.h로 처리 필요 
//enum errorTypes { noerror, illid_digit, illid_long, illid_illch, overst };
//typedef enum errorTypes ERRORtypes;
//ERRORtypes err;

void PrintHeading()
{
	printf("\n\n");
	printf("  -----------      ------------       ------------       ------------ \n");
	printf("  Line number       Token type            Token             ST-index  \n");
	printf("  -----------      ------------       ------------       ------------ \n");
	printf("\n");
}

void PrintToken(enum tnumber tn)
{
	//여기서 line number, token type, token 다 출력
	//ST index는 gloabl 변수로 출력 
	switch (tn) {
		case TCONST: printf("%-16d %-20s %s\n", line, "const", yytext);  break;
		case TELSE: printf("%-16d %-20s %s\n", line, "else", yytext);  break;
        	case TIF: printf("%-16d %-20s %s\n", line, "if", yytext); break;
        	case TINT: printf("%-16d %-20s %s\n", line, "int", yytext); break;
        	case TRETURN: printf("%-16d %-20s %s\n", line, "return", yytext);  break;
        	case TVOID: printf("%-16d %-20s %s\n", line, "void", yytext);  break;
        	case TWHILE: printf("%-16d %-20s %s\n", line, "while", yytext); break;
        	case TEQUAL: printf("%-16d %-20s %s\n", line, "equal", yytext); break;
        	case TNOTEQU: printf("%-16d %-20s %s\n", line, "not_equal", yytext);   break;
		case TLESSE: printf("%-16d %-20s %s\n", line, "less_than", yytext);   break;
		case TGREATE: printf("%-16d %-20s %s\n", line, "greater_than", yytext);   break;
		case TAND: printf("%-16d %-20s %s\n", line, "and", yytext);   break;
		case TOR: printf("%-16d %-20s %s\n", line, "or", yytext);   break;
		case TINC: printf("%-16d %-20s %s\n", line, "increment", yytext);   break;
		case TDEC: printf("%-16d %-20s %s\n", line, "decrement", yytext);   break;
		case TADDASSIGN: printf("%-16d %-20s %s\n", line, "add_assign", yytext);   break;
		case TSUBASSIGN: printf("%-16d %-20s %s\n", line, "sub_assign", yytext);   break;
		case TMULASSIGN: printf("%-16d %-20s %s\n", line, "mul_assign", yytext);   break;
		case TDIVASSIGN: printf("%-16d %-20s %s\n", line, "div_assign", yytext);   break;
		case MODASSIGN: printf("%-16d %-20s %s\n", line, "mod_assign", yytext);   break;
		case TLPAREN: printf("%-16d %-20s %s\n", line, "left parenthesis", yytext);   break;
		case TRPAREN: printf("%-16d %-20s %s\n", line, "right parenthesis", yytext);   break;
		case TCOMMA: printf("%-16d %-20s %s\n", line, "comma", yytext);   break;
		case TLBRACE: printf("%-16d %-20s %s\n", line, "left brace", yytext);   break;
		case TRBRACE: printf("%-16d %-20s %s\n", line, "right brace", yytext);   break;
		case TLBRACKET: printf("%-16d %-20s %s\n", line, "left bracket", yytext);   break;
		case TRBRACKET: printf("%-16d %-20s %s\n", line, "right bracket", yytext);   break;
		case SEMI: printf("%-16d %-20s %s\n", line, "semicolon", yytext);   break;
		case TNUMBER: printf("%-16d %-20s %s\n", line, "number", yytext);   break;

        	case TIDENT: 
		//symboltable.c 함수에서 리턴한 ST 인덱스 추가해야 함
			printf("%-16d %-20s %s\n", line, "identifier", yytext); break;
				
		case TILLID_DIGIT: ReportError(illid_digit, yytext); break; 
		case TILLID_CHAR: ReportError(illid_illch, yytext); break; 
			//overst, illid_long 처리는 어떻게 할지?
	}
}

void main()
{
	enum tnumber tn;

	PrintHeading();

	while ((tn=yylex()!=TEOF)) {
		//Token 출력
		printToken(tn);

		line++;
	}
	if (cErros==0)
		printf("No errors detected \n");
	else
		printf("%d errors detected \n", cErrors);
	end if 

	printf("================================================\n");

}
