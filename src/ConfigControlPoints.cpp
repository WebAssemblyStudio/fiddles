#include <GVMilUtil/ConfigControlPoints.h>
#include <math.h>
#include <stdlib.h>


void ConfigControlPoints::configControlPoints(std::vector<GVCoord> &_controlPoints)//�Դ�������п��Ƶ��������
{	
	int  lenth=_controlPoints.size();
	std::vector<double>  lon_interpolation;
	if (lenth >= 2)
	{
		double lonMod = fmod(_controlPoints[0].lon, 360.0);
		_controlPoints[0].lon = abs(lonMod) <= 180.f ? lonMod : (lonMod > 0 ? lonMod - 360.f : lonMod + 360.f);
		double latMod = fmod(_controlPoints[0].lat, 180.0);
		_controlPoints[0].lat = abs(latMod) <= 90.f ? latMod : (latMod > 0 ? latMod - 180.f : latMod + 180.f);

		for (int i = 1,j=0; i < lenth; i++,j++)
		{
			double lonMod = fmod(_controlPoints[i].lon, 360.0);
			_controlPoints[i].lon = abs(lonMod) <= 180.f ? lonMod : (lonMod>0 ? lonMod - 360.f : lonMod + 360.f);
			double latMod = fmod(_controlPoints[i].lat, 180.0);
			_controlPoints[i].lat = abs(latMod) <= 90.f ? latMod : (latMod > 0 ? latMod - 180.f : latMod + 180.f);
			
			double lon_inter = _controlPoints[i].lon - _controlPoints[i - 1].lon;
			lon_interpolation.push_back(lon_inter);
			if (abs(lon_interpolation[j]) > 180)
			{
				if (lon_interpolation[j]>0)
					lon_interpolation[j] = lon_interpolation[j] - 360;
				else
					lon_interpolation[j] = lon_interpolation[j] + 360;
			}
			_controlPoints[i].lon = _controlPoints[i-1].lon + lon_interpolation[j];
		}

	}
}
void ConfigControlPoints::configControlPoints(GVCoord &vtx, std::vector<GVCoord> &_controlPoints)
{
	int cpSize = _controlPoints.size();
	double LON = 0;
	for (int i = 0; i < cpSize; i++)
	{
		LON += _controlPoints[i].lon;
	}
	LON /= cpSize;
	if (vtx.lon - LON > 180)
	{
		vtx.lon -= 360;
	} 
	else if (vtx.lon - LON < -180)
	{
		vtx.lon += 360;
	}

}
void ConfigControlPoints::configControlPoints(int idx ,std::vector<GVCoord> &_controlPoints){//�϶��������Ƶ��ʱ������޸�


	//�޸�֮��Ĵ���
	if (_controlPoints.size() < 2)
		return;
	std::vector<double> deltaList;

	if (idx>0)
	{
		for (int i = idx; i < _controlPoints.size(); i++)
		{
			double delta = _controlPoints[i].lon - _controlPoints[i - 1].lon;
			deltaList.push_back(delta);
		}
		for (int i = 0; i < deltaList.size(); i++,idx++)
		{
			if (abs(deltaList.at(i)) > 180)
			{
				if (deltaList.at(i)>0)
					deltaList.at(i) = deltaList.at(i) - 360;
				else
					deltaList.at(i) = deltaList.at(i) + 360;
			}
			_controlPoints[idx].lon = _controlPoints[idx - 1].lon + deltaList.at(i);
		}

	}
	else{
		for (int i = 1; i < _controlPoints.size(); i++)
		{
			double delta = _controlPoints[i].lon - _controlPoints[i - 1].lon;
			deltaList.push_back(delta);
		}
		for (int i = 0; i < deltaList.size(); i++)
		{
			if (abs(deltaList.at(i)) > 180)
			{
				if (deltaList.at(i)>0)
					deltaList.at(i) = deltaList.at(i) - 360;
				else
					deltaList.at(i) = deltaList.at(i) + 360;
			}
		}

		for (int i = deltaList.size(); i > 0; i--)
		{
			_controlPoints[i - 1].lon = _controlPoints[i].lon - deltaList.at(i - 1);
		}
	}

	//printf("0_lon��%f��1_lon��%f,2_lon��%f,,3_lon��%f,i=%d\n", _controlPoints[0].lon, _controlPoints[1].lon, _controlPoints[2].lon, _controlPoints[3].lon, idx);
}

