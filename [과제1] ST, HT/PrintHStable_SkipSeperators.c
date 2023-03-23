#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//#define FILE_NAME "testdata.txt"
#define STsize 1000 //size of string table
#define HTsize 100 //size of hash table

//isLetter, isDigit
#define isLetter(x) ( (x>='a' && x<='z')||(x>='A'&& x<='Z'))
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

void PrintHStable() 
{
    int HTIdx, STIdx;
    HTpointer pointer;

    printf("[[  HASH TABLE  ]]\n\n");
    for (HTIdx = 0; HTIdx < HTsize; HTIdx++) {
        
        // HT 출력
        if (HT[HTIdx] != NULL) {
            print("  Hash Code %3d : ", HTIdx);
        }
        
        // ST내의 스트링출력
        for (pointer = HT[HTIdx]; pointer != NULL; pointer = pointer->next) {
            STIdx = pointer->index;
            while (ST[STIdx] != '\0' && STIdx < STsize) {
                print("%c", ST[STIdx]);
            }
            print("\n")
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
    while (!isLetter(input) || !isDigit(input)) {
        // seperator 인 경우 skip
        if (isSeperator(input)) {
            input = fgetc(fp);
            return
        }
        printf("잘못된 문자입니다.")
    }
    
}
