/* error messages
			overst :  overflow in ST. print the hashtable and abort
			illid_digit    : illegal identifier (start with digit)
			illid_long	: illegal identifier (too long identifier)
			illid_illch	: illegal identifier (containing illegal characters)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"

////아래 부분들은 tn.h로 처리 cErrors, error_print 모두 global 변수
//enum errorTypes { noerror, illid_digit, illid_long, illid_illch, overst };
//typedef enum errorTypes ERRORtypes;

int cErrors = 0; //총 에러 개수를 카운트하는 변수 (overflow인 경우를 제외하고 main에서 출력한다.)
char* error_message; //에러 메세지를 담는 변수 (메인에서 error_message를 출력한다.)


void ReportError(ERRORtypes err)
{
	cErrors++;

	switch (err) {
	case overst:
		strcpy(error_message, "overflow\n");
		break;
	case illid_long:
		strcpy(error_message, "too long identifier\n");
		break;
	case illid_illch:
		strcpy(error_message, "identifier containing illegal character\n");
		break;
	case illid_digit:
		strcpy(error_message, "start with digit \n");
		break;
	}
}