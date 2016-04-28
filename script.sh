lex mccompiler.l
yacc -d -v mccompiler.y
cc -Wall -Wno-unused-function -o mccompiler y.tab.c lex.yy.c tree.c symboltable.c utils.c  #&> /dev/null
zip mccompiler.zip mccompiler.l mccompiler.y tree.h tree.c symboltable.c symboltable.h utils.c utils.h  &> /dev/null
./mccompiler < input.mc #> output
