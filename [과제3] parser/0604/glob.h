/*
* glob.h
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

#define STsize 1000  //string table 크기
#define HTsize 100	//hash table 크기
#define IDlen 12 //idntifier 최대 길이

#define FALSE 0
#define TRUE 1

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int lineNumber; //identifier가 입력된 line
    int type; //ident의 종류 
    int index;  //ST에 있는 identifier의 idx
    HTpointer next;  //다음 identifier 가리키는 포인터
} HTentry;

//오류 type 열거형으로 정의
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

int idttype; //identifier의 type 0-8

