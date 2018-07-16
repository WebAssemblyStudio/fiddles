#include <math.h>

#define WASM_EXPORT __attribute__((visibility("default"))) extern "C"

#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr

/*
 * Discrete Fast Fourier Transform based on the algorithm in
 * Numerical Recipes in C, slighly modified by removing the
 * insane 1 based array access.
 *
 * Takes the data pointer which contains nn pairs of doubles,
 * each pair represents a complex number (real-imaginary pairs),
 * and performs the discrete Fourier transformation on them if
 * isign is -1, and the inverse discrete Fourier transformation
 * if isign is 1, but in the case of the inverse transformation,
 * the result is not divided by nn, so it has to be done by the
 * caller afterwards.
 */
WASM_EXPORT
void dfft(float *data, int nn, int isign)
{
    int n,mmax,m,j,istep,i;
    float wtemp,wr,wpr,wpi,wi,theta;
    float tempr,tempi;
    n=nn << 1;
    j=0;
    for (i=0;i<n;i+=2) {
        if (j > i) {
            SWAP(data[j],data[i]);
            SWAP(data[j+1],data[i+1]);
        }
        m=n >> 1;
        while (m >= 2 && j >= m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
    mmax=2;
    while (n > mmax) {
        istep=mmax << 1;
        theta=isign*(6.28318530717959f/mmax);
        wtemp=sinf(0.5f*theta);
        wpr = -2.0f*wtemp*wtemp;
        wpi=sin(theta);
        wr=1.0f;
        wi=0.0f;
        for (m=0;m<mmax;m+=2) {
            for (i=m;i<n;i+=istep) {
                j=i+mmax;
                tempr=wr*data[j]-wi*data[j+1];
                tempi=wr*data[j+1]+wi*data[j];
                data[j]=data[i]-tempr;
                data[j+1]=data[i+1]-tempi;
                data[i] += tempr;
                data[i+1] += tempi;
            }
            wtemp = wr;
            wr=wr*wpr-wi*wpi+wr;
            wi=wi*wpr+wtemp*wpi+wi;
        }
        mmax=istep;
    }
}
#undef SWAP

WASM_EXPORT
void multidfft(float *data, int nn, int isign, int count) {
  while (count-- > 0) {
    dfft(data, nn, isign);
    data += nn << 1;
  }
}

