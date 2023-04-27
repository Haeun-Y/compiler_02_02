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

////�Ʒ� �κе��� tn.h�� ó�� cErrors, error_print ��� global ����
//enum errorTypes { noerror, illid_digit, illid_long, illid_illch, overst };
//typedef enum errorTypes ERRORtypes;

int cErrors = 0; //�� ���� ������ ī��Ʈ�ϴ� ���� (overflow�� ��츦 �����ϰ� main���� ����Ѵ�.)
char* error_message; //���� �޼����� ��� ���� (���ο��� error_message�� ����Ѵ�.)


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