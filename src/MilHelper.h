#ifndef GEOVIS_MILUTIL_MILHELPER_H
#define GEOVIS_MILUTIL_MILHELPER_H
#include <vector>
#include <GVMilUtil/MilTypes.h>


const double EPS = 1E-8;

/***************************************************************
���ܣ�������beg_coord, end_coord֮��ľ���
�����������ʼ��beg_coord�ͽ�����end_coord
���ز���������֮��ľ���
***************************************************************/
 double distance(const GVCoord &beg_coord, const GVCoord &end_coord);

/***************************************************************
���ܣ��������߳���
������������ߵ������coords
���ز���������
˵������
***************************************************************/
 double getLengthOfAll(const std::vector<GVCoord>& coords);

/*****************************************************************************************************
���ܣ���1�ȵ��ݶȲ���360��Բ�ܵ㲢����
���������Բ�ĵ�circle_center��Բ�İ뾶radius�����ڱ���Բ�ܵ������circlecoords
���ز�������
*****************************************************************************************************/
 void getCircle(const GVCoord &circle_center, double radius, std::vector<GVCoord> &circlecoords);

/****************************************************************************************************
���ܣ���1�ȵ��ݶȲ���360����Բ�㲢����
�����������Բ���ĵ�ellipse_center��������1���ȵĵ�ellipse_point1��������2���ȵĵ�ellipse_point2������ķ���������(ellipse_center, ellipse_point2)������ellipsecoords���ڱ�����Բ���ϵĵ������
���ز�������
*****************************************************************************************************/
 void getEllipse(const GVCoord &ellipse_center, const GVCoord &ellipse_point1, const GVCoord &ellipse_point2, std::vector<GVCoord> &ellipsecoords);

/***************************************************************
���ܣ���������Ŀ��Ƶ㣬���������е�����
������������Ƶ�����
���ز������е�����
˵�����е�������ܻ���Ϊ��������ľ�����С��ƫ��
***************************************************************/
 GVCoord calCenterPt(const std::vector<GVCoord>& coords);

/************************************************************************/
/*
* ���ܣ����������е����
* ���룺poly���ߵ�����꣬length�����ܳ���
* �������
* ���أ����
*/
/************************************************************************/
 int getCenterIndex(const std::vector<GVCoord>& poly, double length);

/************************************************************************/
/*
* ���ܣ��жϵ��Ƿ���ͼ���ڲ�
* ���룺x,y ������ꣻpolygon ͼ�εĶ������飬��˳���ŷ�
* �������
* ���أ�true-�����ڣ�false-������
*/
/************************************************************************/
 bool ptInPolygon(double x, double y, const std::vector<GVCoord>& polygon);

/************************************************************************/
/*
* ����ܣ���ȡG1����ֱ��G2��G3�ĶԳƵ�
* ���룺���������G1��G2��G3
* �������
* ���أ�G1�ԳƵ�
*/
/************************************************************************/
 GVCoord getSymPoint(const GVCoord& G1, const GVCoord& G2, const GVCoord& G3);

/************************************************************************/
/*
* ���ܣ���ȡG1��ֱ��G2��G3�ľ���
* ���룺���������G1��G2��G3
* �������
* ���أ�G1��ֱ��G2��G3�ľ���
*/
/************************************************************************/
 double getDisPtToLine(const GVCoord& G1, const GVCoord& G2, const GVCoord& G3);

/***************************************************************
���ܣ���������(start_point, end_point)��x��ļн�
�����������������ʼ��start_point����ֹ��end_point
���ز���������(start_point, end_point)��x��ļнǦ�
˵�������صļнǦ��ǻ����Ƶ�
***************************************************************/
 double calIncludeAngle(const GVCoord &start_point, const GVCoord &end_point);

/***************************************************************
���ܣ���һ������ƽ���ָ��cnt��
������������ߵ����beg_coord���յ�end_coord�����ڱ���ָ������ĵ������linecoords
���ز�������
˵�����ָ�ķ������Ե�����̫��Ļ������ĵ�̫�̫࣬С�Ļ��ָ���ԣ��ָ��ĵ��а������beg_coord���������յ�end_coord
***************************************************************/
 void devideLine(const GVCoord &beg_coord, const GVCoord &end_coord, std::vector<GVCoord> &linecoords);

/************************************************************************/
/*
* ���ܣ���ȡpt��ֱ��spt��ept�ķ�λ
* ���룺���������pt��spt��ept
* �������
* ���أ�1��ʾ��ߣ�-1��ʾ�ұߣ�0��ʾ����
*/
/************************************************************************/
 int isLeftOrRight(const GVCoord& pt, const GVCoord& spt, const GVCoord& ept);

/************************************************************************/
/*
* ���ܣ����������㣬������ݵ�һ������ʱ����ת90�ȵĵ�λ������������Ҫ�󳤶������Ӧ��������
* ���룺���������spt��ept������ʼ��ľ���
* �������
* ���أ���Ӧ�����
*/
/************************************************************************/
 GVCoord getVerticalPt(const GVCoord &startpoint, const GVCoord &endpoint, double dis);

/************************************************************************/
/*
* ���ܣ������������ѻ����ϵĵ�
* ���룺����������������е㣬�Ҽ��������ͷ��λ�������Ҽ�ͷ��λ��������ͷ���߳�/��β���߳� 
* �������
* ���أ����ѻ����ϵĵ�
*/
/************************************************************************/
//  std::vector<GVCoord> getArrowNest(const GVCoord& leftneck, const GVCoord& aux, const GVCoord& rightneck, const osg::Vec3f& dir1, const osg::Vec3f& dir2, double rate);

/************************************************************************/
/*
* ���ܣ����������ߣ����м仡�ߵı�����//�������ר��
* ���룺��n,i��* Pi * (1-t)^(n-i)*t^i
* �������
* ���أ����������ߵ�
*/
/************************************************************************/
 GVCoord getBessel(int n, float t, const std::vector<GVCoord>& points);

/************************************************************************/
/*
* ���ܣ������ͷ�ײ������������㣬˳ʱ�����η����������һ�㣬���ͷ4�㣬�Ҽ�ͷ4�㣬�Ҽ�����һ��
* ���룺��ͷ�ײ�������������
* �������
* ���أ�˳ʱ�����η����������һ�㣬���ͷ4�㣬�Ҽ�ͷ4�㣬�Ҽ�����һ��
*/
/************************************************************************/
 std::vector<GVCoord> getDrawPoints(const GVCoord& bottom_left, const GVCoord& bottom_right, const GVCoord& top_left, const GVCoord& top_right);


/************************************************************************/
/*
* ���ܣ������ͷ�ײ������������㣬����ֵ�����ظ�����
* ���룺�����ͷ�ײ������������㣬����ֵ
* �������
* ���أ�������
*/
/************************************************************************/
 GVCoord getAuxPoint(const GVCoord& bottom_left, const GVCoord& bottom_right, const GVCoord& top_left, const GVCoord& top_right, double rate);

/************************************************************************/
/*
* ���ܣ������ͷβ�����㣬�Ҳ��ͷ���㣬���㷵�ؼ�ͷ���󶥵�
* ���룺��ͷβ�����㣬�Ҳ��ͷ����
* �������
* ���أ���ͷ���󶥵�
*/
/************************************************************************/
 GVCoord getLeftArrowPoints(const GVCoord& left, const GVCoord& right, const GVCoord& arrow);

/************************************************************************/
/*
* ���ܣ������ͷβ�����㣬���㷵�ؼ�ͷ����������
* ���룺��ͷβ������
* �������
* ���أ���ͷ����������
*/
/************************************************************************/
 std::vector<GVCoord> get2ArrowPoints(const GVCoord& left, const GVCoord& right);

/************************************************************************/
/*
* ���ܣ���λ���ȵķ�������
* ���룺����
* �������
* ���أ�
*/
/************************************************************************/
 GVCoord direcVector(const GVCoord& p1, const GVCoord& p2);

/************************************************************************/
/*
* ���ܣ���λ���ȵķ�����
* ���룺����
* �������
* ���أ�
*/
/************************************************************************/
 GVCoord normalVector(const GVCoord& p1, const GVCoord& p2);

/************************************************************************/
/*
* ���ܣ���ֱ�߽���
* ���룺�ĸ���
* �������
* ���أ�
*/
/************************************************************************/
 GVCoord getCrossPoint(const GVCoord& temp_GV1, GVCoord temp_GV2, const GVCoord& temp_GV3, GVCoord temp_GV4);

/************************************************************************/
/*
* ���ܣ���ֱ��G1,G2��ֱ��G3,G4����ƽ��width�õ��Ľ���
* ���룺�ĸ���
* �������
* ���أ�
*/
/************************************************************************/
 GVCoord Get_outpoint(const GVCoord& G1, const GVCoord& G2, const GVCoord& G3, const GVCoord& G4, double width);

/************************************************************************/
/*
* ���ܣ���ת����point0Ϊ����������β��
* ���룺������ʼ�����㡢��ʱ����ת�Ƕȡ����賤��
* ����������ת����point0Ϊ����������β��
* ���أ�
*/
/************************************************************************/
 GVCoord VecChange(const GVCoord& point0, const GVCoord& point1, double angle, double length);

/************************************************************************/
/*
* ���ܣ�������Ƶ������ܳ�
* ���룺����㼯��
* �����
* ���أ�
*/
/************************************************************************/
 double getRoundLength(const std::vector<GVCoord>& controlPoints);

/************************************************************************/
/*
* ���ܣ����������������������ϵĵ�
* ���룺����
* �������
* ���أ������������ϵĵ�
*/
/************************************************************************/
 GVCoord Get_newBezier(const GVCoord& point0, const GVCoord& point1, const double scale0, const double lengthAll, const bool b);

/************************************************************************/
/*
* ���ܣ����㱴��������б��
* ���룺���Ƶ�
* �������
* ���أ�б��
*/
/************************************************************************/
 GVCoord Bessel_deriva(const int m, float t, const std::vector<GVCoord>& _controlPoints);

/************************************************************************/
/*
* ���ܣ����㷵��ĳһ�α���������
* ���룺�������������յ�
* �������
* ���أ����������ߵ�
*/
/************************************************************************/
 std::vector<GVCoord> getBezierPts(const std::vector<GVCoord>& bPts, const std::vector<GVCoord>& brPts, int pos);

/************************************************************************/
/*
* ���ܣ�����4�ױ�����
* ���룺�������������յ�
* �������
* ���أ����������ߵ�
*/
/************************************************************************/
 std::vector<GVCoord> getBezierPart(const GVCoord& G1, const GVCoord& G2, const GVCoord& G3, const GVCoord& G4);

/************************************************************************/
/*
* ���ܣ������м�ͼ�α���ֵ�����5������ֵ��
* ���룺���������㣬���Ƶ㼯��
* �������
* ���أ��м�ͼ�α���ֵ
*/
/************************************************************************/
 std::vector<double> getCenterScales(const GVCoord& center, const GVCoord& pSize, const GVCoord& angle, const std::vector<GVCoord>& bPts);

/************************************************************************/
/*
* ���ܣ�������ά��������x��нǶ���
* ���룺
* �������
* ���أ���x��нǶ���
*/
/************************************************************************/
 double cal_angle(GVCoord dir);
 double cal_angle(const GVCoord &coord0, const GVCoord &coord1);

/************************************************************************/
/*
* ���ܣ��ж��������Ƿ��ཻ
* ���룺
* �������
* ���أ��ཻ����true�����ཻ����false
*/
/************************************************************************/
 bool ifCross(const GVCoord& coord0, const GVCoord& coord1, const GVCoord& coord2);

/************************************************************************/
/*
* ���ܣ��������㼰����Ĳ�ֵ��,������ĸ�����insertpoints��ֵ����Ŀ(������ʼ��)�������������insertsize
* ���룺����
* �������
* ���أ���
*/
/************************************************************************/
 void Insert_TwoPoints(const GVCoord start_point, const GVCoord end_point, int* insertsize, std::vector<GVCoord>* insertpoints);

/*********************************************************************************
���ܣ������������ʱ����ת�������ϵ�ж�Ӧ������
��������������in_coord��������ʱ����ת������ϵx������beg_coord���յ�end_coord
���ز�������ת��ĵ������
˵������ת���ĵ�Ϊbeg_coord��2016.7.20�޸�
**********************************************************************************/
GVCoord rotate(const GVCoord &in_coord, const GVCoord &beg_coord, const GVCoord &end_coord);

/******************************************************************************
���ܣ���������������ĵ���ʱ����תһ���ǶȺ�ĵ������
��������������in_coord����ת���ĵ�center_coord���Ƕ�angle
���ز�������ת��ĵ������
*******************************************************************************/
 GVCoord rotate_by_angle(const GVCoord &in_coord, const GVCoord &center_coord, double angle);

 GVCoord getTail(const std::vector<GVCoord> &points, const GVCoord& head);
//���������ϵĵ�ͼ�ͷͷ������,�����ͷ�����Ķ�����
 int get_Tailpos(const std::vector<GVCoord> &points, GVCoord head);

/***�������㣬ǰ������Ϊ��ʼ��������һ��Ϊ�ƶ���
****����ƶ�����������ʼ�����ĵ�*********BY LH*/
 GVCoord fixPoint(const GVCoord& start_point, const GVCoord& end_point, const GVCoord& fixed_point);

/***�������㣬ǰ������Ϊ�Ƚ��ߣ���һ��Ϊ�Ƚϵ�
****����������˼����ֵ��������Ϊ0��������Ϊ1
****���judge,����0Ϊ��С��0Ϊ��*****BY LH*/
 int Judgeleft_right(const GVCoord& start_point, const GVCoord& end_point, const GVCoord& judge_point);


 GVCoord Get_dir(std::vector<GVCoord>& vtxBuffer, int idx);

/****�ж������ڵ�������Ƿ���ȫ��ͬ****/
 bool all_the_same(const std::vector<GVCoord> &points);

//��ͨ���������Ƶ�������ε��㷨��ȡ��������ʱ�����
 std::vector<GVCoord> sectorPoints(const std::vector<GVCoord>& m_controlPoints, const std::vector<GVCoord>& controlPoints);

 int getIDbyLen(std::vector<GVCoord> &vtxBuffer, double length);

 double getAngle(GVCoord coord0, GVCoord coord1);

//���㱴���������ϵĸ������Լ�����ֵ
 void get3brPts(std::vector<GVCoord> bPts, std::vector<GVCoord> &brPts, std::vector<double> &rates, double length);
//�ж���������й��ɵ�Ȧ��˳ʱ�뻹����ʱ�룬˳ʱ�뷵��1����ʱ�뷵��-1
 int getClockWise(std::vector<GVCoord> bPts);

//���ر����������ϵȼ���ĵ�
 std::vector<int> Get_trianglePointsIndex(std::vector<GVCoord> _bezierPoints, double _lengthInter);

/******************************************************************************
���ܣ���������������ĵ���ʱ����תһ���ǶȺ�ĵ������
��������������in_coord����ת���ĵ�center_coord���Ƕ�angle
���ز�������ת��ĵ������
*******************************************************************************/
// GVCoord rotate_by_angle(const GVCoord &in_coord, const GVCoord &center_coord, double angle);
//����Բ���� ����Բ��һ��
 GVCoord Get_round(const GVCoord& temp_GV1, double r, double angle);

//////////////////////////////////////////////////////////////////////////
//25203
//�����������
//  std::vector<GVCoord> getArrowNest_25203(GVCoord leftneck, GVCoord aux, GVCoord rightneck, osg::Vec3d dir1, osg::Vec3d dir2, double rate);
 GVCoord Bessel_GV25203(int n, float t, std::vector<GVCoord> _controlPoints);
 std::vector<GVCoord> getDrawPoints_25203(GVCoord bottom_left, GVCoord bottom_right, GVCoord top_left, GVCoord top_right);
 GVCoord getAuxPoint_25203(GVCoord bottom_left, GVCoord bottom_right, GVCoord top_left, GVCoord top_right, double rate);
 GVCoord getLeftArrowPoints_25203(GVCoord left, GVCoord right, GVCoord arrow);
 std::vector<GVCoord> get2ArrowPoints_25203(GVCoord left, GVCoord right);

//25204
 std::vector<GVCoord> get2ArrowPoints_25204(GVCoord left, GVCoord right);
 GVCoord getLeftArrowPoints_25204(GVCoord left, GVCoord right, GVCoord arrow);
 GVCoord getAuxPoint_25204(GVCoord bottom_left, GVCoord bottom_right, GVCoord top_left, GVCoord top_right, double rate);
 std::vector<GVCoord> getDrawPoints_25204(GVCoord bottom_left, GVCoord bottom_right, GVCoord top_left, GVCoord top_right);
//  std::vector<GVCoord> getArrowNest_25204(GVCoord leftneck, GVCoord aux, GVCoord rightneck, osg::Vec3f dir1, osg::Vec3f dir2, double rate);
 GVCoord Bessel_GV25204(int n, float t, std::vector<GVCoord> _controlPoints);

//25205
//���빹��������ͷ�ļ�β����������ͷ���㣬����������ͷ����ľ��룬���ؼ�����
 GVCoord getNeckPoint_25205(GVCoord tail, GVCoord body, GVCoord head, double dis);
//�������������ͷ�ļ�β�����������ͷ������ֵ ��������ͷ��ļ��Ѹ�����
 GVCoord getNestPoint_25205(GVCoord lefttail, GVCoord leftbody, GVCoord lefthead, GVCoord rightail, GVCoord rightbody, GVCoord righthead, double scale);
//���빹�ɼ�ͷ�������Լ�������tag=1���������ߣ�tag = -1�������һ���
 std::vector<GVCoord> getArcPoints_25205(GVCoord tail, GVCoord body, GVCoord head, GVCoord neck, int tag);
//�����ͷ���㣬������˳ʱ�뷵�ؼ�ͷ��5��
 std::vector<GVCoord> getArrowPoints_25205(GVCoord head, GVCoord neck);
//����������������е㣬�Ҽ��������ͷ��λ�������Ҽ�ͷ��λ���������ؼ��ѻ����ϵĵ�
//  std::vector<GVCoord> getArrowNest_25205(GVCoord leftneck, GVCoord aux, GVCoord rightneck, osg::Vec3f dir1, osg::Vec3f dir2);
//���м仡�ߵı�����//�������ר��
 GVCoord Bessel_GV25205(int n, float t, std::vector<GVCoord> _controlPoints);
//��ȡ��ͷ������˳��
 std::vector<int> GetOrder_GV25205(std::vector<GVCoord> basicPoints);



#endif 
