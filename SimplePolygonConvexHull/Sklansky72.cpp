#include "Sklansky72.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
void Sklansky72::getConvexHull(SimplePolygon & sp)
{
	int size = sp.points.size();
	int start = sp.getLeftMostThenLowestPoint();
	Points & points = sp.points;
	vector<int> & result = sp.convexHull;
	result.clear();
	// ��Ϊ�Ѿ������Ϸ��Լ��飬�㼯��СΪ3ʱ�ض�Ϊ͹��
	if (size == 3)
	{
		sp.convexHull.push_back(0);
		sp.convexHull.push_back(1);
		sp.convexHull.push_back(2);

		return;
	}
	else
	{
		int next = 0, rsize;
		while (next < size)
		{
			rsize = result.size();
			if (rsize <= 1 || toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[(start + next) % size]))
			{
				result.push_back((next + start) % size);
				next++;
			}
			else
			{
				result.pop_back();
			}
		}
		rsize = result.size();
		while (rsize > 3 && !toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[start]))
		{
			result.pop_back();
			rsize = result.size();
		}
	}
}

void Sklansky72::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{
	int size = sp.points.size();
	int start = sp.getLeftMostThenLowestPoint();
	Points & points = sp.points;
	vector<int> & result = sp.convexHull;
	result.clear();
	displays.clear();
	// ��Ϊ�Ѿ������Ϸ��Լ��飬�㼯��СΪ3ʱ�ض�Ϊ͹��
	if (size == 3)
	{
		sp.convexHull.push_back(0);
		sp.convexHull.push_back(1);
		sp.convexHull.push_back(2);
		return;
	}
	else
	{
		int next = 0, rsize;
		while (next < size)
		{
			rsize = result.size();

			// �����ʾ������ʾ����
			Display temp;
			for (int i = 0; i < rsize; i++)
			{
				temp.points.push_back(points[result[i]]);
				temp.pointColors.push_back(Qt::green);
			}
			temp.points.push_back(points[(next + start) % size]);
			temp.pointColors.push_back(Qt::red);
			displays.push_back(temp);

			if (rsize <= 1)
			{
				result.push_back((next + start) % size);
				next++;

				// �����ʾ��������
				temp.pointColors[temp.pointColors.size() - 1] = Qt::green;
				displays.push_back(temp);
			}
			else if (toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[(start + next) % size]))
			{
				// �����ʾ��������
				Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
				temp.lines.push_back(line);
				temp.lineColors.push_back(Qt::blue);
				temp.pointColors[temp.pointColors.size() - 3] = Qt::yellow;
				temp.pointColors[temp.pointColors.size() - 2] = Qt::yellow;
				displays.push_back(temp);

				result.push_back((next + start) % size);
				next++;

				// �����ʾ��������
				temp.lineColors.pop_back();
				temp.lines.pop_back();
				temp.pointColors[temp.pointColors.size() - 3] = Qt::green;
				temp.pointColors[temp.pointColors.size() - 2] = Qt::green;
				temp.pointColors[temp.pointColors.size() - 1] = Qt::green;
				displays.push_back(temp);
			}
			else
			{
				// �����ʾ��������
				Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
				temp.lines.push_back(line);
				temp.lineColors.push_back(Qt::blue);
				temp.pointColors[temp.pointColors.size() - 3] = Qt::yellow;
				temp.pointColors[temp.pointColors.size() - 2] = Qt::yellow;
				displays.push_back(temp);

				result.pop_back();

				// �����ʾ��������
				temp.lineColors.pop_back();
				temp.lines.pop_back();
				temp.pointColors[temp.pointColors.size() - 2] = Qt::gray;
				displays.push_back(temp);
			}
		}

		rsize = result.size();

		while (rsize > 3 && !toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[start]))
		{
			// �����ʾ������ʾ����
			Display temp;
			for (int i = 1; i < rsize; i++)
			{
				temp.points.push_back(points[result[i]]);
				temp.pointColors.push_back(Qt::green);
			}
			temp.points.push_back(points[start]);
			temp.pointColors.push_back(Qt::red);
			displays.push_back(temp);

			// �����ʾ������ʾ����
			Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
			temp.lines.push_back(line);
			temp.lineColors.push_back(Qt::blue);
			temp.pointColors[temp.pointColors.size() - 3] = Qt::yellow;
			temp.pointColors[temp.pointColors.size() - 2] = Qt::yellow;
			displays.push_back(temp);

			result.pop_back();
			rsize = result.size();

			// �����ʾ������ʾ����
			temp.lineColors.pop_back();
			temp.lines.pop_back();
			temp.pointColors[temp.pointColors.size() - 2] = Qt::gray;
			displays.push_back(temp);
		}

		// �����ʾ������ʾ����
		Display temp;
		for (int i = 1; i < rsize; i++)
		{
			temp.points.push_back(points[result[i]]);
			temp.pointColors.push_back(Qt::green);
		}
		temp.points.push_back(points[start]);
		temp.pointColors.push_back(Qt::red);
		displays.push_back(temp);

		// �����ʾ������ʾ����
		Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
		temp.lines.push_back(line);
		temp.lineColors.push_back(Qt::blue);
		temp.pointColors[temp.pointColors.size() - 3] = Qt::yellow;
		temp.pointColors[temp.pointColors.size() - 2] = Qt::yellow;
		displays.push_back(temp);

		// �����ʾ������ʾ����
		temp.lineColors.pop_back();
		temp.lines.pop_back();
		temp.pointColors[temp.pointColors.size() - 3] = Qt::green;
		temp.pointColors[temp.pointColors.size() - 2] = Qt::green;
		temp.pointColors[temp.pointColors.size() - 1] = Qt::green;
		displays.push_back(temp);
	}
}
