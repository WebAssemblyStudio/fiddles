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
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif


//float mxySensitivity = .5;
int sensitivity = 2;

unsigned char *maskChanges = 0; // = (unsigned char *)malloc(width*height);


WASM_EXPORT
unsigned char* autoHighlight(unsigned char* data, unsigned char* mmask, int width, int height, int expand, int mouseX, int mouseY) {

	expand = (expand + 1) % 4;	// 1+2 expand edges if new pixel is different from object, 3+4 expand edges if new pixel is similar to object (also in 3 expand into lighter areas)

	int sHeight = height-1;
	int sHeight2 = height-2;
	int sWidth = width-1;
	int sWidth2 = width-2;
	int off = width;

	// precalculate log values
	int logVals[500+500];
	int logVals2[500+500];
	if(1) {
		if(500+500 < width+height) {
			printf("Mask is too big? %d+%d > 500+500\n", width, height);
			return mmask;
		}
		int wh = width+height;
		for(int i=1; i<wh; ++i) {
			float v = log(i);
			logVals[i] = (int)(v)*sensitivity;
			logVals2[i] = (int)(v*2)*sensitivity;
		}
		logVals[0] = 0;
	}

	//int repeat = 1;
	int iterCount=0;
	int rptCnt = 2;
	for(int rpt=0; rpt<rptCnt; ++rpt) {
		++iterCount;
		//repeat = 0;
		// make a list of all border pixels
		int yStart = sHeight;
		int yEnd = 0;
		int gList[256] = {0};
		int totalGs = 0;
		int gListInner[256] = {0};
		int totalGsInner = 0;
		for(int y=1; y<sHeight; ++y) {
			int maskDetected = 0;
			for(int x=1; x<sWidth; ++x) {
				int idx = y * off + x;
				if(mmask[idx]) {
					maskDetected = 1;
					++gListInner[data[idx]];
					++totalGsInner;
					if(mmask[idx-1]==0 || mmask[idx+1]==0 || mmask[idx-off]==0 || mmask[idx+off]==0) {	// if any neighbor is not in the mask
						++gList[data[idx]];
						++totalGs;
					}
				}
			}
			if(maskDetected) {
				yStart = min(yStart, y-1);
				yEnd = max(yEnd, y+1);
			}
		}

		if(totalGs == 0) {
			return mmask;
		}

		// add area underneath mouse to bias objEstG
		if(1) {
			float objEstG1_f = 0;
			for(int i=1; i<256; ++i) {
				objEstG1_f += gListInner[i]*i;
			}
			objEstG1_f /= totalGsInner;


			int mYStart = max(0, mouseY-15);
			int mYEnd = min(height, mouseY+16);
			int mXStart = max(0, mouseX-15);
			int mXEnd = min(sWidth, mouseX+16);
			int incAmt = totalGsInner*.0002 + 5;
			for(int y=mYStart; y<mYEnd; ++y) {
				int idx = y*width + mXStart;
				for(int x=mXStart; x<mXEnd; ++x, ++idx) {
					gListInner[data[idx]] += incAmt;
					totalGsInner += incAmt;
				}
			}


			float objEstG2_f = 0;
			for(int i=1; i<256; ++i) {
				objEstG2_f += gListInner[i]*i;
			}
			objEstG2_f /= totalGsInner;
		}

		float objEstG_f = 0;
		float bgEstG_f = 0;
		for(int i=1; i<256; ++i) {
			objEstG_f += gListInner[i]*i;
			bgEstG_f += gList[i]*i;
		}
		objEstG_f /= totalGsInner;
		bgEstG_f /= totalGs;

		int objEstG = objEstG_f;

		// subtract portion inside highlight (improves standard deviation calculations)
		float scale = ((float)totalGs)/totalGsInner;
		if(expand < 2) {		// NOTE: when expand < 2, we expand the edges based on differences, when expand >= 2, we increment based on similarities
			scale *= 1.5;
		}
		for(int x=0; x<256; ++x) {
			int prevG = gList[x];
			int minus = (int)(gListInner[x]*scale);
			gList[x] = max(gList[x]-(int)(gListInner[x]*scale), 0);
			totalGs -= prevG - gList[x];
		}

		// remove outliers
		//int minG = max((int)(1.0/255/2.1*totalGs), 3);
		int minG = (int)(1.0/255/2.1*totalGs);
		int newTotalGs = 0;
		for(int x=0; x<256; ++x) {
			if(minG > gList[x]) {
				gList[x] = 0;
			} else {
				newTotalGs += gList[x];
			}
		}
		totalGs = newTotalGs;

		if(totalGs == 0) {
			return mmask;
		}

		float bg2EstG_f = 0;
		for(int x=1; x<256; ++x) {
			bg2EstG_f += gList[x]*x;
		}
		//printf("pre BG2: %d\n", (int)bg2EstG_f);
		bg2EstG_f /= totalGs;
		objEstG_f += (objEstG_f - bgEstG_f)*.05f;
		//printf("Obj: %d,	BG1: %d,	BG2: %d\n", (int)objEstG_f, (int)bgEstG_f, (int)bg2EstG_f);
		int objBGDiff = max(fabsf(objEstG_f - bgEstG_f)*2-20, 0);

		int countGs = 0;
		int gCutoff = 255;
		float avgG = 0;
		int stop = 0;
		for(int x=0; x<256; ++x) {
			countGs += gList[x];
			avgG += gList[x]*x;
			if(countGs >= totalGs*.5 && !stop) {		// TODO: investigate this!	I think gCutoff as used here might not work on black bgs
				gCutoff = x;
				stop = 1;
			}
		}
		avgG /= totalGs;

		// find standard deviation
		float sqrDiff = 0;
		for(int x=0; x<256; ++x) {
			sqrDiff += (x-avgG)*(x-avgG)*gList[x];
		}
		float stdDevG = sqrt(sqrDiff/totalGs);
		stdDevG = max(stdDevG*1.95, 25);
		float stdDevG2 = min(stdDevG*.5, 60);
		//printf("1stdDev: %d, sqrDiff: %d, totalGs: %d\n", (int)stdDevG, (int)sqrDiff, (int)totalGs);

		if(totalGs < 100) {
			stdDevG = stdDevG*4+50;
			stdDevG2 = 0;
		} else if(totalGs < 200) {
			stdDevG *= 2;
			stdDevG2 /= 2;
		} else if(totalGs < 400) {
			stdDevG *= 1.5;
			stdDevG2 /= 1.75;
		} else if(totalGs < 800) {
			stdDevG *= 1.2;
			stdDevG2 /= 1.2;
		} else if(totalGs > 1200) {
			stdDevG *= .8;
			stdDevG2 /= .8;
		}
		//printf("2stdDev: %d, sqrDiff: %d, totalGs: %d\n", (int)stdDevG, (int)sqrDiff, (int)totalGs);

		for(int iter=0; iter<3 && expand==3; ++iter) {

			// Expand mask down,right (into brighter areas)
			int yS = max(0, yStart);
			int yE = min(sHeight, yEnd+1);
			for(int y=yE; y>=yS; --y) {	 // NOTE: yes yE and yS are reversed for easier comprehension		//for(int y=sHeight; y>=0; --y) {
				int idx = y * off + sWidth;
				int poff1 = min(1, sHeight-y)*off;
				int poff4 = min(4, sHeight-y)*off;
				int *logVals2_pY = logVals2 + abs(y-mouseY);
				for(int x=sWidth; x>=0; --x, --idx) {
					if(!mmask[idx]) {
						continue;
					}

					int thresh_off = logVals2_pY[abs(x-mouseX)];	//int thresh_off = logVals2[abs(x-mouseX) + abs(y-mouseY)];	 //int thresh_off = (int)(log(abs(x-mouseX) + abs(y-mouseY))*2)*sensitivity;
					thresh_off = max(thresh_off-2, 0);
					int threshold = -4 - thresh_off;

					int d_idx = data[idx];
					int thresh_min_samp = threshold - d_idx;
					if(d_idx < gCutoff) {
						int p1 = min(1, sWidth-x);
						if(mmask[idx+p1] == 0) {
							int p4 = min(4, sWidth-x);
							if(d_idx - data[idx+p1] < threshold || d_idx - data[idx+p4] < threshold) {				// compare current pixel to right adjacent pixel and right+4 pixel
								mmask[idx+p1] = 255;			// set the pixel to the right to 255
							}
						}
						if(mmask[idx+poff1] == 0) {
							if(d_idx - data[idx+poff1] < threshold || d_idx - data[idx+poff4] < threshold) {	// compare current pixel to pixel beneath it and pixel below+4
								mmask[idx+poff1] = 255;
							}
						}
					}
				}
			}

			yStart = max(yStart-1, 0);	// TODO: determine if it's more efficient to assume that we expanded by one or to actually go through the motions to calculate if we did

			// Expand mask up,left (into brighter areas)
			yS = max(1, yStart);
			yE = min(height, yEnd+1);
			for(int y=yS; y<yE; ++y) {
			//for(int y=1; y<height; ++y) {
				int idx = y * off;
				int moff1 = min(1, y)*off;
				int moff4 = min(4, y)*off;
				int *logVals2_pY = logVals2 + abs(y-mouseY);
				for(int x=0; x<width; ++x, ++idx) {
					if(!mmask[idx]) {
						continue;
					}

					int thresh_off = logVals2_pY[abs(x-mouseX)];	//int thresh_off = logVals2[abs(x-mouseX) + abs(y-mouseY)];	 //int thresh_off = (int)(log(abs(x-mouseX) + abs(y-mouseY))*2)*sensitivity;
					thresh_off = max(thresh_off-2, 0);
					int threshold = -4 - thresh_off;		// -2??

					int d_idx = data[idx];
					if(d_idx < gCutoff) {
						int m1 = min(1, x);
						if(mmask[idx-m1] == 0) {
							int m4 = min(4, x);
							if(d_idx - data[idx-m1] < threshold || d_idx - data[idx-m4] < threshold) {
								mmask[idx-m1] = 255;
							}
						}
						if(mmask[idx-moff1] == 0) {
							if(d_idx - data[idx-moff1] < threshold || d_idx - data[idx-moff4] < threshold) {
								mmask[idx-moff1] = 255;
							}
						}
					}
				}
			}
			yEnd = min(yEnd+1, sHeight);	// TODO: determine if it's more efficient to assume that we expanded by one or to actually go through the motions to calculate if we did
		}

		//unsigned char *maskChanges = (unsigned char *)malloc(width*height);
		if(maskChanges == 0) {
			maskChanges = (unsigned char *)malloc(width*height);
			memset(maskChanges, 0, width*height);
		}
		for(int z=0; z<1; ++z) {
			// expand borders if they're greater than a threshold (stdDevG)
			int yS = max(0, yStart);
			int yE = min(height, yEnd+1);
			for(int y=yS; y<yE; ++y) {			//for(int y=0; y<height; ++y) {
				int idx = y*off;		// right+down idx
				int *logVals_pY = logVals + abs(y-mouseY);
				for(int x=0; x<width; ++x, ++idx) {			//for(int x=0; x<width; ++x, ++idx) {
					if(!mmask[idx]) {
						float stdDev_off = logVals_pY[abs(x-mouseX)];	 //float stdDev_off1 = logVals[abs(x-mouseX) + abs(y-mouseY)];	 //float stdDev_off1 = log(abs(x-mouseX) + abs(y-mouseY))*sensitivity;
						stdDev_off = max(stdDev_off - .5, 0);

						int p1 = (x < sWidth) ? 1 : 0;
						int poff = (y < sHeight) ? off : 0;
						int m1 = (x > 0) ? 1 : 0;
						int moff = (y > 0) ? off : 0;
						if(expand < 2) {
							if(abs(data[idx]-gCutoff) > stdDevG+stdDev_off && (mmask[idx+p1] || mmask[idx+poff])) {
										maskChanges[idx] = 1;
								//repeat = 1;
							} else if(abs(data[idx]-gCutoff) > stdDevG+stdDev_off && (mmask[idx-m1] || mmask[idx-moff])) {
								maskChanges[idx] = 1;
								//repeat = 1;
							}
						} else {
							unsigned char d_idx = data[idx];
							if((abs(d_idx-gCutoff) > stdDevG+stdDev_off || abs(d_idx - objEstG)*4 < stdDevG2-stdDev_off) && abs(d_idx - objEstG) < stdDevG2+objBGDiff-stdDev_off && (mmask[idx+p1] || mmask[idx+poff])) {		// check right and down
								maskChanges[idx] = 1;
								//repeat = 1;
							} else if((abs(d_idx-gCutoff) > stdDevG+stdDev_off || abs(d_idx - objEstG)*4 < stdDevG2-stdDev_off) && abs(d_idx - objEstG) < stdDevG2+objBGDiff-stdDev_off && (mmask[idx-m1] || mmask[idx-moff])) {	// check left and up
								maskChanges[idx] = 1;
								//repeat = 1;
							}
						}
					}
				}
			}

			// check all borders to see if we should expand one beyond (from object pixel to bg pixel)
			if(expand == 0) {
				int yS = max(0, yStart);
				int yE = min(height, yEnd+1);
				for(int y=yS; y<yE; ++y) {		//for(int y=0; y<height; ++y) {
					int idx = y * off;
					for(int x=0; x<width; ++x, ++idx) {
						unsigned char d_idx = data[idx];
						if(mmask[idx] && abs(d_idx-objEstG) < stdDevG2) { // TODO: determine if putting the second part of this if statement here makes this faster
						//if(mmask[idx]) {
							int p1 = (x < sWidth) ? 1 : 0;
							int m1 = (x > 1) ? 1 : 0;
							int p1off = (y < sHeight) ? off : 0;
							int m1off = (y > 1) ? off : 0;

							if(!mmask[idx+p1] && abs(d_idx-data[idx+p1]) > stdDevG) {
								maskChanges[idx+p1] = 1;
							}
							if(!mmask[idx-m1] && abs(d_idx-data[idx-m1]) > stdDevG) {
								maskChanges[idx-m1] = 1;
							}
							if(!mmask[idx+p1off] && abs(d_idx-data[idx+p1off]) > stdDevG) {
								maskChanges[idx+p1off] = 1;
							}
							if(!mmask[idx-m1off] && abs(d_idx-data[idx-m1off]) > stdDevG) {
								maskChanges[idx-m1off] = 1;
							}
							// This is the original version, where I don't check the data vs stdDevG2 before everything else
							/*
							if(!mmask[idx+p1] && abs(data[idx]-data[idx+p1]) > stdDevG && abs(data[idx]-objEstG) < stdDevG2) {
								maskChanges[idx+p1] = 1;
							}
							if(!mmask[idx-m1] && abs(data[idx]-data[idx-m1]) > stdDevG && abs(data[idx]-objEstG) < stdDevG2) {
								maskChanges[idx-m1] = 1;
							}
							if(!mmask[idx+p1off] && abs(data[idx]-data[idx+p1off]) > stdDevG && abs(data[idx]-objEstG) < stdDevG2) {
								maskChanges[idx+p1off] = 1;
							}
							if(!mmask[idx-m1off] && abs(data[idx]-data[idx-m1off]) > stdDevG && abs(data[idx]-objEstG) < stdDevG2) {
								maskChanges[idx-m1off] = 1;
							}
							*/
						}
					}
				}
			}

			// apply maskChanges
			if(1) {
				int yS = max(0, yStart-1);
				int yE = min(height, yEnd+1);
				int idxStart = yS*width;
				int idxEnd = yE*width;
				for(int idx=idxStart; idx<idxEnd; ++idx) {	//for(int idx=0; idx<width*height; ++idx) {
					if(maskChanges[idx]==1) {
						maskChanges[idx] = 0;
						mmask[idx] = 255;
					}
				}
			}
		}

		//free(maskChanges);
	}

	// fill in holes
	int off2 = off*2;
	for(int iter = 0; iter < 1; ++iter) {
		// Expand mask down,right
		for(int y=0; y<sHeight2; ++y) {
			int idx = y * off;
			for(int x=0; x<sWidth2; ++x, ++idx) {
				if(!mmask[idx]) {
					continue;
				}
				if(mmask[idx+1] == 0) {
					int p8 = min(sWidth-x, 8);
					if(mmask[idx+2] || mmask[idx+p8]) {
						mmask[idx+1] = 255;
					}
				}
				if(mmask[idx+off] == 0) {
					int poff8 = min(sHeight-y, 8)*off;
					if(mmask[idx+off2] || mmask[idx+poff8]) {
						mmask[idx+off] = 255;
					}
				}
			}
		}

		// Expand mask up,left
		for(int y=sHeight; y>1; --y) {
			int idx = y * off + sWidth;
			for(int x=sWidth; x>1; --x, --idx) {
				if(!mmask[idx]) {
					continue;
				}
				if(mmask[idx-1] == 0) {
					int m8 = min(x, 8);
					if(mmask[idx-2] || mmask[idx-m8]) {
						mmask[idx-1] = 255;
					}
				}
				if(mmask[idx-off] == 0) {
					int moff8 = min(y, 8)*off;
					if(mmask[idx-off2] || mmask[idx-moff8]) {
						mmask[idx-off] = 255;
					}
				}
			}
		}

	}


	// fill in corners		TODO: change into filling in all edges!
	if(mmask[0] == 0 && mmask[1] && mmask[off]) {
		mmask[0] = 255;
	}
	if(mmask[sWidth] == 0 && mmask[sWidth-1] && mmask[sWidth+off]) {
		mmask[sWidth] = 255;
	}
	if(mmask[width*sHeight] == 0 && mmask[width*sHeight+1] && mmask[width*sHeight-off]) {
		mmask[width*sHeight] = 255;
	}
	if(mmask[width*height-1] == 0 && mmask[width*height-2] && mmask[width*height-1-off]) {
		mmask[width*height-1] = 255;
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