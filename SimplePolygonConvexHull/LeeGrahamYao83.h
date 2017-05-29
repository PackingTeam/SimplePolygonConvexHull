#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class LeeGrahamYao83 : Algorithm
{
private:
	// 禁止外部初始化
	LeeGrahamYao83() {}
	// 禁止拷贝函数
	LeeGrahamYao83(LeeGrahamYao83 const&) {}
	// 禁止赋值拷贝
	LeeGrahamYao83& operator=(LeeGrahamYao83 const&) {}
	// 禁止析构函数
	~LeeGrahamYao83() {}
	static LeeGrahamYao83* instance;

public:
	static LeeGrahamYao83* Instance() {
		if (!instance)
			instance = new LeeGrahamYao83();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
private:
	Display createDisplay(vector<int>& hull, SimplePolygon& sp, int L1, int E1, int L2, int E2, int index);
};