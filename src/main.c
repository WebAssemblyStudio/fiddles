#include <stdio.h>
#include <sys/uio.h>
//#include <../../GM29800.h>
#include <vector.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
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

// WASM_EXPORT 
// void cal_GMil(char* name,
// 									   double* points,
// 									   int* num,
// 									   int* orders= NULL,
// 									   int* ordersNum = NULL
// 									   )
// 	{
// 		// Todo: factory

// 		// data input
// 		std::vector<GVCoord> pointsList;
// 		std::vector<int>	 ordersList;
// 		std::vector<float>	 unused1;
// 		std::vector<int>	 unused2;

// 		for(int i = 0; i < *num; i++)
// 		{
// 			pointsList.push_back(GVCoord(points[i*3],
// 										 points[i*3+1],
// 										 points[i*3+2]));
// 		}

// 		// handle data
// 		// if( strcmp(name,"GM26800") == 0)
// 		// if(0)
// 		// {
// 		// 	GM26800 obj;
// 		// 	obj.setControlPoints(pointsList);
// 		// 	obj.toVertice(pointsList,&ordersList,&unused1,&unused2);
// 		// }
// 		// else if( strcmp(name,"GM29800") == 0 )
// 		if(1)
// 		{
// 			GM29800 obj;
// 			obj.toVertice(pointsList,&ordersList,&unused1,&unused2);
// 		}
// 		else
// 			return;

// 		// data output
// 		*num = pointsList.size();
// 		for(int i = 0; i < pointsList.size(); i++)
// 		{
// 			points[i*3 + 0] = pointsList[i].lon;
// 			points[i*3 + 1] = pointsList[i].lat;
// 			points[i*3 + 2] = pointsList[i].alt;
// 		}

// 		*ordersNum = ordersList.size();
// 		for(int i = 0; i < ordersList.size(); i++)
// 		{
// 			orders[i] = ordersList[i];
// 		}
// 	}



