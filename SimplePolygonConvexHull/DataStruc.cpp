#include "DataStruc.h"
#include <cmath>

// ����ֱ��ת��Ϊ��ʾ�õ�ֱ��
void Line::getQLineF(QLineF &qline)
{
	qline.setLine(a.x,a.y,b.x,b.y);
}

// ����ת��Ϊ��ʾ�õ�polygon
void Area::getQPolygon(QPolygonF &qpolygon)
{
	qpolygon.clear();
	int size = points.size();
	for (int i = 0; i < size; i++)
	{
		QPointF temp;
		points[i].getQPointF(temp);
		qpolygon << temp;
	}
	QPointF temp;
	points[0].getQPointF(temp);
	qpolygon << temp;
}

// ����ת��Ϊ��ʾ�õ�polygon
void SimplePolygon::getQPolygon(QPolygonF &qpolygon)
{
	qpolygon.clear();
	int size = points.size();
	for (int i = 0; i < size; i++)
	{
		QPointF temp;
		points[i].getQPointF(temp);
		qpolygon << temp;
	}
	QPointF temp;
	points[0].getQPointF(temp);
	qpolygon << temp;
}

// ��͹��ת��Ϊ��ʾ�õ�polygon
void SimplePolygon::getConvexHullPolygon(QPolygonF &qpolygon)
{
	qpolygon.clear();
	int size = convexHull.size();
	for (int i = 0; i < size; i++)
	{
		QPointF temp;
		points[convexHull[i]].getQPointF(temp);
		qpolygon << temp;
	}
	QPointF temp;
	points[convexHull[0]].getQPointF(temp);
	qpolygon << temp;
}

// �ж���Χ�籸ע��ͼ��
//  ==o----o----  
//      (b)   (a)
// ��ͼ�����߶�ab��b���ӳ������Լ�ֱ��ab���ĵ��ж�Ϊtrue������Ϊfalse
// ע��������������������������غϵ�������������Ӧ����֮ǰ�Ĵ������Ѿ��ų�
bool toLeft(const Point & a, const Point & b, const Point & c)
{
	double area2 = a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x;
	// �жϹ������ݲ����Ƚ�
	if (area2 > tolerance) // �����
		return true;
	else if (area2 < -tolerance) // ���Ҳ�
		return false;
	else // �������
	{
		// ʹ��x�������
		double ac = c.x - a.x;
		double bc = c.x - b.x;

		if (abs(ac) < tolerance) // ��ֱ���ߵ������ʹ��y����
		{
			ac = c.y - a.y;
			bc = c.y - b.y;
		}
		if (ac * bc > 0 && abs(ac) > abs(bc)) // �жϷ�������ʱ���������ݲ�����
			return true;
		else
			return false;
	}
}

// ����ֵΪtrue,�������Ϊ��ʱ��
// ����ֵΪfalse,�������Ϊ˳ʱ��
bool getPolygonDirection(const Points& points)
{
	// ���������Ϊ0��������������ݲ�
	return getDirectedArea(points) > 0;
}

// �����һϵ�е�Χ�ɵĶ���������������ʱ���γɵ��������Ϊ����˳ʱ���γɵ�Ϊ��
extern double getDirectedArea(const Points& points)
{
	int size = points.size();
	double x1, y1, x2, y2;
	double total = 0;
	int j;
	for (int i = 0; i < size; i++) {
		j = (i + 1) % size;
		x1 = points[i].x;
		y1 = points[i].y;
		x2 = points[j].x;
		y2 = points[j].y;
		total += (x1 - x2)*(y1 + y2);
	}
	return total;
}

// ���������������˳��
void SimplePolygon::reverse()
{
	std::reverse(points.begin(), points.end());
}

// ������е���������
void SimplePolygon::clearAll()
{
	points.clear();
	convexHull.clear();
}

// �ж���ǰ�ļ򵥶�����Ƿ�Ϸ������Ƿ�����Խ����غ�Ƕ�׵�
bool SimplePolygon::isLegal()
{
	return true;
}

// �����ų��������������ظ��㣬��ʹ�������㼯Ϊ��ʱ�뷽��
// ע�� Ŀǰ�汾��û��ɾ�������غϵĵ㣬����ɾ�����������غϵĵ㡣
void SimplePolygon::normalize()
{
	double x1, y1, x2, y2;
	int j;
	for (int i = 0; i < points.size();) {
		j = (i + 1) % points.size();
		x1 = points[i].x;
		y1 = points[i].y;
		x2 = points[j].x;
		y2 = points[j].y;
		if (abs(x1 - x2) < tolerance && abs(y1 - y2) < tolerance)
			points.erase(points.begin() + j);
		else
			i++;
	}
	
	if (!getPolygonDirection(points))
	{
		reverse();
	}
}

// ����������µ������
int SimplePolygon::getLeftMostThenLowestPoint()
{
	int min = 0, size = points.size();
	for (int i = 0; i < size; i++) {
		if ((points[i].x < points[min].x) || (abs(points[i].x - points[min].x) < tolerance && points[i].y < points[min].y))
		{
			min = i;
		}
	}
	return min;
}
