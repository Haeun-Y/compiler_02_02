//enum ����, ����ü ����, ��ũ�� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STsize 100  //size of string table
#define HTsize 100	//size of hash table

#define FALSE 0
#define TRUE 1

#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z' || (x) == '_') )
#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

#define MAX_LEN		12

typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;  //index of identifier in ST
	HTpointer next;  //pointer to next identifier
} HTentry;

enum tokentypes {
	TEOF,
	TERROR, TCOMMENT, TNUMBER, TIDENT,
	TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE,
	TADD, TSUB, TMUL, TDIV, TMOD,
	TASSIGN, TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN,
	TNOT, TAND, TOR,
	TEQUAL, TNOTEQU, TLESS, TLESSE, TGREAT, TGREATE,
	TINC, TDEC,
	TLPAREN, TRPAREN, TCOMMA, TLBRACE, TRBRACE, TLBRACKET, TRBRACKET, TSEMI
};
enum errorTypes { noerror, illid_digit, illid_long, illid_illch, overst };
typedef enum errorTypes ERRORtypes;

//symboltable.c ��������
extern HTpointer HT[HTsize];
extern char ST[STsize];

extern int nextid;  //the current identifier
extern int nextfree;  //the next available index of ST
extern int hashcode;  //hash code of identifier
extern int sameid;  //first index of identifier

extern int found;  //for the previous occurrence of an identifie

extern int lineNumber;

//error ���� ��������
extern ERRORtypes err;
extern int cErrors;
extern char error_message[100];

//lex ���� ����
extern char* yytext;
extern int yyleng;

//�ܺ� �Լ� ����
extern void SymbolTable();
extern void ReportError(ERRORtypes err);




