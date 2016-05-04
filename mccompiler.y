%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdarg.h>
  #include "tree.h"

  int yylex(void);
  void yyerror(const char *s);

%}

%token INT LBRACE LPAR LSQ RBRACE RETURN RPAR RSQ SEMI
%token VOID RESERVED



%union{
  char *string;
  node n;
}

%token <string> ID STRLIT CHRLIT INTLIT AMP AND ASSIGN AST CHAR COMMA DIV ELSE EQ FOR GE GT IF LE LT MINUS MOD NE NOT OR PLUS

%type <n> TypeSpec Subfactor Expr Start Block Block_ AssignExpr Factor Term ComparationExpr BinaryExpr SingleExpr ExprOptional ListExprOptional Expr_without_comma Expr_without_comma_ IfElseStatement Ast_ ParameterDeclaration IdOptional Declarator Declarator_ ArrayOptional FunctionBody ParameterList ParameterDeclaration_ FunctionDeclarator FunctionDeclaration FunctionDefinition TestExpr RelationExpr FunctionCall Terminator
%type <n> Declaration Declaration_
%type <n> Statement GoodStatement Statement_ StatementList

%nonassoc IFCENAS
%nonassoc ELSE

%%


Start: Block Block_ {syntax_tree = add_to_tree("Program",NULL,2,$1,$2);}
    ;

Epsilon: {};

Block: FunctionDefinition {$$ = $1;}
|  FunctionDeclaration    {$$ = $1;}
|  Declaration            {$$ = $1;}
    ;

Block_: Epsilon     {$$ = NULL;}
    | Block Block_  {$$ = add_brother($1, $2);}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$ = add_to_tree("FuncDefinition",NULL,3,$1,$2,$3);}
    ;

FunctionBody: LBRACE Declaration Declaration_ GoodStatement Statement_ RBRACE {$$ = add_to_tree("FuncBody",NULL,4,$2,$3,$4,$5);}
    | LBRACE GoodStatement Statement_ RBRACE                                  {$$ = add_to_tree("FuncBody",NULL,2,$2,$3);}
    | LBRACE Declaration Declaration_ RBRACE                                  {$$ = add_to_tree("FuncBody",NULL,2,$2,$3);}
    | LBRACE RBRACE                                                           {$$ = add_to_tree("FuncBody",NULL,0);}
    | LBRACE error RBRACE                                                     {$$ = NULL;}
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$ = add_to_tree("FuncDeclaration",NULL,2,$1,$2);}
    ;

FunctionDeclarator: Ast_ ID LPAR ParameterList RPAR {node no = add_brother(add_to_tree("Id",$2,0),$4); $$ = add_brother($1,no);}
    ;

ParameterList: ParameterDeclaration ParameterDeclaration_ {$$ = add_to_tree("ParamList",NULL,2,$1,$2);}
    ;

ParameterDeclaration: TypeSpec Ast_ IdOptional {$$ = add_to_tree("ParamDeclaration",NULL,3,$1,$2,$3);}
    ;

ParameterDeclaration_: Epsilon                          {$$ = NULL;}
    | ParameterDeclaration_ COMMA ParameterDeclaration  {$$ = add_brother($1,$3);}
    ;

Declaration: TypeSpec Declarator Declarator_ SEMI{
      $2 = add_brother($2,$3);
      node t = $2;
      while(t != NULL){
    	  node no = add_to_tree($1->label,NULL,0);
    	  no = add_brother(no,t->child);
    	  t->child = no;
    	  t = t->brother;
      }
      $$ = $2;
      free($1->label);
      free($1->value);
      free($1);
    }
    | error SEMI {$$ = NULL;}
    ;

Declaration_: Epsilon           {$$ = NULL;}
    | Declaration Declaration_  {$$ = add_brother($1, $2);}
    ;

TypeSpec: CHAR {$$ = add_to_tree("Char",NULL,0);}
    |     INT  {$$ = add_to_tree("Int",NULL,0);}
    | 	  VOID {$$ = add_to_tree("Void",NULL,0);}
    ;

Declarator: Ast_ ID ArrayOptional{
      node no = add_to_tree("Id",$2,0);
      node to_add;
      if($1!=NULL){
      	$1 = add_brother($1,no);
      	to_add = $1;
      } else {
  	     to_add = no;
      }
      if($3!=NULL){
	     $$ = add_to_tree("ArrayDeclaration",NULL,2,to_add,$3);
      } else {
  	     $$ = add_to_tree("Declaration",NULL,1,to_add);
      }
      ;
 }
;

ArrayOptional: Epsilon  {$$ = NULL;}
| LSQ INTLIT RSQ    {$$ = add_to_tree("IntLit",$2,0);}
    ;

Declarator_: Epsilon                {$$ = NULL;}
    | Declarator_ COMMA Declarator  {$$ = add_brother($1,$3); }
    ;

Statement_: Epsilon {$$ = NULL;}
    | StatementList {$$ = $1;}
    ;

StatementList: Statement Statement_ {$$ = add_brother($1, $2);}
    ;

Statement: error SEMI {$$ = NULL;}
    | GoodStatement   {$$ = $1;}
    ;

GoodStatement: ExprOptional SEMI                                                {if(strcmp($1->label,"Null")==0){$$=NULL;free($1);}else{$$ = $1;}}
    | LBRACE StatementList RBRACE                                               {if($2!=NULL && $2->brother!= NULL) $$ = add_to_tree("StatList",NULL,1,$2); else $$ = $2;}
    | IfElseStatement                                                           {$$ = $1;}
    | FOR LPAR ExprOptional SEMI ExprOptional SEMI ExprOptional RPAR Statement  {if($9==NULL)$9 = add_to_tree("Null",NULL,0);$$ = add_to_tree("For",NULL,4,$3,$5,$7,$9); }
    | RETURN ExprOptional SEMI                                                  {$$ = add_to_tree("Return",NULL,1,$2);}
    | LBRACE error RBRACE                                                       {$$ = NULL;}
    | LBRACE RBRACE                                                             {$$ = NULL;}
    ;

IfElseStatement: IF LPAR Expr RPAR Statement %prec IFCENAS{
      if($3==NULL){
         $3 = add_to_tree("Null",NULL,0);
      }
      if($5==NULL){
         $5 = add_to_tree("Null",NULL,0);
      }
      node no = add_to_tree("Null",NULL,0);
      $$ = add_to_tree("If",NULL,3,$3,$5,no);
    }
    | IF LPAR Expr RPAR Statement ELSE Statement{
      if($5==NULL)
        $5 = add_to_tree("Null",NULL,0);
      if($7==NULL)
        $7 = add_to_tree("Null",NULL,0);
      $$ = add_to_tree("If",NULL,3,$3,$5,$7);
    }
    ;

Expr: Expr COMMA AssignExpr {$$ = add_to_tree("Comma",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | Expr_without_comma    {$$ = $1;}
    ;

Expr_without_comma: ID LPAR error RPAR  {$$ = add_to_tree("Null",NULL,0);}
    | LPAR error RPAR                   {$$ = add_to_tree("Null",NULL,0);}
    | AssignExpr                        {$$ = $1;}
    ;

Expr_without_comma_: Epsilon                        {$$ = NULL;}
    | COMMA Expr_without_comma Expr_without_comma_  {$$ = add_brother($2,$3);}
    ;

AssignExpr: SingleExpr ASSIGN AssignExpr  {$$ = add_to_tree("Store",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | SingleExpr                          {$$ = $1;}
    ;

SingleExpr: SingleExpr OR TestExpr  {$$ = add_to_tree("Or",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | TestExpr                      {$$ = $1;}
    ;

TestExpr:TestExpr AND BinaryExpr  {$$ = add_to_tree("And",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | BinaryExpr                  {$$ = $1;}
    ;

BinaryExpr: BinaryExpr EQ RelationExpr  {$$ = add_to_tree("Eq",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | BinaryExpr NE RelationExpr        {$$ = add_to_tree("Ne",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | RelationExpr                      {$$=$1;}
    ;

RelationExpr: RelationExpr LT ComparationExpr {$$ = add_to_tree("Lt",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | RelationExpr GT ComparationExpr         {$$ = add_to_tree("Gt",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | RelationExpr LE ComparationExpr         {$$ = add_to_tree("Le",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | RelationExpr GE ComparationExpr         {$$ = add_to_tree("Ge",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | ComparationExpr                         {$$ = $1;}
    ;


ComparationExpr : ComparationExpr PLUS Term {$$ = add_to_tree("Add",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | ComparationExpr MINUS Term            {$$ = add_to_tree("Sub",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | Term                                  {$$ = $1;}
    ;

Term: Term AST Factor {$$ = add_to_tree("Mul",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | Term DIV Factor {$$ = add_to_tree("Div",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | Term MOD Factor {$$ = add_to_tree("Mod",$2,2,$1,$3); $$->tline = @2.first_line; $$->tcol = @2.first_column;}
    | Factor          {$$ = $1;}
    ;

Factor: AMP Factor  {$$ = add_to_tree("Addr",$1,1,$2); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    |  AST Factor   {$$ = add_to_tree("Deref",$1,1,$2); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    |  PLUS Factor  {$$ = add_to_tree("Plus",$1,1,$2); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    |  MINUS Factor {$$ = add_to_tree("Minus",$1,1,$2); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    |  NOT Factor   {$$ = add_to_tree("Not",$1,1,$2); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    |  Subfactor    {$$ = $1;}
    ;

Subfactor:Subfactor LSQ Expr RSQ   {node no = add_to_tree("Add",NULL,2,$1,$3); $$ = add_to_tree("Deref",NULL,1,no);}
    | FunctionCall                {$$ = $1;}
    ;

FunctionCall: ID LPAR ListExprOptional RPAR {node no = add_to_tree("Id",$1,0);$$ = add_to_tree("Call",NULL,2,no,$3); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    | Terminator                            {$$ = $1;}
    ;

Terminator: ID        {$$ = add_to_tree("Id",$1,0); free($1); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    | INTLIT          {$$ = add_to_tree("IntLit",$1,0); free($1); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    | CHRLIT          {$$ = add_to_tree("ChrLit",$1,0); free($1); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    | STRLIT          {$$ = add_to_tree("StrLit",$1,0); free($1); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    | LPAR Expr RPAR  {$$ = $2;}
    ;

ListExprOptional: Epsilon                     {$$ = NULL;}
    |  Expr_without_comma Expr_without_comma_ {$$ = add_brother($1,$2);}
    ;

ExprOptional: Epsilon {$$ = add_to_tree("Null",NULL,0);}
    | Expr            {$$ = $1;}
    ;

IdOptional: Epsilon {$$ = NULL;}
    | ID            {$$ = add_to_tree("Id",$1,0); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    ;

Ast_: Epsilon   {$$ = NULL;}
    | AST Ast_  {node no = add_to_tree("Pointer",$1,0);$$ = add_brother(no,$2); $$->tline = @1.first_line; $$->tcol = @1.first_column;}
    ;

%%
