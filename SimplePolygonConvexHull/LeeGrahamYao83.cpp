#include "LeeGrahamYao83.h"

LeeGrahamYao83* LeeGrahamYao83::instance = NULL;

void LeeGrahamYao83::getConvexHull(SimplePolygon & sp)
{
	int N = (int)sp.points.size();
	Points& points = sp.points;
	vector<int>& result = sp.convexHull;

	if (N == 3) {
		result.push_back(0);
		result.push_back(1);
		result.push_back(2);
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
	int upHull_Size = 2;

	int i = leftIndex + 1;
	while (true) {
		if (i % N == rightIndex) {
			goto upHullFinish;
		}
		if (toLeft(sp.points[upHull[upHull_Size - 2]], sp.points[upHull[upHull_Size - 1]], sp.points[i % N])) {
			i++;
		}
		else {
			upHull.push_back(i % N);
			upHull_Size++;
			i++;
			break;
		}
	}

	if (upHull_Size > 2) {
		while (true) {
			if ((i % N) == rightIndex) {
				goto upHullFinish;
			}

			if (!toLeft(sp.points[upHull[upHull_Size - 2]], sp.points[upHull[upHull_Size - 1]], sp.points[i % N])) {
				int LS = -1, LE = -1;
				if (toLeft(sp.points[(upHull.back() - 1 + N) % N], sp.points[upHull.back()], sp.points[i % N])) {
					LS = upHull[upHull_Size - 2];
					LE = upHull[upHull_Size - 1];
				}
				else {
					LS = upHull.back();
					LE = rightIndex;
				}
				while (true) {
					if (toLeft(sp.points[LS], sp.points[LE], sp.points[i % N])) {
						break;
					}
					++i;
					if (i % N == rightIndex) {
						goto upHullFinish;
					}
				}
			}

			while (toLeft(sp.points[upHull[upHull_Size - 2]], sp.points[upHull[upHull_Size - 1]], sp.points[i % N])) {
				upHull.pop_back();
				upHull_Size--;
			}

			upHull.push_back(i % N);
			upHull_Size++;

			i++;
		}
	}
upHullFinish:
	vector<int> downHull;
	downHull.push_back(leftIndex);
	downHull.push_back(rightIndex);
	int downHull_Size = 2;

	i = rightIndex + 1;
	while (true) {
		if (i % N == leftIndex) {
			goto downHullFinish;
		}
		if (toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull[downHull_Size - 1]], sp.points[i % N])) {
			i++;
		}
		else {
			downHull.push_back(i % N);
			downHull_Size++;
			i++;
			break;
		}
	}

	if (downHull_Size > 2) {
		while (true) {
			if ((i % N) == leftIndex) {
				goto downHullFinish;
			}

			if (!toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull[downHull_Size - 1]], sp.points[i % N])) {
				int LS = -1, LE = -1;
				if (toLeft(sp.points[(downHull.back() - 1 + N) % N], sp.points[downHull.back()], sp.points[i % N])) {
					LS = downHull[downHull_Size - 2];
					LE = downHull[downHull_Size - 1];
				}
				else {
					LS = downHull.back();
					LE = leftIndex;
				}
				while (true) {
					if (toLeft(sp.points[LS], sp.points[LE], sp.points[i % N])) {
						break;
					}
					++i;
					if (i % N == leftIndex) {
						goto downHullFinish;
					}
				}
			}

			while (toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull[downHull_Size - 1]], sp.points[i % N])) {
				downHull.pop_back();
				downHull_Size--;
			}

			downHull.push_back(i % N);
			downHull_Size++;

			i++;
		}
	}

downHullFinish:
	
	for (i = 1; i < upHull_Size; ++i) {
		sp.convexHull.push_back(upHull[i]);
	}
	for (i = 1; i < downHull_Size; ++i) {
		sp.convexHull.push_back(downHull[i]);
	}
}

void LeeGrahamYao83::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{

}