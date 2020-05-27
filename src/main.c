#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"


#define MIN_ALLOC 1024

#define nodeSize 256
#define nodeFill 250
#define key xe*
#define strCopySized(str,src,size) strncpy(str,src,size); 
#define strCopy(str,src) strCopySized(str, src, strlen(src)) 
#define cr 2
#define crc(sn) ((int)(*sn) ^ ((*(sn+1))^0x3C))

typedef struct {void *data[nodeSize];int len;int cnt;void *parent; void *child;}xe; int vxx; char * empty="\0"; 
typedef struct {void **data         ;int len;int cnt;}args;
typedef struct {char *data[256000];int len;int cnt;}console; console x;  void setDAT(int num, char *value, key k); 
int strLength(char *str){char *d=str;while (*d!=0)d+=2;return d-str;} 
char *intToStr(int value){ char *text = (char *)malloc(1024);char *p = text+100;(*p--) = 0;while(value > 10){int rest = value - (((int)(value/10))*10);(*p--) = '0' + rest;value = (int)(value/10);}(*p) = '0' + value; return p;}
void addx( key ptr, void *tr){setDAT(ptr->cnt++,(char*)tr,ptr);}void addxe( key ptr,char *text){setDAT(ptr->cnt++,text,ptr);char *t = text;while (*t!=0)t+=2;ptr->len += (t-text);} 

//warns on c compilers (please use .cpp extension instead)
void addxe( key ptr, int value){char *text=intToStr(value);setDAT(ptr->cnt++,text,ptr);char *t = text;while (*t!=0)t+=2;ptr->len += (t-text);}void addxv( key ptr, int value){vxx = value;void *vPtr = &vxx;char *ok = (char*)malloc(5);strCopy(ok, (char*)vPtr);setDAT(ptr->cnt++,ok,ptr);ptr->len += 4;}
void addce(int value){char *text=intToStr(value);x.data[x.cnt++]=text;char *t = text;while (*t!=0)t+=2;x.len += (t-text);}

void addce(char *text){x.data[x.cnt++]=text;char *t = text;while (*t!=0)t+=2;x.len += (t-text);}
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

str lne="\n";
str keyTides=" ";
#define check(a) addce(a)
#define xcheck(a) addxe(k,a)
#define c(a) check(a);
#define line c(lne);
#define space c(keyTides);


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


#define WASM_EXPORT __attribute__((visibility("default")))


WASM_EXPORT
begin
 
  key star = onekey;
 
end


