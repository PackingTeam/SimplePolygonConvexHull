#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class McCallumAvis79 : Algorithm
{
private:
	// 禁止外部初始化
	McCallumAvis79() {}
	// 禁止拷贝函数
	McCallumAvis79(McCallumAvis79 const&) {}
	// 禁止赋值拷贝
	McCallumAvis79& operator=(McCallumAvis79 const&) {}
	// 禁止析构函数
	~McCallumAvis79() {}
	static McCallumAvis79* instance;

public:
	static McCallumAvis79* Instance() {
		if (!instance)
			instance = new McCallumAvis79();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
