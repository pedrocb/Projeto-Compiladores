%{
	#include <string.h>
	#include <stdio.h>
	#include "tree.h"
	#include "y.tab.h"

	#define COL col += yyleng;
	#define LINE line++; col=1;
	#define PRINT if(flag == 1) printf

	int flag = 0;
	int line=1;
	int col=1;
	int state_line=1;
	int state_col=1;
	int tree = 0;
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
STRUNT ({ESCAPE}|(\\*[^\n\"\\]*))*
STRINV (\\.|{STRANY})*


%%

{AMP}  			{PRINT("AMP\n"); COL; return AMP;}
{AND}  			{PRINT("AND\n"); COL; return AND;}
{ASSIGN}		{PRINT("ASSIGN\n"); COL; return ASSIGN;}
{AST}  			{PRINT("AST\n"); COL; return AST;}
{CHAR} 			{PRINT("CHAR\n"); COL; return CHAR;}
{COMMA} 		{PRINT("COMMA\n"); COL; return COMMA;}
{DIV} 			{PRINT("DIV\n"); COL; return DIV;}
{ELSE} 			{PRINT("ELSE\n"); COL; return ELSE;}
{EQ} 				{PRINT("EQ\n"); COL; return EQ;}
{FOR} 			{PRINT("FOR\n"); COL; return FOR;}
{GE} 				{PRINT("GE\n"); COL; return GE;}
{GT} 				{PRINT("GT\n"); COL; return GT;}
{IF} 				{PRINT("IF\n"); COL; return IF;}
{INT} 			{PRINT("INT\n"); COL; return INT;}
{LBRACE}		{PRINT("LBRACE\n"); COL; return LBRACE;}
{LE} 				{PRINT("LE\n"); COL; return LE;}
{LPAR} 			{PRINT("LPAR\n"); COL; return LPAR;}
{LSQ} 			{PRINT("LSQ\n"); COL; return LSQ;}
{LT} 				{PRINT("LT\n"); COL; return LT;}
{MINUS} 		{PRINT("MINUS\n"); COL; return MINUS;}
{MOD} 			{PRINT("MOD\n"); COL; return MOD;}
{NE} 				{PRINT("NE\n"); COL; return NE;}
{NOT} 			{PRINT("NOT\n"); COL; return NOT;}
{OR} 				{PRINT("OR\n"); COL; return OR;}
{PLUS} 			{PRINT("PLUS\n"); COL; return PLUS;}
{RBRACE}		{PRINT("RBRACE\n"); COL; return RBRACE;}
{RETURN}		{PRINT("RETURN\n"); COL; return RETURN;}
{RPAR} 			{PRINT("RPAR\n"); COL; return RPAR;}
{RSQ} 			{PRINT("RSQ\n"); COL; return RSQ;}
{SEMI} 			{PRINT("SEMI\n"); COL; return SEMI;}
{RESERVED} 	{PRINT("RESERVED(%s)\n",yytext); COL; return RESERVED;}
{VOID} 			{PRINT("VOID\n"); COL; return VOID;}

\n {LINE;}
\r {;}
[ \t]+ {COL;}


{ID} 							{PRINT("ID(%s)\n",yytext); COL; yylval.string = strdup(yytext); return ID;}
{INTLIT} 					{PRINT("INTLIT(%s)\n",yytext); COL; yylval.number = atoi(yytext); return INTLIT;}

"/*" 							{BEGIN COMMENT; state_line=line; state_col=col; COL;}
<COMMENT>"*/"			{BEGIN 0; COL;}
<COMMENT>\n				{LINE;}
<COMMENT>.				{COL;}
<COMMENT><<EOF>>	{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", state_line, state_col); COL;}


\'{CHRLIT}\'			{PRINT("CHRLIT(%s)\n", yytext); COL; yylval.string = strdup(yytext); return CHRLIT;}
\'{CHRUNT}				{printf("Line %d, col %d: unterminated char constant\n", line, col); COL;}
\'{CHRINV}\'			{printf("Line %d, col %d: invalid char constant (%s)\n", line, col, yytext); COL;}

\"{STRLIT}\"			{PRINT("STRLIT(%s)\n", yytext); COL; yylval.string = strdup(yytext); return STRLIT;}
\"{STRUNT}				{printf("Line %d, col %d: unterminated string constant\n", line, col); COL;}
\"{STRINV}\"			{printf("Line %d, col %d: invalid string constant (%s)\n", line, col, yytext); COL;}

. 								{printf("Line %d, col %d: illegal character (%s)\n", line, col, yytext); COL;}

%%

int main(int argc, char *argv[]){

	if(argc == 2){
		if(strcmp(argv[1],"-l") == 0){
			yylex();
		}
		else if(strcmp(argv[1],"-1") == 0){
			flag = 1;
			yylex();
		}
		else if(strcmp(argv[1],"-t") == 0){
			tree = 1;
			yyparse();
		}
	}
	else{
		yyparse();
	}



	return 0;
}

int yywrap(){
	return 1;
}

void yyerror (const char *s) {
	printf ("Line %d, col %d: %s: %s\n", line, col - (int)yyleng, s, yytext);
}
