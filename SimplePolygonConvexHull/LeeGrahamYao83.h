#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class LeeGrahamYao83 : Algorithm
{
public:
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};