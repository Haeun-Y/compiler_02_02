
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



#define	YYFINAL		215
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
    23,    28,    32,    34,    36,    39,    41,    43,    45,    47,
    49,    51,    55,    59,    61,    62,    64,    68,    72,    74,
    77,    80,    85,    90,    92,    93,    95,    98,   102,   106,
   108,   112,   115,   117,   121,   125,   127,   132,   137,   139,
   141,   142,   144,   145,   147,   150,   153,   155,   157,   159,
   161,   163,   165,   168,   171,   173,   177,   178,   184,   192,
   197,   202,   208,   214,   219,   223,   227,   229,   231,   235,
   239,   243,   247,   251,   255,   259,   263,   267,   271,   275,
   279,   281,   285,   289,   291,   295,   299,   301,   305,   309,
   313,   317,   319,   323,   327,   331,   335,   339,   343,   347,
   351,   353,   357,   361,   365,   369,   371,   375,   379,   383,
   387,   391,   395,   397,   400,   403,   406,   409,   412,   415,
   418,   421,   423,   426,   431,   436,   441,   446,   449,   452,
   454,   455,   457,   459,   463,   465,   467,   471,   475
};

static const short yyrhs[] = {    48,
     0,    49,     0,    48,    49,     0,    50,     0,    66,     0,
    43,     0,    51,    63,     0,    51,    28,     0,    51,     1,
     0,     0,    53,    58,    52,    59,     0,     3,    58,    59,
     0,    54,     0,    55,     0,    54,    55,     0,    56,     0,
    57,     0,     5,     0,     8,     0,    10,     0,     3,     0,
    35,    60,    36,     0,    35,    60,     1,     0,    61,     0,
     0,    62,     0,    61,    41,    62,     0,    61,    62,     1,
     0,    10,     0,     8,    69,     0,    69,     1,     0,    37,
    64,    71,    38,     0,    37,    64,    71,     1,     0,    65,
     0,     0,    66,     0,    65,    66,     0,    53,    67,    28,
     0,    53,    67,     1,     0,    68,     0,    67,    41,    68,
     0,    67,    68,     0,    69,     0,    69,    12,     4,     0,
    69,    12,    42,     0,     3,     0,     3,    39,    70,    40,
     0,     3,    39,    70,     1,     0,    42,     0,     4,     0,
     0,    72,     0,     0,    73,     0,    72,    73,     0,    72,
    66,     0,    63,     0,    74,     0,    76,     0,    77,     0,
    78,     0,    43,     0,    75,    28,     0,    79,     1,     0,
    79,     0,    75,    41,    79,     0,     0,     7,    35,    79,
    36,    73,     0,     7,    35,    79,    36,    73,     6,    73,
     0,     7,    35,     1,    36,     0,     7,    35,    79,     1,
     0,    11,    35,    79,    36,    73,     0,    11,    35,    79,
     1,    73,     0,    11,    35,     1,    36,     0,     9,    75,
    28,     0,     9,    75,     1,     0,    80,     0,    81,     0,
    87,    12,    80,     0,    87,    12,     1,     0,    87,    13,
    80,     0,    87,    13,     1,     0,    87,    14,    80,     0,
    87,    14,     1,     0,    87,    15,    80,     0,    87,    15,
     1,     0,    87,    16,    80,     0,    87,    16,     1,     0,
    87,    17,    80,     0,    87,    17,     1,     0,    82,     0,
    81,    18,    82,     0,    81,    18,     1,     0,    83,     0,
    82,    19,    83,     0,    82,    19,     1,     0,    84,     0,
    83,    20,    84,     0,    83,    20,     1,     0,    83,    21,
    84,     0,    83,    21,     1,     0,    85,     0,    84,    24,
    85,     0,    84,    24,     1,     0,    84,    25,    85,     0,
    84,    25,     1,     0,    84,    22,    85,     0,    84,    22,
     1,     0,    84,    23,    85,     0,    84,    23,     1,     0,
    86,     0,    85,    29,    86,     0,    85,    29,     1,     0,
    85,    30,    86,     0,    85,    30,     1,     0,    87,     0,
    86,    31,    87,     0,    86,    31,     1,     0,    86,    32,
    87,     0,    86,    32,     1,     0,    86,    33,    87,     0,
    86,    33,     1,     0,    88,     0,    30,    87,     0,    30,
     1,     0,    34,    87,     0,    34,     1,     0,    26,    87,
     0,    26,     1,     0,    27,    87,     0,    27,     1,     0,
    92,     0,     3,     3,     0,    88,    39,    79,    40,     0,
    88,    39,    79,     1,     0,    88,    35,    89,    36,     0,
    88,    35,    89,     1,     0,    88,    26,     0,    88,    27,
     0,    90,     0,     0,    91,     0,    80,     0,    91,    41,
    80,     0,     3,     0,     4,     0,    35,    79,    36,     0,
    35,    79,     1,     0,    42,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    35,    38,    39,    42,    43,    44,    47,    48,    49,    52,
    53,    53,    56,    59,    60,    63,    64,    67,    70,    71,
    74,    91,    92,    95,    96,    99,   100,   101,   104,   105,
   106,   109,   110,   113,   114,   117,   118,   121,   122,   125,
   126,   127,   129,   130,   131,   134,   160,   184,   185,   188,
   189,   192,   193,   196,   197,   198,   201,   202,   203,   204,
   205,   206,   209,   210,   211,   212,   213,   216,   217,   218,
   219,   222,   223,   224,   227,   228,   231,   234,   235,   236,
   237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
   249,   250,   251,   254,   255,   256,   259,   260,   261,   262,
   263,   266,   267,   268,   269,   270,   271,   272,   273,   274,
   277,   278,   279,   280,   281,   284,   285,   286,   287,   288,
   289,   290,   293,   294,   295,   296,   297,   298,   299,   300,
   301,   304,   305,   306,   307,   308,   309,   310,   311,   314,
   315,   318,   321,   322,   325,   334,   335,   336,   337
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
    51,    51,    53,    54,    54,    55,    55,    56,    57,    57,
    58,    59,    59,    60,    60,    61,    61,    61,    62,    62,
    62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
    67,    67,    68,    68,    68,    69,    69,    69,    69,    70,
    70,    71,    71,    72,    72,    72,    73,    73,    73,    73,
    73,    73,    74,    74,    75,    75,    75,    76,    76,    76,
    76,    77,    77,    77,    78,    78,    79,    80,    80,    80,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    81,    81,    81,    82,    82,    82,    83,    83,    83,    83,
    83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
    85,    85,    85,    85,    85,    86,    86,    86,    86,    86,
    86,    86,    87,    87,    87,    87,    87,    87,    87,    87,
    87,    88,    88,    88,    88,    88,    88,    88,    88,    89,
    89,    90,    91,    91,    92,    92,    92,    92,    92
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     2,     2,     2,     0,
     4,     3,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     3,     3,     1,     0,     1,     3,     3,     1,     2,
     2,     4,     4,     1,     0,     1,     2,     3,     3,     1,
     3,     2,     1,     3,     3,     1,     4,     4,     1,     1,
     0,     1,     0,     1,     2,     2,     1,     1,     1,     1,
     1,     1,     2,     2,     1,     3,     0,     5,     7,     4,
     4,     5,     5,     4,     3,     3,     1,     1,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
     3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
     1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
     3,     3,     1,     2,     2,     2,     2,     2,     2,     2,
     2,     1,     2,     4,     4,     4,     4,     2,     2,     1,
     0,     1,     1,     3,     1,     1,     3,     3,     1
};

static const short yydefact[] = {     0,
     0,    18,    19,    20,     6,     1,     2,     4,     0,     0,
    13,    14,    16,    17,     5,    21,     0,     3,     9,     8,
    35,     7,    46,    49,    10,     0,    40,    43,    15,    25,
    12,     0,    53,    34,    36,    51,     0,    39,    46,    38,
     0,    42,     0,     0,    29,     0,    24,    26,     0,   145,
   146,     0,    67,     0,     0,     0,     0,     0,     0,   149,
    62,    57,     0,    52,    54,    58,     0,    59,    60,    61,
     0,    77,    78,    91,    94,    97,   102,   111,   116,   123,
   132,    37,    50,     0,    11,    41,    44,    45,    30,    23,
    22,     0,     0,    31,   133,     0,     0,    65,     0,   129,
   128,   131,   130,   125,   124,   127,   126,     0,    33,    32,
    56,    55,    63,     0,    64,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   138,   139,   141,     0,    48,    47,
    27,    28,     0,     0,    76,    75,     0,     0,   148,   147,
    66,    93,    92,   116,    96,    95,    99,    98,   101,   100,
   108,   107,   110,   109,   104,   103,   106,   105,   113,   112,
   115,   114,   118,   117,   120,   119,   122,   121,    80,    79,
    82,    81,    84,    83,    86,    85,    88,    87,    90,    89,
   143,     0,   140,   142,     0,    70,    71,    67,    74,    67,
    67,   137,   136,     0,   135,   134,    68,    73,    72,   144,
    67,    69,     0,     0,     0
};

static const short yydefgoto[] = {   213,
     6,     7,     8,     9,    37,    32,    11,    12,    13,    14,
    17,    31,    46,    47,    48,    62,    33,    34,    15,    26,
    27,    28,    84,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,   192,   193,   194,    81
};

static const short yypact[] = {    16,
    24,-32768,-32768,-32768,-32768,    16,-32768,-32768,   120,    36,
    32,-32768,-32768,-32768,-32768,-32768,    -1,-32768,-32768,-32768,
    32,-32768,    62,-32768,-32768,    76,-32768,    20,-32768,   103,
-32768,    45,   577,    32,-32768,    37,    -1,-32768,     4,-32768,
    45,-32768,    90,    45,-32768,    14,   102,-32768,    35,   105,
-32768,    65,   126,   127,    19,    54,    89,   124,   126,-32768,
-32768,-32768,    97,   548,-32768,-32768,    -3,-32768,-32768,-32768,
    81,-32768,   115,   136,    82,   220,   171,   204,   175,   143,
-32768,-32768,-32768,    51,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   103,   164,-32768,-32768,   137,    98,-32768,   172,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    84,-32768,-32768,
-32768,-32768,-32768,   126,-32768,   182,   192,   227,   237,   247,
   282,   292,   302,   337,   347,   357,   392,   402,   412,   447,
   457,   467,   502,   512,-32768,-32768,   126,   126,-32768,-32768,
-32768,-32768,   138,   106,-32768,-32768,   141,   113,-32768,-32768,
-32768,-32768,   136,-32768,-32768,    82,-32768,   220,-32768,   220,
-32768,   171,-32768,   171,-32768,   171,-32768,   171,-32768,   204,
-32768,   204,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   145,-32768,   139,    55,-32768,-32768,   606,-32768,   606,
   606,-32768,-32768,   126,-32768,-32768,   178,-32768,-32768,-32768,
   606,-32768,   194,   197,-32768
};

static const short yypgoto[] = {-32768,
-32768,   199,-32768,-32768,-32768,    29,-32768,   202,-32768,-32768,
   205,   183,-32768,-32768,   -41,   212,-32768,-32768,    -4,-32768,
    -8,   -16,-32768,-32768,-32768,   -64,-32768,   170,-32768,-32768,
-32768,   -52,  -121,-32768,   109,   112,    85,   177,    86,   -53,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		649


static const short yytable[] = {   112,
    98,   101,   103,   105,   107,    93,   108,   180,   182,   184,
   186,   188,   190,    49,    90,   191,    35,    42,     1,   100,
     2,    50,    51,     3,   113,     4,    16,    89,    10,    82,
    49,    43,    86,    30,    10,    94,     2,   114,    23,     3,
    83,     4,    36,   144,    55,    56,   148,    39,    57,    91,
   141,   139,    58,    59,   102,   205,    50,    51,     5,   111,
    60,   151,   154,   154,   154,   154,   154,   154,   154,   154,
   154,   154,   174,   176,   178,    49,    38,    24,    39,    55,
    56,   115,   210,    57,   149,   195,    24,    58,    59,   104,
   140,    50,    51,    87,   206,    60,   -21,   109,   145,    96,
    36,   118,   119,    40,    39,    39,   197,    95,   -65,    44,
    44,    45,    45,   200,    55,    56,    41,    24,    57,   150,
    19,   -65,    58,    59,   106,   146,    50,    51,    50,    51,
    60,    88,   116,   207,   110,   208,   209,   143,   114,    50,
    51,   198,    92,    24,    24,   202,   212,    20,   201,    55,
    56,    55,    56,    57,   117,    57,    21,    58,    59,    58,
    59,    99,    55,    56,   142,    60,    57,    60,   135,   136,
    58,    59,   147,   196,    50,    51,   199,   137,    60,   204,
   203,   138,   152,   211,    50,    51,   129,   130,   131,   132,
   133,   134,   155,   214,    50,    51,   215,    55,    56,   124,
   125,    57,   158,   160,    18,    58,    59,    55,    56,   170,
   172,    57,    29,    60,    25,    58,    59,    55,    56,    85,
    22,    57,    97,    60,   153,    58,    59,   157,   156,    50,
    51,     0,     0,    60,   126,   127,   128,   159,     0,    50,
    51,   120,   121,   122,   123,     0,     0,   161,     0,    50,
    51,     0,    55,    56,     0,     0,    57,     0,     0,     0,
    58,    59,    55,    56,     0,     0,    57,     0,    60,     0,
    58,    59,    55,    56,     0,     0,    57,     0,    60,     0,
    58,    59,   163,     0,    50,    51,     0,     0,    60,     0,
     0,     0,   165,     0,    50,    51,   162,   164,   166,   168,
     0,     0,   167,     0,    50,    51,     0,    55,    56,     0,
     0,    57,     0,     0,     0,    58,    59,    55,    56,     0,
     0,    57,     0,    60,     0,    58,    59,    55,    56,     0,
     0,    57,     0,    60,     0,    58,    59,   169,     0,    50,
    51,     0,     0,    60,     0,     0,     0,   171,     0,    50,
    51,     0,     0,     0,     0,     0,     0,   173,     0,    50,
    51,     0,    55,    56,     0,     0,    57,     0,     0,     0,
    58,    59,    55,    56,     0,     0,    57,     0,    60,     0,
    58,    59,    55,    56,     0,     0,    57,     0,    60,     0,
    58,    59,   175,     0,    50,    51,     0,     0,    60,     0,
     0,     0,   177,     0,    50,    51,     0,     0,     0,     0,
     0,     0,   179,     0,    50,    51,     0,    55,    56,     0,
     0,    57,     0,     0,     0,    58,    59,    55,    56,     0,
     0,    57,     0,    60,     0,    58,    59,    55,    56,     0,
     0,    57,     0,    60,     0,    58,    59,   181,     0,    50,
    51,     0,     0,    60,     0,     0,     0,   183,     0,    50,
    51,     0,     0,     0,     0,     0,     0,   185,     0,    50,
    51,     0,    55,    56,     0,     0,    57,     0,     0,     0,
    58,    59,    55,    56,     0,     0,    57,     0,    60,     0,
    58,    59,    55,    56,     0,     0,    57,     0,    60,     0,
    58,    59,   187,     0,    50,    51,     0,     0,    60,     0,
     0,     0,   189,     0,    50,    51,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    55,    56,     0,
     0,    57,     0,     0,     0,    58,    59,    55,    56,     0,
     0,    57,     0,    60,     0,    58,    59,     0,     0,     0,
    50,    51,     2,    60,    52,     3,    53,     4,    54,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    55,    56,   -67,     0,    57,     0,    50,
    51,    58,    59,    52,    21,    53,     0,    54,   -67,    60,
    61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    55,    56,   -67,     0,    57,     0,    50,    51,
    58,    59,    52,    21,    53,     0,    54,   -67,    60,    61,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    55,    56,     0,     0,    57,     0,     0,     0,    58,
    59,     0,    21,     0,     0,     0,     0,    60,    61
};

static const short yycheck[] = {    64,
    53,    55,    56,    57,    58,    47,    59,   129,   130,   131,
   132,   133,   134,    30,     1,   137,    21,    26,     3,     1,
     5,     3,     4,     8,    28,    10,     3,    44,     0,    34,
    47,    12,    41,    35,     6,     1,     5,    41,     3,     8,
     4,    10,    39,    96,    26,    27,    99,     3,    30,    36,
    92,     1,    34,    35,     1,     1,     3,     4,    43,    64,
    42,   114,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,    92,     1,    42,     3,    26,
    27,     1,   204,    30,     1,   138,    42,    34,    35,     1,
    40,     3,     4,     4,    40,    42,    35,     1,     1,    35,
    39,    20,    21,    28,     3,     3,     1,     3,    28,     8,
     8,    10,    10,     1,    26,    27,    41,    42,    30,    36,
     1,    41,    34,    35,     1,    28,     3,     4,     3,     4,
    42,    42,    18,   198,    38,   200,   201,     1,    41,     3,
     4,    36,    41,    42,    42,     1,   211,    28,    36,    26,
    27,    26,    27,    30,    19,    30,    37,    34,    35,    34,
    35,    35,    26,    27,     1,    42,    30,    42,    26,    27,
    34,    35,     1,    36,     3,     4,    36,    35,    42,    41,
    36,    39,     1,     6,     3,     4,    12,    13,    14,    15,
    16,    17,     1,     0,     3,     4,     0,    26,    27,    29,
    30,    30,   118,   119,     6,    34,    35,    26,    27,   124,
   125,    30,    11,    42,    10,    34,    35,    26,    27,    37,
     9,    30,    53,    42,   116,    34,    35,     1,   117,     3,
     4,    -1,    -1,    42,    31,    32,    33,     1,    -1,     3,
     4,    22,    23,    24,    25,    -1,    -1,     1,    -1,     3,
     4,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,
    34,    35,    26,    27,    -1,    -1,    30,    -1,    42,    -1,
    34,    35,    26,    27,    -1,    -1,    30,    -1,    42,    -1,
    34,    35,     1,    -1,     3,     4,    -1,    -1,    42,    -1,
    -1,    -1,     1,    -1,     3,     4,   120,   121,   122,   123,
    -1,    -1,     1,    -1,     3,     4,    -1,    26,    27,    -1,
    -1,    30,    -1,    -1,    -1,    34,    35,    26,    27,    -1,
    -1,    30,    -1,    42,    -1,    34,    35,    26,    27,    -1,
    -1,    30,    -1,    42,    -1,    34,    35,     1,    -1,     3,
     4,    -1,    -1,    42,    -1,    -1,    -1,     1,    -1,     3,
     4,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
     4,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,
    34,    35,    26,    27,    -1,    -1,    30,    -1,    42,    -1,
    34,    35,    26,    27,    -1,    -1,    30,    -1,    42,    -1,
    34,    35,     1,    -1,     3,     4,    -1,    -1,    42,    -1,
    -1,    -1,     1,    -1,     3,     4,    -1,    -1,    -1,    -1,
    -1,    -1,     1,    -1,     3,     4,    -1,    26,    27,    -1,
    -1,    30,    -1,    -1,    -1,    34,    35,    26,    27,    -1,
    -1,    30,    -1,    42,    -1,    34,    35,    26,    27,    -1,
    -1,    30,    -1,    42,    -1,    34,    35,     1,    -1,     3,
     4,    -1,    -1,    42,    -1,    -1,    -1,     1,    -1,     3,
     4,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
     4,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,
    34,    35,    26,    27,    -1,    -1,    30,    -1,    42,    -1,
    34,    35,    26,    27,    -1,    -1,    30,    -1,    42,    -1,
    34,    35,     1,    -1,     3,     4,    -1,    -1,    42,    -1,
    -1,    -1,     1,    -1,     3,     4,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
    -1,    30,    -1,    -1,    -1,    34,    35,    26,    27,    -1,
    -1,    30,    -1,    42,    -1,    34,    35,    -1,    -1,    -1,
     3,     4,     5,    42,     7,     8,     9,    10,    11,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    26,    27,    28,    -1,    30,    -1,     3,
     4,    34,    35,     7,    37,     9,    -1,    11,    41,    42,
    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    26,    27,    28,    -1,    30,    -1,     3,     4,
    34,    35,     7,    37,     9,    -1,    11,    41,    42,    43,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,    34,
    35,    -1,    37,    -1,    -1,    -1,    -1,    42,    43
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
case 12:
#line 53 "parser.y"
{yyerrok; printError(wrongreturntype);;
    break;}
case 18:
#line 67 "parser.y"
{type_const = 1;;
    break;}
case 19:
#line 70 "parser.y"
{type_int = 1; type_void = 0;;
    break;}
case 20:
#line 71 "parser.y"
{type_void = 1; type_int = 0;;
    break;}
case 21:
#line 75 "parser.y"
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
case 22:
#line 91 "parser.y"
{type_param = 0;;
    break;}
case 23:
#line 92 "parser.y"
{yyerrok;printError(noparen);;
    break;}
case 28:
#line 101 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 29:
#line 104 "parser.y"
{type_void = 0;;
    break;}
case 30:
#line 105 "parser.y"
{type_param = 1; idttype = 5; HT[hashcode]->type=idttype;;
    break;}
case 31:
#line 106 "parser.y"
{yyerrok; printError(wrongparam);;
    break;}
case 33:
#line 110 "parser.y"
{yyerrok; printError(nobrace);;
    break;}
case 39:
#line 122 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 42:
#line 127 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 46:
#line 135 "parser.y"
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
case 47:
#line 161 "parser.y"
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
case 48:
#line 184 "parser.y"
{yyerrok; printError(nobrack);;
    break;}
case 64:
#line 210 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 70:
#line 218 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 71:
#line 219 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 73:
#line 223 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 74:
#line 224 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 76:
#line 228 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 80:
#line 236 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 82:
#line 238 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 84:
#line 240 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 86:
#line 242 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 88:
#line 244 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 90:
#line 246 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 93:
#line 251 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 96:
#line 256 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 99:
#line 261 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 101:
#line 263 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 104:
#line 268 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 106:
#line 270 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 108:
#line 272 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 110:
#line 274 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 113:
#line 279 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 115:
#line 281 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 118:
#line 286 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 120:
#line 288 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 122:
#line 290 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 125:
#line 295 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 127:
#line 297 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 129:
#line 299 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 131:
#line 301 "parser.y"
{yyerrok; printError(noop);;
    break;}
case 133:
#line 305 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 135:
#line 307 "parser.y"
{yyerrok; printError(nobrack);;
    break;}
case 137:
#line 309 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 145:
#line 326 "parser.y"
{
                     //identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
                     if (!found){
                        idttype = 10;
                                HT[hashcode]->type = idttype;
                        yyerrok; printError(notdefined);
                     }
                  ;
    break;}
case 148:
#line 336 "parser.y"
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
#line 339 "parser.y"
