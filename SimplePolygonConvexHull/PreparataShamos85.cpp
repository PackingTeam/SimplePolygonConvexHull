#include "PreparataShamos85.h"


void PreparataShamos85::getConvexHull(SimplePolygon & sp)
{
	int N = (int)sp.points.size();

	if (N == 3) {
		sp.convexHull.push_back(0);
		sp.convexHull.push_back(1);
		sp.convexHull.push_back(2);
		return;
	}

	bool isCCW = getPolygonDirection(sp.points);
	if (isCCW) {
		sp.reverse();
	}

	int leftIndex = sp.getLeftMostThenLowestPoint();
	int rightIndex = sp.getRightMostThenHighestPoint();

	vector<int> upHull;
	upHull.push_back(rightIndex);
	upHull.push_back(leftIndex);

}

void PreparataShamos85::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{

}