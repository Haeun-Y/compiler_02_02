
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



#define	YYFINAL		200
#define	YYFLAG		-32768
#define	YYNTBASE	45

#define YYTRANSLATE(x) ((unsigned)(x) <= 299 ? yytranslate[x] : 91)

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
    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    13,    16,    19,    22,
    23,    28,    30,    32,    35,    37,    39,    41,    43,    45,
    47,    51,    55,    57,    58,    60,    64,    67,    70,    75,
    80,    82,    83,    85,    88,    92,    96,    98,   102,   105,
   107,   111,   113,   118,   123,   125,   126,   128,   129,   131,
   134,   136,   138,   140,   142,   144,   146,   149,   152,   154,
   155,   161,   169,   174,   179,   185,   191,   196,   200,   204,
   206,   208,   212,   216,   220,   224,   228,   232,   236,   240,
   244,   248,   252,   256,   258,   262,   266,   268,   272,   276,
   278,   282,   286,   290,   294,   296,   300,   304,   308,   312,
   316,   320,   324,   328,   330,   334,   338,   342,   346,   348,
   352,   356,   360,   364,   368,   372,   374,   377,   380,   383,
   386,   389,   392,   395,   398,   400,   405,   410,   415,   420,
   423,   426,   428,   429,   431,   433,   437,   439,   441,   445
};

static const short yyrhs[] = {    46,
     0,    47,     0,    46,    47,     0,    48,     0,    64,     0,
    43,     0,    49,    61,     0,    49,    28,     0,    49,     1,
     0,     0,    51,    56,    50,    57,     0,    52,     0,    53,
     0,    52,    53,     0,    54,     0,    55,     0,     5,     0,
     8,     0,    10,     0,     3,     0,    35,    58,    36,     0,
    35,    58,     1,     0,    59,     0,     0,    60,     0,    59,
    41,    60,     0,    59,    60,     0,    51,    67,     0,    37,
    62,    69,    38,     0,    37,    62,    69,     1,     0,    63,
     0,     0,    64,     0,    63,    64,     0,    51,    65,    28,
     0,    51,    65,     1,     0,    66,     0,    65,    41,    66,
     0,    65,    66,     0,    67,     0,    67,    12,     4,     0,
     3,     0,     3,    39,    68,    40,     0,     3,    39,    68,
     1,     0,     4,     0,     0,    70,     0,     0,    71,     0,
    70,    71,     0,    61,     0,    72,     0,    74,     0,    75,
     0,    76,     0,    43,     0,    73,    28,     0,    77,     1,
     0,    77,     0,     0,     7,    35,    77,    36,    71,     0,
     7,    35,    77,    36,    71,     6,    71,     0,     7,    35,
     1,    36,     0,     7,    35,    77,     1,     0,    11,    35,
    77,    36,    71,     0,    11,    35,    77,     1,    71,     0,
    11,    35,     1,    36,     0,     9,    73,    28,     0,     9,
    73,     1,     0,    78,     0,    79,     0,    85,    12,    78,
     0,    85,    12,     1,     0,    85,    13,    78,     0,    85,
    13,     1,     0,    85,    14,    78,     0,    85,    14,     1,
     0,    85,    15,    78,     0,    85,    15,     1,     0,    85,
    16,    78,     0,    85,    16,     1,     0,    85,    17,    78,
     0,    85,    17,     1,     0,    80,     0,    79,    18,    80,
     0,    79,    18,     1,     0,    81,     0,    80,    19,    81,
     0,    80,    19,     1,     0,    82,     0,    81,    20,    82,
     0,    81,    20,     1,     0,    81,    21,    82,     0,    81,
    21,     1,     0,    83,     0,    82,    24,    83,     0,    82,
    24,     1,     0,    82,    25,    83,     0,    82,    25,     1,
     0,    82,    22,    83,     0,    82,    22,     1,     0,    82,
    23,    83,     0,    82,    23,     1,     0,    84,     0,    83,
    29,    84,     0,    83,    29,     1,     0,    83,    30,    84,
     0,    83,    30,     1,     0,    85,     0,    84,    31,    85,
     0,    84,    31,     1,     0,    84,    32,    85,     0,    84,
    32,     1,     0,    84,    33,    85,     0,    84,    33,     1,
     0,    86,     0,    30,    85,     0,    30,     1,     0,    34,
    85,     0,    34,     1,     0,    26,    85,     0,    26,     1,
     0,    27,    85,     0,    27,     1,     0,    90,     0,    86,
    39,    77,    40,     0,    86,    39,    77,     1,     0,    86,
    35,    87,    36,     0,    86,    35,    87,     1,     0,    86,
    26,     0,    86,    27,     0,    88,     0,     0,    89,     0,
    78,     0,    89,    41,    78,     0,     3,     0,     4,     0,
    35,    77,    36,     0,    35,    77,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    33,    36,    37,    40,    41,    42,    45,    46,    47,    50,
    51,    53,    56,    57,    60,    61,    64,    67,    68,    71,
    88,    89,    92,    93,    96,    97,    98,   101,   104,   105,
   108,   109,   112,   113,   116,   117,   120,   121,   122,   124,
   125,   128,   150,   172,   175,   176,   179,   180,   183,   184,
   187,   188,   189,   190,   191,   192,   195,   196,   197,   198,
   201,   202,   203,   204,   207,   208,   209,   212,   213,   216,
   219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
   229,   230,   231,   234,   235,   236,   239,   240,   241,   244,
   245,   246,   247,   248,   251,   252,   253,   254,   255,   256,
   257,   258,   259,   262,   263,   264,   265,   266,   269,   270,
   271,   272,   273,   274,   275,   278,   279,   280,   281,   282,
   283,   284,   285,   286,   289,   290,   291,   292,   293,   294,
   295,   298,   299,   302,   305,   306,   309,   316,   317,   318
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TCONST","TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TASSIGN",
"TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TOR","TAND",
"TEQUAL","TNOTEQU","TGREATE","TLESSE","TLESS","TGREAT","TINC","TDEC","TSEMI",
"TPLUS","TMINUS","TSTAR","TSLASH","TMOD","TNOT","TLPAREN","TRPAREN","TLBRACE",
"TRBRACE","TLBRACKET","TRBRACKET","TCOMMA","TERROR","TCOMMENT","LOWER_THEN_ELSE",
"mini_c","translation_unit","external_dcl","function_def","function_header",
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
    45,    46,    46,    47,    47,    47,    48,    48,    48,    50,
    49,    51,    52,    52,    53,    53,    54,    55,    55,    56,
    57,    57,    58,    58,    59,    59,    59,    60,    61,    61,
    62,    62,    63,    63,    64,    64,    65,    65,    65,    66,
    66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
    71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
    74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
    78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
    78,    78,    78,    79,    79,    79,    80,    80,    80,    81,
    81,    81,    81,    81,    82,    82,    82,    82,    82,    82,
    82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
    84,    84,    84,    84,    84,    85,    85,    85,    85,    85,
    85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
    86,    87,    87,    88,    89,    89,    90,    90,    90,    90
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     2,     2,     2,     0,
     4,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     3,     3,     1,     0,     1,     3,     2,     2,     4,     4,
     1,     0,     1,     2,     3,     3,     1,     3,     2,     1,
     3,     1,     4,     4,     1,     0,     1,     0,     1,     2,
     1,     1,     1,     1,     1,     1,     2,     2,     1,     0,
     5,     7,     4,     4,     5,     5,     4,     3,     3,     1,
     1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
     3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
     3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
     3,     3,     3,     3,     3,     1,     2,     2,     2,     2,
     2,     2,     2,     2,     1,     4,     4,     4,     4,     2,
     2,     1,     0,     1,     1,     3,     1,     1,     3,     3
};

static const short yydefact[] = {     0,
    17,    18,    19,     6,     1,     2,     4,     0,     0,    12,
    13,    15,    16,     5,     3,     9,     8,    32,     7,    42,
    10,     0,    37,    40,    14,     0,    48,    31,    33,    46,
     0,    36,    42,    35,     0,    39,     0,   137,   138,     0,
    60,     0,     0,     0,     0,     0,     0,    56,    51,     0,
    47,    49,    52,     0,    53,    54,    55,     0,    70,    71,
    84,    87,    90,    95,   104,   109,   116,   125,    34,    45,
     0,    24,    11,    38,    41,     0,     0,    59,     0,   122,
   121,   124,   123,   118,   117,   120,   119,     0,    30,    29,
    50,    57,    58,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   130,   131,   133,     0,    44,    43,     0,     0,
    23,    25,     0,     0,    69,    68,     0,     0,   140,   139,
    86,    85,   109,    89,    88,    92,    91,    94,    93,   101,
   100,   103,   102,    97,    96,    99,    98,   106,   105,   108,
   107,   111,   110,   113,   112,   115,   114,    73,    72,    75,
    74,    77,    76,    79,    78,    81,    80,    83,    82,   135,
     0,   132,   134,     0,    28,    22,    21,     0,    27,    63,
    64,    60,    67,    60,    60,   129,   128,     0,   127,   126,
    26,    61,    66,    65,   136,    60,    62,     0,     0,     0
};

static const short yydefgoto[] = {   198,
     5,     6,     7,     8,    31,   119,    10,    11,    12,    13,
    21,    73,   120,   121,   122,    49,    27,    28,    14,    22,
    23,    24,    71,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,   171,   172,   173,    68
};

static const short yypact[] = {    82,
-32768,-32768,-32768,-32768,    82,-32768,-32768,    26,    25,    90,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    90,-32768,     2,
-32768,    10,-32768,    30,-32768,    42,    22,    90,-32768,    49,
    50,-32768,    60,-32768,    42,-32768,    98,-32768,-32768,    70,
   464,    73,   112,   140,   150,   156,   464,-32768,-32768,     9,
    22,-32768,-32768,   102,-32768,-32768,-32768,    11,-32768,   103,
   107,    89,   139,    93,   104,   472,    -3,-32768,-32768,-32768,
    18,    90,-32768,-32768,-32768,   168,    33,-32768,   196,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    19,-32768,-32768,
-32768,-32768,-32768,   206,   212,   224,   252,   262,   268,   280,
   308,   318,   324,   336,   364,   374,   380,   392,   420,   430,
   436,   448,-32768,-32768,   464,   464,-32768,-32768,    42,    43,
    86,-32768,    96,    61,-32768,-32768,   114,    88,-32768,-32768,
-32768,   107,-32768,-32768,    89,-32768,   139,-32768,   139,-32768,
    93,-32768,    93,-32768,    93,-32768,    93,-32768,   104,-32768,
   104,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    92,-32768,    99,    20,-32768,-32768,-32768,    90,-32768,-32768,
-32768,    77,-32768,    77,    77,-32768,-32768,   464,-32768,-32768,
-32768,   146,-32768,-32768,-32768,    77,-32768,   155,   158,-32768
};

static const short yypgoto[] = {-32768,
-32768,   151,-32768,-32768,-32768,   101,-32768,   163,-32768,-32768,
-32768,-32768,-32768,-32768,  -114,   157,-32768,-32768,    12,-32768,
     0,    59,-32768,-32768,-32768,   -51,-32768,   127,-32768,-32768,
-32768,   -33,  -106,-32768,    85,    94,    21,   119,    46,   -28,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		499


static const short yytable[] = {    91,
   159,   161,   163,   165,   167,   169,   179,    78,   170,    89,
    32,    93,    33,    88,    81,    83,    85,    87,   117,   129,
   189,    36,   113,   114,    38,    39,    16,    20,    40,    29,
    41,   115,    42,   125,    74,   116,   -20,    34,   -59,    69,
    30,    37,   124,   176,    33,   128,    90,    43,    44,   -60,
    35,    45,    70,    17,   130,    46,    47,   118,    18,   190,
   126,   181,    18,   191,    48,   133,   133,   133,   133,   133,
   133,   133,   133,   133,   133,   153,   155,   157,   177,    38,
    39,   195,   174,    40,    72,    41,     1,    42,   184,     2,
     1,     3,   186,     2,     1,     3,   182,     2,    30,     3,
     9,    75,    43,    44,    76,     9,    45,    79,    96,    97,
    46,    47,    80,    18,    38,    39,   137,   139,    26,    48,
    94,   102,   103,   185,     4,    95,   178,   187,    26,    92,
   192,   180,   193,   194,   104,   105,   106,    43,    44,   188,
    82,    45,    38,    39,   197,    46,    47,   149,   151,   183,
    84,   196,    38,    39,   199,    15,    86,   200,    38,    39,
    98,    99,   100,   101,    19,    43,    44,    77,   123,    45,
    38,    39,    25,    46,    47,    43,    44,   175,   132,    45,
     0,    43,    44,    46,    47,    45,     0,     0,   135,    46,
    47,     0,     0,    43,    44,     0,   127,    45,    38,    39,
     0,    46,    47,     0,     0,     0,   131,     0,    38,    39,
     0,     0,   134,     0,    38,    39,   141,   143,   145,   147,
     0,    43,    44,     0,   136,    45,    38,    39,     0,    46,
    47,    43,    44,     0,     0,    45,     0,    43,    44,    46,
    47,    45,     0,     0,     0,    46,    47,     0,     0,    43,
    44,     0,   138,    45,    38,    39,     0,    46,    47,     0,
     0,     0,   140,     0,    38,    39,     0,     0,   142,     0,
    38,    39,     0,     0,     0,     0,     0,    43,    44,     0,
   144,    45,    38,    39,     0,    46,    47,    43,    44,     0,
     0,    45,     0,    43,    44,    46,    47,    45,     0,     0,
     0,    46,    47,     0,     0,    43,    44,     0,   146,    45,
    38,    39,     0,    46,    47,     0,     0,     0,   148,     0,
    38,    39,     0,     0,   150,     0,    38,    39,     0,     0,
     0,     0,     0,    43,    44,     0,   152,    45,    38,    39,
     0,    46,    47,    43,    44,     0,     0,    45,     0,    43,
    44,    46,    47,    45,     0,     0,     0,    46,    47,     0,
     0,    43,    44,     0,   154,    45,    38,    39,     0,    46,
    47,     0,     0,     0,   156,     0,    38,    39,     0,     0,
   158,     0,    38,    39,     0,     0,     0,     0,     0,    43,
    44,     0,   160,    45,    38,    39,     0,    46,    47,    43,
    44,     0,     0,    45,     0,    43,    44,    46,    47,    45,
     0,     0,     0,    46,    47,     0,     0,    43,    44,     0,
   162,    45,    38,    39,     0,    46,    47,     0,     0,     0,
   164,     0,    38,    39,     0,     0,   166,     0,    38,    39,
     0,     0,     0,     0,     0,    43,    44,     0,   168,    45,
    38,    39,     0,    46,    47,    43,    44,     0,     0,    45,
     0,    43,    44,    46,    47,    45,    38,    39,     0,    46,
    47,     0,     0,    43,    44,     0,     0,    45,     0,     0,
     0,    46,    47,   107,   108,   109,   110,   111,   112,    43,
    44,     0,     0,    45,     0,     0,     0,    46,    47
};

static const short yycheck[] = {    51,
   107,   108,   109,   110,   111,   112,   121,    41,   115,     1,
     1,     1,     3,    47,    43,    44,    45,    46,     1,     1,
     1,    22,    26,    27,     3,     4,     1,     3,     7,    18,
     9,    35,    11,     1,    35,    39,    35,    28,    28,    28,
    39,    12,    76,     1,     3,    79,    38,    26,    27,    28,
    41,    30,     4,    28,    36,    34,    35,    40,    37,    40,
    28,     1,    37,   178,    43,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,    36,     3,
     4,   188,   116,     7,    35,     9,     5,    11,     1,     8,
     5,    10,     1,     8,     5,    10,    36,     8,    39,    10,
     0,     4,    26,    27,    35,     5,    30,    35,    20,    21,
    34,    35,     1,    37,     3,     4,    96,    97,    18,    43,
    18,    29,    30,    36,    43,    19,    41,    36,    28,    28,
   182,    36,   184,   185,    31,    32,    33,    26,    27,    41,
     1,    30,     3,     4,   196,    34,    35,   102,   103,    36,
     1,     6,     3,     4,     0,     5,     1,     0,     3,     4,
    22,    23,    24,    25,     8,    26,    27,    41,     1,    30,
     3,     4,    10,    34,    35,    26,    27,   119,    94,    30,
    -1,    26,    27,    34,    35,    30,    -1,    -1,    95,    34,
    35,    -1,    -1,    26,    27,    -1,     1,    30,     3,     4,
    -1,    34,    35,    -1,    -1,    -1,     1,    -1,     3,     4,
    -1,    -1,     1,    -1,     3,     4,    98,    99,   100,   101,
    -1,    26,    27,    -1,     1,    30,     3,     4,    -1,    34,
    35,    26,    27,    -1,    -1,    30,    -1,    26,    27,    34,
    35,    30,    -1,    -1,    -1,    34,    35,    -1,    -1,    26,
    27,    -1,     1,    30,     3,     4,    -1,    34,    35,    -1,
    -1,    -1,     1,    -1,     3,     4,    -1,    -1,     1,    -1,
     3,     4,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
     1,    30,     3,     4,    -1,    34,    35,    26,    27,    -1,
    -1,    30,    -1,    26,    27,    34,    35,    30,    -1,    -1,
    -1,    34,    35,    -1,    -1,    26,    27,    -1,     1,    30,
     3,     4,    -1,    34,    35,    -1,    -1,    -1,     1,    -1,
     3,     4,    -1,    -1,     1,    -1,     3,     4,    -1,    -1,
    -1,    -1,    -1,    26,    27,    -1,     1,    30,     3,     4,
    -1,    34,    35,    26,    27,    -1,    -1,    30,    -1,    26,
    27,    34,    35,    30,    -1,    -1,    -1,    34,    35,    -1,
    -1,    26,    27,    -1,     1,    30,     3,     4,    -1,    34,
    35,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,    -1,
     1,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    26,
    27,    -1,     1,    30,     3,     4,    -1,    34,    35,    26,
    27,    -1,    -1,    30,    -1,    26,    27,    34,    35,    30,
    -1,    -1,    -1,    34,    35,    -1,    -1,    26,    27,    -1,
     1,    30,     3,     4,    -1,    34,    35,    -1,    -1,    -1,
     1,    -1,     3,     4,    -1,    -1,     1,    -1,     3,     4,
    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,     1,    30,
     3,     4,    -1,    34,    35,    26,    27,    -1,    -1,    30,
    -1,    26,    27,    34,    35,    30,     3,     4,    -1,    34,
    35,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
    -1,    34,    35,    12,    13,    14,    15,    16,    17,    26,
    27,    -1,    -1,    30,    -1,    -1,    -1,    34,    35
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
#line 47 "parser.y"
{yyerrok; printError(wrongfdef);;
    break;}
case 10:
#line 50 "parser.y"
{type_param = 1;;
    break;}
case 17:
#line 64 "parser.y"
{type_const = 1;;
    break;}
case 18:
#line 67 "parser.y"
{type_int = 1; type_void = 0;;
    break;}
case 19:
#line 68 "parser.y"
{type_void = 1; type_int = 0;;
    break;}
case 20:
#line 72 "parser.y"
{    //identifie가 중복으로 적혀있을 때 type이 바뀌는 것을 방지하기 위해 최초로 입력 될 때만 type을 저장한다.
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
#line 88 "parser.y"
{type_param = 0;;
    break;}
case 22:
#line 89 "parser.y"
{yyerrok;printError(noparen);;
    break;}
case 27:
#line 98 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 28:
#line 101 "parser.y"
{type_param = 1;;
    break;}
case 30:
#line 105 "parser.y"
{yyerrok; printError(nobrace);;
    break;}
case 36:
#line 117 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 39:
#line 122 "parser.y"
{yyerrok; printError(nocomma);;
    break;}
case 42:
#line 129 "parser.y"
{
						if (!found){
							if(type_param == 1){
								idttype = 5; //integer scalar fuction parameter
								HT[hashcode]->type = idttype;
								type_param = 0;
							 }
							else{
								if(type_int == 1){
									idttype = 1; //integer scalar variable
									 HT[hashcode]->type = idttype;

									if(type_const ==1){
										idttype = 7; //integer scalar const
										HT[hashcode]->type = idttype;
										type_const = 0;
									}
				   				}
							}
						}
					;
    break;}
case 43:
#line 151 "parser.y"
{ 
						if (!found){
							if(type_param == 1){
								idttype = 6; //integer array fuction parameter
								HT[hashcode]->type = idttype;
								type_param = 0;
							}
							else{
								if(type_int == 1){
									idttype = 2; //integer array variable
									HT[hashcode]->type = idttype;

									if(type_const ==1){
										idttype = 8; //integer array const
										HT[hashcode]->type = idttype;
										type_const = 0;
									}
								}
							}
						}
					;
    break;}
case 44:
#line 172 "parser.y"
{yyerrok; printError(nobrack);;
    break;}
case 58:
#line 196 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 63:
#line 203 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 64:
#line 204 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 66:
#line 208 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 67:
#line 209 "parser.y"
{yyerrok; printError(nocondition);;
    break;}
case 69:
#line 213 "parser.y"
{yyerrok; printError(nosemi);;
    break;}
case 73:
#line 221 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 75:
#line 223 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 77:
#line 225 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 79:
#line 227 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 81:
#line 229 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 83:
#line 231 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 86:
#line 236 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 89:
#line 241 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 92:
#line 246 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 94:
#line 248 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 97:
#line 253 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 99:
#line 255 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 101:
#line 257 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 103:
#line 259 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 106:
#line 264 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 108:
#line 266 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 111:
#line 271 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 113:
#line 273 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 115:
#line 275 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 118:
#line 280 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 120:
#line 282 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 122:
#line 284 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 124:
#line 286 "parser.y"
{yyerrok; printError(wrongst);;
    break;}
case 127:
#line 291 "parser.y"
{yyerrok; printError(nobrack);;
    break;}
case 129:
#line 293 "parser.y"
{yyerrok; printError(noparen);;
    break;}
case 137:
#line 310 "parser.y"
{
							if (!found){
								idttype = 9;
                                HT[hashcode]->type = idttype;
							}
						;
    break;}
case 140:
#line 318 "parser.y"
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
#line 320 "parser.y"



