/*
* glob.h
* programmer - �ǿ���, ������, ������, �ֿ���
* date - 2023/06/01
*/

#define STsize 1000  //string table ũ��
#define HTsize 100	//hash table ũ��
#define FALSE 0
#define TRUE 1

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int lineNumber; //identifier�� �Էµ� line
    int type; //identifier�� ���� 
    int index;  //ST�� �ִ� identifier�� �ε���
    HTpointer next;  //���� identifier�� ����Ű�� ������
} HTentry;

HTpointer HT[HTsize];
char ST[STsize];

enum errorTypes { noerror, illch, illid_long, wrongreturntype, illid_digit, notdefined, real_num, overst, wrongst, nosemi, noparen, nobrack, nobrace, noop, nocomma, nocondition, wrongparam };
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

int cErrors; //���� ����
int startLineNumber; //�ּ� ���� ����
int cLines; //���� ����
int nextid;  //���� identifier
int nextfree;
int hashcode;
int sameid;  //first index of identifier
int found;  //for the previous occurrence of an identifier
int idttype; //identifier�� type 0~10
