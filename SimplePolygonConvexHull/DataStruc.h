#pragma once

#include <vector>
#include <QPointF>
#include <QLineF>
#include <QPolygonF>
#include <deque>
#include "./lib/GenerateSimplePolygon.h"

using namespace std;

#define tolerance 0.000001 // 定义容差为10^-6
#define sceneWidth 990 // 界面显示的区域宽度
#define sceneHeight 537 // 界面显示的区域高度
#define maxSameDistance 10 // 在输入时，判定最后一个点和原来的点接合的距离

// 颜色枚举类，用于区分颜色
// 其他颜色根据情况使用。
//// Qt::black:给定的原多边形的点，在Display类中不需要添加原有多边形的所有点，默认会在界面绘制。
//// Qt::red:当前正在检查的点。
//// Qt::gray:（可能需要显示的）已经排除掉的点。
//// Qt::yellow:当前检查所用到的点。
//// Qt::green:凸包上的点。最后一步会根据SimplePolygon中的值显示。
//// Qt::white,Qt::darkRed,Qt::darkGreen,Qt::blue,Qt::darkBlue,Qt::cyan,Qt::darkCyan
//// Qt::magenta,Qt::darkMagenta,Qt::darkYellow,Qt::lightGray,Qt::darkGray根据情况使用

typedef vector<Qt::GlobalColor> Colors;

// 点的数据类
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
	// 从序列化字符串恢复数据
	void setPoint(const string& str);
	// 序列化
	string toString();
};

typedef vector<Point> Points;

// 线段类型枚举类
enum LineType
{
	LINE, RAY, SEGMENT, SOLID, DASH, DOT
};

// 线的数据类
// 显示时，直线、射线、线段都显示虚线
class Line 
{
public:
	Point a;
	Point b;
	// LINE:直线(a,b),RAY:直线(a,b),SEGMENT:线段(a,b)
	LineType type; // 默认为实线直线

public:
	// 默认为实线直线
	Line(Point &A, Point &B, LineType Type = LINE) : a(A), b(B), type(Type) {}
	// 默认为实线直线
	Line(double x1, double y1, double x2, double y2, LineType Type = LINE) : a(x1, y1), b(x2, y2), type(Type) {}
	// 默认为实线直线
	Line(const Line & line) : a(line.a), b(line.b), type(line.type) {}
	// 将该直线转化为显示用的直线
	void getQLineF(QLineF &qline);
};

typedef vector<Line> Lines;

// 区域的数据类
class Area 
{
public:
	Points points;
	// 将其转化为显示用的polygon
	void getQPolygon(QPolygonF &qpolygon);
};

typedef vector<Area> Areas;


// 用于演示的数据类
// 在Display类中不需要添加原有多边形的所有点，这些点默认会在界面绘制。
// 最终确定的凸包，会根据SimplePolygon中的值在所有Display演示结束后显示，无需考虑。
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

// 简单多边形类
class SimplePolygon 
{
public:
	// 存储了简单多边形中所有的点，默认按照逆时针顺序存储
	Points points;
	// 用于存储凸包中所含的点的下标，默认按照逆时针顺序存储
	vector<int> convexHull;

public:
	// 将更改整个数组的顺序
	void reverse();
	// 判定当前的简单多边形是否合法，即是否存在自交、重合嵌套等
	// 点集的个数必须大于等于3，整个简单多边形面积不为0。
	bool isLegal();
	// 用于排除输入中连续的重复点，并使得整个点集为逆时针方向
	// 注： 目前版本并没有删除所有重合的点，仅仅删除了连续的重合的点。
	void normalize();
	// 将其转化为显示用的polygon
	void getQPolygon(QPolygonF &qpolygon);
	// 将凸包转化为显示用的polygon
	void getConvexHullPolygon(QPolygonF &qpolygon);
	// 清除已有的所有数据
	void clearAll();
	// 获得最左最下点的坐标
	int getLeftMostThenLowestPoint();
	// 获得最右最上点的坐标
	int getRightMostThenHighestPoint();
	// 从序列化字符串恢复数据
	void setPolygon(const string& str);
	// 序列化
	string toString();
};


// 判定范围如备注中图：
//  ==o----o----  
//     (b)   (a)
// 如图，在线段ab的b侧延长线上以及直线ab左侧的点判定为true，其他为false
// 注：不考虑三个点存在任意两点重合的情况，此种情况应该在之前的处理中已经排除
extern bool toLeft(const Point & a, const Point & b, const Point & c);

// 线段ab与线段cd是否有交点
extern bool intersect(const Point & a, const Point & b, const Point & c, const Point & d);

// 返回值为true,点的序列为逆时针
// 返回值为false,点的序列为顺时针
extern bool getPolygonDirection(const Points& points);

// 获得由一系列点围成的多边形有向面积，逆时针形成的有向面积为正，顺时针形成的为负
extern double getDirectedArea(const Points& points);

// 用于分割字符串
extern void SplitString(const string& s, std::vector<std::string>& v, const std::string& c);

// 随机生成简单多边形
extern void generateSimplePolygon(SimplePolygon& sp, int num, int width, int height);