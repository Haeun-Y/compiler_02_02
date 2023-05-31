#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

char* s;
void yyerror(char* s)
{
}

//오류 typed에 따른 error message 출력
void printError(ERRORtypes err)
{
	cErrors++;
	switch (err)
	{
	case noerror:
		cErrors--;
		break;
	case illch:
		printf("%d      ERROR! illegal character    \n", cLines);
		break;
	case illid_long:
		printf("%d      ERROR! too long identifier    \n", cLines);
		break;
	case illid_digit:
		printf("%d      ERROR! start with digit    \n", cLines);
		break;
	case real_num:
		printf("%d      ERROR! real number is not allowed    \n", cLines);
		break;
	case overst:
		printf("%d      ERROR! ST overflow    \n", cLines);
		break;
	case noparen:
		printf("%d      ERROR! parenthesis is missed  \n", cLines);
		break;
	case nobrack:
		printf("%d      ERROR! bracket is missed  \n", cLines);
		break;
	case nobrace:
		printf("%d      ERROR! brace is missed  \n", cLines);
		break;
	case nocondition:
		printf("%d      ERROR! if statement is missed   \n", cLines);
		break;
	case nosemi:
		printf("%d      ERROR! semicolon is missed  \n", cLines);
		break;
	case noop:
		printf("%d      ERROR! operand is missed  \n", cLines);
		break;
	case nocomma:
		printf("%d      ERROR! comma is missed   \n", cLines);
		break;
	case wrongst:
		printf("%d      ERROR! statement is wrong   \n", cLines);
		break;
	case wrongfdef:
		printf("%d      ERROR! fuction definition is wrong   \n", cLines);
		break;
	case wrongdec:
		printf("%d      ERROR! declaring error   \n", cLines);
		break;
	}

}