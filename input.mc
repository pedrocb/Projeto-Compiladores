int c;

int coiso(int a){
  int b;
  b = 2;
  a = -b;
  coiso(a);
  return 1;
}

int main(void){
  coiso(c);
  return 0;
}
