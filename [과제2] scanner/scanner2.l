%{
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
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
"+"             return(TADD);
"-"             return(TSUB);
"*"             return(TMUL);
"/"             return(TDIV);
"%"             return(TMOD);
"!"             return(TNOT);
"&&"            return(TAND);
"||"            return(TOR);
"=="			return(TEQUAL);
"!="			return(TNOTEQU);
"<="			return(TLESSE);
">="			return(TGREATE);
"++"			return(TINC);
"--"			return(TDEC);
"="             return(TASSIGN);
"+="			return(TADDASSIGN);
"-="			return(TSUBASSIGN);
"*="			return(TMULASSIGN);
"/="			return(TDIVASSIGN);
"%="			return(TMODASSIGN);
"("				return(TLPAREN);
")"				return(TRPAREN);
","				return(TCOMMA);
"{"				return(TLBRACE);
"}"				return(TRBRACE);
"["				return(TLBRACKET);
"]"				return(TRBRACKET);
";"				return(TSEMI);
[A-Za-z_][A-Za-z_z0-9_]*		{
                                if(yyleng > 12)
                                {
                                    err = illid_long; cErrors++; ReportError(err); return(TERROR);
                                }
                                else
                                {
                                    SymbolTable();
                                    return(TIDENT);
                                }
                                }	
[0-9]+[A-Za-z0-9_]+             { err = illid_digit; cErrors++; ReportError(err); return(TERROR);}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?		return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*/"			;
"//".*				;
[ \t]				;
"\n"			{ lineNumber++; }
.               { err = illid_illch; cErrors++; ReportError(err); return(TERROR);}
%%

int yywrap()
{
	return 1;
}
