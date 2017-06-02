#include "GhoshShyamasundar83.h"

using namespace std;

const string GhoshShyamasundar83::counterExample = "(278.000000,15.000000);(198.000000,93.000000);(10.000000,118.000000);(92.000000,152.000000);(78.000000,126.000000);(129.000000,166.000000);(-46.000000,117.000000);(-102.000000,27.000000);(-18.000000,-27.000000);(30.000000,46.000000);(45.000000,-33.000000);(-113.000000,-25.000000);(-123.000000,97.000000);(-176.000000,75.000000);(-161.000000,-110.000000);(44.000000,-104.000000);(134.000000,-48.000000);(110.000000,37.000000);(185.000000,45.000000);(189.000000,-132.000000);(288.000000,-124.000000);";

namespace gs83 {

void backtrackUntilLeftTurn(SimplePolygon &sp, vector<int> &convexHull, const Point &p)
{
	while (convexHull.size() >= 2 &&
	       !toLeft(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], p))
		convexHull.pop_back();
}

Display showConvexHull(SimplePolygon &sp, const vector<int> &convexHull)
{
	Display display;
	for (auto i : convexHull) {
		display.points.push_back(sp.points[i]);
		display.pointColors.push_back(Qt::green);
	}
	return display;
}

Display showCheck(SimplePolygon &sp, const vector<int> &convexHull, const Point &p)
{
	auto display = showConvexHull(sp, convexHull);
	display.points.push_back(p);
	display.pointColors.push_back(Qt::red);
	if (convexHull.size() >= 2) {
		display.lines.emplace_back(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], LINE);
		display.lineColors.push_back(Qt::blue);
		Point nextInRay = sp.points[convexHull.back()];
		if (sp.points[convexHull[convexHull.size() - 2]].x < sp.points[convexHull.back()].x) ++nextInRay.y;
		else --nextInRay.y;
		display.lines.emplace_back(sp.points[convexHull.back()], nextInRay, RAY);
		display.lineColors.push_back(Qt::cyan);
	}
	return display;
}

Displays backtrackForDisplay(SimplePolygon &sp, vector<int> &convexHull, const Point &p)
{
	Displays displays;
	while (convexHull.size() >= 2 &&
	       !toLeft(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], p)) {
		displays.push_back(showCheck(sp, convexHull, p));
		convexHull.pop_back();
	}
	displays.push_back(showCheck(sp, convexHull, p));
	return displays;
}

// 从max到min构造一半的凸包
void getHalfConvexHull(SimplePolygon &sp, int max, int min)
{
	sp.convexHull.push_back(max);
	auto size = sp.points.size();
	int i = (max + 1) % size;

	if (i == min) return;
	sp.convexHull.push_back(i);

	for (i = (i + 1) % size; i != min; i = (i + 1) % size) {
		backtrackUntilLeftTurn(sp, sp.convexHull, sp.points[i]);

		if ((sp.points[min].x < sp.points[max].x) == (sp.points[i].x < sp.points[sp.convexHull.back()].x))
			sp.convexHull.push_back(i);
	}

	backtrackUntilLeftTurn(sp, sp.convexHull, sp.points[min]);
}

Displays getHalfConvexHullForDisplay(SimplePolygon &sp, int max, int min)
{
	Displays displays;
	vector<int> convexHull{max};
	displays.push_back(showConvexHull(sp, convexHull));

	auto size = sp.points.size();
	int i = (max + 1) % size;

	if (i == min) {
		sp.convexHull.insert(sp.convexHull.cend(), convexHull.cbegin(), convexHull.cend());
		return displays;
	}
	convexHull.push_back(i);
	displays.push_back(showConvexHull(sp, convexHull));

	for (i = (i + 1) % size; i != min; i = (i + 1) % size) {
		auto tmp = backtrackForDisplay(sp, convexHull, sp.points[i]);
		displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());

		if ((sp.points[min].x < sp.points[max].x) == (sp.points[i].x < sp.points[convexHull.back()].x))
			convexHull.push_back(i);

		displays.push_back(showConvexHull(sp, convexHull));
	}

	auto tmp = backtrackForDisplay(sp, convexHull, sp.points[min]);
	displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());

	displays.push_back(showConvexHull(sp, convexHull));

	sp.convexHull.insert(sp.convexHull.cend(), convexHull.cbegin(), convexHull.cend());

	return displays;
}

}

using namespace gs83;

void GhoshShyamasundar83::getConvexHull(SimplePolygon & sp)
{
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	getHalfConvexHull(sp, max, min);
	getHalfConvexHull(sp, min, max);
}

void GhoshShyamasundar83::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{
	sp.convexHull.clear();
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	displays = getHalfConvexHullForDisplay(sp, max, min);
	auto tmp = getHalfConvexHullForDisplay(sp, min, max);
	displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());
}
