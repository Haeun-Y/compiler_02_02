
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern yylex();
extern char* yytext;
ERRORtypes err;

int startLineNumber = 0;
int cLines = 1;
int cErrors = 0;
int idfCnt = 0;
int idttype; //identifier�� type (0-8)

int hashcode;
int hashList[HTsize]={ 0 };

int hsidx = 0;
int found; //�̹� ���Ե� ident����
int idfidx = 0;  //���� identifier
int nextST = 0; //ST�� next idx
int sameidf;  //���� identifer idx

extern int yyparse();
extern void PrintHStable();

void main()
{

	cur = (HTpointer)malloc(sizeof(struct HTentry));
	cur_tmp = (HTpointer)malloc(sizeof(struct HTentry));

	printf("***MiniC parsing begins\n");

	yyparse();

	printf("Parsing ends\n");
	printf("%d error(s) detected\n", cErrors);

	PrintHStable();

}