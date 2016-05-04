%{
	#include <string.h>
	#include <stdio.h>
  #include "semantics.h"
	#include "y.tab.h"

	#define COL col += yyleng;
	#define LINE line++; col=1;
	#define PRINT if(flag == 1) printf
	#define RET if(meta1 == 0) return

	int line=1;
	int col=1;
	int state_line=1;
	int state_col=1;

	int meta1 = 0;
	int flag = 0;
%}

%X COMMENT

AMP "&"
AND "&&"
ASSIGN "="
AST "*"
CHAR char
COMMA ","
DIV "/"
ELSE else
EQ "=="
FOR for
GE ">="
GT ">"
IF if
INT int
LBRACE "{"
LE "<="
LPAR "("
LSQ "["
LT "<"
MINUS "-"
MOD "%"
NE "!="
NOT "!"
OR "||"
PLUS "+"
RBRACE "}"
RETURN return
RPAR ")"
RSQ "]"
SEMI ";"
VOID void
RESERVED "auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"long"|"register"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"while"|"double"|"enum"|"extern"|"float"|"for"|"goto"|"--"|"++"

LETTER [a-zA-Z]
NUMBER [0-9]

ID ({LETTER}|_)({LETTER}|{NUMBER}|_)*
INTLIT {NUMBER}+

ESCAPE \\(n|t|\\|\'|\"|([0-7]{1,3}))

CHRANY [^\\\'\n]
CHRLIT ({ESCAPE}|{CHRANY})
CHRUNT {CHRLIT}*\\*[^\n\']*
CHRINV (\\.|{CHRANY})*

STRANY [^\\\"\n]
STRLIT ({ESCAPE}|{STRANY})*
STRUNT ({ESCAPE}(\"\\\")|[^\"\n])*
STRINV (\\(.*)|{STRANY})*

%%

{AMP}  			{PRINT("AMP\n"); COL; RET AMP;}
{AND}  			{PRINT("AND\n"); COL; RET AND;}
{ASSIGN}		{PRINT("ASSIGN\n"); COL; RET ASSIGN;}
{AST}  			{PRINT("AST\n"); COL; RET AST;}
{CHAR} 			{PRINT("CHAR\n"); COL; RET CHAR;}
{COMMA} 		{PRINT("COMMA\n"); COL; RET COMMA;}
{DIV} 			{PRINT("DIV\n"); COL; RET DIV;}
{ELSE} 			{PRINT("ELSE\n"); COL; RET ELSE;}
{EQ} 				{PRINT("EQ\n"); COL; RET EQ;}
{FOR} 			{PRINT("FOR\n"); COL; RET FOR;}
{GE} 				{PRINT("GE\n"); COL; RET GE;}
{GT} 				{PRINT("GT\n"); COL; RET GT;}
{IF} 				{PRINT("IF\n"); COL; RET IF;}
{INT} 			{PRINT("INT\n"); COL; RET INT;}
{LBRACE}		{PRINT("LBRACE\n"); COL; RET LBRACE;}
{LE} 				{PRINT("LE\n"); COL; RET LE;}
{LPAR} 			{PRINT("LPAR\n"); COL; RET LPAR;}
{LSQ} 			{PRINT("LSQ\n"); COL; RET LSQ;}
{LT} 				{PRINT("LT\n"); COL; RET LT;}
{MINUS} 		{PRINT("MINUS\n"); COL; RET MINUS;}
{MOD} 			{PRINT("MOD\n"); COL; RET MOD;}
{NE} 				{PRINT("NE\n"); COL; RET NE;}
{NOT} 			{PRINT("NOT\n"); COL; RET NOT;}
{OR} 				{PRINT("OR\n"); COL; RET OR;}
{PLUS} 			{PRINT("PLUS\n"); COL; RET PLUS;}
{RBRACE}		{PRINT("RBRACE\n"); COL; RET RBRACE;}
{RETURN}		{PRINT("RETURN\n"); COL; RET RETURN;}
{RPAR} 			{PRINT("RPAR\n"); COL; RET RPAR;}
{RSQ} 			{PRINT("RSQ\n"); COL; RET RSQ;}
{SEMI} 			{PRINT("SEMI\n"); COL; RET SEMI;}
{RESERVED} 	{PRINT("RESERVED(%s)\n",yytext); COL; RET RESERVED;}
{VOID} 			{PRINT("VOID\n"); COL; RET VOID;}

\n {LINE;}
\r {;}
[ \t]+ {COL;}


{ID} 							{PRINT("ID(%s)\n",yytext); COL; yylval.string = strdup(yytext); RET ID;}
{INTLIT} 					{PRINT("INTLIT(%s)\n",yytext); COL; yylval.string = strdup(yytext); RET INTLIT; }

"/*" 							{BEGIN COMMENT; state_line=line; state_col=col; COL;}
<COMMENT>"*/"			{BEGIN 0; COL;}
<COMMENT>\n				{LINE;}
<COMMENT>.				{COL;}
<COMMENT><<EOF>>	{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", state_line, state_col); COL;}


\'{CHRLIT}\'			{PRINT("CHRLIT(%s)\n", yytext); COL; yylval.string = strdup(yytext); RET CHRLIT;}
\'{CHRUNT}				{printf("Line %d, col %d: unterminated char constant\n", line, col); COL;}
\'{CHRINV}\'			{printf("Line %d, col %d: invalid char constant (%s)\n", line, col, yytext); COL;}

\"{STRLIT}\"			{PRINT("STRLIT(%s)\n", yytext); COL; yylval.string = strdup(yytext); RET STRLIT;}
\"{STRUNT}				{printf("Line %d, col %d: unterminated string constant\n", line, col); COL;}
\"{STRINV}\"			{printf("Line %d, col %d: invalid string constant (%s)\n", line, col, yytext); COL;}

. 								{printf("Line %d, col %d: illegal character (%s)\n", line, col, yytext); COL;}

%%

int main(int argc, char *argv[]){
	toprint = 0;

	//Default Argument
	if(argc != 2)
	  argv[1] = "-3";

	//Meta 1
	if(strcmp(argv[1],"-1") == 0 || strcmp(argv[1],"-l") == 0){

	  if(strcmp(argv[1],"-l") == 0)
	    flag = 1;

	  meta1 = 1;
	  yylex();
	}

	//Meta 2
	if(strcmp(argv[1],"-2") == 0 || strcmp(argv[1],"-t") == 0){

	  if(strcmp(argv[1],"-t") == 0)
	    toprint = 1;

          yyparse();
	  print_and_free(syntax_tree,0);
	}

	//Meta 3
	if(strcmp(argv[1],"-3") == 0 || strcmp(argv[1],"-s") == 0){

	  if(strcmp(argv[1],"-s") == 0)
	    ;

          yyparse();
          symbol_tables = create_table("Global");
	  symbol_tables->to_print = 1;
	  current_table = symbol_tables;
	  add_predefined_functions(symbol_tables);
	  handle_tree(syntax_tree);
	  print_tables();
	  toprint = 1;
	  print_and_free(syntax_tree,0);
        }

	return 0;
}

int yywrap(){
	return 1;
}

void yyerror (const char *s) {
  int c = col - strlen(yytext);
  printf ("Line %d, col %d: %s: %s\n", line, c, s, yytext);
  toprint = 0;
}
