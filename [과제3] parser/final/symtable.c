/*
* symtable.c
* programmer - �ǿ���, ������, ������, �ֿ���
* date - 2023/06/01
*/

/*
identifier�� type�� ������ ���� �����Ѵ�.

0. error
1. integer scalar variable
2. integer array variable
3. function return type void
4. fuction return type int
5. integer scalar fuction parameter
6. integer array fuction parameter
7. void function parameter
8. integer scalar const
9. integer array const
10. not defined identifier or function

*/

#include <stdio.h>
#include <stdlib.h>
#include "glob.h"

extern void printError(ERRORtypes err);
extern char* yytext;
extern int yyleng;

//hashcode ���
void ComputeHS(int nid, int nfree)
{
    int code = 0;
    for (int i = nid; i < nfree - 1; i++)
        code += (int)ST[i];
    hashcode = code % HTsize + 1;
    hashcode = (hashcode == HTsize ? 0 : hashcode);
}

//hash table�� ������ identifier�� �̹� �����ϴ��� ã�� �Լ�
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
            sameid = i;
            j = nid;

            while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
                if (ST[i] != ST[j]) {
                    found = FALSE;
                }
                else {
                    i++;
                    j++;
                }
            }
            here = here->next;
        }
    }
}

//hash table�� ���ο� identifier �߰�
void ADDHT(int hscode)
{
    HTpointer ptr;

    if (HT[hscode] == NULL) {
        ptr = (HTpointer)malloc(sizeof(ptr));
        ptr->type = 0;
        ptr->lineNumber = cLines;
        ptr->index = nextid;
        ptr->next = NULL;
        HT[hscode] = ptr;
    }
    else {
        ptr = (HTpointer)malloc(sizeof(ptr));
        ptr->type = 0;
        ptr->lineNumber = cLines;
        ptr->index = nextid;
        ptr->next = HT[hscode];
        HT[hscode] = ptr;
    }
}

//hash table ����ϴ� �Լ� identfier ����� line + idetifier + type�� �����
void PrintHStable()
{
    printf("********************************************************************\n");
    printf("\t\t\t [[ HASH TABLE ]] \n");
    printf("********************************************************************\n\n");

    for (int i = 0; i < HTsize; i++)
    {
        if (HT[i] == NULL) continue;
        for (HTpointer cur = HT[i]; cur != NULL; cur = cur->next)
        {
            printf("Hash Code %d\n\t", i);
            for (int j = cur->index; ST[j] != '\0'; j++) printf("%c", ST[j]);

            switch (cur->type) {
            case 1: printf(": integer scalar variable, "); break;
            case 2: printf(": integer array variable, "); break;
            case 3: printf(": fuction name, return type = void, "); break;
            case 4: printf(": fuction name, return type = int, "); break;
            case 5: printf(": integer scalar fuction parameter, "); break;
            case 6: printf(": integer array fuction parameter, "); break;
            case 7: printf(": void fuction parameter, "); break;
            case 8: printf(": integer scalar const, "); break;
            case 9: printf(": integer array const, "); break;
            case 10: printf(": not defined identifier or function, "); break;
            default:printf(": parsing error, "); break;
            }
            printf(" line%d\n", cur->lineNumber);
        }
    }

    printf("********************************************************************\n");
}

void symtable() {
    nextid = nextfree;

    for (int i = 0; i < yyleng; i++) {
        if (STsize == nextfree) {
            err = overst;
            return;
        }
        ST[nextfree++] = yytext[i];
    }

    ST[nextfree++] = '\0';

    ComputeHS(nextid, nextfree);
    LookupHS(nextid, hashcode);

    //���� hashtable�� ������ identifier ���� �� add hashtable
    if (!found) {
        ADDHT(hashcode);
        sameid = nextid;
    }

    //���� hashtable�� ������ identifier �ִ� ���
    else {
        nextfree = nextid;
    }
}