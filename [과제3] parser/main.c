/*
* main.c - 메인 함수
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern yylex();
extern char* yytext;
extern int yyparse();

void main()
{
	/* 전역변수 초기화 */
	lineNumber = 1;
	startLineNumber = 0;
	cErrors = 0;
	nextid = 0;
	nextfree = 0;
	err = noerror;

	printf("==================================================================================\n");
	printf("start of parser\n");
	
	yyparse();

	printf("end of parser\n");
	printf("==================================================================================\n");

	if (cErrors == 0) {
		printf("no errors detected\n\n\n\n");
	}
	else printf("%d error(s) detected\n\n\n\n", cErrors);

	printf("hash table\n");
	printf("==================================================================================\n");
	/* HS테이블 출력*/
	printf("==================================================================================\n");

}
