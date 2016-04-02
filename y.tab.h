/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 20 "mccompiler.y" /* yacc.c:1909  */

    char *string;
    node n;

#line 137 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
