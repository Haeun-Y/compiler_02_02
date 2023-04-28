%{
#include "tn.h"
%}

letter	[a-zA-Z_]
digit	[0-9]

%%
const		return(TCONST);
int			return(TINT);
return      return(TRETURN);
void        return(TVOID);
while       return(TWHILE);
if          return(TIF);
else		return(TELSE);
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
"<"             return(TLESS);
">"             return(TGREAT);
"++"			return(TINC);
"--"			return(TDEC);
"="             return(TASSIGN);
"+="			return(TADDASSIGN);
"-="			return(TSUBASSIGN);
"*="			return(TMULASSIGN);
"/="			return(TDIVASSIGN);
"%="			return(TMODASSIGN);
"("         return(TLPAREN);
")"         return(TRPAREN);
"{"         return(TLBRACE);
"}"         return(TRBRACE);
","				return(TCOMMA);
"["				return(TLBRACKET);
"]"				return(TRBRACKET);
";"				return(TSEMI);
"/*"([^*]|"*"+[^*/])*"*"+"/"    ;
"//".*                          ;
{letter}({letter}|{digit})*	{
    							if(yyleng > 12)
    							{
    								err = illid_long;
    								ReportError(err);
    								return(TERROR);
    							}
    							else
    							{
							    err = noerror;
    							    SymbolTable();
    							    if(err == overst) return(TERROR);
    							    return(TIDENT);
    							}
							}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?		return(TNUMBER);
[0-9]+[A-Za-z0-9_]+             { err = illid_digit; ReportError(err); return(TERROR);}
"\n"     lineNumber++;
[ \t]   ;
%%

int yywrap()
{
	return 1;
}
