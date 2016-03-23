%{
#include <stdio.h>
#include <stdlib.h>
%}

%token ID INTLIT CHRLIT STRLIT AMP AND ASSIGN AST CHAR COMMA DIV ELSE EQ FOR GE GT IF
%token INT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RETURN RPAR RSQ SEMI
%token VOID RESERVED

%%
Start: Block Block_ {printf("Hello");}
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

ExpressionsOptional: Epsilon {}
    | Expr Expr_
    ;
    
Expr_: Epsilon {}
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


