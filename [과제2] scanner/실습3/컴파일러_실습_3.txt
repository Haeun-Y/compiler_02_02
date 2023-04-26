%{
#include <stdio.h>
#include <stdlib.h>
enum tnumber { TEOF, TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, TEQUAL, TNOTEQU,TLESSE,TGREATE, TAND, TOR, TINC, TDEC, TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TIDENT, TNUMBER  };
%}

letter	[a-zA-Z_]
digit	[0-9]

%%
"const"		return(TCONST);
"else"		return(TELSE);
"if"			return(TIF);
"int"			return(TINT);
"return"		return(TRETURN);
"void"		return(TVOID);
"while"		return(TWHILE);
"=="			return(TEQUAL);
"!="			return(TNOTEQU);
"<="			return(TLESSE);
">="			return(TGREATE);
"&&"			return(TAND);
"||"			return(TOR);
"++"			return(TINC);
"--"			return(TDEC);
"+="			return(TADDASSIGN);
"-="			return(TSUBASSIGN);
"*="			return(TMULASSIGN);
"/="			return(TDIVASSIGN);
"%="			return(TMODASSIGN);
[A-Za-z_][A-Za-z_z0-9_]*		return(TIDENT);		
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?		return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*/"			;
"//".*				;
[ \t\n]				;
.				return(yytext[0]);
%%

void main()
{
	enum tnumber tn;  // token number
	printf("  Start of Lex\n");
	while  ((tn = yylex()) != TEOF) {
		switch (tn) {
			case TCONST  : printf("const\n");  break;
			case TELSE  : printf("else\n");  break;
			case TIF    : printf("if\n"); break;
			case TINT: printf("int\n"); break;
			case TRETURN  : printf("return\n");  break;
			case TVOID  : printf("void\n");  break;
			case TWHILE    : printf("while\n"); break;
			case TEQUAL: printf("equal\n"); break;
			case TNOTEQU  : printf("not_equal\n");  break;
			case TLESSE  : printf("less_than\n");  break;
			case TGREATE    : printf("greater_than\n"); break;
			case TAND: printf("and\n"); break;
			case TOR  : printf("or\n");  break;
			case TINC  : printf("increment\n");  break;
			case TDEC    : printf("decrement\n"); break;
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

int yywrap()
{
	printf("   End of Lex \n");
	return 1;
}
