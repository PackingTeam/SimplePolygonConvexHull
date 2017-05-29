#pragma once

#include "DataStruc.h"

class Algorithm {
public:
	// 用于大量数据运算的算法，不包含演示功能
	virtual void getConvexHull(SimplePolygon & sp) = 0;
	// 用于少量数据运算的算法，包含演示功能
	virtual void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays) = 0;
	virtual ~Algorithm() {}
};
