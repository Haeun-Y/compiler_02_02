
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDENT	258
#define	TNUMBER	259
#define	TCONST	260
#define	TELSE	261
#define	TIF	262
#define	TEIF	263
#define	TINT	264
#define	TRETURN	265
#define	TVOID	266
#define	TWHILE	267
#define	TADD	268
#define	TSUB	269
#define	TMUL	270
#define	TDIV	271
#define	TMOD	272
#define	TASSIGN	273
#define	TADDASSIGN	274
#define	TSUBASSIGN	275
#define	TMULASSIGN	276
#define	TDIVASSIGN	277
#define	TMODASSIGN	278
#define	TNOT	279
#define	TOR	280
#define	TAND	281
#define	TEQUAL	282
#define	TNOTEQU	283
#define	TGREATE	284
#define	TLESSE	285
#define	TGREAT	286
#define	TLESS	287
#define	TINC	288
#define	TDEC	289
#define	TLPAREN	290
#define	TRPAREN	291
#define	TLBRACE	292
#define	TRBRACE	293
#define	TLBRACKET	294
#define	TRBRACKET	295
#define	TCOMMA	296
#define	TSEMI	297
#define	TCOMMENT	298
#define	TERROR	299
#define	UIF	300
#define	TIF_CONDITION_ERROR	301
#define	TIF_ERROR	302
#define	TELSE_CONDITION_ERROR	303
#define	TELSE_ERROR	304

#line 7 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

extern yylex();
extern yyerror();
extern char* yytext;

int type_int=0;
int type_void=0;
int param_int=0;

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



#define	YYFINAL		186
#define	YYFLAG		-32768
#define	YYNTBASE	50

#define YYTRANSLATE(x) ((unsigned)(x) <= 304 ? yytranslate[x] : 95)

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
    46,    47,    48,    49
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    29,    33,    35,    37,    40,    42,    44,    46,    48,
    50,    52,    56,    59,    61,    62,    64,    68,    71,    74,
    79,    84,    86,    87,    89,    92,    96,   100,   102,   106,
   109,   111,   115,   119,   121,   126,   131,   133,   134,   136,
   137,   139,   142,   145,   147,   149,   151,   153,   155,   158,
   161,   163,   164,   170,   175,   181,   189,   196,   204,   210,
   216,   221,   225,   229,   231,   233,   237,   241,   245,   249,
   253,   257,   259,   263,   265,   269,   271,   275,   279,   281,
   285,   289,   293,   297,   299,   303,   307,   309,   313,   317,
   321,   323,   326,   329,   332,   335,   337,   342,   347,   352,
   357,   360,   363,   365,   366,   368,   370,   374,   376,   378,
   382
};

static const short yyrhs[] = {    51,
     0,    52,     0,    51,    52,     0,    53,     0,    68,     0,
     3,    42,     0,     3,     1,     0,    54,    65,     0,    54,
    42,     0,    54,     1,     0,     1,    65,     0,    55,    60,
    61,     0,    56,     0,    57,     0,    56,    57,     0,    58,
     0,    59,     0,     5,     0,     9,     0,    11,     0,     3,
     0,    35,    62,    36,     0,    35,    62,     0,    63,     0,
     0,    64,     0,    63,    41,    64,     0,    63,    64,     0,
    55,    71,     0,    37,    66,    73,    38,     0,    37,    66,
    73,     1,     0,    67,     0,     0,    68,     0,    67,    68,
     0,    55,    69,    42,     0,    55,    69,     1,     0,    70,
     0,    69,    41,    70,     0,    69,    70,     0,    71,     0,
    71,    18,     4,     0,    71,    27,     4,     0,     3,     0,
     3,    39,    72,    40,     0,     3,    39,    72,     1,     0,
     4,     0,     0,    74,     0,     0,    75,     0,    74,    75,
     0,    74,    68,     0,    65,     0,    76,     0,    78,     0,
    79,     0,    80,     0,    77,    42,     0,    81,     1,     0,
    81,     0,     0,     7,    35,    81,    36,    75,     0,     7,
    35,    36,    75,     0,     7,    35,    81,     1,    75,     0,
     7,    35,    81,    36,    75,     6,    75,     0,     7,    35,
    36,    75,     6,    75,     0,     7,    35,    81,     1,    75,
     6,    75,     0,    12,    35,    81,    36,    75,     0,    12,
    35,    81,     1,    75,     0,    12,    35,    36,    75,     0,
    10,    77,    42,     0,    10,    77,     1,     0,    82,     0,
    83,     0,    89,    18,    82,     0,    89,    19,    82,     0,
    89,    20,    82,     0,    89,    21,    82,     0,    89,    22,
    82,     0,    89,    23,    82,     0,    84,     0,    83,    25,
    84,     0,    85,     0,    84,    26,    85,     0,    86,     0,
    85,    27,    86,     0,    85,    28,    86,     0,    87,     0,
    86,    31,    87,     0,    86,    32,    87,     0,    86,    29,
    87,     0,    86,    30,    87,     0,    88,     0,    87,    13,
    88,     0,    87,    14,    88,     0,    89,     0,    88,    15,
    89,     0,    88,    16,    89,     0,    88,    17,    89,     0,
    90,     0,    14,    89,     0,    24,    89,     0,    33,    89,
     0,    34,    89,     0,    94,     0,    90,    39,    81,    40,
     0,    90,    39,    81,     1,     0,    90,    35,    91,    36,
     0,    90,    35,    91,     1,     0,    90,    33,     0,    90,
    34,     0,    92,     0,     0,    93,     0,    82,     0,    93,
    41,    82,     0,     3,     0,     4,     0,    35,    81,    36,
     0,    35,    81,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    72,    73,    75,    76,    77,    78,    79,    80,    90,
    91,    92,    93,    94,    95,    96,   100,   107,   108,   109,
   110,   111,   112,   113,   121,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
   196,   197,   198,   199,   200,   201,   202,   203,   208,   209,
   210
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TCONST","TELSE","TIF","TEIF","TINT","TRETURN","TVOID","TWHILE","TADD",
"TSUB","TMUL","TDIV","TMOD","TASSIGN","TADDASSIGN","TSUBASSIGN","TMULASSIGN",
"TDIVASSIGN","TMODASSIGN","TNOT","TOR","TAND","TEQUAL","TNOTEQU","TGREATE","TLESSE",
"TGREAT","TLESS","TINC","TDEC","TLPAREN","TRPAREN","TLBRACE","TRBRACE","TLBRACKET",
"TRBRACKET","TCOMMA","TSEMI","TCOMMENT","TERROR","UIF","TIF_CONDITION_ERROR",
"TIF_ERROR","TELSE_CONDITION_ERROR","TELSE_ERROR","mini_c","translation_unit",
"external_dcl","function_def","function_header","dcl_spec","dcl_specifiers",
"dcl_specifier","type_qualifier","type_specifier","function_name","formal_param",
"opt_formal_param","formal_param_list","param_dcl","compound_st","opt_dcl_list",
"declaration_list","declaration","init_dcl_list","init_declarator","declarator",
"opt_number","opt_stat_list","statement_list","statement","expression_st","opt_expression",
"if_st","while_st","return_st","expression","assignment_exp","logical_or_exp",
"logical_and_exp","equality_exp","relational_exp","additive_exp","multiplicative_exp",
"unary_exp","postfix_exp","opt_actual_param","actual_param","actual_param_list",
"primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    50,    51,    51,    52,    52,    52,    52,    53,    53,    53,
    53,    54,    55,    56,    56,    57,    57,    58,    59,    59,
    60,    61,    61,    62,    62,    63,    63,    63,    64,    65,
    65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
    70,    70,    70,    71,    71,    71,    72,    72,    73,    73,
    74,    74,    74,    75,    75,    75,    75,    75,    76,    76,
    77,    77,    78,    78,    78,    78,    78,    78,    79,    79,
    79,    80,    80,    81,    82,    82,    82,    82,    82,    82,
    82,    83,    83,    84,    84,    85,    85,    85,    86,    86,
    86,    86,    86,    87,    87,    87,    88,    88,    88,    88,
    89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
    90,    90,    91,    91,    92,    93,    93,    94,    94,    94,
    94
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     2,     3,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     3,     2,     1,     0,     1,     3,     2,     2,     4,
     4,     1,     0,     1,     2,     3,     3,     1,     3,     2,
     1,     3,     3,     1,     4,     4,     1,     0,     1,     0,
     1,     2,     2,     1,     1,     1,     1,     1,     2,     2,
     1,     0,     5,     4,     5,     7,     6,     7,     5,     5,
     4,     3,     3,     1,     1,     3,     3,     3,     3,     3,
     3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
     3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
     1,     2,     2,     2,     2,     1,     4,     4,     4,     4,
     2,     2,     1,     0,     1,     1,     3,     1,     1,     3,
     3
};

static const short yydefact[] = {     0,
     0,     0,    18,    19,    20,     0,     2,     4,     0,     0,
    13,    14,    16,    17,     5,    33,    11,     7,     6,     3,
    10,     9,     8,    44,     0,     0,    38,    41,    15,     0,
    50,    32,    34,    48,    25,    12,    37,    44,     0,    36,
    40,     0,     0,   118,   119,     0,    62,     0,     0,     0,
     0,     0,     0,    54,     0,    49,    51,    55,     0,    56,
    57,    58,     0,    74,    75,    82,    84,    86,    89,    94,
    97,   101,   106,    35,    47,     0,     0,    23,    24,    26,
    39,    42,    43,     0,     0,    61,     0,   102,   103,   104,
   105,     0,    31,    30,    53,    52,    59,    60,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   111,   112,   114,
     0,    46,    45,    29,    22,     0,    28,    62,     0,    73,
    72,    62,     0,   121,   120,    83,    97,    85,    87,    88,
    92,    93,    90,    91,    95,    96,    98,    99,   100,    76,
    77,    78,    79,    80,    81,   116,     0,   113,   115,     0,
    27,    64,    62,    62,    71,    62,    62,   110,   109,     0,
   108,   107,    62,    65,    63,    70,    69,   117,    67,    62,
    62,    68,    66,     0,     0,     0
};

static const short yydefgoto[] = {   184,
     6,     7,     8,     9,    30,    11,    12,    13,    14,    25,
    36,    78,    79,    80,    54,    31,    32,    15,    26,    27,
    28,    76,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
   157,   158,   159,    73
};

static const short yypact[] = {    19,
     3,    30,-32768,-32768,-32768,   204,-32768,-32768,    11,    42,
   175,-32768,-32768,-32768,-32768,   175,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    47,    17,     2,-32768,     7,-32768,    51,
   127,   175,-32768,    87,   175,-32768,-32768,    71,    51,-32768,
-32768,   109,   112,-32768,-32768,   103,   139,   105,   139,   139,
   139,   139,   139,-32768,    18,    85,-32768,-32768,    83,-32768,
-32768,-32768,    31,-32768,   107,   118,    -1,   187,    33,    90,
   174,    69,-32768,-32768,-32768,    38,    51,   111,    46,-32768,
-32768,-32768,-32768,   154,    32,-32768,   167,-32768,-32768,-32768,
-32768,    49,-32768,-32768,-32768,-32768,-32768,-32768,   139,   139,
   139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
   139,   139,   139,   139,   139,   139,   139,-32768,-32768,   139,
   139,-32768,-32768,-32768,-32768,   175,-32768,   142,    97,-32768,
-32768,   142,    99,-32768,-32768,   118,-32768,    -1,   187,   187,
    33,    33,    33,    33,    90,    90,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   100,-32768,   114,    41,
-32768,   144,   142,   142,-32768,   142,   142,-32768,-32768,   139,
-32768,-32768,   142,   153,   159,-32768,-32768,-32768,-32768,   142,
   142,-32768,-32768,   148,   182,-32768
};

static const short yypgoto[] = {-32768,
-32768,   161,-32768,-32768,     0,-32768,   172,-32768,-32768,-32768,
-32768,-32768,-32768,   -77,    28,-32768,-32768,    61,-32768,    -3,
   108,-32768,-32768,-32768,   -52,-32768,   151,-32768,-32768,-32768,
   -46,   -99,-32768,   113,   106,   -18,   117,    16,   -41,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		223


static const short yytable[] = {    10,
    86,   127,    37,    96,    38,    10,    92,    88,    89,    90,
    91,    21,   150,   151,   152,   153,   154,   155,    93,     1,
   156,     2,    41,     3,    42,   101,   102,     4,    17,     5,
    18,    98,   130,    43,    77,    81,    23,   129,   122,    16,
   133,   171,    39,    40,    24,   107,   108,    16,   161,   134,
     3,    35,    22,    38,     4,    94,     5,   137,   137,   137,
   137,   137,   137,   137,   137,   137,   137,   147,   148,   149,
   178,    19,   -61,   131,   160,   162,    33,   123,    77,   165,
   172,   -21,   139,   140,   135,    34,   126,    44,    45,     3,
    75,    46,    74,     4,    47,     5,    48,   163,    49,   166,
   168,   118,   119,   120,   109,   110,   111,   121,    50,    34,
   174,   175,    82,   176,   177,    83,    95,    51,    52,    53,
   179,    16,   145,   146,    97,    77,   -62,   182,   183,    44,
    45,    99,   164,    46,   167,   169,    47,    84,    48,    87,
    49,    44,    45,   100,    44,    45,   125,   185,    46,   173,
    50,    47,    49,    48,   170,    49,    44,    45,   180,    51,
    52,    53,    50,    16,   181,    50,    20,    49,   -62,    44,
    45,    51,    52,    53,    51,    52,    53,    50,    16,     3,
    49,   186,    29,     4,   124,     5,    51,    52,    53,   128,
    50,   112,   113,   114,   115,   116,   117,    85,     0,    51,
    52,    53,   132,    -1,     1,   138,     2,     0,     3,     0,
     0,   136,     4,     0,     5,   103,   104,   105,   106,   141,
   142,   143,   144
};

static const short yycheck[] = {     0,
    47,    79,     1,    56,     3,     6,    53,    49,    50,    51,
    52,     1,   112,   113,   114,   115,   116,   117,     1,     1,
   120,     3,    26,     5,    18,    27,    28,     9,     1,    11,
     1,     1,     1,    27,    35,    39,     9,    84,     1,    37,
    87,     1,    41,    42,     3,    13,    14,    37,   126,     1,
     5,    35,    42,     3,     9,    38,    11,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   170,    42,    42,    42,   121,   128,    16,    40,    79,   132,
    40,    35,   101,   102,    36,    39,    41,     3,     4,     5,
     4,     7,    32,     9,    10,    11,    12,     1,    14,     1,
     1,    33,    34,    35,    15,    16,    17,    39,    24,    39,
   163,   164,     4,   166,   167,     4,    56,    33,    34,    35,
   173,    37,   107,   108,    42,   126,    42,   180,   181,     3,
     4,    25,    36,     7,    36,    36,    10,    35,    12,    35,
    14,     3,     4,    26,     3,     4,    36,     0,     7,     6,
    24,    10,    14,    12,    41,    14,     3,     4,     6,    33,
    34,    35,    24,    37,     6,    24,     6,    14,    42,     3,
     4,    33,    34,    35,    33,    34,    35,    24,    37,     5,
    14,     0,    11,     9,    77,    11,    33,    34,    35,    36,
    24,    18,    19,    20,    21,    22,    23,    47,    -1,    33,
    34,    35,    36,     0,     1,   100,     3,    -1,     5,    -1,
    -1,    99,     9,    -1,    11,    29,    30,    31,    32,   103,
   104,   105,   106
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

case 7:
#line 43 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 10:
#line 46 "parser.y"
{cur_tmp->type=0; yyerrok; printError(nosemi);;
    break;}
case 11:
#line 47 "parser.y"
{yyerrok; printError(wrongfdef);;
    break;}
case 19:
#line 55 "parser.y"
{type_int = 1;;
    break;}
case 20:
#line 56 "parser.y"
{type_void=1;;
    break;}
case 21:
#line 58 "parser.y"
{
							//type 0 : type이 지정되지 않은 상태
							if(cur->type==0){
								if(type_void==1){
									  cur->type=3; /* function, return type=void */
								}else if(type_int==1){
									  cur->type=4; /* function, return type=int */
								}
                    
								type_int=0;
								type_void=0;
								cur_tmp=cur;
							}
						;
    break;}
case 23:
#line 73 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 28:
#line 79 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 29:
#line 81 "parser.y"
{
						if(type_int==1){ /* int로 설정된 경우 */
							param_int=1; 
							cur->type=5;  /* integer scalar parameter */
						  }
						  type_int=0;
						  type_void=0;
						  param_int=0;
					;
    break;}
case 31:
#line 91 "parser.y"
{yyerrok; printError(nobrace);;
    break;}
case 36:
#line 96 "parser.y"
{
							type_int=0;
							type_void=0;
						;
    break;}
case 37:
#line 100 "parser.y"
{
					cur->type=0;
					yyerrok; 
					type_int=0;
					type_void=0;
					printError(nosemi);
					;
    break;}
case 40:
#line 109 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 43:
#line 112 "parser.y"
{yyerrok; printError(wrongdec);;
    break;}
case 44:
#line 113 "parser.y"
{
					  if(cur->type==0){
							if(type_int==1){
								  cur->type=1; /* integer scalar variable */
							}    
					  }
					  cur_tmp=cur;
				;
    break;}
case 45:
#line 121 "parser.y"
{
					//array 변수
					if(cur->type==0){
                        if(type_int==1)cur->type=2; /* array integer variable */
					}
					   cur_tmp=cur;
				;
    break;}
case 46:
#line 128 "parser.y"
{yyerrok; printError(nobrack);;
    break;}
case 60:
#line 143 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 64:
#line 147 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 65:
#line 148 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 67:
#line 150 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 68:
#line 151 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 70:
#line 153 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 71:
#line 154 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 73:
#line 157 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 108:
#line 193 "parser.y"
{yyerrok; printError(nobrack);;
    break;}
case 110:
#line 195 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 118:
#line 203 "parser.y"
{
						if(cur->type==0){
							 cur->type=7;
						}
					;
    break;}
case 121:
#line 210 "parser.y"
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
#line 211 "parser.y"
