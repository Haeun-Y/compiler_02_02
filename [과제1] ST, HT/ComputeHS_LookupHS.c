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
    
    hscode = sum%HTsize;
    printf("hscode : %d\n", hscode);
    //return hscode;
    
}
void LookupHS(int nid, int hscode)
{
    
    int nfree = nid;
    //nfree 직접 계산
    printf("new word : ");
    while(ST[nfree] != ' ')
    {
        printf("%c", ST[nfree]);
        nfree++;
    }
    printf("\n");
    
    
    if(HT[hscode] == NULL)
    {
        found = false;
        printf("false\n");
    }
    
    else
    {
        HTpointer cur = HT[hscode];
        
        //list 탐색 
        for(; cur != NULL; cur = cur->next)
        {
            int curStart = cur -> index;
            int curEnd = curStart;
            
            printf("existed word : ");
            while(ST[curEnd] != ' ')
            {
                printf("%c", ST[curEnd]);
                curEnd++;
            }
            printf("\n");
            
            //두 문자열의 길이가 같을 때
            if((nfree - nid) == (curEnd - curStart))
            {
                bool isSame = true;
                for(int i = nid, j = curStart; i<nfree; i++, j++)
                {
                    if(ST[i] != ST[j])
                    {
                        isSame = false;
                        break;
                    }
                    
                }
                if(isSame)
                {
                    found = true;
                    
                    //같은 값이 존재한다면 ST에서의 인덱스를 알려줘야함 
                    sameIdx = curStart;
                    return;
                }
                
            }
            
            else
            {
                printf("lengh is different. %d %d\n", (nfree - nid), (curEnd - curStart));
                continue;
            }
            
        }
        
    }
    
    
    
}
void tmpLookup(int nid, int curIdx) 
{
    int nfree = nid;
    printf("new word : ");
    while(ST[nfree] != ' ')
    {
        printf("%c", ST[nfree]);
        nfree++;
        
    }
    printf("\n");
    
    int curStart = curIdx;
    int curEnd = curStart;
    
    printf("existed word : ");
    while(ST[curEnd] != ' ')
    {
        printf("%c", ST[curEnd]);
        curEnd++;
    }
    printf("\n");
            
    //두 문자열의 길이가 같을 때
    if((nfree - nid) == (curEnd - curStart))
    {
        bool isSame = true;
        for(int i = nid, j = curStart; i<nfree; i++, j++)
        {
            printf("%c %c\n", ST[i], ST[j]);
            if(ST[i] != ST[j])
            {
                isSame = false;
                break;
            }
                    
        }
        if(isSame)
        {
            found = true;
                    
            //같은 값이 존재한다면 ST에서의 인덱스를 알려줘야함 
            sameIdx = curStart;
            return;
        }
                
    }
    else
        printf("lengh is different. %d %d\n", (nfree - nid), (curEnd - curStart));
    
}
int main(void)
{
    //ab Abc AB ab abcd a x 123 x 
    char tmpInput[] = "ab Abc AB ab abcd a x 123 x ";
    
    for(int i = 0; i<strlen(tmpInput); i++)
        ST[i] = tmpInput[i];
        
    //ComputeHS(0, 2);
    tmpLookup(0, 10);
    printf("%s", (found)? "true":"false");
    
}
