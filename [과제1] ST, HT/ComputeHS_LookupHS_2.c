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
void ADDHT(int hscode)
{
    HTpointer newId; //declaration for new identifier pointer
    newId= (HTpointer)malloc(sizeof(newId)); //allocate memory equal to the size of the new identifier pointer

    //pointing to new identifier
    newId->index= nextId; //index of identifier in ST = first index of word
    newId->next= HT[hscode]; //pointer to next identifier = hscode index of HT 

    HT[hscode]= newId; //insert newId into hscode index of hash table
}
