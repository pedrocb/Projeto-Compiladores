char *buffr[20];

int gcd(int a,int b) {
  if (a == 0) {
    return b;
  } else {
    for (b=0 ; b > 0 ; b= b+1)
    if (a > b)
    a = a-b;
    else
    b = b-a;
    return a;
  }
}

int ola(int ola);

int puts(char* ola){
    return 1;
}

void* main(void a) {
  int gcd, b;
  int argc;
  if (argc > 2) {
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    puts(itoa(gcd(a,b), buffer));
  } else
  puts("Error: two parameters required.");
  return 0;
}

int ola(int ole){
    int a;
    int h;
    int ole;
    int a;
    return 1;
}

