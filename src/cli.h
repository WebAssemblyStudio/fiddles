//TODO : use ky_ subsystem

#ifdef _Javascript
#define withcli var v = process.argv; v.shift();
function parsecli(a){
  key k = onekey;if (a.length<=1)add(empty);
  for(int ki=1;ki<a.length;ki++){
    add(a[ki]);
  }
  out k;
}
#else
#ifdef _CSharp
#define withcli string[] v = argv.Skip(1);
key parsecli(string[] a){
  key k = onekey;if (a.length<=1)add(empty);
  for(int ki=1;ki<a.length;ki++)
    add((any)(a[ki]));
  out k;
}
#else
#define withcli args *v = (args*)malloc(sizeof(args)); v->cnt = argc; v->data=(any)argv;
key parsecli(args *a){
  key k = onekey;if (a->cnt<=1)add(empty);
  for(int ki=1;ki<a->cnt;ki++)
    add((any)(a->data[ki]));
  out k;
}

#endif
#endif

#define getcli here=parsecli(v);
