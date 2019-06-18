int newloop(int loopCount);


__attribute__((visibility("default")))
int main(int loopCount) {

  return newloop(6);
}

__attribute__((visibility("default")))
int newloop(int loopCount) {
  // int a=0;
  // for (int i=0 ; i <= loopCount ; i++) {
  //  a=a+i;
  //}
  return 5;
}