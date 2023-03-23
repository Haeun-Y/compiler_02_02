#define isLetter(x) ( (x>='a' && x<='z')||(x>='A'&& x<='Z'))
#define isDigit(x) (x>='0' && x<='9')

int isSeperator(char input) {
    for (int i = 0; i < strlen(seperators); i++) {
        if (input == seperators[i]) return 1; // 배열 내에 존재하므로 구분자임
    }

    return 0; // 구분자가 아님
}

void PrintError( ERRORtypes err )
{
    switch (err) {
        case overst: //오버플로우 발생시 오류문구를 출력하고 지금까지의 해시테이블 출력 후 프로그램 종료
            printf("...Error... OVERFLOW ");
            PrintHStable();
            exit(0);
            break;
            
        case illid: 
            printf("...Error...    ");
            
            if(isDigit(input)){ // 숫자일 경우
                printf(" start with digit \n");
            }else{ // 숫자가 아닐 경우
                printf("%c", input, "Is not allowed");
            }
            break;
    }
}
void ReadID() {

    nextid = nextfree; //nextfree값을 현재 nextid로 대입
    
    if (isDigit(input)) { //숫자로 시작하는 경우, 에러 출력
        err = illid; 
        PrintError(err);
    } else {
        while (input != EOF)) {
            //STsize를 넘을 경우 overflow 에러
            if (nextfree == STsize) {
                err = overst;
                PrintError(err);
            }
            //구분자일 경우 break
            if  (isSeperator(input)){
                break;
            }
            //이상한 문자일 경우 에러
            if (!(isLetter(input) || isDigit(input))){
                err = illid; 
                PrintError(err);
            }
            
            ST[nextfree++] = input; //ST에 input 값을 넣은 후 netfree 값을 1 증가 시킴
            input = fgetc(fp);  //다음 문자를 읽음
        }

    }
}
