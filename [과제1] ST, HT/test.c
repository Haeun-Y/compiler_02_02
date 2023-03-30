//코드 설명
//
//1. 실행 환경(vscode, visual studio)에 따라 initialize 함수의 fopen 코드가 달라집니다.
//2. null 문자를 포함하지 않은 identifier가 13글자를 넘어가면 too long identifier 에러가 발생합니다.
//3. 마지막에 출력되는 string table 내 character 개수는 identifier 뒤의 null 문자를 포함하여 카운트 합니다.
//4. hscode 연산 결과가 100이 되는 경우를 주의해야 합니다. HTpointer HT[HTsize];라고 지정되어있고, HTsize가 100으로 지정되어있고, hashcode 계산이 hscode = (sum % HTsize) + 1; 라고 정해져있습니다. 
//hscode 연산시, 1~HTsize 까지 가능하지만, 해쉬테이블의 가능한 인덱스 범위는 0~(HTsize-1) 이기 때문에 hscode가 100인 경우 출력되지 않습니다. 
//hscode 연산을 hscode = (sum % HTsize); 로 변경하면 문제없이 코드가 동작 가능합니다. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME "testdata.txt"
#define STsize 1000 //size of string table
#define HTsize 100 //size of hash table

//isLetter, isDigit
#define isLetter(x) ( (x>='a' && x<='z')||(x>='A'&& x<='Z')||(x=='_'))
#define isDigit(x) (x>='0' && x<='9')

typedef struct HTentry* HTpointer;
typedef struct HTentry
{
    int index;
    HTpointer next;
} HTentry;

enum errorTypes
{
    noerror,
    illid,
    overst
};

typedef enum errorTypes ERRORtypes;

char seperators[] = " .,;:?!\t\n";

HTpointer HT[HTsize];
char ST[STsize];

bool found;
int hscode;
int sameIdx;
int nextId;
int nextFree;
char input;
FILE* fp;
ERRORtypes err;

void PrintHStable()
{
    int HTIdx, STIdx;
    HTpointer pointer;

    printf("\n\n[[  HASH TABLE  ]]\n\n");
    for (HTIdx = 0; HTIdx < HTsize; HTIdx++) {

        //HT 출력
        if (HT[HTIdx] != NULL) {
            printf("\n  Hash Code %3d : ", HTIdx);
        }

        //ST내의 스트링출력
        for (pointer = HT[HTIdx]; pointer != NULL; pointer = pointer->next) {
            STIdx = pointer->index;
            while (ST[STIdx] != '\0' && STIdx < STsize) {
                printf("%c", ST[STIdx]);
                STIdx++;
            }
            printf("\t");
        }
    }
    printf("\n\n\n < %4d characters are used in the string table > \n ", nextFree);
}


bool isSeperator(char input)
{
    for (int i = 0; i < strlen(seperators); i++) {
        if (input == seperators[i]) return true;
    }
    return false;
}

void SkipSeperators()
{
    while (input != EOF && isSeperator(input)) {
        input = fgetc(fp);
    }
    if (input == EOF) { //파일이 끝났을 경우 HStable 출력 후 프로그램 종료
        PrintHStable();
        exit(0);
    }
}

void printHeading()
{
    printf("-------------- ------------\n");
    printf(" Index in ST    identifier \n");
    printf("-------------- ------------\n");
}

void initialize()
{
    fp = fopen(FILE_NAME, "r"); //vs code에서 실행할 경우
    //fopen_s(&fp, FILE_NAME, "r"); //visual studio에서 실행할 경우

    if (fp != 0) {
        input = fgetc(fp);
    }
    else { //파일 경로가 잘못된 경우 프로그램 종료
        printf("파일 경로가 잘못되지 않았는지 확인해 주세요.\n");
        exit(0);
    }
}

void ADDHT(int hscode)
{
    HTpointer newId; //declaration for new identifier pointer
    newId = (HTpointer)malloc(sizeof(newId)); //allocate memory equal to the size of the new identifier pointer

    //pointing to new identifier
    newId->index = nextId; //index of identifier in ST = first index of word
    newId->next = HT[hscode]; //pointer to next identifier = hscode index of HT 

    HT[hscode] = newId; //insert newId into hscode index of hash table
}

void ComputeHS(int nid, int nfree)
{
    int sum = 0;
    for (int i = nid; i < nfree; i++)
    {
        char ch = ST[i];
        if (ch >= 'A' && ch <= 'Z') //대문자일 경우
            ch -= ('A' - 'a');
        sum += ch;
    }

    hscode = (sum % HTsize) + 1;
}
bool isSameChar(char ch1, char ch2)
{
    //ch1이 대문자일 경우
    if (ch1 >= 'A' && ch1 <= 'Z')
        ch1 -= ('A' - 'a');

    //ch2가 대문자일 경우
    if (ch2 >= 'A' && ch2 <= 'Z')
        ch2 -= ('A' - 'a');

    if (ch1 == ch2)
        return true;

    else return false;
}
void LookupHS(int nid, int hscode)
{
    //global variable found
    found = false;

    if (HT[hscode] == NULL)
        return;

    else
    {
        HTpointer cur = HT[hscode];

        //list 탐색 
        for (; cur != NULL; cur = cur->next)
        {
            int curStart = cur->index;
            int curEnd = curStart;

            //기존 문자열의 끝 탐색
            while (ST[curEnd] != '\0') curEnd++;

            //두 문자열의 길이가 같을 때
            if ((nextFree - nid) == (curEnd - curStart))
            {
                bool isSame = true;
                for (int i = nid, j = curStart; i < nextFree; i++, j++)
                {
                    if (!isSameChar(ST[i], ST[j]))
                    {
                        isSame = false;
                        break;
                    }
                }
                if (isSame)
                {
                    found = true;
                    sameIdx = curStart;
                    return;
                }
            }

            //두 문자열의 길이가 같지 않을 때
            else continue;
        }
    }
}

void PrintError(ERRORtypes err)
{
    switch (err) {
    case overst: //오버 플로우 발생 시 해시테이블 출력 후 프로그램 종료
        printf("...Error... OVERFLOW ");
        nextFree = nextId;
        PrintHStable();
        exit(0);
        break;

    case illid:
        {
            char illc = input; //에러 문자
            int cnt = 0; //글자수 카운터

            printf("%12s    ", "...Error...");

            //에러가 있는 identifier을 ST에 넣지 않고 여기서 출력
            for (int i = nextId; i < nextFree; i++) { //ex)aa&bb인 경우, aa 출력
                printf("%c", ST[i]);
                cnt++;
            }
            while (input != EOF && !isSeperator(input)) { //ex)aa&bb인 경우, &bb 출력
                printf("%c", input);
                input = fgetc(fp);
                cnt++;
            }

            //more than 12 letters
            if (nextFree - nextId >= 12) {
                for (int i = 0; i < 45 - cnt - 19; i++) { //공백을 출력하여 출력문의 열을 맞춤
                    printf(" ");
                }
                printf("too long identifier\n");
            }
            //start with digit
            else if (isDigit(illc)) {
                for (int i = 0; i < 45 - cnt - 16; i++) { //공백을 출력하여 출력문의 열을 맞춤
                    printf(" ");
                }
                printf("start with digit\n");
            }
            //not allowed letter
            else {
                for (int i = 0; i < 45 - cnt - 16; i++) { //공백을 출력하여 출력문의 열을 맞춤
                    printf(" ");
                }
                printf("%c Is not allowed\n", illc);
            }

            nextFree = nextId; //ST에서 삭제하지 않고, 인덱스로 처리
            break;
        }
    }
}
void ReadID() {
    nextId = nextFree; //nextFree 값을 현재 nextId로 대입

    if (isDigit(input)) { //start with digit 에러
        err = illid;
        PrintError(err);
    }
    else {
        while (input != EOF && !isSeperator(input)) {
            //STsize를 넘을 경우 overflow 에러
            if (nextFree == STsize) {
                err = overst;
                PrintError(err);
            }
            //허용되지 않은 문자일 경우 에러
            if (!(isLetter(input) || isDigit(input))) {
                err = illid;
                PrintError(err);
                break;
            }
            //12자 넘을 경우 에러
            if (nextFree - nextId >= 12) {
                err = illid;
                PrintError(err);
                break;
            }

            ST[nextFree++] = input; //ST에 input 값을 넣은 후 netfree 값을 1 증가 시킴
            input = fgetc(fp);  //다음 문자를 읽음
        }
    }
}

int main() {
    initialize();
    printHeading();

    while (input != EOF) {
        err = noerror;

        SkipSeperators();
        ReadID();

        if (err != illid) {
            if (nextFree == STsize) { //null을 넣을 때 overflow가 나는지 검사
                PrintError(overst);
            }
            ST[nextFree] = '\0';

            ComputeHS(nextId, nextFree);
            LookupHS(nextId, hscode);

            if (!found) { //if not matched
                printf("%12d    ", nextId); //index in ST
                printf("%-15s", &ST[nextId]); //identifier
                printf("%30s\n", "(entered)");
                ADDHT(hscode); //add a new element to the list, pointing to new identifier

                nextFree++;
            }
            else { //if matched
                printf("%12d    ", sameIdx);
                printf("%-15s", &ST[nextId]);
                printf("%30s\n", "(already existed)");

                nextFree = nextId; // ST에서 삭제하지 않고, 인덱스로 처리
            }
        }
    }
    PrintHStable();
}
