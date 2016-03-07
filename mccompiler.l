%{
	#define COL col += yyleng;
	#define LINE line++; col=1;
	#define PRINT if(flag == 1) printf

	int flag = 0;
	int line=1;
	int col=1;
	int state_line=1;
	int state_col=1;
%}

%X COMMENT CHR STR

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
INTLIT {NUMBER}+("."({NUMBER}+))?

ESCAPECHARS (n|t|\\|\'|\"|([0-7]{1,3}))
ESCAPE \\({ESCAPECHARS})

CHRANY [^\'\n]
CHRLIT ({ESCAPE}|{CHRANY})
CHRCAM (\\\')


STRLIT ({ESCAPE}|[^(\"|\n)])



%%

\n {LINE;}
[ \t]+ {COL;}

"/*" 					{BEGIN COMMENT; state_line=line; state_col=col; COL;}
<COMMENT>"*/"	{BEGIN 0; COL;}
<COMMENT>\n	{LINE;}
<COMMENT>.	{COL;}
<COMMENT><<EOF>>	{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", state_line, state_col); COL;}


\'{CHRLIT}\'			{PRINT("CHRLIT(%s)\n", yytext); COL;}
\'({CHRLIT}|{CHRCAM})*\'			{printf("Line %d, col %d: invalid char constant (%s)\n", line, col, yytext); COL;}
\'({CHRLIT}|{CHRCAM})*\n			{printf("Line %d, col %d: unterminated char constant\n", line, col); LINE;}


{AMP}  {PRINT("AMP\n"); COL;}
{AND}  {PRINT("AND\n"); COL;}
{ASSIGN}  {PRINT("ASSIGN\n"); COL;}
{AST}  {PRINT("AST\n"); COL;}
{CHAR} {PRINT("CHAR\n"); COL;}
{COMMA} {PRINT("COMMA\n"); COL;}
{DIV} {PRINT("DIV\n"); COL;}
{ELSE} {PRINT("ELSE\n"); COL;}
{EQ} {PRINT("EQ\n"); COL;}
{FOR} {PRINT("FOR\n"); COL;}
{GE} {PRINT("GE\n"); COL;}
{GT} {PRINT("GT\n"); COL;}
{IF} {PRINT("IF\n"); COL;}
{INT} {PRINT("INT\n"); COL;}
{LBRACE} {PRINT("LBRACE\n"); COL;}
{LE} {PRINT("LE\n"); COL;}
{LPAR} {PRINT("LPAR\n"); COL;}
{LSQ} {PRINT("LSQ\n"); COL;}
{LT} {PRINT("LT\n"); COL;}
{MINUS} {PRINT("MINUS\n"); COL;}
{MOD} {PRINT("MOD\n"); COL;}
{NE} {PRINT("NE\n"); COL;}
{NOT} {PRINT("NOT\n"); COL;}
{OR} {PRINT("OR\n"); COL;}
{PLUS} {PRINT("PLUS\n"); COL;}
{RBRACE} {PRINT("RBRACE\n"); COL;}
{RETURN} {PRINT("RETURN\n"); COL;}
{RPAR} {PRINT("RPAR\n"); COL;}
{RSQ} {PRINT("RSQ\n"); COL;}
{SEMI} {PRINT("SEMI\n"); COL;}
{RESERVED} {PRINT("RESERVED(%s)\n",yytext); COL;}

{INTLIT} {PRINT("INTLIT(%s)\n",yytext); COL;}
{ID} {PRINT("ID(%s)\n",yytext); COL;}

. {printf("Line %d, col %d: illegal character (%s)\n", line, col, yytext); COL;}

%%

int main(int argc, char *argv[]){

	if(argc == 2 && strcmp(argv[1],"-l") == 0)
			flag = 1;


	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
