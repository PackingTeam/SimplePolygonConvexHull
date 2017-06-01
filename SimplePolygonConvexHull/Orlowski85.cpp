#include "Orlowski85.h"

void Orlowski85::getConvexHull(SimplePolygon & sp)
{
	int size = sp.points.size();
	int start = sp.getLeftMostThenLowestPoint();

	Points & points = sp.points;
	vector<int> & result = sp.convexHull;

	// dull point: point0
	Point point0(points[start].x, points[start].y + 2 * tolerance);

	// 防止多次运行方法添加重复的dull point
	if (abs(points[(start - 1 + size) % size].y - point0.y) > tolerance)
	{
		points.insert(points.begin() + start, point0);
		size++;
	}
	else
		start--;

	for (int i = 0; i < 4; i++)
		result.push_back((start + i) % size);

	while (result.back() != result[1])
	{
		while (!toLeft(points[result[result.size() - 3]], points[result[result.size() - 2]], points[result[result.size() - 1]]))
			result.erase(result.begin() + result.size() - 2);
		if (toLeft(points[(result[result.size() - 2] - 1 + size) % size], points[result[result.size() - 2]], points[result[result.size() - 1]]))
			result.push_back((result.back() + 1) % size);
		else
		{
			result.push_back((result.back() + 1) % size);
			result.erase(result.begin() + result.size() - 2);
			while (toLeft(points[result[result.size() - 3]], points[result[result.size() - 2]], points[result[result.size() - 1]]))
			{
				result.push_back((result.back() + 1) % size);
				result.erase(result.begin() + result.size() - 2);
			}
			result.erase(result.begin() + result.size() - 2);
		}
	}
	for (int i = 0; i < 2; i++)
		result.pop_back();
}


void Orlowski85::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{
	int size = sp.points.size();
	int start = sp.getLeftMostThenLowestPoint();

	Points & points = sp.points;
	vector<int> & result = sp.convexHull;

	// dull point: point0
	Point point0(points[start].x, points[start].y + 2 * tolerance);

	// 防止多次运行方法添加重复的dull point
	if (abs(points[(start - 1 + size) % size].y - point0.y) > tolerance)
	{
		points.insert(points.begin() + start, point0);
		size++;
	}
	else
		start--;

	for (int i = 0; i < 4; i++)
		result.push_back((start + i) % size);

	Display temp;

	while (result.back() != result[1])
	{
		// 添加演示所需显示内容
		displayIJK(temp, points, result);
		displays.push_back(temp);

		while (!toLeft(points[result[result.size() - 3]], points[result[result.size() - 2]], points[result[result.size() - 1]]))
		{
			result.erase(result.begin() + result.size() - 2);

			// 添加演示所需显示内容
			displayIJK(temp, points, result);
			displays.push_back(temp);
		}

		// 添加演示所需显示内容
		displayJ_1JK(temp, points, result);
		displays.push_back(temp);

		if (toLeft(points[(result[result.size() - 2] - 1 + size) % size], points[result[result.size() - 2]], points[result[result.size() - 1]]))
			result.push_back((result.back() + 1) % size);
		else
		{
			result.push_back((result.back() + 1) % size);
			result.erase(result.begin() + result.size() - 2);

			// 添加演示所需显示内容
			displayIJK(temp, points, result);
			displays.push_back(temp);

			while (toLeft(points[result[result.size() - 3]], points[result[result.size() - 2]], points[result[result.size() - 1]]))
			{
				result.push_back((result[result.size() - 1] + 1) % size);
				result.erase(result.begin() + result.size() - 2);

				// 添加演示所需显示内容
				displayIJK(temp, points, result);
				displays.push_back(temp);
			}
			result.erase(result.begin() + result.size() - 2);
		}
	}
	for (int i = 0; i < 2; i++)
		result.pop_back();
}

void Orlowski85::displayIJK(Display &temp, Points &points, vector<int> &result)
{
	temp.clearAll();
	int size = result.size();
	for (int i = 0; i < size - 3; i++)
	{
		temp.points.push_back(points[result[i]]);
		temp.pointColors.push_back(Qt::green);
	}
	temp.points.push_back(points[result[result.size() - 1]]);
	temp.pointColors.push_back(Qt::red);
	temp.points.push_back(points[result[result.size() - 2]]);
	temp.pointColors.push_back(Qt::yellow);
	temp.points.push_back(points[result[result.size() - 3]]);
	temp.pointColors.push_back(Qt::darkBlue);

	Line line5(points[result[result.size() - 3]], points[result[result.size() - 2]], LINE);
	temp.lines.push_back(line5);
	temp.lineColors.push_back(Qt::blue);
}

void Orlowski85::displayJ_1JK(Display &temp, Points &points, vector<int> &result)
{
	temp.clearAll();
	int size = result.size();
	for (int i = 0; i < size - 3; i++)
	{
		temp.points.push_back(points[result[i]]);
		temp.pointColors.push_back(Qt::green);
	}
	temp.points.push_back(points[result[result.size() - 1]]);
	temp.pointColors.push_back(Qt::red);
	temp.points.push_back(points[result[result.size() - 2]]);
	temp.pointColors.push_back(Qt::yellow);
	temp.points.push_back(points[(result[result.size() - 2] - 1 + points.size()) % points.size()]);
	temp.pointColors.push_back(Qt::darkBlue);

	Line line3(points[(result[result.size() - 2] - 1 + points.size()) % points.size()], points[result[result.size() - 2]], LINE);
	temp.lines.push_back(line3);
	temp.lineColors.push_back(Qt::blue);
}
