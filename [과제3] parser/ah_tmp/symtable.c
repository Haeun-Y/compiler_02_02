//identifier가 입력되면 symboltable로 관리해 준다
/*
identifier의 type은 다음과 같이 정의한다
0. integer scalar
1. float scalar
2. integer array
3. float array
4. function return type void
5. fuction return type int
6. fuction return type float
7. fuction parameter
8. not defined identifier or function
파서에서 오류가 난 identifier는 8번으로 지정함
*/


#include <stdio.h>
#include <stdlib.h>
#include "glob.h"

extern void printError(ERRORtypes err);
extern char* yytext;
extern int yyleng;

//hashcode 계산
void ComputeHS(int nid, int nfree) 
{
    int sum = 0;
    for (int i = nid; i < nfree - 1; i++)
        sum += (int)ST[i];
    hashcode = sum % HTsize;

    //이미 있는 hashcode면 hashList 삽입 X
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

//hash table에서 동일한 identifier 찾는 함수
void LookupHS(int nowid, int hscode) 
{
    HTpointer here;
    int hereidf, nowidf;
    found = FALSE;
    //같은 해시 코드 중 -> 같은 identifier 찾음
    if (HT[hscode] != NULL) {
        here = HT[hashcode];
        while (here != NULL && found == FALSE) {
            found = TRUE;
            hereidf = here->index;
            sameidf = hereidf;
            nowidf = nowid; //현재 idf

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
            //같은 해시코드 값 가진 string check
            here = here->next;
        }
    }
}

//hash table에 새로운 identifier 추가
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

//hash table 출력하는 함수 identfier 저장된 line + idetifier + type을 출력함
void PrintHStable()
{
    int  j;
    HTpointer here;

    printf("\n\n\n\n [[ HASH TABLE ]] \n\n\n");

    //hashcode 저장해 놓은 배열에서 원소 꺼내서 해당 idx identifier 출력
    for (int i = 0; i < hsidx; i++) {
        printf(" Hash Code %3d : ", hashList[i]);
        for (here = HT[hashList[i]]; here != NULL; here = here->next) {
            j = here->index;
            printf("(");
            while (ST[j] != '\0' && j <= STsize)
                printf("%c", ST[j++]);
            //identifier의 type에 따라 출력함
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
        // identifier에 대한 속성 출력하는 구간이 필요함
        printf("\n");
    }
    printf("\n\n\n < %-5d characters are used in the string table > \n", nextST);
}

//identifier가 12글자를 넘지 않고, 기존에 있던 identifier가 아니라면 hashtable에 삽입
void symtable() {
    ERRORtypes err;

    if (yyleng > IDlen) {
        err = illid_long; //12글자 이상의 identifier 
        printError(err);
        err = noerror;
    }

    else {
        idfidx = nextST;

        for (int j = 0; yytext[j] != '\0'; j++) {
            if (nextST == STsize) {
                err = overst;
                nextST = idfidx; //overflow 나기 전으로 ST 인덱스 돌려 주기
                printError(err);
            }
            ST[nextST++] = yytext[j];
            idfCnt++;
        }

        ST[nextST++] = '\0';

        ComputeHS(idfidx, nextST);
        LookupHS(idfidx, hashcode);

        //기존 hashtable에 동일한 identifier 없을 시 add hashtable
        if (!found) {
             ADDHT(hashcode);
        }

        //기존 hashtable에 동일한 identifier 있는 경우
        else {
            nextST = idfidx;
        }
    }
}