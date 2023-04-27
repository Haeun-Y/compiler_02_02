#include "tn.h"

HTpointer HT[HTsize];
char ST[STsize];
extern char* yytext;
extern int yyleng;

int nextid;  //the current identifier
int nextfree;  //the next available index of ST
int hashcode;  //hash code of identifier
int sameid;  //first index of identifier

int found;  //for the previous occurrence of an identifie

/*PrintHStable     -   	Prints the hash table.write out the hashcode and the list of identifiers
						associated with each hashcode,but only for non-empty lists.
						Print out the number of characters used up in ST. */
void PrintHStable()
{
	int i, j;
	HTpointer here;

	printf("\n\n\n\n\n [[  HASH TABLE ]] \n\n");

	for (i = 0; i < HTsize; i++)
		if (HT[i] != NULL) { // non-empty 
			printf("  Hash Code %3d : ", i);
			for (here = HT[i]; here != NULL; here = here->next) {
				j = here->index;
				while (ST[j] != '\0' && j < STsize)
					printf("%c", ST[j++]);
				printf("\t");
			}
			printf("\n");
		}

	printf("\n\n\n < %5d characters are used in the string table >\n", nextfree);
}

/* ComputeHS 	- 	Compute the hash code of identifier by summing the ordinal values of its
					characters and then taking the sum modulo the size of HT. */
void ComputeHS(int nid, int nfree)
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

/*LookupHS 	-	For each identifier,Look it up in the hashtable for previous occurrence
				of the identifier.If find a match, set the found flag as true.
				Otherwise flase.
				If find a match, save the starting index of ST in same id. */
void LookupHS(int nid, int hscode)
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


/* ADDHT	-	Add a new identifier to the hash table.
			If list head ht[hashcode] is null, simply add a list element with
			starting index of the identifier in ST.
			IF list head is not a null , it adds a new identifier to the head of the chain */
void ADDHT(int hscode)
{
	HTpointer ptr;

	ptr = (HTpointer)malloc(sizeof(ptr));
	ptr->index = nextid;
	ptr->next = HT[hscode];
	HT[hscode] = ptr;
}
//오류없는 identifier인 경우 yytext를 hashtable에 삽입하는 함수
void SymmbolTable()
{
	if(STsize == nextfree)
	{
		err = overst;
		return;
	}
	nextid = nextfree;
	for (int i = 0; i < yyleng; i++)
		ST[nextfree++] = yytext[i];
	
	ST[nextfree++] = '\0';

	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);

	//TODO : 중복이 발생하는 경우와 발생하지 않는 경우 모두 sameid로 STindex 출력할 수 있도록 변경한 것 주의 
	//TODO : main 로직에서 출력상 필요하지 않으면 다시 변경하기 
	
	if (!found) {
		ADDHT(hashcode);
		sameid = nextid;
	}
	else {
		//printf("%6d         ", sameid);
		//for (int i = nextid; i < nextfree - 1; i++)
		//	printf("%c", ST[i]);
		//printf("          (already existed)\n");
		nextfree = nextid;
	}

	//TODO : 토큰 출력을 위한 함수호출 확인하고 코드 수정하기
	//PrintHStable();

}
