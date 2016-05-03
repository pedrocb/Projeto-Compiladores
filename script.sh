lex mccompiler.l
yacc -d -v mccompiler.y
cc -O0 -g -Wall -Wno-unused-function -o mccompiler y.tab.c lex.yy.c tree.c symboltable.c utils.c semantics.c #&> /dev/null
zip mccompiler.zip mccompiler.l mccompiler.y tree.h tree.c symboltable.c symboltable.h utils.c utils.h semantics.c semantics.h  &> /dev/null
./mccompiler -s < input.mc #> output
