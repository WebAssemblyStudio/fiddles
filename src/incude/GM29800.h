
#ifndef GEOVIS_MILMATH_GM29800_H
#define GEOVIS_MILMATH_GM29800_H

class GM29800 
{
public:
	GM29800();
	~GM29800();
	bool toVertice(std::vector<GVCoord>& vtxBuffer,
				   std::vector<int>* vtxBuffer2 /*= NULL*/,
				   std::vector<float>* alphaBuffer /*= NULL*/,
				   std::vector<int>* typeBuffer /*= NULL*/);
    virtual int getMaxCPCount() const { return 10000;}
    virtual int getMinCPCount() const { return 2;}
	void setControlPoints(std::vector<GVCoord>& vtxBuffer);
	void modifyControlPoints(std::vector<GVCoord>& controlPoints);
	void getAuxandPoints_29800(std::vector<GVCoord>& controls, std::vector<GVCoord>& aux, std::vector<double>& rates);
	std::vector<GVCoord> getArrowbody_29800(std::vector<GVCoord> bPts);
	GVCoord Bessel_GV29800(const int& n, const float& t, const std::vector<GVCoord>& _controlPoints);
private:
	std::vector<GVCoord>   _normalPoints;    
	std::vector<double>    _rates;           
	std::vector<GVCoord>   _auxPoints;       
	int                    _normalPointCount;
	double neck_rate_29800;
	double tailAuxRate;
	bool   _tailAuxSide;
	std::vector<GVCoord>   _controlPoints;
};

#endif 
