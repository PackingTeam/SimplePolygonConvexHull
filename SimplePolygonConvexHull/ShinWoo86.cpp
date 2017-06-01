#include "ShinWoo86.h"

ShinWoo86* ShinWoo86::instance = NULL;

void ShinWoo86::getConvexHull(SimplePolygon & sp)
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

		flag1 = upHull[upHull_Size - 2] == -1 ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[upHull[upHull_Size - 2]], sp.points[upHull.back()], sp.points[index]);

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

		upHull.push_back(index);
		upHull_Size++;
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

		downHull.push_back(index);
		downHull_Size++;
	}

	for (int i = 1; i < upHull_Size; ++i) {
		sp.convexHull.push_back(upHull[i]);
	}

	for (int i = 1; i < downHull_Size; ++i) {
		sp.convexHull.push_back(downHull[i]);
	}
}

Display ShinWoo86::createDisplay(SimplePolygon& sp, vector<int>& hull, Point& support, int leftIndex, int rightIndex, int curIndex) 
{
	Display ret;
	ret.points.push_back(support);
	ret.pointColors.push_back(Qt::gray);

	int N = (int)sp.points.size();

	int hull_Size = (int)hull.size();

	for (int i = 1; i < hull_Size; ++i) {
		ret.points.push_back(sp.points[hull[i]]);
		ret.pointColors.push_back(Qt::green);
	}

	{
		if (hull_Size == 2) {
			Line line(support, sp.points[hull.back()], LINE);
			ret.lines.push_back(line);
		}
		else {
			Line line(sp.points[hull[hull_Size - 2]], sp.points[hull.back()], LINE);
			ret.lines.push_back(line);
		}
		ret.lineColors.push_back(Qt::yellow);
	}

	{
		if (hull.back() == leftIndex) {
			Line line(support, sp.points[hull.back()], LINE);
			ret.lines.push_back(line);
		}
		else {
			Line line(sp.points[(hull.back() - 1 + N) % N], sp.points[hull.back()], LINE);
			ret.lines.push_back(line);
		}
		ret.lineColors.push_back(Qt::blue);
	}

	{
		Line line(sp.points[hull.back()], sp.points[rightIndex], LINE);
		ret.lines.push_back(line);
		ret.lineColors.push_back(Qt::red);
	}

	ret.points.push_back(sp.points[curIndex]);
	ret.pointColors.push_back(Qt::red);

	return ret;
}

void ShinWoo86::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
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
	Point supportLeft(sp.points[leftIndex].x, sp.points[leftIndex].y - 20);
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

		displays.push_back(createDisplay(sp, upHull, supportLeft, leftIndex, rightIndex, index));

		flag1 = upHull[upHull_Size - 2] == -1 ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[upHull[upHull_Size - 2]], sp.points[upHull.back()], sp.points[index]);

		if (flag1) {
			// ������2
			// һֱ��ջֱ��flag1Ϊtrue
			while (true) {
				upHull.pop_back();
				upHull_Size--;
				displays.push_back(createDisplay(sp, upHull, supportLeft, leftIndex, rightIndex, index));
				flag1 = upHull[upHull_Size - 2] == -1 ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[upHull[upHull_Size - 2]], sp.points[upHull.back()], sp.points[index]);
				if (!flag1)	break;
			}
		}

		flag2 = upHull.back() == leftIndex ? toLeft(supportLeft, sp.points[upHull.back()], sp.points[index]) : toLeft(sp.points[(upHull.back() - 1 + N) % N], sp.points[upHull.back()], sp.points[index]);

		//����1
		if (flag2)	continue;

		upHull.push_back(index);
		upHull_Size++;
	}

	vector<int> downHull;
	// ��Ӹ����� x�������x_max ��rightIndex���Ϸ�
	downHull.push_back(-1);
	Point supportRight(sp.points[rightIndex].x, sp.points[rightIndex].y + 20);
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

		displays.push_back(createDisplay(sp, downHull, supportRight, rightIndex, leftIndex, index));

		flag1 = downHull[downHull_Size - 2] == -1 ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull.back()], sp.points[index]);

		if (flag1) {
			// ������2
			// һֱ��ջֱ��flag1Ϊtrue
			while (true) {
				downHull.pop_back();
				downHull_Size--;
				displays.push_back(createDisplay(sp, downHull, supportRight, rightIndex, leftIndex, index));
				flag1 = downHull[downHull_Size - 2] == -1 ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[downHull[downHull_Size - 2]], sp.points[downHull.back()], sp.points[index]);
				if (!flag1)	break;
			}
		}

		flag2 = downHull.back() == rightIndex ? toLeft(supportRight, sp.points[downHull.back()], sp.points[index]) : toLeft(sp.points[(downHull.back() - 1 + N) % N], sp.points[downHull.back()], sp.points[index]);

		//����1
		if (flag2)	continue;

		downHull.push_back(index);
		downHull_Size++;
	}

	for (int i = 1; i < upHull_Size; ++i) {
		sp.convexHull.push_back(upHull[i]);
	}

	for (int i = 1; i < downHull_Size; ++i) {
		sp.convexHull.push_back(downHull[i]);
	}
}
