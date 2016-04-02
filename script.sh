lex mccompiler.l
yacc -d -v mccompiler.y
cc -Wall -Wno-unused-function -o mccompiler y.tab.c lex.yy.c tree.c #&> /dev/null
zip mccompiler.zip mccompiler.l mccompiler.y tree.h tree.c
./mccompiler -t  < input.mc #> output
