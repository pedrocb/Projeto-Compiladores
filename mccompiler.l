AMP &
AND &&
ASSIGN =
AST "*"
CHAR char
%%
[" "|"\n"|"\t"]+ {printf("");}
{AMP}  {printf("AMP\n");}
{AND}  {printf("AND\n");}
{ASSIGN}  {printf("ASSIGN\n");}
{AST}  {printf("AST\n");}
{CHAR} {printf("CHAR\n");}
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
