%{
#include <stdio.h>
#include <stdlib.h>
%}

%token AMP AND ASSIGN AST CHAR COMMA DIV ELSE EQ FOR GE GT IF
%token INT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RETURN RPAR RSQ SEMI
%token VOID RESERVED



%union{
    int number;
    char character;
    char *string;
}

%token <string> ID STRLIT
%token <number> INTLIT
%token <character> CHRLIT SEMI //O semi esta so para teste, depois nao queremos o valor para nada

%%


 /*
Test: INTLIT ID SEMI {printf("%d - %s - %c\n", $1, $2, $3);}
    ;
 */

Start: Block Block_ {printf("Yup\n");}
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

Statement: ExprOptional SEMI {}
    | LBRACE Statement_ RBRACE {}
    | IF LPAR Expr RPAR Statement ElseOptional {}
    | FOR LPAR ExprOptional SEMI ExprOptional SEMI ExprOptional RPAR Statement {}
    | RETURN ExprOptional SEMI {}
    ;

Expr: SingleExpr ASSIGN Expr {}
    | Expr COMMA SingleExpr {}
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

Factor: Operator Factor
    | Factor LSQ Subfactor RSQ
    | Subfactor
    ;

Subfactor: ID LPAR ExpressionsOptional RPAR
    | ID
    | INTLIT
    | CHRLIT
    | STRLIT
    | LPAR Expr RPAR
    ;


ExpressionsOptional: Epsilon {}
    | Expr Expr_
    ;

Expr_: Epsilon {}
    | Expr_ COMMA Expr {}
    ;

ElseOptional: Epsilon {}
    | ELSE Statement {}
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

Statement_: Epsilon {}
    | Statement_ Statement {}
    ;

%%
