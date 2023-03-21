#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//#define FILE_NAME "testdata.txt"
#define STsize 1000 //size of string table
#define HTsize 100 //size of hash table

typedef struct HTentry *HTpointer;
typedef struct HTentry 
{
    int index; //index of identifier in ST
    HTpointer next; //pointer to next identifier
} HTentry;

enum errorTypes 
{ 
    //noerror 0, illid 1, overst 2
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
//우선 전역변수로 처리했음 필요하다면 return값으로 수정하기

void ComputeHS(int nid, int nfree)
{
    int sum = 0;
    for(int i = nid; i<nfree; i++)
    {
        char ch = ST[i];
        if(ch >= 'A' && ch <= 'Z') //대문자일 경우
            ch -= ('A' - 'a');
        printf("%c : %d\n", ch, ch);
        sum += ch;
    }
    
    //return sum%HTsize;
    //hashcode 계산 방법 수정하기 
    //전역 변수로 사용할지 ?? return 값을 변경해도 될지?? 
    
    hscode = sum%HTsize;
    printf("hscode : %d\n", hscode);
    
}
void LookupHS(int nid, int hscode)
{
    //main에서 사용되는 found는 전역변수로 관리할 것인지, return 값으로 돌려줄건지
    //found는 LookupHS 의 결과 
    //found == true 이면, 이미 해쉬테이블에 존재하는 것
    
    //nfree를 직접 계산할지, 파라미터로 받을지 ??
    
    //직접 계산 
    int nfree = nid;
    
    //빈칸과 \0는 다른데 둘 중 어느걸로 해야할지? 
    while(ST[nfree] != ' ') nfree++;
    
    //int targetSize = nfree - nid;
    
    
    if(HT[hscode] == NULL)
    {
        found = false;
        printf("false\n");
        //return false;
    }
    
    else
    {
        HTpointer cur = HT[hscode];
        
        //list 탐색 
        for(; cur != NULL; cur = cur->next)
        {
            int curIdx = cur -> index;
            bool isSame = true;
            for(int i = nid; i<nfree; i++)
            {
                if(ST[curIdx] != ' ' && ST[curIdx] != ST[i])
                {
                    isSame = false;
                    break;
                }
                
                if(ST[curIdx] == ' ')
                {
                    isSame = false;
                    break;
                }
                
                curIdx++;
                
            }
            if(ST[curIdx] != ' ') isSame = false;
            
            if(isSame)
            {
                found = true;
                sameIdx = cur -> index;
                return;
            }
            
        }
        //만약 같은 값이 존재한다면 ST에서의 인덱스를 알려줘야함 
    }
    
    
    
}
void tmpLookup(int nid, int curIdx) 
{
    int nfree = nid;
    while(ST[nfree] != ' ') nfree++;
    
    bool isSame = true;
    for(int i = nid; i<nfree; i++)
    {
        printf("new ch : %c\texisted ch : %c\n", ST[i], ST[curIdx]);
        if(ST[curIdx] != ' ' && ST[curIdx] != ST[i])
        {
                    isSame = false;
                    break;
        }
                
        if(ST[curIdx] == ' ')
        {
            isSame = false;
            break;
        }
                
        curIdx++;
                
    }
    if(ST[curIdx] != ' ') isSame = false;
            
    if(isSame)
    {
        found = true;
        return;
    }
}
int main(void)
{
    //ab Abc AB ab abcd a x 123 x 
    char tmpInput[] = "ab Abc AB ab abcd a x 123 x ";
    
    for(int i = 0; i<strlen(tmpInput); i++)
        ST[i] = tmpInput[i];
        
    ComputeHS(0, 2);
    tmpLookup(0, 18);
    printf("%s", (found)? "true":"false");
    
}
