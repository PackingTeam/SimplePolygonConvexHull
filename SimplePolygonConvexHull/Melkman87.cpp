#include "Melkman87.h"

Melkman87* Melkman87::instance = NULL;

void Melkman87::getConvexHull(SimplePolygon & sp)
{
	int N = (int)sp.points.size();

	deque<int> Q;

	if (toLeft(sp.points[0], sp.points[1], sp.points[2])) {
		Q.push_back(1);
		Q.push_back(0);
	}
	else {
		Q.push_back(0);
		Q.push_back(1);
	}

	Q.push_back(2);
	Q.push_front(2);

	int index = 3;
	int Q_Size = 4;

	while (index < N) {
		while ((index < N) && !toLeft(sp.points[index], sp.points[Q[0]], sp.points[Q[1]]) && !toLeft(sp.points[Q[Q_Size - 2]], sp.points[Q[Q_Size - 1]], sp.points[index])) {
			index++;
		}
		if (index >= N)	break;
		while (toLeft(sp.points[Q[Q_Size - 2]], sp.points[Q[Q_Size - 1]], sp.points[index])) {
			Q.pop_back();
			Q_Size--;
		}
		Q.push_back(index);
		Q_Size++;
		while (toLeft(sp.points[index], sp.points[Q[0]], sp.points[Q[1]])) {
			Q.pop_front();
			Q_Size--;
		}
		Q.push_front(index);
		Q_Size++;
		index++;
	}

	for (int i = 0; i + 1 < Q_Size; ++i) {
		sp.convexHull.push_back(Q[i]);
	}
}

Display Melkman87::createDisplay(SimplePolygon& sp, deque<int>& Q)
{
	Display ret;
	int Q_Size = (int)Q.size();
	for (int i = 0; i + 1 < Q_Size; ++i) {
		ret.points.push_back(sp.points[Q[i]]);
		ret.pointColors.push_back(Qt::green);	
	}

	{
		Line line(sp.points[Q[0]], sp.points[Q[1]], SEGMENT);
		ret.lines.push_back(line);
		ret.lineColors.push_back(Qt::blue);
	}
	for (int i = 1; i + 2 < Q_Size; ++i) {
		Line line(sp.points[Q[i]], sp.points[Q[i + 1]], SEGMENT);
		ret.lines.push_back(line);
		ret.lineColors.push_back(Qt::red);
	}
	{
		Line line(sp.points[Q[Q_Size - 2]], sp.points[Q[Q_Size - 1]], SEGMENT);
		ret.lines.push_back(line);
		ret.lineColors.push_back(Qt::yellow);
	}
	return ret;
}

void Melkman87::getConvexHullForDisplay(SimplePolygon & sp, Displays & displays)
{
	int N = (int)sp.points.size();

	deque<int> Q;

	if (toLeft(sp.points[0], sp.points[1], sp.points[2])) {
		Q.push_back(1);
		Q.push_back(0);
	}
	else {
		Q.push_back(0);
		Q.push_back(1);
	}

	Q.push_back(2);
	Q.push_front(2);
	displays.push_back(createDisplay(sp, Q));

	int index = 3;
	int Q_Size = 4;

	while (index < N) {
		while ((index < N) && !toLeft(sp.points[index], sp.points[Q[0]], sp.points[Q[1]]) && !toLeft(sp.points[Q[Q_Size - 2]], sp.points[Q[Q_Size - 1]], sp.points[index])) {
			index++;
		}
		if (index >= N)	break;
		while (toLeft(sp.points[Q[Q_Size - 2]], sp.points[Q[Q_Size - 1]], sp.points[index])) {
			Q.pop_back();
			Q_Size--;
		}
		Q.push_back(index);
		Q_Size++;
		while (toLeft(sp.points[index], sp.points[Q[0]], sp.points[Q[1]])) {
			Q.pop_front();
			Q_Size--;
		}
		Q.push_front(index);
		Q_Size++;
		index++;
		displays.push_back(createDisplay(sp, Q));
	}

	for (int i = 0; i + 1 < Q_Size; ++i) {
		sp.convexHull.push_back(Q[i]);
	}
}