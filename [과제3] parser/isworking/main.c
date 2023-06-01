
#include <stdio.h>
#include <stdlib.h>
/*
* main.c
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

#include "tn.h"
#include "glob.h"

extern yylex();
extern char* yytext;
extern int yyparse();
extern void PrintHStable();

void main()
{
	startLineNumber = 0;
	cLines = 1;
	cErrors = 0;
	nextid = 0;
	nextfree = 0;
	idttype = 0;
	err = noerror;

	printf("********************************************************************\n");
	printf("\t\t\t [[   Mini C   ]] \n");
	printf("********************************************************************\n\n");
	printf("Parsing begins...\n");

	yyparse();

	printf("Parsing ends...\n");
	printf("********************************************************************\n");

	printf("%d error(s) detected\n\n", cErrors);

	PrintHStable();

}