#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int Xa(int c,int d,int e) {
  int a[100] = {0};
  int b[100] = {0};
    c = c | 0;
    d = d | 0;
    e = e | 0;
    int f = 0,
    g = 0,
    h = 0;
    if (!c) {
        d = 2;
        return (d | 0) ;
    }
    do{
    switch (d << 16 >> 16) {
    case 1:
        {
            h = c + 4 | 0;
            f = b[h >> 1] & -3;
            b[h >> 1] = f;
            c = c + 6 | 0;
            b[c >> 1] = 0;
            c = h;
            break;
        }
    case 2:
        {
            h = c + 4 | 0;
            f = b[h >> 1] & -2;
            b[h >> 1] = f;
            g = c + 6 | 0;
            if (!e) {
                c = h;
                f = b[h >> 1] | 0;
                break;
            } else {
                c = e;
                e = g + 16 | 0;
                do {
                    a[g >> 0] = a[c >> 0] | 0;
                    g = g + 1 | 0;
                    c = c + 1 | 0;
                } while (( g | 0 ) < (e | 0));
                c = h;
                break;
            }
        }
    default:
        {
            d = 3;
            return (d | 0);
        }
    }
    }
    while (0);
    b[c >> 1] = f | d;
    d = 0;
    return (d | 0);
}
int main() {
  int i = 10;
  int i1 = 100;
  int i2 = 20;
  int i3 = 90;
  int i4 = -1;
  int i5 = -11;
  int m = 0;
  m += i + i1 + i2 + i3;
  m += i3 + i4 + i5;
  m += i4 + i2 + i1;
  m = Xa(100,30,30);
  return m;
}

