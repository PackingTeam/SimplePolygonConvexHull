#include "LeeGrahamYao83.h"

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

	// 实现 Graham&Yao 的方法

	// 将点列顺时针排列
	reverse(points.begin(), points.end());

	//找最右最上点

	int m = -1;
	double xMax = -1e9;
	double yMax = -1e9;

	for (int i = 0; i < N; ++i) {
		if (points[i].x > xMax) {
			m = i;
			xMax = points[i].x;
			yMax = points[i].y;
		}
		else if (points[i].x == xMax) {
			if (points[i].y > yMax) {
				m = i;
				yMax = points[i].y;
			}
		}
	}

	// 先处理一半凸包

	vector<int> inds;
	// 现在最后一个点是最左最下点
	inds.push_back(N - 1);
	for (int i = m; i + 1 < N; ++i) {
		inds.push_back(i);
	}

	int CH = 2;
	result.push_back(inds[0]);
	result.push_back(inds[1]);

	int X = 2;
	

	while (toLeft(points[result[CH - 1]], points[result[CH - 2]], points[inds[X]])) {
		++X;
	}

	result.push_back(inds[X]);
	++CH;

	while (X < inds.size()) {
		++X;
		if (!toLeft(points[result[CH - 1]], points[result[CH - 2]], points[inds[X]])) {
			int LS = -1, LE = -1;
			if (toLeft(points[inds[X - 1]], points[result[CH - 1]], points[inds[X]])) {
				LS = result[CH - 2];
				LE = result[CH - 1];
			}
			else {
				LS = result[CH - 1];
				LE = result[0];
			}
			while (!toLeft(points[LS], points[LE], points[inds[X]])) {
				++X;
			}
		}
		if (X >= inds.size())	break;

		while (toLeft(points[result[CH - 1]], points[result[CH - 2]], points[inds[X]])) {
			result.pop_back();
			--CH;
		}

		result.push_back(inds[X]);
		++CH;
	}
}

void LeeGrahamYao83::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{

}