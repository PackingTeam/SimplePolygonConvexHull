#pragma once

#include <vector>
#include <QPointF>
#include <QLineF>
#include <QPolygonF>
#include <deque>
#include "./lib/GenerateSimplePolygon.h"

using namespace std;

#define tolerance 0.000001 // �����ݲ�Ϊ10^-6
#define sceneWidth 990 // ������ʾ��������
#define sceneHeight 537 // ������ʾ������߶�
#define maxSameDistance 10 // ������ʱ���ж����һ�����ԭ���ĵ�Ӻϵľ���

// ��ɫö���࣬����������ɫ
// ������ɫ�������ʹ�á�
//// Qt::black:������ԭ����εĵ㣬��Display���в���Ҫ���ԭ�ж���ε����е㣬Ĭ�ϻ��ڽ�����ơ�
//// Qt::red:��ǰ���ڼ��ĵ㡣
//// Qt::gray:��������Ҫ��ʾ�ģ��Ѿ��ų����ĵ㡣
//// Qt::yellow:��ǰ������õ��ĵ㡣
//// Qt::green:͹���ϵĵ㡣���һ�������SimplePolygon�е�ֵ��ʾ��
//// Qt::white,Qt::darkRed,Qt::darkGreen,Qt::blue,Qt::darkBlue,Qt::cyan,Qt::darkCyan
//// Qt::magenta,Qt::darkMagenta,Qt::darkYellow,Qt::lightGray,Qt::darkGray�������ʹ��

typedef vector<Qt::GlobalColor> Colors;

// ���������
class Point
{
public:
	double x;
	double y;

public:
	Point(double a = 0, double b = 0) : x(a), y(b) {}
	Point(const Point &m) : x(m.x), y(m.y) {}
	Point(const QPointF &qpoint)
	{
		x = qpoint.x();
		y = qpoint.y();
	}
	void getQPointF(QPointF &qpoint)
	{
		qpoint.setX(x);
		qpoint.setY(y);
	}
	void setPoint(const QPointF &qpoint)
	{
		x = qpoint.x();
		y = qpoint.y();
	}
	void setPoint(double X, double Y) 
	{
		x = X;
		y = Y;
	}
	bool operator==(const Point &point2)
	{
		if (x == point2.x && y == point2.y)
			return true;
		else
			return false;
	}
	// �����л��ַ����ָ�����
	void setPoint(const string& str);
	// ���л�
	string toString();
};

typedef vector<Point> Points;

// �߶�����ö����
enum LineType
{
	LINE, RAY, SEGMENT, SOLID, DASH, DOT
};

// �ߵ�������
// ��ʾʱ��ֱ�ߡ����ߡ��߶ζ���ʾ����
class Line 
{
public:
	Point a;
	Point b;
	// LINE:ֱ��(a,b),RAY:ֱ��(a,b),SEGMENT:�߶�(a,b)
	LineType type; // Ĭ��Ϊʵ��ֱ��

public:
	// Ĭ��Ϊʵ��ֱ��
	Line(Point &A, Point &B, LineType Type = LINE) : a(A), b(B), type(Type) {}
	// Ĭ��Ϊʵ��ֱ��
	Line(double x1, double y1, double x2, double y2, LineType Type = LINE) : a(x1, y1), b(x2, y2), type(Type) {}
	// Ĭ��Ϊʵ��ֱ��
	Line(const Line & line) : a(line.a), b(line.b), type(line.type) {}
	// ����ֱ��ת��Ϊ��ʾ�õ�ֱ��
	void getQLineF(QLineF &qline);
};

typedef vector<Line> Lines;

// �����������
class Area 
{
public:
	Points points;
	// ����ת��Ϊ��ʾ�õ�polygon
	void getQPolygon(QPolygonF &qpolygon);
};

typedef vector<Area> Areas;


// ������ʾ��������
// ��Display���в���Ҫ���ԭ�ж���ε����е㣬��Щ��Ĭ�ϻ��ڽ�����ơ�
// ����ȷ����͹���������SimplePolygon�е�ֵ������Display��ʾ��������ʾ�����迼�ǡ�
class Display
{
public:
	Points points;
	Colors pointColors;
	Lines lines;
	Colors lineColors;
	Areas areas;
	Colors areaColors;
	void clearAll();
};

typedef vector<Display> Displays;

// �򵥶������
class SimplePolygon 
{
public:
	// �洢�˼򵥶���������еĵ㣬Ĭ�ϰ�����ʱ��˳��洢
	Points points;
	// ���ڴ洢͹���������ĵ���±꣬Ĭ�ϰ�����ʱ��˳��洢
	vector<int> convexHull;

public:
	// ���������������˳��
	void reverse();
	// �ж���ǰ�ļ򵥶�����Ƿ�Ϸ������Ƿ�����Խ����غ�Ƕ�׵�
	// �㼯�ĸ���������ڵ���3�������򵥶���������Ϊ0��
	bool isLegal();
	// �����ų��������������ظ��㣬��ʹ�������㼯Ϊ��ʱ�뷽��
	// ע�� Ŀǰ�汾��û��ɾ�������غϵĵ㣬����ɾ�����������غϵĵ㡣
	void normalize();
	// ����ת��Ϊ��ʾ�õ�polygon
	void getQPolygon(QPolygonF &qpolygon);
	// ��͹��ת��Ϊ��ʾ�õ�polygon
	void getConvexHullPolygon(QPolygonF &qpolygon);
	// ������е���������
	void clearAll();
	// ����������µ������
	int getLeftMostThenLowestPoint();
	// ����������ϵ������
	int getRightMostThenHighestPoint();
	// �����л��ַ����ָ�����
	void setPolygon(const string& str);
	// ���л�
	string toString();
};


// �ж���Χ�籸ע��ͼ��
//  ==o----o----  
//     (b)   (a)
// ��ͼ�����߶�ab��b���ӳ������Լ�ֱ��ab���ĵ��ж�Ϊtrue������Ϊfalse
// ע��������������������������غϵ�������������Ӧ����֮ǰ�Ĵ������Ѿ��ų�
extern bool toLeft(const Point & a, const Point & b, const Point & c);

// �߶�ab���߶�cd�Ƿ��н���
extern bool intersect(const Point & a, const Point & b, const Point & c, const Point & d);

// ����ֵΪtrue,�������Ϊ��ʱ��
// ����ֵΪfalse,�������Ϊ˳ʱ��
extern bool getPolygonDirection(const Points& points);

// �����һϵ�е�Χ�ɵĶ���������������ʱ���γɵ��������Ϊ����˳ʱ���γɵ�Ϊ��
extern double getDirectedArea(const Points& points);

// ���ڷָ��ַ���
extern void SplitString(const string& s, std::vector<std::string>& v, const std::string& c);

// ������ɼ򵥶����
extern void generateSimplePolygon(SimplePolygon& sp, int num, int width, int height);