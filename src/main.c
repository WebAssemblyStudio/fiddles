#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT


#include <cv.h>
#include <cvcam.h>
#include <highgui.h>
#include <stdio.h>
#include <ctype.h>
int main( int argc, char** argv )
{
int tecla;
CvCapture* capture = 0;
capture = cvCaptureFromCAM( argc == 2 ? argv[1][0] - '0' : 0 );
if( !capture )
{
return -1;
}
cvNamedWindow( "Camara", 1 );
for(;;)
{
IplImage* frame = 0;
frame = cvQueryFrame( capture );
if( !frame )
break;
cvShowImage( "Camara", frame );
tecla = cvWaitKey(10);
if( (char) tecla == 27 )
break;
}
cvReleaseCapture( &capture );
cvDestroyWindow("Camara");
return 0;
}