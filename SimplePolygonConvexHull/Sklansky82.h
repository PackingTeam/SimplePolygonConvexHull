#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class Sklansky82 : Algorithm
{
private:
	// 禁止外部初始化
	Sklansky82() {}
	// 禁止拷贝函数
	Sklansky82(Sklansky82 const&) = delete;
	// 禁止赋值拷贝
	Sklansky82& operator=(Sklansky82 const&) = delete;
	// 禁止析构函数
	~Sklansky82() {}
	static Sklansky82* instance;

public:
	static Sklansky82* Instance() {
		if (!instance)
			instance = new Sklansky82();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
