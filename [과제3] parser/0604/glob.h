/*
* glob.h
* programmer - �ǿ���, ������, ������, �ֿ���
* date - 2023/06/01
*/

#define STsize 1000  //string table ũ��
#define HTsize 100	//hash table ũ��
#define IDlen 12 //idntifier �ִ� ����

#define FALSE 0
#define TRUE 1

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int lineNumber; //identifier�� �Էµ� line
    int type; //ident�� ���� 
    int index;  //ST�� �ִ� identifier�� idx
    HTpointer next;  //���� identifier ����Ű�� ������
} HTentry;

//���� type ���������� ����
enum errorTypes { noerror, illch, illid_long, illid_digit, real_num, overst, wrongst, wrongfdef, nosemi, noparen, nobrack, nobrace, noop, nocomma, nocondition, wrongdec};
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

extern void printError(ERRORtypes err);
extern void symtable();
extern char* yytext;
extern int yyleng;

HTpointer HT[HTsize];
char ST[STsize];

int startLineNumber;
int cErrors;
int cLines;

int nextid;  //the current identifier
int nextfree;  //the next available index of ST
int hashcode;  //hash code of identifier
int sameid;  //first index of identifier
int found;  //for the previous occurrence of an identifier

int idttype; //identifier�� type 0-8

