//전역변수들 정의하는 헤더파일
#define STsize 1000  //string table 크기
#define HTsize 100	//hash table 크기
#define IDlen 12 //idntifier 최대 길이

#define FALSE 0
#define TRUE 1

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int IDline; //identifier가 입력된 line **새롭게 추가한 부분 
    int type; //ident의 종류 
    int index;  //ST에 있는 identifier의 idx
    HTpointer next;  //다음 identifier 가리키는 포인터
} HTentry;

//오류 type 열거형으로 정의
enum errorTypes { noerror, illch, illid_long, illid_digit, real_num, overst, wrongst, wrongfdef, nosemi, noparen, nobrack, wrongdec, nobrace, noround, noop, nocomma, nocondition};
typedef enum errorTypes ERRORtypes;

extern void printError(ERRORtypes err);
extern void symtable();

extern int hashList[HTsize];
extern int hsidx;

HTpointer HT[HTsize];
HTpointer cur;
HTpointer cur_tmp;
char ST[STsize];

extern int startLineNumber;
extern int cErrors;
extern int cLines;
extern char* yytext;
extern int yyleng;
extern ERRORtypes err;

extern int idfCnt;
extern int hashcode;
extern int found;
extern int idfidx;
extern int nextST;
extern int sameidf;

extern int idttype; //identifier의 type 0-8

