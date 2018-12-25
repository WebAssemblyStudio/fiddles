// #include <stdio.h>
#include <sys/uio.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))


#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif



WASM_EXPORT
unsigned char* autoHighlight(unsigned char* data, unsigned char* mmask, int width, int height, int expand, int mouseX, int mouseY) {

//  printf("params: %d %d %d %d %d\n", data, mmask, width, height, expand);
  //printf("test data: %d %d %d %d %d\n", data[0], data[1], data[2], data[3], data[4]);
  //printf("test mmask: %d %d %d %d %d\n", mmask[0], mmask[1], mmask[2], mmask[3], mmask[4]);
  //printf("test mmask 4*8+4: %d\n", mmask[4*8+4]);

	int sHeight = height-1;
	int sWidth = width-1;
	int sWidth2 = width-2;
	int off = width;

	int repeat = 1;
	int iterCount=0;
	int rptCnt = 1;
//  printf("rpt section\n");
	for(int rpt=0; rpt<rptCnt; ++rpt) {
		++iterCount;
		repeat = 0;
		// make a list of all border pixels
		int gList[256] = {0};
		int totalGs = 0;
//		for(int x=0; x<256; ++x) {
//			gList[x] = 0;
//		}
//    printf("for loop 1\n");
		for(int y=1; y<sHeight; ++y) {
			for(int x=1; x<sWidth; ++x) {
				int idx = y * off + x;
				if(mmask[idx]) {
					if(mmask[idx-1]==0){ ++gList[data[idx]];++totalGs;}
					else if(mmask[idx+1]==0){ ++gList[data[idx]];++totalGs;}
					else if(mmask[idx-off]==0){ ++gList[data[idx]];++totalGs;}
					else if(mmask[idx+off]==0){ ++gList[data[idx]];++totalGs;}
				}
			}
		}

    if(totalGs == 0) {
			//alert("Please highlight the object");
//      printf("exit - totalGs is 0 #1\n");
			return 0;
		}

		// remove outliers
	//	float minG = 1.0/255/2.1;
    int minG = (int)(1.0/255/2.1*totalGs);
		int newTotalGs = 0;
//    printf("for loop 2\n");
		for(int x=0; x<256; ++x) {
//      printf("x = %d, gList[x] = %d, totalGs = %d, newTotalGs = %d\n", x, gList[x], totalGs, newTotalGs);
			//if(minG > gList[x]/totalGs) {
      if(minG > gList[x]) {
				gList[x] = 0;
			} else {
				newTotalGs += gList[x];
			}
		}
		totalGs = newTotalGs;

		if(totalGs == 0) {
			//alert("Please highlight the object");
//      printf("exit - totalGs is 0 #2\n");
    //  printf("minG is %.2f\n", minG);
			return 0;
		}

		int countGs = 0;
		int gCutoff = 255;
		float avgG = 0;
		int stop = 0;
 //   printf("for loop 3\n");
		for(int x=0; x<256; ++x) {
			countGs += gList[x];
			avgG += gList[x]*x;
			if(countGs >= totalGs*.5 && !stop) {
				gCutoff = x;
				stop = 1;
			}
		}
		avgG /= totalGs;

		// find standard deviation
		float sqrDiff = 0;
//    printf("for loop 4\n");
		for(int x=0; x<256; ++x) {
			sqrDiff += (x-avgG)*(x-avgG)*gList[x];
		}
		float stdDevG = sqrt(sqrDiff/totalGs);
		stdDevG = (stdDevG*1.95 < 25) ? 25 : stdDevG*1.95;

//		expand = (expand + 1) % 4;
//    printf("for loop 5\n");
		for(int iter = 0; iter < 1 && expand == 3; ++iter) {

			// Expand mask down,right
//      printf("for loop 6\n");
			for(int y = 0; y < sHeight; ++y) {
				int idx = y * off;
//			for(int x = sWidth; x--; ++idx) {
        for(int x = 0; x<width; ++x, ++idx) {
					if(!mmask[idx]) {
						continue;
					}
          int thresh_off = (int)(log(abs(x-mouseX) + abs(y-mouseY))*2);
          thresh_off -= 2;
          thresh_off = (thresh_off < 0) ? 0 : thresh_off;
          int threshold = -4 - thresh_off;

					int sample = data[idx];
					if(sample < gCutoff) {
						if(mmask[idx+1] == 0) {
              int p4 = min(4, width-x);
							if(sample - data[idx+1] < threshold || sample - data[idx+p4] < threshold) {
								mmask[idx+1] = 255;
							}
						}
						if(mmask[idx+off] == 0) {
              int poff4 = min(4, height-y)*off;
							if(sample - data[idx+off] < threshold || sample - data[idx+poff4] < threshold) {
								mmask[idx+off] = 255;
							}
						}
					}
				}
			}
			
			// Expand mask up,left
//      printf("for loop 7\n");
			for(int y = sHeight; y > 0; --y) {
				int idx = y * off + sWidth;
			//	for(int x = sWidth; x--; --idx) {
        for(int x = sWidth; x>0; --x, --idx) {
					if(!mmask[idx]) {
						continue;
					}

          int thresh_off = (int)(log(abs(x-mouseX) + abs(y-mouseY))*2);
          thresh_off = min(thresh_off-2, 0);
          int threshold = -4 - thresh_off;    // -2??

					int sample = data[idx];
					if(sample < gCutoff) {
						if(mmask[idx-1] == 0) {
              int m4 = min(4, x);
							if(sample - data[idx-1] < threshold || sample - data[idx-m4] < threshold) {
								mmask[idx-1] = 255;
							}
						}
						if(mmask[idx-off] == 0) {
              int moff4 = min(4, y)*off;
							if(sample - data[idx-off] < threshold || sample - data[idx-moff4] < threshold) {
								mmask[idx-off] = 255;
							}
						}
					}  
				}
			}
		}
		unsigned char *maskChanges = (unsigned char *)malloc(width*height);
//    printf("for loop 8\n");
		for(int z=0; z<1; ++z) {	// expand borders if they're greater than a threshold (stdDevG)
		//	var maskChanges = [];		// TODO: this is no longer increased 1 by 1 so it becomes a sparse array! :(
			memset(maskChanges, 0, width*height);

//      printf("for loop 9\n");
		//	for(int y=0; y<sHeight; ++y) {
      for(int y=0; y<height; ++y) {
				int idx = y*off;		// right+down idx
        int yp1 = min(y+1, sHeight);
				int idx2 = (yp1)*off + sWidth;	// left+up idx
			//	for(int x=sWidth2; x--; ++idx, --idx2) {
        for(int x=0; x<width; ++x, ++idx, --idx2) {
          float stdDev_off1 = log(abs(x-mouseX) + abs(y-mouseY))/4.0;
          float stdDev_off2 = log(abs((sWidth-x)-mouseX) + abs(yp1-mouseY))/4.0;
          stdDev_off1 = max(stdDev_off1 - .5, 0);
          stdDev_off2 = max(stdDev_off1 - .5, 0);

          int p1 = (x < sWidth) ? 1 : 0;
          int poff = (y < sHeight) ? off : 0;
					if(!mmask[idx] && abs(data[idx]-gCutoff) > stdDevG+stdDev_off1 && (mmask[idx+p1] || mmask[idx+poff])) {		// check right and down
						maskChanges[idx] = 1;
						repeat = 1;
					}
          int m1 = (x > 0) ? 1 : 0;
          int moff = (y > 0) ? off : 0;
					if(!mmask[idx2] && abs(data[idx2]-gCutoff) > stdDevG+stdDev_off2 && (mmask[idx2-m1] || mmask[idx2-moff])) {	// check left and up
						maskChanges[idx2] = 1;
						repeat = 1;
					}
				}
			}

			//for(var idx=width*height-1; idx--;) {
	//		for(var idx=0; idx<width*(height-1); ++idx) {
	//			if(!mmask[idx] && Math.abs(data[idx]-gCutoff) > stdDevG && (mmask[idx-1] || mmask[idx+1] || mmask[idx-off] || mmask[idx+off])) {
	//				maskChanges[idx] = 1;
	//				//mmask[idx] = 1;
	//				repeat = 1;
	//			}
	//		}
			//for(var idx=width*height-1; idx--;) {
//      printf("for loop 10\n");
			for(int idx=0; idx<width*(height-1); ++idx) {
				if(maskChanges[idx] == 1) {
					mmask[idx]=255;
				}
			}
		}
		free(maskChanges);
	}

	// fill in holes
//  printf("for loop 11\n");
	for(int iter = 0; iter < 1; ++iter) {
		// Expand mask down,right
		for(int y = 0; y < sHeight; ++y) {
			int idx = y * off;
			for(int x = sWidth; x--; ++idx) {
				if(!mmask[idx]) {
					continue;
				}
				if(mmask[idx+1] == 0) {
					if(mmask[idx+2] || mmask[idx+8]) {
						mmask[idx+1] = 255;
					}
				}
				if(mmask[idx+off] == 0) {
					if(mmask[idx+off*2] || mmask[idx+off*8]) {
						mmask[idx+off] = 255;
					}
				}
			}
		}
			
		// Expand mask up,left
//    printf("for loop 12\n");
		for(int y = sHeight; y > 0; --y) {
			int idx = y * off + sWidth;
			for(int x = sWidth; x--; --idx) {
				if(!mmask[idx]) {
					continue;
				}
				if(mmask[idx-1] == 0) {
					if(mmask[idx-2] || mmask[idx-8]) {
						mmask[idx-1] = 255;
					}
				}
				if(mmask[idx-off] == 0) {
					if(mmask[idx-off*2] || mmask[idx-off*8]) {
						mmask[idx-off] = 255;
					}
				}
			}
		}
	}

	return mmask;

/*
	// alert("cutoff: "+gCutoff+"  stdDev: " + stdDevG+ "  iter: " +iterCount);

	// for(var i = width*height-1; i--;) {
	// 	mask[i*4] = mask[i*4+1] = mmask[i];
	// }
	// maskImg.data = mask;
	// c.putImageData(maskImg, 0, 0);
	// uploadMask(true, function(){}, false);
	// \$("#highlightHelper").hide();

	//pMsg = JSON.stringify(pMsg);

	//if(msg.useTransferable == 0) {
		var pMsg = new Object();
		pMsg.mask = mmask;
		postMessage(pMsg);
	//} else {
	//	var pMsg = new Uint8Array(mmask);
	//	webkitPostMessage(pMsg.buffer, [pMsg.buffer]);
	//}
*/
}









WASM_EXPORT
int main(void) {
  printf("Hello World\n");
  return 0;
}

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
