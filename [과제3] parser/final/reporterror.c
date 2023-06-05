/*
* reporterror.c
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

/*
* [illegal character 오류 처리]
* identifier에 illegal char를 포함할 경우 어휘 분석시 illegal char 오류가 발생하고
* 정상적인 identifier 문자들과 illegal char가 별도로 처리되어 identifier에 대해 no comma 구문 오류가 발생하게 된다.
* 예를 들어 int l@ve; 인 경우 @에 대해 illegal char 오류가 발생하기 때문에 
* 나머지 구문을 보면 comma 가 필요한데 없다고 인식하게 되어 nocomma 에러가 발생한다.
*/

/*
* [float 데이터 타입 관련 처리]
* float는 키워드로 처리하지 않아 float를 입력할 경우 identifier 로 인식한다. 
* 따라서 float a; 처럼 float를 사용해 타입을 지정해주는 구문을 사용할 경우 identifier identifier; 로 인식되어 nocomma 에러가 발생한다. 
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