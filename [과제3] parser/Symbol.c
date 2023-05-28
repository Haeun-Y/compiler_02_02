/*
 * Symbol.c - Symbol table management
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"

void PrintError(ERRORtypes err);
extern char *yytext;
extern int yyleng;

/*
typedef struct HTentry *HTpointer;
typedef struct HTentry {
	int index;
	char[100] identType;//ex) scalar variable, function
    char[100] dataType;//ex) integer | identType == function일 경우 함수 이름
    char[100] returnType;//identType == function 일경우 유효, 그 외에는 '\0' 저장
  //  char[100] name;
    int lineNumber;
	HTpointer next;
} HTentry;

*/


char print_ST[STsize];	//ST for printing the results
int p_nextfree = 0;		//nextfree of print_ST
int str_length;			//count length of string to print the results nicely

/*
 * computeHS() - Compute the hash code of identifier by summing the ordinal values of 
 *             its charactors an then taking the sum modulo the size of HT
 */
void ComputeHS(int nid,int nfree)
{
	int code, i;
	code = 0;
	for (i = nid; i < nfree - 1; i++) {
		int current = (int)ST[i];
		//If current is lowercase, convert it to uppercase
		current = (current >= 'A' && current <= 'Z' ? current - 'A' + 'a' : current);
		code += current;
	}
	hashcode = (code % HTsize) + 1;
	hashcode = (hashcode == HTsize ? 0 : hashcode);
}
void ComputeHSForString(char * str)
{
	int code, i;
	code = 0;
	for (i = 0; i < strlen(str); i++) {
		int current = (int)str[i];
		//If current is lowercase, convert it to uppercase
		current = (current >= 'A' && current <= 'Z' ? current - 'A' + 'a' : current);
		code += current;
	}
	hashcode = (code % HTsize) + 1;
	hashcode = (hashcode == HTsize ? 0 : hashcode);
}
/*
 * LookupHS() - For each identifier, Look it up in the hashtable for previous occurrence
 *              of the identifier. If fine a match, set the found flag as true. Otherwise flase.
 *              If fine a match, save the starting index of ST in same id
 */
void LookupHS(int nid,int hscode)
{
	HTpointer here;
	int i, j;

	found = FALSE;
	if (HT[hscode] != NULL) {
		here = HT[hscode];
		while (here != NULL && found == FALSE) {
			found = TRUE;
			i = here->index;
			j = nid;
			sameid = i;

			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				int left = ST[i] >= 'A' && ST[i] <= 'Z' ? ST[i] - 'A' + 'a' : ST[i];
				int right = ST[j] >= 'A' && ST[j] <= 'Z' ? ST[j] - 'A' + 'a' : ST[j];
				if (left != right)
					found = FALSE;
				else {
					i++;
					j++;
				}
			}
			here = here->next;
		}
	}
}
HTpointer LookupHSForUpdate(char* str,int hscode)
{
	HTpointer here;
	int i, j;

	found = FALSE;
	if (HT[hscode] != NULL) {
		here = HT[hscode];
		while (here != NULL && found == FALSE) {
			found = TRUE;
			i = here->index;
			j = 0;
			sameid = i;

			while (ST[i] != '\0' && str[j] != '\0' && found == TRUE) {
				int left = ST[i] >= 'A' && ST[i] <= 'Z' ? ST[i] - 'A' + 'a' : ST[i];
				int right = str[j] >= 'A' && str[j] <= 'Z' ? str[j] - 'A' + 'a' : str[j];
				if (left != right)
					found = FALSE;
				else {
					i++;
					j++;
				}
			}
			if(found == TRUE) return here;
			here = here->next;
		}

	}
}

/*
 * ADDHT() - Add a new identifier to the hash table.
 *           If list head ht[hashcode] is null, simply add a list element with
 *           starting index of the identifier in ST.
 *           If list head is not a null, it adds a new identifier to the head of the chain
 */
void ADDHT(int hscode)
{
	HTpointer ptr;

	ptr = (HTpointer)malloc(sizeof(ptr));
	ptr->index = nextid;
	ptr->next = HT[hscode];
	HT[hscode] = ptr;
}
//find existing identfier in HT and update identifier properties
void updateHT(HTpointer cur, char* identType, char* dataType, char* returnType)
{
	for(int i = 0; i<strlen(identType); i++)
		cur->identType[i] = identType[i];

	for(int i = 0; i<strlen(dataType); i++)
		cur->dataType[i] = dataType[i];
	
	for(int i = 0; i<strlen(returnType); i++)
		cur->returnType[i] = returnType[i];
}

/*
 * SymbolTable() - If read the identifier, symbol table management 
 */
//nextfree, nextid global variable 처리한 것처럼 ident 정보도 variable 처리할 것인지??
//parser.y 에서 identifier 속성 업데이트시 뭐로 접근해야 하는지? 
//scanner.l에서 yytext로 읽은것처럼 $1 이런거에 접근하려면 그냥 문자열 자체를 호출할 때 넘겨줄 것인지??
//call from parser.y
void SymbolTableUpdate(char* str, char* identType, char* dataType, char* returnType) 
{
	//err = noerror;
	//여기서는 에러가 발생할 일이 없음
	//TODO : error에 대해 다시 생각해보기 	
	ComputeHSForString(str);
	//cur : 현재 identifier가 저장된 주소 
	HTpointer cur = LookupHSForUpdate(str, hashcode);
	updateHT(cur, identType, dataType, returnType);

}
//call from scanner.l
//교수님 코드 returnType int -> void로 수정함
//TODO : 교수님 코드에서 SymbolTable return 값이 어떻게 사용되었는지 확인하기
void SymbolTable()
{
	err = noerror;
	if((nextfree == STsize) || ((nextfree+yyleng) > STsize)) {
		err = overst;
		PrintError(err);
	}

	//READ identifier
	for (int i = 0; i<yyleng; i++) {
		ST[nextfree++] = yytext[i];
	}
	ST[nextfree++] = '\0';

	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);
	if (!found) {
		printf("%6d          TIDENT     %7d\t", cLine, nextid);
		for (int i = nextid; i< nextfree-1; i++)
			printf("%c", ST[i]);
		printf("\t(entered)\n");
		
		ADDHT(hashcode);
		nextid = nextfree;
	}
	else {
		printf("%6d          TIDENT     %7d\t", cLine, sameid);
		for (int i = nextid; i < nextfree - 1; i++)
			printf("%c", ST[i]);
		printf("\t(already existed)\n");
		
		nextfree = nextid;
	}
}
