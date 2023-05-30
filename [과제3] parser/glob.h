/*
* glob.c - 전역변수 선언
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

#define STsize 1000
#define HTsize 100
#define FALSE 0
#define TRUE 1
#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z' || (x) == '_') )
#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

/*
* 심볼테이블, 해시테이블 관련 변수
*/
typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;
	char identType[100];//ex) scalar variable, function
	char dataType[100];//ex) integer | identType == function일 경우 함수 이름
	char returnType[100];//identType == function 일경우 유효, 그 외에는 '\0' 저장
	//  char[100] name;
	int lineNumber;
	HTpointer next;
} HTentry;

HTpointer HT[HTsize];
char ST[STsize];

int nextid;  //the current identifier
int nextfree;  //the next available index of ST
int hashcode;  //hash code of identifier
int sameid;  //first index of identifier
int found;  //for the previous occurrence of an identifier

/*
* lineNumber 관련 변수
*/
int lineNumber;//코드 lineNumber를 담는 변수
int startLineNumber;//주석 처리시 주석 시작 lineNumber를 담는 변수

/*
* error 관련 변수
*/
enum errorTypes { noerror, overst, illid_long, illch, illid_digit, real_num };
typedef enum errorTypes ERRORtypes;
ERRORtypes err;//에러 타입을 담는 변수
int cErrors; //총 에러 개수를 카운트하는 변수 (overflow인 경우를 제외하고 main에서 출력한다.)
char error_message[100]; //에러 메세지를 담는 변수 (메인에서 error_message를 출력한다.)
