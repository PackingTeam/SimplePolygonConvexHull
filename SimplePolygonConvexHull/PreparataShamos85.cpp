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
	// -1 ��ʾ��ӵĸ�����
	// ��������x_minһ�� y�����x_minС
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

		// flag1��ջ������Ԫ�ع��ɵ�����ֱ��
		bool flag1 = false;
		// flag2��ջ��Ԫ�غ�����ǰ��
		bool flag2 = false;
		// flag3��ջ��Ԫ�ص����Ҷ˵�
		bool flag3 = false;

		flag1 = upHull[upHull_Size-2] == -1 ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[upHull[upHull_Size-2]], sp.points[upHull.back()], sp.points[index]);

		if (flag1) {
			// ������2
			// һֱ��ջֱ��flag1Ϊtrue
			while (true) {
				upHull.pop_back();
				upHull_Size--;
				flag1 = upHull[upHull_Size - 2] == -1 ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[upHull[upHull_Size - 2]], sp.points[upHull.back()], sp.points[index]);
				if (!flag1)	break;
			}
		}

		flag2 = upHull.back() == leftIndex ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[(upHull.back() - 1 + N) % N], sp.points[upHull.back()], sp.points[index]);

		//����1
		if (flag2)	continue;

		flag3 = toLeft(sp.points[upHull.back()], sp.points[rightIndex], sp.points[index]);

		if (flag3) {
			// ����3
			upHull.push_back(index);
			upHull_Size++;
		}
		else {
			// ����4
			continue;
		}
	}

	vector<int> downHull;
	// ��Ӹ����� x�������x_max ��rightIndex���Ϸ�
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

		// flag1��ջ������Ԫ�ع��ɵ�����ֱ��
		bool flag1 = false;
		// flag2��ջ��Ԫ�غ�����ǰ��
		bool flag2 = false;
		// flag3��ջ��Ԫ�ص����Ҷ˵�
		bool flag3 = false;

		flag1 = downHull[downHull_Size - 2] == -1 ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull.back()], sp.points[index]);

		if (flag1) {
			// ������2
			// һֱ��ջֱ��flag1Ϊtrue
			while (true) {
				downHull.pop_back();
				downHull_Size--;
				flag1 = downHull[downHull_Size - 2] == -1 ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull.back()], sp.points[index]);
				if (!flag1)	break;
			}
		}

		flag2 = downHull.back() == rightIndex ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[(downHull.back() - 1 + N) % N], sp.points[downHull.back()], sp.points[index]);

		//����1
		if (flag2)	continue;

		flag3 = toLeft(sp.points[downHull.back()], sp.points[leftIndex], sp.points[index]);

		if (flag3) {
			// ����3
			downHull.push_back(index);
			downHull_Size++;
		}
		else {
			// ����4
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