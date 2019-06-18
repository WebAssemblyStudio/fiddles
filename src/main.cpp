__attribute__((visibility("default")))
int main(int loopCount) {
       long long a=0;
  for (int i=0 ; i <= loopCount ; i++) {
    a=a+i;
  }
  return a;
}

__attribute__((visibility("default")))
int newloop(int loopCount) {
  //int a=0;
  //for (int i=0 ; i <= loopCount ; i++) {
  //  a=a+i;
  //}
  return 5;
}