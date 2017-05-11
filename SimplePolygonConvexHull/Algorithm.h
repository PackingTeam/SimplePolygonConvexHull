#pragma once

#include "DataStruc.h"
#include "Commands.h"

class Algorithm {
public:
	virtual void getConvexHull(SimplePolygon & sp, Commands & result)=0;
};