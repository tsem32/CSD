/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Hash.h"
extern int yylex(void);
extern int yylineno;
extern char *yytext;
int scope=0;
int counter=0;
int funcdefflag=0;
int funcall=0;
int tempexists=0;
int loop=0;

#line 83 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    STRING = 259,
    WHILE = 260,
    FOR = 261,
    IF = 262,
    ELSE = 263,
    FUNCTION = 264,
    RETURN = 265,
    BREAK = 266,
    CONTINUE = 267,
    AND = 268,
    OR = 269,
    NOT = 270,
    LOCAL = 271,
    TRUE = 272,
    FALSE = 273,
    NIL = 274,
    PLUS = 275,
    MINUS = 276,
    MUL = 277,
    MOD = 278,
    DIV = 279,
    EQUALS = 280,
    N_EQL = 281,
    PLUSPLUS = 282,
    MINUSMINUS = 283,
    ID = 284,
    ASSIGN = 285,
    REALNUMBER = 286,
    GRTR_EQL = 287,
    LESS_EQL = 288,
    GRTR = 289,
    LESS = 290,
    L_BRACKET = 291,
    R_BRACKET = 292,
    L_BRACE = 293,
    R_BRACE = 294,
    L_PAR = 295,
    R_PAR = 296,
    COMMA = 297,
    SEMCOL = 298,
    COLON = 299,
    DOT = 300,
    DBL_DOT = 301,
    WRONG_DEFINITION = 302,
    GLOB = 303
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define STRING 259
#define WHILE 260
#define FOR 261
#define IF 262
#define ELSE 263
#define FUNCTION 264
#define RETURN 265
#define BREAK 266
#define CONTINUE 267
#define AND 268
#define OR 269
#define NOT 270
#define LOCAL 271
#define TRUE 272
#define FALSE 273
#define NIL 274
#define PLUS 275
#define MINUS 276
#define MUL 277
#define MOD 278
#define DIV 279
#define EQUALS 280
#define N_EQL 281
#define PLUSPLUS 282
#define MINUSMINUS 283
#define ID 284
#define ASSIGN 285
#define REALNUMBER 286
#define GRTR_EQL 287
#define LESS_EQL 288
#define GRTR 289
#define LESS 290
#define L_BRACKET 291
#define R_BRACKET 292
#define L_BRACE 293
#define R_BRACE 294
#define L_PAR 295
#define R_PAR 296
#define COMMA 297
#define SEMCOL 298
#define COLON 299
#define DOT 300
#define DBL_DOT 301
#define WRONG_DEFINITION 302
#define GLOB 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "parser.y" /* yacc.c:355  */

	int intval;
	char* strval;
	float realval;

#line 225 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 240 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   601

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    57,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    72,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    90,    92,
      93,    97,   101,   105,   109,   113,   117,   119,   120,   121,
     122,   123,   124,   126,   155,   164,   185,   187,   188,   189,
     190,   192,   193,   194,   196,   197,   199,   200,   201,   202,
     203,   205,   206,   208,   209,   212,   213,   214,   216,   217,
     219,   219,   219,   220,   220,   229,   230,   231,   232,   233,
     234,   236,   242,   250,   252,   253,   255,   255,   256,   256,
     257,   258
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "STRING", "WHILE", "FOR",
  "IF", "ELSE", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND", "OR",
  "NOT", "LOCAL", "TRUE", "FALSE", "NIL", "PLUS", "MINUS", "MUL", "MOD",
  "DIV", "EQUALS", "N_EQL", "PLUSPLUS", "MINUSMINUS", "ID", "ASSIGN",
  "REALNUMBER", "GRTR_EQL", "LESS_EQL", "GRTR", "LESS", "L_BRACKET",
  "R_BRACKET", "L_BRACE", "R_BRACE", "L_PAR", "R_PAR", "COMMA", "SEMCOL",
  "COLON", "DOT", "DBL_DOT", "WRONG_DEFINITION", "GLOB", "$accept",
  "program", "stmt", "expr", "term", "assignexpr", "primary", "lvalue",
  "member", "call", "callsuffix", "normcall", "methodcall", "elist",
  "objectdef", "indexed", "indexedelem", "temp_id", "temp_st", "block",
  "$@1", "$@2", "funcdef", "$@3", "const", "idlist", "ifstmt", "whilestmt",
  "$@4", "forstmt", "$@5", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     207,   -85,   -85,   -39,   -36,   -33,   207,   -19,     5,   -30,
     -26,   279,   -10,   -85,   -85,   -85,   279,    -2,    -2,   -85,
     -85,    92,   -85,   245,   -85,    10,    31,   207,   316,   -85,
     -85,   -85,   523,   -85,    18,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   279,   -85,   -85,   -85,   -85,
     332,   -85,   -85,   -85,   -85,    82,    43,    11,    18,    11,
     279,   506,   -12,     0,   -85,   -85,   364,    51,   -85,   -85,
     -85,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   -85,   -85,   -85,   279,   279,   279,
      83,    89,   -85,   -85,   -85,   279,   279,    93,   279,   279,
     387,    62,   -85,    85,   300,   -85,   279,   -85,    96,   161,
     -85,    87,   550,   522,    82,    82,   -85,   -85,   -85,   566,
     566,    65,    65,    65,    65,   506,   456,   -13,   -85,    91,
     481,     2,   -85,   410,     7,   207,   106,    87,   279,   506,
     -85,   -85,   -85,   279,   -85,   -85,   279,   -85,   -85,   207,
     279,   -85,   -85,    19,   433,   -85,    23,    38,   -85,   348,
      98,   108,   -85,   -85,   -85,   279,   -85,   -85,    73,   207,
     -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    75,    77,     0,     0,     0,     0,    67,     0,     0,
       0,     0,     0,    79,    80,    78,     0,     0,     0,    43,
      76,    60,    70,     0,    13,     0,     0,     3,     0,    28,
      14,    36,    38,    46,    39,    40,    11,    12,    42,     5,
       6,     7,     8,    86,    88,     0,    85,    66,    73,    90,
       0,     9,    10,    31,    45,    30,     0,    32,     0,    34,
       0,    58,     0,     0,    63,    69,     0,     0,    44,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,    33,    35,     0,     0,    60,
       0,     0,    52,    54,    55,     0,    60,     0,     0,    60,
       0,     0,    91,     0,     0,    61,     0,    62,     0,     0,
      29,    41,    26,    27,    15,    16,    17,    19,    18,    24,
      25,    21,    23,    20,    22,    37,     0,     0,    47,     0,
       0,     0,    49,     0,     0,     0,    83,     0,     0,    59,
      64,    71,    68,    60,    48,    56,    60,    50,    51,     0,
       0,    84,    81,     0,     0,    72,     0,     0,    87,     0,
       0,     0,    65,    53,    57,    60,    74,    82,     0,     0,
      89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   112,    -6,    -5,   -85,   -85,   -85,    99,   -85,   107,
     -85,   -85,   -85,   -84,   -85,   -85,    34,   -85,   -85,   -16,
     -85,   -85,   -21,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      92,    93,    94,    62,    35,    63,    64,    48,   109,    36,
      65,   155,    37,   101,    38,   153,    39,    40,    98,    41,
      99,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    43,    67,    50,    44,   127,    53,    45,     1,     2,
      47,    55,   131,    51,    12,   134,    61,    52,    66,    54,
      11,    12,    13,    14,    15,   105,    16,    19,   145,   106,
     106,    69,    17,    18,    19,   103,    20,   107,    56,    68,
     100,    21,   108,   148,   106,    23,    25,    88,    49,   106,
     150,    89,     7,    25,    95,   104,    90,    91,    96,   156,
     160,   161,   157,    97,   163,   106,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   164,
     106,   168,   125,   126,    61,    73,    74,    75,    76,    77,
     130,    61,   111,   133,    61,     1,     2,    -1,    -1,    -1,
      -1,   139,   136,   142,    75,    76,    77,    11,    12,    13,
      14,    15,   128,    16,   169,   106,    57,    59,   129,    17,
      18,    19,   132,    20,    58,    58,   137,   143,    21,   151,
      60,   146,    23,   154,    60,   152,    22,   167,    61,    70,
      25,    61,   140,   158,   166,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,   170,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,     0,    11,    12,    13,    14,
      15,     0,    16,     0,     0,     0,     0,     0,    17,    18,
      19,     0,    20,     0,     0,     0,     0,    21,     0,    22,
     141,    23,     0,     0,    24,     0,     0,     0,     0,    25,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,    11,    12,    13,    14,    15,     0,    16,     0,
       0,     0,     0,     0,    17,    18,    19,     0,    20,     0,
       0,     0,     0,    21,     0,    22,     0,    23,     1,     2,
      24,     0,     0,     0,     7,    25,     0,     0,     0,     0,
      11,    12,    13,    14,    15,     0,    16,     0,     0,     0,
       0,     0,    17,    18,    19,     0,    20,     0,     0,     0,
       0,    21,     1,     2,     0,    23,     0,     0,     0,     0,
       0,     0,     0,    25,    11,    12,    13,    14,    15,     0,
      16,     0,     0,     0,     0,     0,    17,    18,    19,     0,
      20,     0,     0,    71,    72,    21,     0,     0,     0,    23,
      73,    74,    75,    76,    77,    78,    79,    25,     0,    71,
      72,     0,    80,    81,    82,    83,    73,    74,    75,    76,
      77,    78,    79,     0,   138,    71,    72,     0,    80,    81,
      82,    83,    73,    74,    75,    76,    77,    78,    79,    84,
       0,    71,    72,     0,    80,    81,    82,    83,    73,    74,
      75,    76,    77,    78,    79,   102,     0,    71,    72,     0,
      80,    81,    82,    83,    73,    74,    75,    76,    77,    78,
      79,   165,     0,     0,     0,     0,    80,    81,    82,    83,
      71,    72,     0,     0,     0,   110,     0,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    71,    72,     0,     0,     0,   135,     0,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    71,    72,     0,     0,
       0,   149,     0,    73,    74,    75,    76,    77,    78,    79,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    71,
      72,     0,   162,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,     0,    80,    81,
      82,    83,     0,   144,    71,    72,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,    79,     0,     0,
       0,     0,     0,    80,    81,    82,    83,     0,   147,    71,
      72,     0,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    71,     0,     0,    80,    81,
      82,    83,    73,    74,    75,    76,    77,    78,    79,     0,
      85,    86,     0,    87,    80,    81,    82,    83,     0,    88,
       0,     0,     0,    89,     0,     0,     0,     0,    90,    91,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    73,    74,    75,    76,
      77,    -1,    -1,     0,     0,     0,     0,     0,    80,    81,
      82,    83
};

static const yytype_int16 yycheck[] =
{
       6,    40,    23,     8,    40,    89,    11,    40,     3,     4,
      29,    16,    96,    43,    16,    99,    21,    43,    23,    29,
      15,    16,    17,    18,    19,    37,    21,    29,    41,    42,
      42,     0,    27,    28,    29,    56,    31,    37,    40,    29,
      45,    36,    42,    41,    42,    40,    48,    36,    43,    42,
      43,    40,     9,    48,    36,    60,    45,    46,    40,   143,
      41,    42,   146,    45,    41,    42,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    41,
      42,   165,    87,    88,    89,    20,    21,    22,    23,    24,
      95,    96,    41,    98,    99,     3,     4,    32,    33,    34,
      35,   106,    40,   109,    22,    23,    24,    15,    16,    17,
      18,    19,    29,    21,    41,    42,    17,    18,    29,    27,
      28,    29,    29,    31,    17,    18,    41,    40,    36,   135,
      38,    40,    40,   138,    38,    29,    38,    29,   143,    27,
      48,   146,   108,   149,   160,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,   169,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,    -1,
      -1,    -1,    -1,    36,    -1,    38,    -1,    40,     3,     4,
      43,    -1,    -1,    -1,     9,    48,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    36,     3,     4,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    15,    16,    17,    18,    19,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    -1,    -1,    13,    14,    36,    -1,    -1,    -1,    40,
      20,    21,    22,    23,    24,    25,    26,    48,    -1,    13,
      14,    -1,    32,    33,    34,    35,    20,    21,    22,    23,
      24,    25,    26,    -1,    44,    13,    14,    -1,    32,    33,
      34,    35,    20,    21,    22,    23,    24,    25,    26,    43,
      -1,    13,    14,    -1,    32,    33,    34,    35,    20,    21,
      22,    23,    24,    25,    26,    43,    -1,    13,    14,    -1,
      32,    33,    34,    35,    20,    21,    22,    23,    24,    25,
      26,    43,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      13,    14,    -1,    -1,    -1,    41,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    13,    14,    -1,    -1,    -1,    41,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    13,    14,    -1,    -1,
      -1,    41,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    13,
      14,    -1,    39,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    37,    13,    14,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    -1,    37,    13,
      14,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    13,    -1,    -1,    32,    33,
      34,    35,    20,    21,    22,    23,    24,    25,    26,    -1,
      27,    28,    -1,    30,    32,    33,    34,    35,    -1,    36,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    45,    46,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    15,    16,    17,    18,    19,    21,    27,    28,    29,
      31,    36,    38,    40,    43,    48,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    63,    68,    71,    73,    75,
      76,    78,    80,    40,    40,    40,    51,    29,    66,    43,
      52,    43,    43,    52,    29,    52,    40,    56,    58,    56,
      38,    52,    62,    64,    65,    69,    52,    71,    29,     0,
      50,    13,    14,    20,    21,    22,    23,    24,    25,    26,
      32,    33,    34,    35,    43,    27,    28,    30,    36,    40,
      45,    46,    59,    60,    61,    36,    40,    45,    77,    79,
      52,    72,    43,    71,    52,    37,    42,    37,    42,    67,
      41,    41,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    62,    29,    29,
      52,    62,    29,    52,    62,    41,    40,    41,    44,    52,
      65,    39,    51,    40,    37,    41,    40,    37,    41,    41,
      43,    51,    29,    74,    52,    70,    62,    62,    51,    52,
      41,    42,    39,    41,    41,    43,    68,    29,    62,    41,
      51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      62,    63,    63,    64,    64,    65,    66,    66,    67,    67,
      69,    70,    68,    72,    71,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    75,    77,    76,    79,    78,
      80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     4,     2,     6,     1,     1,     3,     5,     1,     3,
       0,     3,     3,     1,     3,     5,     1,     0,     2,     0,
       0,     0,     5,     0,     7,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     5,     2,     0,     6,     0,    10,
       2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 57 "parser.y" /* yacc.c:1646  */
    {
			printf("Program\n");
		}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "parser.y" /* yacc.c:1646  */
    {printf("Expression \n");}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "parser.y" /* yacc.c:1646  */
    {printf("ifstatement\n");}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 63 "parser.y" /* yacc.c:1646  */
    {printf("whilestatement\n");}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 64 "parser.y" /* yacc.c:1646  */
    {printf("forstatement\n");}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "parser.y" /* yacc.c:1646  */
    {printf("retstatement\n");}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "parser.y" /* yacc.c:1646  */
    {if(loop==0)printf("Break is not contained in active loop . line: %d\n",yylineno); printf("break\n");}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "parser.y" /* yacc.c:1646  */
    {if(loop==0)printf("Continue is not contained in active loop . line: %d\n",yylineno); printf("continue\n");}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 68 "parser.y" /* yacc.c:1646  */
    {printf("block\n");}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 69 "parser.y" /* yacc.c:1646  */
    {printf("funcdef\n");funcdefflag=0;}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 72 "parser.y" /* yacc.c:1646  */
    {if(funcall==1){
				printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
				funcall=0;
			} printf("assign expression\n");funcall=0;}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 76 "parser.y" /* yacc.c:1646  */
    {printf("expression  + expression \n");}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 77 "parser.y" /* yacc.c:1646  */
    {printf("expression - expression \n");}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 78 "parser.y" /* yacc.c:1646  */
    { printf("expression * expression  \n");}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 79 "parser.y" /* yacc.c:1646  */
    {printf("expression / expression  \n");}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 80 "parser.y" /* yacc.c:1646  */
    {printf("expression % expression \n");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 81 "parser.y" /* yacc.c:1646  */
    {printf("expression > expression %d>%d \n");}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 82 "parser.y" /* yacc.c:1646  */
    {printf("expression >= expression  \n");}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 83 "parser.y" /* yacc.c:1646  */
    {printf("expression  < expression  \n");}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 84 "parser.y" /* yacc.c:1646  */
    {printf("expression <= expression  \n");}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 85 "parser.y" /* yacc.c:1646  */
    {printf("expression == expression \n");}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 86 "parser.y" /* yacc.c:1646  */
    {printf("expression != expression  \n");}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 87 "parser.y" /* yacc.c:1646  */
    {printf("expression && expression  \n");}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "parser.y" /* yacc.c:1646  */
    {printf("expression || expression \n");}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 90 "parser.y" /* yacc.c:1646  */
    {printf("term\n");}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "parser.y" /* yacc.c:1646  */
    {printf("(expr)\n");}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "parser.y" /* yacc.c:1646  */
    {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("-expr\n");}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 97 "parser.y" /* yacc.c:1646  */
    {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("oxiexpr\n");}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 101 "parser.y" /* yacc.c:1646  */
    { if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        }printf("++lvalue\n");}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 105 "parser.y" /* yacc.c:1646  */
    {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("lvalue++\n");}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 109 "parser.y" /* yacc.c:1646  */
    {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("--lvalue\n");}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 113 "parser.y" /* yacc.c:1646  */
    {if(funcall==1){
                                printf("Syntax Error: In line %d .Trying to make an lvalue action to function[invalid action : rvalue ASSIGN].\n",yylineno);
                                funcall=0;
                        } printf("lvalue--\n");}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 117 "parser.y" /* yacc.c:1646  */
    { printf("termprimary\n");}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 119 "parser.y" /* yacc.c:1646  */
    {printf("lvalue=expr\n");}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 120 "parser.y" /* yacc.c:1646  */
    {printf("lvalue\n");}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 121 "parser.y" /* yacc.c:1646  */
    {printf("call\n");}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 122 "parser.y" /* yacc.c:1646  */
    {printf("objectdef\n");}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 123 "parser.y" /* yacc.c:1646  */
    {printf("(funcdef)\n");}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 124 "parser.y" /* yacc.c:1646  */
    {printf("const\n");}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 126 "parser.y" /* yacc.c:1646  */
    {printf("identifier\n"); 
             int i =0;
             i= Exists(yytext,scope,set_type(scope));
	     funcall=0;
             if(i==-1){  //An den uparxei to id dhlwmeno sto hashtable,valto
                Hash_Put(yytext,yylineno,scope,set_type(scope),0);
             }

              
            else if(is_func(yytext)!=-1 ){ //An uparxei sto hashtable,kai einai sunarthsh
                if(ez_active(yytext,scope)==0){ //Kai an den einai uparxei san energh metavlhth
                 funcall=1; }
             }
               else  if((i!=scope && i!=0)  && funcdefflag!=0 ){ 
//An auto pou koitaw den einai sto idio scope me auto pou vrhka sto symbol table 
//KAI h kataxwrhsh tou symbol tble DEN einai global
//KAI den paw na kanw dhlwsh sunarthshs 
                                           if(is_func(yytext)!=i){                    
                 		 printf("Variable %s not accessible in line %d\n",yytext,yylineno);
		     }
                }

              
             else if(i==scope && is_func(yytext)==1 && funcdefflag==1)
	  	{printf("Trying to redeclare variable that is function in same scope in line %d \n",yylineno);funcdefflag=0;
	          
             } 
             
        }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 155 "parser.y" /* yacc.c:1646  */
    {
		funcall=0;
		if(is_func(yytext)>=0){
			funcall=1;
		}
		if(Global_Exists(yytext)==-1){
			printf("Variable %s not globally declared in line : %d \n",yytext,yylineno);
		}
	}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 164 "parser.y" /* yacc.c:1646  */
    {tempexists=Exists(yytext,scope,set_type(scope));funcall=0;
		if(check_lib(yytext)==1){   //Des an einai sunarthsh bibliothikis

			printf("Error in line: %d . Shadowing not permitted \n");
		
		}else if(Local_Exists(yytext,scope)==-1 || ez_active(yytext,tempexists)==0){ //An den uparxei local metvlhth me to idio onoma H den uparxei active metavlhth me to idio onoma	
                      if(scope==0){
			   Hash_Put(yytext,yylineno,scope,GLOBAL,0);
			}else{  
                           Hash_Put(yytext,yylineno,scope,LCAL,0);
			}		
			
		}
                else if(Local_Exists(yytext,scope)==1 && ez_active(yytext,tempexists)!=0){ //An uparxei hdh h metavlhth sto idio scope pou vriskomai,kai einai energh
                    printf("Local variable %s redefinition in line %d: \n",yytext,yylineno);
                  }
	
	printf("|LOCAL ID\n");
	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 185 "parser.y" /* yacc.c:1646  */
    {printf("member\n");}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 187 "parser.y" /* yacc.c:1646  */
    {printf("lvalue.identifier\n");}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 188 "parser.y" /* yacc.c:1646  */
    {printf("lvalue expr\n");}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 189 "parser.y" /* yacc.c:1646  */
    {printf("call.identifier\n");}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 190 "parser.y" /* yacc.c:1646  */
    {printf("call expr\n");}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 192 "parser.y" /* yacc.c:1646  */
    {printf("(elist)\n");}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 193 "parser.y" /* yacc.c:1646  */
    {printf("lvaluecallsuffix\n");}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 194 "parser.y" /* yacc.c:1646  */
    {printf("(funcdef)(elist)\n");}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 196 "parser.y" /* yacc.c:1646  */
    {printf("normcall\n");funcall=1;}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 197 "parser.y" /* yacc.c:1646  */
    {printf("methodcall\n");}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 199 "parser.y" /* yacc.c:1646  */
    {printf("(elist)\n");}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 200 "parser.y" /* yacc.c:1646  */
    {printf("method call\n");}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 201 "parser.y" /* yacc.c:1646  */
    {printf("Expr\n");}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 202 "parser.y" /* yacc.c:1646  */
    {printf("Expr,..,Expr\n");}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 203 "parser.y" /* yacc.c:1646  */
    {printf("Empty Elist\n");}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 205 "parser.y" /* yacc.c:1646  */
    {printf(" [ Elist ] \n");}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 206 "parser.y" /* yacc.c:1646  */
    {printf(" [ Indexed ] \n");}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 208 "parser.y" /* yacc.c:1646  */
    {printf("Idexedelem\n");}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 209 "parser.y" /* yacc.c:1646  */
    {printf("indexedelem , indexedelem\n");}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 212 "parser.y" /* yacc.c:1646  */
    {printf("{ Expr : Expr }\n");}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 213 "parser.y" /* yacc.c:1646  */
    {}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 214 "parser.y" /* yacc.c:1646  */
    {printf("empty\n");}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 216 "parser.y" /* yacc.c:1646  */
    {}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 217 "parser.y" /* yacc.c:1646  */
    {}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 219 "parser.y" /* yacc.c:1646  */
    {scope++; }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 219 "parser.y" /* yacc.c:1646  */
    {Hide(scope);scope--; }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 219 "parser.y" /* yacc.c:1646  */
    {printf("block\n");}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 220 "parser.y" /* yacc.c:1646  */
    {funcdefflag=1;funcall=1;
                 if(check_lib(yytext)==1){
			printf("Shadowing of library function %s in line: %d \n",yytext,yylineno);
		 }else if(Exists(yytext,scope,set_type(scope))==scope){
			printf("Variable %s redefinition in line: %d \n",yytext,yylineno);
		 }else{
			Hash_Put(yytext,yylineno,scope,USERFUNC,1);
		}	
		}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 228 "parser.y" /* yacc.c:1646  */
    {printf("function def \n");}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 229 "parser.y" /* yacc.c:1646  */
    {printf("|NUMBER %s\n",yytext);}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 230 "parser.y" /* yacc.c:1646  */
    {printf("|REALNUMBER %s\n",yytext);}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 231 "parser.y" /* yacc.c:1646  */
    {printf("|STRING\n");}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 232 "parser.y" /* yacc.c:1646  */
    {printf("|NIL\n");}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 233 "parser.y" /* yacc.c:1646  */
    {printf("|TRUE\n");}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 234 "parser.y" /* yacc.c:1646  */
    {printf("|FALSE\n");}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 236 "parser.y" /* yacc.c:1646  */
    {if(check_formal(yytext,scope)==1){
		printf("Error: Formal argument redefinition in line : %d \n",yylineno);
	   }else{
		Hash_Put(yytext,yylineno,scope+1,FORMAL,0);
           }	
	printf("idlist ID\n");}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 242 "parser.y" /* yacc.c:1646  */
    {
	if(check_formal(yytext,scope)==1){
                printf("Error: Formal argument redefinition in line : %d \n",yylineno);
           }else{
                Hash_Put(yytext,yylineno,scope+1,FORMAL,0);
           }

	printf("idlist comma \n");}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 250 "parser.y" /* yacc.c:1646  */
    {;}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 252 "parser.y" /* yacc.c:1646  */
    {printf("if()\n");}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 253 "parser.y" /* yacc.c:1646  */
    {printf("ifelse stmt \n");}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 255 "parser.y" /* yacc.c:1646  */
    {loop++;}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 255 "parser.y" /* yacc.c:1646  */
    {loop--;printf("while()stmt\n");}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 256 "parser.y" /* yacc.c:1646  */
    {loop++;}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 256 "parser.y" /* yacc.c:1646  */
    {loop--;printf("|FOR (ELIST;EXPR;ELIST)STMT\n");}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 257 "parser.y" /* yacc.c:1646  */
    {if(funcdefflag==0)printf("Error in line:%d .Return statement not inside func declaration \n",yylineno);printf("return;\n");}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 258 "parser.y" /* yacc.c:1646  */
    {if(funcdefflag==0)printf("Error in line:%d .Return statement not inside func declaration \n",yylineno); printf("RETURN EXPR;\n");}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2151 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 261 "parser.y" /* yacc.c:1906  */

int yyerror (const char * YaccProvidedMessage)
{	
	if ((strstr(YaccProvidedMessage,"$end")))
		printf("Unexpected reach of the EOF.\n");
	else
		printf("%s -- in line %d , token %s \n ",YaccProvidedMessage,yylineno,yytext);
	return 0;
}


int main(int argc,char **argv)
{
	hash_init();
	yyparse();
	Hash_Print();
	return 0;
}
