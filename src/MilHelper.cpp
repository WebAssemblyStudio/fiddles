#include <GVMilUtil/MilHelper.h>
#include <GVMilUtil/Bezier.h>

#include <math.h>

#define MILHELPER_PI 3.1415926

double distance(const GVCoord &beg_coord, const GVCoord &end_coord)
{
	return sqrt(pow((end_coord.lon - beg_coord.lon), 2) + pow((end_coord.lat - beg_coord.lat), 2));
}

void getCircle(const GVCoord &circle_center, double radius, std::vector<GVCoord> &circlecoords)
{
	for (double radian = 0.0; (radian - 2 * MILHELPER_PI) <= 1E-8; radian += (MILHELPER_PI / 180))
		circlecoords.push_back(GVCoord(circle_center.lon + radius * cos(radian), circle_center.lat + radius * sin(radian), 0.0));
	circlecoords.push_back(GVCoord(circle_center.lon + radius * cos(0.0), circle_center.lat + radius * sin(0.0), 0.0));	//��ֹ�򸡵����㾫�����⵼��Բ���ܱպ�
}

void getEllipse(const GVCoord &ellipse_center, const GVCoord &ellipse_point1, const GVCoord &ellipse_point2, std::vector<GVCoord> &ellipsecoords)
{
	double axis1_len = distance(ellipse_center, ellipse_point1);
	double axis2_len = distance(ellipse_center, ellipse_point2);
	for (double radian = 0.0; (radian - 2 * MILHELPER_PI) <= EPS; radian += (MILHELPER_PI / 180))
		ellipsecoords.push_back(rotate(GVCoord(ellipse_center.lon + axis2_len * cos(radian), ellipse_center.lat + axis1_len * sin(radian), 0.0), ellipse_center, ellipse_point2));
	ellipsecoords.push_back(rotate(GVCoord(ellipse_center.lon + axis2_len * cos(0.0), ellipse_center.lat + axis1_len * sin(0.0), 0.0), ellipse_center, ellipse_point2));
}

double getLengthOfAll(const std::vector<GVCoord>& coords)
{
	double len = 0.0;
	for (int i = 0; i < coords.size() - 1; i++)
	{
		len += distance(coords[i], coords[i + 1]);
	}
	return len;
}

GVCoord calCenterPt(const std::vector<GVCoord>& coords)
{
	GVCoord centerPoint;
	double total_len = 0.0, sum_len = 0.0;
	std::vector<GVCoord>::const_iterator tmp = coords.begin();

	while (tmp != coords.end() - 1)
	{
		total_len += distance(*tmp, *(tmp + 1));
		++tmp;
	}

	tmp = coords.begin();
	for (; tmp != coords.end() - 1; ++tmp)
	{
		sum_len += distance(*tmp, *(tmp + 1));
		if ((sum_len - total_len / 2.0) >= EPS)
		{
			double delta_len = total_len / 2.0 - (sum_len - distance(*tmp, *(tmp + 1)));
			centerPoint.lon = (*tmp).lon + delta_len / distance(*tmp, *(tmp + 1)) * ((*(tmp + 1)).lon - (*tmp).lon);
			centerPoint.lat = (*tmp).lat + delta_len / distance(*tmp, *(tmp + 1)) * ((*(tmp + 1)).lat - (*tmp).lat);
			centerPoint.alt = 0.0;
			break;
		}
	}
	return centerPoint;
}

int getCenterIndex(const std::vector<GVCoord>& poly, double length)
{
	double len = 0.0;
	double hLen = length / 2.0f;
	for (int i = 0; i < poly.size() - 1; i++)
	{
		len += distance(poly[i], poly[i + 1]);
		if (len >= hLen)
			return i;
	}
	return -1;
}

bool ptInPolygon(double x, double y, const std::vector<GVCoord>& polygon)
{
	int polySides = polygon.size();
	int i, j = polySides - 1;
	bool oddNodes = false;
	for (i = 0; i < polySides; i++)
	{
		if ((polygon[i].lat < y&&polygon[j].lat >= y || polygon[j].lat < y&&polygon[i].lat >= y) && (polygon[i].lon <= x || polygon[j].lon <= x))
		{
			oddNodes ^= (polygon[i].lon + (y - polygon[i].lat) / (polygon[j].lat - polygon[i].lat)*(polygon[j].lon - polygon[i].lon) < x);
		}
		j = i;
	}
	return oddNodes;
}

GVCoord getSymPoint(const GVCoord& G1, const GVCoord& G2, const GVCoord& G3)
{
	double height;   //G1��G2��G3�ľ���,  2*���/�ױ߳�
	height = fabs((G1.lon - G2.lon)*(G3.lat - G2.lat) - (G1.lat - G2.lat)*(G3.lon - G2.lon))
		/ distance(G2, G3);
	//G3��G2��������,����λ����
	GVCoord direct = GVCoord(G3.lon - G2.lon, G3.lat - G2.lat, 0);
	direct.normalize();
	//�ж�G1��G2,G3����һ��
	double t = (G2.lon - G1.lon)*(G3.lat - G1.lat) - (G3.lon - G1.lon)*(G2.lat - G1.lat);
	double side = t > 0 ? -1 : t < 0 ? 1 : 0;    //-1��ʾ��ߣ�1��ʾ�ұߣ�0��ʾ����

	GVCoord symPoint = G1;
	symPoint.lon -= direct.lat * 2.0 * height * side;
	symPoint.lat += direct.lon * 2.0 * height * side;

	return symPoint;
}

double getDisPtToLine(const GVCoord& G1, const GVCoord& G2, const GVCoord& G3)
{
	double dis = 0.0f;   //G1��G2,G3���ߵľ���,  2*���/�ױ߳�
	double cross = (G2.lon - G1.lon)*(G3.lat - G1.lat) - (G3.lon - G1.lon)*(G2.lat - G1.lat);

	dis = fabs(cross) / distance(G2, G3);
	return dis;
}

double calIncludeAngle(const GVCoord &start_point, const GVCoord &end_point)
{
	double x01 = end_point.lon - start_point.lon;
	double y01 = end_point.lat - start_point.lat;
	double alpha;	//����(start_point, end_point)��x��ļн�

	if (fabs(x01) <= EPS)
	{
		alpha = MILHELPER_PI / 2.0;
		if (y01 < 0)
			alpha = -alpha + MILHELPER_PI * 2.0;
	}
	else
		alpha = atan(y01 / x01);
	if (x01 < 0)
		alpha += MILHELPER_PI;
	else if (y01 < 0)
		alpha += 2.0 * MILHELPER_PI;
	return alpha;
}

void devideLine(const GVCoord &beg_coord, const GVCoord &end_coord, std::vector<GVCoord> &linecoords)
{
	int cnt = 500;	//�ָ�ķ���
	double len = distance(beg_coord, end_coord);
	double delta_len = len / cnt;

	for (int i = 0; i != cnt; ++i)
		linecoords.push_back(GVCoord(beg_coord.lon + i * delta_len / len * (end_coord.lon - beg_coord.lon), beg_coord.lat + i * delta_len / len * (end_coord.lat - beg_coord.lat), 0.0));
}

int isLeftOrRight(const GVCoord& pt, const GVCoord& spt, const GVCoord& ept)
{
	double t = (spt.lon - pt.lon)*(ept.lat - pt.lat) - (ept.lon - pt.lon)*(spt.lat - pt.lat);
	return t > 0.0f ? 1 : t < 0.0f ? -1 : 0;
}

//���������㣬������ݵ�һ������ʱ����ת90�ȵĵ�λ������������Ҫ�󳤶������Ӧ������
GVCoord getVerticalPt(const GVCoord &startpoint, const GVCoord &endpoint, double dis)
{
	GVCoord spinvector;
	double lenthxy = distance(startpoint, endpoint);
	double xvector = (endpoint.lon - startpoint.lon) * dis / lenthxy;
	double yvector = (endpoint.lat - startpoint.lat) * dis / lenthxy;
	spinvector.lon = startpoint.lon - yvector;
	spinvector.lat = startpoint.lat + xvector;
	spinvector.alt = 0.0f;
	return spinvector;
}

//����������������е㣬�Ҽ��������ͷ��λ�������Ҽ�ͷ��λ��������ͷ���߳� / ��β���߳�               ���ؼ��ѻ����ϵĵ�
std::vector<GVCoord> getArrowNest(const GVCoord& leftneck, const GVCoord& aux, const GVCoord& rightneck, const GVCoord& dir1, const GVCoord& dir2, double rate)
{
	double auxlr;//���Ѵ�������ƫ����/��ͷ���߳�
	if (rate < 0.4)
	{
		auxlr = 0.4;
	}
	else if (rate < 1 && rate >= 0.4)
	{
		auxlr = 0.4;
	}
	else
	{
		auxlr = 0.4 - 0.1*rate;
		if (rate > 3)
		{
			auxlr = 0.1;
		}
	}
	double ldis = distance(leftneck, aux);
	double rdis = distance(rightneck, aux);
	//�����λ�����������
	std::vector<GVCoord> result;
	GVCoord templeft, tempright; //���������߸����㣬�������ؼ�ͷ������ƽ��һ�ξ���õ�
	GVCoord auxleft, auxright;   //aux��leftneck-leftneck��������ƽ�Ƶõ�����֤���α��������Ӵ�ƽ��
	std::vector<GVCoord> controls;
	//�����߻���
	templeft = leftneck;
	templeft.lon -= 0.4 * distance(leftneck, aux) * dir1.lon;
	templeft.lat -= 0.4 * distance(leftneck, aux) * dir1.lat;
	auxleft = aux;
	auxleft.lon += auxlr * (ldis / rdis) * (leftneck.lon - rightneck.lon);
	auxleft.lat += auxlr * (ldis / rdis) * (leftneck.lat - rightneck.lat);
	controls.clear();
	controls.push_back(leftneck);
	controls.push_back(templeft);
	controls.push_back(auxleft);
	controls.push_back(aux);
	for (double t = 0; t <= 100; t++)
	{
		result.push_back(getBessel(4, t / 100.0, controls));
	}
	//���Ұ�߻���
	tempright = rightneck;
	tempright.lon -= 0.4 * distance(rightneck, aux) * dir2.lon;
	tempright.lat -= 0.4 * distance(rightneck, aux) * dir2.lat;
	auxright = aux;
	auxright.lon -= auxlr * (rdis / ldis) * (leftneck.lon - rightneck.lon);
	auxright.lat -= auxlr * (rdis / ldis) * (leftneck.lat - rightneck.lat);
	controls.clear();
	controls.push_back(aux);
	controls.push_back(auxright);
	controls.push_back(tempright);
	controls.push_back(rightneck);
	for (double t = 0; t <= 100; t++)
	{
		result.push_back(getBessel(4, t / 100.0, controls));
	}
	return result;
}

/*--���������� ��n,i��* Pi * (1-t)^(n-i)*t^i---*/
GVCoord getBessel(int n, float t, const std::vector<GVCoord>& points)
{
	GVCoord bessel;
	bessel.alt = 0;
	bessel.lat = 0;
	bessel.lon = 0;
	float i, j, k;
	int index;
	float temp = 1, temp_alt, temp_lat, temp_lon;
	for (i = 0; i <= n - 1; i++)
	{
		temp = 1;
		for (j = 0; j < n - i - 1; j++)
		{
			temp = temp*(1 - t);
		}
		for (k = 1; k <= i; k++)
		{
			temp = temp*t;
			temp = temp*(n - k) / k;
		}
		index = i;
		temp_alt = temp*points[index].alt;
		temp_lat = temp*points[index].lat;
		temp_lon = temp*points[index].lon;
		bessel.alt = bessel.alt + temp_alt;
		bessel.lat = bessel.lat + temp_lat;
		bessel.lon = bessel.lon + temp_lon;
	}
	return bessel;
}

//�����ͷ�ײ������������㣬˳ʱ�����η����������һ�㣬���ͷ4�㣬�Ҽ�ͷ4�㣬�Ҽ�����һ��
std::vector<GVCoord> getDrawPoints(const GVCoord& bottom_left, const GVCoord& bottom_right, const GVCoord& top_left, const GVCoord& top_right)
{
	std::vector<GVCoord> result;
	//�����ͷβ�������󡱷���ƽ�Ƶײ����ȵ�0.2���õ�һ�㣬������������ͷ���㣬0.5��Ϊ�������һ�㣬0.8��Ϊ��ͷ
	GVCoord left, right; //ƽ�Ƶõ��ĵ�
	GVCoord arrleft, arrright;  //���Ҽ�����һ��
	GVCoord neck, ear, sym_neck, sym_ear;  //�����������Լ��Գ�
	//�����ƽ�Ƶõ��ĵ�
	left = bottom_left;
	left.lon += (bottom_left.lon - bottom_right.lon)*0.20;
	left.lat += (bottom_left.lat - bottom_right.lat)*0.20;
	//��������ϵĵ�
	arrleft.alt = (left.alt + top_left.alt) / 2.0;
	arrleft.lon = (left.lon + top_left.lon) / 2.0;
	arrleft.lat = (left.lat + top_left.lat) / 2.0;
	result.push_back(arrleft);
	//�����ͷ��ߵļ���������
	neck.lon = left.lon + 0.82*(top_left.lon - left.lon) - 0.03*(top_left.lat - left.lat);
	neck.lat = left.lat + 0.82*(top_left.lat - left.lat) + 0.03*(top_left.lon - left.lon);
	neck.alt = left.alt;
	sym_neck = getSymPoint(neck, top_left, left);

	ear.lon = left.lon + 0.75*(top_left.lon - left.lon) - 0.1*(top_left.lat - left.lat);
	ear.lat = left.lat + 0.75*(top_left.lat - left.lat) + 0.1*(top_left.lon - left.lon);
	ear.alt = left.alt;
	sym_ear = getSymPoint(ear, top_left, left);
	//˳ʱ�����δ洢
	int side = isLeftOrRight(top_right, bottom_left, bottom_right);
	if (side == -1)
	{
		result.push_back(sym_neck);
		result.push_back(sym_ear);
		result.push_back(ear);
		result.push_back(neck);
	}
	else
	{
		result.push_back(neck);
		result.push_back(ear);
		result.push_back(sym_ear);
		result.push_back(sym_neck);
	}

	//ͬ�����ұߵ�
	//���ұ�ƽ�Ƶõ��ĵ�
	right = bottom_right;
	right.lon -= (bottom_left.lon - bottom_right.lon)*0.20;
	right.lat -= (bottom_left.lat - bottom_right.lat)*0.20;
	//���Ҽ����ϵĵ�
	arrright.alt = (right.alt + top_right.alt) / 2.0;
	arrright.lon = (right.lon + top_right.lon) / 2.0;
	arrright.lat = (right.lat + top_right.lat) / 2.0;

	//���Ҽ�ͷ��ߵļ���������
	neck.lon = right.lon + 0.82*(top_right.lon - right.lon) - 0.03*(top_right.lat - right.lat);
	neck.lat = right.lat + 0.82*(top_right.lat - right.lat) + 0.03*(top_right.lon - right.lon);
	neck.alt = right.alt;
	sym_neck = getSymPoint(neck, top_right, right);

	ear.lon = right.lon + 0.75*(top_right.lon - right.lon) - 0.1*(top_right.lat - right.lat);
	ear.lat = right.lat + 0.75*(top_right.lat - right.lat) + 0.1*(top_right.lon - right.lon);
	ear.alt = right.alt;
	sym_ear = getSymPoint(ear, top_right, right);
	//˳ʱ�����δ洢
	if (side == -1)
	{
		result.push_back(sym_neck);
		result.push_back(sym_ear);
		result.push_back(ear);
		result.push_back(neck);
	}
	else
	{
		result.push_back(neck);
		result.push_back(ear);
		result.push_back(sym_ear);
		result.push_back(sym_neck);
	}
	result.push_back(arrright);
	return result;
}

//�����ͷ�ײ������������㣬����ֵ�����ظ�����
GVCoord getAuxPoint(const GVCoord& bottom_left, const GVCoord& bottom_right, const GVCoord& top_left, const GVCoord& top_right, double rate)
{
	GVCoord bottom_central, top_central;
	//��ײ����������е�
	bottom_central.alt = (bottom_left.alt + bottom_right.alt) / 2.0;
	bottom_central.lon = (bottom_left.lon + bottom_right.lon) / 2.0;
	bottom_central.lat = (bottom_left.lat + bottom_right.lat) / 2.0;
	top_central.alt = (top_left.alt + top_right.alt) / 2.0;
	top_central.lon = (top_left.lon + top_right.lon) / 2.0;
	top_central.lat = (top_left.lat + top_right.lat) / 2.0;
	//���ݱ���ֵ���������
	GVCoord aux = bottom_central;
	aux.lon += rate * (top_central.lon - bottom_central.lon);
	aux.lat += rate * (top_central.lat - bottom_central.lat);
	return aux;
}

//�����ͷβ�����㣬���㷵�ؼ�ͷ����������
std::vector<GVCoord> get2ArrowPoints(const GVCoord& left, const GVCoord& right)
{
	GVCoord central;//����β����е�
	GVCoord topleft, topright; //�����������ͷ����
	central.alt = (left.alt + right.alt) / 2.0;
	central.lon = (left.lon + right.lon) / 2.0;
	central.lat = (left.lat + right.lat) / 2.0;

	//����ͷ������е�
	central.lon -= (right.lat - left.lat);
	central.lat += (right.lon - left.lon);

	//����ͷ����ֱ��صױ߷���ƽ��0.1����
	topleft = topright = central;
	topleft.lon += (left.lon - right.lon) / 10.0;
	topleft.lon += (left.lon - right.lon) / 10.0;
	topright.lon += (right.lon - left.lon) / 10.0;
	topright.lon += (right.lon - left.lon) / 10.0;
	std::vector<GVCoord> result;
	result.push_back(topleft);
	result.push_back(topright);
	return result;
}

//�����ͷβ�����㣬�Ҳ��ͷ���㣬���㷵�ؼ�ͷ���󶥵�
GVCoord getLeftArrowPoints(const GVCoord& left, const GVCoord& right, const GVCoord& arrow)
{
	GVCoord top;//���ͷ����
	GVCoord bottom_central, top_central;  //�ײ������������е�
	bottom_central.alt = (left.alt + right.alt) / 2.0;
	bottom_central.lon = (left.lon + right.lon) / 2.0;
	bottom_central.lat = (left.lat + right.lat) / 2.0;

	double height;   //arrow���ײ��������ߵľ���,  2*���/�ױ߳�
	height = fabs((right.lon - left.lon)*(arrow.lat - left.lat) - (right.lat - left.lat)*(arrow.lon - left.lon))
		/ distance(left, right);
	//�ױ������㷽������,����λ����
	GVCoord direct = GVCoord(right.lon - left.lon, right.lat - left.lat, 0);
	direct.normalize();
	int side = isLeftOrRight(arrow, left, right);
	direct = direct*side;
	//����������е�
	top_central = bottom_central;
	top_central.lon -= height*direct.lat;
	top_central.lat += height*direct.lon;

	//���ͷ������arrow����top_central�Գ�
	top.alt = arrow.alt;
	top.lon = top_central.lon + (top_central.lon - arrow.lon);
	top.lat = top_central.lat + (top_central.lat - arrow.lat);

	return top;
}

// ��λ���ȵķ�������
GVCoord direcVector(const GVCoord& p1, const GVCoord& p2)
{
	GVCoord vec;
	double length = distance(p1, p2);
	vec.lon = (p2.lon - p1.lon) / length;
	vec.lat = (p2.lat - p1.lat) / length;
	return vec;
}
// ��λ���ȵķ�����
GVCoord normalVector(const GVCoord& p1, const GVCoord& p2)
{
	GVCoord normal;
	double length = distance(p1, p2);
	normal.lon = (p2.lat - p1.lat) / length;
	normal.lat = (p1.lon - p2.lon) / length;
	return normal;
}

GVCoord getCrossPoint(const GVCoord& temp_GV1, GVCoord temp_GV2, const GVCoord& temp_GV3, GVCoord temp_GV4)
{
	GVCoord R;
	if (temp_GV2.lat == temp_GV1.lat)
	{
		temp_GV2.lat += 0.0001f;
	}
	if (temp_GV4.lat == temp_GV3.lat)
	{
		temp_GV4.lat += 0.0001f;
	}

	if (((temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat)) - ((temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat)) == 0)
	{
		return temp_GV4;
	}
	else
	{
		R.lat = ((temp_GV3.lon - (temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat)*temp_GV3.lat)  //(b2
			- (temp_GV1.lon - (temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat)*temp_GV1.lat))       //-b1)
			/ (((temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat))    //  /(k1
			- ((temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat)));    //  -k2);
		R.lon = (((temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat))  //(k1
			*(temp_GV3.lon - (temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat)*temp_GV3.lat)  // *b2
			- ((temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat))                           //  -k2
			*(temp_GV1.lon - (temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat)*temp_GV1.lat))   //*b1)
			/ (((temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat))    //  /(k1
			- ((temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat)));    //  -k2);
		return R;
	}
}

GVCoord Get_outpoint(const GVCoord& G1, const GVCoord& G2, const GVCoord& G3, const GVCoord& G4, double width)
{
	GVCoord R, temp_GV1, temp_GV2, temp_GV3, temp_GV4;
	GVCoord dir1 = GVCoord(G2.lon - G1.lon, G2.lat - G1.lat, 0.0);
	dir1.normalize();
	GVCoord dir2 = GVCoord(G4.lon - G3.lon, G4.lat - G3.lat, 0.0);
	dir2.normalize();
	temp_GV1 = G1;
	temp_GV1.lat += width*dir1.lon;
	temp_GV1.lon -= width*dir1.lat;
	temp_GV2 = G2;
	temp_GV2.lat += width*dir1.lon;
	temp_GV2.lon -= width*dir1.lat;

	temp_GV3 = G3;
	temp_GV3.lat += width*dir2.lon;
	temp_GV3.lon -= width*dir2.lat;
	temp_GV4 = G4;
	temp_GV4.lat += width*dir2.lon;
	temp_GV4.lon -= width*dir2.lat;
	R.alt = G3.alt;
	if( fabs(temp_GV2.lat - temp_GV1.lat) < 1E-8) 
	{
		temp_GV2.lat += 0.01;
	}
	if( fabs(temp_GV4.lat - temp_GV3.lat) < 1E-8 )
	{
		temp_GV4.lat += 0.01;
	}
	if ( ( (temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat)  
	    -  (temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat) ) == 0)
	{
		return temp_GV4;
	}
	else
	{
		double b1,b2,k1,k2;
		b1 = temp_GV1.lon - (temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat)*temp_GV1.lat;
		b2 = temp_GV3.lon - (temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat)*temp_GV3.lat;
		k1 = (temp_GV2.lon - temp_GV1.lon) / (temp_GV2.lat - temp_GV1.lat);
		k2 = (temp_GV4.lon - temp_GV3.lon) / (temp_GV4.lat - temp_GV3.lat);

		if( fabs(k1 - k2) < 1E-8 )
		{
			R.lat = b2 - b1;
			R.lon = k1 * b2 - k2 *b1;
		}
		else
		{
			R.lat = (b2 - b1) / (k1 - k2);
			R.lon = (k1 * b2 - k2 * b1 )/ (k1 - k2);
		}


		return R;
	}
}

GVCoord VecChange(const GVCoord& point0, const GVCoord& point1, double angle, double length)
{
	GVCoord result;
	double d01 = sqrt((point0.lat - point1.lat) * (point0.lat - point1.lat) + (point0.lon - point1.lon) * (point0.lon - point1.lon));
	double x = (point1.lon - point0.lon) / d01;
	double y = (point1.lat - point0.lat) / d01;
	double z = (point1.alt - point0.alt) / d01;
	result.lon = point0.lon + (x * cos(angle) - y * sin(angle)) * length;
	result.lat = point0.lat + (x * sin(angle) + y * cos(angle)) * length;
	result.alt = point0.alt + z * length;
	return result;
}

double getRoundLength(const std::vector<GVCoord>& controlPoints)
{
	double len = 0.0;							//��λ������֮�ͣ���β��������
	for (int i = 0; i < controlPoints.size() - 3; i++)
	{
		len += sqrt((controlPoints[i + 1].lon - controlPoints[i].lon) * (controlPoints[i + 1].lon - controlPoints[i].lon) + (controlPoints[i + 1].lat - controlPoints[i].lat) * (controlPoints[i + 1].lat - controlPoints[i].lat));
	}
	return len;
}

GVCoord Get_newBezier(const GVCoord& point0, const GVCoord& point1, const double scale0, const double lengthAll, const bool b)
{
	GVCoord newBezier;
	GVCoord dvs1, dvs2, dvs3;
	dvs1 = direcVector(point0, point1);
	if (b == 1)
	{
		dvs2.lon = -dvs1.lat;
		dvs2.lat = dvs1.lon;
		dvs2.alt = 0.0;
	}
	else
	{
		dvs2.lon = dvs1.lat;
		dvs2.lat = -dvs1.lon;
		dvs2.alt = 0.0;
	}
	newBezier.lon = point0.lon + dvs2.lon * scale0 * lengthAll;
	newBezier.lat = point0.lat + dvs2.lat * scale0 * lengthAll;
	return newBezier;
}

GVCoord Bessel_deriva(const int m, float t, const std::vector<GVCoord>& _controlPoints)
{
	int n;
	n = m - 1;
	GVCoord bessel;
	bessel.alt = 0;
	bessel.lat = 0;
	bessel.lon = 0;
	float i, j, k;
	float temp = 1, temp_alt, temp_lat, temp_lon;
	if (t == 0)
	{
		t = 0.01;
	}
	if (t == 1)
	{
		t = 0.99;
	}
	for (i = 0; i <= n; i++)
	{
		temp = 1;
		for (j = 0; j < n - i - 1; j++)
		{
			temp = temp*(1 - t);
		}
		if (n - i - 1 < 0)
		{
			temp /= (1 - t);
		}
		for (k = 1; k < i; k++)
		{
			temp = temp*t;
		}
		if (i == 0)
		{
			temp /= t;
		}
		for (k = 1; k <= i; k++)
		{
			temp = temp*(n - k + 1) / k;
		}
		temp = temp*(i - n*t);
		temp_alt = temp*_controlPoints[i].alt;
		temp_lat = temp*_controlPoints[i].lat;
		temp_lon = temp*_controlPoints[i].lon;
		bessel.alt = bessel.alt + temp_alt;
		bessel.lat = bessel.lat + temp_lat;
		bessel.lon = bessel.lon + temp_lon;
	}
	//	temp = sqrt(bessel.alt*bessel.alt + bessel.lat*bessel.lat + bessel.lon*bessel.lon);
	temp = sqrt(bessel.lat*bessel.lat + bessel.lon*bessel.lon);
	bessel.alt = _controlPoints[0].alt;
	bessel.lat = bessel.lat / temp;
	bessel.lon = bessel.lon / temp;
	return bessel;
}

std::vector<GVCoord> getBezierPts(const std::vector<GVCoord>& bPts, const std::vector<GVCoord>& brPts, int pos)
{
	return getBezierPart(bPts[pos], brPts[2 * pos + 1],
		brPts[(2 * pos + 2) % brPts.size()], bPts[(pos + 1) % bPts.size()]);
}

std::vector<GVCoord> getBezierPart(const GVCoord& G1, const GVCoord& G2, const GVCoord& G3, const GVCoord& G4)
{
	std::vector<GVCoord> BezierPoints;
	GVCoord temp;
	for (double i = 0; i <= 100; i++)
	{
		temp.lon = G1.lon * pow((1 - i / 100.0), 3)
			+ 3 * G2.lon * (1 - i / 100.0) * (1 - i / 100.0) * (i / 100.0)
			+ 3 * G3.lon * (1 - i / 100.0) * (i / 100.0) * (i / 100.0)
			+ G4.lon * pow(i / 100.0, 3);
		temp.lat = G1.lat * pow((1 - i / 100.0), 3)
			+ 3 * G2.lat * (1 - i / 100.0) * (1 - i / 100.0) * (i / 100.0)
			+ 3 * G3.lat * (1 - i / 100.0) * (i / 100.0) * (i / 100.0)
			+ G4.lat * pow(i / 100.0, 3);
		temp.alt = G1.alt * pow((1 - i / 100.0), 3)
			+ 3 * G2.alt * (1 - i / 100.0) * (1 - i / 100.0) * (i / 100.0)
			+ 3 * G3.alt * (1 - i / 100.0) * (i / 100.0) * (i / 100.0)
			+ G4.alt * pow(i / 100.0, 3);
		BezierPoints.push_back(temp);
	}
	return BezierPoints;
}

std::vector<double> getCenterScales(const GVCoord& center, const GVCoord& pSize, const GVCoord& angle, const std::vector<GVCoord>& bPts)
{
	double length = 0;//��λ�������ܳ�
	//length += Distance_4900903(bPts[bPts.size()-1], bPts[0]);
	for (int i = 0; i < bPts.size() - 1; i++)
	{
		length += distance(bPts[i], bPts[i + 1]);
	}

	double left, right, top, bottom;//��Ӿ���
	left = right = bPts[0].lon;
	top = bottom = bPts[0].lat;
	for (int i = 1; i < bPts.size(); i++)
	{
		if (bPts[i].lon < left)
		{
			left = bPts[i].lon;
		}
		if (bPts[i].lon > right)
		{
			right = bPts[i].lon;
		}
		if (bPts[i].lat > top)
		{
			top = bPts[i].lat;
		}
		if (bPts[i].lat < bottom)
		{
			bottom = bPts[i].lat;
		}
	}
	std::vector<double> scales;
	//�ڲ��ӱ�Ŵ�С2/3���������ܳ�
	scales.push_back(distance(pSize, center)*2.0 / 3.0 / length);
	//�ڲ��ӱ����x��нǵĴ�С
	GVCoord tm = GVCoord(angle.lon - center.lon, angle.lat - center.lat, 0.0);
	double ang = /*360 - */cal_angle(tm);
	if (ang >= 360)
	{
		ang -= 360;
	}
	scales.push_back(ang);
	//�ڲ��ӱ�Ŵ�С��һ��
	scales.push_back(distance(pSize, center) / 2.0);
	//���ӱ��x - ��Ӿ����е�x�� /  �����ܳ�
	scales.push_back((center.lon - (left + right) / 2.0) / length);
	//���ӱ��y - ��Ӿ����е�y�� /  �����ܳ�
	scales.push_back((center.lat - (top + bottom) / 2.0) / length);
	return scales;
}

double cal_angle(GVCoord dir)
{
	double len = dir.length();
	if (len == 0) return 0;
	double sin_angle = dir.lat / len;
	double cos_angle = dir.lon / len;
	double angle = asin(sin_angle);
	if (sin_angle > 0 && cos_angle < 0) //�ڶ�����
		angle = MILHELPER_PI - angle;
	if (sin_angle < 0 && cos_angle < 0) //��������
		angle = MILHELPER_PI - angle;
	if (sin_angle < 0 && cos_angle>0) //��������
		angle = 2 * MILHELPER_PI + angle;
	return angle / MILHELPER_PI * 180;
}

double cal_angle(const GVCoord &coord0, const GVCoord &coord1)
{
	double len = distance(coord0, coord1);
	if (len == 0) return 0;
	double sin_angle = (coord1.lat - coord0.lat) / len;
	double cos_angle = (coord1.lon - coord0.lon) / len;
	double angle = asin(sin_angle);
	if (sin_angle > 0 && cos_angle < 0 || sin_angle < 0 && cos_angle < 0) 
		angle = MILHELPER_PI - angle;
	return angle;
}

bool ifCross(const GVCoord& coord0, const GVCoord& coord1, const GVCoord& coord2)
{
	if (coord2.lat >= coord1.lat)
	{
		if ((coord2.lat >= coord0.lat) && (coord0.lat >= coord1.lat))
		{
			return true;
		}
	}
	else
	{
		if ((coord2.lat <= coord0.lat) && (coord0.lat <= coord1.lat))
		{
			return true;
		}
	}
	return false;
}

void Insert_TwoPoints(const GVCoord start_point, const GVCoord end_point, int* insertsize, std::vector<GVCoord>* insertpoints)
{
	int accuracy = 50;//��ֵ����
	int count = 0;
	for (double t = 0; t <= 1; t += (1.0 / accuracy))
	{
		double x = t * end_point.lon + (1 - t) * start_point.lon;
		double y = t * end_point.lat + (1 - t) * start_point.lat;
		double z = t * end_point.alt + (1 - t) * start_point.alt;
		insertpoints->push_back(GVCoord(x, y, z));
		count++;
	}
	*insertsize = count;
}

GVCoord rotate(const GVCoord &in_coord, const GVCoord &beg_coord, const GVCoord &end_coord)
{
	double alpha = calIncludeAngle(beg_coord, end_coord);
	GVCoord out_coord;
	out_coord.lon = (in_coord.lon - beg_coord.lon) * cos(alpha) - (in_coord.lat - beg_coord.lat) * sin(alpha) + beg_coord.lon;
	out_coord.lat = (in_coord.lon - beg_coord.lon) * sin(alpha) + (in_coord.lat - beg_coord.lat) * cos(alpha) + beg_coord.lat;
	out_coord.alt = 0.0;
	return out_coord;
}

GVCoord rotate_by_angle(const GVCoord &in_coord, const GVCoord &center_coord, double angle)
{
	GVCoord out_coord;
	out_coord.lon = (in_coord.lon - center_coord.lon) * cos(angle * MILHELPER_PI / 180.0) - (in_coord.lat - center_coord.lat) * sin(angle * MILHELPER_PI / 180.0) + center_coord.lon;
	out_coord.lat = (in_coord.lon - center_coord.lon) * sin(angle * MILHELPER_PI / 180.0) + (in_coord.lat - center_coord.lat) * cos(angle * MILHELPER_PI / 180.0) + center_coord.lat;
	out_coord.alt = 0.0;
	return out_coord;
}

GVCoord getTail(const std::vector<GVCoord> &points, const GVCoord& head)
{
	int pos = get_Tailpos(points, head);
	//���ݹ��ɶ��������
	double c = distance(points[pos], head);
	double b = getDisPtToLine(head, points[pos], points[pos + 1]);
	double a = sqrt(c*c - b*b);
	GVCoord tail;
	GVCoord dir1 = GVCoord(points[pos + 1].lon - points[pos].lon, points[pos + 1].lat - points[pos].lat, 0.0);
	dir1.normalize();
	tail.lon = points[pos].lon + a*dir1.lon;
	tail.lat = points[pos].lat + a*dir1.lat;
	return tail;
}

int get_Tailpos(const std::vector<GVCoord> &points, GVCoord head)
{
	/************************************************************************/
	/* �������߼��ƽ���߻�������,�ж�head��������ȷ�������Ķ�����          */
	/************************************************************************/
	int pos = 0; //�ڵڼ����߶�
	bool left, right;//�Ƿ������ұ߽���
	int cpSize = points.size();
	GVCoord dir1, dir2;
	GVCoord e;
	for (int i = 0; i < cpSize - 1; i++)
	{
		left = true;
		right = true;
		if (true)
		{
			if (i != 0)
			{
				dir1 = GVCoord(points[i - 1].lon - points[i].lon, points[i - 1].lat - points[i].lat, 0.0);
				dir1.normalize();
				dir2 = GVCoord(points[i + 1].lon - points[i].lon, points[i + 1].lat - points[i].lat, 0.0);
				dir2.normalize();
				e.lon = points[i].lon + dir1.lon + dir2.lon;
				e.lat = points[i].lat + dir1.lat + dir2.lat;

			}
			else
			{
				dir2 = GVCoord(points[i + 1].lon - points[i].lon, points[i + 1].lat - points[i].lat, 0.0);
				dir2.normalize();
				e.lon = points[i].lon - dir2.lat;
				e.lat = points[i].lat + dir2.lon;
			}
			if (isLeftOrRight(head, points[i], e)
				!= isLeftOrRight(points[i + 1], points[i], e)
				|| isLeftOrRight(head, points[i], e) == 0)
			{
				left = false;
			}
		}
		if (left)
		{
			if (i != cpSize - 2)
			{
				dir1 = GVCoord(points[i].lon - points[i + 1].lon, points[i].lat - points[i + 1].lat, 0.0);
				dir1.normalize();
				dir2 = GVCoord(points[i + 2].lon - points[i + 1].lon, points[i + 2].lat - points[i + 1].lat, 0.0);
				dir2.normalize();
				e.lon = points[i + 1].lon + dir1.lon + dir2.lon;
				e.lat = points[i + 1].lat + dir1.lat + dir2.lat;
			}
			else
			{
				dir2 = GVCoord(points[i + 1].lon - points[i].lon, points[i + 1].lat - points[i].lat, 0.0);
				dir2.normalize();
				e.lon = points[i + 1].lon - dir2.lat;
				e.lat = points[i + 1].lat + dir2.lon;
			}
			if (isLeftOrRight(head, points[i + 1], e)
				!= isLeftOrRight(points[i], points[i + 1], e)
				|| isLeftOrRight(head, points[i + 1], e) == 0)
			{
				right = false;
			}
		}
		if (left && right)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

GVCoord fixPoint(const GVCoord& start_point, const GVCoord& end_point, const GVCoord& fixed_point)
{
	GVCoord dir1, dir2, dir3, result;
	dir1.lon = end_point.lon - start_point.lon;//��ʼ����
	dir1.lat = end_point.lat - start_point.lat;
	dir1.alt = end_point.alt - start_point.alt;

	dir2.lon = fixed_point.lon - start_point.lon;
	dir2.lat = fixed_point.lat - start_point.lat;
	dir2.lat = fixed_point.lat - start_point.lat;

	dir3.lon = dir1.lon*(dir1.lon*dir2.lon + dir1.lat*dir2.lat) / (pow(dir1.lon, 2) + pow(dir1.lat, 2));
	dir3.lat = dir1.lat*(dir1.lon*dir2.lon + dir1.lat*dir2.lat) / (pow(dir1.lon, 2) + pow(dir1.lat, 2));
	dir3.alt = dir1.alt*(dir1.lon*dir2.lon + dir1.lat*dir2.lat) / (pow(dir1.lon, 2) + pow(dir1.lat, 2));
	result.lon = start_point.lon + dir3.lon;
	result.lat = start_point.lat + dir3.lat;
	result.alt = start_point.alt + dir3.alt;
	return result;
}

int Judgeleft_right(const GVCoord& start_point, const GVCoord& end_point, const GVCoord& judge_point)
{
	double x1 = start_point.lon;
	double y1 = start_point.lat;
	double x2 = end_point.lon;
	double y2 = end_point.lat;
	double x3 = judge_point.lon;
	double y3 = judge_point.lat;
	double judge = (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);
	if (judge > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

GVCoord Get_dir(std::vector<GVCoord>& vtxBuffer, int idx)
{
	double len;
	GVCoord dir;
	if (idx == 0)
	{
		dir.lon = vtxBuffer[1].lon - vtxBuffer[0].lon;
		dir.lat = vtxBuffer[1].lat - vtxBuffer[0].lat;
	}
	else if (idx == vtxBuffer.size() - 1)
	{
		int size = vtxBuffer.size();
		dir.lon = vtxBuffer[size - 1].lon - vtxBuffer[size - 2].lon;
		dir.lat = vtxBuffer[size - 1].lat - vtxBuffer[size - 2].lat;
	}
	else
	{
		GVCoord dir1, dir2;
		GVCoord G1, G2, cen;
		double len1, len2;
		dir1.lon = vtxBuffer[idx].lon - vtxBuffer[idx - 1].lon;
		dir1.lat = vtxBuffer[idx].lat - vtxBuffer[idx - 1].lat;
		len1 = sqrt(dir1.lon*dir1.lon + dir1.lat*dir1.lat);
		dir1.lon /= len1;
		dir1.lat /= len1;
		dir2.lon = vtxBuffer[idx + 1].lon - vtxBuffer[idx].lon;
		dir2.lat = vtxBuffer[idx + 1].lat - vtxBuffer[idx].lat;
		len2 = sqrt(dir2.lon*dir2.lon + dir2.lat*dir2.lat);
		dir2.lon /= len2;
		dir2.lat /= len2;
		G1 = vtxBuffer[idx];
		G2 = vtxBuffer[idx];
		G1.lon -= dir1.lat;
		G1.lat += dir1.lon;
		G2.lon -= dir2.lat;
		G2.lat += dir2.lon;
		cen.lon = (G1.lon + G2.lon) / 2.0;
		cen.lat = (G1.lat + G2.lat) / 2.0;
		dir.lon = cen.lon - vtxBuffer[idx].lon;
		dir.lat = cen.lat - vtxBuffer[idx].lat;
	}
	len = sqrt(dir.lon*dir.lon + dir.lat*dir.lat);
	dir.lon /= len;
	dir.lat /= len;
	if (idx == 0 || idx == vtxBuffer.size() - 1)
	{
		len = dir.lat;
		dir.lat = dir.lon;
		dir.lon = -len;
	}
	return dir;
}

bool all_the_same(const std::vector<GVCoord> &points)
{
	bool flag = true;
	for (std::vector<GVCoord>::size_type i = 0; i < points.size(); ++i)
	for (std::vector<GVCoord>::size_type j = i + 1; j < points.size(); ++j)
	if (points[i].lon != points[j].lon || points[i].lat != points[j].lat)
	{
		flag = false;
		return flag;
	}
	return flag;
}

std::vector<GVCoord> sectorPoints(const std::vector<GVCoord>& m_controlPoints, const std::vector<GVCoord>& controlPoints)
{
	double rad_th1;		//Բ��������x����ʱ��ƫ�ƽǻ���
	double rad_th2;		//Բ���յ����x����ʱ��ƫ�ƽǻ���
	double r1, r2;		//�뾶
	double rad_beta;	//��ֵ�������
	int num;			//��������
	double pi = 3.1415926;

	std::vector<GVCoord> coords;		//������ղ���㼯
	std::vector<GVCoord> temp_coords;	//��ſ��Ƶ�ƫ�ƺ�ĵ㼯

	if (m_controlPoints.size() >= 3)
	{
		temp_coords.push_back(GVCoord(m_controlPoints[1].lon - m_controlPoints[0].lon, m_controlPoints[1].lat - m_controlPoints[0].lat, 0));
		temp_coords.push_back(GVCoord(m_controlPoints[2].lon - m_controlPoints[0].lon, m_controlPoints[2].lat - m_controlPoints[0].lat, 0));

		//��⣺���ε�����ֱ�߱��Ƿ��غϣ��غϲ�������
		if (temp_coords[0].lon == temp_coords[1].lon && temp_coords[0].lat == temp_coords[1].lat)
		{
			return coords;	//����һ��������
		}

		double r1_square = pow(temp_coords[0].lon, 2) + pow(temp_coords[0].lat, 2);
		r1 = sqrt(r1_square);
		double r2_square = pow(temp_coords[1].lon, 2) + pow(temp_coords[1].lat, 2);
		r2 = sqrt(r2_square);

		//����Բ��������x����ʱ��ƫ�ƽǻ���
		//��һ���ޡ��������ޣ������޵��������
		if (temp_coords[0].lon > 0 && temp_coords[0].lat > 0)
		{
			rad_th1 = asin(temp_coords[0].lat / r1);
		}
		else if (temp_coords[0].lon <= 0)
		{
			rad_th1 = pi - asin(temp_coords[0].lat / r1);
		}
		else
		{
			rad_th1 = 2 * pi + asin(temp_coords[0].lat / r1);
		}

		//����Բ���յ����x����ʱ��ƫ�ƽǻ���
		if (temp_coords[1].lon > 0 && temp_coords[1].lat > 0)
		{
			rad_th2 = asin(temp_coords[1].lat / r2);
		}
		else if (temp_coords[1].lon <= 0)
		{
			rad_th2 = pi - asin(temp_coords[1].lat / r2);
		}
		else
		{
			rad_th2 = 2 * pi + asin(temp_coords[1].lat / r2);
		}

		coords.push_back(m_controlPoints[0]);
		coords.push_back(m_controlPoints[1]);
		//����������ֵ�Ƕȼ���Ļ���
		if (rad_th1 >= rad_th2)
		{
			num = (int)((2 * pi - (rad_th1 - rad_th2))*r1 * 5);		//���ݰ뾶�ͼн��Ż��������Ŀ
			//��ͼ�κ�Сʱ��ȷ��Բ����������50����
			if (num <= 50)
			{
				num = 50;
			}
			rad_beta = (2 * pi - (rad_th1 - rad_th2)) / num;
		}
		else if (rad_th1 < rad_th2)
		{
			num = (int)((rad_th2 - rad_th1)*r1 * 5);				//���ݰ뾶�ͼн��Ż��������Ŀ
			//��ͼ�κ�Сʱ��ȷ��Բ����������50����
			if (num <= 50)
			{
				num = 50;
			}
			rad_beta = (rad_th2 - rad_th1) / num;
		}

		//���ݻ��ȺͰ뾶�����������겢ƫ�ƻص�ͼ����
		for (int i = 1; i < num; i++)
		{
			coords.push_back(GVCoord(r1 * cos(rad_th1 + i*rad_beta) + controlPoints[0].lon, r1 * sin(rad_th1 + i*rad_beta) + controlPoints[0].lat, 0));
		}
		//coords.push_back(_controlPoints[2]);
		//�����������Ƶ��޸ĵ�Բ������
		coords.push_back(GVCoord(r1*temp_coords[1].lon / r2 + m_controlPoints[0].lon, r1*temp_coords[1].lat / r2 + m_controlPoints[0].lat, 0));
		coords.push_back(m_controlPoints[0]);
	}
	return coords;
}

int getIDbyLen(std::vector<GVCoord> &vtxBuffer, double length)
{
	if (length <= 0)
	{
		return 0;
	}
	else
	{
		int size = vtxBuffer.size();
		double len = 0;
		int i;
		for (i = 0; i < size - 1; i++)
		{
			len += sqrt((vtxBuffer[i].lon - vtxBuffer[i + 1].lon) * (vtxBuffer[i].lon - vtxBuffer[i + 1].lon)
				+ (vtxBuffer[i].lat - vtxBuffer[i + 1].lat)*(vtxBuffer[i].lat - vtxBuffer[i + 1].lat));
			if (len >= length)
			{
				break;
			}
		}
		return i;
	}
}

double getAngle(GVCoord coord0, GVCoord coord1)
{
	double len = distance(coord0, coord1);
	if (len == 0) return MILHELPER_PI;
	double sin_angle = (coord1.lat - coord0.lat) / len;
	double cos_angle = (coord1.lon - coord0.lon) / len;
	double angle = asin(sin_angle);
	if (sin_angle > 0 && cos_angle < 0 || sin_angle < 0 && cos_angle < 0) angle = MILHELPER_PI - angle;
	return angle;
}

void get3brPts(std::vector<GVCoord> bPts, std::vector<GVCoord> &brPts, std::vector<double> &rates, double length)
{
	/*
	�������ȷ��
	1.������ж�λ����е�
	2.�ض�λ�����е����ߵĴ�ֱ����ƽ��
	//ƽ�Ƶı��������⣬���ݶ�ά��ƽ�Ƶı����ǲ�һ���ģ���֪����μ��㣬����д�˶�ֵ
	*/
	int bPtNum = bPts.size();
	GVCoord front, back;
	GVCoord dir;
	double scale = 0.5;  //���������������������ƫ�Ʊ���
	rates.clear();
	//�����ж�λ����е�
	GVCoord center(0, 0, 0);
	for (int i = 0; i<bPtNum; i++)
	{
		center.lon += bPts[i].lon;
		center.lat += bPts[i].lat;
	}
	center.lon /= bPtNum;
	center.lat /= bPtNum;
	//�ж�˳��ʱ�룬˳ʱ��1����ʱ��-1��Ȼ�����˳��ʱ���жϼ������������Ⱥ�˳��
	int wise = getClockWise(bPts);
	//���㸨����
	for (int i = 0; i<bPtNum; i++)
	{
		dir = GVCoord(-(bPts[i].lat - center.lat),
			bPts[i].lon - center.lon, 0.0);
		front = back = bPts[i];
		front.lon += wise*scale * dir.lon;
		front.lat += wise*scale * dir.lat;
		back.lon -= wise*scale * dir.lon;
		back.lat -= wise*scale * dir.lat;
		brPts.push_back(front);
		brPts.push_back(back);
		rates.push_back((front.lon - bPts[i].lon) / length);
		rates.push_back((bPts[i].lat - front.lat) / length);
		rates.push_back((back.lon - bPts[i].lon) / length);
		rates.push_back((bPts[i].lat - back.lat) / length);
	}
}

int getClockWise(std::vector<GVCoord> bPts)
{
	//����������������������������ж�˳��ʱ��
	int wise = 0;
	double area = 0;
	int cpSize = bPts.size();
	area += bPts[0].lat*(bPts[1].lon - bPts[cpSize - 1].lon);
	for (int i = 1; i < cpSize; i++)
	{
		area += bPts[i].lat*(bPts[(i + 1) % cpSize].lon - bPts[i - 1].lon);
	}
	if (area > 0)
	{//˳ʱ��
		wise = 1;
	}
	else
	{
		wise = -1;
	}
	return wise;
}

// GVCoord rotate_by_angle(const GVCoord &in_coord, const GVCoord &center_coord, double angle)
// {
// 	GVCoord out_coord;
// 	out_coord.lon = (in_coord.lon - center_coord.lon) * cos(angle * MILHELPER_PI / 180.0) - (in_coord.lat - center_coord.lat) * sin(angle * MILHELPER_PI / 180.0) + center_coord.lon;
// 	out_coord.lat = (in_coord.lon - center_coord.lon) * sin(angle * MILHELPER_PI / 180.0) + (in_coord.lat - center_coord.lat) * cos(angle * MILHELPER_PI / 180.0) + center_coord.lat;
// 	out_coord.alt = 0.0;
// 	return out_coord;
// }

GVCoord Get_round(const GVCoord& temp_GV1, double r, double angle)
{
	GVCoord round;
	round.alt = temp_GV1.alt;
	round.lat = temp_GV1.lat + r*sin(MILHELPER_PI*angle / 180);
	round.lon = temp_GV1.lon + r*cos(MILHELPER_PI*angle / 180);
	return round;
}

std::vector<int> Get_trianglePointsIndex(std::vector<GVCoord> _bezierPoints, double _lengthInter)
{
	std::vector<int> _triangleIndice;
	_triangleIndice.clear();
	double lengthAll = 0;
	int i;
	for (i = 0; i < _bezierPoints.size() - 1; i++)
	{
		lengthAll += distance(_bezierPoints[i], _bezierPoints[i + 1]);
	}
	int triangleNum = lengthAll / _lengthInter;
	double length = 0;
	double tempNum = 1;
	int j;
	for (i = 0; i < _bezierPoints.size() - 1; i++)
	{
		length += distance(_bezierPoints[i], _bezierPoints[i + 1]);
		if (length >= _lengthInter * tempNum && (length - distance(_bezierPoints[i], _bezierPoints[i + 1])) < _lengthInter * tempNum)
		{
			_triangleIndice.push_back(i);
			tempNum++;
		}
	}
	return _triangleIndice;
}



//////////////////////////////////////////////////////////////////////////

GVCoord Get_sym_GV25000(GVCoord G1, GVCoord G2, GVCoord G3)
{
	GVCoord DIR;
	DIR.lon = G3.lon - G2.lon;
	DIR.lat = G3.lat - G2.lat;
	double t = sqrt(DIR.lon*DIR.lon + DIR.lat*DIR.lat);
	DIR.lon /= t;
	DIR.lat /= t;
	GVCoord GV;
	double A, B, C, D;
	//AX+BY+C=0     D=(Ax+By+C)/(A^2+B^2)
	A = DIR.lat;
	if (DIR.lon == 0)
	{
		DIR.lon += 0.000001;
	}
	B = -DIR.lon;
	C = (G2.lat - DIR.lat / DIR.lon*G2.lon)*DIR.lon;
	D = (A*G1.lon + B*G1.lat + C) / sqrt(A*A + B*B);
	GV.alt = G1.alt;
	GV.lon = G1.lon - 2 * A*D;
	GV.lat = G1.lat - 2 * B*D;
	return GV;
}

//�����ͷβ�����㣬���㷵�ؼ�ͷ����������
std::vector<GVCoord> get2ArrowPoints_25203(GVCoord left, GVCoord right)
{
	GVCoord central;//����β����е�
	GVCoord topleft, topright; //�����������ͷ����
	central.alt = (left.alt + right.alt) / 2.0;
	central.lon = (left.lon + right.lon) / 2.0;
	central.lat = (left.lat + right.lat) / 2.0;

	//����ͷ������е�
	central.lon -= (right.lat - left.lat);
	central.lat += (right.lon - left.lon);

	//����ͷ����ֱ��صױ߷���ƽ��0.1����
	topleft = topright = central;
	topleft.lon += (left.lon - right.lon) / 10.0;
	topleft.lon += (left.lon - right.lon) / 10.0;
	topright.lon += (right.lon - left.lon) / 10.0;
	topright.lon += (right.lon - left.lon) / 10.0;
	std::vector<GVCoord> result;
	result.push_back(topleft);
	result.push_back(topright);
	return result;
}

//�����ͷβ�����㣬�Ҳ��ͷ���㣬���㷵�ؼ�ͷ���󶥵�
GVCoord getLeftArrowPoints_25203(GVCoord left, GVCoord right, GVCoord arrow)
{
	GVCoord top;//���ͷ����
	GVCoord bottom_central, top_central;  //�ײ������������е�
	bottom_central.alt = (left.alt + right.alt) / 2.0;
	bottom_central.lon = (left.lon + right.lon) / 2.0;
	bottom_central.lat = (left.lat + right.lat) / 2.0;

	double height;   //arrow���ײ��������ߵľ���,  2*���/�ױ߳�
	height = fabs((right.lon - left.lon)*(arrow.lat - left.lat) - (right.lat - left.lat)*(arrow.lon - left.lon))
		/ distance(left, right);
	//�ױ������㷽������,����λ����
	GVCoord direct = GVCoord(right.lon - left.lon, right.lat - left.lat, 0);
	direct.normalize();
	int side = isLeftOrRight(arrow, left, right);
	direct = direct*side;
	//����������е�
	top_central = bottom_central;
	top_central.lon -= height*direct.lat;
	top_central.lat += height*direct.lon;

	//���ͷ������arrow����top_central�Գ�
	top.alt = arrow.alt;
	top.lon = top_central.lon + (top_central.lon - arrow.lon);
	top.lat = top_central.lat + (top_central.lat - arrow.lat);

	return top;
}

//�����ͷ�ײ������������㣬����ֵ�����ظ�����
GVCoord getAuxPoint_25203(GVCoord bottom_left, GVCoord bottom_right, GVCoord top_left, GVCoord top_right, double rate)
{
	GVCoord bottom_central, top_central;
	//��ײ����������е�
	bottom_central.alt = (bottom_left.alt + bottom_right.alt) / 2.0;
	bottom_central.lon = (bottom_left.lon + bottom_right.lon) / 2.0;
	bottom_central.lat = (bottom_left.lat + bottom_right.lat) / 2.0;
	top_central.alt = (top_left.alt + top_right.alt) / 2.0;
	top_central.lon = (top_left.lon + top_right.lon) / 2.0;
	top_central.lat = (top_left.lat + top_right.lat) / 2.0;
	//���ݱ���ֵ���������
	GVCoord aux = bottom_central;
	aux.lon += rate * (top_central.lon - bottom_central.lon);
	aux.lat += rate * (top_central.lat - bottom_central.lat);
	return aux;
}

//�����ͷ�ײ������������㣬˳ʱ�����η����������һ�㣬���ͷ4�㣬�Ҽ�ͷ4�㣬�Ҽ�����һ��
std::vector<GVCoord> getDrawPoints_25203(GVCoord bottom_left, GVCoord bottom_right, GVCoord top_left, GVCoord top_right)
{
	std::vector<GVCoord> result;
	//�����ͷβ�������󡱷���ƽ�Ƶײ����ȵ�0.2���õ�һ�㣬������������ͷ���㣬0.5��Ϊ�������һ�㣬0.8��Ϊ��ͷ
	GVCoord left, right; //ƽ�Ƶõ��ĵ�
	GVCoord arrleft, arrright;  //���Ҽ�����һ��
	GVCoord neck, ear, sym_neck, sym_ear;  //�����������Լ��Գ�
	//�����ƽ�Ƶõ��ĵ�
	left = bottom_left;
	left.lon += (bottom_left.lon - bottom_right.lon)*0.20;
	left.lat += (bottom_left.lat - bottom_right.lat)*0.20;
	//��������ϵĵ�
	arrleft.alt = (left.alt + top_left.alt) / 2.0;
	arrleft.lon = (left.lon + top_left.lon) / 2.0;
	arrleft.lat = (left.lat + top_left.lat) / 2.0;
	result.push_back(arrleft);
	//�����ͷ��ߵļ���������
	neck.lon = left.lon + 0.82*(top_left.lon - left.lon) - 0.03*(top_left.lat - left.lat);
	neck.lat = left.lat + 0.82*(top_left.lat - left.lat) + 0.03*(top_left.lon - left.lon);
	neck.alt = left.alt;
	sym_neck = getSymPoint(neck, top_left, left);

	ear.lon = left.lon + 0.75*(top_left.lon - left.lon) - 0.1*(top_left.lat - left.lat);
	ear.lat = left.lat + 0.75*(top_left.lat - left.lat) + 0.1*(top_left.lon - left.lon);
	ear.alt = left.alt;
	sym_ear = getSymPoint(ear, top_left, left);
	//˳ʱ�����δ洢
	int side = isLeftOrRight(top_right, bottom_left, bottom_right);
	if (side == -1)
	{
		result.push_back(sym_neck);
		result.push_back(sym_ear);
		result.push_back(ear);
		result.push_back(neck);
	}
	else
	{
		result.push_back(neck);
		result.push_back(ear);
		result.push_back(sym_ear);
		result.push_back(sym_neck);
	}

	//ͬ�����ұߵ�
	//���ұ�ƽ�Ƶõ��ĵ�
	right = bottom_right;
	right.lon -= (bottom_left.lon - bottom_right.lon)*0.20;
	right.lat -= (bottom_left.lat - bottom_right.lat)*0.20;
	//���Ҽ����ϵĵ�
	arrright.alt = (right.alt + top_right.alt) / 2.0;
	arrright.lon = (right.lon + top_right.lon) / 2.0;
	arrright.lat = (right.lat + top_right.lat) / 2.0;

	//���Ҽ�ͷ��ߵļ���������
	neck.lon = right.lon + 0.82*(top_right.lon - right.lon) - 0.03*(top_right.lat - right.lat);
	neck.lat = right.lat + 0.82*(top_right.lat - right.lat) + 0.03*(top_right.lon - right.lon);
	neck.alt = right.alt;
	sym_neck = getSymPoint(neck, top_right, right);

	ear.lon = right.lon + 0.75*(top_right.lon - right.lon) - 0.1*(top_right.lat - right.lat);
	ear.lat = right.lat + 0.75*(top_right.lat - right.lat) + 0.1*(top_right.lon - right.lon);
	ear.alt = right.alt;
	sym_ear = getSymPoint(ear, top_right, right);
	//˳ʱ�����δ洢
	if (side == -1)
	{
		result.push_back(sym_neck);
		result.push_back(sym_ear);
		result.push_back(ear);
		result.push_back(neck);
	}
	else
	{
		result.push_back(neck);
		result.push_back(ear);
		result.push_back(sym_ear);
		result.push_back(sym_neck);
	}
	result.push_back(arrright);
	return result;
}

/*--���������� ��n,i��* Pi * (1-t)^(n-i)*t^i---*/
GVCoord Bessel_GV25203(int n, float t, std::vector<GVCoord> _controlPoints)
{
	GVCoord bessel;
	bessel.alt = 0;
	bessel.lat = 0;
	bessel.lon = 0;
	float i, j, k;
	int index;
	float temp = 1, temp_alt, temp_lat, temp_lon;
	for (i = 0; i <= n - 1; i++)
	{
		temp = 1;
		for (j = 0; j < n - i - 1; j++)
		{
			temp = temp*(1 - t);
		}
		for (k = 1; k <= i; k++)
		{
			temp = temp*t;
			temp = temp*(n - k) / k;
		}
		index = i;
		temp_alt = temp*_controlPoints[index].alt;
		temp_lat = temp*_controlPoints[index].lat;
		temp_lon = temp*_controlPoints[index].lon;
		bessel.alt = bessel.alt + temp_alt;
		bessel.lat = bessel.lat + temp_lat;
		bessel.lon = bessel.lon + temp_lon;

	}
	return bessel;
}

//����������������е㣬�Ҽ��������ͷ��λ�������Ҽ�ͷ��λ��������ͷ���߳� / ��β���߳�              
//���ؼ��ѻ����ϵĵ�
std::vector<GVCoord> getArrowNest_25203(GVCoord leftneck, GVCoord aux, GVCoord rightneck, GVCoord dir1, GVCoord dir2, double rate)
{
	double auxlr;//���Ѵ�������ƫ����/��ͷ���߳�
	if (rate < 0.4)
	{
		auxlr = 0.4;
	}
	else if (rate < 1 && rate >= 0.4)
	{
		auxlr = 0.4;
	}
	else
	{
		auxlr = 0.4 - 0.1*rate;
		if (rate > 3)
		{
			auxlr = 0.1;
		}
	}
	double ldis = distance(leftneck, aux);
	double rdis = distance(rightneck, aux);
	//�����λ�����������
	std::vector<GVCoord> result;
	GVCoord templeft, tempright; //���������߸����㣬�������ؼ�ͷ������ƽ��һ�ξ���õ�
	GVCoord auxleft, auxright;   //aux��leftneck-leftneck��������ƽ�Ƶõ�����֤���α��������Ӵ�ƽ��
	std::vector<GVCoord> controls;
	//�����߻���
	templeft = leftneck;
	templeft.lon -= 0.4 * distance(leftneck, aux) * dir1.lon;
	templeft.lat -= 0.4 * distance(leftneck, aux) * dir1.lat;
	auxleft = aux;
	auxleft.lon += auxlr * (ldis / rdis) * (leftneck.lon - rightneck.lon);
	auxleft.lat += auxlr * (ldis / rdis) * (leftneck.lat - rightneck.lat);
	controls.clear();
	controls.push_back(leftneck);
	controls.push_back(templeft);
	controls.push_back(auxleft);
	controls.push_back(aux);
	for (double t = 0; t <= 90; t++)
	{
		result.push_back(Bessel_GV25203(4, t / 90.0, controls));
	}
	//���Ұ�߻���
	tempright = rightneck;
	tempright.lon -= 0.4 * distance(rightneck, aux) * dir2.lon;
	tempright.lat -= 0.4 * distance(rightneck, aux) * dir2.lat;
	auxright = aux;
	auxright.lon -= auxlr * (rdis / ldis) * (leftneck.lon - rightneck.lon);
	auxright.lat -= auxlr * (rdis / ldis) * (leftneck.lat - rightneck.lat);
	controls.clear();
	controls.push_back(aux);
	controls.push_back(auxright);
	controls.push_back(tempright);
	controls.push_back(rightneck);
	for (double t = 0; t <= 90; t++)
	{
		result.push_back(Bessel_GV25203(4, t / 90.0, controls));
	}
	return result;
}


//�����ͷβ�����㣬���㷵�ؼ�ͷ����������
std::vector<GVCoord> get2ArrowPoints_25204(GVCoord left, GVCoord right)
{
	GVCoord central;//����β����е�
	GVCoord topleft, topright; //�����������ͷ����
	central.alt = (left.alt + right.alt) / 2.0;
	central.lon = (left.lon + right.lon) / 2.0;
	central.lat = (left.lat + right.lat) / 2.0;

	//����ͷ������е�
	central.lon -= (right.lat - left.lat);
	central.lat += (right.lon - left.lon);

	//����ͷ����ֱ��صױ߷���ƽ��0.1����
	topleft = topright = central;
	topleft.lon += (left.lon - right.lon) / 10.0;
	topleft.lon += (left.lon - right.lon) / 10.0;
	topright.lon += (right.lon - left.lon) / 10.0;
	topright.lon += (right.lon - left.lon) / 10.0;
	std::vector<GVCoord> result;
	result.push_back(topleft);
	result.push_back(topright);
	return result;
}

//�����ͷβ�����㣬�Ҳ��ͷ���㣬���㷵�ؼ�ͷ���󶥵�
GVCoord getLeftArrowPoints_25204(GVCoord left, GVCoord right, GVCoord arrow)
{
	GVCoord top;//���ͷ����
	GVCoord bottom_central, top_central;  //�ײ������������е�
	bottom_central.alt = (left.alt + right.alt) / 2.0;
	bottom_central.lon = (left.lon + right.lon) / 2.0;
	bottom_central.lat = (left.lat + right.lat) / 2.0;

	double height;   //arrow���ײ��������ߵľ���,  2*���/�ױ߳�
	height = fabs((right.lon - left.lon)*(arrow.lat - left.lat) - (right.lat - left.lat)*(arrow.lon - left.lon))
		/ distance(left, right);
	//�ױ������㷽������,����λ����
	GVCoord direct = GVCoord(right.lon - left.lon, right.lat - left.lat, 0);
	direct.normalize();
	int side = isLeftOrRight(arrow, left, right);
	direct = direct*side;
	//����������е�
	top_central = bottom_central;
	top_central.lon -= height*direct.lat;
	top_central.lat += height*direct.lon;

	//���ͷ������arrow����top_central�Գ�
	top.alt = arrow.alt;
	top.lon = top_central.lon + (top_central.lon - arrow.lon);
	top.lat = top_central.lat + (top_central.lat - arrow.lat);

	return top;
}

//�����ͷ�ײ������������㣬����ֵ�����ظ�����
GVCoord getAuxPoint_25204(GVCoord bottom_left, GVCoord bottom_right, GVCoord top_left, GVCoord top_right, double rate)
{
	GVCoord bottom_central, top_central;
	//��ײ����������е�
	bottom_central.alt = (bottom_left.alt + bottom_right.alt) / 2.0;
	bottom_central.lon = (bottom_left.lon + bottom_right.lon) / 2.0;
	bottom_central.lat = (bottom_left.lat + bottom_right.lat) / 2.0;
	top_central.alt = (top_left.alt + top_right.alt) / 2.0;
	top_central.lon = (top_left.lon + top_right.lon) / 2.0;
	top_central.lat = (top_left.lat + top_right.lat) / 2.0;
	//���ݱ���ֵ���������
	GVCoord aux = bottom_central;
	aux.lon += rate * (top_central.lon - bottom_central.lon);
	aux.lat += rate * (top_central.lat - bottom_central.lat);
	return aux;
}

//�����ͷ�ײ������������㣬˳ʱ�����η����������һ�㣬���ͷ4�㣬�Ҽ�ͷ4�㣬�Ҽ�����һ��
std::vector<GVCoord> getDrawPoints_25204(GVCoord bottom_left, GVCoord bottom_right, GVCoord top_left, GVCoord top_right)
{
	std::vector<GVCoord> result;
	//�����ͷβ�������ҡ�����ƽ�Ƶײ����ȵ�0.2���õ�һ�㣬������������ͷ���㣬0.5��Ϊ�������һ�㣬0.8��Ϊ��ͷ
	GVCoord left, right; //ƽ�Ƶõ��ĵ�
	GVCoord arrleft, arrright;  //���Ҽ�����һ��
	GVCoord neck, ear, sym_neck, sym_ear;  //�����������Լ��Գ�
	//�����ƽ�Ƶõ��ĵ�
	left = bottom_left;
	left.lon -= (bottom_left.lon - bottom_right.lon)*0.20;
	left.lat -= (bottom_left.lat - bottom_right.lat)*0.20;
	//��������ϵĵ�
	arrleft.alt = (left.alt + top_left.alt) / 2.0;
	arrleft.lon = (left.lon + top_left.lon) / 2.0;
	arrleft.lat = (left.lat + top_left.lat) / 2.0;
	//ˮƽ����Ӹ�ƫ����������������ֻ�Ƚ�ϸ��������Э��
	arrleft.lon += 0.08 * (bottom_left.lon - bottom_right.lon);
	arrleft.lat += 0.08 * (bottom_left.lat - bottom_right.lat);
	result.push_back(arrleft);
	//�����ͷ��ߵļ�����������
	neck.lon = left.lon + 0.82*(top_left.lon - left.lon) - 0.03*(top_left.lat - left.lat);
	neck.lat = left.lat + 0.82*(top_left.lat - left.lat) + 0.03*(top_left.lon - left.lon);
	neck.alt = left.alt;
	sym_neck = getSymPoint(neck, top_left, left);

	ear.lon = left.lon + 0.75*(top_left.lon - left.lon) - 0.1*(top_left.lat - left.lat);
	ear.lat = left.lat + 0.75*(top_left.lat - left.lat) + 0.1*(top_left.lon - left.lon);
	ear.alt = left.alt;
	sym_ear = getSymPoint(ear, top_left, left);
	//˳ʱ�����δ洢
	int side = isLeftOrRight(top_right, bottom_left, bottom_right);
	if (side == -1)
	{
		result.push_back(sym_neck);
		result.push_back(sym_ear);
		result.push_back(ear);
		result.push_back(neck);
	}
	else
	{
		result.push_back(neck);
		result.push_back(ear);
		result.push_back(sym_ear);
		result.push_back(sym_neck);
	}

	//ͬ�����ұߵ�
	//���ұ�ƽ�Ƶõ��ĵ�
	right = bottom_right;
	right.lon += (bottom_left.lon - bottom_right.lon)*0.20;
	right.lat += (bottom_left.lat - bottom_right.lat)*0.20;
	//���Ҽ����ϵĵ�
	arrright.alt = (right.alt + top_right.alt) / 2.0;
	arrright.lon = (right.lon + top_right.lon) / 2.0;
	arrright.lat = (right.lat + top_right.lat) / 2.0;
	//ˮƽ����Ӹ�ƫ����������������ֻ�Ƚ�ϸ��������Э��
	arrright.lon -= 0.08 * (bottom_left.lon - bottom_right.lon);
	arrright.lat -= 0.08 * (bottom_left.lat - bottom_right.lat);
	//���Ҽ�ͷ��ߵļ���������
	neck.lon = right.lon + 0.82*(top_right.lon - right.lon) - 0.03*(top_right.lat - right.lat);
	neck.lat = right.lat + 0.82*(top_right.lat - right.lat) + 0.03*(top_right.lon - right.lon);
	neck.alt = right.alt;
	sym_neck = getSymPoint(neck, top_right, right);

	ear.lon = right.lon + 0.75*(top_right.lon - right.lon) - 0.1*(top_right.lat - right.lat);
	ear.lat = right.lat + 0.75*(top_right.lat - right.lat) + 0.1*(top_right.lon - right.lon);
	ear.alt = right.alt;
	sym_ear = getSymPoint(ear, top_right, right);
	//˳ʱ�����δ洢
	if (side == -1)
	{
		result.push_back(sym_neck);
		result.push_back(sym_ear);
		result.push_back(ear);
		result.push_back(neck);
	}
	else
	{
		result.push_back(neck);
		result.push_back(ear);
		result.push_back(sym_ear);
		result.push_back(sym_neck);
	}
	result.push_back(arrright);
	return result;
}

//����������������е㣬�Ҽ��������ͷ��λ�������Ҽ�ͷ��λ��������ͷ���߳� / ��β���߳�               ���ؼ��ѻ����ϵĵ�
std::vector<GVCoord> getArrowNest_25204(GVCoord leftneck, GVCoord aux, GVCoord rightneck, GVCoord dir1, GVCoord dir2, double rate)
{
	double auxlr;//���Ѵ�������ƫ����/��ͷ���߳�
	if (rate < 0.4)
	{
		auxlr = 0.4;
	}
	else if (rate < 1 && rate >= 0.4)
	{
		auxlr = 0.4;
	}
	else
	{
		auxlr = 0.4 - 0.1*rate;
		if (rate > 3)
		{
			auxlr = 0.1;
		}
	}
	double ldis = distance(leftneck, aux);
	double rdis = distance(rightneck, aux);
	//�����λ�����������
	std::vector<GVCoord> result;
	GVCoord templeft, tempright; //���������߸����㣬�������ؼ�ͷ������ƽ��һ�ξ���õ�
	GVCoord auxleft, auxright;   //aux��leftneck-leftneck��������ƽ�Ƶõ�����֤���α��������Ӵ�ƽ��
	std::vector<GVCoord> controls;
	//�����߻���
	templeft = leftneck;
	templeft.lon -= 0.4 * distance(leftneck, aux) * dir1.lon;
	templeft.lat -= 0.4 * distance(leftneck, aux) * dir1.lat;
	auxleft = aux;
	auxleft.lon += auxlr * (ldis / rdis) * (leftneck.lon - rightneck.lon);
	auxleft.lat += auxlr * (ldis / rdis) * (leftneck.lat - rightneck.lat);
	controls.clear();
	controls.push_back(leftneck);
	controls.push_back(templeft);
	controls.push_back(auxleft);
	controls.push_back(aux);
	for (double t = 0; t <= 90; t++)
	{
		result.push_back(Bessel_GV25204(4, t / 90.0, controls));
	}
	//���Ұ�߻���
	tempright = rightneck;
	tempright.lon -= 0.4 * distance(rightneck, aux) * dir2.lon;
	tempright.lat -= 0.4 * distance(rightneck, aux) * dir2.lat;
	auxright = aux;
	auxright.lon -= auxlr * (rdis / ldis) * (leftneck.lon - rightneck.lon);
	auxright.lat -= auxlr * (rdis / ldis) * (leftneck.lat - rightneck.lat);
	controls.clear();
	controls.push_back(aux);
	controls.push_back(auxright);
	controls.push_back(tempright);
	controls.push_back(rightneck);
	for (double t = 0; t <= 90; t++)
	{
		result.push_back(Bessel_GV25204(4, t / 90.0, controls));
	}
	return result;
}


/*--���������� ��n,i��* Pi * (1-t)^(n-i)*t^i---*/
GVCoord Bessel_GV25204(int n, float t, std::vector<GVCoord> Points)
{
	GVCoord bessel;
	bessel.alt = 0;
	bessel.lat = 0;
	bessel.lon = 0;
	int i, j, k;
	int index;
	float temp = 1, temp_alt, temp_lat, temp_lon;
	for (i = 0; i <= n - 1; i++)
	{
		temp = 1;
		for (j = 0; j < n - i - 1; j++)
		{
			temp = temp*(1 - t);
		}
		for (k = 1; k <= i; k++)
		{
			temp = temp*t;
			temp = temp*(n - k) / k;
		}
		index = i;
		temp_alt = temp*Points[index].alt;
		temp_lat = temp*Points[index].lat;
		temp_lon = temp*Points[index].lon;
		bessel.alt = bessel.alt + temp_alt;
		bessel.lat = bessel.lat + temp_lat;
		bessel.lon = bessel.lon + temp_lon;

	}
	return bessel;
}

//////////////////////25205/////////////////////////
//���빹��������ͷ�ļ�β����������ͷ���㣬����������ͷ����ľ��룬���ؼ�����
GVCoord getNeckPoint_25205(GVCoord tail, GVCoord body, GVCoord head, double dis)
{
	double len = distance(tail, body) + distance(body, head);
	//��dis��Χ������
	if (dis < 0.05*len)
	{
		dis = 0.05*len;
	}
	else if (dis > 0.5*len)
	{
		dis = 0.5*len;
	}
	Bezier bezier;
	std::vector<GVCoord> points;
	std::vector<GVCoord> bezierPoints;
	points.push_back(head);
	points.push_back(body);
	points.push_back(tail);
	bezier.getBezier(points, NULL, NULL, &bezierPoints);
	len = 0;
	int i;
	for (i = 1; i < bezierPoints.size(); i++)
	{
		len += distance(bezierPoints[i - 1], bezierPoints[i]);
		if (len >= dis)
		{
			break;
		}
	}
	return bezierPoints[i];
}

//�������������ͷ�ļ�β����������ͷ������ֵ ��������ͷ��ļ��Ѹ�����
GVCoord getNestPoint_25205(GVCoord lefttail, GVCoord leftbody, GVCoord lefthead, GVCoord rightail, GVCoord rightbody, GVCoord righthead, double scale)
{
	//�����е�
	GVCoord tail, body, head;
	GVCoord nest;
	tail.alt = (lefttail.alt + rightail.alt) / 2.0;
	tail.lon = (lefttail.lon + rightail.lon) / 2.0;
	tail.lat = (lefttail.lat + rightail.lat) / 2.0;
	body.alt = (leftbody.alt + rightbody.alt) / 2.0;
	body.lon = (leftbody.lon + rightbody.lon) / 2.0;
	body.lat = (leftbody.lat + rightbody.lat) / 2.0;
	head.alt = (lefthead.alt + righthead.alt) / 2.0;
	head.lon = (lefthead.lon + righthead.lon) / 2.0;
	head.lat = (lefthead.lat + righthead.lat) / 2.0;
	double len1 = distance(head, body); //�ϰ�����
	double len2 = distance(tail, body); //�°�����
	GVCoord dir = GVCoord(body.lon - head.lon, body.lat - head.lat, 0.0);  //��ͷָ������ķ�������
	dir.normalize();
	//���Ѹ������ڼ�ͷ֮��
	if (scale < 0)
	{
		nest = head;
		nest.lon += scale * dir.lon * (len1 + len2);
		nest.lat += scale * dir.lat * (len1 + len2);
	}
	else
	{
		//��1���� <= �ϰ�����   ��1���� / (�ϰ�����+�°�����)
		if (scale <= len1 / (len1 + len2))
		{
			nest = head;
			nest.lon += scale * dir.lon * (len1 + len2);
			nest.lat += scale * dir.lat * (len1 + len2);
		}
		else   //��1���� > �ϰ�����    (��2����+�ϰ�����) / (�ϰ�����+�°�����)
		{
			nest = body;
			nest.lon += (scale - len1 / (len1 + len2)) * dir.lon * (len1 + len2);
			nest.lat += (scale - len1 / (len1 + len2)) * dir.lat * (len1 + len2);
		}
	}
	return nest;
}

//���빹�ɼ�ͷ�����㣬tag=1���������ߣ�tag = -1�������һ���
std::vector<GVCoord> getArcPoints_25205(GVCoord tail, GVCoord body, GVCoord head, GVCoord neck, int tag)
{
	GVCoord dir1 = GVCoord(body.lon - tail.lon, body.lat - tail.lat, 0.0);
	dir1.normalize();
	GVCoord dir2 = GVCoord(head.lon - neck.lon, head.lat - neck.lat, 0.0);
	dir2.normalize();
	double len1 = distance(tail, body) + distance(body, head);
	double len2 = distance(head, neck);
	double tailscale = 0.2;  //��βƫ����
	double bodyscale = 0.1;  //����ƫ����
	double neckscale = 0.25; //����ƫ����
	tail.lon -= tag * dir1.lat * tailscale * len1;
	tail.lat += tag * dir1.lon * tailscale * len1;

	body.lon -= tag * dir1.lat * bodyscale * len1;
	body.lat += tag * dir1.lon * bodyscale * len1;

	neck.lon -= tag * dir2.lat * neckscale * len2;
	neck.lat += tag * dir2.lon * neckscale * len2;

	std::vector<GVCoord> controls;
	std::vector<GVCoord> bezierPoints;
	controls.push_back(tail);
	controls.push_back(body);
	controls.push_back(neck);
	Bezier bezier;
	bezier.getBezier(controls, NULL, NULL, &bezierPoints);

	return bezierPoints;
}

//�����ͷ���㣬������˳ʱ�뷵�ؼ�ͷ��5��
std::vector<GVCoord> getArrowPoints_25205(GVCoord head, GVCoord neck)
{
	//���Ҽ���������
	GVCoord leftneck, rightneck, leftear, rightear;
	GVCoord dir = GVCoord(head.lon - neck.lon, head.lat - neck.lat, 0.0);   //��ͷ��������
	leftneck = rightneck = neck;
	/************************************************************************/
	/*�пӣ�����ı� neckscale��ֵ��getArcPoints_25205��� neckscaleҲҪ��  */
	/************************************************************************/
	double neckscale = 0.25; //���Ҽ������ڼ����������ƫ�Ʊ���
	double earscale = 0.4;   //���Ҽ�������ڼ�����ı��˱���
	leftneck.lon -= neckscale*dir.lat;
	leftneck.lat += neckscale*dir.lon;
	rightneck.lon += neckscale*dir.lat;
	rightneck.lat -= neckscale*dir.lon;

	leftear.alt = leftneck.alt;
	leftear.lon = leftneck.lon - earscale*dir.lat - earscale*dir.lon;
	leftear.lat = leftneck.lat + earscale*dir.lon - earscale*dir.lat;
	rightear = rightneck;
	rightear.lon = rightneck.lon + earscale*dir.lat - earscale*dir.lon;
	rightear.lat = rightneck.lat - earscale*dir.lon - earscale*dir.lat;

	std::vector<GVCoord> result;
	result.push_back(leftneck);
	result.push_back(leftear);
	result.push_back(head);
	result.push_back(rightear);
	result.push_back(rightneck);

	return result;
}

//����������������е㣬�Ҽ��������ͷ��λ�������Ҽ�ͷ��λ���������ؼ��ѻ����ϵĵ�
std::vector<GVCoord> getArrowNest_25205(GVCoord leftneck, GVCoord aux, GVCoord rightneck, GVCoord dir1, GVCoord dir2)
{
	//�����λ�����������
	std::vector<GVCoord> result;
	GVCoord templeft, tempright; //���������߸����㣬�������ؼ�ͷ������ƽ��һ�ξ���õ�
	GVCoord auxleft, auxright;   //aux��leftneck-leftneck��������ƽ�Ƶõ�����֤���α��������Ӵ�ƽ��
	std::vector<GVCoord> controls;
	double ldis = distance(leftneck, aux);
	double rdis = distance(rightneck, aux);
	//�����߻���
	templeft = leftneck;
	templeft.lon -= 0.3 * distance(leftneck, aux) * dir1.lon;
	templeft.lat -= 0.3 * distance(leftneck, aux) * dir1.lat;
	auxleft = aux;
	//����aux�����Ҽ����ľ���ȷ��aux�������������ƫ�Ʊ���
	auxleft.lon += 0.6 * (ldis / (ldis + rdis)) * (leftneck.lon - rightneck.lon);
	auxleft.lat += 0.6 * (ldis / (ldis + rdis)) * (leftneck.lat - rightneck.lat);
	controls.clear();
	controls.push_back(leftneck);
	controls.push_back(templeft);
	controls.push_back(auxleft);
	controls.push_back(aux);
	for (double t = 0; t <= 100; t++)
	{
		result.push_back(Bessel_GV25205(4, t / 100.0, controls));
	}
	//���Ұ�߻���
	tempright = rightneck;
	tempright.lon -= 0.3 * distance(rightneck, aux) * dir2.lon;
	tempright.lat -= 0.3 * distance(rightneck, aux) * dir2.lat;
	auxright = aux;
	auxright.lon -= 0.6 * (rdis / (ldis + rdis)) * (leftneck.lon - rightneck.lon);
	auxright.lat -= 0.6 * (rdis / (ldis + rdis)) * (leftneck.lat - rightneck.lat);
	controls.clear();
	controls.push_back(aux);
	controls.push_back(auxright);
	controls.push_back(tempright);
	controls.push_back(rightneck);
	for (double t = 0; t <= 100; t++)
	{
		result.push_back(Bessel_GV25205(4, t / 100.0, controls));
	}
	return result;
}

//--���������� ��n,i��* Pi * (1-t)^(n-i)*t^i---//�������ר��
GVCoord Bessel_GV25205(int n, float t, std::vector<GVCoord> _controlPoints)
{
	GVCoord bessel;
	bessel.alt = 0;
	bessel.lat = 0;
	bessel.lon = 0;
	float i, j, k;
	int index;
	float temp = 1, temp_alt, temp_lat, temp_lon;
	for (i = 0; i <= n - 1; i++)
	{
		temp = 1;
		for (j = 0; j < n - i - 1; j++)
		{
			temp = temp*(1 - t);
		}
		for (k = 1; k <= i; k++)
		{
			temp = temp*t;
			temp = temp*(n - k) / k;
		}
		index = i;
		temp_alt = temp*_controlPoints[index].alt;
		temp_lat = temp*_controlPoints[index].lat;
		temp_lon = temp*_controlPoints[index].lon;
		bessel.alt = bessel.alt + temp_alt;
		bessel.lat = bessel.lat + temp_lat;
		bessel.lon = bessel.lon + temp_lon;

	}
	return bessel;
}

//��ȡ��ͷ������˳��
std::vector<int> GetOrder_GV25205(std::vector<GVCoord> bzPoints)
{
	std::vector<GVCoord> basicPoints = bzPoints;
	std::vector<int> order;
	order.clear();
	int size = basicPoints.size();
	int arrowCount = (size + 1) / 3;

	if (arrowCount * 3 - 1 >= size)
	{
		GVCoord gtemp;
		gtemp.alt = (basicPoints[arrowCount * 3 - 3].alt + basicPoints[arrowCount * 3 - 2].alt) / 2.0;
		gtemp.lon = (basicPoints[arrowCount * 3 - 3].lon + basicPoints[arrowCount * 3 - 2].lon) / 2.0;
		gtemp.lat = (basicPoints[arrowCount * 3 - 3].lat + basicPoints[arrowCount * 3 - 2].lat) / 2.0;
		basicPoints.insert(basicPoints.begin() + 3 * (arrowCount - 1) + 1, gtemp);
	}

	order.push_back(0);
	for (int i = 1; i < arrowCount; i++)
	{
		int orderSize = order.size();
		for (int j = 0; j < orderSize; j++)
		{
			int k = order[j];
			double axis_x = basicPoints[3 * k + 1].lon - basicPoints[3 * k].lon;
			double axis_y = basicPoints[3 * k + 1].lat - basicPoints[3 * k].lat;
			double temp_x = basicPoints[3 * i + 1].lon - basicPoints[3 * k].lon;
			double temp_y = basicPoints[3 * i + 1].lat - basicPoints[3 * k].lat;
			if ((temp_x*axis_y - temp_y*axis_x) < 0)
			{
				order.insert(order.begin() + j, i);
				break;
			}
			else if (j == orderSize - 1)
			{
				order.insert(order.end(), i);
			}

		}
	}
	return order;
}


