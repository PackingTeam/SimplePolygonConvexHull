#include "GhoshShyamasundar83.h"

GhoshShyamasundar83* GhoshShyamasundar83::instance = NULL;

// 从max到min构造一半的凸包
void GhoshShyamasundar83::getHalfConvexHull(SimplePolygon &sp, int max, int min)
{
	sp.convexHull.push_back(max);
	auto size = sp.points.size();
	int i = (max + 1) % size;

	if (i == min) return;
	sp.convexHull.push_back(i);

	for (i = (i + 1) % size; i != min; i = (i + 1) % size) {
		while (sp.convexHull.size() >= 2 &&
		       !toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]],
		               sp.points[sp.convexHull.back()],
		               sp.points[i]))
			sp.convexHull.pop_back();

		if ((sp.points[min].x < sp.points[max].x) ==
		    (sp.points[i].x < sp.points[sp.convexHull.back()].x))
			sp.convexHull.push_back(i);
	}

	while (sp.convexHull.size() >= 2 &&
	       !toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]],
	               sp.points[sp.convexHull.back()],
	               sp.points[i]))
		sp.convexHull.pop_back();
}

void GhoshShyamasundar83::getConvexHull(SimplePolygon & sp)
{
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	getHalfConvexHull(sp, max, min);
	getHalfConvexHull(sp, min, max);
}

void GhoshShyamasundar83::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{

}
