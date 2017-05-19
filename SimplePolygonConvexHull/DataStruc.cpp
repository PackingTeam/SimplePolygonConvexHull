#include "DataStruc.h"

// 判定范围如备注中图：
//  ==o----o----  
//      (b)   (a)
// 如图，在线段ab的b侧延长线上以及直线ab左侧的点判定为true，其他为false
// 注：不考虑三个点存在任意两点重合的情况，此种情况应该在之前的处理中已经排除
bool toLeft(const Point & a, const Point & b, const Point & c)
{
	double area2 = a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x;
	// 判断共线与容差作比较
	if (area2 > tolerance) // 在左侧
		return true;
	else if (area2 < -tolerance) // 在右侧
		return false;
	else // 共线情况
	{
		// 使用x坐标计算
		double ac = c.x - a.x;
		double bc = c.x - b.x;

		if (abs(ac) < tolerance) // 垂直共线的情况，使用y坐标
		{
			ac = c.y - a.y;
			bc = c.y - b.y;
		}
		if (ac * bc > 0 && abs(ac) > abs(bc)) // 判断符号正负时，不考虑容差因素
			return true;
		else
			return false;
	}
}

// 返回值为true,点的序列为逆时针
// 返回值为false,点的序列为顺时针
bool getPolygonDirection(const Points& points)
{
	// 不考虑面积为0的情况，不考虑容差
	return getDirectedArea(points) > 0;
}

// 获得由一系列点围成的多边形有向面积，逆时针形成的有向面积为正，顺时针形成的为负
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

// 根据后续决定来判断是只改变标记位isCounterClockWise来确定方向，还是更改整个数组的顺序
void SimplePolygon::reverse()
{

}

// 根据给定的点集顺序来得出当前简单多边形的点集顺序，并据此设置isCounterClockWise的值
void SimplePolygon::makeDirectoin()
{
	isCounterClockWise = getPolygonDirection(points);
}

// 判定当前的简单多边形是否合法，即是否存在自交、重合嵌套等
bool SimplePolygon::isLegal()
{
	return true;
}

// 用于排除输入中连续的重复点，并且通过调换次序使得第一个点为最左最下点，从而令点集序列正规化
// 注：	可能会出现非连续的点出现重合的现象，若后续对任意可能重合的两个点进行比较则花费至少O(nlogn)的时间在排序中。
//		而调换次序的工作可以在排序后进行，不提升时间复杂度。
void SimplePolygon::normalize()
{
	int size = points.size();
	double x1, y1, x2, y2;
	int j;
	for (int i = 0; i < size; i++) {
		j = (i + 1) % size;
		x1 = points[i].x;
		y1 = points[i].y;
		x2 = points[j].x;
		y2 = points[j].y;
		if (abs(x1 - x2) < tolerance && abs(y1 - y2) < tolerance)
			// 考虑remove和erase的效率问题后再作操作
		{

		}
	}
}
