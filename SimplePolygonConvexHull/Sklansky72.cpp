#pragma once

#include "Sklansky72.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
void Sklansky72::getConvexHull(SimplePolygon & sp)
{
	int size = sp.points.size();
	Points & points = sp.points;
	vector<int> & result = sp.convexHull;
	// ��Ϊ�Ѿ������Ϸ��Լ��飬�㼯��СΪ3ʱ�ض�Ϊ͹��
	if (size == 3)
	{
		return;
	}
	else
	{
		int next = 0, rsize;
		while (next < size)
		{
			rsize = result.size();
			if (rsize <= 1 || toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[next]))
			{
				result.push_back(next);
				next++;
			}
			else
			{
				result.pop_back();
			}
		}
		rsize = result.size();
		while (rsize > 3 && !toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[0]))
		{
			result.pop_back();
			rsize = result.size();
		}
	}
}

void Sklansky72::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{
	int size = sp.points.size();
	Points & points = sp.points;
	vector<int> & result = sp.convexHull;
	// ��Ϊ�Ѿ������Ϸ��Լ��飬�㼯��СΪ3ʱ�ض�Ϊ͹��
	if (size == 3)
	{
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
				temp.pointColors.push_back(GREEN);
			}
			temp.points.push_back(points[next]);
			temp.pointColors.push_back(RED);
			displays.push_back(temp);

			if (rsize <= 1)
			{
				result.push_back(next);
				next++;

				// �����ʾ��������
				temp.pointColors[temp.pointColors.size() - 1] = GREEN;
				displays.push_back(temp);
			}
			else if (toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[next]))
			{
				// �����ʾ��������
				Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
				temp.lines.push_back(line);
				temp.lineColors.push_back(BLUE);
				temp.pointColors[temp.pointColors.size() - 3] = YELLOW;
				temp.pointColors[temp.pointColors.size() - 2] = YELLOW;
				displays.push_back(temp);

				result.push_back(next);
				next++;

				// �����ʾ��������
				temp.lineColors.pop_back();
				temp.lines.pop_back();
				temp.pointColors[temp.pointColors.size() - 3] = GREEN;
				temp.pointColors[temp.pointColors.size() - 2] = GREEN;
				temp.pointColors[temp.pointColors.size() - 1] = GREEN;
				displays.push_back(temp);
			}
			else
			{
				// �����ʾ��������
				Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
				temp.lines.push_back(line);
				temp.lineColors.push_back(BLUE);
				temp.pointColors[temp.pointColors.size() - 3] = YELLOW;
				temp.pointColors[temp.pointColors.size() - 2] = YELLOW;
				displays.push_back(temp);

				result.pop_back();

				// �����ʾ��������
				temp.lineColors.pop_back();
				temp.lines.pop_back();
				temp.pointColors[temp.pointColors.size() - 2] = GREY;
				displays.push_back(temp);
			}
		}

		rsize = result.size();

		while (rsize > 3 && !toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[0]))
		{
			// �����ʾ������ʾ����
			Display temp;
			for (int i = 1; i < rsize; i++)
			{
				temp.points.push_back(points[result[i]]);
				temp.pointColors.push_back(GREEN);
			}
			temp.points.push_back(points[0]);
			temp.pointColors.push_back(RED);
			displays.push_back(temp);

			// �����ʾ������ʾ����
			Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
			temp.lines.push_back(line);
			temp.lineColors.push_back(BLUE);
			temp.pointColors[temp.pointColors.size() - 3] = YELLOW;
			temp.pointColors[temp.pointColors.size() - 2] = YELLOW;
			displays.push_back(temp);

			result.pop_back();
			rsize = result.size();

			// �����ʾ������ʾ����
			temp.lineColors.pop_back();
			temp.lines.pop_back();
			temp.pointColors[temp.pointColors.size() - 2] = GREY;
			displays.push_back(temp);
		}

		// �����ʾ������ʾ����
		Display temp;
		for (int i = 1; i < rsize; i++)
		{
			temp.points.push_back(points[result[i]]);
			temp.pointColors.push_back(GREEN);
		}
		temp.points.push_back(points[0]);
		temp.pointColors.push_back(RED);
		displays.push_back(temp);

		// �����ʾ������ʾ����
		Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
		temp.lines.push_back(line);
		temp.lineColors.push_back(BLUE);
		temp.pointColors[temp.pointColors.size() - 3] = YELLOW;
		temp.pointColors[temp.pointColors.size() - 2] = YELLOW;
		displays.push_back(temp);

		// �����ʾ������ʾ����
		temp.lineColors.pop_back();
		temp.lines.pop_back();
		temp.pointColors[temp.pointColors.size() - 3] = GREEN;
		temp.pointColors[temp.pointColors.size() - 2] = GREEN;
		temp.pointColors[temp.pointColors.size() - 1] = GREEN;
		displays.push_back(temp);
	}
}