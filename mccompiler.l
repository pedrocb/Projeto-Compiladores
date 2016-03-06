%{
	#define COL col += yyleng;
	#define LINE line++; col=1;

	int line=1;
	int col=1;
	int comment_start=1;
%}

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
LETTER [a-zA-Z]
NUMBER [0-9]
ID ({LETTER}|_)({LETTER}|{NUMBER}|_)*
INTLIT {NUMBER}+("."({NUMBER}+))?


RESERVED "auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"long"|"register"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"while"|"double"|"enum"|"extern"|"float"|"for"|"goto"|"--"|"++"

%X COMMENT

%%

\n {LINE;}
[ \t]+ {COL;}

"/*" 					{BEGIN COMMENT; comment_start=line;}
<COMMENT>"*/"	{COL; BEGIN 0;}
<COMMENT>\n	{LINE;}
<COMMENT>.	{COL;}
<COMMENT><<EOF>>	{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", comment_start, col);}


{INTLIT} {printf("INTLIT(%s)\n",yytext); COL;}

{AMP}  {printf("AMP\n"); COL;}
{AND}  {printf("AND\n"); COL;}
{ASSIGN}  {printf("ASSIGN\n"); COL;}
{AST}  {printf("AST\n"); COL;}
{CHAR} {printf("CHAR\n"); COL;}
{COMMA} {printf("COMMA\n"); COL;}
{DIV} {printf("DIV\n"); COL;}
{ELSE} {printf("ELSE\n"); COL;}
{EQ} {printf("EQ\n"); COL;}
{FOR} {printf("FOR\n"); COL;}
{GE} {printf("GE\n"); COL;}
{GT} {printf("GT\n"); COL;}
{IF} {printf("IF\n"); COL;}
{INT} {printf("INT\n"); COL;}
{LBRACE} {printf("LBRACE\n"); COL;}
{LE} {printf("LE\n"); COL;}
{LPAR} {printf("LPAR\n"); COL;}
{LSQ} {printf("LSQ\n"); COL;}
{LT} {printf("LT\n"); COL;}
{MINUS} {printf("MINUS\n"); COL;}
{MOD} {printf("MOD\n"); COL;}
{NE} {printf("NE\n"); COL;}
{NOT} {printf("NOT\n"); COL;}
{OR} {printf("OR\n"); COL;}
{PLUS} {printf("PLUS\n"); COL;}
{RBRACE} {printf("RBRACE\n"); COL;}
{RETURN} {printf("RETURN\n"); COL;}
{RPAR} {printf("RPAR\n"); COL;}
{RSQ} {printf("RSQ\n"); COL;}
{SEMI} {printf("SEMI\n"); COL;}
{RESERVED} {printf("RESERVED(%s)\n",yytext); COL;}


{ID} {printf("ID(%s), col: %d\n",yytext, col); COL;}

. { COL;}

%%

int main(){

	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
