#pragma once

#include <vector>

using namespace std;

#define tolerance 0.000001 // �����ݲ�Ϊ10^-6

// ��ɫö���࣬����������ɫ
// ������ɫ�������ʹ�á�
enum Color
{
	// BLACK:������ԭ����εĵ㣬��Display���в���Ҫ���ԭ�ж���ε����е㣬Ĭ�ϻ��ڽ�����ơ�
	BLACK, 
	// WHITE:�������ʹ��
	WHITE,
	// RED:��ǰ���ڼ��ĵ㡣
	RED,
	// GREEN:͹���ϵĵ㡣���һ�������SimplePolygon�е�ֵ��ʾ��
	GREEN, 
	// BLUE:�������ʹ��
	BLUE,
	// YELLOW:��ǰ������õ��ĵ㡣
	YELLOW,
	// PINK:�������ʹ��
	PINK,
	// PURPLE:�������ʹ��
	PURPLE,
	// GREY:��������Ҫ��ʾ�ģ��Ѿ��ų����ĵ㡣
	GREY
};

typedef vector<Color> Colors;

// ���������
class Point
{
public:
	double x;
	double y;

public:
	Point(double a = 0, double b = 0) : x(a), y(b) {}
	Point(const Point &m) : x(m.x), y(m.y) {}
	Point() {}
	void setPoint(double X, double Y) {
		x = X;
		y = Y;
	}
};

typedef vector<Point> Points;

// �߶�����ö����
enum LineType
{
	LINE, RAY, SEGMENT
};

// �ߵ�������
// ��ʾʱ��ֱ�ߡ����ߡ��߶ζ���ʾ����
class Line 
{
public:
	Point a;
	Point b;
	// LINE:ֱ��(a,b),RAY:ֱ��(a,b),SEGMENT:�߶�(a,b)
	LineType type; // Ĭ��Ϊֱ��

public:
	// Ĭ��Ϊֱ��
	Line(Point &A, Point &B, LineType Type = LINE) : a(A), b(B), type(Type) {}
	// Ĭ��Ϊֱ��
	Line(double x1, double y1, double x2, double y2, LineType Type = LINE) : a(x1, y1), b(x2, y2), type(Type) {}
	// Ĭ��Ϊֱ��
	Line(const Line & line) : a(line.a), b(line.b), type(line.type) {}
};

typedef vector<Line> Lines;

// �����������
class Area 
{
public:
	Points points;
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
};

typedef vector<Display> Displays;

// �򵥶������
class SimplePolygon 
{
public:
	bool isCounterClockWise = false;
	// �洢�˼򵥶���������еĵ㣬Ĭ�ϰ�����ʱ��˳��洢
	Points points;
	// ���ڴ洢͹���������ĵ���±꣬Ĭ�ϰ�����ʱ��˳��洢
	vector<int> convexHull;

public:
	// ���ݺ����������ж���ֻ�ı���λisCounterClockWise��ȷ�����򣬻��Ǹ������������˳��
	void reverse();
	// �ж���ǰ�ļ򵥶�����Ƿ�Ϸ������Ƿ�����Խ����غ�Ƕ�׵�
	// �㼯�ĸ���������ڵ���3�������򵥶���������Ϊ0��
	bool isLegal();
	// �����ų��������������ظ��㣬����ͨ����������ʹ�õ�һ����Ϊ�������µ㣬�Ӷ���㼯�������滯
	// ע��	���ܻ���ַ������ĵ�����غϵ���������������������غϵ���������бȽ��򻨷�����O(nlogn)��ʱ���������С�
	//		����������Ĺ����������������У�������ʱ�临�Ӷȡ�
	//		�����е���makeDirection()��ȷ���㼯�ķ���
	void normalize();

private:
	// ���ݵ���±����ó���ǰ�򵥶���εĵ㼯˳�򣬲��ݴ�����isCounterClockWise��ֵ
	// ��normalize()�н��е���
	void makeDirectoin();
};


// �ж���Χ�籸ע��ͼ��
//  ==o----o----  
//     (b)   (a)
// ��ͼ�����߶�ab��b���ӳ������Լ�ֱ��ab���ĵ��ж�Ϊtrue������Ϊfalse
// ע��������������������������غϵ�������������Ӧ����֮ǰ�Ĵ������Ѿ��ų�
extern bool toLeft(const Point & a, const Point & b, const Point & c);

//����ֵΪtrue,�������Ϊ��ʱ��
//����ֵΪfalse,�������Ϊ˳ʱ��
extern bool getPolygonDirection(const Points& points);

//�����һϵ�е�Χ�ɵĶ���������������ʱ���γɵ��������Ϊ����˳ʱ���γɵ�Ϊ��
extern double getDirectedArea(const Points& points);