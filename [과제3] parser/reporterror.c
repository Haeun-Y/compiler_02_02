#include <stdio.h>
#include "glob.h"


/* 
	yyerror(parser에서 발생한 에러 처리)

		lineNumber : 에러가 발생한 행
		sb		   : 에러 명(에러 문구)
		yytext	   : 에러가 발생한 문자

		ex) int num = 35
			=> line 3; no semicolon in 35

	ReportError(scanner에서 발생한 에러 처리)

		overst :  ST 내 overflow
		illid_digit    : start with digit
		illid_long	: too long identifier
		illch	: illegal characters
		real_num : real number

*/
yyerror(char* sb)
{
	cErrors++
	printf("line %d: %s in %s \n", lineNumber, sb, yytext);
}

void ReportError(ERRORtypes err)
{
	cErrors++;

	switch (err) {
		case overst:
			strcpy(error_message, "overflow");
			break;
		case illid_long:
			strcpy(error_message, "too long identifier");
			break;
		case illch:
			sprintf(error_message, "%s illegal character", yytext);
			break;
		case illid_digit:
			sprintf(error_message, "%s start with digit", yytext);
			break;
		case real_num:
			strcpy(error_message, "real number is not allowed");
			//실수가 들어올 경우 에러 발생. Floating Point 경우는 제외하였음.
			break;
		}
}
