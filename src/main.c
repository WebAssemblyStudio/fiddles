#define WASM_EXPORT __attribute__((visibility("default")))

#include "stdio.h"
#include "malloc.h"
#include "math.h"
#define PI acos(-1.0f)

WASM_EXPORT
int main() {
  return 42;
}

//////////////////函数说明////////////
///名称：加力窗
///作用：对指定数据进行加力窗处理
///参数：fInData， 输入数据数组
///      nDataCounts, 输入数据数组长度
///      nStartPoint, 加力窗的起点
///      nWinLength, 力窗的长度
///      fDt,离散的时间间隔
///      nWinType窗类型 定义如下：
///         0 矩形窗
///         1 力窗1
///         2 力窗2
///////////////////////////////////////////////////////////////////////////////////////////// 
WASM_EXPORT
int ForceWinDo(float *fInData, int nDataCounts, int nStartPoint, int nWinLength, float fDt, int nWinType)
{
	int i;
	float t = nWinLength * fDt;
	switch(nWinType)
	{
	case 1: 
		for(i = 0; i < nStartPoint; i++)
			fInData[i] *= 0;
		for(i = nStartPoint; i < nStartPoint + 1.2 * nWinLength; i++)
			fInData[i] *= 1.f;
		for(i = nStartPoint + 1.2 * nWinLength; i < nStartPoint + 1.8 * nWinLength; i++)
		{
			if(i > nDataCounts - 1)
				break;
			fInData[i] *= 0.5f * (1.f + cos(5 * PI * (i - nStartPoint - 1.2 * nWinLength) * fDt / ( 3.f * t)));
		}
		for(i = nStartPoint + 1.8 * nWinLength; i < nDataCounts; i++)
			fInData[i] *= 0;
		break;
	case 2:
		for(i = 0; i < nStartPoint; i++)
			fInData[i] *= 0;
		for(i = nStartPoint; i < nStartPoint + 1.2 * nWinLength; i++)
			fInData[i] *= 1.f;
		for(i = nStartPoint + nWinLength; i < nDataCounts; i++)
		{
			fInData[i] *= 0.f;
		}
		break;
	default:
		break;
	}
	return 1;
}

//////////////////函数说明////////////
///名称：FFT
///作用：基2的快速富立叶变换
///参数：fInData, 输入数据数组
///      fRealData, 输出变换后的实部数据
///      fImageData, 输出变换后的虚部数据
///      nStartPoint, 需要作谱的数据在输入数据数组的起始位置
///      nFramePoint, 需要作谱的点数，为2的整次幂
///      nInv, 正、逆变换开关，0：正变换； 1:负变换
//////////////////////////////////////////////////////////////////////////////////////////////////////
WASM_EXPORT
int FFTr_2 (float *fInData, float *fRealData, float *fImageData, int nStartPoint, int nFramePoint, int nInv)
{
	if(nFramePoint <= 0) 
		return 0;

	
	int nbd2,m,me,k,lpk;
    int j, l, nm;
    float pi;
    float t,tr,ti,ur,ui,wr,wi;
    
	if(nInv == 0)
	{
		for(j = 0; j < nFramePoint; j++)
		{
			fRealData[j] = fInData[j + nStartPoint];
			fImageData[j] = 0.f;
		}
	}
//////////////////nFramePoint = 2^^nm
	frexp((double)nFramePoint, &nm);
    nm--;
    if((int)pow(2,nm) < nFramePoint)
		nm++;
////////////////////////////////////////
/////////ndb2 = nFramePoint / 2
    nbd2 = nFramePoint >> 1;
//////////////////////////////////
    j = 0;
    for(l = 0; l <= nFramePoint - 2; l++)
	{
		if(l < j)
		{
	       t = fRealData[j]; fRealData[j] = fRealData[l]; fRealData[l] = t;
		   t = fImageData[j]; fImageData[j] = fImageData[l]; fImageData[l] = t;
		}
		k = nbd2;
	    while(k <= j)
		{
	       j -= k; 
		   k = k >> 1;
		}
		j += k;
	}

   for(m = 1; m <= nm; m++)
   {
	   ur = 1; 
	   ui = 0;
       me = 1 << m;
       k = me >> 1;
       wr = (float)cos(PI / k); 
	   wi = -(float)sin(PI / k);
       if(nInv == 1)
		   wi=-wi;
       for(j = 0; j <= k - 1; j++)
	   {
		   for(l = j; l <= nFramePoint - 1; l = l + me)
		   {
			   lpk = l + k;
			   tr = fRealData[lpk] * ur - fImageData[lpk] * ui;
	           ti = fRealData[lpk] * ui + fImageData[lpk] * ur;
	           fRealData[lpk] = fRealData[l] - tr;
               fImageData[lpk] = fImageData[l] - ti;
	           fRealData[l] += tr;
	           fImageData[l] += ti;
		   }
		   tr = ur * wr - ui * wi;
           ui = ur * wi + ui * wr;
           ur = tr;
	   }
   }

   t = 1.0f / nFramePoint;
   if(nInv != 1)
   {
	   for(j = 0; j <= nFramePoint - 1; j++)
	   {
		   fRealData[j] *= t; 
		   fImageData[j] *= t;
	   }
   }
   else
   {
	   for(j = 0; j < nFramePoint; j++)
	   {
		   fInData[j] = fRealData[j]; 
	   }
   }
   return 1;
}

//////////////////函数说明////////////
///名称：加窗
///作用：对指定数据进行加窗处理
///参数：fInData， 输入数据数组
///      nWinLength为窗数组fInData的长度；
///      nWinType窗类型 定义如下：
///         0 矩形窗
///         1 海宁窗hanning
///         2 汉明窗hamming
///         3 10%余弦窗
///         4 5%余弦窗
///         5 频域平顶窗
///         6 平顶窗
///         7 Bartlett(三角窗)
///         8 布莱克曼窗
///         9 指数窗
///////////////////////////////////////////////////////////////////////////////////////////// 
WASM_EXPORT
int WindowDo(float *fInData, int nStartPoint, int nWinLength, int nWinType, float fAttenCoe)//2007.4.9更改对称性问题
{
	int i, j, n;
	double thta;
	double* fData = new double[nWinLength];
	if(fData==NULL)
		return 0;

	//计算一半
	if((nWinLength%2)==0)
		n = nWinLength/2;
	else
		n = (nWinLength+1)/2;

	switch(nWinType)
	{
	case 0:  ///////0 矩形窗
		//for(i = 0; i < nWinLength; i++)
		//	fInData[i + nStartPoint] *= 1.f;
		break;
	case 1:   ////////1 海宁窗hanning
		thta = 2.f * PI / (nWinLength + 1);
		for(i = 0; i < n; i++)
		{
			fData[i] = (1 - cos(thta * (i + 1))) * .5f;
		}		
		//对称赋值
		if((nWinLength%2)==0)
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-1-i];
			}
		}
		else
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-2-i];
			}
		}
		//加窗
		for(i = 0; i < nWinLength; i++)
		{
			fInData[i + nStartPoint] *= (float)fData[i];
		}
		break;
	case 2:   ////////汉明窗hamming
		thta = 2.f * PI/(nWinLength + 1);
		for(i = 0; i < n; i++) 
		{
			fData[i] = 0.54f - 0.46f * cos(thta * (i + 1));
		}
		//对称赋值
		if((nWinLength%2)==0)
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-1-i];
			}
		}
		else
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-2-i];
			}
		}
		//加窗
		for(i = 0; i < nWinLength; i++) 
		{
			fInData[i + nStartPoint] *= (float)fData[i];
		}
		break;
	case 3:  ///////10%余弦窗
	  	j = int(.1 * nWinLength);
		thta = PI / (j+1.f);		
		for(i = 0; i < nWinLength; i++)
		{
			fData[i] = 1.f;
		}
		for(i = 0; i < j; i++)
		{
			fData[i] = (1 - cos(thta * (i + 1))) * 0.5f;
			fData[nWinLength - i - 1] = fData[i];
		}
		//加窗
		for(i = 0; i < nWinLength; i++)
		{
			fInData[i + nStartPoint] *= (float)fData[i];
		}
		break;
	case 4:  /////////5%余弦窗
		j = int(.05 * nWinLength);
		thta = PI / (j+1.f);		
		for(i = 0; i < nWinLength; i++)
		{
			fData[i] = 1.f;
		}		
		for(i = 0; i < j; i++)
		{
			fData[i] = (1 - cos(thta * (i + 1))) * 0.5f;
			fData[nWinLength - i - 1] = fData[i];
		}
		//加窗
		for(i = 0; i < nWinLength; i++)
		{
			fInData[i + nStartPoint] *= (float)fData[i];
		}
		break;
	case 5:  //////// 频域平顶窗
		thta = 2.f * PI / (nWinLength + 1);
		for(i = 0; i < n; i++) 
		{
			fData[i] = (float)(0.21170 - 0.40565 * cos(thta * (i + 1)) + 0.27808 * cos(2 * thta * (i + 1))
				- 0.09435 * cos(3 * thta * (i + 1)) + 0.01022 * cos(4 * thta * (i + 1)));	
		}		
		//对称赋值
		if((nWinLength%2)==0)
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-1-i];
			}
		}
		else
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-2-i];
			}
		}
		//加窗
		for(i = 0; i < nWinLength; i++)
		{
			fInData[i + nStartPoint] *= (float)fData[i];
		}
		break;
	case 6:   //////////平顶窗
		thta = 2.f * PI / (nWinLength + 1);
		for(i = 0; i < n; i++)
		{
			fData[i] = (float)(0.2810639f - 0.5208972f * cos(2 * PI * (i + 1) / (nWinLength + 1)) + 0.1980399f * cos(4 * PI * (i + 1) / (nWinLength + 1)));
		}
		//对称赋值
		if((nWinLength%2)==0)
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-1-i];
			}
		}
		else
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-2-i];
			}
		}
		//加窗
		for(i = 0; i < nWinLength; i++)
		{
			fInData[i + nStartPoint] *= (float)fData[i];
		}
		break;
	case 7:  ////////三角窗
		for(i = 0; i < n; i++)
		{
			fData[i] = 1.f - fabs(2 * (i+1) - nWinLength) / nWinLength;
		}		
		//对称赋值
		if((nWinLength%2)==0)
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-1-i];
			}
		}
		else
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-2-i];
			}
		}
		//加窗
		for(i = 0; i < nWinLength; i++)
		{
			fInData[i + nStartPoint] *= (float)fData[i];
		}
		break;
	case 8:  //////////布莱克曼窗
		thta = float(2.f * PI / (nWinLength + 1));
		for(i = 0; i < n; i++) 
		{
			fData[i] = 0.42 - 0.5 * cos(thta * (i + 1)) + 0.08 * cos(thta * 2 * (i + 1));
		}
		
		//对称赋值
		if((nWinLength%2)==0)
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-1-i];
			}
		}
		else
		{
			for(i=n; i<nWinLength; i++)
			{
				fData[i] = fData[2*n-2-i];
			}
		}
		//加窗
		for(i = 0; i < nWinLength; i++)
		{
			fInData[i + nStartPoint] *= (float)fData[i];
		}
		break;
	case 9:   //////////指数窗
		for(i = 0; i < nWinLength; i++)
			fInData[i + nStartPoint] *= (float)exp(-fAttenCoe * i / nWinLength);
		break;
	default:  /////////缺省加矩形窗
		//for(i = 0; i < nWinLength; i++)
		//	fInData[i + nStartPoint] *= 1.f;
		break;
	}
	delete fData;

	return 1;
}

//////////////////函数说明////////////
///名称：相位补偿
///作用：对使用分时采集的数据为了消除相位误差，而进行相位补偿
///参数：fInData， 输入数据数组
///      nDataCounts, 输入数据数组长度
///      nChannelMargin, 输入数据通道与相对通道的通道差值
///      nChannelCounts, 总通道数
/////////////////////////////////////////////////////////////////////////////////////////////
WASM_EXPORT
int PhaseCompensate(float *fInData, int nDataCounts, int nChannelMargin, int nChannelCounts)
{
	int i, n2;
	float SYT, SYTA;
	float xx, yy;
	n2 = nDataCounts / 2;
	SYTA = 2 * PI * nChannelMargin / nDataCounts / nChannelCounts;
	for(i = 0; i < n2; i++)
	{
		SYT = SYTA * (i - 1);
	    xx = fInData[i] * cos(SYT) + fInData[n2 + i] * sin(SYT);
	    yy = fInData[n2 + i] * cos(SYT) - fInData[i] * sin(SYT);
	    fInData[i] = xx;
	    fInData[n2 + i] = yy;
	}
	return 1;
}

//////////////////函数说明////////////
///名称：传递函数
///作用：计算输出数据相对于输入数据的传递函数
///参数：fInData1, 输入数据数组1
///      fInData2, 输入数据数组2
///      fOutData, 输出数据数组，其中0 ~ nFramPoint / 2 - 1为实部数据，nFramPoint / 2 ~ nFramPoint为虚部数据
///      nStartPoint, 需要作谱的数据在输入数据数组的起始位置
///      nFramePoint, 每个作谱数据段的点数，为2的整次幂
///      nAverageCounts, 平均次数
///      nForceWinStartPoint, 力窗起点
///      nForceWinLength，力窗长度
///      nForceWinType，力窗类型 
///      nExpWinStartPoint, 指数窗起点
///      nExpWinLength，指数窗长度
///      nExpWinType，力窗类型 
///      fAttenCoe，指数窗衰减系数
///      fXInterval，频率分辨率
///      nChannelMargin，输入数据与输出数据的通道差，
///      nChannelCounts, 输入的总通道数
///      nModify, 是否进行修正开关, 0：幅值和相位都不修正； 1：幅值修正，相位不修正  2: 幅值修正，相位修正  3:幅值不修正， 相位修正
//////////////////////////////////////////////////////////////////////////////////////////////////////
WASM_EXPORT
int TransFunction(float *fInData1, float *fInData2, float *fOutData, int nStartPoint, int nFramePoint, int nAverageCounts, 
								int nForceWinStartPoint, int nForceWinLength, int nForceWinType, 
								int nExpWinStartPoint, int nExpWinLength, int nExpWinType, float fAttenCoe, 
								float fXInterval, int nChannelMargin, int nChannelCounts, int nModify)
{
	int i,j;
	int n2 = nFramePoint / 2;
    float xi, xin, yi, yin, dyy = 1.f;
 
	float *yy, *ai, *ar, *temp, *xx;

	yy = (float *)calloc(nFramePoint, sizeof(float));
	if(yy == NULL) return -1;

	ar = (float *)calloc(nFramePoint, sizeof(float));
	if(ar == NULL) return -1;

	ai = (float *)calloc(nFramePoint, sizeof(float));
	if(ai == NULL) return -1;

	temp = (float *)calloc(nFramePoint, sizeof(float));
	if(temp == NULL) return -1;

	xx = (float *)calloc(nFramePoint, sizeof(float));
	if(xx == NULL) return -1;

    for(i = 0; i < nFramePoint; i++)
	{
		fOutData[i] = 0.f;
		yy[i] = 0.f;
		xx[i] = 0.f;
	}
	
		
	for(j = 1; j <= nAverageCounts; j++)
	{
		for(i = 0; i < nFramePoint; i++)
		{
			 temp[i] = fInData1[(j - 1) * nFramePoint + i + nStartPoint];
			 ai[i] = 0.f;
			 ar[i] = 0.f;
		}
		ForceWinDo(temp, nFramePoint, nForceWinStartPoint, nForceWinLength, fXInterval, nForceWinType);
		FFTr_2(temp, ar, ai, 0, nFramePoint, 0);
		
        for(i = 0; i < n2; i++)
			ar[i + n2] = ai[i]; 
		
		
		for(i = 0; i < nFramePoint; i++)
		{
			temp[i] = fInData2[(j - 1) * nFramePoint + i + nStartPoint];
			yy[i] = 0.f;
			ai[i] = 0.f;
		}
		WindowDo(temp, nExpWinStartPoint, nExpWinLength, nExpWinType, fAttenCoe);
		FFTr_2(temp, ai, yy, 0, nFramePoint, 0);
		for(i = 0; i < n2; i++)
			ai[i + n2] = yy[i];  

		if(nModify == 2 || nModify == 3)
			PhaseCompensate(ai, nFramePoint, nChannelMargin, nChannelCounts);
			
		for(i = 0; i < n2; i++)
		{
		    xi  = ar[i];
		    xin = ar[n2 + i];
		    yi  = ai[i];
		    yin = ai[n2 + i];
		    temp[i] = (xi * yi + xin * yin);
			temp[n2 + i] = (xi * yin - yi * xin);
			xx[i] += xi * xi + xin * xin;
		}
		

		for(i = 0; i < nFramePoint; i++) 
//			fOutData[i] = fOutData[i] * (j - 1) / j + temp[i] / j;
			fOutData[i] += temp[i];
	}
	xi = 0;
	for(i = 0; i < n2; i++)
	{
		xx[i] /= nAverageCounts;
		if(xi < xx[i])
			xi = xx[i];
	}
	xi *= pow(10., -9);
	for(i = 0; i < n2; i++) 
	{
		if(xx[i] < xi)
			xx[i] = xi;
		fOutData[i] /= nAverageCounts;
		fOutData[i + n2] /= nAverageCounts;
		fOutData[i] /= xx[i];
		fOutData[i + n2] /= xx[i];
	}
	   	 
	 free(ar);
	 free(ai);
	 free(yy);
	 free(xx);
	 free(temp);
	return 1;
}

