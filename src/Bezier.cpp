#include <GVMilUtil/Bezier.h>

#include <math.h>
#include <stdlib.h>
     
/*
*���ܣ����������Ŀ��Ƶ����ر����������Ϊ�գ����ɱ���������
*������
*controlPoints 
*	�������������������ĵ㣬�������㣬����ĿΪn
*	controlPoints����Ϊ��
*rates
*	���������������λ��ı�����x��y�ֿ�,��4n-4����˳��Ϊx1,y1,x2,y2,x3,y3 ...
*	rates��Ϊ�գ�Ϊ��ʱ��Ĭ�Ϸ�ʽ���㣬��ʹ��rates
*	rates��Ϊ��ʱ��ʹ��rates������Ӧ���Ƶ�
*ratePoints
*	����������Ǹ���controlPoints��rates(�����Ϊ��)�������ÿ�����ڻ������������㣨������controlPoints�еĵ㣩����ĿΪ2n-2��
*	ratePoints��Ϊ�գ�Ϊ��ʱ�������������Ϊ���Ǹ�������2n-2����
*bezierPoints
*	�����������ֵ���ı����������ϵ����е㣬��ĿΪ��size+1��*(n-1)������size+1����ÿ�α������ϵĵ��������ں����ж����
*	bezierPoints����Ϊ��
*
*�����÷�:
*	std::vector<GVCoord> controlPoints;(������Ӧ�ĸ�ֵ)
*	std::vector<double> rates;(������Ӧ�ĸ�ֵ)
*	std::vector<GVCoord> ratePoints;
*	std::vector<GVCoord> bezierPoints;
*	Bezier bezier;
*	//bezier.getBezier(controlPoints, &rates, &ratePoints, &bezierPoints);		//ʹ��rates����ȡratePoints
*	//bezier.getBezier(controlPoints, &rates, NULL, &bezierPoints);				//ʹ��rates������ȡratePoints
*	//bezier.getBezier(controlPoints, NULL, &ratePoints, &bezierPoints);		//��ʹ��rates����ȡratePoints
*   //bezier.getBezier(controlPoints, NULL, &ratePoints, &bezierPoints);        //��ratePoints->size() = (controlPoints.size()*2 -2), ����ratePoints������
*	//bezier.getBezier(controlPoints, NULL, NULL, &bezierPoints);				//��ʹ��rates������ȡratePoints
*/

//������Ĵ˺������뽫����ĺ���Ҳ��һ��
void Bezier::getBezier(const std::vector<GVCoord>& controlPoints, const std::vector<double>* rates, std::vector<GVCoord>* ratePoints, std::vector<GVCoord>* bezierPoints)
{

	std::vector<GVCoord>	tempControlPoints;		//�������Ӳ������Ŀ��Ƶ�
	int	size	=	50;								//������ϱ��������ߵĵ����Ŀ
	if (ratePoints != NULL)
	{
		if (ratePoints->size() != (controlPoints.size()*2 -2))
		{
			ratePoints->clear();
		}
	}
	
	//�������߳���
	double len = 0.0;
	for(int i=0; i<controlPoints.size()-1; i++)
	{
		len += sqrt((controlPoints[i].lat-controlPoints[i+1].lat) * (controlPoints[i].lat-controlPoints[i+1].lat) + (controlPoints[i].lon-controlPoints[i+1].lon) * (controlPoints[i].lon-controlPoints[i+1].lon));
	}

	if(rates == NULL)
	{
		if (ratePoints == NULL)
		{
			//�洢��һ����͵�һ���ο���
			tempControlPoints.push_back(controlPoints[0]);
			tempControlPoints.push_back(controlPoints[0]);

			//�������еĲο���
			for(int i=1; i<controlPoints.size()-1; i++)
			{	
				//�������ο��㲢����tempControlPoints
				GVCoord p0;	//���
				GVCoord p1;	//�ҵ�
				GVCoord p2;	//�м��
				GVCoord curPoint = GVCoord(controlPoints[i].lon, controlPoints[i].lat, 0);
				//�����е�
				p0.lon = (controlPoints[i-1].lon + curPoint.lon) / 2;
				p0.lat = (controlPoints[i-1].lat + curPoint.lat) / 2;
				p1.lon = (controlPoints[i+1].lon + curPoint.lon) / 2;
				p1.lat = (controlPoints[i+1].lat + curPoint.lat) / 2;
				p2.lon = (p0.lon + p1.lon) / 2;
				p2.lat = (p0.lat + p1.lat) / 2;

				tempControlPoints.push_back(GVCoord((p0.lon-p2.lon), (p0.lat-p2.lat), 0) + curPoint);
				tempControlPoints.push_back(GVCoord(curPoint));
				tempControlPoints.push_back(GVCoord((p1.lon-p2.lon), (p1.lat-p2.lat), 0) + curPoint);
			}

			//�洢���һ��������һ���ο���
			tempControlPoints.push_back(controlPoints[controlPoints.size()-1]);
			tempControlPoints.push_back(controlPoints[controlPoints.size()-1]);
		}
		else
		{
			if (ratePoints->size() == 0)
			{
				//�洢��һ����͵�һ���ο���
				tempControlPoints.push_back(controlPoints[0]);
				tempControlPoints.push_back(controlPoints[0]);

				//�������еĲο���
				for(int i=1; i<controlPoints.size()-1; i++)
				{	
					//�������ο��㲢����tempControlPoints
					GVCoord p0;	//���
					GVCoord p1;	//�ҵ�
					GVCoord p2;	//�м��
					GVCoord curPoint = GVCoord(controlPoints[i].lon, controlPoints[i].lat, 0);
					//�����е�
					p0.lon = (controlPoints[i-1].lon + curPoint.lon) / 2;
					p0.lat = (controlPoints[i-1].lat + curPoint.lat) / 2;
					p1.lon = (controlPoints[i+1].lon + curPoint.lon) / 2;
					p1.lat = (controlPoints[i+1].lat + curPoint.lat) / 2;
					p2.lon = (p0.lon + p1.lon) / 2;
					p2.lat = (p0.lat + p1.lat) / 2;

					tempControlPoints.push_back(GVCoord((p0.lon-p2.lon), (p0.lat-p2.lat), 0) + curPoint);
					tempControlPoints.push_back(GVCoord(curPoint));
					tempControlPoints.push_back(GVCoord((p1.lon-p2.lon), (p1.lat-p2.lat), 0) + curPoint);
				}

				tempControlPoints.push_back(controlPoints[controlPoints.size()-1]);
				tempControlPoints.push_back(controlPoints[controlPoints.size()-1]);
			} 
			else
			{
				for(int i=0; i<controlPoints.size()-1; i++)
				{
					tempControlPoints.push_back(controlPoints[i]);
					tempControlPoints.push_back(ratePoints->at(2*i));
					tempControlPoints.push_back(ratePoints->at(2*i+1));
				}
				tempControlPoints.push_back(controlPoints[controlPoints.size() - 1]);
			}
			
		}
		
	}
	else
	{
		for(int i=0; i<controlPoints.size()-1; i++)
		{
			tempControlPoints.push_back(controlPoints[i]);
			GVCoord temp;
			temp.lon = (*rates)[i * 4] * len +  controlPoints[i].lon;
			temp.lat = (*rates)[i * 4 + 1] * len + controlPoints[i].lat;
			tempControlPoints.push_back(temp);

			temp.lon = (*rates)[i * 4 + 2] * len + controlPoints[i+1].lon;
			temp.lat = (*rates)[i * 4 + 3] * len + controlPoints[i+1].lat;
			tempControlPoints.push_back(temp);
		}
		tempControlPoints.push_back(controlPoints[controlPoints.size() - 1]);
	}

	bezierPoints->clear();
	int factors[4] = {1, 3, 3, 1};		
	
	
	int  lenth=tempControlPoints.size();
	std::vector<double>  lon_interpolation;
	if (lenth >= 2)
	{
		for (int i = 1,j=0; i < lenth; i++,j++)
		{

			double lon_inter = tempControlPoints[i].lon - tempControlPoints[i - 1].lon;
			lon_interpolation.push_back(lon_inter);
			if (abs(lon_interpolation[j]) > 180)
			{
				if (lon_interpolation[j]>0)
					lon_interpolation[j] = lon_interpolation[j] - 360;
				else
					lon_interpolation[j] = lon_interpolation[j] + 360;
			}
			tempControlPoints[i].lon =tempControlPoints[i-1].lon + lon_interpolation[j];
		}

	}

	if(ratePoints != NULL)
	{
		ratePoints->clear();
		for(int i=0; i<tempControlPoints.size(); i++)
		{
			if(i%3 == 0)
				continue;
			ratePoints->push_back(tempControlPoints[i]);
		}
	}


	for(int index=0; index<=tempControlPoints.size()-4; index += 3)
	{

		double t = 0.0;
		for (int i=0; i<size; i++)
		{
			t = i/(double)size;
			double	lon		=	0.0;
			double	lat		=	0.0;

			for(int j=0; j<4; j++)
			{
				lon += factors[j] * pow(1-t, 3-j) * pow(t, j) * tempControlPoints[index + j].lon;
				lat += factors[j] * pow(1-t, 3-j) * pow(t, j) * tempControlPoints[index + j].lat;
			}
			bezierPoints->push_back(GVCoord(lon, lat, 0));
		}
		
	}
	bezierPoints->push_back(tempControlPoints[tempControlPoints.size()-1]);
}



void Bezier::getBezier_100(const std::vector<GVCoord>& controlPoints, const std::vector<double>* rates, std::vector<GVCoord>* ratePoints, std::vector<GVCoord>* bezierPoints)
{

	std::vector<GVCoord>	tempControlPoints;		
	int	size	=	100;								
	if (controlPoints.size() == 2 || controlPoints.size() == 3)
	{
		size = 400;
	}
	if (ratePoints != NULL)
	{
		if (ratePoints->size() != (controlPoints.size()*2 -2))
		{
			ratePoints->clear();
		}
	}

	
	double len = 0.0;
	for(int i=0; i<controlPoints.size()-1; i++)
	{
		len += sqrt((controlPoints[i].lat-controlPoints[i+1].lat) * (controlPoints[i].lat-controlPoints[i+1].lat) + (controlPoints[i].lon-controlPoints[i+1].lon) * (controlPoints[i].lon-controlPoints[i+1].lon));
	}

	if(rates == NULL)
	{
		if (ratePoints == NULL)
		{
			tempControlPoints.push_back(controlPoints[0]);
			tempControlPoints.push_back(controlPoints[0]);

			for(int i=1; i<controlPoints.size()-1; i++)
			{	
				GVCoord p0;	//���
				GVCoord p1;	//�ҵ�
				GVCoord p2;	//�м��
				GVCoord curPoint = GVCoord(controlPoints[i].lon, controlPoints[i].lat, 0);
				//�����е�
				p0.lon = (controlPoints[i-1].lon + curPoint.lon) / 2;
				p0.lat = (controlPoints[i-1].lat + curPoint.lat) / 2;
				p1.lon = (controlPoints[i+1].lon + curPoint.lon) / 2;
				p1.lat = (controlPoints[i+1].lat + curPoint.lat) / 2;
				p2.lon = (p0.lon + p1.lon) / 2;
				p2.lat = (p0.lat + p1.lat) / 2;

				tempControlPoints.push_back(GVCoord((p0.lon-p2.lon), (p0.lat-p2.lat), 0) + curPoint);
				tempControlPoints.push_back(GVCoord(curPoint));
				tempControlPoints.push_back(GVCoord((p1.lon-p2.lon), (p1.lat-p2.lat), 0) + curPoint);
			}

			//�洢���һ��������һ���ο���
			tempControlPoints.push_back(controlPoints[controlPoints.size()-1]);
			tempControlPoints.push_back(controlPoints[controlPoints.size()-1]);
		}
		else
		{
			if (ratePoints->size() == 0)
			{
				//�洢��һ����͵�һ���ο���
				tempControlPoints.push_back(controlPoints[0]);
				tempControlPoints.push_back(controlPoints[0]);

				//�������еĲο���
				for(int i=1; i<controlPoints.size()-1; i++)
				{	
					//�������ο��㲢����tempControlPoints
					GVCoord p0;	//���
					GVCoord p1;	//�ҵ�
					GVCoord p2;	//�м��
					GVCoord curPoint = GVCoord(controlPoints[i].lon, controlPoints[i].lat, 0);
					//�����е�
					p0.lon = (controlPoints[i-1].lon + curPoint.lon) / 2;
					p0.lat = (controlPoints[i-1].lat + curPoint.lat) / 2;
					p1.lon = (controlPoints[i+1].lon + curPoint.lon) / 2;
					p1.lat = (controlPoints[i+1].lat + curPoint.lat) / 2;
					p2.lon = (p0.lon + p1.lon) / 2;
					p2.lat = (p0.lat + p1.lat) / 2;

					tempControlPoints.push_back(GVCoord((p0.lon-p2.lon), (p0.lat-p2.lat), 0) + curPoint);
					tempControlPoints.push_back(GVCoord(curPoint));
					tempControlPoints.push_back(GVCoord((p1.lon-p2.lon), (p1.lat-p2.lat), 0) + curPoint);
				}

				//�洢���һ��������һ���ο���
				tempControlPoints.push_back(controlPoints[controlPoints.size()-1]);
				tempControlPoints.push_back(controlPoints[controlPoints.size()-1]);
			} 
			else
			{
				for(int i=0; i<controlPoints.size()-1; i++)
				{
					tempControlPoints.push_back(controlPoints[i]);
					tempControlPoints.push_back(ratePoints->at(2*i));
					tempControlPoints.push_back(ratePoints->at(2*i+1));
				}
				tempControlPoints.push_back(controlPoints[controlPoints.size() - 1]);
			}

		}

	}
	else
	{
		for(int i=0; i<controlPoints.size()-1; i++)
		{
			tempControlPoints.push_back(controlPoints[i]);
			GVCoord temp;
			temp.lon = (*rates)[i * 4] * len +  controlPoints[i].lon;
			temp.lat = (*rates)[i * 4 + 1] * len + controlPoints[i].lat;
			tempControlPoints.push_back(temp);

			temp.lon = (*rates)[i * 4 + 2] * len + controlPoints[i+1].lon;
			temp.lat = (*rates)[i * 4 + 3] * len + controlPoints[i+1].lat;
			tempControlPoints.push_back(temp);
		}
		tempControlPoints.push_back(controlPoints[controlPoints.size() - 1]);
	}




	bezierPoints->clear();
	int factors[4] = {1, 3, 3, 1};		//���������ߵĶ���ʽϵ��


	//���������������ϵĲ�ֵ��
	int  lenth=tempControlPoints.size();
	std::vector<double>  lon_interpolation;
	if (lenth >= 2)
	{
		for (int i = 1,j=0; i < lenth; i++,j++)
		{

			double lon_inter = tempControlPoints[i].lon - tempControlPoints[i - 1].lon;
			lon_interpolation.push_back(lon_inter);
			if (abs(lon_interpolation[j]) > 180)
			{
				if (lon_interpolation[j]>0)
					lon_interpolation[j] = lon_interpolation[j] - 360;
				else
					lon_interpolation[j] = lon_interpolation[j] + 360;
			}
			tempControlPoints[i].lon =tempControlPoints[i-1].lon + lon_interpolation[j];
		}

	}

	if(ratePoints != NULL)
	{
		ratePoints->clear();
		for(int i=0; i<tempControlPoints.size(); i++)
		{
			if(i%3 == 0)
				continue;
			ratePoints->push_back(tempControlPoints[i]);
		}
	}


	//tempControlPoints�е�ÿ�ĸ�����Ϊһ�α��������ߵĿ��Ƶ�
	for(int index=0; index<=tempControlPoints.size()-4; index += 3)
	{

		//���������������������ģ��ĵ�(3��)
		double t = 0.0;
		for (int i=0; i<size; i++)
		{
			t = i/(double)size;
			double	lon		=	0.0;
			double	lat		=	0.0;

			//����ϵ���Ͳ���t��ÿ�����Ƶ��ֵ����������������ϵĵ�
			for(int j=0; j<4; j++)
			{
				lon += factors[j] * pow(1-t, 3-j) * pow(t, j) * tempControlPoints[index + j].lon;
				lat += factors[j] * pow(1-t, 3-j) * pow(t, j) * tempControlPoints[index + j].lat;
			}
			bezierPoints->push_back(GVCoord(lon, lat, 0));
		}

	}
	bezierPoints->push_back(tempControlPoints[tempControlPoints.size()-1]);
}

