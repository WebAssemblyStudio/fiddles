#include <GVMilUtil/MilHelper.h>
#include <GVMilUtil/ConfigControlPoints.h>
#include <GVMilUtil/Bezier.h>
#include <GVMilUtil/MilHelper.h>
#include <GVMilMath/GM29800.h>

#include <math.h>
#include <stdlib.h>

//GM29800--------------------
bool GM29800::toVertice(std::vector<GVCoord>& vtxBuffer,
				        std::vector<int>* vtxBuffer2 /*= NULL*/,
				        std::vector<float>* alphaBuffer /*= NULL*/,
				        std::vector<int>* typeBuffer /*= NULL*/)
{
	float maxPointZ = 0.0f;
	_controlPoints = vtxBuffer;
	vtxBuffer.clear();
	std::vector<GVCoord> controlPoints;
	for (int i = 0; i < _controlPoints.size(); i++)
	{
		GVCoord pt = _controlPoints.at(i);
		maxPointZ = maxPointZ > pt.alt ? maxPointZ : pt.alt;
		controlPoints.push_back(GVCoord(pt.lon, pt.lat, pt.alt));
	}
	setControlPoints(controlPoints);
	int cpSize = controlPoints.size();
	if (cpSize < 2)
	{
		return false;
	}
	else if (cpSize == 2)
	{
		vtxBuffer.push_back(controlPoints[0]);
		vtxBuffer.push_back(controlPoints[1]);
		vtxBuffer2->push_back(2);
		typeBuffer->push_back(0);
		return true;
	}
	else
	{
		int first, second;

		Bezier bezier;
		std::vector<GVCoord> bPts;  
		std::vector<GVCoord> bezierPoints;  
		bPts.clear();
		bPts.push_back(_auxPoints[3]);
		bPts.push_back(controlPoints[0]);
		bPts.push_back(controlPoints[1]);
		bPts.push_back(_auxPoints[4]);
		bezier.getBezier(bPts, NULL, NULL, &bezierPoints);
		for (int i = 0; i < bezierPoints.size(); i++)
		{
			vtxBuffer.push_back(bezierPoints[i]);

			if (bezierPoints[i].lon == controlPoints[0].lon && bezierPoints[i].lat == controlPoints[0].lat)
			{
				first = i;
			}

			if (bezierPoints[i].lon == controlPoints[1].lon && bezierPoints[i].lat == controlPoints[1].lat)
			{
				second = i;
			}
		}
		vtxBuffer2->push_back(bezierPoints.size());
		typeBuffer->push_back(0);

		GVCoord neck_l, neck_r;
		GVCoord ear_l, ear_r;
		GVCoord center, head; 
		center = _auxPoints[2];
		head = controlPoints[_normalPointCount - 1];

		neck_r = _auxPoints[0];
		neck_l = getSymPoint(neck_r, center, head);
		ear_l = _auxPoints[1];
		ear_r = getSymPoint(ear_l, center, head);

		double max_len = distance(controlPoints[0], controlPoints[1]) / 2.0;
		double min_len = distance(neck_l, neck_r) / 2.0;
		double delta = max_len - min_len;
		GVCoord mid_tail;
		GVCoord mid_neck;

		double cdelta = (distance(ear_l, ear_r) / 2.0 - min_len)*0.3 + min_len;  //当输入点为3时,center的偏移量
		mid_tail.lon = (controlPoints[0].lon + controlPoints[1].lon) / 2.0;
		mid_tail.lat = (controlPoints[0].lat + controlPoints[1].lat) / 2.0;
		mid_neck.lon = (neck_l.lon + neck_r.lon) / 2.0;
		mid_neck.lat = (neck_l.lat + neck_r.lat) / 2.0;
		double mid_len = distance(mid_tail, controlPoints[2]);

		for (int i = 2; i < _normalPointCount - 2; i++)
		{
			mid_len += distance(controlPoints[i], controlPoints[i + 1]);
		}
		mid_len += distance(controlPoints[_normalPointCount - 2], center);
		mid_len += distance(mid_neck, center);
		if (_normalPointCount == 3)
		{
			mid_len = distance(mid_tail, center) + distance(mid_neck, center);
		}

		std::vector<GVCoord> lbPts, rbPts;                    
		std::vector<GVCoord> lbezierPoints, rbezierPoints;   

		if (_normalPointCount == 3)
		{
			lbPts.push_back(controlPoints[0]);
			rbPts.push_back(controlPoints[1]);
			GVCoord dir = GVCoord(center.lon - mid_tail.lon, center.lat - mid_tail.lat, 0.0);
			dir.normalize();
			//添加两个控制点(实际不存在,为保持平滑添加的)
			//其实就是差值,插入两个控制点
			GVCoord temp, ltemp, rtemp;
			temp.lon = mid_tail.lon + (center.lon - mid_tail.lon)*(1.0 / 3.0);
			temp.lat = mid_tail.lat + (center.lat - mid_tail.lat)*(1.0 / 3.0);
			ltemp = rtemp = temp;
			ltemp.lon -= dir.lat*(max_len - sqrt(1.0 / 2.0)*delta);// 1.0/2.0是大致量的比例,慎动
			ltemp.lat += dir.lon*(max_len - sqrt(1.0 / 2.0)*delta);
			rtemp.lon += dir.lat*(max_len - sqrt(1.0 / 2.0)*delta);
			rtemp.lat -= dir.lon*(max_len - sqrt(1.0 / 2.0)*delta);

			GVCoord dtail = GVCoord(controlPoints[1].lon - controlPoints[0].lon, controlPoints[1].lat - controlPoints[0].lat, 0.0);
			GVCoord darr = GVCoord(controlPoints[2].lon - mid_tail.lon, controlPoints[2].lat - mid_tail.lat, 0.0);
			double t = (0 - darr.lon)*(dtail.lat - darr.lat) - (dtail.lon - darr.lon)*(0 - darr.lat);
			if (Judgeleft_right(ltemp, controlPoints[0], controlPoints[1]) == 1 && t > 0 && _tailAuxSide)
			{
				ltemp = controlPoints[0];
			}
			else if (Judgeleft_right(ltemp, controlPoints[0], controlPoints[1]) == 0 && t < 0 && _tailAuxSide)
			{
				ltemp = controlPoints[1];
			}
			if (Judgeleft_right(rtemp, controlPoints[0], controlPoints[1]) == 1 && t > 0 && _tailAuxSide)
			{
				rtemp = controlPoints[1];
			}
			else if (Judgeleft_right(rtemp, controlPoints[0], controlPoints[1]) == 0 && t < 0 && _tailAuxSide)
			{
				rtemp = controlPoints[0];
			}
			lbPts.push_back(ltemp);
			rbPts.push_back(rtemp);

			temp.lon = mid_tail.lon + (center.lon - mid_tail.lon)*(2.0 / 3.0);
			temp.lat = mid_tail.lat + (center.lat - mid_tail.lat)*(2.0 / 3.0);
			ltemp = rtemp = temp;
			ltemp.lon -= dir.lat*(max_len - sqrt(2.5 / 3.0)*delta);//2.5/3.0是大致量出来的
			ltemp.lat += dir.lon*(max_len - sqrt(2.5 / 3.0)*delta);
			rtemp.lon += dir.lat*(max_len - sqrt(2.5 / 3.0)*delta);
			rtemp.lat -= dir.lon*(max_len - sqrt(2.5 / 3.0)*delta);

			lbPts.push_back(ltemp);
			rbPts.push_back(rtemp);

			lbPts.push_back(neck_l);
			rbPts.push_back(neck_r);
		}
		else
		{
			std::vector<GVCoord> midPoints;//中轴线上的点集合
			midPoints.push_back(mid_tail);
			for (int i = 2; i < _normalPointCount - 1; i++)
			{
				midPoints.push_back(controlPoints[i]);
			}
			midPoints.push_back(center);
			midPoints.push_back(mid_neck);

			lbPts.push_back(controlPoints[0]);
			rbPts.push_back(controlPoints[1]);
			GVCoord dir;
			GVCoord ltemp, rtemp;
			double temp_len = 0;  //记录当前折线长
			for (int i = 1; i < midPoints.size() - 2; i++)
			{
				temp_len += distance(midPoints[i - 1], midPoints[i]);

				////求角平分线方向
				//dir = getDiagonal_29800(midPoints[i-1], midPoints[i], midPoints[i+1], 1);
				ltemp = rtemp = midPoints[i];
				//根据当前中轴线长度与中轴线总长度的比值做偏移
				//double move = max_len - temp_len/mid_len*delta*1.1;  //偏移量
				double move = max_len - sqrt(temp_len / mid_len)*delta;//抽象为 y=x^2
				if (move < min_len)//当小于最小宽度,修正
				{
					move = min_len;
				}
				ltemp = Get_outpoint(midPoints[i - 1], midPoints[i], midPoints[i], midPoints[i + 1], move);
				rtemp = Get_outpoint(midPoints[i + 1], midPoints[i], midPoints[i], midPoints[i - 1], move);
				lbPts.push_back(ltemp);
				rbPts.push_back(rtemp);
			}
			lbPts.push_back(neck_l);
			rbPts.push_back(neck_r);
		}
		GVCoord dtail = GVCoord(controlPoints[1].lon - controlPoints[0].lon, controlPoints[1].lat - controlPoints[0].lat, 0.0);
		GVCoord darr = GVCoord(controlPoints[2].lon - mid_tail.lon, controlPoints[2].lat - mid_tail.lat, 0.0);
		double t = (0 - darr.lon)*(dtail.lat - darr.lat) - (dtail.lon - darr.lon)*(0 - darr.lat);
		if (t < 0)// && _tailAuxSide)
		{

			{
				lbPts[0] = controlPoints[1];
				rbPts[0] = controlPoints[0];
			}
		}

		lbezierPoints = getArrowbody_29800(lbPts);
		for (int i = 0; i < lbezierPoints.size(); i++)
		{
			vtxBuffer.push_back(lbezierPoints[i]);
		}

		//画箭头
		vtxBuffer.push_back(neck_l);
		vtxBuffer.push_back(ear_l);
		vtxBuffer.push_back(head);
		vtxBuffer.push_back(ear_r);
		vtxBuffer.push_back(neck_r);

		//画右曲线
		rbezierPoints = getArrowbody_29800(rbPts);
		for (int i = rbezierPoints.size() - 1; i >= 0; i--)
		{
			vtxBuffer.push_back(rbezierPoints[i]);
		}


		if (t < 0)
		{
			for (int i = first; i <= second; i++)
			{
				vtxBuffer.push_back(bezierPoints[i]);
			}

		}
		else
		{
			for (int i = second; i >= first; i--)
			{
				vtxBuffer.push_back(bezierPoints[i]);
			}
		}


		vtxBuffer2->push_back(lbezierPoints.size() + 5 + rbezierPoints.size() + second - first + 1);
		typeBuffer->push_back(1);

		return true;
	}
}

//画箭身专用贝赛尔,输入控制点集合,返回贝塞尔曲线上的点
std::vector<GVCoord> GM29800::getArrowbody_29800(std::vector<GVCoord> bPts)
{
	int cpSize = bPts.size();
	std::vector<GVCoord> bezier;
	std::vector<GVCoord> bezierPoints;
	if (cpSize < 2)
	{
		return bezierPoints;
	}
	double rate = 0.15; //偏移比例
	GVCoord front, next;
	GVCoord dir;
	dir = GVCoord(bPts[1].lon - bPts[0].lon, bPts[1].lat - bPts[0].lat, 0.0);
	next = bPts[0];
	next.lon += rate*dir.lon;
	next.lat += rate*dir.lat;
	bezier.push_back(bPts[0]);
	bezier.push_back(next);

	for (int i = 1; i < cpSize - 1; i++)
	{
		dir = GVCoord(bPts[i + 1].lon - bPts[i - 1].lon, bPts[i + 1].lat - bPts[i - 1].lat, 0.0);
		next = front = bPts[i];
		front.lon -= rate*dir.lon;
		front.lat -= rate*dir.lat;
		next.lon += rate*dir.lon;
		next.lat += rate*dir.lat;
		bezier.push_back(front);
		bezier.push_back(bPts[i]);
		bezier.push_back(next);
	}

	dir = GVCoord(bPts[cpSize - 1].lon - bPts[cpSize - 2].lon, bPts[cpSize - 1].lat - bPts[cpSize - 2].lat, 0.0);
	front = bPts[cpSize - 1];
	front.lon -= rate*dir.lon;
	front.lat -= rate*dir.lat;
	bezier.push_back(front);
	bezier.push_back(bPts[cpSize - 1]);
	std::vector<GVCoord> temp;
	for (int i = 0; i < bPts.size() - 1; i++)
	{
		temp.clear();
		temp.push_back(bezier[3 * i]);
		temp.push_back(bezier[3 * i + 1]);
		temp.push_back(bezier[3 * i + 2]);
		temp.push_back(bezier[3 * i + 3]);
		for (double t = 0; t <= 1; t += 0.01)
		{
			bezierPoints.push_back(Bessel_GV29800(4, t, temp));
		}
	}

	return bezierPoints;
}

/*--贝塞尔曲线 （n,i）* Pi * (1-t)^(n-i)*t^i---*/
GVCoord GM29800::Bessel_GV29800(const int& n,const float& t,const std::vector<GVCoord>& controlPoints)
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
		temp_alt = temp*controlPoints[index].alt;
		temp_lat = temp*controlPoints[index].lat;
		temp_lon = temp*controlPoints[index].lon;
		bessel.alt = bessel.alt + temp_alt;
		bessel.lat = bessel.lat + temp_lat;
		bessel.lon = bessel.lon + temp_lon;

	}
	return bessel;
}

GM29800::GM29800()
{
	//箭尾辅助点是否随箭头方向变化
	//true 自动计算箭尾辅助点, 箭尾辅助点始终与箭身方向在箭尾连线的异侧
	//false箭尾辅助点不再跟随箭身方向的变化而变化
	_tailAuxSide = true;
	neck_rate_29800 = 0.6;
	tailAuxRate = 100;
}

GM29800::~GM29800()
{

}

void GM29800::setControlPoints(std::vector<GVCoord>& vtxBuffer)
{
	std::vector<GVCoord> controlPoints;
	std::vector<double> s;
	ConfigControlPoints::configControlPoints(vtxBuffer);
	controlPoints = vtxBuffer;
	_normalPointCount = controlPoints.size();
	_normalPoints = controlPoints;
	//两个点画直线,三个点及以上才画箭头
	if (_normalPointCount > 2)
	{
		//计算初始辅助点以及比例值
		getAuxandPoints_29800(_normalPoints, _auxPoints, _rates);
		//更新controlPoints
		for (int i = 0; i < _auxPoints.size(); i++)
		{
			controlPoints.push_back(_auxPoints[i]);
		}
	}
	vtxBuffer.clear();
	vtxBuffer = controlPoints;
	
}

//根据输入点,计算辅助点以及比例值
void GM29800::getAuxandPoints_29800(std::vector<GVCoord>& controls, std::vector<GVCoord>& aux, std::vector<double>& rates)
{
	int cpSize = controls.size();
	aux.clear();
	rates.clear();
	if (cpSize < 3)
	{
		return;
	}
	else
	{
		GVCoord mid_tail;  //箭尾中点
		GVCoord tail_l, tail_r;  //箭尾左右辅助点
		GVCoord center, neck, ear;  //箭头中间点, 箭颈, 箭耳,
		Bezier bezier;
		std::vector<GVCoord> bPts;           //箭头中轴线贝塞尔控制点
		std::vector<GVCoord> bezierPoints;   //箭头中轴线贝塞尔上的点

		//箭头各初始偏移比例    粗略估计,不太准
		//箭耳,箭颈到箭头的距离 / 贝塞尔曲线长度
		double ear_rate = 0.25;
		double neck_rate = 0.15;
		//箭颈,箭耳到箭头中轴线的距离 / 箭头部分长度
		double ear_dis = 0.5;
		double neck_dis = 0.2;

		mid_tail.lon = (controls[0].lon + controls[1].lon) / 2.0;
		mid_tail.lat = (controls[0].lat + controls[1].lat) / 2.0;
		bPts.push_back(mid_tail);
		for (int i = 2; i < cpSize; i++)
		{
			bPts.push_back(controls[i]);
		}
		bezier.getBezier(bPts, NULL, NULL, &bezierPoints);

		double length = getLengthOfAll(bezierPoints);    //贝塞尔曲线长
		//箭头大小的确定:距箭头顶点距离 = 0.1*ear_rate*贝塞尔曲线长 - ear_rate*最后两控制点长度//根据二维猜的
		center = bezierPoints[getIDbyLen(bezierPoints, length - 0.1*ear_rate*length - ear_rate*distance(controls[cpSize - 2], controls[cpSize - 1]))];
		if (controls.size() == 3)
		{
			center = bezierPoints[getIDbyLen(bezierPoints, length - ear_rate*distance(controls[cpSize - 2], controls[cpSize - 1]))];
		}
		//double arr_len = Distance_29800(center, bPts[cpSize-1]);   //箭头长度
		GVCoord dir = GVCoord(controls[cpSize - 1].lon - center.lon, controls[cpSize - 1].lat - center.lat, 0.0);//箭头指向的方向向量
		//dir.normalize();
		//初始设置箭耳与center在同一水平线
		ear = center;   //箭耳沿center向左平移
		ear.lon -= ear_dis*dir.lat;
		ear.lat += ear_dis*dir.lon;
		//箭颈是向右平移
		neck = bezierPoints[getIDbyLen(bezierPoints, length - 0.15*ear_rate*length - neck_rate*distance(controls[cpSize - 2], controls[cpSize - 1]))];
		neck.lon += neck_dis*dir.lat;
		neck.lat -= neck_dis*dir.lon;

		GVCoord vtail = GVCoord(controls[0].lat - controls[1].lat, controls[1].lon - controls[0].lon, 0.0);//垂直箭尾的方向向量
		vtail.normalize();
		GVCoord ptail = GVCoord(controls[1].lon - controls[0].lon, controls[1].lat - controls[0].lat, 0.0);//平行箭尾的方向向量
		ptail.normalize();
		//箭头指向方向在controlPoints[0]到controlPoints[1]方向的右边 需要改变方向
		GVCoord darr = GVCoord(controls[2].lon - mid_tail.lon, controls[2].lat - mid_tail.lat, 0.0);
		double t = (0 - darr.lon)*(ptail.lat - darr.lat) - (ptail.lon - darr.lon)*(0 - darr.lat);
		if (t < 0 && _tailAuxSide)
		{
			//vtail = -vtail;
			vtail.lon = 0 - vtail.lon;
			vtail.lat = 0 - vtail.lat;
			vtail.alt = 0 - vtail.alt;
			//ptail = -ptail;
		}
		double tail_len = distance(controls[0], controls[1]);
		double prate = 0.7;//箭尾辅助点相对于箭尾控制点的平行. 垂直偏移比例
		double vrate = 0.2;
		tail_l = controls[0];
		tail_l.lon += -1.0*prate*ptail.lon*tail_len - vrate*vtail.lon*tail_len;
		tail_l.lat += -1.0*prate*ptail.lat*tail_len - vrate*vtail.lat*tail_len;
		tail_r = controls[1];
		tail_r.lon += prate*ptail.lon*tail_len - vrate*vtail.lon*tail_len;
		tail_r.lat += prate*ptail.lat*tail_len - vrate*vtail.lat*tail_len;

		aux.push_back(neck);
		aux.push_back(ear);
		aux.push_back(center);
		aux.push_back(tail_l);
		aux.push_back(tail_r);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//开始计算比例值
		double temprate;//临时变量
		double linlength = getLengthOfAll(controls);  //各定位点间折线的总长（首尾不相连）
		double arr_len = distance(controls[cpSize - 1], center);  //顶端箭头的长度。

		//第一比例值：顶端箭头的长度/各定位点间折线的总长（首尾不相连）
		temprate = arr_len / linlength;
		rates.push_back(temprate);
		//第二比例值：箭颈宽的一半/顶端箭头的长度。
		temprate = getDisPtToLine(neck, controls[cpSize - 1], center) / arr_len;
		rates.push_back(temprate);
		//第三比例值：箭耳宽的一半/顶端箭头的长度
		temprate = getDisPtToLine(ear, controls[cpSize - 1], center) / arr_len;
		rates.push_back(temprate);
		//第四比例值：箭耳长/顶端箭头的长度。
		//初始设置箭耳与center在同一水平线
		temprate = 1.0 - neck_rate_29800; //Length_point_line_29800(ear, controls[cpSize-1, center]) / arr_len;
		rates.push_back(temprate);
		//第五比例值：第四修饰点到第一、第二定位点连线（延长线）的距离/各定位点间折线的总长（首尾不相连）。
		temprate = getDisPtToLine(tail_l, controls[0], controls[1]) / linlength / tailAuxRate;
		rates.push_back(temprate);
		//第六比例值：第四修饰点作垂线与第一、第二定位点连线（延长线）相交的交点和第一定位点间的距离/各定位点间折线的总长（首尾不相连）
		//根据上面的计算来
		temprate = prate*tail_len / linlength / tailAuxRate;
		rates.push_back(temprate);
		//第七比例值：第五修饰点到第一、第二定位点连线（延长线）的距离/各定位点间折线的总长（首尾不相连）
		temprate = getDisPtToLine(tail_r, controls[0], controls[1]) / linlength / tailAuxRate;
		rates.push_back(temprate);
		//第八比例值：第五修饰点作垂线与第一、第二定位点连线（延长线）相交的交点和第二定位点间的距离/各定位点间折线的总长（首尾不相连）
		temprate = prate*tail_len / linlength / tailAuxRate;
		rates.push_back(temprate);
		//第九比例值：第四修饰点在第一、第二定位点连线的左侧还是右侧（左：0；右：1），方向为第一定位点到第二定位点
		temprate = Judgeleft_right(tail_l, controls[0], controls[1]);
		rates.push_back(temprate);
		//第十比例值：第五修饰点在第一、第二定位点连线的左侧还是右侧（左：0；右：1），方向为第一定位点到第二定位点
		temprate = Judgeleft_right(tail_r, controls[0], controls[1]);
		rates.push_back(temprate);
	}
}


void GM29800::modifyControlPoints(std::vector<GVCoord>& controlPoints)
{
	//对传入的所有控制点进行修正
	int  lenth = controlPoints.size();
	std::vector<double>  lon_interpolation;
	if (lenth >= 2)
	{
		for (int i = 1, j = 0; i < lenth; i++, j++)
		{

			double lon_inter = controlPoints[i].lon - controlPoints[i - 1].lon;
			lon_interpolation.push_back(lon_inter);
			if (abs(lon_interpolation[j]) > 180)
			{
				if (lon_interpolation[j] > 0)
					lon_interpolation[j] = lon_interpolation[j] - 360;
				else
					lon_interpolation[j] = lon_interpolation[j] + 360;
			}
			controlPoints[i].lon = controlPoints[i - 1].lon + lon_interpolation[j];
		}

	}
}

