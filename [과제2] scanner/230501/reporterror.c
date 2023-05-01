/*
* reporterror.c - error report
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/04/27
*/
/* error messages
			overst :  overflow in ST. print the hashtable and abort
			illid_digit    : illegal identifier (start with digit)
			illid_long	: illegal identifier (too long identifier)
			illid_illch	: illegal characters
			real_num : real number 
*/
#include "tn.h"

void ReportError(ERRORtypes err)
{
	cErrors++;

	switch (err) {
	case overst:
		strcpy(error_message, "overflow");
		break;
	case illid_long:
		strcpy(error_message, "too long identifier");
		break;
	case illch:
		sprintf(error_message, "%s illegal character", yytext);
		break;
	case illid_digit:
		sprintf(error_message, "%s start with digit", yytext);
		break;
	case real_num:
		strcpy(error_message, "real number is not allowed");
	}
}
