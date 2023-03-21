#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "testdata.txt"
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


int main()
{
    int i;
    PrintHeading();
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
                    printf("%s", ST[i]);
                    i++;
                }
                printf("(entered)\n");
            }
            else { //if matched
                printf(" 	%d", sameIdx); 
                i = nextId;
                while (i < nextFree-1) {
                    printf("%s", ST[i]);
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