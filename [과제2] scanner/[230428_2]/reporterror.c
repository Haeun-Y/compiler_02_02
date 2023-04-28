/* error messages
			overst :  overflow in ST. print the hashtable and abort
			illid_digit    : illegal identifier (start with digit)
			illid_long	: illegal identifier (too long identifier)
			illid_illch	: illegal identifier (containing illegal characters)
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
	case illid_illch:
		strcpy(error_message, "identifier containing illegal character");
		break;
	case illid_digit:
		strcpy(error_message, "start with digit");
		break;
	}
}