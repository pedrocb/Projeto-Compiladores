lex mccompiler.l
yacc -d mccompiler.y
cc -o mccompiler y.tab.c lex.yy.c #tree.c #&> /dev/null
#zip mccompiler.zip mccompiler.l
./mccompiler -l < input.mc #> output
