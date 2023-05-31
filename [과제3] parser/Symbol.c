/*
* symtable.c - symboltable 관리
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/04/27
*/
#include "glob.h"

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
void ComputeHSForString(char* str)
{
	int code, i;
	code = 0;
	for (i = 0; i < (int)strlen(str); i++) {
		int current = (int)str[i];
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
HTpointer LookupHSForUpdate(char* str, int hscode)
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
			if (found == TRUE) return here;
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
	ptr->lineNumber = lineNumber;
	ptr->index = nextid;
	ptr->next = HT[hscode];
	HT[hscode] = ptr;
}
void updateHT(HTpointer cur, char* identType, char* dataType, char* returnType)
{
	strcpy(cur->identType, identType);
	strcpy(cur->dataType, dataType);
	strcpy(cur->returnType, returnType);
}
void printHT()
{
	printf("[[HASH TABLE]]\n");
	for (int i = 0; i < HTsize; i++)
	{
		if (HT[i] == NULL) continue;
		printf("Hash Code %d : \n", i);
		for (HTpointer cur = HT[i]; cur != NULL; cur = cur->next)
		{
			//(abc: integer scalar variable, line3 )
			if ((int)strlen(cur->returnType) == 0)// not functionType
				printf("%s : %s %s, line%d\n", &ST[cur->index], cur->dataType, cur->identType, cur->lineNumber);
			//(f: function name, return type = void, line2)
			else//functionType
				printf("%s : function name, return type = %s, line%d\n", cur->dataType, cur->returnType, cur->lineNumber);
		}

	}

}

void SymbolTableUpdate(char* str, char* identType, char* dataType, char* returnType)
{	
	ComputeHSForString(str);
	//cur : 현재 identifier가 저장된 주소 
	HTpointer cur = LookupHSForUpdate(str, hashcode);
	updateHT(cur, identType, dataType, returnType);

}
//오류없는 identifier인 경우 yytext를 hashtable에 삽입하는 함수
void SymbolTable()
{
	nextid = nextfree;

	for (int i = 0; i < yyleng; i++)
	{
		if (STsize == nextfree)
		{
			err = overst;
			return;
		}
		ST[nextfree++] = yytext[i];
	}
	if (STsize == nextfree)
	{
		err = overst;
		return;
	}
	ST[nextfree++] = '\0';

	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);

	if (!found) {
		ADDHT(hashcode);
		sameid = nextid;
	}
	else nextfree = nextid;

}