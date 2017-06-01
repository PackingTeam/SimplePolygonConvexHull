#include "GenerateSimplePolygon.h"

/*
\brief	�ж�����p0-p1-p2�ĳ���������ʱ�뷽�򣬷���1������˳ʱ�뷽�򣬷���-1�����򣬷���0.
*/
int Orientation(const Point2D& p0, const Point2D& p1, const Point2D& p2)
{
	Real d = (p1 - p0).cross(p2 - p0);
	if(d > 0)	return  1;
	if(d < 0)	return -1;
	return 0;
}

void Divide(PointList& ptList, const Point2D& p0, const Point2D& p1, int sign, PointList& part1, PointList& part2)
{
	PointListIterator  iter;
	int r ;
	for( iter = ptList.begin() ; iter != ptList.end() ; iter++ )
	{
		r = sign * Orientation(p0, p1, *iter);
		if( r > 0 )
			part1.push_back(*iter);
		else if( r < 0 )
			part2.push_back(*iter);
	}
	ptList.clear();
}

void Partition(PointList& ptList, const Point2D& p0, const Point2D& p1, PointList& result)
{
	if( ptList.empty() )
	{
		result.push_back(p1);
		result.push_back(p0);
		return ;
	}

	//������������ѡ��ĵ㣬���������������Ƴ�
	int randNode = rand() % ptList.size();
	PointListIterator iter = ptList.begin();
	while( randNode-- )
		iter ++;
	Point2D t1 = *iter;
	ptList.erase(iter);

	//����߶�p0-p1֮�������һ����
	int range = 100;
	Real t = (Real)(rand() % range) / (Real)(range);
	Point2D t0 = p0 + (p1 - p0)*t;

	PointList part1, part2;
	PointList res1, res2;

	int orient = Orientation(t0,t1,p0);
	Divide(ptList,t0,t1,orient,part1,part2);
	Partition(part1,p0,t1,res1);
	Partition(part2,t1,p1,res2);

	res1.pop_front();
	result.splice(result.begin(),res2);
	result.splice(result.end(),res1);
}

//���ȡ��������ͬ�ĵ�
void RandomPointIndex(int n, int& p0, int& p1)
{
	
	p0 = rand() % n;
	do 
	{
		p1 = rand() % n;
	} while (p1==p0);
}

/*
\brief	��������ĵ㼯�����ÿռ�ָ���������ɵļ򵥶���Σ���򵥶��������ʱ��˳���
\param[in]	pts, numPoint		�涨�㼯
\param[out] simple,numSimple	����򵥶����
*/
void GenerateSimplePolygon(const Point2D* pts, int numPoint, Point2D*& simple, int& numSimple)
{
	//���ȡ��������ͬ�ĵ�
	int p0 , p1;
	RandomPointIndex(numPoint, p0, p1);

	//�ѵ㼯��������ptList�У��ų�ǰ�����ѡ���������
	PointList ptList;
	int i;
	for( i = 0 ; i < numPoint ; ++ i )
	{
		if( i == p0 || i == p1 )
			continue;
		ptList.push_back(pts[i]);
	}

	PointList part1,part2;
	PointList res1, res2;
	PointList result;
	Divide(ptList, pts[p0], pts[p1], 1.0, part1, part2);
	Partition(part1,pts[p0],pts[p1],res1);
	Partition(part2,pts[p1],pts[p0],res2);

	res1.pop_front();
	
	result.splice(result.begin(),res2);
	result.splice(result.end(),res1);

	//����򵥶����
	PointListIterator it;
	numSimple = result.size();
	simple = new Point2D[ numSimple ];
	i = 0;
	for(it = result.begin() ; it != result.end() ; ++ it)
	{
		simple[i++] = *it;
	}
}