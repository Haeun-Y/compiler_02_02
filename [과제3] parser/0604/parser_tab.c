
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDENT	258
#define	TNUMBER	259
#define	TCONST	260
#define	TELSE	261
#define	TIF	262
#define	TINT	263
#define	TRETURN	264
#define	TVOID	265
#define	TWHILE	266
#define	TASSIGN	267
#define	TADDASSIGN	268
#define	TSUBASSIGN	269
#define	TMULASSIGN	270
#define	TDIVASSIGN	271
#define	TMODASSIGN	272
#define	TOR	273
#define	TAND	274
#define	TEQUAL	275
#define	TNOTEQU	276
#define	TGREATE	277
#define	TLESSE	278
#define	TLESS	279
#define	TGREAT	280
#define	TINC	281
#define	TDEC	282
#define	TSEMI	283
#define	TPLUS	284
#define	TMINUS	285
#define	TSTAR	286
#define	TSLASH	287
#define	TMOD	288
#define	TNOT	289
#define	TLPAREN	290
#define	TRPAREN	291
#define	TLBRACE	292
#define	TRBRACE	293
#define	TLBRACKET	294
#define	TRBRACKET	295
#define	TCOMMA	296
#define	TERROR	297
#define	TCOMMENT	298
#define	LOWER_THEN_ELSE	299
#define	LOW	300
#define	HIGH	301

#line 7 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

extern yylex();
extern yyerror(s);

int type_int = 0;
int type_void = 0;
int type_param = 0;
int type_const = 0;


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		211
#define	YYFLAG		-32768
#define	YYNTBASE	47

#define YYTRANSLATE(x) ((unsigned)(x) <= 301 ? yytranslate[x] : 93)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    13,    16,    19,    22,
    23,    28,    30,    32,    35,    37,    39,    41,    43,    45,
    47,    51,    55,    57,    58,    60,    64,    68,    70,    73,
    76,    81,    86,    88,    89,    91,    94,    98,   102,   104,
   108,   111,   113,   117,   121,   123,   128,   133,   135,   137,
   138,   140,   141,   143,   146,   149,   151,   153,   155,   157,
   159,   161,   164,   167,   169,   173,   174,   180,   188,   193,
   198,   204,   210,   215,   219,   223,   225,   227,   231,   235,
   239,   243,   247,   251,   255,   259,   263,   267,   271,   275,
   277,   281,   285,   287,   291,   295,   297,   301,   305,   309,
   313,   315,   319,   323,   327,   331,   335,   339,   343,   347,
   349,   353,   357,   361,   365,   367,   371,   375,   379,   383,
   387,   391,   393,   396,   399,   402,   405,   408,   411,   414,
   417,   419,   422,   427,   432,   437,   442,   445,   448,   450,
   451,   453,   455,   459,   461,   463,   467,   471
};

static const short yyrhs[] = {    48,
     0,    49,     0,    48,    49,     0,    50,     0,    66,     0,
    43,     0,    51,    63,     0,    51,    28,     0,    51,     1,
     0,     0,    53,    58,    52,    59,     0,    54,     0,    55,
     0,    54,    55,     0,    56,     0,    57,     0,     5,     0,
     8,     0,    10,     0,     3,     0,    35,    60,    36,     0,
    35,    60,     1,     0,    61,     0,     0,    62,     0,    61,
    41,    62,     0,    61,    62,     1,     0,    10,     0,     8,
    69,     0,    69,     1,     0,    37,    64,    71,    38,     0,
    37,    64,    71,     1,     0,    65,     0,     0,    66,     0,
    65,    66,     0,    53,    67,    28,     0,    53,    67,     1,
     0,    68,     0,    67,    41,    68,     0,    67,    68,     0,
    69,     0,    69,    12,     4,     0,    69,    12,    42,     0,
     3,     0,     3,    39,    70,    40,     0,     3,    39,    70,
     1,     0,    42,     0,     4,     0,     0,    72,     0,     0,
    73,     0,    72,    73,     0,    72,    66,     0,    63,     0,
    74,     0,    76,     0,    77,     0,    78,     0,    43,     0,
    75,    28,     0,    79,     1,     0,    79,     0,    75,    41,
    79,     0,     0,     7,    35,    79,    36,    73,     0,     7,
    35,    79,    36,    73,     6,    73,     0,     7,    35,     1,
    36,     0,     7,    35,    79,     1,     0,    11,    35,    79,
    36,    73,     0,    11,    35,    79,     1,    73,     0,    11,
    35,     1,    36,     0,     9,    75,    28,     0,     9,    75,
     1,     0,    80,     0,    81,     0,    87,    12,    80,     0,
    87,    12,     1,     0,    87,    13,    80,     0,    87,    13,
     1,     0,    87,    14,    80,     0,    87,    14,     1,     0,
    87,    15,    80,     0,    87,    15,     1,     0,    87,    16,
    80,     0,    87,    16,     1,     0,    87,    17,    80,     0,
    87,    17,     1,     0,    82,     0,    81,    18,    82,     0,
    81,    18,     1,     0,    83,     0,    82,    19,    83,     0,
    82,    19,     1,     0,    84,     0,    83,    20,    84,     0,
    83,    20,     1,     0,    83,    21,    84,     0,    83,    21,
     1,     0,    85,     0,    84,    24,    85,     0,    84,    24,
     1,     0,    84,    25,    85,     0,    84,    25,     1,     0,
    84,    22,    85,     0,    84,    22,     1,     0,    84,    23,
    85,     0,    84,    23,     1,     0,    86,     0,    85,    29,
    86,     0,    85,    29,     1,     0,    85,    30,    86,     0,
    85,    30,     1,     0,    87,     0,    86,    31,    87,     0,
    86,    31,     1,     0,    86,    32,    87,     0,    86,    32,
     1,     0,    86,    33,    87,     0,    86,    33,     1,     0,
    88,     0,    30,    87,     0,    30,     1,     0,    34,    87,
     0,    34,     1,     0,    26,    87,     0,    26,     1,     0,
    27,    87,     0,    27,     1,     0,    92,     0,     3,     3,
     0,    88,    39,    79,    40,     0,    88,    39,    79,     1,
     0,    88,    35,    89,    36,     0,    88,    35,    89,     1,
     0,    88,    26,     0,    88,    27,     0,    90,     0,     0,
    91,     0,    80,     0,    91,    41,    80,     0,     3,     0,
     4,     0,    35,    79,    36,     0,    35,    79,     1,     0,
    42,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    35,    38,    39,    42,    43,    44,    47,    48,    49,    52,
    53,    55,    58,    59,    62,    63,    66,    69,    70,    73,
    90,    91,    94,    95,    98,    99,   100,   103,   104,   105,
   108,   109,   112,   113,   116,   117,   120,   121,   124,   125,
   126,   128,   129,   130,   133,   159,   183,   184,   187,   188,
   191,   192,   195,   196,   197,   200,   201,   202,   203,   204,
   205,   208,   209,   210,   211,   212,   215,   216,   217,   218,
   221,   222,   223,   226,   227,   230,   233,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   248,
   249,   250,   253,   254,   255,   258,   259,   260,   261,   262,
   265,   266,   267,   268,   269,   270,   271,   272,   273,   276,
   277,   278,   279,   280,   283,   284,   285,   286,   287,   288,
   289,   292,   293,   294,   295,   296,   297,   298,   299,   300,
   303,   304,   305,   306,   307,   308,   309,   310,   313,   314,
   317,   320,   321,   324,   332,   333,   334,   335
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TCONST","TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TASSIGN",
"TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TOR","TAND",
"TEQUAL","TNOTEQU","TGREATE","TLESSE","TLESS","TGREAT","TINC","TDEC","TSEMI",
"TPLUS","TMINUS","TSTAR","TSLASH","TMOD","TNOT","TLPAREN","TRPAREN","TLBRACE",
"TRBRACE","TLBRACKET","TRBRACKET","TCOMMA","TERROR","TCOMMENT","LOWER_THEN_ELSE",
"LOW","HIGH","mini_c","translation_unit","external_dcl","function_def","function_header",
"@1","dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier","type_specifier",
"function_name","formal_param","opt_formal_param","formal_param_list","param_dcl",
"compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    47,    48,    48,    49,    49,    49,    50,    50,    50,    52,
    51,    53,    54,    54,    55,    55,    56,    57,    57,    58,
    59,    59,    60,    60,    61,    61,    61,    62,    62,    62,
    63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
    67,    68,    68,    68,    69,    69,    69,    69,    70,    70,
    71,    71,    72,    72,    72,    73,    73,    73,    73,    73,
    73,    74,    74,    75,    75,    75,    76,    76,    76,    76,
    77,    77,    77,    78,    78,    79,    80,    80,    80,    80,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
    81,    81,    82,    82,    82,    83,    83,    83,    83,    83,
    84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
    85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
    86,    87,    87,    87,    87,    87,    87,    87,    87,    87,
    88,    88,    88,    88,    88,    88,    88,    88,    89,    89,
    90,    91,    91,    92,    92,    92,    92,    92
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     2,     2,     2,     0,
     4,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     3,     3,     1,     0,     1,     3,     3,     1,     2,     2,
     4,     4,     1,     0,     1,     2,     3,     3,     1,     3,
     2,     1,     3,     3,     1,     4,     4,     1,     1,     0,
     1,     0,     1,     2,     2,     1,     1,     1,     1,     1,
     1,     2,     2,     1,     3,     0,     5,     7,     4,     4,
     5,     5,     4,     3,     3,     1,     1,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
     3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
     1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
     3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
     3,     1,     2,     2,     2,     2,     2,     2,     2,     2,
     1,     2,     4,     4,     4,     4,     2,     2,     1,     0,
     1,     1,     3,     1,     1,     3,     3,     1
};

static const short yydefact[] = {     0,
    17,    18,    19,     6,     1,     2,     4,     0,     0,    12,
    13,    15,    16,     5,     3,     9,     8,    34,     7,    45,
    48,    10,     0,    39,    42,    14,     0,    52,    33,    35,
    50,     0,    38,    45,    37,     0,    41,     0,   144,   145,
     0,    66,     0,     0,     0,     0,     0,     0,   148,    61,
    56,     0,    51,    53,    57,     0,    58,    59,    60,     0,
    76,    77,    90,    93,    96,   101,   110,   115,   122,   131,
    36,    49,     0,    24,    11,    40,    43,    44,   132,     0,
     0,    64,     0,   128,   127,   130,   129,   124,   123,   126,
   125,     0,    32,    31,    55,    54,    62,     0,    63,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
   140,     0,    47,    46,     0,    28,     0,    23,    25,     0,
     0,     0,    75,    74,     0,     0,   147,   146,    65,    92,
    91,   115,    95,    94,    98,    97,   100,    99,   107,   106,
   109,   108,   103,   102,   105,   104,   112,   111,   114,   113,
   117,   116,   119,   118,   121,   120,    79,    78,    81,    80,
    83,    82,    85,    84,    87,    86,    89,    88,   142,     0,
   139,   141,     0,    29,    22,    21,     0,     0,    30,    69,
    70,    66,    73,    66,    66,   136,   135,     0,   134,   133,
    26,    27,    67,    72,    71,   143,    66,    68,     0,     0,
     0
};

static const short yydefgoto[] = {   209,
     5,     6,     7,     8,    32,    27,    10,    11,    12,    13,
    22,    75,   127,   128,   129,    51,    28,    29,    14,    23,
    24,    25,    73,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,   180,   181,   182,    70
};

static const short yypact[] = {   108,
-32768,-32768,-32768,-32768,   108,-32768,-32768,    10,    23,    34,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    34,-32768,     2,
-32768,-32768,    28,-32768,     0,-32768,    42,   508,    34,-32768,
    15,     8,-32768,    -5,-32768,    42,-32768,    98,    87,-32768,
    84,   468,   118,    24,    59,    94,   122,   468,-32768,-32768,
-32768,    29,   479,-32768,-32768,    -8,-32768,-32768,-32768,    12,
-32768,    93,   136,   113,   156,   129,    76,   211,    -3,-32768,
-32768,-32768,    56,   102,-32768,-32768,-32768,-32768,-32768,   142,
    20,-32768,   159,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    99,-32768,-32768,-32768,-32768,-32768,   468,-32768,   170,
   187,   205,   215,   233,   250,   261,   278,   296,   306,   324,
   341,   352,   369,   387,   397,   415,   432,   443,-32768,-32768,
   468,   468,-32768,-32768,    42,-32768,   114,    96,-32768,   160,
   134,   130,-32768,-32768,   139,   131,-32768,-32768,-32768,-32768,
   136,-32768,-32768,   113,-32768,   156,-32768,   156,-32768,   129,
-32768,   129,-32768,   129,-32768,   129,-32768,    76,-32768,    76,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   146,
-32768,   124,    90,-32768,-32768,-32768,   102,   182,-32768,-32768,
-32768,   537,-32768,   537,   537,-32768,-32768,   468,-32768,-32768,
-32768,-32768,   181,-32768,-32768,-32768,   537,-32768,   192,   195,
-32768
};

static const short yypgoto[] = {-32768,
-32768,   193,-32768,-32768,-32768,   117,-32768,   189,-32768,-32768,
-32768,-32768,-32768,-32768,  -119,   199,-32768,-32768,    74,-32768,
    -1,   -73,-32768,-32768,-32768,   -53,-32768,   168,-32768,-32768,
-32768,   -34,  -111,-32768,   111,   119,   100,   165,   135,   -29,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		580


static const short yytable[] = {    96,
   130,   168,   170,   172,   174,   176,   178,    82,   188,   179,
    16,    38,    99,    92,    85,    87,    89,    91,    72,    97,
   133,    37,   119,   120,    84,    20,    39,    40,    33,    93,
    34,   121,    98,    31,    76,   122,   -20,    17,     1,   -64,
    31,     2,    74,     3,    34,   132,    18,   134,   136,    44,
    45,   184,   -64,    46,   130,    35,   123,    47,    48,    86,
    98,    39,    40,   139,    21,    49,    94,   201,    36,    21,
   142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
   162,   164,   166,    21,    44,    45,   206,   183,    46,    79,
   199,    30,    47,    48,    88,   124,    39,    40,    34,   137,
    49,    77,    71,   125,    34,   126,   110,   111,   112,   125,
   100,   126,     1,   130,   185,     2,     9,     3,    80,    44,
    45,     9,    90,    46,    39,    40,    95,    47,    48,   200,
   191,   194,   102,   103,   138,    49,   187,    21,   203,    78,
   204,   205,   131,    21,    39,    40,   196,    44,    45,   186,
     4,    46,    83,   208,   101,    47,    48,   108,   109,   135,
   189,    39,    40,    49,   198,   192,   195,    44,    45,   190,
   140,    46,    39,    40,   193,    47,    48,   104,   105,   106,
   107,   197,   202,    49,    44,    45,   207,   143,    46,    39,
    40,   210,    47,    48,   211,    44,    45,    15,    26,    46,
    49,   146,   148,    47,    48,   145,    19,    39,    40,    81,
   141,    49,    44,    45,     0,   147,    46,    39,    40,   144,
    47,    48,   113,   114,   115,   116,   117,   118,    49,     0,
    44,    45,     0,   149,    46,    39,    40,     0,    47,    48,
    44,    45,   158,   160,    46,     0,    49,     0,    47,    48,
   151,     0,    39,    40,     0,     0,    49,     0,    44,    45,
     0,   153,    46,    39,    40,     0,    47,    48,   150,   152,
   154,   156,     0,     0,    49,    44,    45,     0,   155,    46,
    39,    40,     0,    47,    48,     0,    44,    45,     0,     0,
    46,    49,     0,     0,    47,    48,   157,     0,    39,    40,
     0,     0,    49,    44,    45,     0,   159,    46,    39,    40,
     0,    47,    48,     0,     0,     0,     0,     0,     0,    49,
     0,    44,    45,     0,   161,    46,    39,    40,     0,    47,
    48,    44,    45,     0,     0,    46,     0,    49,     0,    47,
    48,   163,     0,    39,    40,     0,     0,    49,     0,    44,
    45,     0,   165,    46,    39,    40,     0,    47,    48,     0,
     0,     0,     0,     0,     0,    49,    44,    45,     0,   167,
    46,    39,    40,     0,    47,    48,     0,    44,    45,     0,
     0,    46,    49,     0,     0,    47,    48,   169,     0,    39,
    40,     0,     0,    49,    44,    45,     0,   171,    46,    39,
    40,     0,    47,    48,     0,     0,     0,     0,     0,     0,
    49,     0,    44,    45,     0,   173,    46,    39,    40,     0,
    47,    48,    44,    45,     0,     0,    46,     0,    49,     0,
    47,    48,   175,     0,    39,    40,     0,     0,    49,     0,
    44,    45,     0,   177,    46,    39,    40,     0,    47,    48,
     0,     0,     0,     0,     0,     0,    49,    44,    45,     0,
     0,    46,     0,     0,     0,    47,    48,     0,    44,    45,
    39,    40,    46,    49,     0,     0,    47,    48,     0,     0,
     0,    39,    40,     1,    49,    41,     2,    42,     3,    43,
     0,     0,     0,    44,    45,     0,     0,    46,     0,     0,
     0,    47,    48,     0,    44,    45,   -66,     0,    46,    49,
    39,    40,    47,    48,    41,    18,    42,     0,    43,   -66,
    49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    44,    45,   -66,     0,    46,     0,    39,
    40,    47,    48,    41,    18,    42,     0,    43,   -66,    49,
    50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    44,    45,     0,     0,    46,     0,     0,     0,
    47,    48,     0,    18,     0,     0,     0,     0,    49,    50
};

static const short yycheck[] = {    53,
    74,   113,   114,   115,   116,   117,   118,    42,   128,   121,
     1,    12,     1,    48,    44,    45,    46,    47,     4,    28,
     1,    23,    26,    27,     1,     3,     3,     4,     1,     1,
     3,    35,    41,    39,    36,    39,    35,    28,     5,    28,
    39,     8,    35,    10,     3,    80,    37,    28,    83,    26,
    27,   125,    41,    30,   128,    28,     1,    34,    35,     1,
    41,     3,     4,    98,    42,    42,    38,   187,    41,    42,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,    42,    26,    27,   198,   122,    30,     3,
     1,    18,    34,    35,     1,    40,     3,     4,     3,     1,
    42,     4,    29,     8,     3,    10,    31,    32,    33,     8,
    18,    10,     5,   187,     1,     8,     0,    10,    35,    26,
    27,     5,     1,    30,     3,     4,    53,    34,    35,    40,
     1,     1,    20,    21,    36,    42,    41,    42,   192,    42,
   194,   195,     1,    42,     3,     4,     1,    26,    27,    36,
    43,    30,    35,   207,    19,    34,    35,    29,    30,     1,
     1,     3,     4,    42,    41,    36,    36,    26,    27,    36,
     1,    30,     3,     4,    36,    34,    35,    22,    23,    24,
    25,    36,     1,    42,    26,    27,     6,     1,    30,     3,
     4,     0,    34,    35,     0,    26,    27,     5,    10,    30,
    42,   102,   103,    34,    35,     1,     8,     3,     4,    42,
   100,    42,    26,    27,    -1,     1,    30,     3,     4,   101,
    34,    35,    12,    13,    14,    15,    16,    17,    42,    -1,
    26,    27,    -1,     1,    30,     3,     4,    -1,    34,    35,
    26,    27,   108,   109,    30,    -1,    42,    -1,    34,    35,
     1,    -1,     3,     4,    -1,    -1,    42,    -1,    26,    27,
    -1,     1,    30,     3,     4,    -1,    34,    35,   104,   105,
   106,   107,    -1,    -1,    42,    26,    27,    -1,     1,    30,
     3,     4,    -1,    34,    35,    -1,    26,    27,    -1,    -1,
    30,    42,    -1,    -1,    34,    35,     1,    -1,     3,     4,
    -1,    -1,    42,    26,    27,    -1,     1,    30,     3,     4,
    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
    -1,    26,    27,    -1,     1,    30,     3,     4,    -1,    34,
    35,    26,    27,    -1,    -1,    30,    -1,    42,    -1,    34,
    35,     1,    -1,     3,     4,    -1,    -1,    42,    -1,    26,
    27,    -1,     1,    30,     3,     4,    -1,    34,    35,    -1,
    -1,    -1,    -1,    -1,    -1,    42,    26,    27,    -1,     1,
    30,     3,     4,    -1,    34,    35,    -1,    26,    27,    -1,
    -1,    30,    42,    -1,    -1,    34,    35,     1,    -1,     3,
     4,    -1,    -1,    42,    26,    27,    -1,     1,    30,     3,
     4,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
    42,    -1,    26,    27,    -1,     1,    30,     3,     4,    -1,
    34,    35,    26,    27,    -1,    -1,    30,    -1,    42,    -1,
    34,    35,     1,    -1,     3,     4,    -1,    -1,    42,    -1,
    26,    27,    -1,     1,    30,     3,     4,    -1,    34,    35,
    -1,    -1,    -1,    -1,    -1,    -1,    42,    26,    27,    -1,
    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    26,    27,
     3,     4,    30,    42,    -1,    -1,    34,    35,    -1,    -1,
    -1,     3,     4,     5,    42,     7,     8,     9,    10,    11,
    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
    -1,    34,    35,    -1,    26,    27,    28,    -1,    30,    42,
     3,     4,    34,    35,     7,    37,     9,    -1,    11,    41,
    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    26,    27,    28,    -1,    30,    -1,     3,
     4,    34,    35,     7,    37,     9,    -1,    11,    41,    42,
    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,
    34,    35,    -1,    37,    -1,    -1,    -1,    -1,    42,    43
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 9:
#line 49 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 10:
#line 52 "parser.y"
{type_param = 1;;
    break;}
case 17:
#line 66 "parser.y"
{type_const = 1;;
    break;}
case 18:
#line 69 "parser.y"
{type_int = 1; type_void = 0;;
    break;}
case 19:
#line 70 "parser.y"
{type_void = 1; type_int = 0;;
    break;}
case 20:
#line 74 "parser.y"
{   //identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
							if (!found){ 
								if(type_void == 1){
									idttype = 3; //fuction name, return type = void
                                    HT[hashcode]->type = idttype;
									type_void = 0;
								}
								if(type_int == 1){
									idttype = 4; //fuction name, return type = int
									HT[hashcode]->type = idttype;
									type_int = 0;
								}
							}
						;
    break;}
case 21:
#line 90 "parser.y"
{type_param = 0;;
    break;}
case 22:
#line 91 "parser.y"
{yyerrok;printError(noparen);;
    break;}
case 27:
#line 100 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 28:
#line 103 "parser.y"
{type_void = 0;;
    break;}
case 29:
#line 104 "parser.y"
{type_param = 1;;
    break;}
case 30:
#line 105 "parser.y"
{yyerrok; printError(wrongparam);;
    break;}
case 32:
#line 109 "parser.y"
{yyerrok; printError(nobrace);;
    break;}
case 38:
#line 121 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 41:
#line 126 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 45:
#line 134 "parser.y"
{
						//identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
						if (!found){
							if(type_param == 1){
								if(type_int == 1){
									idttype = 5; //integer scalar fuction parameter
									HT[hashcode]->type = idttype;
									type_int = 0;
								}
								type_param = 0;
							 }
							else{
								if(type_int == 1){
									idttype = 1; //integer scalar variable
									 HT[hashcode]->type = idttype;

									if(type_const ==1){
										idttype = 8; //integer scalar const
										HT[hashcode]->type = idttype;
										type_const = 0;
									}
				   				}
							}
						}
					;
    break;}
case 46:
#line 160 "parser.y"
{ 
						//identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
						if (!found){
							if(type_param == 1 && type_int == 1){
								idttype = 6; //integer array fuction parameter
								HT[hashcode]->type = idttype;
								type_param = 0;
								type_int = 0;
							}
							else{
								if(type_int == 1){
									idttype = 2; //integer array variable
									HT[hashcode]->type = idttype;

									if(type_const ==1){
										idttype = 9; //integer array const
										HT[hashcode]->type = idttype;
										type_const = 0;
									}
								}
							}
						}
					;
    break;}
case 47:
#line 183 "parser.y"
{yyerrok; printError(nobrack);;
    break;}
case 63:
#line 209 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 69:
#line 217 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 70:
#line 218 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 72:
#line 222 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 73:
#line 223 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 75:
#line 227 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 79:
#line 235 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 81:
#line 237 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 83:
#line 239 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 85:
#line 241 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 87:
#line 243 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 89:
#line 245 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 92:
#line 250 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 95:
#line 255 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 98:
#line 260 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 100:
#line 262 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 103:
#line 267 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 105:
#line 269 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 107:
#line 271 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 109:
#line 273 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 112:
#line 278 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 114:
#line 280 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 117:
#line 285 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 119:
#line 287 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 121:
#line 289 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 124:
#line 294 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 126:
#line 296 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 128:
#line 298 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 130:
#line 300 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 132:
#line 304 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 134:
#line 306 "parser.y"
{yyerrok; printError(nobrack);;
    break;}
case 136:
#line 308 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 144:
#line 325 "parser.y"
{
							//identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
							if (!found){
								idttype = 10;
                                HT[hashcode]->type = idttype;
							}
						;
    break;}
case 147:
#line 334 "parser.y"
{yyerrok; printError(noparen);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 337 "parser.y"

