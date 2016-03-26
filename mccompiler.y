%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "tree.h"
%}

%token AMP AND ASSIGN AST CHAR COMMA DIV ELSE EQ FOR GE GT IF
%token INT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RETURN RPAR RSQ SEMI
%token VOID RESERVED



%union{
    int number;
    char character;
    char *string;
    node n;
}

%token <string> ID STRLIT
%token <number> INTLIT
%token <character> CHRLIT

%type <n> TypeSpec Declaration

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

Declaration: TypeSpec Declarator Declarator_ SEMI {$$ = create_node("Declaration"); add_child($$, $1); print_tree($$, 0);}
    ;

Declaration_: Epsilon {}
    | Declaration_ Declaration {}
    ;

TypeSpec: CHAR {$$ = create_node("Char");}
    |     INT  {$$ = create_node("Int");}
    | 	  VOID {$$ = create_node("Void");}
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

Factor: Operator Factor {}
    | Subfactor
    ;

Subfactor:Subfactor LSQ Expr RSQ {printf("mekie\n");}
    | ID LPAR ExpressionsOptional RPAR
    | ID
    | INTLIT
    | CHRLIT
    | STRLIT
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
