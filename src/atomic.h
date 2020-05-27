#ifdef _CSharp
//TODO
//#define newroot key k=onekey; k->parent=(void*)k;  key root = here; keys = new(key); pconst
//#define done puts(consoleJoin());
//#define xinit x.cnt = 0; x.len = 0;
//#define add(a) xcheck(a);
//#define last getDAT(vk=(k->cnt-1), k)
//#define first getDAT(vk=0, k)
//#define hasData (k->cnt>0)
//#define theFirst (vk==0)
//#define theLast ((vk+1)==(k->cnt))
//#define next getDAT(++vk >= k->cnt ? vk=0 : vk, k)
//#define previous getDAT(--vk==0 ? k->cnt -1 : vk, k)
#endif

#ifdef _Javascript
#define newroot key k=onekey; k.parent=k;  key root = here; keys = new xe(); pconst
#define done puts(consoleJoin());
#define xinit x.cnt = 0; x.len = 0;
#define add(a) xcheck(a);
#define last getDAT(vk=(k->cnt-1), k)
#define first getDAT(vk=0, k)
#define hasData (k->cnt>0)
#define theFirst (vk==0)
#define theLast ((vk+1)==(k->cnt))
#define next getDAT(++vk >= k->cnt ? vk=0 : vk, k)
#define previous getDAT(--vk==0 ? k->cnt -1 : vk, k)
#else

#define newroot key k=onekey; k->parent=(void*)k;  key root = here; keys = new(key); pconst
#define done puts(consoleJoin());
#define xinit x.cnt = 0; x.len = 0;
#define add(a) xcheck(a);
#define last getDAT(vk=(k->cnt-1), k)
#define first getDAT(vk=0, k)
#define hasData (k->cnt>0)
#define theFirst (vk==0)
#define theLast ((vk+1)==(k->cnt))
#define next getDAT(++vk >= k->cnt ? vk=0 : vk, k)
#define previous getDAT(--vk==0 ? k->cnt -1 : vk, k)

#endif

str lne="\n";
str keyTides=" ";
#define check(a) addce(a)
#define xcheck(a) addxe(k,a)
#define c(a) check(a);
#define line c(lne);
#define space c(keyTides);
