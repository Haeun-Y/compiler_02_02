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
int nextId;
int nextFree;

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
    
    printf("character sum : %d\n", sum);
    hscode = sum%HTsize;
    printf("hscode : %d\n", hscode);
    
}
bool isSameChar(char ch1, char ch2)
{
    if(ch1 >= 'A' && ch1 <= 'Z')
        ch1 -= ('A' - 'a');
    
    if(ch2 >= 'A' && ch2 <= 'Z')
        ch2 -= ('A' - 'a');
    
    if(ch1 == ch2)
        return true;

    else return false;

}
void LookupHS(int nid, int hscode)
{
    printf("***begin LookupHS function***\n");
    found = false;
    int nfree = nid;
    //nfree 직접 계산
    printf("new word : ");
    while(ST[nfree] != '\0')
    {
        printf("%c", ST[nfree]);
        nfree++;
    }
    printf("\n");
    
    
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
            
            printf("existed word with same hashcode: ");
            while(ST[curEnd] != '\0')
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
                    if(!isSameChar(ST[i], ST[j]))
                    {
                        isSame = false;
                        break;
                    }
                    
                }
                if(isSame)
                {
                    found = true;
                    printf("same word with same hashcode : ");
                    for(int i = curStart; i<curEnd; i++)
                        printf("%c", ST[i]);
                    printf("\n");
                    //같은 값이 존재한다면 ST에서의 인덱스를 알려줘야함 
                    sameIdx = curStart;
                    return;
                }
                
            }
            
            else
            {
                //printf("lengh is different. %d %d\n", (nfree - nid), (curEnd - curStart));
                continue;
            }
            
        }
        
    }
    printf("***end LookupHS function***\n");
    
    
    
}
void ADDHT(int hscode)
{
    HTpointer newId; //declaration for new identifier pointer
    newId= (HTpointer)malloc(sizeof(newId)); //allocate memory equal to the size of the new identifier pointer

    //pointing to new identifier
    newId->index= nextId; //index of identifier in ST = first index of word
    newId->next= HT[hscode]; //pointer to next identifier = hscode index of HT 

    HT[hscode]= newId; //insert newId into hscode index of hash table
}
void printHeading()
{
    printf("-------------- ------------\n");
    printf(" Index in ST    identifier \n");
    printf("-------------- ------------\n");
}
int main(void)
{
    //ab Abc AB ab abcd a x 123 x 
    char tmpInput[] = "ab\0Abc\0bA\0ab\0abcd\0a\0x\0x123\0X\0";
    
    for(int i = 0; i<29; i++)
        ST[i] = tmpInput[i];
        
    while(nextId < 29)
    {
        while(ST[nextFree] != '\0') nextFree++;
        printf("******************************\n");
        printf("nextId : %d, nextFree : %d\n", nextId, nextFree);
        ComputeHS(nextId, nextFree);
        LookupHS(nextId, hscode);
        printf("found : %s\n", (found)? "true":"false");   
        

        if(!found)
        {
            ADDHT(hscode);
            printf("Index in ST : %d", nextId);
        }
        else printf("Index in ST : %d", sameIdx);

        printf("\nidentifier : ");
        for(int i = nextId; i<nextFree; i++)
            printf("%c", ST[i]);
        printf("\n");

        nextId = nextFree + 1;
        nextFree = nextId;
        printf("******************************\n\n");
    }
    
    
}


/*

******************************
nextId : 0, nextFree : 2
character sum : 195
hscode : 95
***begin LookupHS function***
new word : ab
found : false
Index in ST : 0
identifier : ab
******************************

******************************
nextId : 3, nextFree : 6
character sum : 294
hscode : 94
***begin LookupHS function***
new word : Abc
found : false
Index in ST : 3
identifier : Abc
******************************

******************************
nextId : 7, nextFree : 9
character sum : 195
hscode : 95
***begin LookupHS function***
new word : bA
existed word with same hashcode: ab
***end LookupHS function***
found : false
Index in ST : 7
identifier : bA
******************************

******************************
nextId : 10, nextFree : 12
character sum : 195
hscode : 95
***begin LookupHS function***
new word : ab
existed word with same hashcode: bA
existed word with same hashcode: ab
same word with same hashcode : ab
found : true
Index in ST : 0
identifier : ab
******************************

******************************
nextId : 13, nextFree : 17
character sum : 394
hscode : 94
***begin LookupHS function***
new word : abcd
existed word with same hashcode: Abc
***end LookupHS function***
found : false
Index in ST : 13
identifier : abcd
******************************

******************************
nextId : 18, nextFree : 19
character sum : 97
hscode : 97
***begin LookupHS function***
new word : a
found : false
Index in ST : 18
identifier : a
******************************

******************************
nextId : 20, nextFree : 21
character sum : 120
hscode : 20
***begin LookupHS function***
new word : x
found : false
Index in ST : 20
identifier : x
******************************

******************************
nextId : 22, nextFree : 26
character sum : 270
hscode : 70
***begin LookupHS function***
new word : x123
found : false
Index in ST : 22
identifier : x123
******************************

******************************
nextId : 27, nextFree : 28
character sum : 120
hscode : 20
***begin LookupHS function***
new word : X
existed word with same hashcode: x
same word with same hashcode : x
found : true
Index in ST : 20
identifier : X
******************************

*/
