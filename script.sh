lex mccompiler.l
cc -o mccompiler lex.yy.c
zip mccompiler.zip mccompiler.l
./mccompiler -l < input.mc
