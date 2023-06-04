/*
* scanner.l
* programmer - 권영경, 옥진주, 윤하은, 최예원
* date - 2023/06/01
*/

%{
#include <stdio.h>
#include <stdlib.h>

#include "tn.h"
#include "glob.h"
%}

letter	[a-zA-Z_]
digit	[0-9]

%%
"const"                          return(TCONST);
"else"                            return(TELSE);
"if"                               return(TIF);
"int"                              return(TINT);
"return"                         return(TRETURN);
"void"                           return(TVOID);
"while"                          return(TWHILE);
","                                return(TCOMMA); 
";"                                return(TSEMI);
"("                               return(TLPAREN);
")"                               return(TRPAREN);
"{"                               return(TLBRACE);
"}"                               return(TRBRACE);
"["                                return(TLBRACKET);
"]"                               return(TRBRACKET);
"=="                             return(TEQUAL);
"!="                              return(TNOTEQU);
"<="                             return(TLESSE);
">="                             return(TGREATE);
"<"                             return(TLESS);
">"                             return(TGREAT);
"&&"                             return(TAND);
"||"                                return(TOR);
"!"                                 return(TNOT);    
"++"                              return(TINC);
"--"                                return(TDEC);
"+"                                return(TPLUS);
"-"                                return(TMINUS);
"*"                                return(TSTAR);
"/"                                return(TSLASH);
"%"                                return(TMOD);
"="                                return(TASSIGN);
"+="                              return(TADDASSIGN);
"-="                               return(TSUBASSIGN);
"*="                               return(TMULASSIGN);
"/="                               return(TDIVASSIGN);
"%="                              return(TMODASSIGN);
"/*"([^*]|"*"+[^*/])*"*"+"/"    {
                                    startLineNumber = cLines;
                                    for(int i = 0; i<yyleng; i++)
                                    {
                                        if(yytext[i] == '\n')
                                            cLines++;
                                    }
                                    return(TCOMMENT);
                                } 
"//".*                          {
                                    startLineNumber = cLines; 
                                    return(TCOMMENT);
                                }
{letter}({letter}|{digit})*	{
    							if(yyleng > 12)
    							{
    								err = illid_long;
                                    printError(err);
    								return(TERROR);
    							}
    							else
    							{
    							    symtable();
    							    if(err == overst)
                                    {
                                        printError(err);
                                        return(TERROR);
                                    }
    							    return(TIDENT);
    							}
							}
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]+)?		return(TNUMBER); //정수 상수의 경우, 부호를 포함하지 않고 인식함. 연산자는 개별 토큰 인식이 되므로 부호는 고려하지 않음.
{digit}+"."{digit}+(e[+-]?{digit}+)?  {
                                            err = real_num;
                                            printError(err);
                                            return(TERROR);
                                      } //실수 들어올 시 에러로 간주함. Floating Point 경우는 제외하였음.
{digit}+[A-Za-z0-9_]+             { err = illid_digit; printError(err); return(TERROR);}
"\n"     cLines++;
[ \t]   ;
.                       { err = illch; printError(err); return(TERROR);}
%%

int yywrap()
{
	return 1;
}
