#include <math.h>
#define WASM_EXPORT __attribute__((visibility("default")))

int num,width,height,trianglenum;
float *pos,*ver,*sepvec,*alivec,*cohvec;
int *sepcnt,*alicnt,*cohcnt,*DLhalfedges,*DLtriangles;
WASM_EXPORT
void init(unsigned char* raw, int offset,int n,int w,int h,int t) {
  num=n;
  width=w;
  height=h;
  trianglenum=t;
  pos=(float*)(raw+offset);
  ver=(float*)(raw+offset+n*8);
  DLhalfedges=(int*)(raw+offset+n*16);
  DLtriangles=(int*)(raw+offset+n*20);
  sepvec=(float*)(raw+offset+n*24);
  alivec=(float*)(raw+offset+n*32);
  cohvec=(float*)(raw+offset+n*38);
  sepcnt=(int*)(raw+offset+n*42);
  alicnt=(int*)(raw+offset+n*46);
  cohcnt=(int*)(raw+offset+n*50);
}

int taikaku(int e) {
  return e % 3 ? e - 1 : e + 2;
}
int nexthalfedge(int e) {
  return ((e + 1) % 3) ? e + 1 : e - 2;
}
int prevhalfedge(int e) {
  return (e % 3) ? e - 1 : e + 2;
}
int triangleid(int e) {
  return e - (e % 3);
}
// return 2d orientation sign if we're confident in it through J. Shewchuk's error bound check
int orientIfSure(float px,float py,float rx,float ry,float qx,float qy) {
  float l = (ry - py) * (qx - px);
  float r = (rx - px) * (qy - py);
  return fabsf(l - r) >= 3.3306690738754716e-16 * fabsf(l + r) ? l - r : 0;
}

// a more robust orientation test that's stable in a given triangle (to fix robustness issues)
int orient(float rx,float ry,float qx,float qy,float px,float py) {
  int sign = orientIfSure(px, py, rx, ry, qx, qy) ||
    orientIfSure(rx, ry, qx, qy, px, py) ||
    orientIfSure(qx, qy, px, py, rx, ry);
  return sign < 0;
}
int inCircle(float ax,float ay,float bx,float by,float cx,float cy,float px,float py) {
  float dx = ax - px;
  float dy = ay - py;
  float ex = bx - px;
  float ey = by - py;
  float fx = cx - px;
  float fy = cy - py;

  float ap = dx * dx + dy * dy;
  float bp = ex * ex + ey * ey;
  float cp = fx * fx + fy * fy;

  return dx * (ey * cp - bp * fy) -
    dy * (ex * cp - bp * fx) +
    ap * (ex * fy - ey * fx) < 0;
}

void sotogawacheck() {
  int ccount = 0;
  int ebegin = 0;
  while (DLhalfedges[ebegin] != -1) ebegin += 1;
  int e1 = ebegin;
  while (1) {
    int ud = 1;
    int e0 = e1;
    e1 = nexthalfedge(e1);
    while (DLhalfedges[e1] != -1) {
      e1 = nexthalfedge(DLhalfedges[e1]);
      ccount += 1;
    }
    int trie0 = DLtriangles[e0],
      trie1 = DLtriangles[e1],
      trine = DLtriangles[nexthalfedge(e1)];
    if (orient(
      pos[trie0*2+0], pos[trie0*2+1],
      pos[trie1*2+0], pos[trie1*2+1],
      pos[trine*2+0], pos[trine*2+1])
    ) {
      int next = trianglenum;
      DLtriangles[next+0]=trine;
      DLtriangles[next+1]=trie1;
      DLtriangles[next+2]=trie0;
      trianglenum+=3;
      DLhalfedges[e0] = next + 1;
      DLhalfedges[e1] = next;
      DLhalfedges[next+0]=e1;
      DLhalfedges[next+1]=e0;
      DLhalfedges[next+0]=-1;
      if (e0 == ebegin) ebegin = next + 2;
      if (e1 == ebegin) break;
      e1 = next + 2;
      ud = 0;
    }
    if (ud && e1 == ebegin) break;
  }
}

void legalize() {
  for (int e = 0; e < trianglenum; e++) {
    int he = DLhalfedges[e];
    if (e >= he) continue;
    int tri0 = DLtriangles[e],
      tri1 = DLtriangles[he],
      tri2 = DLtriangles[taikaku(e)],
      tri3 = DLtriangles[taikaku(he)];
    if (!inCircle(
      pos[tri0*2+0], pos[tri0*2+1],
      pos[tri1*2+0], pos[tri1*2+1],
      pos[tri2*2+0], pos[tri2*2+1],
      pos[tri3*2+0], pos[tri3*2+1])
    ) continue;

    int t0 = triangleid(e), t1 = triangleid(he);

    DLtriangles[t0] = tri2;
    DLtriangles[t0 + 1] = tri3;
    DLtriangles[t0 + 2] = tri1;
    DLtriangles[t1] = tri3;
    DLtriangles[t1 + 1] = tri2;
    DLtriangles[t1 + 2] = tri0;

    int ohe0 = DLhalfedges[nexthalfedge(e)],
      ohe1 = DLhalfedges[prevhalfedge(e)],
      ohe2 = DLhalfedges[nexthalfedge(he)],
      ohe3 = DLhalfedges[prevhalfedge(he)];
    if (ohe0 != -1) DLhalfedges[ohe0] = t0 + 2;
    if (ohe1 != -1) DLhalfedges[ohe1] = t1 + 1;
    if (ohe2 != -1) DLhalfedges[ohe2] = t1 + 2;
    if (ohe3 != -1) DLhalfedges[ohe3] = t0 + 1;

    DLhalfedges[t0] = t1;
    DLhalfedges[t0 + 1] = ohe3;
    DLhalfedges[t0 + 2] = ohe0;
    DLhalfedges[t1] = t0;
    DLhalfedges[t1 + 1] = ohe1;
    DLhalfedges[t1 + 2] = ohe2;
  }
}

void rotationcheck() {
  for (int t = 0; t < trianglenum; t += 3) {
    int tri0 = DLtriangles[t],
      tri1 = DLtriangles[t + 1],
      tri2 = DLtriangles[t + 2];

    if (!orient(
      pos[tri0*2+0], pos[tri0*2+1],
      pos[tri1*2+0], pos[tri1*2+1],
      pos[tri2*2+0], pos[tri2*2+1])
    ) continue;

    //console.log(t);
    int he0 = DLhalfedges[t],
      he1 = DLhalfedges[t + 1],
      he2 = DLhalfedges[t + 2];

    int count = (he0 == -1) + (he1 == -1) + (he2 == -1);
    if (count == 0) {
      //console.log("count=0", t, t + 1, t + 2, tri0, tri1, tri2);
      continue;
    }
    if (count == 3) {
      //console.log("count=3", t, t + 1, t + 2, tri0, tri1, tri2);
      continue;
    }
    if (count == 2) {
      //console.log("count=2", t, t + 1, t + 2, tri0, tri1, tri2);
      continue;
    }

    if (he0 != -1) DLhalfedges[he0] = -1;
    if (he1 != -1) DLhalfedges[he1] = -1;
    if (he2 != -1) DLhalfedges[he2] = -1;
    trianglenum-=3;
    for(int i=t;i<trianglenum;i++){
      DLhalfedges[i]=DLhalfedges[i+3];
      DLtriangles[i]=DLtriangles[i+3];
    }
    for (int i = 0; i < trianglenum; i++) {
      if (DLhalfedges[i] >= t) { DLhalfedges[i] = DLhalfedges[i] - 3; }
    }
    t -= 3;
  }
}


void updateee() {
  rotationcheck();
  sotogawacheck();
  legalize();
}
void mover(float dist,float difx,float dify,int n,int o){
  if (dist < 100) {
    sepcnt[n]++;
    sepvec[n*2+0] -= difx / dist;
    sepvec[n*2+1] -= dify / dist;
  } else if (dist > 10000) {
    cohcnt[n]++;
    cohvec[n*2+0] += difx;
    cohvec[n*2+1] += dify;
  } else {
    alicnt[n]++;
    alivec[n*2+0] += ver[o*2+0];
    alivec[n*2+1] += ver[o*2+1];
  }
}

WASM_EXPORT
void update(){
  updateee();
  for (int i = 0; i < num; i++) {
    sepcnt[i] = 0;
    sepvec[i*2] = 0;
    sepvec[i*2+1] = 0;
    alicnt[i] = 0;
    alivec[i*2] = 0;
    alivec[i*2+1] = 0;
    cohcnt[i] = 0;
    cohvec[i*2] = 0;
    cohvec[i*2+1] = 0;
  }
  for (int t = 0; t < trianglenum; t += 3) {
    float difx0 = (pos[DLtriangles[t + 1]*2+0] - pos[DLtriangles[t]*2+0]), dify0 = (pos[DLtriangles[t + 1]*2+1] - pos[DLtriangles[t]*2+1]);
    float difx1 = (pos[DLtriangles[t + 2]*2+0] - pos[DLtriangles[t + 1]*2+0]), dify1 = (pos[DLtriangles[t + 2]*2+1] - pos[DLtriangles[t + 1]*2+1]);
    float difx2 = (pos[DLtriangles[t]*2+0] - pos[DLtriangles[t + 2]*2+0]), dify2 = (pos[DLtriangles[t]*2+1] - pos[DLtriangles[t + 2]*2+1]);
    mover(difx0 * difx0 + dify0 * dify0, difx0, dify0, DLtriangles[t], DLtriangles[t + 1]);
    mover(difx1 * difx1 + dify1 * dify1, difx1, dify1, DLtriangles[t + 1], DLtriangles[t + 2]);
    mover(difx2 * difx2 + dify2 * dify2, difx2, dify2, DLtriangles[t + 2], DLtriangles[t]);
  }
  for (int i = 0; i < num; i++) {
    if (sepcnt[i]) {
      ver[i*2+0] += (sepvec[i*2+0] / sepcnt[i]) * 1.0;
      ver[i*2+1] += (sepvec[i*2+1] / sepcnt[i]) * 1.0;
    }
    if (alicnt[i]) {
      ver[i*2+0] += (alivec[i*2+0] / alicnt[i] - ver[i*2+0]) * 0.1;
      ver[i*2+1] += (alivec[i*2+1] / alicnt[i] - ver[i*2+1]) * 0.1;
    }
    if (cohcnt[i]) {
      ver[i*2+0] += cohvec[i*2+0] / cohcnt[i] * 0.00001;
      ver[i*2+1] += cohvec[i*2+1] / cohcnt[i] * 0.00001;
    }
    float vers = sqrt(ver[i*2+0] * ver[i*2+0] + ver[i*2+1] * ver[i*2+1]);
    /*if (vers > 1000.0) {
      ver[i*2+0] *= 1000.0 / vers;
      ver[i*2+1] *= 1000.0 / vers;
      vers = 1000.0;
    }*/
    if (vers < 0.5) {
      ver[i*2+0] *= 0.5 / vers;
      ver[i*2+1] *= 0.5 / vers;
      vers = 0.5;
    }
  }
  for (int i = 0; i < num; i++) {
    pos[i*2] += ver[i*2];
    pos[i*2+1] += ver[i*2+1];

    if (pos[i*2] < 0) {
      pos[i*2] = 0;
      ver[i*2] = -ver[i*2];
    }
    if (pos[i*2] > width) {
      pos[i*2] = width;
      ver[i*2] = -ver[i*2];
    }

    if (pos[i*2+1] < 0) {
      pos[i*2+1] = 0;
      ver[i*2+1] = -ver[i*2+1];
    }
    if (pos[i*2+1] > height) {
      pos[i*2+1] = height;
      ver[i*2+1] = -ver[i*2+1];
    }
  }
}