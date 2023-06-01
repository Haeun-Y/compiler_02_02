//���������� �����ϴ� �������
#define STsize 1000  //string table ũ��
#define HTsize 100	//hash table ũ��
#define IDlen 12 //idntifier �ִ� ����

#define FALSE 0
#define TRUE 1

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int IDline; //identifier�� �Էµ� line **���Ӱ� �߰��� �κ� 
    int type; //ident�� ���� 
    int index;  //ST�� �ִ� identifier�� idx
    HTpointer next;  //���� identifier ����Ű�� ������
} HTentry;

//���� type ���������� ����
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

extern int idttype; //identifier�� type 0-8

