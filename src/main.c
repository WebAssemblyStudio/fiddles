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


WASM_EXPORT
unsigned char* autoHighlight(unsigned char* data, unsigned char* mmask, int width, int height, int expand, int mouseX, int mouseY) {

  printf("Mouse XY: %d %d\n", mouseX, mouseY);

//	printf("params: %d %d %d %d %d\n", data, mmask, width, height, expand);
	//printf("test data: %d %d %d %d %d\n", data[0], data[1], data[2], data[3], data[4]);
	//printf("test mmask: %d %d %d %d %d\n", mmask[0], mmask[1], mmask[2], mmask[3], mmask[4]);
	//printf("test mmask 4*8+4: %d\n", mmask[4*8+4]);

	int sHeight = height-1;
	int sHeight2 = height-2;
	int sWidth = width-1;
	int sWidth2 = width-2;
	int off = width;

	int repeat = 1;
	int iterCount=0;
	int rptCnt = 2;		// TODO: revert to 1??
	//printf("rpt section\n");
	for(int rpt=0; rpt<rptCnt; ++rpt) {
		++iterCount;
		repeat = 0;
		// make a list of all border pixels
		int gList[256] = {0};
		int totalGs = 0;
		int gListInner[256] = {0};
		int totalGsInner = 0;
//		for(int x=0; x<256; ++x) {
//			gList[x] = 0;
//		}
//		printf("for loop 1\n");
		for(int y=1; y<sHeight; ++y) {
			for(int x=1; x<sWidth; ++x) {
				int idx = y * off + x;
				if(mmask[idx]) {
					++gListInner[data[idx]];
					++totalGsInner;
					if(mmask[idx-1]==0 || mmask[idx+1]==0 || mmask[idx-off]==0 || mmask[idx+off]==0) {	// if any neighbor is not in the mask
						++gList[data[idx]];
						++totalGs;
					}
				}
			}
		}

		if(totalGs == 0) {
    //if(totalGs < 100) {
			//alert("Please highlight the object");
			//printf("exit - totalGs is 0 #1\n");
      printf("Oh no!1 - %d\n", totalGs);
      return mmask;
			//return 0;
		}


    // TODO: try adding to gListInner first... if that doesn't seem to work right, try just modifying objEstG_f/objEstG directly
    // add area underneath mouse to bias objEstG
    if(1) {
      float objEstG1_f = 0;
      for(int i=1; i<256; ++i) {
        objEstG1_f += gListInner[i]*i;
      }
      objEstG1_f /= totalGsInner;
		  printf("Obj Est 1: %d\n", (int)objEstG1_f);


      int mYStart = max(0, mouseY-15);
      int mYEnd = min(height, mouseY+16);
      int mXStart = max(0, mouseX-15);
      int mXEnd = min(sWidth, mouseX+16);
      int incAmt = totalGsInner*.0002 + 5;
      printf("Mouse x: %d to %d, Mouse y: %d to %d\n", mXStart, mXEnd, mYStart, mYEnd);
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
		  printf("Obj Est 2: %d\n", (int)objEstG2_f);
    }

		float objEstG_f = 0;
		float bgEstG_f = 0;
		for(int i=1; i<256; ++i) {
			objEstG_f += gListInner[i]*i;
			bgEstG_f += gList[i]*i;
		}
		//printf("Pre Obj: %d,  Pre BG1: %d\n", (int)objEstG_f, (int)bgEstG_f);
		objEstG_f /= totalGsInner;
		bgEstG_f /= totalGs;

		int objEstG = objEstG_f;

    // subtract portion inside highlight (improves standard deviation calculations)
    ///*
    float scale = ((float)totalGs)/totalGsInner;
    if(expand < 2) {
      scale *= 1.5;
    }
    for(int x=0; x<256; ++x) {
      int prevG = gList[x];
      int minus = (int)(gListInner[x]*scale);
      gList[x] = max(gList[x]-(int)(gListInner[x]*scale), 0);
      totalGs -= prevG - gList[x];
    //  if(gList[x] >=3 ){
        //printf("%d: %d - %d (%d) = %d\n", x, prevG, minus, gListInner[x], gList[x]);
    //  }
    }
    //*/

		// remove outliers
	//	float minG = 1.0/255/2.1;
		//int minG = max((int)(1.0/255/2.1*totalGs), 3);
		int minG = (int)(1.0/255/2.1*totalGs);
		int newTotalGs = 0;
		//printf("for loop 2\n");
		for(int x=0; x<256; ++x) {
			//printf("x = %d, gList[x] = %d, totalGs = %d, newTotalGs = %d\n", x, gList[x], totalGs, newTotalGs);
			//if(minG > gList[x]/totalGs) {
			if(minG > gList[x]) {
				gList[x] = 0;
			} else {
				newTotalGs += gList[x];
				//printf("%d: %d (%d)\n", x, gList[x], gListInner[x]);
			}
		}
		totalGs = newTotalGs;

		if(totalGs == 0) {
    //if(totalGs < 100) {
			//alert("Please highlight the object");
			//printf("exit - totalGs is 0 #2\n");
			//printf("minG is %.2f\n", minG);
      printf("Oh no!2 - %d\n", totalGs);
      return mmask;
			//return 0;
		}

		float bg2EstG_f = 0;
		for(int x=1; x<256; ++x) {
			bg2EstG_f += gList[x]*x;
		}
		printf("pre BG2: %d\n", (int)bg2EstG_f);
		bg2EstG_f /= totalGs;
    objEstG_f += (objEstG_f - bgEstG_f)*.05f;
		printf("Obj: %d,  BG1: %d,  BG2: %d\n", (int)objEstG_f, (int)bgEstG_f, (int)bg2EstG_f);
		int objBGDiff = max(fabsf(objEstG_f - bgEstG_f)*2-20, 0);
  //  if(expand == 1) {
  //    objBGDiff *= 4;
  //  }

		int countGs = 0;
		int gCutoff = 255;
		float avgG = 0;
		int stop = 0;
		//printf("for loop 3\n");
		for(int x=0; x<256; ++x) {
			countGs += gList[x];
			avgG += gList[x]*x;
			if(countGs >= totalGs*.5 && !stop) {		// TODO: investigate this!  I think gCutoff as used here might not work on black bgs
				gCutoff = x;
				stop = 1;
			}
		}
		avgG /= totalGs;

		// find standard deviation
		float sqrDiff = 0;
		//printf("for loop 4\n");
		for(int x=0; x<256; ++x) {
			sqrDiff += (x-avgG)*(x-avgG)*gList[x];
		}
		float stdDevG = sqrt(sqrDiff/totalGs);
		//stdDevG = (stdDevG*1.95 < 25) ? 25 : stdDevG*1.95;
		//stdDevG = min(stdDevG*1.95, 25);
		//stdDevG = max(stdDevG*1.95, 25);
		stdDevG = max(stdDevG*1.95, 25);
    float stdDevG2 = min(stdDevG*.5, 60);
		//stdDevG = max(stdDevG, 128);
		printf("1stdDev: %d, sqrDiff: %d, totalGs: %d\n", (int)stdDevG, (int)sqrDiff, (int)totalGs);

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
		printf("2stdDev: %d, sqrDiff: %d, totalGs: %d\n", (int)stdDevG, (int)sqrDiff, (int)totalGs);

		//expand = (expand + 1) % 4;
		//printf("for loop 5\n");
		for(int iter = 0; iter < 3 && expand == 3; ++iter) {
		//for(int iter=0; iter<0; ++iter) {

			// Expand mask down,right (into brighter areas)
			//printf("for loop 6\n");
			//for(int y = 0; y < sHeight; ++y) {
			//for(int y=sHeight2; y>=0; --y) {
			for(int y=sHeight; y>=0; --y) {
				//int idx = y * off;
				int idx = y * off + sWidth;
				int poff1 = min(1, sHeight-y)*off;
				int poff4 = min(4, sHeight-y)*off;

				//for(int x = sWidth; x--; ++idx) {
				//for(int x = 0; x<width; ++x, ++idx) {
				//for(int x = 0; x<swidth; ++x, ++idx) {
				for(int x=sWidth; x>=0; --x, --idx) {		// TODO: revert to THIS
				//for(int x = sWidth; x--; --idx) {					// TODO: THIS IS WRONG
					if(!mmask[idx]) {
						continue;
					}
					int thresh_off = (int)(log(abs(x-mouseX) + abs(y-mouseY))*2)*sensitivity;
					//thresh_off -= 2;
					//thresh_off = (thresh_off < 0) ? 0 : thresh_off;
					thresh_off = max(thresh_off-2, 0);					// TODO: replace the above two lines with this
					int threshold = -4 - thresh_off;

					int sample = data[idx];
					if(sample < gCutoff) {
						int p1 = min(1, sWidth-x);
						if(mmask[idx+p1] == 0) {
							int p4 = min(4, sWidth-x);
							if(sample - data[idx+p1] < threshold || sample - data[idx+p4] < threshold) {				// compare current pixel to right adjacent pixel and right+4 pixel
								mmask[idx+p1] = 255;			// set the pixel to the right to 255
							}
						}
						if(mmask[idx+poff1] == 0) {
							//int poff4 = min(4, sHeight-y)*off;
							if(sample - data[idx+poff1] < threshold || sample - data[idx+poff4] < threshold) {	// compare current pixel to pixel beneath it and pixel below+4
								mmask[idx+poff1] = 255;
							}
						}
					}
				}
			}

			// Expand mask up,left (into brighter areas)
			//printf("for loop 7\n");
			//for(int y = sHeight; y > 0; --y) {
			for(int y=1; y<height; ++y) {
				//int idx = y * off + sWidth;
				int idx = y * off;
				int moff1 = min(1, y)*off;
				int moff4 = min(4, y)*off;
				//for(int x = sWidth; x--; --idx) {
				//for(int x = sWidth; x>0; --x, --idx) {
				for(int x=0; x<width; ++x, ++idx) {
					if(!mmask[idx]) {
						continue;
					}

					int thresh_off = (int)(log(abs(x-mouseX) + abs(y-mouseY))*2)*sensitivity;
					//int thresh_off = (int)(log(abs(x-mouseX))*2)*sensitivity;
					thresh_off = max(thresh_off-2, 0);
					//thresh_off = min(thresh_off-2, 0);		// TODO: revert to line above!  this should be a max, not a min!
					int threshold = -4 - thresh_off;		// -2??

					int sample = data[idx];
					if(sample < gCutoff) {
						int m1 = min(1, x);
						if(mmask[idx-m1] == 0) {
							int m4 = min(4, x);
							if(sample - data[idx-m1] < threshold || sample - data[idx-m4] < threshold) {
								mmask[idx-m1] = 255;
							}
						}
						if(mmask[idx-moff1] == 0) {
							//int moff4 = min(4, y)*off;
							if(sample - data[idx-moff1] < threshold || sample - data[idx-moff4] < threshold) {
								mmask[idx-moff1] = 255;
							}
						}
					}
				}
			}
		}

		unsigned char *maskChanges = (unsigned char *)malloc(width*height);
		//printf("for loop 8\n");
		for(int z=0; z<1; ++z) {	// expand borders if they're greater than a threshold (stdDevG)
			//var maskChanges = [];		// TODO: this is no longer increased 1 by 1 so it becomes a sparse array! :(
			memset(maskChanges, 0, width*height);

			//printf("for loop 9\n");
			//for(int y=0; y<sHeight; ++y) {
			for(int y=0; y<height; ++y) {
				int idx = y*off;		// right+down idx
				//int yp1 = min(y+1, sHeight);		// TODO: remove this line - it shouldn't be used
				//int idx2 = (yp1)*off + sWidth;	// left+up idx
				int idx2 = y*off + sWidth;	// left+up idx
				//for(int x=sWidth2; x--; ++idx, --idx2) {
				for(int x=0; x<width; ++x, ++idx, --idx2) {
					float stdDev_off1 = log(abs(x-mouseX) + abs(y-mouseY))*sensitivity;
					//float stdDev_off2 = log(abs((sWidth-x)-mouseX) + abs(yp1-mouseY))*sensitivity;		// NOTE: only x is reversed
					//float stdDev_off2 = log(abs((sWidth-x)-mouseX) + abs(yp1-mouseY))*sensitivity;
					float stdDev_off2 = log(abs((sWidth-x)-mouseX) + abs(y-mouseY))*sensitivity;		// NOTE: only x is reversed       TODO: this is the correct line!  Not the one above!
					//float stdDev_off2 = log(abs((sWidth-x)-mouseX))*sensitivity;		// NOTE: only x is reversed
					stdDev_off1 = max(stdDev_off1 - .5, 0);
					//stdDev_off2 = max(stdDev_off1 - .5, 0);		// TODO: revert re-introduced bug!  off2, not off1!
					stdDev_off2 = max(stdDev_off2 - .5, 0);

					int p1 = (x < sWidth) ? 1 : 0;
					int poff = (y < sHeight) ? off : 0;
          if(expand < 2) {
            //if(!mmask[idx] && (abs(data[idx]-gCutoff) > stdDevG+stdDev_off1 || abs(data[idx] - objEstG)*4 < stdDevG2-stdDev_off1) && abs(data[idx] - objEstG) < stdDevG2+objBGDiff-stdDev_off1 && (mmask[idx+p1] || mmask[idx+poff])) {		// check right and down
            //if(!mmask[idx] && abs(data[idx]-gCutoff) > stdDevG+stdDev_off1 && (mmask[idx+p1] || mmask[idx+poff])) {		// check right and down
            if(!mmask[idx] && abs(data[idx]-gCutoff) > stdDevG+stdDev_off1 && (mmask[idx+p1] || mmask[idx+poff])) {			// TODO: revert to the line two above!
              maskChanges[idx] = 1;
              repeat = 1;
            }
            int m1 = (x < sWidth) ? 1 : 0;		// NOTE: this is backwards because idx2 is in reverse x-wise
            //int m1 = (x > 0) ? 1 : 0;			// TODO: this is wrong!  Use the line above!
            int moff = (y > 0) ? off : 0;
            //if(!mmask[idx2] && (abs(data[idx2]-gCutoff) > stdDevG+stdDev_off2 || abs(data[idx2] - objEstG)*4 < stdDevG2-stdDev_off2) && abs(data[idx2] - objEstG) < stdDevG2+objBGDiff-stdDev_off2 && (mmask[idx2-m1] || mmask[idx2-moff])) {	// check left and up
            //if(!mmask[idx2] && abs(data[idx2]-gCutoff) > stdDevG+stdDev_off2 && (mmask[idx2-m1] || mmask[idx2-moff])) {	// check left and up
            if(!mmask[idx2] && abs(data[idx2]-gCutoff) > stdDevG+stdDev_off2 && (mmask[idx2-m1] || mmask[idx2-moff])) {		// TODO: revert to the line two above!
              maskChanges[idx2] = 1;
              repeat = 1;
            }
          } else {
            if(!mmask[idx] && (abs(data[idx]-gCutoff) > stdDevG+stdDev_off1 || abs(data[idx] - objEstG)*4 < stdDevG2-stdDev_off1) && abs(data[idx] - objEstG) < stdDevG2+objBGDiff-stdDev_off1 && (mmask[idx+p1] || mmask[idx+poff])) {		// check right and down
            //if(!mmask[idx] && abs(data[idx]-gCutoff) > stdDevG+stdDev_off1 && (mmask[idx+p1] || mmask[idx+poff])) {		// check right and down
            //if(!mmask[idx] && abs(data[idx]-gCutoff) > stdDevG+stdDev_off1 && (mmask[idx+p1] || mmask[idx+poff])) {			// TODO: revert to the line two above!
              maskChanges[idx] = 1;
              repeat = 1;
            }
            int m1 = (x < sWidth) ? 1 : 0;		// NOTE: this is backwards because idx2 is in reverse x-wise
            //int m1 = (x > 0) ? 1 : 0;			// TODO: this is wrong!  Use the line above!
            int moff = (y > 0) ? off : 0;
            if(!mmask[idx2] && (abs(data[idx2]-gCutoff) > stdDevG+stdDev_off2 || abs(data[idx2] - objEstG)*4 < stdDevG2-stdDev_off2) && abs(data[idx2] - objEstG) < stdDevG2+objBGDiff-stdDev_off2 && (mmask[idx2-m1] || mmask[idx2-moff])) {	// check left and up
            //if(!mmask[idx2] && abs(data[idx2]-gCutoff) > stdDevG+stdDev_off2 && (mmask[idx2-m1] || mmask[idx2-moff])) {	// check left and up
            //if(!mmask[idx2] && abs(data[idx2]-gCutoff) > stdDevG+stdDev_off2 && (mmask[idx2-m1] || mmask[idx2-moff])) {		// TODO: revert to the line two above!
              maskChanges[idx2] = 1;
              repeat = 1;
            }
          }
				}
			}


      // check all borders to see if we should expand one beyond (from object pixel to bg pixel)
      //unsigned char *maskChanges = (unsigned char *)malloc(width*height);
      //memset(maskChanges, 0, width*height);
      for(int y=0; y<height; ++y) {
        int idx = y * off;
        for(int x=0; x<width; ++x, ++idx) {
          if(mmask[idx]) {
            int p1 = (x < sWidth) ? 1 : 0;
            int m1 = (x > 1) ? 1 : 0;
            int p1off = (y < sHeight) ? off : 0;
            int m1off = (y > 1) ? off : 0;
            if(!mmask[idx+p1] && abs(data[idx]-data[idx+p1]) > stdDevG && abs(data[idx]-objEstG) < stdDevG2) {
            //if(!mmask[idx+p1] && abs(data[idx]-data[idx+p1]) > stdDevG*0) {
              //printf("1 %d (%d,%d) = 255\n", idx+p1, x+1, y);
              maskChanges[idx+p1] = 1;
            }
            if(!mmask[idx-m1] && abs(data[idx]-data[idx-m1]) > stdDevG && abs(data[idx]-objEstG) < stdDevG2) {
            //if(!mmask[idx-m1] && abs(data[idx]-data[idx-m1]) > stdDevG*0) {
              //printf("2 %d (%d,%d) = 255\n", idx+p1, x-1, y);
              maskChanges[idx-m1] = 1;
            }
            if(!mmask[idx+p1off] && abs(data[idx]-data[idx+p1off]) > stdDevG && abs(data[idx]-objEstG) < stdDevG2) {
            //if(!mmask[idx+p1off] && abs(data[idx]-data[idx+p1off]) > stdDevG*0) {
              //printf("3 %d (%d,%d) = 255\n", idx+p1, x, y+1);
              maskChanges[idx+p1off] = 1;
            }
            if(!mmask[idx-m1off] && abs(data[idx]-data[idx-m1off]) > stdDevG && abs(data[idx]-objEstG) < stdDevG2) {
            //if(!mmask[idx-m1off] && abs(data[idx]-data[idx-m1off]) > stdDevG*0) {
              //printf("4 %d (%d,%d) = 255\n", idx+p1, x, y-1);
              maskChanges[idx-m1off] = 1;
            }
          }
        }
      }/*
      for(int idx=0; idx<width*height; ++idx) {
        if(maskChanges[idx] == 1) {
          mmask[idx]=255;
        }
      }
      free(maskChanges);*/

			//for(var idx=width*height-1; idx--;) {
	//		for(var idx=0; idx<width*(height-1); ++idx) {
	//			if(!mmask[idx] && Math.abs(data[idx]-gCutoff) > stdDevG && (mmask[idx-1] || mmask[idx+1] || mmask[idx-off] || mmask[idx+off])) {
	//				maskChanges[idx] = 1;
	//				//mmask[idx] = 1;
	//				repeat = 1;
	//			}
	//		}
			//for(var idx=width*height-1; idx--;) {
//			printf("for loop 10\n");
			//for(int idx=0; idx<width*(height-1); ++idx) {
			for(int idx=0; idx<width*height; ++idx) {
				if(maskChanges[idx] == 1) {
					mmask[idx]=255;
				}
			}
		}
		free(maskChanges);
	}

	// fill in holes
//	printf("for loop 11\n");
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
//		printf("for loop 12\n");
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


	// fill in corners    TODO: change into filling in all edges!
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