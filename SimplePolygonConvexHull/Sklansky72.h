#pragma once

#include "Algorithm.h"

class Sklansky72 : Algorithm {
public:
	void getConvexHull(SimplePolygon & sp, Commands & result);
};