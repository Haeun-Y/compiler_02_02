/*
* reporterror.c
* programmer - �ǿ���, ������, ������, �ֿ���
* date - 2023/06/01
*/

/*
* [illegal character ���� ó��]
* identifier�� illegal char�� ������ ��� ���� �м��� illegal char ������ �߻��ϰ�
* �������� identifier ���ڵ�� illegal char�� ������ ó���Ǿ� identifier�� ���� no comma ���� ������ �߻��ϰ� �ȴ�.
* ���� ��� int l@ve; �� ��� @�� ���� illegal char ������ �߻��ϱ� ������ 
* ������ ������ ���� comma �� �ʿ��ѵ� ���ٰ� �ν��ϰ� �Ǿ� nocomma ������ �߻��Ѵ�.
*/

/*
* [float ������ Ÿ�� ���� ó��]
* float�� Ű����� ó������ �ʾ� float�� �Է��� ��� identifier �� �ν��Ѵ�. 
* ���� float a; ó�� float�� ����� Ÿ���� �������ִ� ������ ����� ��� identifier identifier; �� �νĵǾ� nocomma ������ �߻��Ѵ�. 
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
		printf("line %3d      SCANNER ERROR! %s illegal character    \n", cLines, yytext);
		break;
	case illid_long:
		printf("line %3d      SCANNER ERROR! too long identifier    \n", cLines);
		break;
	case illid_digit:
		printf("line %3d      SCANNER ERROR! %s start with digit    \n", cLines, yytext);
		break;
	case real_num:
		printf("line %3d      SCANNER ERROR! real number is not allowed    \n", cLines);
		break;
	case overst:
		printf("line %3d      SCANNER ERROR! ST overflow    \n", cLines);
		break;
	case noparen:
		printf("line %3d      PARSER  ERROR! parenthesis is missed  \n", cLines);
		break;
	case nobrack:
		printf("line %3d      PARSER  ERROR! bracket is missed  \n", cLines);
		break;
	case notdefined:
		printf("line %3d      PARSER  ERROR! not defined identifier or function  \n", cLines);
		break;
	case wrongreturntype:
		printf("line %3d      PARSER  ERROR! function return type is wrong  \n", cLines);
		break;
	case nobrace:
		printf("line %3d      PARSER  ERROR! brace is missed  \n", cLines);
		break;
	case nocondition:
		printf("line %3d      PARSER  ERROR! condition statement is missed   \n", cLines);
		break;
	case nosemi:
		printf("line %3d      PARSER  ERROR! semicolon is missed  \n", cLines);
		break;
	case noop:
		printf("line %3d      PARSER  ERROR! operand is missed  \n", cLines);
		break;
	case nocomma:
		printf("line %3d      PARSER  ERROR! comma is missed   \n", cLines);
		break;
	case wrongst:
		printf("line %3d      PARSER  ERROR! statement is wrong   \n", cLines);
		break;
	case wrongparam:
		printf("line %3d      PARSER  ERROR! wrong parameter   \n", cLines);
		break;
	}

}