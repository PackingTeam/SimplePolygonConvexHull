#include "McCallumAvis79.h"
#include <stack>

using namespace std;

// 从max到min构造一半的凸包
void McCallumAvis79::getHalfConvexHull(SimplePolygon &sp, int max, int min)
{
	sp.convexHull.push_back(max);
	auto size = sp.points.size();
	int i = (max + 1) % size;

	for (; i != min && toLeft(sp.points[max], sp.points[min], sp.points[i]); i = (i + 1) % size);
	if (i == min) return;
	sp.convexHull.push_back(i);

	vector<int> rejectedConvexHull;
	rejectedConvexHull.push_back(min);
	for (i = (i + 1) % size; i != min; i = (i + 1) % size) {
		auto toLeft0 = toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]],
		                      sp.points[sp.convexHull.back()],
		                      sp.points[i]),
		     toLeft1 = toLeft(sp.points[sp.convexHull.back()],
		                      sp.points[rejectedConvexHull.back()],
		                      sp.points[i]);

		if (!toLeft1) {
			while (rejectedConvexHull.size() >= 2 &&
			       toLeft(sp.points[rejectedConvexHull[rejectedConvexHull.size() - 2]],
			              sp.points[rejectedConvexHull.back()],
			              sp.points[i]))
				rejectedConvexHull.pop_back();
			if (!toLeft0) {
				while (sp.convexHull.size() >= 2 &&
				       !toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]],
				               sp.points[sp.convexHull.back()],
				               sp.points[i]))
					sp.convexHull.pop_back();
			}
			sp.convexHull.push_back(i);
		}

		else if (!toLeft0) {
			rejectedConvexHull.push_back(sp.convexHull.back());
			sp.convexHull.pop_back();
			while (sp.convexHull.size() >= 2 &&
			       !toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]],
			               sp.points[sp.convexHull.back()],
			               sp.points[i]))
			sp.convexHull.pop_back();
		}
	}
}

void McCallumAvis79::getConvexHull(SimplePolygon & sp)
{
	sp.convexHull.clear();
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	getHalfConvexHull(sp, max, min);
	getHalfConvexHull(sp, min, max);
}

void McCallumAvis79::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{

}
