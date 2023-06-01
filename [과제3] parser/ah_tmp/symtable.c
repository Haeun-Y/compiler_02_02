//identifier�� �ԷµǸ� symboltable�� ������ �ش�
/*
identifier�� type�� ������ ���� �����Ѵ�
0. integer scalar
1. float scalar
2. integer array
3. float array
4. function return type void
5. fuction return type int
6. fuction return type float
7. fuction parameter
8. not defined identifier or function
�ļ����� ������ �� identifier�� 8������ ������
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
    int sum = 0;
    for (int i = nid; i < nfree - 1; i++)
        sum += (int)ST[i];
    hashcode = sum % HTsize;

    //�̹� �ִ� hashcode�� hashList ���� X
    int same = FALSE;
    for (int j = 0; j < hsidx; j++) {
        if (hashList[j] == hashcode) {
            same = TRUE;
            break;
        }
    }
    if (!same)
        hashList[hsidx++] = hashcode;
}

//hash table���� ������ identifier ã�� �Լ�
void LookupHS(int nowid, int hscode) 
{
    HTpointer here;
    int hereidf, nowidf;
    found = FALSE;
    //���� �ؽ� �ڵ� �� -> ���� identifier ã��
    if (HT[hscode] != NULL) {
        here = HT[hashcode];
        while (here != NULL && found == FALSE) {
            found = TRUE;
            hereidf = here->index;
            sameidf = hereidf;
            nowidf = nowid; //���� idf

            while (ST[hereidf] != '\0' && ST[nowidf] != '\0') {
                if (ST[hereidf] != ST[nowidf]) {
                    found = FALSE;
                    break;
                }
                else {
                    hereidf++;
                    nowidf++;
                }
            }
            //���� �ؽ��ڵ� �� ���� string check
            here = here->next;
        }
    }
}

//hash table�� ���ο� identifier �߰�
void ADDHT(int hscode)
{
    HTpointer ptr;
    ptr = (HTpointer)malloc(sizeof(ptr));
    //ptr->type = idttype;
    ptr->IDline = cLines;
    ptr->index = idfidx;
    ptr->next = HT[hscode];
    HT[hscode] = ptr;
}

//hash table ����ϴ� �Լ� identfier ����� line + idetifier + type�� �����
void PrintHStable()
{
    int  j;
    HTpointer here;

    printf("\n\n\n\n [[ HASH TABLE ]] \n\n\n");

    //hashcode ������ ���� �迭���� ���� ������ �ش� idx identifier ���
    for (int i = 0; i < hsidx; i++) {
        printf(" Hash Code %3d : ", hashList[i]);
        for (here = HT[hashList[i]]; here != NULL; here = here->next) {
            j = here->index;
            printf("(");
            while (ST[j] != '\0' && j <= STsize)
                printf("%c", ST[j++]);
            //identifier�� type�� ���� �����
            switch (here->type) {
              case 0: printf(": integer scalar variable, "); break;
              case 1: printf(": floating point scalar variable, "); break;
              case 2: printf(": integer array variable, "); break;
              case 3: printf(": floating point array variable, "); break;
              case 4: printf(": fuction name, return type = void, "); break;
              case 5: printf(": fuction name, return type = int, "); break;
              case 6: printf(": fuction name, return type = float, "); break;
              case 7: printf(": fuction parameter "); break;
              case 8: printf(": not defined identifier or function "); break;
              default: break;
            }
            printf(" line%d )", here->IDline);
        }
        // identifier�� ���� �Ӽ� ����ϴ� ������ �ʿ���
        printf("\n");
    }
    printf("\n\n\n < %-5d characters are used in the string table > \n", nextST);
}

//identifier�� 12���ڸ� ���� �ʰ�, ������ �ִ� identifier�� �ƴ϶�� hashtable�� ����
void symtable() {
    ERRORtypes err;

    if (yyleng > IDlen) {
        err = illid_long; //12���� �̻��� identifier 
        printError(err);
        err = noerror;
    }

    else {
        idfidx = nextST;

        for (int j = 0; yytext[j] != '\0'; j++) {
            if (nextST == STsize) {
                err = overst;
                nextST = idfidx; //overflow ���� ������ ST �ε��� ���� �ֱ�
                printError(err);
            }
            ST[nextST++] = yytext[j];
            idfCnt++;
        }

        ST[nextST++] = '\0';

        ComputeHS(idfidx, nextST);
        LookupHS(idfidx, hashcode);

        //���� hashtable�� ������ identifier ���� �� add hashtable
        if (!found) {
             ADDHT(hashcode);
        }

        //���� hashtable�� ������ identifier �ִ� ���
        else {
            nextST = idfidx;
        }
    }
}