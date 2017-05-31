#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class ShinWoo86 : Algorithm
{
private:
	// 禁止外部初始化
	ShinWoo86() {}
	// 禁止拷贝函数
	ShinWoo86(ShinWoo86 const&) {}
	// 禁止赋值拷贝
	ShinWoo86& operator=(ShinWoo86 const&) {}
	// 禁止析构函数
	~ShinWoo86() {}
	static ShinWoo86* instance;
	Display createDisplay(SimplePolygon& sp, vector<int>& hull, Point& support, int leftIndex, int rightIndex, int curIndex);

public:
	static ShinWoo86* Instance() {
		if (!instance)
			instance = new ShinWoo86();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};