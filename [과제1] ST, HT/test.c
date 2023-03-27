#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME "testdata1.txt"
#define STsize 1000 //size of string table
#define HTsize 100 //size of hash table

//isLetter, isDigit
#define isLetter(x) ( (x>='a' && x<='z')||(x>='A'&& x<='Z')||(x=='_'))
#define isDigit(x) (x>='0' && x<='9')

typedef struct HTentry *HTpointer;
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
FILE *fp;
ERRORtypes err;

void PrintHStable() 
{
    int HTIdx, STIdx;
    HTpointer pointer;

    printf("\n\n[[  HASH TABLE  ]]\n\n");
    for (HTIdx = 0; HTIdx < HTsize; HTIdx++) {
        
        // HT 출력
        if (HT[HTIdx] != NULL) {
            printf("\n  Hash Code %3d : ", HTIdx);
        }
        
        // ST내의 스트링출력
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

int isSeperator(char input) 
{
    for (int i = 0; i < strlen(seperators); i++) {
        if (input == seperators[i]) return 1; 
    }

    return 0;
}

void SkipSeperators() 
{
    // 문자도 아니고, 숫자도 아닌 경우
    while (input != EOF && isSeperator(input)) {
        input = fgetc(fp);
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
    fp = fopen(FILE_NAME, "r");
    input = fgetc(fp);
}

//Add a new identifier to the hash table
void ADDHT(int hscode)
{
    HTpointer newId; //declaration for new identifier pointer
    newId= (HTpointer)malloc(sizeof(newId)); //allocate memory equal to the size of the new identifier pointer

    //pointing to new identifier
    newId->index= nextId; //index of identifier in ST = first index of word
    newId->next= HT[hscode]; //pointer to next identifier = hscode index of HT 

    HT[hscode]= newId; //insert newId into hscode index of hash table
}

void ComputeHS(int nid, int nfree)
{
    int sum = 0;
    for(int i = nid; i<nfree; i++)
    {
        char ch = ST[i];
        if(ch >= 'A' && ch <= 'Z') //대문자일 경우
            ch -= ('A' - 'a');
        sum += ch;
    }
    
    hscode = (sum%HTsize)+1;
    
}
bool isSameChar(char ch1, char ch2)
{
    //ch1이 대문자일 경우
    if(ch1 >= 'A' && ch1 <= 'Z')
        ch1 -= ('A' - 'a');
    
    //ch2가 대문자일 경우
    if(ch2 >= 'A' && ch2 <= 'Z')
        ch2 -= ('A' - 'a');
    
    if(ch1 == ch2)
        return true;

    else return false;

}
void LookupHS(int nid, int hscode)
{
    //global variable found
    found = false;
    
    if(HT[hscode] == NULL)
        return;
    
    
    else
    {
        HTpointer cur = HT[hscode];
        
        //list 탐색 
        for(; cur != NULL; cur = cur->next)
        {
            int curStart = cur -> index;
            int curEnd = curStart;
            
            //기존 문자열의 끝 탐색
            while(ST[curEnd] != '\0') curEnd++;
            
            //두 문자열의 길이가 같을 때
            if((nextFree - nid) == (curEnd - curStart))
            {
                bool isSame = true;
                for(int i = nid, j = curStart; i<nextFree; i++, j++)
                {
                    if(!isSameChar(ST[i], ST[j]))
                    {
                        isSame = false;
                        break;
                    }
                    
                }
                if(isSame)
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
    case overst: //오버플로우 발생시 오류문구를 출력하고 지금까지의 해시테이블 출력 후 프로그램 종료
        printf("...Error... OVERFLOW ");
        PrintHStable();
        exit(0);
        break;

    case illid:
        printf("...Error... 	");

        //start with digit
        if (isDigit(input)) {
            while (input != EOF && !isSeperator(input)) {
                printf("%c", input);
                input = fgetc(fp);
            }
            printf(" 	start with digit \n");
        }
        //not allowed letter
        else {
            char illc = input; //에러 문자를 출력해야 하므로 변수에 저장해놓음

            for (int i = nextId; i < nextFree; i++) { //ex)aa&bb인 경우, aa 출력
                printf("%c", ST[i]);
            }
            while (input != EOF && !isSeperator(input)) { //ex)aa&bb인 경우, &bb 출력
                printf("%c", input);
                input = fgetc(fp);
            }
            printf(" 	%c Is not allowed \n", illc);

            nextFree = nextId; //nextFree값 되돌리기
        }
        break;
    case noerror:
        break;
    }
}
void ReadID() {

    nextId = nextFree; //nextFree값을 현재 nextId로 대입

    if (isDigit(input)) { //숫자로 시작하는 경우 에러
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
            //이상한 문자일 경우 에러
            if (!(isLetter(input) || isDigit(input))) {
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
    int i;
    printHeading();
    initialize();
    
    while (input != EOF) {
        err = noerror;
        SkipSeperators();
        ReadID();
        if( input != EOF && err != illid ) {
            if( nextFree == STsize ) {
                // print error message
            }
            ST[nextFree++] = '\0';

            ComputeHS(nextId, nextFree);
            LookupHS(nextId,hscode);
            
            if(!found) { //if not matched
                ADDHT(hscode); //add a new element to the list, pointing to new identifier
                printf(" 	%d", nextId); //index in ST
                i = nextId;
                while (i < nextFree-1) {
                    printf("%s", &ST[i]);
                    i++;
                }
                printf("(entered)\n");
            }
            else { //if matched
                printf(" 	%d", sameIdx); 
                i = nextId;
                while (i < nextFree-1) {
                    printf("%s", &ST[i]);
                    i++;
                }
                printf("(already existed)\n");

                //not delete the identifier from ST but process by index (ST에서 삭제하지 않고, 인덱스로 처리)
                nextFree = nextId;
            }
        }
    }
    PrintHStable();
}
