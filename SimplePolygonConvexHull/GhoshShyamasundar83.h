#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class GhoshShyamasundar83 : Algorithm
{
private:
	// 禁止外部初始化
	GhoshShyamasundar83() {}
	// 禁止拷贝函数
	GhoshShyamasundar83(GhoshShyamasundar83 const&) = delete;
	// 禁止赋值拷贝
	GhoshShyamasundar83& operator=(GhoshShyamasundar83 const&) = delete;
	// 禁止析构函数
	~GhoshShyamasundar83() {}
	static GhoshShyamasundar83* instance;

public:
	static GhoshShyamasundar83* Instance() {
		if (!instance)
			instance = new GhoshShyamasundar83();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
