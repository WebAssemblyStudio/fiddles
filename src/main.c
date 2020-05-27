#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include <sys/uio.h>


#define MIN_ALLOC 1024

#define nodeSize 256
#define nodeFill 250
#define key xe*
#define strCopySized(str,src,size) strncpy(str,src,size); 
#define strCopy(str,src) strCopySized(str, src, strlen(src)) 
#define cr 2
#define crc(sn) ((int)(*sn) ^ ((*(sn+1))^0x3C))

typedef struct {void **data[nodeSize];int len;int cnt;void *parent; void *child;}xe; int vxx; char * empty="\0"; 
typedef struct {void **data         ;int len;int cnt;}args;
typedef struct {char *data[256000];int len;int cnt;}console; console x;  void setDAT(int num, char *value, key k); 
int strLength(char *str){char *d=str;while (*d!=0)d+=2;return d-str;} 
char *intToStr(int value){ char *text = (char *)malloc(1024);char *p = text+100;(*p--) = 0;while(value > 10){int rest = value - (((int)(value/10))*10);(*p--) = '0' + rest;value = (int)(value/10);}(*p) = '0' + value; return p;}
void addx( key ptr, void *tr){setDAT(ptr->cnt++,(char*)tr,ptr);}
void addxe( key ptr,char *text){setDAT(ptr->cnt++,text,ptr);char *t = text;while (*t!=0)t+=2;ptr->len += (t-text);} 
void addce(char *text){x.data[x.cnt++]=text;char *t = text;while (*t!=0)t+=2;x.len += (t-text);}

//warns on c compilers (please use .cpp extension instead)
//void addxe( key ptr, int value){char *text=intToStr(value);setDAT(ptr->cnt++,text,ptr);char *t = text;while (*t!=0)t+=2;ptr->len += (t-text);}void addxv( key ptr, int value){vxx = value;void *vPtr = &vxx;char *ok = (char*)malloc(5);strCopy(ok, (char*)vPtr);setDAT(ptr->cnt++,ok,ptr);ptr->len += 4;}
//void addce(int value){char *text=intToStr(value);x.data[x.cnt++]=text;char *t = text;while (*t!=0)t+=2;x.len += (t-text);}


char* consoleJoin(){char* ret = (char*)malloc(x.len+2); char *s, *d = ret;int cn=0; while(cn<(x.cnt)) {s=x.data[cn++];while(*s!=0)(*d++)=(*s++);}(*d++)=0; return ret;}

#define new(t) (t)malloc(sizeof(xe));
#define onekey (key)malloc(sizeof(xe))
#define keyInit(p) p->cnt =0; p->len =0; p->child =0;

void setCRC(char *name, void *value, key k){
if(strlen(name)>cr){
key xk = new(key) keyInit(xk) k->data[crc(name)]=(void*)xk; setCRC(name+cr,value,xk);} 
else k->data[crc(name)]=value;}

char *find( key k, char *n){ if(strlen(n)>cr){ key xk = (key)k->data[crc(n)]; if (xk) return find(xk,n+cr); else return empty;}else  return (char*)k->data[crc(n)];}

void setDAT(int num, char *value, key k){
if (num>nodeFill){ if (k->child==0){ key newk = new(key); keyInit(newk); k->child = (void*)newk;} setDAT(num-nodeSize,value,(key)k->child);  } 
else { k->data[num]=value; } }

char *getDAT(int nk, key k){
if (nk>nodeFill){ return getDAT(nk-nodeSize, (key)k->child);} 
else return (char*)k->data[nk];}

char *join( key xxe, char *by){int b = (*by) ? strlen(by) : 0; char *bs;int cn=0; char* ret = (char*)malloc(xxe->len+2+b*xxe->cnt);char *s, *d = ret;   while(cn<(xxe->cnt-1)) {    s=getDAT(cn++,xxe);while(*s!=0)strCopySized(d++,s++,1)   if (b){bs = by; strCopySized(d,bs,b) d+=b;}}   s=getDAT(cn++,xxe);while(*s!=0)strCopySized(d++,s++,1)   strCopySized(d,"\0",1); return ret;}
char *before(char *str, char *src){ char *s = str;int b = (*src) ? strlen(src) : 0; char *ret=(char*)malloc(strlen(str)+1);	char *d=ret;   while(*s!=0){if (b){ char *v=src; char *t=s;while(*t==*v){t++; v++;if ((v-src)==b){ if (d==(ret+b-1)) return empty; strCopySized(d,empty,1); return ret;}}}strCopySized(d++,s++,1);}   return str;}
char *after(char *str, char *src){ char *s = str;int b = (*src) ? strlen(src) : 0;	   while(*s!=0){if (b){ char *d=src; while(*s==*d){s++; d++; if ((d-src)==b) return s;}}s++;}   return str;}

#define str char *
#define any void *
#define ptr unsigned int *

key split(str src, str sep, key xk){ str in=(str)malloc(strlen(src)+1);	strcpy(in, src);keyInit(xk) str e=after(in, sep);	 addxe(xk, before(in,sep)); while(e!=in){*(e-1)=0;  in=e; addxe(xk, before(e,sep)); e=after(in, sep); }	return xk;}
str replace(str in, str sep, str by){key xk = split(in, sep, (key)malloc(sizeof(xe))); return join(xk, by);}


#define newroot key k=ky_create("");  key root = here; keys = new(key);
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

str lne="\n";
str keyTides=" ";
#define check(a) addce(a)
#define xcheck(a) addxe(k,a)
#define c(a) check(a);
#define line c(lne);
#define space c(keyTides);

console x;

str strA; str strB;

#define joinBy(by) join(here, by)
#define splitHere(in, by) sp = split(in, by, (key)malloc(sizeof(xe))); sp->parent = k; k=sp;
#define ifStrContains(a,b) strA=a; strB=b; if (after(strA,strB)!=strA)
#define strNotEmpty(s) (s!="")
#define strIsEmpty(s) (s=="")
#define endsWith(a,b) strIsEmpty(after(a,b))
#define startsWith(a,b) strIsEmpty(before(a,b))

#define quoteChar "'"
#define dblquoteChar "\""

#define quote(d) addce("'"); d; addce("'");
#define dblquote(d) addce("\""); d; addce("\"");
#define round(d) addce("("); d; addce(")");
#define curly(d) addce("{"); d; addce("}");
#define square(d) addce("["); d; addce("]");

#define con pn
#define build(p) str p; str p##con=stop;
#define finish(p) p=stop; c(p##con);
#define shout(p) finish(p) out p;
#define invoke(p) toGlobal(p); out local(p);


//eXtended pex
#define unload(x) (unsigned int)(*x);
#define console c
#define name(n,v,k) setCRC((char *)n,(void *)v,k);
#define set(n,v) name(#n,v,k);
#define get(s) find(k, #s)
#define push(s) if(containsKey(#s)){ k= (key)ky_find(k,#s); }else {sp=ky_create(#s); ky_set(k,#s,sp); k=sp;} 
#define begin int main() { newroot xinit axiom(core); global = core;
#define end done return 0; }
#define math atoi
#define index(s) getDAT(s,k)
#define stop consoleJoin(); xinit
#define here k
//only full back allowed
#define back k=root;
#define foreach(a) for(fe=0;fe<k->cnt || a=getDAT(fe,k);fe++)  
#define each while(!theLast)
#define containsKey(s) (k->data[vk_list][crc(s)]>0)
#define keyContainsKey(q,s) (q->data[vk_list][crc(s)]>0)
#define ifHereContains(s) strA = k->data[vk_label]; strB = s; if (after(strA,strB)!=strA)
//TODO
//#define ifKeyExists(q) 
#define item(n,v) name(n,v,here)

//eXtended veronunca
#define ray(n) key n=ky_create(#n);
#define axiom(a) key a=ky_create(#a);
#define bridge(a,n,v) ky_set(a,n,v);
#define adapter(d,b) str d##b(register key, register key);
#define adapted(d,b) d##b(register key core, register key global)
#define adapt(d,b) name(#b,(void*)d##b(d, global),d);
#define create(node) ray(_##node) bridge(core,node,_##node) adapter(core,node)
#define getter(node) str adapted(core,node)
#define eq value
#define setter(node) str adapted(core,node##eq)
#define toGlobal(node) adapt(core,node)
#define out return
#define node(n) (any) ky_find(root, #n)
#define data(n,v) ky_set(root, #n,v);
#define local(n)  n=(any) ky_find(global,#n);
#define toLocal(g,n) toGlobal(g); str n=ky_find(global,#g);
#define setLocal(n,v) ky_set(global, #n, v);
#define addLocal(v) ky_text(global, v);
#define uselocal key here = core; key root = here;
#define throw(errmsg) sp=(key)ky_find(global,exKey); ky_text(sp,errmsg); return lne;
#define catch sp=(key)ky_find(global,exKey); if(sp->cnt)
#define errorMessage (str) join((key)(ky_find(global,exKey)), lne)

int vk=0;int fe;
key sp;
key global;
key keys;
str exKey="ex";

#define vk_names 251
#define vk_label 252
#define vk_list 253
#define vk_getter 255

#define ky_list(in) in->data[vk_names];
#define ky_add(in, item) addxe(in->data[vk_list], item);
#define ky_set(in, name, item) addxe(in->data[vk_names], #name); setCRC(#name, item, in->data[vk_list]);
#define ky_text(in,txt) addxe(in, txt)
#define ky_find(in,label) find(in->data[vk_list], label)
#define ky_label(in,label) in->data[vk_label] = label;
#define ky_delete(in,name) ky_set(in, name, null);
#define ky_for(in, name, item) for(vk=0;vk<(in->data[vk_names]->cnt) || (name = in->data[vk_names][vk] && item=ky_find(in, name));vk++) 
//TODO : use adapter instead of join when present 
// and recurse procedure
#define output(in) join(in, empty)


key ky_create(str label){

	key ky = onekey; keyInit(ky);
	ky_label(ky, label);

	key names = onekey; keyInit(names);
	key list = onekey; keyInit(list);

	ky->data[vk_names] = names;
	ky->data[vk_list] = list;

	out ky;
}


#define WASM_EXPORT __attribute__((visibility("default")))


WASM_EXPORT

begin

  int i;
  for(i=0;i<100000;i++)
    console("x: ") console(intToStr(i))

  
end





/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}
