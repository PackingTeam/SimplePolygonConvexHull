#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class ShinWoo86 : Algorithm
{
private:
	// 禁止外部初始化
	ShinWoo86() {}

	Display createDisplay(SimplePolygon& sp, vector<int>& hull, Point& support, int leftIndex, int rightIndex, int curIndex);

public:
	// 禁止拷贝函数
	ShinWoo86(ShinWoo86 const&) = delete;
	// 禁止赋值拷贝
	ShinWoo86& operator=(ShinWoo86 const&) = delete;
	static ShinWoo86* Instance() {
		static ShinWoo86 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
