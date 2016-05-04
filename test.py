import sys, os

vs = ['a', 'b', 'c', 'd', 'e']

def printcenas(s):
    os.system("echo '" + s + "' >> test.c")

def default_code():
    printcenas('#include<stdio.h>\n#include<stdlib.h>\n#define typename(x) _Generic((x),\\')
    printcenas('int: "int",       \\')
    printcenas('int *: "int*",    \\')
    printcenas('char: "char",     \\')
    printcenas('char *: "char*",  \\')
    printcenas('void *: "void*",  \\')
    printcenas('default: "other")')

    printcenas('int a;')
    printcenas('int *b;')
    printcenas('char c;')
    printcenas('char *d;')
    printcenas('void *e;')

    printcenas('int main(){\n\n')

def writecode(s):
    default_code();

    for i in vs:
        for j in vs:
            printcenas('printf("%s\\t' + s + ' %s\\t-> %s\\n", typename(' + i + '), typename(' + j + '), typename((' + i + s + j + ')));')

    printcenas('}')

def writecode1(s):
    default_code();

    for i in vs:
        printcenas('printf("' + s + ' %s\\t-> %s\\n", typename(' + i + '), typename((' + s + i + ')));')

    printcenas('}')


def main():
    os.system('rm output.txt')
    os.system('touch output.txt')

    for i in ['||', '&&', '==', '!=', '<', '>', '<=', '>=', '+', '-', '*', '/', '%', '=', ',']:
        os.system('rm test.c')
        os.system('rm a.out')
        os.system('touch test.c')
        writecode(i)
        os.system('echo "' + i + ' ERRORS-------------------------------------------------------------------------------------------------" >> output.txt')
        os.system('gcc -w test.c &>> output.txt')

        os.system('echo "' + i + ' WARNINGS-------------------------------------------------------------------------------------------------" >> output.txt')
        os.system('gcc test.c &>> output.txt')

        os.system('echo "' + i + ' OUTPUT-------------------------------------------------------------------------------------------------" >> output.txt')
        os.system('if [ -f a.out ]; then ./a.out >> output.txt; fi')
        os.system('echo "\n\n\n\n\n\n\n\n\n\n\n\n\n" >> output.txt')

    for i in ['!', '-', '+', '&', '*']:
        os.system('rm test.c')
        os.system('rm a.out')
        os.system('touch test.c')
        writecode1(i)
        os.system('echo "' + i + ' ERRORS-------------------------------------------------------------------------------------------------" >> output.txt')
        os.system('gcc -w test.c &>> output.txt')

        os.system('echo "' + i + ' WARNINGS-------------------------------------------------------------------------------------------------" >> output.txt')
        os.system('gcc test.c &>> output.txt')

        os.system('echo "' + i + ' OUTPUT-------------------------------------------------------------------------------------------------" >> output.txt')
        os.system('if [ -f a.out ]; then ./a.out >> output.txt; fi')
        os.system('echo "\n\n\n\n\n\n\n\n\n\n\n\n\n" >> output.txt')

main()
