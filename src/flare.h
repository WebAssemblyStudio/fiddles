str strA; str strB;

#define joinBy(by) join(here, by)
#define splitHere(in, by) sp = split(in, by, (key)malloc(sizeof(xe))); sp->parent = k; k=sp;
#define ifStrContains(a,b) strA=a; strB=b; if (after(strA,strB)!=strA)

//todo : use ky_ subsystem and recurse
#define ifStrExists(sr) strA=join(k,"");


#ifndef _Javascript
#ifdef _CSharp
#define strNotEmpty(s) (!string.isNullOrEmpty(s))
#define strIsEmpty(s) (string.isNullOrEmpty(s))
#endif
#define strNotEmpty(s) ((strA=s)!=0 && strA[0]!=0)
#define strIsEmpty(s) ((strA=a)==0 || strA[0]==0)
#else
#define strNotEmpty(s) (s!="")
#define strIsEmpty(s) (s=="")
#endif
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


//TODO : set default getter and inherits
#define pconst ky_set(k,"@",onekey);

#ifdef _Javascript
#define strlen(s) s.length
#endif

#define len(s) strlen(s)

#ifdef _Javascript
#define takes =function
#else
#define takes
#endif

#ifdef _Javascript
#define jumps
#else
#ifdef _CSharp
delegate jumps void(key system);
#else
typedef void (*jumps)(key);
#endif

str cat takes(str a, str b){
	build(result)
		c(a) c(b)
	shout(result)
}

str strquote takes(str text){
	build(result) 
		quote(c(text)) 
	shout(result);
}

#define spaces " \r\n\t"

str stackEnd takes(str stack, str end, int start, int stop, str text){
	//TODO
}

str groupEnd takes(str group, int start, int stop, str text){
	//TODO
}

any jumpnext takes(key system){
	key table = ky_find(system, "table");
	str group = ky_find(system, "group");
	str txt = ky_find(system, "text");
	int stop = unload(ky_find(system, "stop"));
	int start = unload(ky_find(system, "start"));
	str token = groupEnd(group, start, stop, txt);
	jumps go = (jumps)ky_find(table, token);
	go(system);
}

any jump takes(str txt, key table){
	key system = table;
	ptr len = load(len(txt));
	ptr now = load(0);
	str group = join(ky_list(table), empty);
	ky_set(system, "root", "");
	ky_set(system, "node", "");
	ky_set(system, "text", txt);
	ky_set(system, "stop", len);
	ky_set(system, "start", now);
	ky_set(system, "table", table);
	ky_set(system, "group", group);

	int stop = unload(ky_find(system, stop));
	int start = unload(ky_find(system, start));
	while(start<stop){jumpnext(system);}

}



