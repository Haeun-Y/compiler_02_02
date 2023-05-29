%{
#include "tn.h"
%}

%option lineNumber
letter	[a-zA-Z_]
digit	[0-9]

%%
[Cc][Oo][Nn][Ss][Tt]		return(TCONST);
[Ii][Nn][Tt]		        return(TINT);
[Rr][Ee][Tt][Uu][Rr][Nn]    return(TRETURN);
[Vv][Oo][Ii][Dd]            return(TVOID);
[Ww][Hh][Ii][Ll][Ee]        return(TWHILE);
[Ii][Ff]                    return(TIF);
[Ee][Ll][Ss][Ee]		    return(TELSE);
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
"("             return(TLPAREN);
")"             return(TRPAREN);
"{"             return(TLBRACE);
"}"             return(TRBRACE);
","				return(TCOMMA);
"["				return(TLBRACKET);
"]"				return(TRBRACKET);
";"				return(TSEMI);
"/*"([^*]|"*"+[^*/])*"*"+"/"    {
                                    startLineNumber = lineNumber;
                                    for(int i = 0; i<yyleng; i++)
                                    {
                                        if(yytext[i] == '\n')
                                            lineNumber++;
                                    }
                                    return(TCOMMENT);
                                } 
"//".*                          {
                                    startLineNumber = lineNumber; 
                                    return(TCOMMENT);
                                }
{letter}({letter}|{digit})*	{
    							if(yyleng > 12)
    							{
    								err = illid_long;
    								ReportError(err);
    								return(TERROR);
    							}
    							else
    							{
    							    SymbolTable();
    							    if(err == overst)
                                    {
                                        ReportError(err);
                                        return(TERROR);
                                    }
    							    return(TIDENT);
    							}
							}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]+)?		return(TNUMBER); //정수 상수의 경우, 부호를 포함하지 않고 인식함. 연산자는 개별 토큰 인식이 되므로 부호는 고려하지 않음.
{digit}+"."{digit}+(e[+-]?{digit}+)?  {
                                            err = real_num;
                                            ReportError(err);
                                            return(TERROR);
                                      } //실수 들어올 시 에러로 간주함. Floating Point 경우는 제외하였음.
{digit}+[A-Za-z0-9_]+             { err = illid_digit; ReportError(err); return(TERROR);}
"\n"     lineNumber++;
[ \t]   ;
.                       { err = illch; ReportError(err); return(TERROR);}
%%

int yywrap()
{
	return 1;
}
