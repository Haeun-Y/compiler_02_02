/*
* reporterror.c
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern char* yytext;

char* s;
void yyerror(char* s)
{
}

void printError(ERRORtypes err)
{
	cErrors++;
	switch (err)
	{
		case illch:
			printf("line %d      SCANNER ERROR! %s illegal character    \n", cLines, yytext);
			break;
		case illid_long:
			printf("line %d      SCANNER ERROR! too long identifier    \n", cLines);
			break;
		case illid_digit:
			printf("line %d      SCANNER ERROR! %s start with digit    \n", cLines, yytext);
			break;
		case real_num:
			printf("line %d      SCANNER ERROR! real number is not allowed    \n", cLines);
			break;
		case overst:
			printf("line %d      SCANNER ERROR! ST overflow    \n", cLines);
			break;
		case noparen:
			printf("line %d      PARSER  ERROR! parenthesis is missed  \n", cLines);
			break;
		case nobrack:
			printf("line %d      PARSER  ERROR! bracket is missed  \n", cLines);
			break;
		case nobrace:
			printf("line %d      PARSER  ERROR! brace is missed  \n", cLines);
			break;
		case nocondition:
			printf("line %d      PARSER  ERROR! condition statement is missed   \n", cLines);
			break;
		case nosemi:
			printf("line %d      PARSER  ERROR! semicolon is missed  \n", cLines);
			break;
		case noop:
			printf("line %d      PARSER  ERROR! operand is missed  \n", cLines);
			break;
		case nocomma:
			printf("line %d      PARSER  ERROR! comma is missed   \n", cLines);
			break;
		case wrongst:
			printf("line %d      PARSER  ERROR! statement is wrong   \n", cLines);
			break;
		case wrongfdef:
			printf("line %d      PARSER  ERROR! fuction definition is wrong   \n", cLines);
			break;
		case wrongdec:
			printf("line %d      PARSER  ERROR! wrong declaration   \n", cLines);
			break;
	}

}