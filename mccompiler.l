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

%%

[" "|"\n"|"\t"]+ {printf("");}
"/*"."*/" {printf("");}

{AMP}  {printf("AMP\n");}
{AND}  {printf("AND\n");}
{ASSIGN}  {printf("ASSIGN\n");}
{AST}  {printf("AST\n");}
{CHAR} {printf("CHAR\n");}
. {;}

%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
