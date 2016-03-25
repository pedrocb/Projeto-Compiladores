char buffer[20];
int main(int argc, char **argv) {
    int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (a == 0) {
    } else {
	for ( ; b > 0 ; )
	    if (a > b)
		a = a-b;
	    else
		b = b-a;
	return 0;
    }
}
