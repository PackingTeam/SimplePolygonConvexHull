#include "PreparataShamos85.h"

PreparataShamos85* PreparataShamos85::instance = NULL;

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
	// -1 表示添加的辅助点
	// 横坐标与x_min一致 y坐标比x_min小
	upHull.push_back(-1);
	Point supportLeft(sp.points[leftIndex].x, sp.points[leftIndex].y - 2);
	upHull.push_back(leftIndex);

	int upHull_Size = 2;

	for (int i = leftIndex + 1; ; ++i) {
		int index = i % N;
		if (index == rightIndex) {
			//upHull_Size++;
			//upHull.push_back(rightIndex);
			break;
		}

		// flag1：栈顶两个元素构成的有向直线
		bool flag1 = false;
		// flag2：栈顶元素和它的前驱
		bool flag2 = false;
		// flag3：栈顶元素到最右端点
		bool flag3 = false;

		flag1 = upHull[upHull_Size-2] == -1 ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[upHull[upHull_Size-2]], sp.points[upHull.back()], sp.points[index]);

		if (flag1) {
			// 在区域2
			// 一直退栈直到flag1为true
			while (true) {
				upHull.pop_back();
				upHull_Size--;
				flag1 = upHull[upHull_Size - 2] == -1 ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[upHull[upHull_Size - 2]], sp.points[upHull.back()], sp.points[index]);
				if (!flag1)	break;
			}
		}

		flag2 = upHull.back() == leftIndex ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[(upHull.back() - 1 + N) % N], sp.points[upHull.back()], sp.points[index]);

		//区域1
		if (flag2)	continue;

		flag3 = toLeft(sp.points[upHull.back()], sp.points[rightIndex], sp.points[index]);

		if (flag3) {
			// 区域3
			upHull.push_back(index);
			upHull_Size++;
		}
		else {
			// 区域4
			continue;
		}
	}

	vector<int> downHull;
	// 添加辅助点 x坐标等于x_max 在rightIndex的上方
	downHull.push_back(-1);
	Point supportRight(sp.points[rightIndex].x, sp.points[rightIndex].y + 2);
	downHull.push_back(rightIndex);
	int downHull_Size = 2;

	for (int i = rightIndex + 1; ; ++i) {
		int index = i % N;
		if (index == leftIndex) {
			//downHull_Size++;
			//downHull.push_back(leftIndex);
			break;
		}

		// flag1：栈顶两个元素构成的有向直线
		bool flag1 = false;
		// flag2：栈顶元素和它的前驱
		bool flag2 = false;
		// flag3：栈顶元素到最右端点
		bool flag3 = false;

		flag1 = downHull[downHull_Size - 2] == -1 ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull.back()], sp.points[index]);

		if (flag1) {
			// 在区域2
			// 一直退栈直到flag1为true
			while (true) {
				downHull.pop_back();
				downHull_Size--;
				flag1 = downHull[downHull_Size - 2] == -1 ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull.back()], sp.points[index]);
				if (!flag1)	break;
			}
		}

		flag2 = downHull.back() == rightIndex ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[(downHull.back() - 1 + N) % N], sp.points[downHull.back()], sp.points[index]);

		//区域1
		if (flag2)	continue;

		flag3 = toLeft(sp.points[downHull.back()], sp.points[leftIndex], sp.points[index]);

		if (flag3) {
			// 区域3
			downHull.push_back(index);
			downHull_Size++;
		}
		else {
			// 区域4
			continue;
		}
	}

	for (int i = 1; i < upHull_Size; ++i) {
		sp.convexHull.push_back(upHull[i]);
	}

	for (int i = 1; i < downHull_Size; ++i) {
		sp.convexHull.push_back(downHull[i]);
	}
}

void PreparataShamos85::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{

}