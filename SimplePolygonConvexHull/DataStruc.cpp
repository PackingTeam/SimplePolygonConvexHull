#include "DataStruc.h"
#include <cmath>

using std::abs;

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

void Display::clearAll()
{
	points.clear();
	pointColors.clear();
	lines.clear();
	lineColors.clear();
	areas.clear();
	areaColors.clear();
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

// �߶�ab���߶�cd�Ƿ��н���
bool intersect(const Point & a, const Point & b, const Point & c, const Point & d)
{
	return toLeft(a, b, c) == toLeft(b, a, d) && toLeft(c, d, a) == toLeft(d, c, b);
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
// Ĭ���Ѿ�����normalize()
// ʹ�ñ������������ڴ�㼯����������ʹ��ɨ�����㷨���иĽ�
bool SimplePolygon::isLegal()
{
	int size = points.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 2; j < size - 1; j++)
		{
			if (intersect(points[i%size], points[(i + 1) % size], points[(i + j) % size], points[(i + j + 1) % size]))
				return false;
		}
	}
	return true;
}

// �����ų��������������ظ��㣬��ʹ�������㼯Ϊ��ʱ�뷽��
// ע�� Ŀǰ�汾��û��ɾ�������غϵĵ㣬����ɾ�����������غϵĵ㡣
void SimplePolygon::normalize()
{
	double x1, y1, x2, y2;
	int j;
	for (decltype(points.size()) i = 0; i < points.size();) {
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
		reverse();
}

// ����������µ������
int SimplePolygon::getLeftMostThenLowestPoint()
{
	int min = 0, size = points.size();
	for (int i = 0; i < size; i++)
		if ((points[i].x < points[min].x) || (abs(points[i].x - points[min].x) < tolerance && points[i].y < points[min].y))
			min = i;
	return min;
}

// ����������ϵ������
int SimplePolygon::getRightMostThenHighestPoint()
{
	int max = 0, size = points.size();
	for (int i = 0; i < size; i++)
		if ((points[i].x > points[max].x) || (abs(points[i].x - points[max].x) < tolerance && points[i].y > points[max].y))
			max = i;
	return max;
}

// �����л��ַ����ָ�����
void SimplePolygon::setPolygon(const string& str)
{
	// ���ԭ������
	clearAll();

	vector<string> temp;
	SplitString(str, temp, ";");
	Point tp;
	int size = temp.size();
	for (int i = 0; i < size; i++)
	{
		tp.setPoint(temp[i]);
		points.push_back(tp);
	}
}

// ���л�
string SimplePolygon::toString()
{
	string temp = "";
	int size = points.size();
	for (int i = 0; i < size; i++)
	{
		temp += points[i].toString() + ";";
	}
	return temp;
}

// �����л��ַ����ָ�����
void Point::setPoint(const string& str)
{
	vector<string> temp;
	SplitString(str, temp, ",");
	if (temp.size() != 2) // �������
		return;
	double td = stod(temp[0].substr(1, temp[0].size() - 1));
	x = td;
	td = stod(temp[1].substr(0, temp[0].size() - 1));
	y = td;
}

// ���л�
string Point::toString()
{
	return "(" + to_string(x) + "," + to_string(y) + ")";
}

void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}
