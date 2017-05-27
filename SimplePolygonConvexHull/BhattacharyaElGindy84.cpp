#include "BhattacharyaElGindy84.h"

BhattacharyaElGindy84* BhattacharyaElGindy84::instance = NULL;

// 从max到min构造一半的凸包
void BhattacharyaElGindy84::getHalfConvexHull(SimplePolygon &sp, int max, int min)
{
	sp.convexHull.push_back(max);
	auto size = sp.points.size();
	int pre = max, i = (max + 1) % size;

	if (i == min) return;
	sp.convexHull.push_back(i);

	for (i = (i + 1) % size; i != min; i = (i + 1) % size) {
		auto toLeft0 = toLeft(sp.points[pre], sp.points[sp.convexHull.back()], sp.points[i]);

		if (!toLeft0 && toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]],
		                       sp.points[sp.convexHull.back()],
		                       sp.points[i])) {
			for (; !intersect(sp.points[i],
			                  sp.points[(i + 1) % size],
			                  sp.points[sp.convexHull[sp.convexHull.size() - 2]],
			                  sp.points[sp.convexHull.back()]); i = (i + 1) % size);
		}

		else if (toLeft0 && (sp.points[min].x < sp.points[max].x) !=
		                    (sp.points[i].x < sp.points[sp.convexHull.back()].x)) {
			for (; (sp.points[min].x < sp.points[max].x) !=
			       (sp.points[(i + 1) % size].x < sp.points[sp.convexHull.back()].x); i = (i + 1) % size);
		}

		else {
			pre = sp.convexHull.back();
			while (sp.convexHull.size() >= 2 &&
			       !toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]],
			                         sp.points[sp.convexHull.back()],
			                         sp.points[i]))
				sp.convexHull.pop_back();
			sp.convexHull.push_back(i);
		}
	}

	while (sp.convexHull.size() >= 2 &&
	       !toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]],
	               sp.points[sp.convexHull.back()],
	               sp.points[i]))
		sp.convexHull.pop_back();
}

void BhattacharyaElGindy84::getConvexHull(SimplePolygon & sp)
{
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	getHalfConvexHull(sp, max, min);
	getHalfConvexHull(sp, min, max);
}

void BhattacharyaElGindy84::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{

}
