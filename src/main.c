#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  export memory memory(initial: 256, max: 256);

global g_a:int = 5245056;
global g_b:int = 0;
global g_c:int = 0;

export table indirect_function_table:funcref(min: 1, max: 1);

data d_cce2021__keyismecwko0gvYGr64(offset: 1024) = 
  "cce2021__keyisme\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00c|w{\f2"
  "ko\c50\01g+\fe\d7\abv\ca\82\c9}\faYG\f0\ad\d4\a2\af\9c\a4r\c0\b7\fd\93"
  "&6?\f7\cc4\a5\e5\f1q\d81\15\04\c7#\c3\18\96\05\9a\07\12\80\e2\eb'\b2u\09"
  "\83,\1a\1bnZ\a0R;\d6\b3)\e3/\84S\d1\00\ed \fc\b1[j\cb\be9JLX\cf\d0\ef\aa"
  "\fbCM3\85E\f9\02\7fP<\9f\a8Q\a3@\8f\92\9d8\f5\bc\b6\da!\10\ff\f3\d2\cd"
  "\0c\13\ec_\97D\17\c4\a7~=d]\19s`\81O\dc"*\90\88F\ee\b8\14\de^\0b\db\e0"
  "2:\0aI\06$\\c2\d3\acb\91\95\e4y\e7\c87m\8d\d5N\a9lV\f4\eaez\ae\08\bax%"
  ".\1c\a6\b4\c6\e8\ddt\1fK\bd\8b\8ap>\b5fH\03\f6\0ea5W\b9\86\c1\1d\9e\e1"
  "\f8\98\11i\d9\8e\94\9b\1e\87\e9\ceU(\df\8c\a1\89\0d\bf\e6BhA\99-\0f\b0"
  "T\bb\16\8d\01\02\04\08\10 @\80\1b6\00\00\00\00\00R\09j\d506\a58\bf@\a3"
  "\9e\81\f3\d7\fb|\e39\82\9b/\ff\874\8eCD\c4\de\e9\cbT{\942\a6\c2#=\eeL\95"
  "\0bB\fa\c3N\08.\a1f(\d9$\b2v[\a2Im\8b\d1%r\f8\f6d\86h\98\16\d4\a4\\cc]"
  "e\b6\92lpHP\fd\ed\b9\da^\15FW\a7\8d\9d\84\90\d8\ab\00\8c\bc\d3\0a\f7\e4"
  "X\05\b8\b3E\06\d0,\1e\8f\ca?\0f\02\c1\af\bd\03\01\13\8ak:\91\11AOg\dc\ea"
  "\97\f2\cf\ce\f0\b4\e6s\96\act"\e7\ad5\85\e2\f97\e8\1cu\dfnG\f1\1aq\1d)"
  "\c5\89o\b7b\0e\aa\18\be\1b\fcV>K\c6\d2y \9a\db\c0\fex\cdZ\f4\1f\dd\a83"
  "\88\07\c71\b1\12\10Y'\80\ec_`Q\7f\a9\19\b5J\0d-\e5z\9f\93\c9\9c\ef\a0\e0"
  ";M\ae*\f5\b0\c8\eb\bb<\83S\99a\17+\04~\baw\d6&\e1i\14cU!\0c}";
data d_ABCDEFGHIJKLMNOPQRSTUVWXYZab(offset: 1584) = 
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/\00\00"
  "\00\00\80\08P\00";

import function env_emscripten_resize_heap(a:int):int;

import function env_emscripten_memcpy_big(a:int, b:int, c:int):int;

export function wasm_call_ctors() {
  emscripten_stack_init()
}

function f_d(a:int, b:int) {
  var c:int = g_a;
  var d:int = 16;
  var e:int_ptr = c - d;
  g_a = e;
  e[3] = a;
  e[2] = b;
  var f:int = e[3];
  var g:int = e[2];
  f_e(f, g);
  var h:int = 16;
  var i:int = e + h;
  g_a = i;
}

function f_e(a:int, b:int) {
  var c:int = g_a;
  var d:int = 32;
  var e:int = c - d;
  e[7]:int = a;
  e[6]:int = b;
  var f:int = 0;
  e[5]:int = f;
  loop L_b {
    var g:int = e[5]:int;
    var h:int = 4;
    var i:int = g;
    var j:int = h;
    var k:int = i < j;
    var l:int = 1;
    var m:int = k & l;
    if (eqz(m)) goto B_a;
    var n:int = e[6]:int;
    var o:int = e[5]:int;
    var p:int = 2;
    var q:int = o << p;
    var r:int = 0;
    var s:int = q + r;
    var t:ubyte_ptr = n + s;
    var u:int = t[0];
    var v:int = e[7]:int;
    var w:int = e[5]:int;
    var x:int = 2;
    var y:int = w << x;
    var z:int = 0;
    var aa:int = y + z;
    var ba:byte_ptr = v + aa;
    ba[0] = u;
    var ca:int = e[6]:int;
    var da:int = e[5]:int;
    var ea:int = 2;
    var fa:int = da << ea;
    var ga:int = 1;
    var ha:int = fa + ga;
    var ia:ubyte_ptr = ca + ha;
    var ja:int = ia[0];
    var ka:int = e[7]:int;
    var la:int = e[5]:int;
    var ma:int = 2;
    var na:int = la << ma;
    var oa:int = 1;
    var pa:int = na + oa;
    var qa:byte_ptr = ka + pa;
    qa[0] = ja;
    var ra:int = e[6]:int;
    var sa:int = e[5]:int;
    var ta:int = 2;
    var ua:int = sa << ta;
    var va:int = 2;
    var wa:int = ua + va;
    var xa:ubyte_ptr = ra + wa;
    var ya:int = xa[0];
    var za:int = e[7]:int;
    var ab:int = e[5]:int;
    var bb:int = 2;
    var cb:int = ab << bb;
    var db:int = 2;
    var eb:int = cb + db;
    var fb:byte_ptr = za + eb;
    fb[0] = ya;
    var gb:int = e[6]:int;
    var hb:int = e[5]:int;
    var ib:int = 2;
    var jb:int = hb << ib;
    var kb:int = 3;
    var lb:int = jb + kb;
    var mb:ubyte_ptr = gb + lb;
    var nb:int = mb[0];
    var ob:int = e[7]:int;
    var pb:int = e[5]:int;
    var qb:int = 2;
    var rb:int = pb << qb;
    var sb:int = 3;
    var tb:int = rb + sb;
    var ub:byte_ptr = ob + tb;
    ub[0] = nb;
    var vb:int = e[5]:int;
    var wb:int = 1;
    var xb:int = vb + wb;
    e[5]:int = xb;
    continue L_b;
  }
  unreachable;
  label B_a:
  var yb:int = 4;
  e[5]:int = yb;
  loop L_d {
    var zb:int = e[5]:int;
    var ac:int = 44;
    var bc:int = zb;
    var cc:int = ac;
    var dc:int = bc < cc;
    var ec:int = 1;
    var fc:int = dc & ec;
    if (eqz(fc)) goto B_c;
    var gc:int = e[5]:int;
    var hc:int = 1;
    var ic:int = gc - hc;
    var jc:int = 2;
    var kc:int = ic << jc;
    e[3]:int = kc;
    var lc:int = e[7]:int;
    var mc:int = e[3]:int;
    var nc:int = 0;
    var oc:int = mc + nc;
    var pc:ubyte_ptr = lc + oc;
    var qc:int = pc[0];
    e[8]:byte = qc;
    var rc:int = e[7]:int;
    var sc:int = e[3]:int;
    var tc:int = 1;
    var uc:int = sc + tc;
    var vc:ubyte_ptr = rc + uc;
    var wc:int = vc[0];
    e[9]:byte = wc;
    var xc:int = e[7]:int;
    var yc:int = e[3]:int;
    var zc:int = 2;
    var ad:int = yc + zc;
    var bd:ubyte_ptr = xc + ad;
    var cd:int = bd[0];
    e[10]:byte = cd;
    var dd:int = e[7]:int;
    var ed:int = e[3]:int;
    var fd:int = 3;
    var gd:int = ed + fd;
    var hd:ubyte_ptr = dd + gd;
    var id:int = hd[0];
    e[11]:byte = id;
    var jd:int = e[5]:int;
    var kd:int = 3;
    var ld:int = jd & kd;
    if (ld) goto B_e;
    var md:int = e[8]:ubyte;
    e[7]:byte = md;
    var nd:int = e[9]:ubyte;
    e[8]:byte = nd;
    var od:int = e[10]:ubyte;
    e[9]:byte = od;
    var pd:int = e[11]:ubyte;
    e[10]:byte = pd;
    var qd:int = e[7]:ubyte;
    e[11]:byte = qd;
    var rd:int = e[8]:ubyte;
    var sd:int = 255;
    var td:ubyte_ptr = rd & sd;
    var ud:int = td[1056];
    e[8]:byte = ud;
    var vd:int = e[9]:ubyte;
    var wd:int = 255;
    var xd:ubyte_ptr = vd & wd;
    var yd:int = xd[1056];
    e[9]:byte = yd;
    var zd:int = e[10]:ubyte;
    var ae:int = 255;
    var be:ubyte_ptr = zd & ae;
    var ce:int = be[1056];
    e[10]:byte = ce;
    var de:int = e[11]:ubyte;
    var ee:int = 255;
    var fe:ubyte_ptr = de & ee;
    var ge:int = fe[1056];
    e[11]:byte = ge;
    var he:int = e[8]:ubyte;
    var ie:int = 255;
    var je:int = he & ie;
    var ke:int = e[5]:int;
    var le:int = 2;
    var me:ubyte_ptr = ke >> le;
    var ne:int = me[1312];
    var oe:int = 255;
    var pe:int = ne & oe;
    var qe:int = je ^ pe;
    e[8]:byte = qe;
    label B_e:
    var re:int = e[5]:int;
    var se:int = 2;
    var te:int = re << se;
    e[4]:int = te;
    var ue:int = e[5]:int;
    var ve:int = 4;
    var we:int = ue - ve;
    var xe:int = 2;
    var ye:int = we << xe;
    e[3]:int = ye;
    var ze:int = e[7]:int;
    var af:int = e[3]:int;
    var bf:int = 0;
    var cf:int = af + bf;
    var df:ubyte_ptr = ze + cf;
    var ef:int = df[0];
    var ff:int = 255;
    var gf:int = ef & ff;
    var hf:int = e[8]:ubyte;
    var if:int = 255;
    var jf:int = hf & if;
    var kf:int = gf ^ jf;
    var lf:int = e[7]:int;
    var mf:int = e[4]:int;
    var nf:int = 0;
    var of:int = mf + nf;
    var pf:byte_ptr = lf + of;
    pf[0] = kf;
    var qf:int = e[7]:int;
    var rf:int = e[3]:int;
    var sf:int = 1;
    var tf:int = rf + sf;
    var uf:ubyte_ptr = qf + tf;
    var vf:int = uf[0];
    var wf:int = 255;
    var xf:int = vf & wf;
    var yf:int = e[9]:ubyte;
    var zf:int = 255;
    var ag:int = yf & zf;
    var bg:int = xf ^ ag;
    var cg:int = e[7]:int;
    var dg:int = e[4]:int;
    var eg:int = 1;
    var fg:int = dg + eg;
    var gg:byte_ptr = cg + fg;
    gg[0] = bg;
    var hg:int = e[7]:int;
    var ig:int = e[3]:int;
    var jg:int = 2;
    var kg:int = ig + jg;
    var lg:ubyte_ptr = hg + kg;
    var mg:int = lg[0];
    var ng:int = 255;
    var og:int = mg & ng;
    var pg:int = e[10]:ubyte;
    var qg:int = 255;
    var rg:int = pg & qg;
    var sg:int = og ^ rg;
    var tg:int = e[7]:int;
    var ug:int = e[4]:int;
    var vg:int = 2;
    var wg:int = ug + vg;
    var xg:byte_ptr = tg + wg;
    xg[0] = sg;
    var yg:int = e[7]:int;
    var zg:int = e[3]:int;
    var ah:int = 3;
    var bh:int = zg + ah;
    var ch:ubyte_ptr = yg + bh;
    var dh:int = ch[0];
    var eh:int = 255;
    var fh:int = dh & eh;
    var gh:int = e[11]:ubyte;
    var hh:int = 255;
    var ih:int = gh & hh;
    var jh:int = fh ^ ih;
    var kh:int = e[7]:int;
    var lh:int = e[4]:int;
    var mh:int = 3;
    var nh:int = lh + mh;
    var oh:byte_ptr = kh + nh;
    oh[0] = jh;
    var ph:int = e[5]:int;
    var qh:int = 1;
    var rh:int = ph + qh;
    e[5]:int = rh;
    continue L_d;
  }
  unreachable;
  label B_c:
}

function f_f(a:int, b:int) {
  var c:int = g_a;
  var d:int = 16;
  var e:int_ptr = c - d;
  g_a = e;
  e[3] = a;
  e[2] = b;
  var f:int = e[2];
  var g:int = e[3];
  f_g(f, g);
  var h:int = 16;
  var i:int = e + h;
  g_a = i;
}

function f_g(a:int, b:int) {
  var c:int = g_a;
  var d:int = 16;
  var e:int = c - d;
  g_a = e;
  e[3]:int = a;
  e[2]:int = b;
  var f:int = 0;
  e[7]:byte = f;
  var g:int = e[3]:int;
  var h:int = e[2]:int;
  var i:int = 0;
  var j:int = 255;
  var k:int = i & j;
  f_h(k, g, h);
  var l:int = 1;
  e[7]:byte = l;
  loop L_b {
    var m:int = e[3]:int;
    f_i(m);
    var n:int = e[3]:int;
    f_j(n);
    var o:int = e[7]:ubyte;
    var p:int = 255;
    var q:int = o & p;
    var r:int = 10;
    var s:int = q;
    var t:int = r;
    var u:int = s == t;
    var v:int = 1;
    var w:int = u & v;
    if (eqz(w)) goto B_c;
    goto B_a;
    label B_c:
    var x:int = e[3]:int;
    f_k(x);
    var y:int = e[7]:ubyte;
    var z:int = e[3]:int;
    var aa:int = e[2]:int;
    var ba:int = 255;
    var ca:int = y & ba;
    f_h(ca, z, aa);
    var da:int = e[7]:ubyte;
    var ea:int = 1;
    var fa:int = da + ea;
    e[7]:byte = fa;
    continue L_b;
  }
  unreachable;
  label B_a:
  var ga:int = e[3]:int;
  var ha:int = e[2]:int;
  var ia:int = 10;
  var ja:int = 255;
  var ka:int = ia & ja;
  f_h(ka, ga, ha);
  var la:int = 16;
  var ma:int = e + la;
  g_a = ma;
}

function f_h(a:int, b:int, c:int) {
  var d:int = g_a;
  var e:int = 16;
  var f:int = d - e;
  f[15]:byte = a;
  f[2]:int = b;
  f[1]:int = c;
  var g:int = 0;
  f[3]:byte = g;
  loop L_b {
    var h:int = f[3]:ubyte;
    var i:int = 255;
    var j:int = h & i;
    var k:int = 4;
    var l:int = j;
    var m:int = k;
    var n:int = l < m;
    var o:int = 1;
    var p:int = n & o;
    if (eqz(p)) goto B_a;
    var q:int = 0;
    f[2]:byte = q;
    loop L_d {
      var r:int = f[2]:ubyte;
      var s:int = 255;
      var t:int = r & s;
      var u:int = 4;
      var v:int = t;
      var w:int = u;
      var x:int = v < w;
      var y:int = 1;
      var z:int = x & y;
      if (eqz(z)) goto B_c;
      var aa:int = f[1]:int;
      var ba:int = f[15]:ubyte;
      var ca:int = 255;
      var da:int = ba & ca;
      var ea:int = 2;
      var fa:int = da << ea;
      var ga:int = 2;
      var ha:int = fa << ga;
      var ia:int = f[3]:ubyte;
      var ja:int = 255;
      var ka:int = ia & ja;
      var la:int = 2;
      var ma:int = ka << la;
      var na:int = ha + ma;
      var oa:int = f[2]:ubyte;
      var pa:int = 255;
      var qa:int = oa & pa;
      var ra:int = na + qa;
      var sa:ubyte_ptr = aa + ra;
      var ta:int = sa[0];
      var ua:int = 255;
      var va:int = ta & ua;
      var wa:int = f[2]:int;
      var xa:int = f[3]:ubyte;
      var ya:int = 255;
      var za:int = xa & ya;
      var ab:int = 2;
      var bb:int = za << ab;
      var cb:int = wa + bb;
      var db:int = f[2]:ubyte;
      var eb:int = 255;
      var fb:int = db & eb;
      var gb:int = cb + fb;
      var hb:int = gb[0]:ubyte;
      var ib:int = 255;
      var jb:int = hb & ib;
      var kb:int = jb ^ va;
      gb[0]:byte = kb;
      var lb:int = f[2]:ubyte;
      var mb:int = 1;
      var nb:int = lb + mb;
      f[2]:byte = nb;
      continue L_d;
    }
    unreachable;
    label B_c:
    var ob:int = f[3]:ubyte;
    var pb:int = 1;
    var qb:int = ob + pb;
    f[3]:byte = qb;
    continue L_b;
  }
  unreachable;
  label B_a:
}

function f_i(a:int) {
  var b:int = g_a;
  var c:int = 16;
  var d:int = b - c;
  d[3]:int = a;
  var e:int = 0;
  d[11]:byte = e;
  loop L_b {
    var f:int = d[11]:ubyte;
    var g:int = 255;
    var h:int = f & g;
    var i:int = 4;
    var j:int = h;
    var k:int = i;
    var l:int = j < k;
    var m:int = 1;
    var n:int = l & m;
    if (eqz(n)) goto B_a;
    var o:int = 0;
    d[10]:byte = o;
    loop L_d {
      var p:int = d[10]:ubyte;
      var q:int = 255;
      var r:int = p & q;
      var s:int = 4;
      var t:int = r;
      var u:int = s;
      var v:int = t < u;
      var w:int = 1;
      var x:int = v & w;
      if (eqz(x)) goto B_c;
      var y:int = d[3]:int;
      var z:int = d[10]:ubyte;
      var aa:int = 255;
      var ba:int = z & aa;
      var ca:int = 2;
      var da:int = ba << ca;
      var ea:int = y + da;
      var fa:int = d[11]:ubyte;
      var ga:int = 255;
      var ha:int = fa & ga;
      var ia:ubyte_ptr = ea + ha;
      var ja:int = ia[0];
      var ka:int = 255;
      var la:ubyte_ptr = ja & ka;
      var ma:int = la[1056];
      var na:int = d[3]:int;
      var oa:int = d[10]:ubyte;
      var pa:int = 255;
      var qa:int = oa & pa;
      var ra:int = 2;
      var sa:int = qa << ra;
      var ta:int = na + sa;
      var ua:int = d[11]:ubyte;
      var va:int = 255;
      var wa:int = ua & va;
      var xa:byte_ptr = ta + wa;
      xa[0] = ma;
      var ya:int = d[10]:ubyte;
      var za:int = 1;
      var ab:int = ya + za;
      d[10]:byte = ab;
      continue L_d;
    }
    unreachable;
    label B_c:
    var bb:int = d[11]:ubyte;
    var cb:int = 1;
    var db:int = bb + cb;
    d[11]:byte = db;
    continue L_b;
  }
  unreachable;
  label B_a:
}

function f_j(a:int) {
  var b:int = g_a;
  var c:int = 16;
  var d:int = b - c;
  d[3]:int = a;
  var e:ubyte_ptr = d[3]:int;
  var f:int = e[1];
  d[11]:byte = f;
  var g:ubyte_ptr = d[3]:int;
  var h:int = g[5];
  var i:byte_ptr = d[3]:int;
  i[1] = h;
  var j:ubyte_ptr = d[3]:int;
  var k:int = j[9];
  var l:byte_ptr = d[3]:int;
  l[5] = k;
  var m:ubyte_ptr = d[3]:int;
  var n:int = m[13];
  var o:byte_ptr = d[3]:int;
  o[9] = n;
  var p:int = d[11]:ubyte;
  var q:byte_ptr = d[3]:int;
  q[13] = p;
  var r:ubyte_ptr = d[3]:int;
  var s:int = r[2];
  d[11]:byte = s;
  var t:ubyte_ptr = d[3]:int;
  var u:int = t[10];
  var v:byte_ptr = d[3]:int;
  v[2] = u;
  var w:int = d[11]:ubyte;
  var x:byte_ptr = d[3]:int;
  x[10] = w;
  var y:ubyte_ptr = d[3]:int;
  var z:int = y[6];
  d[11]:byte = z;
  var aa:ubyte_ptr = d[3]:int;
  var ba:int = aa[14];
  var ca:byte_ptr = d[3]:int;
  ca[6] = ba;
  var da:int = d[11]:ubyte;
  var ea:byte_ptr = d[3]:int;
  ea[14] = da;
  var fa:ubyte_ptr = d[3]:int;
  var ga:int = fa[3];
  d[11]:byte = ga;
  var ha:ubyte_ptr = d[3]:int;
  var ia:int = ha[15];
  var ja:byte_ptr = d[3]:int;
  ja[3] = ia;
  var ka:ubyte_ptr = d[3]:int;
  var la:int = ka[11];
  var ma:byte_ptr = d[3]:int;
  ma[15] = la;
  var na:ubyte_ptr = d[3]:int;
  var oa:int = na[7];
  var pa:byte_ptr = d[3]:int;
  pa[11] = oa;
  var qa:int = d[11]:ubyte;
  var ra:byte_ptr = d[3]:int;
  ra[7] = qa;
}

function f_k(a:int) {
  var b:int = g_a;
  var c:int = 16;
  var d:int = b - c;
  g_a = d;
  d[3]:int = a;
  var e:int = 0;
  d[11]:byte = e;
  loop L_b {
    var f:int = d[11]:ubyte;
    var g:int = 255;
    var h:int = f & g;
    var i:int = 4;
    var j:int = h;
    var k:int = i;
    var l:int = j < k;
    var m:int = 1;
    var n:int = l & m;
    if (eqz(n)) goto B_a;
    var o:int = d[3]:int;
    var p:int = d[11]:ubyte;
    var q:int = 255;
    var r:int = p & q;
    var s:int = 2;
    var t:int = r << s;
    var u:ubyte_ptr = o + t;
    var v:int = u[0];
    d[8]:byte = v;
    var w:int = d[3]:int;
    var x:int = d[11]:ubyte;
    var y:int = 255;
    var z:int = x & y;
    var aa:int = 2;
    var ba:int = z << aa;
    var ca:ubyte_ptr = w + ba;
    var da:int = ca[0];
    var ea:int = 255;
    var fa:int = da & ea;
    var ga:int = d[3]:int;
    var ha:int = d[11]:ubyte;
    var ia:int = 255;
    var ja:int = ha & ia;
    var ka:int = 2;
    var la:int = ja << ka;
    var ma:ubyte_ptr = ga + la;
    var na:int = ma[1];
    var oa:int = 255;
    var pa:int = na & oa;
    var qa:int = fa ^ pa;
    var ra:int = d[3]:int;
    var sa:int = d[11]:ubyte;
    var ta:int = 255;
    var ua:int = sa & ta;
    var va:int = 2;
    var wa:int = ua << va;
    var xa:ubyte_ptr = ra + wa;
    var ya:int = xa[2];
    var za:int = 255;
    var ab:int = ya & za;
    var bb:int = qa ^ ab;
    var cb:int = d[3]:int;
    var db:int = d[11]:ubyte;
    var eb:int = 255;
    var fb:int = db & eb;
    var gb:int = 2;
    var hb:int = fb << gb;
    var ib:ubyte_ptr = cb + hb;
    var jb:int = ib[3];
    var kb:int = 255;
    var lb:int = jb & kb;
    var mb:int = bb ^ lb;
    d[10]:byte = mb;
    var nb:int = d[3]:int;
    var ob:int = d[11]:ubyte;
    var pb:int = 255;
    var qb:int = ob & pb;
    var rb:int = 2;
    var sb:int = qb << rb;
    var tb:ubyte_ptr = nb + sb;
    var ub:int = tb[0];
    var vb:int = 255;
    var wb:int = ub & vb;
    var xb:int = d[3]:int;
    var yb:int = d[11]:ubyte;
    var zb:int = 255;
    var ac:int = yb & zb;
    var bc:int = 2;
    var cc:int = ac << bc;
    var dc:ubyte_ptr = xb + cc;
    var ec:int = dc[1];
    var fc:int = 255;
    var gc:int = ec & fc;
    var hc:int = wb ^ gc;
    d[9]:byte = hc;
    var ic:int = d[9]:ubyte;
    var jc:int = 255;
    var kc:int = ic & jc;
    var lc:int = f_x(kc);
    d[9]:byte = lc;
    var mc:int = d[9]:ubyte;
    var nc:int = 255;
    var oc:int = mc & nc;
    var pc:int = d[10]:ubyte;
    var qc:int = 255;
    var rc:int = pc & qc;
    var sc:int = oc ^ rc;
    var tc:int = d[3]:int;
    var uc:int = d[11]:ubyte;
    var vc:int = 255;
    var wc:int = uc & vc;
    var xc:int = 2;
    var yc:int = wc << xc;
    var zc:int = tc + yc;
    var ad:int = zc[0]:ubyte;
    var bd:int = 255;
    var cd:int = ad & bd;
    var dd:int = cd ^ sc;
    zc[0]:byte = dd;
    var ed:int = d[3]:int;
    var fd:int = d[11]:ubyte;
    var gd:int = 255;
    var hd:int = fd & gd;
    var id:int = 2;
    var jd:int = hd << id;
    var kd:ubyte_ptr = ed + jd;
    var ld:int = kd[1];
    var md:int = 255;
    var nd:int = ld & md;
    var od:int = d[3]:int;
    var pd:int = d[11]:ubyte;
    var qd:int = 255;
    var rd:int = pd & qd;
    var sd:int = 2;
    var td:int = rd << sd;
    var ud:ubyte_ptr = od + td;
    var vd:int = ud[2];
    var wd:int = 255;
    var xd:int = vd & wd;
    var yd:int = nd ^ xd;
    d[9]:byte = yd;
    var zd:int = d[9]:ubyte;
    var ae:int = 255;
    var be:int = zd & ae;
    var ce:int = f_x(be);
    d[9]:byte = ce;
    var de:int = d[9]:ubyte;
    var ee:int = 255;
    var fe:int = de & ee;
    var ge:int = d[10]:ubyte;
    var he:int = 255;
    var ie:int = ge & he;
    var je:int = fe ^ ie;
    var ke:int = d[3]:int;
    var le:int = d[11]:ubyte;
    var me:int = 255;
    var ne:int = le & me;
    var oe:int = 2;
    var pe:int = ne << oe;
    var qe:int = ke + pe;
    var re:int = qe[1]:ubyte;
    var se:int = 255;
    var te:int = re & se;
    var ue:int = te ^ je;
    qe[1]:byte = ue;
    var ve:int = d[3]:int;
    var we:int = d[11]:ubyte;
    var xe:int = 255;
    var ye:int = we & xe;
    var ze:int = 2;
    var af:int = ye << ze;
    var bf:ubyte_ptr = ve + af;
    var cf:int = bf[2];
    var df:int = 255;
    var ef:int = cf & df;
    var ff:int = d[3]:int;
    var gf:int = d[11]:ubyte;
    var hf:int = 255;
    var if:int = gf & hf;
    var jf:int = 2;
    var kf:int = if << jf;
    var lf:ubyte_ptr = ff + kf;
    var mf:int = lf[3];
    var nf:int = 255;
    var of:int = mf & nf;
    var pf:int = ef ^ of;
    d[9]:byte = pf;
    var qf:int = d[9]:ubyte;
    var rf:int = 255;
    var sf:int = qf & rf;
    var tf:int = f_x(sf);
    d[9]:byte = tf;
    var uf:int = d[9]:ubyte;
    var vf:int = 255;
    var wf:int = uf & vf;
    var xf:int = d[10]:ubyte;
    var yf:int = 255;
    var zf:int = xf & yf;
    var ag:int = wf ^ zf;
    var bg:int = d[3]:int;
    var cg:int = d[11]:ubyte;
    var dg:int = 255;
    var eg:int = cg & dg;
    var fg:int = 2;
    var gg:int = eg << fg;
    var hg:int = bg + gg;
    var ig:int = hg[2]:ubyte;
    var jg:int = 255;
    var kg:int = ig & jg;
    var lg:int = kg ^ ag;
    hg[2]:byte = lg;
    var mg:int = d[3]:int;
    var ng:int = d[11]:ubyte;
    var og:int = 255;
    var pg:int = ng & og;
    var qg:int = 2;
    var rg:int = pg << qg;
    var sg:ubyte_ptr = mg + rg;
    var tg:int = sg[3];
    var ug:int = 255;
    var vg:int = tg & ug;
    var wg:int = d[8]:ubyte;
    var xg:int = 255;
    var yg:int = wg & xg;
    var zg:int = vg ^ yg;
    d[9]:byte = zg;
    var ah:int = d[9]:ubyte;
    var bh:int = 255;
    var ch:int = ah & bh;
    var dh:int = f_x(ch);
    d[9]:byte = dh;
    var eh:int = d[9]:ubyte;
    var fh:int = 255;
    var gh:int = eh & fh;
    var hh:int = d[10]:ubyte;
    var ih:int = 255;
    var jh:int = hh & ih;
    var kh:int = gh ^ jh;
    var lh:int = d[3]:int;
    var mh:int = d[11]:ubyte;
    var nh:int = 255;
    var oh:int = mh & nh;
    var ph:int = 2;
    var qh:int = oh << ph;
    var rh:int = lh + qh;
    var sh:int = rh[3]:ubyte;
    var th:int = 255;
    var uh:int = sh & th;
    var vh:int = uh ^ kh;
    rh[3]:byte = vh;
    var wh:int = d[11]:ubyte;
    var xh:int = 1;
    var yh:int = wh + xh;
    d[11]:byte = yh;
    continue L_b;
  }
  unreachable;
  label B_a:
  var zh:int = 16;
  var ai:int = d + zh;
  g_a = ai;
}

function f_l(a:int, b:int) {
  var c:int = g_a;
  var d:int = 16;
  var e:int_ptr = c - d;
  g_a = e;
  e[3] = a;
  e[2] = b;
  var f:int = e[2];
  var g:int = e[3];
  f_m(f, g);
  var h:int = 16;
  var i:int = e + h;
  g_a = i;
}

function f_m(a:int, b:int) {
  var c:int = g_a;
  var d:int = 16;
  var e:int = c - d;
  g_a = e;
  e[3]:int = a;
  e[2]:int = b;
  var f:int = 0;
  e[7]:byte = f;
  var g:int = e[3]:int;
  var h:int = e[2]:int;
  var i:int = 10;
  var j:int = 255;
  var k:int = i & j;
  f_h(k, g, h);
  var l:int = 9;
  e[7]:byte = l;
  loop L_b {
    var m:int = e[3]:int;
    f_n(m);
    var n:int = e[3]:int;
    f_o(n);
    var o:int = e[7]:ubyte;
    var p:int = e[3]:int;
    var q:int = e[2]:int;
    var r:int = 255;
    var s:int = o & r;
    f_h(s, p, q);
    var t:int = e[7]:ubyte;
    var u:int = 255;
    var v:int = t & u;
    if (v) goto B_c;
    goto B_a;
    label B_c:
    var w:int = e[3]:int;
    f_p(w);
    var x:int = e[7]:ubyte;
    var y:int = -1;
    var z:int = x + y;
    e[7]:byte = z;
    continue L_b;
  }
  unreachable;
  label B_a:
  var aa:int = 16;
  var ba:int = e + aa;
  g_a = ba;
}

function f_n(a:int) {
  var b:int = g_a;
  var c:int = 16;
  var d:int = b - c;
  d[3]:int = a;
  var e:ubyte_ptr = d[3]:int;
  var f:int = e[13];
  d[11]:byte = f;
  var g:ubyte_ptr = d[3]:int;
  var h:int = g[9];
  var i:byte_ptr = d[3]:int;
  i[13] = h;
  var j:ubyte_ptr = d[3]:int;
  var k:int = j[5];
  var l:byte_ptr = d[3]:int;
  l[9] = k;
  var m:ubyte_ptr = d[3]:int;
  var n:int = m[1];
  var o:byte_ptr = d[3]:int;
  o[5] = n;
  var p:int = d[11]:ubyte;
  var q:byte_ptr = d[3]:int;
  q[1] = p;
  var r:ubyte_ptr = d[3]:int;
  var s:int = r[2];
  d[11]:byte = s;
  var t:ubyte_ptr = d[3]:int;
  var u:int = t[10];
  var v:byte_ptr = d[3]:int;
  v[2] = u;
  var w:int = d[11]:ubyte;
  var x:byte_ptr = d[3]:int;
  x[10] = w;
  var y:ubyte_ptr = d[3]:int;
  var z:int = y[6];
  d[11]:byte = z;
  var aa:ubyte_ptr = d[3]:int;
  var ba:int = aa[14];
  var ca:byte_ptr = d[3]:int;
  ca[6] = ba;
  var da:int = d[11]:ubyte;
  var ea:byte_ptr = d[3]:int;
  ea[14] = da;
  var fa:ubyte_ptr = d[3]:int;
  var ga:int = fa[3];
  d[11]:byte = ga;
  var ha:ubyte_ptr = d[3]:int;
  var ia:int = ha[7];
  var ja:byte_ptr = d[3]:int;
  ja[3] = ia;
  var ka:ubyte_ptr = d[3]:int;
  var la:int = ka[11];
  var ma:byte_ptr = d[3]:int;
  ma[7] = la;
  var na:ubyte_ptr = d[3]:int;
  var oa:int = na[15];
  var pa:byte_ptr = d[3]:int;
  pa[11] = oa;
  var qa:int = d[11]:ubyte;
  var ra:byte_ptr = d[3]:int;
  ra[15] = qa;
}

function f_o(a:int) {
  var b:int = g_a;
  var c:int = 16;
  var d:int = b - c;
  d[3]:int = a;
  var e:int = 0;
  d[11]:byte = e;
  loop L_b {
    var f:int = d[11]:ubyte;
    var g:int = 255;
    var h:int = f & g;
    var i:int = 4;
    var j:int = h;
    var k:int = i;
    var l:int = j < k;
    var m:int = 1;
    var n:int = l & m;
    if (eqz(n)) goto B_a;
    var o:int = 0;
    d[10]:byte = o;
    loop L_d {
      var p:int = d[10]:ubyte;
      var q:int = 255;
      var r:int = p & q;
      var s:int = 4;
      var t:int = r;
      var u:int = s;
      var v:int = t < u;
      var w:int = 1;
      var x:int = v & w;
      if (eqz(x)) goto B_c;
      var y:int = d[3]:int;
      var z:int = d[10]:ubyte;
      var aa:int = 255;
      var ba:int = z & aa;
      var ca:int = 2;
      var da:int = ba << ca;
      var ea:int = y + da;
      var fa:int = d[11]:ubyte;
      var ga:int = 255;
      var ha:int = fa & ga;
      var ia:ubyte_ptr = ea + ha;
      var ja:int = ia[0];
      var ka:int = 255;
      var la:ubyte_ptr = ja & ka;
      var ma:int = la[1328];
      var na:int = d[3]:int;
      var oa:int = d[10]:ubyte;
      var pa:int = 255;
      var qa:int = oa & pa;
      var ra:int = 2;
      var sa:int = qa << ra;
      var ta:int = na + sa;
      var ua:int = d[11]:ubyte;
      var va:int = 255;
      var wa:int = ua & va;
      var xa:byte_ptr = ta + wa;
      xa[0] = ma;
      var ya:int = d[10]:ubyte;
      var za:int = 1;
      var ab:int = ya + za;
      d[10]:byte = ab;
      continue L_d;
    }
    unreachable;
    label B_c:
    var bb:int = d[11]:ubyte;
    var cb:int = 1;
    var db:int = bb + cb;
    d[11]:byte = db;
    continue L_b;
  }
  unreachable;
  label B_a:
}

function f_p(a:int) {
  var b:int = g_a;
  var c:int = 16;
  var d:int = b - c;
  g_a = d;
  d[3]:int = a;
  var e:int = 0;
  d[2]:int = e;
  loop L_b {
    var f:int = d[2]:int;
    var g:int = 4;
    var h:int = f;
    var i:int = g;
    var j:int = h < i;
    var k:int = 1;
    var l:int = j & k;
    if (eqz(l)) goto B_a;
    var m:int = d[3]:int;
    var n:int = d[2]:int;
    var o:int = 2;
    var p:int = n << o;
    var q:ubyte_ptr = m + p;
    var r:int = q[0];
    d[7]:byte = r;
    var s:int = d[3]:int;
    var t:int = d[2]:int;
    var u:int = 2;
    var v:int = t << u;
    var w:ubyte_ptr = s + v;
    var x:int = w[1];
    d[6]:byte = x;
    var y:int = d[3]:int;
    var z:int = d[2]:int;
    var aa:int = 2;
    var ba:int = z << aa;
    var ca:ubyte_ptr = y + ba;
    var da:int = ca[2];
    d[5]:byte = da;
    var ea:int = d[3]:int;
    var fa:int = d[2]:int;
    var ga:int = 2;
    var ha:int = fa << ga;
    var ia:ubyte_ptr = ea + ha;
    var ja:int = ia[3];
    d[4]:byte = ja;
    var ka:int = d[7]:ubyte;
    var la:int = 255;
    var ma:int = ka & la;
    var na:int = 0;
    var oa:int = ma * na;
    var pa:int = d[7]:ubyte;
    var qa:int = 255;
    var ra:int = pa & qa;
    var sa:int = f_x(ra);
    var ta:int = 255;
    var ua:int = sa & ta;
    var va:int = 0;
    var wa:int = ua << va;
    var xa:int = oa ^ wa;
    var ya:int = d[7]:ubyte;
    var za:int = 255;
    var ab:int = ya & za;
    var bb:int = f_x(ab);
    var cb:int = 255;
    var db:int = bb & cb;
    var eb:int = f_x(db);
    var fb:int = 255;
    var gb:int = eb & fb;
    var hb:int = 0;
    var ib:int = gb << hb;
    var jb:int = xa ^ ib;
    var kb:int = d[7]:ubyte;
    var lb:int = 255;
    var mb:int = kb & lb;
    var nb:int = f_x(mb);
    var ob:int = 255;
    var pb:int = nb & ob;
    var qb:int = f_x(pb);
    var rb:int = 255;
    var sb:int = qb & rb;
    var tb:int = f_x(sb);
    var ub:int = 255;
    var vb:int = tb & ub;
    var wb:int = 0;
    var xb:int = vb << wb;
    var yb:int = jb ^ xb;
    var zb:int = d[7]:ubyte;
    var ac:int = 255;
    var bc:int = zb & ac;
    var cc:int = f_x(bc);
    var dc:int = 255;
    var ec:int = cc & dc;
    var fc:int = f_x(ec);
    var gc:int = 255;
    var hc:int = fc & gc;
    var ic:int = f_x(hc);
    var jc:int = 255;
    var kc:int = ic & jc;
    var lc:int = f_x(kc);
    var mc:int = 255;
    var nc:int = lc & mc;
    var oc:int = 0;
    var pc:int = nc * oc;
    var qc:int = yb ^ pc;
    var rc:int = d[6]:ubyte;
    var sc:int = 255;
    var tc:int = rc & sc;
    var uc:int = 0;
    var vc:int = tc << uc;
    var wc:int = d[6]:ubyte;
    var xc:int = 255;
    var yc:int = wc & xc;
    var zc:int = f_x(yc);
    var ad:int = 255;
    var bd:int = zc & ad;
    var cd:int = 0;
    var dd:int = bd << cd;
    var ed:int = vc ^ dd;
    var fd:int = d[6]:ubyte;
    var gd:int = 255;
    var hd:int = fd & gd;
    var id:int = f_x(hd);
    var jd:int = 255;
    var kd:int = id & jd;
    var ld:int = f_x(kd);
    var md:int = 255;
    var nd:int = ld & md;
    var od:int = 0;
    var pd:int = nd * od;
    var qd:int = ed ^ pd;
    var rd:int = d[6]:ubyte;
    var sd:int = 255;
    var td:int = rd & sd;
    var ud:int = f_x(td);
    var vd:int = 255;
    var wd:int = ud & vd;
    var xd:int = f_x(wd);
    var yd:int = 255;
    var zd:int = xd & yd;
    var ae:int = f_x(zd);
    var be:int = 255;
    var ce:int = ae & be;
    var de:int = 0;
    var ee:int = ce << de;
    var fe:int = qd ^ ee;
    var ge:int = d[6]:ubyte;
    var he:int = 255;
    var ie:int = ge & he;
    var je:int = f_x(ie);
    var ke:int = 255;
    var le:int = je & ke;
    var me:int = f_x(le);
    var ne:int = 255;
    var oe:int = me & ne;
    var pe:int = f_x(oe);
    var qe:int = 255;
    var re:int = pe & qe;
    var se:int = f_x(re);
    var te:int = 255;
    var ue:int = se & te;
    var ve:int = 0;
    var we:int = ue * ve;
    var xe:int = fe ^ we;
    var ye:int = qc ^ xe;
    var ze:int = d[5]:ubyte;
    var af:int = 255;
    var bf:int = ze & af;
    var cf:int = 0;
    var df:int = bf << cf;
    var ef:int = d[5]:ubyte;
    var ff:int = 255;
    var gf:int = ef & ff;
    var hf:int = f_x(gf);
    var if:int = 255;
    var jf:int = hf & if;
    var kf:int = 0;
    var lf:int = jf * kf;
    var mf:int = df ^ lf;
    var nf:int = d[5]:ubyte;
    var of:int = 255;
    var pf:int = nf & of;
    var qf:int = f_x(pf);
    var rf:int = 255;
    var sf:int = qf & rf;
    var tf:int = f_x(sf);
    var uf:int = 255;
    var vf:int = tf & uf;
    var wf:int = 0;
    var xf:int = vf << wf;
    var yf:int = mf ^ xf;
    var zf:int = d[5]:ubyte;
    var ag:int = 255;
    var bg:int = zf & ag;
    var cg:int = f_x(bg);
    var dg:int = 255;
    var eg:int = cg & dg;
    var fg:int = f_x(eg);
    var gg:int = 255;
    var hg:int = fg & gg;
    var ig:int = f_x(hg);
    var jg:int = 255;
    var kg:int = ig & jg;
    var lg:int = 0;
    var mg:int = kg << lg;
    var ng:int = yf ^ mg;
    var og:int = d[5]:ubyte;
    var pg:int = 255;
    var qg:int = og & pg;
    var rg:int = f_x(qg);
    var sg:int = 255;
    var tg:int = rg & sg;
    var ug:int = f_x(tg);
    var vg:int = 255;
    var wg:int = ug & vg;
    var xg:int = f_x(wg);
    var yg:int = 255;
    var zg:int = xg & yg;
    var ah:int = f_x(zg);
    var bh:int = 255;
    var ch:int = ah & bh;
    var dh:int = 0;
    var eh:int = ch * dh;
    var fh:int = ng ^ eh;
    var gh:int = ye ^ fh;
    var hh:int = d[4]:ubyte;
    var ih:int = 255;
    var jh:int = hh & ih;
    var kh:int = 0;
    var lh:int = jh << kh;
    var mh:int = d[4]:ubyte;
    var nh:int = 255;
    var oh:int = mh & nh;
    var ph:int = f_x(oh);
    var qh:int = 255;
    var rh:int = ph & qh;
    var sh:int = 0;
    var th:int = rh * sh;
    var uh:int = lh ^ th;
    var vh:int = d[4]:ubyte;
    var wh:int = 255;
    var xh:int = vh & wh;
    var yh:int = f_x(xh);
    var zh:int = 255;
    var ai:int = yh & zh;
    var bi:int = f_x(ai);
    var ci:int = 255;
    var di:int = bi & ci;
    var ei:int = 0;
    var fi:int = di * ei;
    var gi:int = uh ^ fi;
    var hi:int = d[4]:ubyte;
    var ii:int = 255;
    var ji:int = hi & ii;
    var ki:int = f_x(ji);
    var li:int = 255;
    var mi:int = ki & li;
    var ni:int = f_x(mi);
    var oi:int = 255;
    var pi:int = ni & oi;
    var qi:int = f_x(pi);
    var ri:int = 255;
    var si:int = qi & ri;
    var ti:int = 0;
    var ui:int = si << ti;
    var vi:int = gi ^ ui;
    var wi:int = d[4]:ubyte;
    var xi:int = 255;
    var yi:int = wi & xi;
    var zi:int = f_x(yi);
    var aj:int = 255;
    var bj:int = zi & aj;
    var cj:int = f_x(bj);
    var dj:int = 255;
    var ej:int = cj & dj;
    var fj:int = f_x(ej);
    var gj:int = 255;
    var hj:int = fj & gj;
    var ij:int = f_x(hj);
    var jj:int = 255;
    var kj:int = ij & jj;
    var lj:int = 0;
    var mj:int = kj * lj;
    var nj:int = vi ^ mj;
    var oj:int = gh ^ nj;
    var pj:int = d[3]:int;
    var qj:int = d[2]:int;
    var rj:int = 2;
    var sj:int = qj << rj;
    var tj:byte_ptr = pj + sj;
    tj[0] = oj;
    var uj:int = d[7]:ubyte;
    var vj:int = 255;
    var wj:int = uj & vj;
    var xj:int = 0;
    var yj:int = wj << xj;
    var zj:int = d[7]:ubyte;
    var ak:int = 255;
    var bk:int = zj & ak;
    var ck:int = f_x(bk);
    var dk:int = 255;
    var ek:int = ck & dk;
    var fk:int = 0;
    var gk:int = ek * fk;
    var hk:int = yj ^ gk;
    var ik:int = d[7]:ubyte;
    var jk:int = 255;
    var kk:int = ik & jk;
    var lk:int = f_x(kk);
    var mk:int = 255;
    var nk:int = lk & mk;
    var ok:int = f_x(nk);
    var pk:int = 255;
    var qk:int = ok & pk;
    var rk:int = 0;
    var sk:int = qk * rk;
    var tk:int = hk ^ sk;
    var uk:int = d[7]:ubyte;
    var vk:int = 255;
    var wk:int = uk & vk;
    var xk:int = f_x(wk);
    var yk:int = 255;
    var zk:int = xk & yk;
    var al:int = f_x(zk);
    var bl:int = 255;
    var cl:int = al & bl;
    var dl:int = f_x(cl);
    var el:int = 255;
    var fl:int = dl & el;
    var gl:int = 0;
    var hl:int = fl << gl;
    var il:int = tk ^ hl;
    var jl:int = d[7]:ubyte;
    var kl:int = 255;
    var ll:int = jl & kl;
    var ml:int = f_x(ll);
    var nl:int = 255;
    var ol:int = ml & nl;
    var pl:int = f_x(ol);
    var ql:int = 255;
    var rl:int = pl & ql;
    var sl:int = f_x(rl);
    var tl:int = 255;
    var ul:int = sl & tl;
    var vl:int = f_x(ul);
    var wl:int = 255;
    var xl:int = vl & wl;
    var yl:int = 0;
    var zl:int = xl * yl;
    var am:int = il ^ zl;
    var bm:int = d[6]:ubyte;
    var cm:int = 255;
    var dm:int = bm & cm;
    var em:int = 0;
    var fm:int = dm * em;
    var gm:int = d[6]:ubyte;
    var hm:int = 255;
    var im:int = gm & hm;
    var jm:int = f_x(im);
    var km:int = 255;
    var lm:int = jm & km;
    var mm:int = 0;
    var nm:int = lm << mm;
    var om:int = fm ^ nm;
    var pm:int = d[6]:ubyte;
    var qm:int = 255;
    var rm:int = pm & qm;
    var sm:int = f_x(rm);
    var tm:int = 255;
    var um:int = sm & tm;
    var vm:int = f_x(um);
    var wm:int = 255;
    var xm:int = vm & wm;
    var ym:int = 0;
    var zm:int = xm << ym;
    var an:int = om ^ zm;
    var bn:int = d[6]:ubyte;
    var cn:int = 255;
    var dn:int = bn & cn;
    var en:int = f_x(dn);
    var fn:int = 255;
    var gn:int = en & fn;
    var hn:int = f_x(gn);
    var in:int = 255;
    var jn:int = hn & in;
    var kn:int = f_x(jn);
    var ln:int = 255;
    var mn:int = kn & ln;
    var nn:int = 0;
    var on:int = mn << nn;
    var pn:int = an ^ on;
    var qn:int = d[6]:ubyte;
    var rn:int = 255;
    var sn:int = qn & rn;
    var tn:int = f_x(sn);
    var un:int = 255;
    var vn:int = tn & un;
    var wn:int = f_x(vn);
    var xn:int = 255;
    var yn:int = wn & xn;
    var zn:int = f_x(yn);
    var ao:int = 255;
    var bo:int = zn & ao;
    var co:int = f_x(bo);
    var do:int = 255;
    var eo:int = co & do;
    var fo:int = 0;
    var go:int = eo * fo;
    var ho:int = pn ^ go;
    var io:int = am ^ ho;
    var jo:int = d[5]:ubyte;
    var ko:int = 255;
    var lo:int = jo & ko;
    var mo:int = 0;
    var no:int = lo << mo;
    var oo:int = d[5]:ubyte;
    var po:int = 255;
    var qo:int = oo & po;
    var ro:int = f_x(qo);
    var so:int = 255;
    var to:int = ro & so;
    var uo:int = 0;
    var vo:int = to << uo;
    var wo:int = no ^ vo;
    var xo:int = d[5]:ubyte;
    var yo:int = 255;
    var zo:int = xo & yo;
    var ap:int = f_x(zo);
    var bp:int = 255;
    var cp:int = ap & bp;
    var dp:int = f_x(cp);
    var ep:int = 255;
    var fp:int = dp & ep;
    var gp:int = 0;
    var hp:int = fp * gp;
    var ip:int = wo ^ hp;
    var jp:int = d[5]:ubyte;
    var kp:int = 255;
    var lp:int = jp & kp;
    var mp:int = f_x(lp);
    var np:int = 255;
    var op:int = mp & np;
    var pp:int = f_x(op);
    var qp:int = 255;
    var rp:int = pp & qp;
    var sp:int = f_x(rp);
    var tp:int = 255;
    var up:int = sp & tp;
    var vp:int = 0;
    var wp:int = up << vp;
    var xp:int = ip ^ wp;
    var yp:int = d[5]:ubyte;
    var zp:int = 255;
    var aq:int = yp & zp;
    var bq:int = f_x(aq);
    var cq:int = 255;
    var dq:int = bq & cq;
    var eq:int = f_x(dq);
    var fq:int = 255;
    var gq:int = eq & fq;
    var hq:int = f_x(gq);
    var iq:int = 255;
    var jq:int = hq & iq;
    var kq:int = f_x(jq);
    var lq:int = 255;
    var mq:int = kq & lq;
    var nq:int = 0;
    var oq:int = mq * nq;
    var pq:int = xp ^ oq;
    var qq:int = io ^ pq;
    var rq:int = d[4]:ubyte;
    var sq:int = 255;
    var tq:int = rq & sq;
    var uq:int = 0;
    var vq:int = tq << uq;
    var wq:int = d[4]:ubyte;
    var xq:int = 255;
    var yq:int = wq & xq;
    var zq:int = f_x(yq);
    var ar:int = 255;
    var br:int = zq & ar;
    var cr:int = 0;
    var dr:int = br * cr;
    var er:int = vq ^ dr;
    var fr:int = d[4]:ubyte;
    var gr:int = 255;
    var hr:int = fr & gr;
    var ir:int = f_x(hr);
    var jr:int = 255;
    var kr:int = ir & jr;
    var lr:int = f_x(kr);
    var mr:int = 255;
    var nr:int = lr & mr;
    var or:int = 0;
    var pr:int = nr << or;
    var qr:int = er ^ pr;
    var rr:int = d[4]:ubyte;
    var sr:int = 255;
    var tr:int = rr & sr;
    var ur:int = f_x(tr);
    var vr:int = 255;
    var wr:int = ur & vr;
    var xr:int = f_x(wr);
    var yr:int = 255;
    var zr:int = xr & yr;
    var as:int = f_x(zr);
    var bs:int = 255;
    var cs:int = as & bs;
    var ds:int = 0;
    var es:int = cs << ds;
    var fs:int = qr ^ es;
    var gs:int = d[4]:ubyte;
    var hs:int = 255;
    var is:int = gs & hs;
    var js:int = f_x(is);
    var ks:int = 255;
    var ls:int = js & ks;
    var ms:int = f_x(ls);
    var ns:int = 255;
    var os:int = ms & ns;
    var ps:int = f_x(os);
    var qs:int = 255;
    var rs:int = ps & qs;
    var ss:int = f_x(rs);
    var ts:int = 255;
    var us:int = ss & ts;
    var vs:int = 0;
    var ws:int = us * vs;
    var xs:int = fs ^ ws;
    var ys:int = qq ^ xs;
    var zs:int = d[3]:int;
    var at:int = d[2]:int;
    var bt:int = 2;
    var ct:int = at << bt;
    var dt:byte_ptr = zs + ct;
    dt[1] = ys;
    var et:int = d[7]:ubyte;
    var ft:int = 255;
    var gt:int = et & ft;
    var ht:int = 0;
    var it:int = gt << ht;
    var jt:int = d[7]:ubyte;
    var kt:int = 255;
    var lt:int = jt & kt;
    var mt:int = f_x(lt);
    var nt:int = 255;
    var ot:int = mt & nt;
    var pt:int = 0;
    var qt:int = ot * pt;
    var rt:int = it ^ qt;
    var st:int = d[7]:ubyte;
    var tt:int = 255;
    var ut:int = st & tt;
    var vt:int = f_x(ut);
    var wt:int = 255;
    var xt:int = vt & wt;
    var yt:int = f_x(xt);
    var zt:int = 255;
    var au:int = yt & zt;
    var bu:int = 0;
    var cu:int = au << bu;
    var du:int = rt ^ cu;
    var eu:int = d[7]:ubyte;
    var fu:int = 255;
    var gu:int = eu & fu;
    var hu:int = f_x(gu);
    var iu:int = 255;
    var ju:int = hu & iu;
    var ku:int = f_x(ju);
    var lu:int = 255;
    var mu:int = ku & lu;
    var nu:int = f_x(mu);
    var ou:int = 255;
    var pu:int = nu & ou;
    var qu:int = 0;
    var ru:int = pu << qu;
    var su:int = du ^ ru;
    var tu:int = d[7]:ubyte;
    var uu:int = 255;
    var vu:int = tu & uu;
    var wu:int = f_x(vu);
    var xu:int = 255;
    var yu:int = wu & xu;
    var zu:int = f_x(yu);
    var av:int = 255;
    var bv:int = zu & av;
    var cv:int = f_x(bv);
    var dv:int = 255;
    var ev:int = cv & dv;
    var fv:int = f_x(ev);
    var gv:int = 255;
    var hv:int = fv & gv;
    var iv:int = 0;
    var jv:int = hv * iv;
    var kv:int = su ^ jv;
    var lv:int = d[6]:ubyte;
    var mv:int = 255;
    var nv:int = lv & mv;
    var ov:int = 0;
    var pv:int = nv << ov;
    var qv:int = d[6]:ubyte;
    var rv:int = 255;
    var sv:int = qv & rv;
    var tv:int = f_x(sv);
    var uv:int = 255;
    var vv:int = tv & uv;
    var wv:int = 0;
    var xv:int = vv * wv;
    var yv:int = pv ^ xv;
    var zv:int = d[6]:ubyte;
    var aw:int = 255;
    var bw:int = zv & aw;
    var cw:int = f_x(bw);
    var dw:int = 255;
    var ew:int = cw & dw;
    var fw:int = f_x(ew);
    var gw:int = 255;
    var hw:int = fw & gw;
    var iw:int = 0;
    var jw:int = hw * iw;
    var kw:int = yv ^ jw;
    var lw:int = d[6]:ubyte;
    var mw:int = 255;
    var nw:int = lw & mw;
    var ow:int = f_x(nw);
    var pw:int = 255;
    var qw:int = ow & pw;
    var rw:int = f_x(qw);
    var sw:int = 255;
    var tw:int = rw & sw;
    var uw:int = f_x(tw);
    var vw:int = 255;
    var ww:int = uw & vw;
    var xw:int = 0;
    var yw:int = ww << xw;
    var zw:int = kw ^ yw;
    var ax:int = d[6]:ubyte;
    var bx:int = 255;
    var cx:int = ax & bx;
    var dx:int = f_x(cx);
    var ex:int = 255;
    var fx:int = dx & ex;
    var gx:int = f_x(fx);
    var hx:int = 255;
    var ix:int = gx & hx;
    var jx:int = f_x(ix);
    var kx:int = 255;
    var lx:int = jx & kx;
    var mx:int = f_x(lx);
    var nx:int = 255;
    var ox:int = mx & nx;
    var px:int = 0;
    var qx:int = ox * px;
    var rx:int = zw ^ qx;
    var sx:int = kv ^ rx;
    var tx:int = d[5]:ubyte;
    var ux:int = 255;
    var vx:int = tx & ux;
    var wx:int = 0;
    var xx:int = vx * wx;
    var yx:int = d[5]:ubyte;
    var zx:int = 255;
    var ay:int = yx & zx;
    var by:int = f_x(ay);
    var cy:int = 255;
    var dy:int = by & cy;
    var ey:int = 0;
    var fy:int = dy << ey;
    var gy:int = xx ^ fy;
    var hy:int = d[5]:ubyte;
    var iy:int = 255;
    var jy:int = hy & iy;
    var ky:int = f_x(jy);
    var ly:int = 255;
    var my:int = ky & ly;
    var ny:int = f_x(my);
    var oy:int = 255;
    var py:int = ny & oy;
    var qy:int = 0;
    var ry:int = py << qy;
    var sy:int = gy ^ ry;
    var ty:int = d[5]:ubyte;
    var uy:int = 255;
    var vy:int = ty & uy;
    var wy:int = f_x(vy);
    var xy:int = 255;
    var yy:int = wy & xy;
    var zy:int = f_x(yy);
    var az:int = 255;
    var bz:int = zy & az;
    var cz:int = f_x(bz);
    var dz:int = 255;
    var ez:int = cz & dz;
    var fz:int = 0;
    var gz:int = ez << fz;
    var hz:int = sy ^ gz;
    var iz:int = d[5]:ubyte;
    var jz:int = 255;
    var kz:int = iz & jz;
    var lz:int = f_x(kz);
    var mz:int = 255;
    var nz:int = lz & mz;
    var oz:int = f_x(nz);
    var pz:int = 255;
    var qz:int = oz & pz;
    var rz:int = f_x(qz);
    var sz:int = 255;
    var tz:int = rz & sz;
    var uz:int = f_x(tz);
    var vz:int = 255;
    var wz:int = uz & vz;
    var xz:int = 0;
    var yz:int = wz * xz;
    var zz:int = hz ^ yz;
    var aaa:int = sx ^ zz;
    var baa:int = d[4]:ubyte;
    var caa:int = 255;
    var daa:int = baa & caa;
    var eaa:int = 0;
    var faa:int = daa << eaa;
    var gaa:int = d[4]:ubyte;
    var haa:int = 255;
    var iaa:int = gaa & haa;
    var jaa:int = f_x(iaa);
    var kaa:int = 255;
    var laa:int = jaa & kaa;
    var maa:int = 0;
    var naa:int = laa << maa;
    var oaa:int = faa ^ naa;
    var paa:int = d[4]:ubyte;
    var qaa:int = 255;
    var raa:int = paa & qaa;
    var saa:int = f_x(raa);
    var taa:int = 255;
    var uaa:int = saa & taa;
    var vaa:int = f_x(uaa);
    var waa:int = 255;
    var xaa:int = vaa & waa;
    var yaa:int = 0;
    var zaa:int = xaa * yaa;
    var aba:int = oaa ^ zaa;
    var bba:int = d[4]:ubyte;
    var cba:int = 255;
    var dba:int = bba & cba;
    var eba:int = f_x(dba);
    var fba:int = 255;
    var gba:int = eba & fba;
    var hba:int = f_x(gba);
    var iba:int = 255;
    var jba:int = hba & iba;
    var kba:int = f_x(jba);
    var lba:int = 255;
    var mba:int = kba & lba;
    var nba:int = 0;
    var oba:int = mba << nba;
    var pba:int = aba ^ oba;
    var qba:int = d[4]:ubyte;
    var rba:int = 255;
    var sba:int = qba & rba;
    var tba:int = f_x(sba);
    var uba:int = 255;
    var vba:int = tba & uba;
    var wba:int = f_x(vba);
    var xba:int = 255;
    var yba:int = wba & xba;
    var zba:int = f_x(yba);
    var aca:int = 255;
    var bca:int = zba & aca;
    var cca:int = f_x(bca);
    var dca:int = 255;
    var eca:int = cca & dca;
    var fca:int = 0;
    var gca:int = eca * fca;
    var hca:int = pba ^ gca;
    var ica:int = aaa ^ hca;
    var jca:int = d[3]:int;
    var kca:int = d[2]:int;
    var lca:int = 2;
    var mca:int = kca << lca;
    var nca:byte_ptr = jca + mca;
    nca[2] = ica;
    var oca:int = d[7]:ubyte;
    var pca:int = 255;
    var qca:int = oca & pca;
    var rca:int = 0;
    var sca:int = qca << rca;
    var tca:int = d[7]:ubyte;
    var uca:int = 255;
    var vca:int = tca & uca;
    var wca:int = f_x(vca);
    var xca:int = 255;
    var yca:int = wca & xca;
    var zca:int = 0;
    var ada:int = yca << zca;
    var bda:int = sca ^ ada;
    var cda:int = d[7]:ubyte;
    var dda:int = 255;
    var eda:int = cda & dda;
    var fda:int = f_x(eda);
    var gda:int = 255;
    var hda:int = fda & gda;
    var ida:int = f_x(hda);
    var jda:int = 255;
    var kda:int = ida & jda;
    var lda:int = 0;
    var mda:int = kda * lda;
    var nda:int = bda ^ mda;
    var oda:int = d[7]:ubyte;
    var pda:int = 255;
    var qda:int = oda & pda;
    var rda:int = f_x(qda);
    var sda:int = 255;
    var tda:int = rda & sda;
    var uda:int = f_x(tda);
    var vda:int = 255;
    var wda:int = uda & vda;
    var xda:int = f_x(wda);
    var yda:int = 255;
    var zda:int = xda & yda;
    var aea:int = 0;
    var bea:int = zda << aea;
    var cea:int = nda ^ bea;
    var dea:int = d[7]:ubyte;
    var eea:int = 255;
    var fea:int = dea & eea;
    var gea:int = f_x(fea);
    var hea:int = 255;
    var iea:int = gea & hea;
    var jea:int = f_x(iea);
    var kea:int = 255;
    var lea:int = jea & kea;
    var mea:int = f_x(lea);
    var nea:int = 255;
    var oea:int = mea & nea;
    var pea:int = f_x(oea);
    var qea:int = 255;
    var rea:int = pea & qea;
    var sea:int = 0;
    var tea:int = rea * sea;
    var uea:int = cea ^ tea;
    var vea:int = d[6]:ubyte;
    var wea:int = 255;
    var xea:int = vea & wea;
    var yea:int = 0;
    var zea:int = xea << yea;
    var afa:int = d[6]:ubyte;
    var bfa:int = 255;
    var cfa:int = afa & bfa;
    var dfa:int = f_x(cfa);
    var efa:int = 255;
    var ffa:int = dfa & efa;
    var gfa:int = 0;
    var hfa:int = ffa * gfa;
    var ifa:int = zea ^ hfa;
    var jfa:int = d[6]:ubyte;
    var kfa:int = 255;
    var lfa:int = jfa & kfa;
    var mfa:int = f_x(lfa);
    var nfa:int = 255;
    var ofa:int = mfa & nfa;
    var pfa:int = f_x(ofa);
    var qfa:int = 255;
    var rfa:int = pfa & qfa;
    var sfa:int = 0;
    var tfa:int = rfa << sfa;
    var ufa:int = ifa ^ tfa;
    var vfa:int = d[6]:ubyte;
    var wfa:int = 255;
    var xfa:int = vfa & wfa;
    var yfa:int = f_x(xfa);
    var zfa:int = 255;
    var aga:int = yfa & zfa;
    var bga:int = f_x(aga);
    var cga:int = 255;
    var dga:int = bga & cga;
    var ega:int = f_x(dga);
    var fga:int = 255;
    var gga:int = ega & fga;
    var hga:int = 0;
    var iga:int = gga << hga;
    var jga:int = ufa ^ iga;
    var kga:int = d[6]:ubyte;
    var lga:int = 255;
    var mga:int = kga & lga;
    var nga:int = f_x(mga);
    var oga:int = 255;
    var pga:int = nga & oga;
    var qga:int = f_x(pga);
    var rga:int = 255;
    var sga:int = qga & rga;
    var tga:int = f_x(sga);
    var uga:int = 255;
    var vga:int = tga & uga;
    var wga:int = f_x(vga);
    var xga:int = 255;
    var yga:int = wga & xga;
    var zga:int = 0;
    var aha:int = yga * zga;
    var bha:int = jga ^ aha;
    var cha:int = uea ^ bha;
    var dha:int = d[5]:ubyte;
    var eha:int = 255;
    var fha:int = dha & eha;
    var gha:int = 0;
    var hha:int = fha << gha;
    var iha:int = d[5]:ubyte;
    var jha:int = 255;
    var kha:int = iha & jha;
    var lha:int = f_x(kha);
    var mha:int = 255;
    var nha:int = lha & mha;
    var oha:int = 0;
    var pha:int = nha * oha;
    var qha:int = hha ^ pha;
    var rha:int = d[5]:ubyte;
    var sha:int = 255;
    var tha:int = rha & sha;
    var uha:int = f_x(tha);
    var vha:int = 255;
    var wha:int = uha & vha;
    var xha:int = f_x(wha);
    var yha:int = 255;
    var zha:int = xha & yha;
    var aia:int = 0;
    var bia:int = zha * aia;
    var cia:int = qha ^ bia;
    var dia:int = d[5]:ubyte;
    var eia:int = 255;
    var fia:int = dia & eia;
    var gia:int = f_x(fia);
    var hia:int = 255;
    var iia:int = gia & hia;
    var jia:int = f_x(iia);
    var kia:int = 255;
    var lia:int = jia & kia;
    var mia:int = f_x(lia);
    var nia:int = 255;
    var oia:int = mia & nia;
    var pia:int = 0;
    var qia:int = oia << pia;
    var ria:int = cia ^ qia;
    var sia:int = d[5]:ubyte;
    var tia:int = 255;
    var uia:int = sia & tia;
    var via:int = f_x(uia);
    var wia:int = 255;
    var xia:int = via & wia;
    var yia:int = f_x(xia);
    var zia:int = 255;
    var aja:int = yia & zia;
    var bja:int = f_x(aja);
    var cja:int = 255;
    var dja:int = bja & cja;
    var eja:int = f_x(dja);
    var fja:int = 255;
    var gja:int = eja & fja;
    var hja:int = 0;
    var ija:int = gja * hja;
    var jja:int = ria ^ ija;
    var kja:int = cha ^ jja;
    var lja:int = d[4]:ubyte;
    var mja:int = 255;
    var nja:int = lja & mja;
    var oja:int = 0;
    var pja:int = nja * oja;
    var qja:int = d[4]:ubyte;
    var rja:int = 255;
    var sja:int = qja & rja;
    var tja:int = f_x(sja);
    var uja:int = 255;
    var vja:int = tja & uja;
    var wja:int = 0;
    var xja:int = vja << wja;
    var yja:int = pja ^ xja;
    var zja:int = d[4]:ubyte;
    var aka:int = 255;
    var bka:int = zja & aka;
    var cka:int = f_x(bka);
    var dka:int = 255;
    var eka:int = cka & dka;
    var fka:int = f_x(eka);
    var gka:int = 255;
    var hka:int = fka & gka;
    var ika:int = 0;
    var jka:int = hka << ika;
    var kka:int = yja ^ jka;
    var lka:int = d[4]:ubyte;
    var mka:int = 255;
    var nka:int = lka & mka;
    var oka:int = f_x(nka);
    var pka:int = 255;
    var qka:int = oka & pka;
    var rka:int = f_x(qka);
    var ska:int = 255;
    var tka:int = rka & ska;
    var uka:int = f_x(tka);
    var vka:int = 255;
    var wka:int = uka & vka;
    var xka:int = 0;
    var yka:int = wka << xka;
    var zka:int = kka ^ yka;
    var ala:int = d[4]:ubyte;
    var bla:int = 255;
    var cla:int = ala & bla;
    var dla:int = f_x(cla);
    var ela:int = 255;
    var fla:int = dla & ela;
    var gla:int = f_x(fla);
    var hla:int = 255;
    var ila:int = gla & hla;
    var jla:int = f_x(ila);
    var kla:int = 255;
    var lla:int = jla & kla;
    var mla:int = f_x(lla);
    var nla:int = 255;
    var ola:int = mla & nla;
    var pla:int = 0;
    var qla:int = ola * pla;
    var rla:int = zka ^ qla;
    var sla:int = kja ^ rla;
    var tla:int = d[3]:int;
    var ula:int = d[2]:int;
    var vla:int = 2;
    var wla:int = ula << vla;
    var xla:byte_ptr = tla + wla;
    xla[3] = sla;
    var yla:int = d[2]:int;
    var zla:int = 1;
    var ama:int = yla + zla;
    d[2]:int = ama;
    continue L_b;
  }
  unreachable;
  label B_a:
  var bma:int = 16;
  var cma:int = d + bma;
  g_a = cma;
}

function f_q(a:int):int {
  var b:int = g_a;
  var c:int = 16;
  var d:int_ptr = b - c;
  d[2] = a;
  var e:int = d[2];
  var f:int = 43;
  var g:int = e;
  var h:int = f;
  var i:int = g == h;
  var j:int = 1;
  var k:int = i & j;
  if (eqz(k)) goto B_b;
  var l:int = 62;
  d[3] = l;
  goto B_a;
  label B_b:
  var m:int = d[2];
  var n:int = 47;
  var o:int = m;
  var p:int = n;
  var q:int = o == p;
  var r:int = 1;
  var s:int = q & r;
  if (eqz(s)) goto B_c;
  var t:int = 63;
  d[3] = t;
  goto B_a;
  label B_c:
  var u:int = d[2];
  var v:int = 61;
  var w:int = u;
  var x:int = v;
  var y:int = w == x;
  var z:int = 1;
  var aa:int = y & z;
  if (eqz(aa)) goto B_d;
  var ba:int = 64;
  d[3] = ba;
  goto B_a;
  label B_d:
  var ca:int = d[2];
  var da:int = 47;
  var ea:int = ca;
  var fa:int = da;
  var ga:int = ea > fa;
  var ha:int = 1;
  var ia:int = ga & ha;
  if (eqz(ia)) goto B_e;
  var ja:int = d[2];
  var ka:int = 58;
  var la:int = ja;
  var ma:int = ka;
  var na:int = la < ma;
  var oa:int = 1;
  var pa:int = na & oa;
  if (eqz(pa)) goto B_e;
  var qa:int = d[2];
  var ra:int = 4;
  var sa:int = qa + ra;
  d[3] = sa;
  goto B_a;
  label B_e:
  var ta:int = d[2];
  var ua:int = 64;
  var va:int = ta;
  var wa:int = ua;
  var xa:int = va > wa;
  var ya:int = 1;
  var za:int = xa & ya;
  if (eqz(za)) goto B_f;
  var ab:int = d[2];
  var bb:int = 91;
  var cb:int = ab;
  var db:int = bb;
  var eb:int = cb < db;
  var fb:int = 1;
  var gb:int = eb & fb;
  if (eqz(gb)) goto B_f;
  var hb:int = d[2];
  var ib:int = 65;
  var jb:int = hb - ib;
  d[3] = jb;
  goto B_a;
  label B_f:
  var kb:int = d[2];
  var lb:int = 96;
  var mb:int = kb;
  var nb:int = lb;
  var ob:int = mb > nb;
  var pb:int = 1;
  var qb:int = ob & pb;
  if (eqz(qb)) goto B_g;
  var rb:int = d[2];
  var sb:int = 123;
  var tb:int = rb;
  var ub:int = sb;
  var vb:int = tb < ub;
  var wb:int = 1;
  var xb:int = vb & wb;
  if (eqz(xb)) goto B_g;
  var yb:int = d[2];
  var zb:int = 97;
  var ac:int = yb - zb;
  var bc:int = 26;
  var cc:int = ac + bc;
  d[3] = cc;
  goto B_a;
  label B_g:
  var dc:int = 0;
  d[3] = dc;
  label B_a:
  var ec:int = d[3];
  return ec;
}

function f_r(a:int):int {
  var b:int = g_a;
  var c:int = 16;
  var d:int_ptr = b - c;
  d[3] = a;
  var e:int = d[3];
  var f:int = 3;
  var g:int = e * f;
  var h:int = 2;
  var i:int = g >> h;
  return i;
}

function f_s(a:int, b:int, c:int):int {
  var d:int = g_a;
  var e:int = 48;
  var f:int_ptr = d - e;
  f[11] = a;
  f[10] = b;
  f[9] = c;
  var g:int = 0;
  f[8] = g;
  var h:int = 0;
  f[7] = h;
  var i:int = 0;
  f[6] = i;
  var j:int = 0;
  f[8] = j;
  loop L_b {
    var k:int = f[8];
    var l:int = f[10];
    var m:int = k;
    var n:int = l;
    var o:int = m < n;
    var p:int = 1;
    var q:int = o & p;
    if (eqz(q)) goto B_a;
    var r:int = f[11];
    var s:int = f[8];
    var t:ubyte_ptr = r + s;
    var u:int = t[0];
    var v:int = 255;
    var w:int = u & v;
    var x:int = f[7];
    var y:int = 1;
    var z:int = x + y;
    f[7] = z;
    var aa:int = 12;
    var ba:int = f + aa;
    var ca:int = ba;
    var da:int = 2;
    var ea:int = x << da;
    var fa:int_ptr = ca + ea;
    fa[0] = w;
    var ga:int = f[7];
    var ha:int = 3;
    var ia:int = ga;
    var ja:int = ha;
    var ka:int = ia == ja;
    var la:int = 1;
    var ma:int = ka & la;
    if (eqz(ma)) goto B_c;
    var na:int = f[3];
    var oa:int = 255;
    var pa:int = na & oa;
    var qa:int = 2;
    var ra:ubyte_ptr = pa >> qa;
    var sa:int = ra[1584];
    var ta:int = f[9];
    var ua:int = f[6];
    var va:int = 0;
    var wa:int = ua + va;
    var xa:byte_ptr = ta + wa;
    xa[0] = sa;
    var ya:int = f[3];
    var za:int = 3;
    var ab:int = ya & za;
    var bb:int = 4;
    var cb:int = ab << bb;
    var db:int = f[4];
    var eb:int = 240;
    var fb:int = db & eb;
    var gb:int = 4;
    var hb:int = fb >> gb;
    var ib:ubyte_ptr = cb + hb;
    var jb:int = ib[1584];
    var kb:int = f[9];
    var lb:int = f[6];
    var mb:int = 1;
    var nb:int = lb + mb;
    var ob:byte_ptr = kb + nb;
    ob[0] = jb;
    var pb:int = f[4];
    var qb:int = 15;
    var rb:int = pb & qb;
    var sb:int = 2;
    var tb:int = rb << sb;
    var ub:int = f[5];
    var vb:int = 192;
    var wb:int = ub & vb;
    var xb:int = 6;
    var yb:int = wb >> xb;
    var zb:ubyte_ptr = tb + yb;
    var ac:int = zb[1584];
    var bc:int = f[9];
    var cc:int = f[6];
    var dc:int = 2;
    var ec:int = cc + dc;
    var fc:byte_ptr = bc + ec;
    fc[0] = ac;
    var gc:int = f[5];
    var hc:int = 63;
    var ic:ubyte_ptr = gc & hc;
    var jc:int = ic[1584];
    var kc:int = f[9];
    var lc:int = f[6];
    var mc:int = 3;
    var nc:int = lc + mc;
    var oc:byte_ptr = kc + nc;
    oc[0] = jc;
    var pc:int = 0;
    f[7] = pc;
    var qc:int = f[6];
    var rc:int = 4;
    var sc:int = qc + rc;
    f[6] = sc;
    label B_c:
    var tc:int = f[8];
    var uc:int = 1;
    var vc:int = tc + uc;
    f[8] = vc;
    continue L_b;
  }
  unreachable;
  label B_a:
  var wc:int = f[7];
  if (eqz(wc)) goto B_d;
  var xc:int = f[7];
  var yc:int = 1;
  var zc:int = xc;
  var ad:int = yc;
  var bd:int = zc == ad;
  var cd:int = 1;
  var dd:int = bd & cd;
  if (eqz(dd)) goto B_e;
  var ed:int = 0;
  f[4] = ed;
  label B_e:
  var fd:int = f[3];
  var gd:int = 255;
  var hd:int = fd & gd;
  var id:int = 2;
  var jd:ubyte_ptr = hd >> id;
  var kd:int = jd[1584];
  var ld:int = f[9];
  var md:int = f[6];
  var nd:int = 0;
  var od:int = md + nd;
  var pd:byte_ptr = ld + od;
  pd[0] = kd;
  var qd:int = f[3];
  var rd:int = 3;
  var sd:int = qd & rd;
  var td:int = 4;
  var ud:int = sd << td;
  var vd:int = f[4];
  var wd:int = 240;
  var xd:int = vd & wd;
  var yd:int = 4;
  var zd:int = xd >> yd;
  var ae:ubyte_ptr = ud + zd;
  var be:int = ae[1584];
  var ce:int = f[9];
  var de:int = f[6];
  var ee:int = 1;
  var fe:int = de + ee;
  var ge:byte_ptr = ce + fe;
  ge[0] = be;
  var he:int = f[7];
  var ie:int = 2;
  var je:int = he;
  var ke:int = ie;
  var le:int = je == ke;
  var me:int = 1;
  var ne:int = le & me;
  if (eqz(ne)) goto B_g;
  var oe:int = f[4];
  var pe:int = 15;
  var qe:int = oe & pe;
  var re:int = 2;
  var se:ubyte_ptr = qe << re;
  var te:int = se[1584];
  var ue:int = f[9];
  var ve:int = f[6];
  var we:int = 2;
  var xe:int = ve + we;
  var ye:byte_ptr = ue + xe;
  ye[0] = te;
  goto B_f;
  label B_g:
  var ze:int = f[9];
  var af:int = f[6];
  var bf:int = 2;
  var cf:int = af + bf;
  var df:byte_ptr = ze + cf;
  var ef:int = 61;
  df[0] = ef;
  label B_f:
  var ff:int = f[9];
  var gf:int = f[6];
  var hf:int = 3;
  var if:int = gf + hf;
  var jf:byte_ptr = ff + if;
  var kf:int = 61;
  jf[0] = kf;
  var lf:int = f[6];
  var mf:int = 4;
  var nf:int = lf + mf;
  f[6] = nf;
  label B_d:
  var of:int = f[9];
  var pf:int = f[6];
  var qf:byte_ptr = of + pf;
  var rf:int = 0;
  qf[0] = rf;
  var sf:int = f[6];
  return sf;
}

function f(a:int, b:int, c:int):int {
  var d:int = g_a;
  var e:int = 48;
  var f:int_ptr = d - e;
  g_a = f;
  f[11] = a;
  f[10] = b;
  f[9] = c;
  var g:int = 0;
  f[8] = g;
  var h:int = 0;
  f[7] = h;
  var i:int = 0;
  f[6] = i;
  var j:int = 0;
  f[8] = j;
  loop L_b {
    var k:int = f[8];
    var l:int = f[10];
    var m:int = k;
    var n:int = l;
    var o:int = m < n;
    var p:int = 1;
    var q:int = o & p;
    if (eqz(q)) goto B_a;
    var r:int = f[11];
    var s:int = f[8];
    var t:ubyte_ptr = r + s;
    var u:int = t[0];
    var v:int = 255;
    var w:int = u & v;
    var x:int = f_q(w);
    var y:int = f[7];
    var z:int = 1;
    var aa:int = y + z;
    f[7] = aa;
    var ba:int = f;
    var ca:int = 2;
    var da:int = y << ca;
    var ea:int_ptr = ba + da;
    ea[0] = x;
    var fa:int = f[7];
    var ga:int = 4;
    var ha:int = fa;
    var ia:int = ga;
    var ja:int = ha == ia;
    var ka:int = 1;
    var la:int = ja & ka;
    if (eqz(la)) goto B_c;
    var ma:int = f[0];
    var na:int = 255;
    var oa:int = ma & na;
    var pa:int = 2;
    var qa:int = oa << pa;
    var ra:int = f[1];
    var sa:int = 48;
    var ta:int = ra & sa;
    var ua:int = 4;
    var va:int = ta >> ua;
    var wa:int = qa + va;
    var xa:int = f[9];
    var ya:int = f[6];
    var za:int = 0;
    var ab:int = ya + za;
    var bb:byte_ptr = xa + ab;
    bb[0] = wa;
    var cb:int = f[2];
    var db:int = 64;
    var eb:int = cb;
    var fb:int = db;
    var gb:int = eb != fb;
    var hb:int = 1;
    var ib:int = gb & hb;
    if (eqz(ib)) goto B_e;
    var jb:int = f[1];
    var kb:int = 15;
    var lb:int = jb & kb;
    var mb:int = 4;
    var nb:int = lb << mb;
    var ob:int = f[2];
    var pb:int = 60;
    var qb:int = ob & pb;
    var rb:int = 2;
    var sb:int = qb >> rb;
    var tb:int = nb + sb;
    var ub:int = f[9];
    var vb:int = f[6];
    var wb:int = 1;
    var xb:int = vb + wb;
    var yb:byte_ptr = ub + xb;
    yb[0] = tb;
    var zb:int = f[3];
    var ac:int = 64;
    var bc:int = zb;
    var cc:int = ac;
    var dc:int = bc != cc;
    var ec:int = 1;
    var fc:int = dc & ec;
    if (eqz(fc)) goto B_g;
    var gc:int = f[2];
    var hc:int = 3;
    var ic:int = gc & hc;
    var jc:int = 6;
    var kc:int = ic << jc;
    var lc:int = f[3];
    var mc:int = kc + lc;
    var nc:int = f[9];
    var oc:int = f[6];
    var pc:int = 2;
    var qc:int = oc + pc;
    var rc:byte_ptr = nc + qc;
    rc[0] = mc;
    var sc:int = f[6];
    var tc:int = 3;
    var uc:int = sc + tc;
    f[6] = uc;
    goto B_f;
    label B_g:
    var vc:int = f[6];
    var wc:int = 2;
    var xc:int = vc + wc;
    f[6] = xc;
    label B_f:
    goto B_d;
    label B_e:
    var yc:int = f[6];
    var zc:int = 1;
    var ad:int = yc + zc;
    f[6] = ad;
    label B_d:
    var bd:int = 0;
    f[7] = bd;
    label B_c:
    var cd:int = f[8];
    var dd:int = 1;
    var ed:int = cd + dd;
    f[8] = ed;
    continue L_b;
  }
  unreachable;
  label B_a:
  var fd:int = f[6];
  var gd:int = 48;
  var hd:int = f + gd;
  g_a = hd;
  return fd;
}

function f_u():int {
  var a:int = g_a;
  var b:int = 208;
  var c:int_ptr = a - b;
  g_a = c;
  var d:int = 0;
  c[51] = d;
  var e:int = 1;
  var f:int = 17;
  var g:int = f_ca(e, f);
  var h:int_ptr = 0;
  h[414] = g;
  var i:int_ptr = 0;
  var j:byte_ptr = i[414];
  var k:int = 104;
  j[1] = k;
  var l:int_ptr = 0;
  var m:byte_ptr = l[414];
  var n:int = 115;
  m[3] = n;
  var o:int_ptr = 0;
  var p:byte_ptr = o[414];
  var q:int = 116;
  p[9] = q;
  var r:int_ptr = 0;
  var s:byte_ptr = r[414];
  var t:int = 95;
  s[15] = t;
  var u:int_ptr = 0;
  var v:byte_ptr = u[414];
  var w:int = 107;
  v[10] = w;
  var x:int_ptr = 0;
  var y:byte_ptr = x[414];
  var z:int = 116;
  y[6] = z;
  var aa:int_ptr = 0;
  var ba:byte_ptr = aa[414];
  var ca:int = 122;
  ba[14] = ca;
  var da:int_ptr = 0;
  var ea:byte_ptr = da[414];
  var fa:int = 121;
  ea[12] = fa;
  var ga:int_ptr = 0;
  var ha:byte_ptr = ga[414];
  var ia:int = 122;
  ha[13] = ia;
  var ja:int_ptr = 0;
  var ka:byte_ptr = ja[414];
  var la:int = 116;
  ka[0] = la;
  var ma:int_ptr = 0;
  var na:byte_ptr = ma[414];
  var oa:int = 101;
  na[11] = oa;
  var pa:int_ptr = 0;
  var qa:byte_ptr = pa[414];
  var ra:int = 115;
  qa[8] = ra;
  var sa:int_ptr = 0;
  var ta:byte_ptr = sa[414];
  var ua:int = 105;
  ta[2] = ua;
  var va:int_ptr = 0;
  var wa:byte_ptr = va[414];
  var xa:int = 101;
  wa[7] = xa;
  var ya:int_ptr = 0;
  var za:byte_ptr = ya[414];
  var ab:int = 105;
  za[5] = ab;
  var bb:int_ptr = 0;
  var cb:byte_ptr = bb[414];
  var db:int = 115;
  cb[4] = db;
  var eb:int = 1024;
  c[50] = eb;
  var fb:int = c[50];
  var gb:int = 8;
  var hb:int = c + gb;
  var ib:int = hb;
  f_d(ib, fb);
  var jb:int_ptr = 0;
  var kb:int = jb[414];
  var lb:int = 8;
  var mb:int = c + lb;
  var nb:int = mb;
  f_f(nb, kb);
  var ob:int = 0;
  var pb:int = 208;
  var qb:int = c + pb;
  g_a = qb;
  return ob;
}

export function encodeString(a:int, b:int):int {
  var c:int = g_a;
  var d:int = 224;
  var e:int_ptr = c - d;
  g_a = e;
  e[55] = a;
  e[54] = b;
  var f:int = e[55];
  var g:int = f_z(f);
  e[53] = g;
  var h:int_ptr = 0;
  var i:int = h[414];
  var j:int = 16;
  var k:int = e + j;
  var l:int = k;
  f_d(l, i);
  var m:int = 0;
  e[3] = m;
  loop L_b {
    var n:int = e[3];
    var o:int = e[54];
    var p:int = 16;
    var q:int = o / p;
    var r:int = n;
    var s:int = q;
    var t:int = r < s;
    var u:int = 1;
    var v:int = t & u;
    if (eqz(v)) goto B_a;
    var w:int = e[53];
    var x:int = e[3];
    var y:int = 4;
    var z:int = x << y;
    var aa:int = w + z;
    var ba:int = 16;
    var ca:int = e + ba;
    var da:int = ca;
    f_f(da, aa);
    var ea:int = e[3];
    var fa:int = 1;
    var ga:int = ea + fa;
    e[3] = ga;
    continue L_b;
  }
  unreachable;
  label B_a:
  var ha:int = e[54];
  var ia:int = f_r(ha);
  var ja:int = 4;
  var ka:int = ia + ja;
  var la:int = 1;
  var ma:int = f_ca(la, ka);
  e[2] = ma;
  var na:int = e[53];
  var oa:int = e[54];
  var pa:int = e[2];
  f_s(na, oa, pa);
  var qa:int = e[2];
  var ra:int = 224;
  var sa:int = e + ra;
  g_a = sa;
  return qa;
}

export function decodeString(a:int, b:int):int {
  var c:int = g_a;
  var d:int = 224;
  var e:int_ptr = c - d;
  g_a = e;
  e[55] = a;
  e[54] = b;
  var f:int = e[55];
  var g:int = f_z(f);
  e[53] = g;
  var h:int = e[53];
  var i:int = f_ha(h);
  var j:int = 1;
  var k:int = i + j;
  var l:int = 1;
  var m:int = f_ca(l, k);
  e[52] = m;
  var n:int = e[53];
  var o:int = e[53];
  var p:int = f_ha(o);
  var q:int = e[52];
  f(n, p, q);
  var r:int_ptr = 0;
  var s:int = r[414];
  var t:int = 16;
  var u:int = e + t;
  var v:int = u;
  f_d(v, s);
  var w:int = 0;
  e[3] = w;
  loop L_b {
    var x:int = e[3];
    var y:int = e[54];
    var z:int = 16;
    var aa:int = y / z;
    var ba:int = x;
    var ca:int = aa;
    var da:int = ba < ca;
    var ea:int = 1;
    var fa:int = da & ea;
    if (eqz(fa)) goto B_a;
    var ga:int = e[52];
    var ha:int = e[3];
    var ia:int = 4;
    var ja:int = ha << ia;
    var ka:int = ga + ja;
    var la:int = 16;
    var ma:int = e + la;
    var na:int = ma;
    f_l(na, ka);
    var oa:int = e[3];
    var pa:int = 1;
    var qa:int = oa + pa;
    e[3] = qa;
    continue L_b;
  }
  unreachable;
  label B_a:
  var ra:int = e[52];
  var sa:int = 224;
  var ta:int = e + sa;
  g_a = ta;
  return ra;
}

function f_x(a:int):int {
  var b:int = g_a;
  var c:int = 16;
  var d:int = b - c;
  d[15]:byte = a;
  var e:int = d[15]:ubyte;
  var f:int = 255;
  var g:int = e & f;
  var h:int = 1;
  var i:int = g << h;
  var j:int = d[15]:ubyte;
  var k:int = 255;
  var l:int = j & k;
  var m:int = 7;
  var n:int = l >> m;
  var o:int = 1;
  var p:int = n & o;
  var q:int = 27;
  var r:int = p * q;
  var s:int = i ^ r;
  var t:int = 255;
  var u:int = s & t;
  return u;
}

export function main(a:int, b:int):int {
  var c:int = f_u();
  return c;
}

function f_z(a:int):int {
  var c:int;
  var b:int;
  b = f_ha(a) + 1;
  c = f_ba(b);
  if (c) goto B_a;
  return 0;
  label B_a:
  return f_fa(c, a, b);
}

export function errno_location():int {
  return 1660
}

function f_ba(a:int):int {
  var d:int;
  var e:int;
  var h:int;
  var f:{ a:int, b:int, c:int, d:int, e:int }
  var g:int_ptr;
  var c:{ a:int, b:int, c:int, d:int, e:int, f:int, g:int, h:int }
  var i:int;
  var m:int;
  var j:int_ptr;
  var l:int_ptr;
  var k:int_ptr;
  var b:int = g_a - 16;
  g_a = b;
  if (a > 244) goto B_m;
  c = 0[416]:int;
  a = c >> (e = (d = select_if(16, a + 11 & -8, a < 11)) >> 3);
  if (eqz(a & 3)) goto B_n;
  f = ((a ^ -1) & 1) + e;
  g = f << 3;
  e = (g + 1712)[0]:int;
  a = e + 8;
  d = e[2]:int;
  if (d != (g = g + 1704)) goto B_p;
  0[416]:int = c & -2 << f;
  goto B_o;
  label B_p:
  d[3]:int = g;
  g[2] = d;
  label B_o:
  e[1]:int = (f = f << 3) | 3;
  e = e + f;
  e[1]:int = e[1]:int | 1;
  goto B_a;
  label B_n:
  if (d <= (h = 0[418]:int)) goto B_l;
  if (eqz(a)) goto B_q;
  a = a << e & ((a = 2 << e) | 0 - a);
  a = (a & 0 - a) + -1;
  e = a >> (a = a >> 12 & 16);
  f = e >> 5 & 8;
  f = 
    ((((f | a) | (e = (a = e >> f) >> 2 & 4)) | (e = (a = a >> e) >> 1 & 2)) | 
     (e = (a = a >> e) >> 1 & 1)) + 
    (a >> e);
  g = f << 3;
  e = (g + 1712)[0]:int;
  a = e[2]:int;
  if (a != (g = g + 1704)) goto B_s;
  0[416]:int = (c = c & -2 << f);
  goto B_r;
  label B_s:
  a[3]:int = g;
  g[2] = a;
  label B_r:
  a = e + 8;
  e[1]:int = d | 3;
  g = e + d;
  g[1] = (f = (i = f << 3) - d) | 1;
  (e + i)[0]:int = f;
  if (eqz(h)) goto B_t;
  i = h >> 3;
  d = (i << 3) + 1704;
  e = 0[421]:int;
  if (c & (i = 1 << i)) goto B_v;
  0[416]:int = c | i;
  i = d;
  goto B_u;
  label B_v:
  i = d[2]:int;
  label B_u:
  d[2]:int = e;
  i[3]:int = e;
  e[3]:int = d;
  e[2]:int = i;
  label B_t:
  0[421]:int = g;
  0[418]:int = f;
  goto B_a;
  label B_q:
  j = 0[417]:int;
  if (eqz(j)) goto B_l;
  a = (j & 0 - j) + -1;
  e = a >> (a = a >> 12 & 16);
  f = e >> 5 & 8;
  g = 
    ((((((f | a) | (e = (a = e >> f) >> 2 & 4)) | (e = (a = a >> e) >> 1 & 2)) | 
       (e = (a = a >> e) >> 1 & 1)) + 
      (a >> e) << 
      2) + 
     1968)[0]:int;
  e = (g[1] & -8) - d;
  f = g;
  loop L_x {
    a = f.e;
    if (a) goto B_y;
    a = (f + 20)[0]:int;
    if (eqz(a)) goto B_w;
    label B_y:
    f = (a[1]:int & -8) - d;
    e = select_if(f, e, f = f < e);
    g = select_if(a, g, f);
    f = a;
    continue L_x;
  }
  unreachable;
  label B_w:
  k = g + d;
  if (k <= g) goto B_k;
  l = g[6];
  i = g[3];
  if (i == g) goto B_z;
  0[420]:int > (a = g[2]);
  a[3]:int = i;
  i[2]:int = a;
  goto B_b;
  label B_z:
  f = g + 20;
  a = f.a;
  if (a) goto B_aa;
  a = g[4];
  if (eqz(a)) goto B_j;
  f = g + 16;
  label B_aa:
  loop L_ba {
    m = f;
    i = a;
    f = i + 20;
    a = f.a;
    if (a) continue L_ba;
    f = i + 16;
    a = i[4]:int;
    if (a) continue L_ba;
  }
  m[0]:int = 0;
  goto B_b;
  label B_m:
  d = -1;
  if (a > -65) goto B_l;
  a = a + 11;
  d = a & -8;
  h = 0[417]:int;
  if (eqz(h)) goto B_l;
  m = 31;
  if (d > 16777215) goto B_ca;
  a = a >> 8;
  e = a << (a = a + 1048320 >> 16 & 8);
  f = e << (e = e + 520192 >> 16 & 4);
  a = ((f << (f = f + 245760 >> 16 & 2)) >> 15) - ((a | e) | f);
  m = (a << 1 | (d >> a + 21 & 1)) + 28;
  label B_ca:
  e = 0 - d;
  f = ((m << 2) + 1968)[0]:int;
  if (f) goto B_ga;
  a = 0;
  i = 0;
  goto B_fa;
  label B_ga:
  a = 0;
  g = d << select_if(0, 25 - (m >> 1), m == 31);
  i = 0;
  loop L_ha {
    c = (f.b & -8) - d;
    if (c >= e) goto B_ia;
    e = c;
    i = f;
    if (c) goto B_ia;
    e = 0;
    i = f;
    a = f;
    goto B_ea;
    label B_ia:
    a = select_if(select_if(a,
                            c = (f + 20)[0]:int,
                            c == (f = (f + (g >> 29 & 4) + 16)[0]:int)),
                  a,
                  c);
    g = g << 1;
    if (f) continue L_ha;
  }
  label B_fa:
  if (a | i) goto B_ja;
  a = 2 << m;
  a = (a | 0 - a) & h;
  if (eqz(a)) goto B_l;
  a = (a & 0 - a) + -1;
  f = a >> (a = a >> 12 & 16);
  g = f >> 5 & 8;
  a = 
    ((((((g | a) | (f = (a = f >> g) >> 2 & 4)) | (f = (a = a >> f) >> 1 & 2)) | 
       (f = (a = a >> f) >> 1 & 1)) + 
      (a >> f) << 
      2) + 
     1968)[0]:int;
  label B_ja:
  if (eqz(a)) goto B_da;
  label B_ea:
  loop L_ka {
    c = (a[1]:int & -8) - d;
    g = c < e;
    f = a[4]:int;
    if (f) goto B_la;
    f = (a + 20)[0]:int;
    label B_la:
    e = select_if(c, e, g);
    i = select_if(a, i, g);
    a = f;
    if (f) continue L_ka;
  }
  label B_da:
  if (eqz(i)) goto B_l;
  if (e >= 0[418]:int - d) goto B_l;
  m = i + d;
  if (m <= i) goto B_k;
  j = i[6]:int;
  g = i[3]:int;
  if (g == i) goto B_ma;
  0[420]:int > (a = i[2]:int);
  a[3]:int = g;
  g[2] = a;
  goto B_c;
  label B_ma:
  f = i + 20;
  a = f.a;
  if (a) goto B_na;
  a = i[4]:int;
  if (eqz(a)) goto B_i;
  f = i + 16;
  label B_na:
  loop L_oa {
    c = f;
    g = a;
    f = g + 20;
    a = f.a;
    if (a) continue L_oa;
    f = g + 16;
    a = g[4];
    if (a) continue L_oa;
  }
  c.a = 0;
  goto B_c;
  label B_l:
  a = 0[418]:int;
  if (a < d) goto B_pa;
  e = 0[421]:int;
  f = a - d;
  if (f < 16) goto B_ra;
  0[418]:int = f;
  0[421]:int = (g = e + d);
  g[1] = f | 1;
  (e + a)[0]:int = f;
  e[1]:int = d | 3;
  goto B_qa;
  label B_ra:
  0[421]:int = 0;
  0[418]:int = 0;
  e[1]:int = a | 3;
  a = e + a;
  a[1]:int = a[1]:int | 1;
  label B_qa:
  a = e + 8;
  goto B_a;
  label B_pa:
  g = 0[419]:int;
  if (g <= d) goto B_sa;
  0[419]:int = (e = g - d);
  0[422]:int = (f = (a = 0[422]:int) + d);
  f.b = e | 1;
  a[1]:int = d | 3;
  a = a + 8;
  goto B_a;
  label B_sa:
  if (eqz(0[534]:int)) goto B_ua;
  e = 0[536]:int;
  goto B_ta;
  label B_ua:
  0[537]:long@4 = -1L;
  0[535]:long@4 = 17592186048512L;
  0[534]:int = (b + 12 & -16) ^ 1431655768;
  0[539]:int = 0;
  0[527]:int = 0;
  e = 4096;
  label B_ta:
  a = 0;
  c = e + (h = d + 47);
  i = c & (m = 0 - e);
  if (i <= d) goto B_a;
  a = 0;
  e = 0[526]:int;
  if (eqz(e)) goto B_va;
  f = 0[524]:int;
  j = f + i;
  if (j <= f) goto B_a;
  if (j > e) goto B_a;
  label B_va:
  if (0[2108]:ubyte & 4) goto B_f;
  e = 0[422]:int;
  if (eqz(e)) goto B_ya;
  a = 2112;
  loop L_za {
    f = a[0]:int;
    if (f > e) goto B_ab;
    if (f + a[1]:int > e) goto B_xa;
    label B_ab:
    a = a[2]:int;
    if (a) continue L_za;
  }
  label B_ya:
  g = f_ea(0);
  if (g == -1) goto B_g;
  c = i;
  a = 0[535]:int;
  e = a + -1;
  if (eqz(e & g)) goto B_bb;
  c = i - g + (e + g & 0 - a);
  label B_bb:
  if (c <= d) goto B_g;
  if (c > 2147483646) goto B_g;
  a = 0[526]:int;
  if (eqz(a)) goto B_cb;
  e = 0[524]:int;
  f = e + c;
  if (f <= e) goto B_g;
  if (f > a) goto B_g;
  label B_cb:
  a = f_ea(c);
  if (a != g) goto B_wa;
  goto B_e;
  label B_xa:
  c = c - g & m;
  if (c > 2147483646) goto B_g;
  g = f_ea(c);
  if (g == a[0]:int + a[1]:int) goto B_h;
  a = g;
  label B_wa:
  if (a == -1) goto B_db;
  if (d + 48 <= c) goto B_db;
  e = h - c + (e = 0[536]:int) & 0 - e;
  if (e <= 2147483646) goto B_eb;
  g = a;
  goto B_e;
  label B_eb:
  if (f_ea(e) == -1) goto B_fb;
  c = e + c;
  g = a;
  goto B_e;
  label B_fb:
  f_ea(0 - c);
  goto B_g;
  label B_db:
  g = a;
  if (a != -1) goto B_e;
  goto B_g;
  label B_k:
  unreachable;
  label B_j:
  i = 0;
  goto B_b;
  label B_i:
  g = 0;
  goto B_c;
  label B_h:
  if (g != -1) goto B_e;
  label B_g:
  0[527]:int = 0[527]:int | 4;
  label B_f:
  if (i > 2147483646) goto B_d;
  g = f_ea(i);
  a = f_ea(0);
  if (g == -1) goto B_d;
  if (a == -1) goto B_d;
  if (g >= a) goto B_d;
  c = a - g;
  if (c <= d + 40) goto B_d;
  label B_e:
  0[524]:int = (a = 0[524]:int + c);
  if (a <= 0[525]:int) goto B_gb;
  0[525]:int = a;
  label B_gb:
  e = 0[422]:int;
  if (eqz(e)) goto B_kb;
  a = 2112;
  loop L_lb {
    if (g == (f = a[0]:int) + (i = a[1]:int)) goto B_jb;
    a = a[2]:int;
    if (a) continue L_lb;
    goto B_ib;
  }
  unreachable;
  label B_kb:
  a = 0[420]:int;
  if (eqz(a)) goto B_nb;
  if (g >= a) goto B_mb;
  label B_nb:
  0[420]:int = g;
  label B_mb:
  a = 0;
  0[529]:int = c;
  0[528]:int = g;
  0[424]:int = -1;
  0[425]:int = 0[534]:int;
  0[531]:int = 0;
  loop L_ob {
    e = a << 3;
    (e + 1712)[0]:int = (f = e + 1704);
    (e + 1716)[0]:int = f;
    a = a + 1;
    if (a != 32) continue L_ob;
  }
  0[419]:int = 
    (f = (a = c + -40) - (e = select_if(-8 - g & 7, 0, g + 8 & 7)));
  0[422]:int = (e = g + e);
  e[1]:int = f | 1;
  (g + a)[1]:int = 40;
  0[423]:int = 0[538]:int;
  goto B_hb;
  label B_jb:
  if (a[12]:ubyte & 8) goto B_ib;
  if (f > e) goto B_ib;
  if (g <= e) goto B_ib;
  a[1]:int = i + c;
  0[422]:int = (f = e + (a = select_if(-8 - e & 7, 0, e + 8 & 7)));
  0[419]:int = (a = (g = 0[419]:int + c) - a);
  f.b = a | 1;
  (e + g)[1]:int = 40;
  0[423]:int = 0[538]:int;
  goto B_hb;
  label B_ib:
  if (g >= (i = 0[420]:int)) goto B_pb;
  0[420]:int = g;
  i = g;
  label B_pb:
  f = g + c;
  a = 2112;
  loop L_xb {
    if (a[0]:int == f) goto B_wb;
    a = a[2]:int;
    if (a) continue L_xb;
    goto B_vb;
  }
  unreachable;
  label B_wb:
  if (eqz(a[12]:ubyte & 8)) goto B_ub;
  label B_vb:
  a = 2112;
  loop L_yb {
    f = a[0]:int;
    if (f > e) goto B_zb;
    f = f + a[1]:int;
    if (f > e) goto B_tb;
    label B_zb:
    a = a[2]:int;
    continue L_yb;
  }
  unreachable;
  label B_ub:
  a[0]:int = g;
  a[1]:int = a[1]:int + c;
  m = g + select_if(-8 - g & 7, 0, g + 8 & 7);
  m[1]:int = d | 3;
  c = f + select_if(-8 - f & 7, 0, f + 8 & 7);
  f = c - (d = m + d);
  if (e != c) goto B_ac;
  0[422]:int = d;
  0[419]:int = (a = 0[419]:int + f);
  d[1]:int = a | 1;
  goto B_rb;
  label B_ac:
  if (0[421]:int != c) goto B_bc;
  0[421]:int = d;
  0[418]:int = (a = 0[418]:int + f);
  d[1]:int = a | 1;
  (d + a)[0]:int = a;
  goto B_rb;
  label B_bc:
  a = c.b;
  if ((a & 3) != 1) goto B_cc;
  h = a & -8;
  if (a > 255) goto B_ec;
  e = c.c;
  e == (g = ((i = a >> 3) << 3) + 1704);
  a = c.d;
  if (a != e) goto B_fc;
  0[416]:int = 0[416]:int & -2 << i;
  goto B_dc;
  label B_fc:
  a == g;
  e[3]:int = a;
  a[2]:int = e;
  goto B_dc;
  label B_ec:
  j = c.g;
  g = c.d;
  if (g == c) goto B_hc;
  i > (a = c.c);
  a[3]:int = g;
  g[2] = a;
  goto B_gc;
  label B_hc:
  a = c + 20;
  e = a[0]:int;
  if (e) goto B_ic;
  a = c + 16;
  e = a[0]:int;
  if (e) goto B_ic;
  g = 0;
  goto B_gc;
  label B_ic:
  loop L_jc {
    i = a;
    g = e;
    a = g + 20;
    e = a[0]:int;
    if (e) continue L_jc;
    a = g + 16;
    e = g[4];
    if (e) continue L_jc;
  }
  i[0]:int = 0;
  label B_gc:
  if (eqz(j)) goto B_dc;
  e = c.h;
  a = (e << 2) + 1968;
  if (a[0]:int != c) goto B_lc;
  a[0]:int = g;
  if (g) goto B_kc;
  0[417]:int = 0[417]:int & -2 << e;
  goto B_dc;
  label B_lc:
  (j + select_if(16, 20, j[4] == c))[0]:int = g;
  if (eqz(g)) goto B_dc;
  label B_kc:
  g[6] = j;
  a = c.e;
  if (eqz(a)) goto B_mc;
  g[4] = a;
  a[6]:int = g;
  label B_mc:
  a = c.f;
  if (eqz(a)) goto B_dc;
  (g + 20)[0]:int = a;
  a[6]:int = g;
  label B_dc:
  f = h + f;
  c = c + h;
  label B_cc:
  c.b = c.b & -2;
  d[1]:int = f | 1;
  (d + f)[0]:int = f;
  if (f > 255) goto B_nc;
  e = f >> 3;
  a = (e << 3) + 1704;
  f = 0[416]:int;
  if (f & (e = 1 << e)) goto B_pc;
  0[416]:int = f | e;
  e = a;
  goto B_oc;
  label B_pc:
  e = a[2]:int;
  label B_oc:
  a[2]:int = d;
  e[3]:int = d;
  d[3]:int = a;
  d[2]:int = e;
  goto B_rb;
  label B_nc:
  a = 31;
  if (f > 16777215) goto B_qc;
  a = f >> 8;
  e = a << (a = a + 1048320 >> 16 & 8);
  g = e << (e = e + 520192 >> 16 & 4);
  a = ((g << (g = g + 245760 >> 16 & 2)) >> 15) - ((a | e) | g);
  a = (a << 1 | (f >> a + 21 & 1)) + 28;
  label B_qc:
  d[7]:int = a;
  d[4]:long@4 = 0L;
  e = (a << 2) + 1968;
  g = 0[417]:int;
  if (g & (i = 1 << a)) goto B_sc;
  0[417]:int = g | i;
  e[0]:int = d;
  d[6]:int = e;
  goto B_rc;
  label B_sc:
  a = f << select_if(0, 25 - (a >> 1), a == 31);
  g = e[0]:int;
  loop L_tc {
    e = g;
    if ((e[1]:int & -8) == f) goto B_sb;
    g = a >> 29;
    a = a << 1;
    i = e + (g & 4) + 16;
    g = i[0]:int;
    if (g) continue L_tc;
  }
  i[0]:int = d;
  d[6]:int = e;
  label B_rc:
  d[3]:int = d;
  d[2]:int = d;
  goto B_rb;
  label B_tb:
  0[419]:int = 
    (m = (a = c + -40) - (i = select_if(-8 - g & 7, 0, g + 8 & 7)));
  0[422]:int = (i = g + i);
  i[1]:int = m | 1;
  (g + a)[1]:int = 40;
  0[423]:int = 0[538]:int;
  i = select_if(e,
                a = f + select_if(39 - f & 7, 0, f + -39 & 7) + -47,
                a < e + 16);
  i[1]:int = 27;
  (i + 16)[0]:long@4 = 0[530]:long@4;
  i[2]:long@4 = 0[528]:long@4;
  0[530]:int = i + 8;
  0[529]:int = c;
  0[528]:int = g;
  0[531]:int = 0;
  a = i + 24;
  loop L_uc {
    a[1]:int = 7;
    g = a + 8;
    a = a + 4;
    if (f > g) continue L_uc;
  }
  if (i == e) goto B_hb;
  i[1]:int = i[1]:int & -2;
  e[1]:int = (c = i - e) | 1;
  i[0]:int = c;
  if (c > 255) goto B_vc;
  f = c >> 3;
  a = (f << 3) + 1704;
  g = 0[416]:int;
  if (g & (f = 1 << f)) goto B_xc;
  0[416]:int = g | f;
  f = a;
  goto B_wc;
  label B_xc:
  f = a[2]:int;
  label B_wc:
  a[2]:int = e;
  f.d = e;
  e[3]:int = a;
  e[2]:int = f;
  goto B_hb;
  label B_vc:
  a = 31;
  if (c > 16777215) goto B_yc;
  a = c >> 8;
  f = a << (a = a + 1048320 >> 16 & 8);
  g = f << (f = f + 520192 >> 16 & 4);
  a = ((g << (g = g + 245760 >> 16 & 2)) >> 15) - ((a | f) | g);
  a = (a << 1 | (c >> a + 21 & 1)) + 28;
  label B_yc:
  e[4]:long@4 = 0L;
  (e + 28)[0]:int = a;
  f = (a << 2) + 1968;
  g = 0[417]:int;
  if (g & (i = 1 << a)) goto B_ad;
  0[417]:int = g | i;
  f.a = e;
  (e + 24)[0]:int = f;
  goto B_zc;
  label B_ad:
  a = c << select_if(0, 25 - (a >> 1), a == 31);
  g = f.a;
  loop L_bd {
    f = g;
    if ((f.b & -8) == c) goto B_qb;
    g = a >> 29;
    a = a << 1;
    i = f + (g & 4) + 16;
    g = i[0]:int;
    if (g) continue L_bd;
  }
  i[0]:int = e;
  (e + 24)[0]:int = f;
  label B_zc:
  e[3]:int = e;
  e[2]:int = e;
  goto B_hb;
  label B_sb:
  a = e[2]:int;
  a[3]:int = d;
  e[2]:int = d;
  d[6]:int = 0;
  d[3]:int = e;
  d[2]:int = a;
  label B_rb:
  a = m + 8;
  goto B_a;
  label B_qb:
  a = f.c;
  a[3]:int = e;
  f.c = e;
  (e + 24)[0]:int = 0;
  e[3]:int = f;
  e[2]:int = a;
  label B_hb:
  a = 0[419]:int;
  if (a <= d) goto B_d;
  0[419]:int = (e = a - d);
  0[422]:int = (f = (a = 0[422]:int) + d);
  f.b = e | 1;
  a[1]:int = d | 3;
  a = a + 8;
  goto B_a;
  label B_d:
  errno_location()[0]:int = 48;
  a = 0;
  goto B_a;
  label B_c:
  if (eqz(j)) goto B_cd;
  if (i != (a = ((f = i[7]:int) << 2) + 1968)[0]:int) goto B_ed;
  a[0]:int = g;
  if (g) goto B_dd;
  0[417]:int = (h = h & -2 << f);
  goto B_cd;
  label B_ed:
  (j + select_if(16, 20, j[4] == i))[0]:int = g;
  if (eqz(g)) goto B_cd;
  label B_dd:
  g[6] = j;
  a = i[4]:int;
  if (eqz(a)) goto B_fd;
  g[4] = a;
  a[6]:int = g;
  label B_fd:
  a = (i + 20)[0]:int;
  if (eqz(a)) goto B_cd;
  (g + 20)[0]:int = a;
  a[6]:int = g;
  label B_cd:
  if (e > 15) goto B_hd;
  i[1]:int = (a = e + d) | 3;
  a = i + a;
  a[1]:int = a[1]:int | 1;
  goto B_gd;
  label B_hd:
  i[1]:int = d | 3;
  m[1]:int = e | 1;
  (m + e)[0]:int = e;
  if (e > 255) goto B_id;
  e = e >> 3;
  a = (e << 3) + 1704;
  f = 0[416]:int;
  if (f & (e = 1 << e)) goto B_kd;
  0[416]:int = f | e;
  e = a;
  goto B_jd;
  label B_kd:
  e = a[2]:int;
  label B_jd:
  a[2]:int = m;
  e[3]:int = m;
  m[3]:int = a;
  m[2]:int = e;
  goto B_gd;
  label B_id:
  a = 31;
  if (e > 16777215) goto B_ld;
  a = e >> 8;
  f = a << (a = a + 1048320 >> 16 & 8);
  d = f << (f = f + 520192 >> 16 & 4);
  a = ((d << (d = d + 245760 >> 16 & 2)) >> 15) - ((a | f) | d);
  a = (a << 1 | (e >> a + 21 & 1)) + 28;
  label B_ld:
  m[7]:int = a;
  m[4]:long@4 = 0L;
  f = (a << 2) + 1968;
  if (h & (d = 1 << a)) goto B_od;
  0[417]:int = h | d;
  f.a = m;
  m[6]:int = f;
  goto B_nd;
  label B_od:
  a = e << select_if(0, 25 - (a >> 1), a == 31);
  d = f.a;
  loop L_pd {
    f = d;
    if ((f.b & -8) == e) goto B_md;
    d = a >> 29;
    a = a << 1;
    g = f + (d & 4) + 16;
    d = g[0];
    if (d) continue L_pd;
  }
  g[0] = m;
  m[6]:int = f;
  label B_nd:
  m[3]:int = m;
  m[2]:int = m;
  goto B_gd;
  label B_md:
  a = f.c;
  a[3]:int = m;
  f.c = m;
  m[6]:int = 0;
  m[3]:int = f;
  m[2]:int = a;
  label B_gd:
  a = i + 8;
  goto B_a;
  label B_b:
  if (eqz(l)) goto B_qd;
  if (g != (a = ((f = g[7]) << 2) + 1968)[0]:int) goto B_sd;
  a[0]:int = i;
  if (i) goto B_rd;
  0[417]:int = j & -2 << f;
  goto B_qd;
  label B_sd:
  (l + select_if(16, 20, l[4] == g))[0]:int = i;
  if (eqz(i)) goto B_qd;
  label B_rd:
  i[6]:int = l;
  a = g[4];
  if (eqz(a)) goto B_td;
  i[4]:int = a;
  a[6]:int = i;
  label B_td:
  a = (g + 20)[0]:int;
  if (eqz(a)) goto B_qd;
  (i + 20)[0]:int = a;
  a[6]:int = i;
  label B_qd:
  if (e > 15) goto B_vd;
  g[1] = (a = e + d) | 3;
  a = g + a;
  a[1]:int = a[1]:int | 1;
  goto B_ud;
  label B_vd:
  g[1] = d | 3;
  k[1] = e | 1;
  (k + e)[0]:int = e;
  if (eqz(h)) goto B_wd;
  d = h >> 3;
  f = (d << 3) + 1704;
  a = 0[421]:int;
  d = 1 << d;
  if (d & c) goto B_yd;
  0[416]:int = d | c;
  d = f;
  goto B_xd;
  label B_yd:
  d = f.c;
  label B_xd:
  f.c = a;
  d[3]:int = a;
  a[3]:int = f;
  a[2]:int = d;
  label B_wd:
  0[421]:int = k;
  0[418]:int = e;
  label B_ud:
  a = g + 8;
  label B_a:
  g_a = b + 16;
  return a;
}

function f_ca(a:int, b:int):int {
  var c:int;
  if (a) goto B_b;
  c = 0;
  goto B_a;
  label B_b:
  var d:long = i64_extend_i32_u(a) * i64_extend_i32_u(b);
  c = i32_wrap_i64(d);
  if ((b | a) < 65536) goto B_a;
  c = select_if(-1, c, i32_wrap_i64(d >> 32L) != 0);
  label B_a:
  a = f_ba(c);
  if (eqz(a)) goto B_c;
  if (eqz((a + -4)[0]:ubyte & 3)) goto B_c;
  f_ga(a, 0, c);
  label B_c:
  return a;
}

function f_da():int {
  return memory_size() << 16
}

function f_ea(a:int):int {
  var c:int;
  var b:int = d_ABCDEFGHIJKLMNOPQRSTUVWXYZab[17]:int;
  a = b + (c = a + 3 & -4);
  if (eqz(c)) goto B_b;
  if (a <= b) goto B_a;
  label B_b:
  if (a <= f_da()) goto B_c;
  if (eqz(env_emscripten_resize_heap(a))) goto B_a;
  label B_c:
  d_ABCDEFGHIJKLMNOPQRSTUVWXYZab[17]:int = a;
  return b;
  label B_a:
  errno_location()[0]:int = 48;
  return -1;
}

function f_fa(a:int, b:int, c:int):int {
  var f:int;
  var e:int;
  if (c < 512) goto B_a;
  env_emscripten_memcpy_big(a, b, c);
  return a;
  label B_a:
  var d:int = a + c;
  if ((b ^ a) & 3) goto B_c;
  if (a & 3) goto B_e;
  c = a;
  goto B_d;
  label B_e:
  if (c >= 1) goto B_f;
  c = a;
  goto B_d;
  label B_f:
  c = a;
  loop L_g {
    c[0]:byte = b[0]:ubyte;
    b = b + 1;
    c = c + 1;
    if (eqz(c & 3)) goto B_d;
    if (c < d) continue L_g;
  }
  label B_d:
  e = d & -4;
  if (e < 64) goto B_h;
  if (c > (f = e + -64)) goto B_h;
  loop L_i {
    c[0]:int = b[0]:int;
    c[1]:int = b[1]:int;
    c[2]:int = b[2]:int;
    c[3]:int = b[3]:int;
    c[4]:int = b[4]:int;
    c[5]:int = b[5]:int;
    c[6]:int = b[6]:int;
    c[7]:int = b[7]:int;
    c[8]:int = b[8]:int;
    c[9]:int = b[9]:int;
    c[10]:int = b[10]:int;
    c[11]:int = b[11]:int;
    c[12]:int = b[12]:int;
    c[13]:int = b[13]:int;
    c[14]:int = b[14]:int;
    c[15]:int = b[15]:int;
    b = b + 64;
    c = c + 64;
    if (c <= f) continue L_i;
  }
  label B_h:
  if (c >= e) goto B_b;
  loop L_j {
    c[0]:int = b[0]:int;
    b = b + 4;
    c = c + 4;
    if (c < e) continue L_j;
    goto B_b;
  }
  unreachable;
  label B_c:
  if (d >= 4) goto B_k;
  c = a;
  goto B_b;
  label B_k:
  e = d + -4;
  if (e >= a) goto B_l;
  c = a;
  goto B_b;
  label B_l:
  c = a;
  loop L_m {
    c[0]:byte = b[0]:ubyte;
    c[1]:byte = b[1]:ubyte;
    c[2]:byte = b[2]:ubyte;
    c[3]:byte = b[3]:ubyte;
    b = b + 4;
    c = c + 4;
    if (c <= e) continue L_m;
  }
  label B_b:
  if (c >= d) goto B_n;
  loop L_o {
    c[0]:byte = b[0]:ubyte;
    b = b + 1;
    c = c + 1;
    if (c != d) continue L_o;
  }
  label B_n:
  return a;
}

function f_ga(a:{ a:byte, b:byte, c:byte, d:byte }, b:{ a:long, b:long, c:long, d:long }, c:int):int {
  var e:int;
  var f:int;
  if (eqz(c)) goto B_a;
  var d:{ a:int, b:int, c:int, d:int, e:int, f:int, g:int } = c + a;
  (d + -1)[0]:byte = b;
  a.a = b;
  if (c < 3) goto B_a;
  (d + -2)[0]:byte = b;
  a.b = b;
  (d + -3)[0]:byte = b;
  a.c = b;
  if (c < 7) goto B_a;
  (d + -4)[0]:byte = b;
  a.d = b;
  if (c < 9) goto B_a;
  d = a + (e = 0 - a & 3);
  d.a = (b = (b & 255) * 16843009);
  c = d + (e = c - e & -4);
  (c + -4)[0]:int = b;
  if (e < 9) goto B_a;
  d.c = b;
  d.b = b;
  (c + -8)[0]:int = b;
  (c + -12)[0]:int = b;
  if (e < 25) goto B_a;
  d.g = b;
  d.f = b;
  d.e = b;
  d.d = b;
  (c + -16)[0]:int = b;
  (c + -20)[0]:int = b;
  (c + -24)[0]:int = b;
  (c + -28)[0]:int = b;
  c = e - (f = (d & 4) | 24);
  if (c < 32) goto B_a;
  var g:long = i64_extend_i32_u(b) * 4294967297L;
  b = d + f;
  loop L_b {
    b.d = g;
    b.c = g;
    b.b = g;
    b.a = g;
    b = b + 32;
    c = c + -32;
    if (c > 31) continue L_b;
  }
  label B_a:
  return a;
}

function f_ha(a:int):int {
  var d:int;
  var c:int;
  var b:ubyte_ptr = a;
  if (eqz(a & 3)) goto B_b;
  b = a;
  loop L_c {
    if (eqz(b[0])) goto B_a;
    b = b + 1;
    if (b & 3) continue L_c;
  }
  label B_b:
  loop L_d {
    c = b;
    b = c + 4;
    d = c[0]:int;
    if (eqz(((d ^ -1) & d + -16843009) & -2139062144)) continue L_d;
  }
  if (d & 255) goto B_e;
  return c - a;
  label B_e:
  loop L_f {
    d = c[1]:ubyte;
    b = c + 1;
    c = b;
    if (d) continue L_f;
  }
  label B_a:
  return b - a;
}

export function stackSave():int {
  return g_a
}

export function stackRestore(a:int) {
  g_a = a
}

export function stackAlloc(a:int):int {
  var b:int = g_a - a & -16;
  g_a = b;
  return b;
}

export function emscripten_stack_init() {
  g_c = 5245056;
  g_b = 2176 + 15 & -16;
}

export function emscripten_stack_get_free():int {
  return g_a - g_b
}

export function emscripten_stack_get_end():int {
  return g_b
}

function f_oa(a:int):int {
  return 1
}

function f_pa(a:int) {
}

function f_qa(a:int) {
}

function f_ra(a:int) {
}

function f_sa():int {
  f_qa(2160);
  return 2168;
}

function f_ta() {
  f_ra(2160)
}

export function fflush(a:int_ptr):int {
  var c:int;
  var b:int;
  if (eqz(a)) goto B_b;
  if (a[19] > -1) goto B_c;
  return f_va(a);
  label B_c:
  b = f_oa(a);
  c = f_va(a);
  if (eqz(b)) goto B_a;
  f_pa(a);
  return c;
  label B_b:
  c = 0;
  if (eqz(0[543]:int)) goto B_d;
  c = fflush(0[543]:int);
  label B_d:
  a = f_sa()[0]:int;
  if (eqz(a)) goto B_e;
  loop L_f {
    b = 0;
    if (a[19] < 0) goto B_g;
    b = f_oa(a);
    label B_g:
    if (a[5] <= a[7]) goto B_h;
    c = f_va(a) | c;
    label B_h:
    if (eqz(b)) goto B_i;
    f_pa(a);
    label B_i:
    a = a[14];
    if (a) continue L_f;
  }
  label B_e:
  f_ta();
  label B_a:
  return c;
}

function f_va(a:int):int {
  var c:int;
  if (a[5]:int <= a[7]:int) goto B_a;
  call_indirect(a, 0, 0, a[9]:int);
  if (a[5]:int) goto B_a;
  return -1;
  label B_a:
  var b:int = a[1]:int;
  if (b >= (c = a[2]:int)) goto B_b;
  call_indirect(a, i64_extend_i32_s(b - c), 1, a[10]:int);
  label B_b:
  a[7]:int = 0;
  a[2]:long = 0L;
  a[1]:long@4 = 0L;
  return 0;
}


}
