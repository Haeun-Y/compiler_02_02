/*
* glob.h
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

#define STsize 1000  //string table 크기
#define HTsize 100	//hash table 크기
#define FALSE 0
#define TRUE 1

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int lineNumber; //identifier가 입력된 line
    int type; //identifier의 종류 
    int index;  //ST에 있는 identifier의 인덱스
    HTpointer next;  //다음 identifier를 가리키는 포인터
} HTentry;

HTpointer HT[HTsize];
char ST[STsize];

enum errorTypes { noerror, illch, illid_long, illid_digit, real_num, overst, wrongst, nosemi, noparen, nobrack, nobrace, noop, nocomma, nocondition, wrongparam};
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

int cErrors; //에러 개수
int startLineNumber; //주석 시작 라인
int cLines; //현재 라인
int nextid;  //현재 identifier
int nextfree;  
int hashcode;  
int sameid;  //first index of identifier
int found;  //for the previous occurrence of an identifier
int idttype; //identifier의 type 0~10

