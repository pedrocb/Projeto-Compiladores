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

%token <string> ID STRLIT CHRLIT INTLIT

%type <n> TypeSpec Declaration AMP AST PLUS MINUS NOT Operator Subfactor Expr Start Block Block_

%nonassoc IFCENAS
%nonassoc ELSE

%%


Start: Block Block_ {print_tree(add_to_tree("Program",2,$1,$2),0);}
    ;

Epsilon: {};

Block: FunctionDefinition {}
    |  FunctionDeclaration {}
    |  Declaration {$$ = add_to_tree("Declaration",0);}
    ;

Block_: Epsilon {$$ = NULL}
    | Block Block_ {$$ = add_brother($1, $2);}
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

Declaration_: Epsilon {$$ = NULL}
    | Declaration Declaration_ {$$ = add_brother($1, $2);}
    ;

TypeSpec: CHAR {$$ = add_to_tree("Char",0);}
    |     INT  {$$ = add_to_tree("Int",0);}
    | 	  VOID {$$ = add_to_tree("Void",0);}
    ;

Declarator: Ast_ ID ArrayOptional {}
    ;

ArrayOptional: Epsilon {}
    | LSQ INTLIT RSQ {}
    ;

Declarator_: Epsilon {}
    | Declarator_ COMMA Declarator {}
    ;

Statement_: Epsilon {$$ = NULL}
    | Statement Statement_ {$$ = add_brother($1, $2);}
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

Expr: CommaExpr ASSIGN Expr {$$ = add_to_tree("Store",2,$1,$3);}
    | CommaExpr {$$ = $1;}
    | ID LPAR error RPAR {}
    | LPAR error RPAR {}
    ;

Expr_without_comma: ID LPAR error RPAR {}
    | LPAR error RPAR {}
    | SingleExpr {}
    | SingleExpr ASSIGN Expr_without_comma {}
    ;

Expr_without_comma_: Epsilon {}
    | Expr_without_comma_ COMMA Expr_without_comma {}
    ;


CommaExpr: CommaExpr COMMA SingleExpr {}
    | SingleExpr {}
    ;

SingleExpr: SingleExpr AND BinaryExpr {$$ = add_to_tree("And",2,$1,$3);}
    | SingleExpr OR BinaryExpr {$$ = add_to_tree("Or",2,$1,$3);}
    | BinaryExpr {$$ = $1;}
    ;

BinaryExpr: BinaryExpr EQ ComparationExpr {$$ = add_to_tree("Eq",2,$1,$3);}
    | BinaryExpr NE ComparationExpr {$$ = add_to_tree("Ne",2,$1,$3);}
    | BinaryExpr LT ComparationExpr {$$ = add_to_tree("Lt",2,$1,$3);}
    | BinaryExpr GT ComparationExpr {$$ = add_to_tree("Gt",2,$1,$3);}
    | BinaryExpr LE ComparationExpr {$$ = add_to_tree("Le",2,$1,$3);}
    | BinaryExpr GE ComparationExpr {$$ = add_to_tree("Ge",2,$1,$3);}
    | ComparationExpr {$$ = $1;}
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

Operator: AMP {$$ = add_to_tree("Addr",0);}
    |  AST {$$ = add_to_tree("Pointer",0);}
    |  PLUS {$$ = add_to_tree("Plus",0);}
    |  MINUS {$$ = add_to_tree("Minus",0);}
    |  NOT {$$ = add_to_tree("Not",0);}
    ;

Factor: Operator Factor {}
    | Subfactor {}
    ;

Subfactor:Subfactor LSQ Expr RSQ {}
    | ID LPAR ListExprOptional RPAR {}
    | ID {$$ = add_to_tree(strcat(strcat("Id(",$1),")"),0);}
    | INTLIT {$$ = add_to_tree(strcat(strcat("IntLit(",$1),")"),0);}
    | CHRLIT {$$ = add_to_tree(strcat(strcat("ChrLit(",$1),")"),0);}
    | STRLIT {$$ = add_to_tree(strcat(strcat("StrLit(",$1),")"),0);}
    | LPAR Expr RPAR {}
    ;

ListExprOptional: Epsilon {}
    | Expr_without_comma Expr_without_comma_ {}


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
