#ifndef GEOVIS_MILUTIL_BEZIER_H
#define GEOVIS_MILUTIL_BEZIER_H
#include <vector>
#include <GVMilUtil/MilTypes.h>

class Bezier
{
public:
	void getBezier(const std::vector<GVCoord>& controlPoints, const std::vector<double>* rates, std::vector<GVCoord>* ratePoints, std::vector<GVCoord>* bezierPoints);
	
	//���ò�ֵΪ100    ʱ�����ȣ�����ԭ��------LH
	void getBezier_100(const std::vector<GVCoord>& controlPoints, const std::vector<double>* rates, std::vector<GVCoord>* ratePoints, std::vector<GVCoord>* bezierPoints);
};


#endif