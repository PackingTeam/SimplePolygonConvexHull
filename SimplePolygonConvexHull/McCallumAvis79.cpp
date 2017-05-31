#include "DataStruc.h"
#include "McCallumAvis79.h"
#include <algorithm>
#include <utility>
#include <vector>

McCallumAvis79* McCallumAvis79::instance = NULL;

using namespace std;

namespace ma79 {

void backtrackUntilLeftTurn(SimplePolygon &sp, vector<int> &convexHull, const Point &p)
{
	while (convexHull.size() >= 2 &&
	       !toLeft(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], p))
		convexHull.pop_back();
}

void backtrackUntilRightTurn(SimplePolygon &sp, vector<int> &convexHull, const Point &p)
{
	while (convexHull.size() >= 2 &&
	       toLeft(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], p))
		convexHull.pop_back();
}

Display showConvexHull(SimplePolygon &sp, const vector<int> &convexHull, const vector<int> &rejectedConvexHull)
{
	Display display;
	for (auto i : convexHull) {
		display.points.push_back(sp.points[i]);
		display.pointColors.push_back(Qt::green);
	}
	for (auto i : rejectedConvexHull) {
		display.points.push_back(sp.points[i]);
		display.pointColors.push_back(Qt::gray);
	}
	return display;
}

Display showBacktrackConvexHull(SimplePolygon &sp, const vector<int> &convexHull, const vector<int> &rejectedConvexHull, const Point &p)
{
	auto display = showConvexHull(sp, convexHull, rejectedConvexHull);
	display.points.push_back(p);
	display.pointColors.push_back(Qt::red);
	if (convexHull.size() >= 2) {
		display.lines.emplace_back(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], LINE);
		display.lineColors.push_back(Qt::blue);
	}
	return display;
}

Display showBacktrackRejectedConvexHull(SimplePolygon &sp, const vector<int> &convexHull, const vector<int> &rejectedConvexHull, const Point &p)
{
	auto display = showConvexHull(sp, convexHull, rejectedConvexHull);
	display.points.push_back(p);
	display.pointColors.push_back(Qt::red);
	if (rejectedConvexHull.size() >= 2) {
		display.lines.emplace_back(sp.points[rejectedConvexHull[rejectedConvexHull.size() - 2]], sp.points[rejectedConvexHull.back()], LINE);
		display.lineColors.push_back(Qt::magenta);
	}
	return display;
}

Display showCheck(SimplePolygon &sp, const vector<int> &convexHull, const vector<int> &rejectedConvexHull, const Point &p)
{
	auto display = showBacktrackConvexHull(sp, convexHull, rejectedConvexHull, p);
	display.lines.emplace_back(sp.points[convexHull.back()], sp.points[rejectedConvexHull.back()], LINE);
	display.lineColors.push_back(Qt::cyan);
	return display;
}

Displays backtrackConvexHullForDisplay(SimplePolygon &sp, vector<int> &convexHull, const vector<int> &rejectedConvexHull, const Point &p)
{
	Displays displays;
	while (convexHull.size() >= 2 &&
	       !toLeft(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], p)) {
		displays.push_back(showBacktrackConvexHull(sp, convexHull, rejectedConvexHull, p));
		convexHull.pop_back();
	}
	displays.push_back(showBacktrackConvexHull(sp, convexHull, rejectedConvexHull, p));
	return displays;
}

Displays backtrackRejectedConvexHullForDisplay(SimplePolygon &sp, const vector<int> &convexHull, vector<int> &rejectedConvexHull, const Point &p)
{
	Displays displays;
	while (rejectedConvexHull.size() >= 2 &&
	       toLeft(sp.points[rejectedConvexHull[rejectedConvexHull.size() - 2]], sp.points[rejectedConvexHull.back()], p)) {
		displays.push_back(showBacktrackRejectedConvexHull(sp, convexHull, rejectedConvexHull, p));
		rejectedConvexHull.pop_back();
	}
	displays.push_back(showBacktrackRejectedConvexHull(sp, convexHull, rejectedConvexHull, p));
	return displays;
}

// 从max到min构造一半的凸包
void getHalfConvexHull(SimplePolygon &sp, int max, int min)
{
	vector<int> convexHull{max};
	auto size = sp.points.size();
	int i = (max + 1) % size;

	for (; i != min && toLeft(sp.points[max], sp.points[min], sp.points[i]); i = (i + 1) % size);
	if (i == min) return;
	convexHull.push_back(i);

	vector<int> rejectedConvexHull{min};
	for (i = (i + 1) % size; i != min; i = (i + 1) % size) {
		auto toLeft0 = toLeft(sp.points[convexHull[convexHull.size() - 2]],
		                      sp.points[convexHull.back()],
		                      sp.points[i]),
		     toLeft1 = toLeft(sp.points[convexHull.back()],
		                      sp.points[rejectedConvexHull.back()],
		                      sp.points[i]);

		if (!toLeft1) {
			backtrackUntilRightTurn(sp, rejectedConvexHull, sp.points[i]);
			if (!toLeft0) backtrackUntilLeftTurn(sp, convexHull, sp.points[i]);
			convexHull.push_back(i);
		}

		else if (!toLeft0) {
			rejectedConvexHull.push_back(convexHull.back());
			convexHull.pop_back();
			backtrackUntilLeftTurn(sp, convexHull, sp.points[i]);
		}
	}

	sp.convexHull.insert(sp.convexHull.cend(), convexHull.cbegin(), convexHull.cend());
}

// 从max到min构造一半的凸包
Displays getHalfConvexHullForDisplay(SimplePolygon &sp, int max, int min)
{
	Displays displays;
	vector<int> convexHull{max}, rejectedConvexHull{min};
	displays.push_back(showConvexHull(sp, convexHull, rejectedConvexHull));

	auto size = sp.points.size();
	int i = (max + 1) % size;

	for (; i != min; i = (i + 1) % size) {
		displays.push_back(showCheck(sp, convexHull, rejectedConvexHull, sp.points[i]));
		if (!toLeft(sp.points[max], sp.points[min], sp.points[i])) break;
		displays.push_back(showConvexHull(sp, convexHull, rejectedConvexHull));
	}
	if (i == min) return displays;
	convexHull.push_back(i);
	displays.push_back(showConvexHull(sp, convexHull, rejectedConvexHull));

	for (i = (i + 1) % size; i != min; i = (i + 1) % size) {
		displays.push_back(showCheck(sp, convexHull, rejectedConvexHull, sp.points[i]));

		auto toLeft0 = toLeft(sp.points[convexHull[convexHull.size() - 2]],
		                      sp.points[convexHull.back()],
		                      sp.points[i]),
		     toLeft1 = toLeft(sp.points[convexHull.back()],
		                      sp.points[rejectedConvexHull.back()],
		                      sp.points[i]);

		if (!toLeft1) {
			auto tmp = backtrackRejectedConvexHullForDisplay(sp, convexHull, rejectedConvexHull, sp.points[i]);
			displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());
			if (!toLeft0) {
				auto tmp = backtrackConvexHullForDisplay(sp, convexHull, rejectedConvexHull, sp.points[i]);
				displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());
			}
			convexHull.push_back(i);
		}

		else if (!toLeft0) {
			rejectedConvexHull.push_back(convexHull.back());
			convexHull.pop_back();
			auto tmp = backtrackConvexHullForDisplay(sp, convexHull, rejectedConvexHull, sp.points[i]);
			displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());
		}

		displays.push_back(showConvexHull(sp, convexHull, rejectedConvexHull));
	}

	sp.convexHull.insert(sp.convexHull.cend(), convexHull.cbegin(), convexHull.cend());

	return displays;
}

}

using namespace ma79;

void McCallumAvis79::getConvexHull(SimplePolygon & sp)
{
	sp.convexHull.clear();
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	getHalfConvexHull(sp, max, min);
	getHalfConvexHull(sp, min, max);
}

void McCallumAvis79::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{
	sp.convexHull.clear();
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	displays = getHalfConvexHullForDisplay(sp, max, min);
	auto tmp = getHalfConvexHullForDisplay(sp, min, max);
	displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());
}
