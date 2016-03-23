%{
#include <stdio.h>
#include <stdlib.h>
    %}

%%

Epsilon: {};

Start: Block Block_ {}
    ;

Block: FunctionDefinition {}
    |  FunctionDeclaration {}
    |  Declaration {}
    ;

Block_: epsilon {}
    |  Block_ Block {}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {}
    ;

FunctionBody: LBRACE Declaration_ Statement_ RBRACE {}
    ;	      

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {}
    ;

FunctionDeclarator: AST_ ID LPAR ParameterList RPAR {}
    ;

ParameterList: ParameterDeclaration ParameterDeclaration_ {}
    ;

ParameterDeclaration: TypeSpec Ast_ IdOptional {}
    ;

ParameterDeclaration_: epsilon {}
    | ParameterDeclaration_ COMMA ParameterDeclaration {}
    ;

Declaration: TypeSpec Declarator Declarator_ SEMI {}
    ;

Declaration_: epsilon {}
    | Declaration_ Declaration {}
    ;

TypeSpec: CHAR {}
    |     INT  {}
    | 	  VOID {}
    ;
    
Declarator: Ast_ ID ArrayOptional {}
    ;

ArrayOptional: epsilon {}
    | LSQ INTLIT RSQ {}
    ;

Declarator_: epsilon {}
    | Declarator_ COMMA Declarator {}
    ;

Statement: ExprOptional SEMI {}
    | LBRACE Statement_ RBRACE {}
    | IF LPAR Expr RPAR Statement ElseOptional {}
    | FOR LPAR ExprOptional SEMI ExprOptional SEMI ExprOptional RPAR Statement {}
    | RETURN ExprOptional SEMI;
    ;

Expr: Expr Operator Expr {}
    | Expr LSQ Expr RSQ {}
    | ID LPAR ExpressionsOptional RPAR
    | ID
    | INTLIT
    | CHRLIT
    | STRLIT
    | LPAR Expr RPAR
    ;

ExpressionsOptional: epsilon {}
    | Expr Expr_
    ;
    
Expr_: epsilon {}
    | Expr_ COMMA Expr {}
    ;
    
Operator: ASSIGN
    | COMMA
    | AND
    | OR
    | EQ
    | NE
    | LT
    | GT
    | LE
    | GE
    | PLUS
    | MINUS
    | AST
    | DIV
    | MOD
    ;

ElseOptional: epsilon {}
    | ElSE Statement {}
    ;

ExprOptional: epsilon {}
    | Expr {}
    ;

IdOptional: epsilon {}
    | ID {}
    ;
    
Ast_: epsilon {}
    | Ast_ AST {}
    ;

Statement_: epsilon {}
    | Statement_ Statement {}
    ;
%%


