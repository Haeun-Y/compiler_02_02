//전역변수 관리
#include "tn.h";

int lineNumber = 1;//코드 lineNumber를 담는 변수

//error 관련 변수
ERRORtypes err = noerror;//에러 타입을 담는 변수
int cErrors = 0; //총 에러 개수를 카운트하는 변수 (overflow인 경우를 제외하고 main에서 출력한다.)
char error_message[100]; //에러 메세지를 담는 변수 (메인에서 error_message를 출력한다.)

//symbolTable 관련 변수
HTpointer HT[HTsize];
char ST[STsize];
int nextid;  //the current identifier
int nextfree;  //the next available index of ST
int hashcode;  //hash code of identifier
int sameid;  //first index of identifier
int found;  //for the previous occurrence of an identifie
