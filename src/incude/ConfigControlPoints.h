#include <vector>
#include <GVMilUtil/MilTypes.h>


class  ConfigControlPoints
{
public:
	//Îª·½±ãÐÞ¸Ä£¬Í³Ò»Ê¹ÓÃ¶ÔÏóÃûcfcp£¬
	//¼´:ConfigControlPoints cfcp;

	static void configControlPoints(std::vector<GVCoord> &_controlPoints);//ÐÞÕýÈ«²¿¿ØÖÆµã
	
	static void configControlPoints(GVCoord &vtx, std::vector<GVCoord> &_controlPoints);//¸ù¾ÝÒÑÓÐµÄ_controlPointsÖÐµÄµã£¬ÐÞÕýµãvtx£»

	static void configControlPoints(int idx, std::vector<GVCoord> &_controlPoints);//¸ù¾ÝËù¸øÏÂ±êIdx£¬ÐÞÕý_controlPoints[idx]
};

