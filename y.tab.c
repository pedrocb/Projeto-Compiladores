/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mccompiler.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdarg.h>
  #include "tree.h"

  int yylex(void);
  void yyerror(const char *s);



#line 79 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
    AMP = 258,
    AND = 259,
    ASSIGN = 260,
    AST = 261,
    CHAR = 262,
    COMMA = 263,
    DIV = 264,
    ELSE = 265,
    EQ = 266,
    FOR = 267,
    GE = 268,
    GT = 269,
    IF = 270,
    INT = 271,
    LBRACE = 272,
    LE = 273,
    LPAR = 274,
    LSQ = 275,
    LT = 276,
    MINUS = 277,
    MOD = 278,
    NE = 279,
    NOT = 280,
    OR = 281,
    PLUS = 282,
    RBRACE = 283,
    RETURN = 284,
    RPAR = 285,
    RSQ = 286,
    SEMI = 287,
    VOID = 288,
    RESERVED = 289,
    ID = 290,
    STRLIT = 291,
    CHRLIT = 292,
    INTLIT = 293,
    IFCENAS = 294
  };
#endif
/* Tokens.  */
#define AMP 258
#define AND 259
#define ASSIGN 260
#define AST 261
#define CHAR 262
#define COMMA 263
#define DIV 264
#define ELSE 265
#define EQ 266
#define FOR 267
#define GE 268
#define GT 269
#define IF 270
#define INT 271
#define LBRACE 272
#define LE 273
#define LPAR 274
#define LSQ 275
#define LT 276
#define MINUS 277
#define MOD 278
#define NE 279
#define NOT 280
#define OR 281
#define PLUS 282
#define RBRACE 283
#define RETURN 284
#define RPAR 285
#define RSQ 286
#define SEMI 287
#define VOID 288
#define RESERVED 289
#define ID 290
#define STRLIT 291
#define CHRLIT 292
#define INTLIT 293
#define IFCENAS 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "mccompiler.y" /* yacc.c:355  */

    char *string;
    node n;

#line 202 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    38,    40,    41,    42,    45,    46,    49,
      52,    53,    54,    55,    56,    59,    62,    65,    68,    71,
      72,    75,    76,    79,    80,    83,    84,    85,    88,    91,
      92,    95,    96,    99,   100,   103,   104,   107,   108,   109,
     110,   111,   112,   113,   116,   117,   120,   121,   122,   123,
     126,   127,   128,   129,   132,   133,   137,   138,   141,   142,
     143,   146,   147,   148,   149,   150,   151,   152,   155,   156,
     157,   160,   161,   162,   163,   166,   167,   168,   169,   170,
     173,   174,   177,   178,   179,   180,   181,   182,   183,   186,
     187,   190,   191,   194,   195,   198,   199
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMP", "AND", "ASSIGN", "AST", "CHAR",
  "COMMA", "DIV", "ELSE", "EQ", "FOR", "GE", "GT", "IF", "INT", "LBRACE",
  "LE", "LPAR", "LSQ", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RETURN", "RPAR", "RSQ", "SEMI", "VOID", "RESERVED", "ID",
  "STRLIT", "CHRLIT", "INTLIT", "IFCENAS", "$accept", "Start", "Epsilon",
  "Block", "Block_", "FunctionDefinition", "FunctionBody",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterDeclaration", "ParameterDeclaration_", "Declaration",
  "Declaration_", "TypeSpec", "Declarator", "ArrayOptional", "Declarator_",
  "Statement_", "Statement", "GoodStatement", "IfElseStatement", "Expr",
  "Expr_without_comma", "Expr_without_comma_", "CommaExpr", "SingleExpr",
  "BinaryExpr", "ComparationExpr", "Term", "Operator", "Factor",
  "Subfactor", "ListExprOptional", "ExprOptional", "IdOptional", "Ast_", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -131

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-131)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    -9,  -131,  -131,  -131,    50,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,    14,  -131,    34,  -131,     7,  -131,
     138,  -131,  -131,  -131,     1,  -131,     6,    47,  -131,  -131,
      36,    45,   214,   393,  -131,  -131,  -131,  -131,   435,    61,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,    64,
      39,   109,     5,  -131,   458,    65,    69,     2,  -131,  -131,
      21,    43,  -131,  -131,  -131,   435,   435,    57,  -131,  -131,
      60,    62,    66,    81,  -131,   176,    11,  -131,   252,   435,
     458,   458,   458,   458,   458,   458,   458,   458,   458,   458,
     458,   435,    74,  -131,   458,   458,   458,   435,  -131,  -131,
      71,  -131,  -131,    63,    70,    75,  -131,   290,  -131,  -131,
    -131,    77,   431,    85,  -131,  -131,    31,    80,  -131,  -131,
    -131,    93,    89,  -131,  -131,  -131,  -131,    39,   109,   109,
       5,     5,     5,     5,     5,     5,  -131,  -131,   478,  -131,
    -131,  -131,    94,  -131,  -131,   116,    18,  -131,   435,   366,
    -131,  -131,    96,   386,  -131,   120,   478,  -131,   328,  -131,
    -131,    21,  -131,  -131,  -131,    97,   121,  -131,   104,   478,
    -131,  -131,  -131,   435,   366,  -131,  -131,   105,  -131,   366,
    -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    25,    26,    27,     0,     3,     4,     5,     6,
       3,    22,     1,     7,     0,    95,     0,     3,     0,     8,
       0,    15,     9,    31,     0,    96,     3,     0,    75,    76,
       0,     0,     0,     0,    78,    79,    77,    13,     3,    84,
      87,    86,    85,    91,     3,     3,     3,    39,    92,    47,
      57,    60,    67,    70,     0,    74,    81,     0,     3,    21,
       0,     0,    29,    28,    14,     3,     0,     0,    43,     3,
       0,     0,     0,     0,    23,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    80,     0,     0,     0,     0,    37,    32,
       0,     3,     3,     0,     0,     0,    42,     0,    49,    88,
      41,     0,     0,    84,    89,     3,    52,     0,    12,    24,
       3,     3,     0,    11,    34,    36,    46,    56,    58,    59,
      61,    66,    64,    65,    63,    62,    69,    68,     3,    71,
      72,    73,     0,    16,    19,    17,     3,    30,     3,     0,
      38,    48,     0,     0,    54,    90,     0,    83,     0,    35,
      82,     0,    94,    93,    18,     0,    44,    51,     0,     0,
      53,    10,    20,     3,     0,    50,    55,     0,    45,     0,
      40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,    -6,   122,  -131,  -131,  -131,  -131,  -131,  -131,
     -23,  -131,   -13,  -131,   -19,    88,  -131,  -131,   -61,  -130,
     -14,  -131,   -21,   -96,  -131,  -131,   -70,    -4,   359,    91,
    -131,    95,  -131,  -131,   -36,  -131,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    43,     6,    14,     7,    22,     8,    16,   100,
     101,   145,     9,    75,    10,    17,    63,    24,    78,   124,
     125,    47,    48,   115,   155,    49,    50,    51,    52,    53,
      54,    55,    56,   117,    57,   164,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    45,    72,   116,    15,    18,    46,    44,   107,    58,
     127,    23,    71,    25,    -2,     1,     1,    25,    69,   166,
      62,     2,     2,    11,    25,    60,    61,    89,     2,   104,
       3,     3,    90,    59,    98,    81,   156,     3,    74,    15,
      77,   102,    26,    81,   178,   105,   121,     4,     4,   180,
      12,    20,    15,   162,     4,    65,    45,    82,   126,   158,
     170,   120,   119,    77,    66,    82,    21,   114,   116,    79,
      71,    94,    80,   176,    95,    64,   142,   128,   129,    11,
      73,   103,   111,   116,    28,   106,   116,    29,    96,    97,
     108,    71,   109,   138,   147,   144,    15,   146,   110,   116,
     112,   143,   148,    34,   153,   149,    35,   151,    36,   154,
     157,    -3,   165,    61,    77,    62,   113,    40,    41,    42,
      83,   159,    84,    85,   161,   160,   167,    86,   169,   173,
      87,   174,   114,    88,   175,   179,    19,   177,   172,    27,
     163,    28,   102,     0,    29,     2,    99,   114,     0,    93,
      30,     0,     0,    31,     3,    32,     0,    33,     0,     0,
      34,     0,     0,    35,     0,    36,    37,    38,     0,     0,
      -3,     4,     0,    39,    40,    41,    42,     1,     0,    28,
     136,   137,    29,     2,     0,   139,   140,   141,    30,     0,
       0,    31,     3,    32,     0,    33,     0,     0,    34,     0,
       0,    35,     0,    36,   118,    38,     0,     0,    -3,     4,
       0,    39,    40,    41,    42,    67,     0,    28,     0,     0,
      29,     0,     0,     0,     0,     0,    30,     0,     0,    31,
       0,    32,     0,    33,     0,     0,    34,     0,     0,    35,
       0,    36,    68,    38,     0,     0,    -3,     0,     0,    39,
      40,    41,    42,   122,     0,    28,     0,     0,    29,     0,
       0,     0,     0,     0,    30,     0,     0,    31,     0,    32,
       0,    33,     0,     0,    34,     0,     0,    35,     0,    36,
     123,    38,     0,     0,    -3,     0,     0,    39,    40,    41,
      42,   122,     0,    28,     0,     0,    29,     0,     0,     0,
       0,     0,    30,     0,     0,    31,     0,    32,     0,    33,
       0,     0,    34,     0,     0,    35,     0,    36,   150,    38,
       0,     0,    -3,     0,     0,    39,    40,    41,    42,   122,
       0,    28,     0,     0,    29,     0,     0,     0,     0,     0,
      30,     0,     0,    31,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,     0,    36,   171,    38,     0,     0,
      -3,     0,     0,    39,    40,    41,    42,   122,     0,    28,
       0,     0,    29,     0,     0,     0,     0,     0,    30,     0,
       0,    31,     0,    32,     0,    33,     0,   168,    34,    28,
       0,    35,    29,    36,    70,    38,    28,     0,    -3,    29,
       0,    39,    40,    41,    42,   112,     0,     0,    34,     0,
       0,    35,    33,    36,     0,    34,    -3,     0,    35,     0,
      36,   113,    40,    41,    42,     0,     0,     0,    39,    40,
      41,    42,   152,     0,    28,     0,     0,    29,    28,     0,
       0,    29,   130,   131,   132,   133,   134,   135,     0,     0,
      33,     0,     0,    34,    33,     0,    35,    34,    36,     0,
      35,    28,    36,     0,    29,     0,    39,    40,    41,    42,
      39,    40,    41,    42,     0,     0,     0,    91,     0,     0,
      34,    28,     0,    35,    29,    36,     0,     0,     0,     0,
       0,     0,     0,    92,    40,    41,    42,   112,     0,     0,
      34,     0,     0,    35,     0,    36,     0,     0,     0,     0,
       0,     0,     0,   113,    40,    41,    42
};

static const yytype_int16 yycheck[] =
{
       6,    20,    38,    73,    10,    10,    20,    20,    69,     8,
      80,    17,    33,     6,     0,     1,     1,     6,    32,   149,
      26,     7,     7,    32,     6,    19,    20,    22,     7,    65,
      16,    16,    27,    32,    32,     4,     5,    16,    44,    45,
      46,    60,    35,     4,   174,    66,    35,    33,    33,   179,
       0,    17,    58,    35,    33,    19,    75,    26,    79,   120,
     156,    75,    75,    69,    19,    26,    32,    73,   138,     5,
      91,     6,     8,   169,     9,    28,    97,    81,    82,    32,
      19,    38,     1,   153,     3,    28,   156,     6,    23,    20,
      30,   112,    30,    19,    31,   101,   102,   102,    32,   169,
      19,    30,    32,    22,    19,    30,    25,    30,    27,   115,
      30,    30,   148,    20,   120,   121,    35,    36,    37,    38,
      11,    32,    13,    14,     8,    31,    30,    18,     8,    32,
      21,    10,   138,    24,    30,    30,    14,   173,   161,     1,
     146,     3,   161,    -1,     6,     7,    58,   153,    -1,    54,
      12,    -1,    -1,    15,    16,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    33,    -1,    35,    36,    37,    38,     1,    -1,     3,
      89,    90,     6,     7,    -1,    94,    95,    96,    12,    -1,
      -1,    15,    16,    17,    -1,    19,    -1,    -1,    22,    -1,
      -1,    25,    -1,    27,    28,    29,    -1,    -1,    32,    33,
      -1,    35,    36,    37,    38,     1,    -1,     3,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    15,
      -1,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    25,
      -1,    27,    28,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,     1,    -1,     3,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    15,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    25,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,     1,    -1,     3,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    15,    -1,    17,    -1,    19,
      -1,    -1,    22,    -1,    -1,    25,    -1,    27,    28,    29,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,     1,
      -1,     3,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    15,    -1,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,     1,    -1,     3,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    15,    -1,    17,    -1,    19,    -1,     1,    22,     3,
      -1,    25,     6,    27,     1,    29,     3,    -1,    32,     6,
      -1,    35,    36,    37,    38,    19,    -1,    -1,    22,    -1,
      -1,    25,    19,    27,    -1,    22,    30,    -1,    25,    -1,
      27,    35,    36,    37,    38,    -1,    -1,    -1,    35,    36,
      37,    38,     1,    -1,     3,    -1,    -1,     6,     3,    -1,
      -1,     6,    83,    84,    85,    86,    87,    88,    -1,    -1,
      19,    -1,    -1,    22,    19,    -1,    25,    22,    27,    -1,
      25,     3,    27,    -1,     6,    -1,    35,    36,    37,    38,
      35,    36,    37,    38,    -1,    -1,    -1,    19,    -1,    -1,
      22,     3,    -1,    25,     6,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    19,    -1,    -1,
      22,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    16,    33,    41,    43,    45,    47,    52,
      54,    32,     0,    42,    44,    42,    48,    55,    76,    43,
      17,    32,    46,    42,    57,     6,    35,     1,     3,     6,
      12,    15,    17,    19,    22,    25,    27,    28,    29,    35,
      36,    37,    38,    42,    52,    54,    60,    61,    62,    65,
      66,    67,    68,    69,    70,    71,    72,    74,     8,    32,
      19,    20,    42,    56,    28,    19,    19,     1,    28,    60,
       1,    62,    74,    19,    42,    53,    76,    42,    58,     5,
       8,     4,    26,    11,    13,    14,    18,    21,    24,    22,
      27,    19,    35,    71,     6,     9,    23,    20,    32,    55,
      49,    50,    54,    38,    74,    62,    28,    58,    30,    30,
      32,     1,    19,    35,    42,    63,    66,    73,    28,    52,
      60,    35,     1,    28,    59,    60,    62,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    19,    69,
      69,    69,    62,    30,    42,    51,    76,    31,    32,    30,
      28,    30,     1,    19,    42,    64,     5,    30,    58,    32,
      31,     8,    35,    42,    75,    74,    59,    30,     1,     8,
      63,    28,    50,    32,    10,    30,    63,    74,    59,    30,
      59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    43,    43,    44,    44,    45,
      46,    46,    46,    46,    46,    47,    48,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     2,     3,
       6,     4,     4,     2,     3,     3,     5,     2,     3,     1,
       3,     4,     2,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     2,     2,     1,     2,     4,     1,
       9,     3,     3,     2,     5,     7,     3,     1,     4,     3,
       4,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     4,     4,     1,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     2
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
        case 2:
#line 35 "mccompiler.y" /* yacc.c:1646  */
    {/*print_tree(add_to_tree("Program",1,$1),0);*/}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 38 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 41 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 42 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Declaration",0);}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 46 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 49 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 52 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 53 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 54 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 55 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 56 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 59 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 62 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 65 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 68 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 71 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 72 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 75 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 76 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 79 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 80 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 83 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Char",0);}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 84 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Int",0);}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 85 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Void",0);}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 88 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 91 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 92 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 95 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 96 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 99 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 100 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 103 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 104 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 107 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[-1].n);}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 108 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 109 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 110 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 111 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 112 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 113 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 116 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 117 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 120 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Store",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 121 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);print_tree((yyval.n),0);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 122 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 123 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 126 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 127 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 128 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 129 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 132 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 133 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 137 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Comma",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 138 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 141 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("And",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 142 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Or",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 143 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 146 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Eq",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 147 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Ne",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 148 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Lt",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 149 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Gt",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 150 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Le",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 151 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Ge",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 152 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 155 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Add",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 156 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Sub",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 157 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 160 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Mul",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 161 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Div",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 162 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Mod",2,(yyvsp[-2].n),(yyvsp[0].n));}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 163 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 166 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Addr",0);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 167 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Pointer",0);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 168 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Plus",0);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 169 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Minus",0);}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 170 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Not",0);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 173 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 174 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 177 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 178 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 179 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree(strcat(strcat("Id(",(yyvsp[0].string)),")"),0);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 180 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree((yyvsp[0].string),0);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 181 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree(strcat(strcat("ChrLit(",(yyvsp[0].string)),")"),0);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 182 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree(strcat(strcat("StrLit(",(yyvsp[0].string)),")"),0);}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 183 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[-1].n);}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 186 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 187 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 190 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = add_to_tree("Null",0);}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 191 "mccompiler.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 194 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 195 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 198 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 199 "mccompiler.y" /* yacc.c:1646  */
    {}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2059 "y.tab.c" /* yacc.c:1646  */
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
#line 202 "mccompiler.y" /* yacc.c:1906  */

