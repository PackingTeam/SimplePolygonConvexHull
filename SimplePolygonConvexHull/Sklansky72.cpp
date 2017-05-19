#pragma once

#include "Sklansky72.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
void Sklansky72::getConvexHull(SimplePolygon & sp)
{
	int size = sp.points.size();
	Points & points = sp.points;
	vector<int> & result = sp.convexHull;
	// 因为已经经过合法性检验，点集大小为3时必定为凸包
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
	// 因为已经经过合法性检验，点集大小为3时必定为凸包
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

			// 添加演示所需显示内容
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

				// 添加演示所需内容
				temp.pointColors[temp.pointColors.size() - 1] = GREEN;
				displays.push_back(temp);
			}
			else if (toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[next]))
			{
				// 添加演示所需内容
				Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
				temp.lines.push_back(line);
				temp.lineColors.push_back(BLUE);
				temp.pointColors[temp.pointColors.size() - 3] = YELLOW;
				temp.pointColors[temp.pointColors.size() - 2] = YELLOW;
				displays.push_back(temp);

				result.push_back(next);
				next++;

				// 添加演示所需内容
				temp.lineColors.pop_back();
				temp.lines.pop_back();
				temp.pointColors[temp.pointColors.size() - 3] = GREEN;
				temp.pointColors[temp.pointColors.size() - 2] = GREEN;
				temp.pointColors[temp.pointColors.size() - 1] = GREEN;
				displays.push_back(temp);
			}
			else
			{
				// 添加演示所需内容
				Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
				temp.lines.push_back(line);
				temp.lineColors.push_back(BLUE);
				temp.pointColors[temp.pointColors.size() - 3] = YELLOW;
				temp.pointColors[temp.pointColors.size() - 2] = YELLOW;
				displays.push_back(temp);

				result.pop_back();

				// 添加演示所需内容
				temp.lineColors.pop_back();
				temp.lines.pop_back();
				temp.pointColors[temp.pointColors.size() - 2] = GREY;
				displays.push_back(temp);
			}
		}

		rsize = result.size();

		while (rsize > 3 && !toLeft(points[result[rsize - 2]], points[result[rsize - 1]], points[0]))
		{
			// 添加演示所需显示内容
			Display temp;
			for (int i = 1; i < rsize; i++)
			{
				temp.points.push_back(points[result[i]]);
				temp.pointColors.push_back(GREEN);
			}
			temp.points.push_back(points[0]);
			temp.pointColors.push_back(RED);
			displays.push_back(temp);

			// 添加演示所需显示内容
			Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
			temp.lines.push_back(line);
			temp.lineColors.push_back(BLUE);
			temp.pointColors[temp.pointColors.size() - 3] = YELLOW;
			temp.pointColors[temp.pointColors.size() - 2] = YELLOW;
			displays.push_back(temp);

			result.pop_back();
			rsize = result.size();

			// 添加演示所需显示内容
			temp.lineColors.pop_back();
			temp.lines.pop_back();
			temp.pointColors[temp.pointColors.size() - 2] = GREY;
			displays.push_back(temp);
		}

		// 添加演示所需显示内容
		Display temp;
		for (int i = 1; i < rsize; i++)
		{
			temp.points.push_back(points[result[i]]);
			temp.pointColors.push_back(GREEN);
		}
		temp.points.push_back(points[0]);
		temp.pointColors.push_back(RED);
		displays.push_back(temp);

		// 添加演示所需显示内容
		Line line(points[result[rsize - 2]], points[result[rsize - 1]], LINE);
		temp.lines.push_back(line);
		temp.lineColors.push_back(BLUE);
		temp.pointColors[temp.pointColors.size() - 3] = YELLOW;
		temp.pointColors[temp.pointColors.size() - 2] = YELLOW;
		displays.push_back(temp);

		// 添加演示所需显示内容
		temp.lineColors.pop_back();
		temp.lines.pop_back();
		temp.pointColors[temp.pointColors.size() - 3] = GREEN;
		temp.pointColors[temp.pointColors.size() - 2] = GREEN;
		temp.pointColors[temp.pointColors.size() - 1] = GREEN;
		displays.push_back(temp);
	}
}