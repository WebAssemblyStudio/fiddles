/*

Implementation of script helpers
Script v 0.08 (pex)


*/

#include "std.h"
#include "types/ky.h"

#ifndef SCRIPT_H
#define SCRIPT_H

#include "atomic.h"
#include "flare.h"
#include "cli.h"

//eXtended pex
ptr load(int val){ptr result = malloc(sizeof(ptr)); *result = val; return result}
ptr load(void* val){return (ptr)result;}
#define unload(x) (unsigned int)(*x);
#define console c
#define name(n,v,k) setCRC((char *)n,(void *)v,k);
#define set(n,v) name(#n,v,k);
#define get(s) find(k, #s)
#define push(s) if(containsKey(#s)) k= (key)ky_find(k,#s); else {sp=ky_create(cat(k o data[vk_label],s)); ky_set(k,s,sp); k=sp;} 
#define begin int main(int argc, str argv[]) { newroot xinit axiom(core); global = core;
#define end done return 0; }
#define math atoi
#define index(s) getDAT(s,k)
#define stop consoleJoin(); xinit
#define here k
//only full back allowed
#define back k=root;
#define foreach(a) for(fe=0;fe<k->cnt || a=getDAT(fe,k);fe++)  
#define each while(!theLast)
#define containsKey(s) (k o data[vk_list][crc(s)]>0)
#define keyContainsKey(q,s) (q o data[vk_list][crc(s)]>0)
#define ifHereContains(s) strA = k o data[vk_label]; strB = s; if (after(strA,strB)!=strA)
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
#define node(n) (any) ky_find(root, #n);
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
str exKey="ex";

#endif

