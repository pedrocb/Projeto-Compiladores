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
    char *string;
    node n;
}

%token <string> ID STRLIT CHRLIT INTLIT

%type <n> TypeSpec Subfactor Expr Start Block Block_ CommaExpr Factor Term ComparationExpr BinaryExpr SingleExpr ExprOptional ListExprOptional Expr_without_comma Expr_without_comma_ IfElseStatement Ast_ ParameterDeclaration IdOptional Declarator Declarator_ ArrayOptional
%type <n> Declaration Declaration_
%type <n> Statement GoodStatement Statement_ StatementList

%nonassoc IFCENAS
%nonassoc ELSE

%%


Start: Block Block_ {/*print_tree(add_to_tree("Program",NULL,0),0);*/}
    ;

Epsilon: {};

Block: FunctionDefinition {}
    |  FunctionDeclaration {}
|  Declaration {$$ = $1;}
    ;

Block_: Epsilon {$$ = NULL;}
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

ParameterDeclaration: TypeSpec Ast_ IdOptional {$$ = add_to_tree("ParamDeclaration",NULL,3,$1,$2,$3);/*print_tree($$,0);*/}
    ;

ParameterDeclaration_: Epsilon {}
    | ParameterDeclaration_ COMMA ParameterDeclaration {}
    ;

Declaration: TypeSpec Declarator Declarator_ SEMI {
    $2 = add_brother($2,$3);
    node t = $2;
    while(t != NULL){
	node no = add_to_tree($1->label,NULL,0);
	no = add_brother(no,t->child);
	t->child = no;
	t = t->brother;
    }
    $$ = $2;
    print_tree($$,0);}
| error SEMI {}
    ;

Declaration_: Epsilon {$$ = NULL;}
| Declaration Declaration_ {$$ = add_brother($1, $2);}
    ;

TypeSpec: CHAR {$$ = add_to_tree("Char",NULL,0);}
    |     INT  {$$ = add_to_tree("Int",NULL,0);}
    | 	  VOID {$$ = add_to_tree("Void",NULL,0);}
    ;

Declarator: Ast_ ID ArrayOptional {node no = add_to_tree("Id",$2,0);node to_add;if($1!=NULL){$1 = add_brother($1,no); to_add = $1;} else {to_add = no;} if($3!=NULL){$$ = add_to_tree("ArrayDeclaration",NULL,2,to_add,$3);} else {$$ = add_to_tree("Declaration",NULL,1,to_add);};}
    ;

ArrayOptional: Epsilon {$$ = NULL;}
| LSQ INTLIT RSQ {printf("-.--%s---\n",$2);$$ = add_to_tree("IntLit",$2,0);}
    ;

Declarator_: Epsilon {$$ = NULL;}
    | Declarator_ COMMA Declarator {$$ = add_brother($1,$3);}
    ;

Statement_: Epsilon {$$ = NULL;}
    | StatementList {$$ = $1;}
    ;

StatementList: Statement Statement_ {if($1!=NULL) $$ = add_brother($1, $2); else {$$ = add_to_tree("Null",NULL,0);}}

Statement: error SEMI {}
    | GoodStatement {$$ = $1;}
    ;

GoodStatement: ExprOptional SEMI {if(strcmp($1->label,"Null")==0){$$=NULL;free($1);}else{$$ = $1;}}
    | LBRACE StatementList RBRACE {if($2->brother!= NULL) $$ = add_to_tree("StatList",NULL,1,$2); else $$ = $2;}
| IfElseStatement {$$ = $1;/*print_tree($$,0);*/}
    | FOR LPAR ExprOptional SEMI ExprOptional SEMI ExprOptional RPAR Statement {$$ = add_to_tree("For",NULL,4,$3,$5,$7,$9); /*print_tree($$,0);*/}
    | RETURN ExprOptional SEMI {}
    | LBRACE error RBRACE {}
    | LBRACE RBRACE {$$ = NULL;}
    ;

IfElseStatement: IF LPAR Expr RPAR Statement %prec IFCENAS {if($3==NULL){$3 = add_to_tree("NULL",NULL,0);} if($5==NULL){$5 = add_to_tree("NULL",NULL,0);} node no = add_to_tree("Null",NULL,0); $$ = add_to_tree("If",NULL,3,$3,$5,no);}
| IF LPAR Expr RPAR Statement ELSE Statement {if($3==NULL) $3 = add_to_tree("NULL",NULL,0); if($5==NULL) $5 = add_to_tree("NULL",NULL,0); if($7==NULL)$7 = add_to_tree("NULL",NULL,0);$$ = add_to_tree("If",NULL,3,$3,$5,$7);}
    ;

Expr: CommaExpr ASSIGN Expr {$$ = add_to_tree("Store",NULL,2,$1,$3);/*print_tree($$,0)*/;}
    | CommaExpr {$$ = $1;}
    | ID LPAR error RPAR {}
    | LPAR error RPAR {}
    ;

Expr_without_comma: ID LPAR error RPAR {}
    | LPAR error RPAR {}
    | SingleExpr {$$ = $1;}
    | SingleExpr ASSIGN Expr_without_comma {$$ = add_to_tree("Store",NULL,2,$1,$3);/*print_tree($$,0);*/}
    ;

Expr_without_comma_: Epsilon {$$ = NULL;}
    | COMMA Expr_without_comma {$$ = $2;}
    ;


CommaExpr: CommaExpr COMMA SingleExpr {$$ = add_to_tree("Comma",NULL,2,$1,$3);}
| SingleExpr {$$ = $1;}
    ;

SingleExpr: SingleExpr AND BinaryExpr {$$ = add_to_tree("And",NULL,2,$1,$3);}
| SingleExpr OR BinaryExpr {$$ = add_to_tree("Or",NULL,2,$1,$3);}
| BinaryExpr {$$ = $1;}
    ;

BinaryExpr: BinaryExpr EQ ComparationExpr {$$ = add_to_tree("Eq",NULL,2,$1,$3);}
| BinaryExpr NE ComparationExpr {$$ = add_to_tree("Ne",NULL,2,$1,$3);}
| BinaryExpr LT ComparationExpr {$$ = add_to_tree("Lt",NULL,2,$1,$3);}
| BinaryExpr GT ComparationExpr {$$ = add_to_tree("Gt",NULL,2,$1,$3);}
| BinaryExpr LE ComparationExpr {$$ = add_to_tree("Le",NULL,2,$1,$3);}
| BinaryExpr GE ComparationExpr {$$ = add_to_tree("Ge",NULL,2,$1,$3);}
| ComparationExpr {$$ = $1;}
    ;

ComparationExpr : ComparationExpr PLUS Term {$$ = add_to_tree("Add",NULL,2,$1,$3);}
| ComparationExpr MINUS Term {$$ = add_to_tree("Sub",NULL,2,$1,$3);}
| Term {$$ = $1;}
    ;

Term: Factor AST Term {$$ = add_to_tree("Mul",NULL,2,$1,$3);}
| Factor DIV Term {$$ = add_to_tree("Div",NULL,2,$1,$3);}
| Factor MOD Term {$$ = add_to_tree("Mod",NULL,2,$1,$3);}
| Factor {$$ = $1;}
    ;

Factor: AMP Factor {$$ = add_to_tree("Addr",NULL,1,$2);}
|  AST Factor {$$ = add_to_tree("Deref",NULL,1,$2);}
|  PLUS Factor {$$ = add_to_tree("Plus",NULL,1,$2);}
|  MINUS Factor {$$ = add_to_tree("Minus",NULL,1,$2);}
|  NOT Factor {$$ = add_to_tree("Not",NULL,1,$2);}
|  Subfactor {$$ = $1;}
    ;

Subfactor:Subfactor LSQ Expr RSQ {node no = add_to_tree("Add",NULL,2,$1,$3); $$ = add_to_tree("Deref",NULL,1,no);}
| ID LPAR ListExprOptional RPAR {node no = add_to_tree("Id",$1,0);$$ = add_to_tree("Call",NULL,2,no,$3);}
| ID {$$ = add_to_tree("Id",$1,0);}
| INTLIT {$$ = add_to_tree("IntLit",$1,0);}
| CHRLIT {$$ = add_to_tree("ChrLit",$1,0);}
| STRLIT {$$ = add_to_tree("StrLit",$1,0);}
| LPAR Expr RPAR {$$ = $2;}
    ;

ListExprOptional: Epsilon {$$ = NULL;}
    |  Expr_without_comma Expr_without_comma_ {$$ = add_brother($1,$2);}


ExprOptional: Epsilon {$$ = add_to_tree("Null",NULL,0);}
    | Expr {$$ = $1;}
    ;

IdOptional: Epsilon {$$ = NULL;}
    | ID {$$ = add_to_tree("Id",$1,0);}
    ;

Ast_: Epsilon {$$ = NULL;}
| AST Ast_ {node no = add_to_tree("Pointer",NULL,0);$$ = add_brother(no,$2);}
    ;

%%
