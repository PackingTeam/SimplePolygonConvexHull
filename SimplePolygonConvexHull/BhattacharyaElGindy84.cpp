#include "BhattacharyaElGindy84.h"

using namespace std;

namespace be84 {

void backtrackUntilLeftTurn(SimplePolygon &sp, vector<int> &convexHull, const Point &p)
{
	while (convexHull.size() >= 2 &&
	       !toLeft(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], p))
		convexHull.pop_back();
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
		auto top = sp.convexHull.back();
		auto toConvexHullLeft = toLeft(sp.points[sp.convexHull[sp.convexHull.size() - 2]], sp.points[top], sp.points[i]);
		if (toConvexHullLeft && !toLeft(sp.points[top == 0 ? size - 1 : top - 1], sp.points[top], sp.points[i])) {
			for (; !intersect(sp.points[i],
			                  sp.points[(i + 1) % size],
			                  sp.points[sp.convexHull[sp.convexHull.size() - 2]],
			                  sp.points[top]); i = (i + 1) % size);
		}

		else if (toConvexHullLeft && (sp.points[min].x < sp.points[max].x) != (sp.points[i].x < sp.points[top].x)) {
			for (; (sp.points[min].x < sp.points[max].x) !=
			       (sp.points[(i + 1) % size].x < sp.points[top].x); i = (i + 1) % size);
		}

		else {
			backtrackUntilLeftTurn(sp, sp.convexHull, sp.points[i]);
			sp.convexHull.push_back(i);
		}
	}

	backtrackUntilLeftTurn(sp, sp.convexHull, sp.points[min]);
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

Display showBacktrack(SimplePolygon &sp, const vector<int> &convexHull, const Point &p)
{
	auto display = showConvexHull(sp, convexHull);
	display.points.push_back(p);
	display.pointColors.push_back(Qt::red);
	if (convexHull.size() >= 2) {
		display.lines.emplace_back(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], LINE);
		display.lineColors.push_back(Qt::blue);
	}
	return display;
}

Display showCheck(SimplePolygon &sp, const vector<int> &convexHull, const Point &p)
{
	auto display = showBacktrack(sp, convexHull, p);
	if (convexHull.size() >= 2) {
		Point nextInRay = sp.points[convexHull.back()];
		if (sp.points[convexHull[convexHull.size() - 2]].x < sp.points[convexHull.back()].x) ++nextInRay.y;
		else --nextInRay.y;
		display.lines.emplace_back(sp.points[convexHull.back()], nextInRay, RAY);
		display.lineColors.push_back(Qt::cyan);
		for (auto i = convexHull[convexHull.size() - 2]; i != convexHull.back(); i = (i + 1) % sp.points.size()) {
			display.lines.emplace_back(sp.points[i], sp.points[(i + 1) % sp.points.size()], SEGMENT);
			display.lineColors.push_back(Qt::magenta);
		}
	}
	return display;
}

Displays backtrackForDisplay(SimplePolygon &sp, vector<int> &convexHull, const Point &p)
{
	Displays displays;
	while (convexHull.size() >= 2 &&
	       !toLeft(sp.points[convexHull[convexHull.size() - 2]], sp.points[convexHull.back()], p)) {
		displays.push_back(showBacktrack(sp, convexHull, p));
		convexHull.pop_back();
	}
	displays.push_back(showBacktrack(sp, convexHull, p));
	return displays;
}

// 从max到min构造一半的凸包
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
		displays.push_back(showCheck(sp, convexHull, sp.points[i]));

		auto top = convexHull.back();
		auto toConvexHullLeft = toLeft(sp.points[convexHull[convexHull.size() - 2]], sp.points[top], sp.points[i]);

		if (toConvexHullLeft && !toLeft(sp.points[top == 0 ? size - 1 : top - 1], sp.points[top], sp.points[i])) {
			for (; !intersect(sp.points[i],
			                  sp.points[(i + 1) % size],
			                  sp.points[convexHull[convexHull.size() - 2]],
			                  sp.points[top]); i = (i + 1) % size)
				displays.push_back(showCheck(sp, convexHull, sp.points[(i + 1) % size]));
		}

		else if (toConvexHullLeft && (sp.points[min].x < sp.points[max].x) != (sp.points[i].x < sp.points[top].x)) {
			for (; (sp.points[min].x < sp.points[max].x) !=
			       (sp.points[(i + 1) % size].x < sp.points[top].x); i = (i + 1) % size)
				displays.push_back(showCheck(sp, convexHull, sp.points[(i + 1) % size]));
		}

		else {
			auto tmp = backtrackForDisplay(sp, convexHull, sp.points[i]);
			displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());

			convexHull.push_back(i);

			displays.push_back(showConvexHull(sp, convexHull));
		}
	}

	auto tmp = backtrackForDisplay(sp, convexHull, sp.points[min]);
	displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());

	displays.push_back(showConvexHull(sp, convexHull));

	sp.convexHull.insert(sp.convexHull.cend(), convexHull.cbegin(), convexHull.cend());

	return displays;
}

}

using namespace be84;

void BhattacharyaElGindy84::getConvexHull(SimplePolygon & sp)
{
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	getHalfConvexHull(sp, max, min);
	getHalfConvexHull(sp, min, max);
}

void BhattacharyaElGindy84::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{
	sp.convexHull.clear();
	auto min = sp.getLeftMostThenLowestPoint(), max = sp.getRightMostThenHighestPoint();
	displays = getHalfConvexHullForDisplay(sp, max, min);
	auto tmp = getHalfConvexHullForDisplay(sp, min, max);
	displays.insert(displays.cend(), tmp.cbegin(), tmp.cend());
}
