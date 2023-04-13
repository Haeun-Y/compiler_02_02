#include <stdio.h>
#include <stdlib.h>

#include "tn.h"
extern char* yytext;

void main()
{
	enum tokentypes tn;  // token number
	printf("  Start of Lex\n");
	while ((tn = yylex()) != TEOF) {
		switch (tn) {
		case TCONST: printf("const\n");  break;
		case TELSE: printf("else\n");  break;
		case TIF: printf("if\n"); break;
		case TINT: printf("int\n"); break;
		case TRETURN: printf("return\n");  break;
		case TVOID: printf("void\n");  break;
		case TWHILE: printf("while\n"); break;
		case TEQUAL: printf("equal\n"); break;
		case TNOTEQU: printf("not_equal\n");  break;
		case TLESSE: printf("less_than\n");  break;
		case TGREATE: printf("greater_than\n"); break;
		case TAND: printf("and\n"); break;
		case TOR: printf("or\n");  break;
		case TINC: printf("increment\n");  break;
		case TDEC: printf("decrement\n"); break;
		case TADDASSIGN: printf("add_assign\n"); break;
		case TSUBASSIGN: printf("sub_assign\n"); break;
		case TMULASSIGN: printf("mul_assign\n"); break;
		case TDIVASSIGN: printf("div_assign\n"); break;
		case TMODASSIGN: printf("mod_assign\n"); break;
		case TIDENT: printf("identifier\n"); break;
		case TNUMBER: printf("number\n"); break;
		default: printf("%s\n", yytext); break;
		}
	}
}
