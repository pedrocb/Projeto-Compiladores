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

FunctionBody: LBRACE Declaration_ Statement_ RBRACE {}
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

Statement: error SEMI {}
    | LBRACE error RBRACE {}
    | GoodStatement {}
    ;

GoodStatement: ExprOptional SEMI {}
    | LBRACE Statement_ RBRACE {}
    | IfElseStatement {}
    | FOR LPAR ExprOptional SEMI ExprOptional SEMI ExprOptional RPAR GoodStatement {}
    | RETURN ExprOptional SEMI {}
    ;

IfElseStatement: IF LPAR Expr RPAR GoodStatement %prec IFCENAS {}
    | IF LPAR Expr RPAR GoodStatement ELSE GoodStatement {}
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
    | ID LPAR ExpressionsOptional RPAR
    | ID
    | INTLIT
    | CHRLIT {printf("%s\n", $1);}
    | STRLIT {printf("%s\n", $1);}
    | LPAR Expr RPAR
    ;


ExpressionsOptional: Epsilon {}
    | Expr
      //    | Expr Expr_ Not sure if this rule is needed over the above
    ;

/*Expr_: Epsilon {}
    | Expr_ COMMA Expr {}
    ;
*/

ExprOptional: Epsilon {}
    | Expr {}
    ;

IdOptional: Epsilon {}
    | ID {}
    ;

Ast_: Epsilon {}
    | Ast_ AST {}
    ;

Statement_: Epsilon {}
    | Statement_ Statement {}
    ;

%%
