#define isLetter(x) ( (x>='a' && x<='z')||(x>='A'&& x<='Z'))
#define isDigit(x) (x>='0' && x<='9')

ERRORtypes err;

bool isSeperator(char input) {
    for (int i = 0; i < strlen(seperators); i++) {
        if (input == seperators[i]) return true; // 배열 내에 존재하므로 구분자임
    }

    return false; // 구분자가 아님
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
