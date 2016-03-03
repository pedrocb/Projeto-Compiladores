AMP &
AND &&
ASSIGN =
AST "*"
CHAR char
COMMA ","
DIV "/"
ELSE else

%%
[" "|"\n"|"\t"]+ {printf("");}
{AMP}  {printf("AMP\n");}
{AND}  {printf("AND\n");}
{ASSIGN}  {printf("ASSIGN\n");}
{AST}  {printf("AST\n");}
{CHAR} {printf("CHAR\n");}
{COMMA} {printf("COMMA\n");}
{DIV} {printf("DIV\n");}
{ELSE} {printf("ELSE\n");}
{EQ} {printf("EQ\n");}
{FOR} {printf("FOR\n");}
{GE} {printf("GE\n");}
{GT} {printf("GT\n");}
{IF} {printf("IF\n");}
{INT} {printf("INT\n");}
{LBRACE} {printf("LBRACE\n");}
{LE} {printf("LE\n");}
{LPAR} {printf("LPAR\n");}
{LSQ} {printf("LSQ\n");}
{LT} {printf("LT\n");}
{MINUS} {printf("MINUS\n");}
{MOD} {printf("MOD\n");}
{NE} {printf("NE\n");}
{NOT} {printf("NOT\n");}
{OR} {printf("OR\n");}
{PLUS} {printf("PLUS\n");}
{RBRACE} {printf("RBRACE\n");}
{RETURN} {printf("RETURN\n");}
{RPAR} {printf("RPAR\n");}
{RSQ} {printf("RSQ\n");}
{SEMI} {printf("SEMI\n");}

. {;}

%%
int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}
