/*
* glob.c - �������� ����
* programmer - �ǿ���, ������, ������, �ֿ���
* date - 2023/04/27
*/
#include "tn.h";

//lineNumber ���� ����
int lineNumber = 1;//�ڵ� lineNumber�� ��� ����
int startLineNumber = 0;//�ּ� ó���� �ּ� ���� lineNumber�� ��� ����

//error ���� ����
ERRORtypes err = noerror;//���� Ÿ���� ��� ����
int cErrors = 0; //�� ���� ������ ī��Ʈ�ϴ� ���� (overflow�� ��츦 �����ϰ� main���� ����Ѵ�.)
char error_message[100]; //���� �޼����� ��� ���� (���ο��� error_message�� ����Ѵ�.)

//symbolTable ���� ����
HTpointer HT[HTsize];
char ST[STsize];
int nextid;  //the current identifier
int nextfree;  //the next available index of ST
int hashcode;  //hash code of identifier
int sameid;  //first index of identifier
int found;  //for the previous occurrence of an identifie
