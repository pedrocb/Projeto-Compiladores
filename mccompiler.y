%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdarg.h>
  #include "tree.h"

  int yylex(void);
  void yyerror(const char *s);


%}

%token AMP AND ASSIGN AST CHAR COMMA DIV ELSE EQ FOR GE GT IF
%token INT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RETURN RPAR RSQ SEMI
%token VOID RESERVED



%union{
    int number;
    char *string;
    node n;
}

%token <string> ID STRLIT CHRLIT
%token <number> INTLIT

%type <n> TypeSpec Declaration

%nonassoc IFCENAS
%nonassoc ELSE

%%

Start: Block Block_ {}
    ;

Epsilon: {};

Block: FunctionDefinition {}
    |  FunctionDeclaration {}
    |  Declaration {}
    ;

Block_: Epsilon {}
    |  Block_ Block {}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {}
    ;

FunctionBody: LBRACE Declaration Declaration_ GoodStatement Statement_ RBRACE {}
    | LBRACE GoodStatement Statement_ RBRACE {}
    | LBRACE Declaration Declaration_ RBRACE {}
    | LBRACE RBRACE {}
    | LBRACE error RBRACE {}
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {}
    ;

FunctionDeclarator: Ast_ ID LPAR ParameterList RPAR {}
    ;

ParameterList: ParameterDeclaration ParameterDeclaration_ {}
    ;

ParameterDeclaration: TypeSpec Ast_ IdOptional {}
    ;

ParameterDeclaration_: Epsilon {}
    | ParameterDeclaration_ COMMA ParameterDeclaration {}
    ;

Declaration: TypeSpec Declarator Declarator_ SEMI {}
    | error SEMI {}
    ;

Declaration_: Epsilon {}
    | Declaration_ Declaration {}
    ;

TypeSpec: CHAR {}
    |     INT  {}
    | 	  VOID {}
    ;

Declarator: Ast_ ID ArrayOptional {}
    ;

ArrayOptional: Epsilon {}
    | LSQ INTLIT RSQ {}
    ;

Declarator_: Epsilon {}
    | Declarator_ COMMA Declarator {}
    ;

Statement_: Epsilon {}
    | Statement_ Statement {}
    ;

Statement: error SEMI {}
    | GoodStatement {}
    ;

GoodStatement: ExprOptional SEMI {}
    | LBRACE GoodStatement Statement_ RBRACE {}
    | IfElseStatement {}
    | FOR LPAR ExprOptional SEMI ExprOptional SEMI ExprOptional RPAR Statement {}
    | RETURN ExprOptional SEMI {}
    | LBRACE error RBRACE {}
    | LBRACE RBRACE {}
    ;

IfElseStatement: IF LPAR Expr RPAR Statement %prec IFCENAS {}
    | IF LPAR Expr RPAR Statement ELSE Statement {}
    ;

Expr: CommaExpr ASSIGN Expr {}
    | CommaExpr {}
    | ID LPAR error RPAR {}
    | LPAR error RPAR {}
    ;

CommaExpr: CommaExpr COMMA SingleExpr {}
    | SingleExpr {}
    ;

SingleExpr: SingleExpr AND BinaryExpr {}
    | SingleExpr OR BinaryExpr {}
    | BinaryExpr {}
    ;

BinaryExpr: BinaryExpr EQ ComparationExpr {}
    | BinaryExpr NE ComparationExpr {}
    | BinaryExpr LT ComparationExpr {}
    | BinaryExpr GT ComparationExpr {}
    | BinaryExpr LE ComparationExpr {}
    | BinaryExpr GE ComparationExpr {}
    | ComparationExpr {}
    ;

ComparationExpr : ComparationExpr PLUS Term {}
    | ComparationExpr MINUS Term {}
    | Term {}
    ;

Term: Factor AST Term {}
    | Factor DIV Term {}
    | Factor MOD Term {}
    | Factor {}
    ;

Operator: AMP
    |  AST
    |  PLUS
    |  MINUS
    |  NOT
    ;

Factor: Operator Factor {}
    | Subfactor
    ;

Subfactor:Subfactor LSQ Expr RSQ {}
    | ID LPAR ExprOptional RPAR
    | ID
    | INTLIT
    | CHRLIT {printf("%s\n", $1);}
    | STRLIT {printf("%s\n", $1);}
    | LPAR Expr RPAR
    ;

ExprOptional: Epsilon {}
    | Expr {}
    ;

IdOptional: Epsilon {}
    | ID {}
    ;

Ast_: Epsilon {}
    | Ast_ AST {}
    ;

%%
