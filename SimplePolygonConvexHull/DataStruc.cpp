#include "DataStruc.h"

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

// ���ݺ����������ж���ֻ�ı���λisCounterClockWise��ȷ�����򣬻��Ǹ������������˳��
void SimplePolygon::reverse()
{

}

// ���ݸ����ĵ㼯˳�����ó���ǰ�򵥶���εĵ㼯˳�򣬲��ݴ�����isCounterClockWise��ֵ
void SimplePolygon::makeDirectoin()
{
	isCounterClockWise = getPolygonDirection(points);
}

// �ж���ǰ�ļ򵥶�����Ƿ�Ϸ������Ƿ�����Խ����غ�Ƕ�׵�
bool SimplePolygon::isLegal()
{
	return true;
}

// �����ų��������������ظ��㣬����ͨ����������ʹ�õ�һ����Ϊ�������µ㣬�Ӷ���㼯�������滯
// ע��	���ܻ���ַ������ĵ�����غϵ���������������������غϵ���������бȽ��򻨷�����O(nlogn)��ʱ���������С�
//		����������Ĺ����������������У�������ʱ�临�Ӷȡ�
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
			// ����remove��erase��Ч���������������
		{

		}
	}
}
