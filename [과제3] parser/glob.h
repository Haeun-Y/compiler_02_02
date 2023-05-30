/*
 * glob.h - global variable for the project
 */
#define STsize 1000
#define HTsize 100
#define FALSE 0
#define TRUE 1

typedef struct HTentry *HTpointer;
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

int nextid; 
int nextfree;
int hashcode; 
int sameid;
int num_err;//number of errors
int lineNumber;
//int i, j, cErrors; //?

int found;

enum errorTypes { noerror, illid_digit, illid_long, illid_illch, illid_illegal, overst };
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z' || (x) == '_') )
#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

#define MAX_LEN		12
