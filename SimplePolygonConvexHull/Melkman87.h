#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class Melkman87 : Algorithm
{
private:
	// 禁止外部初始化
	Melkman87() {}
	// 禁止拷贝函数
	Melkman87(Melkman87 const&) = delete;
	// 禁止赋值拷贝
	Melkman87& operator=(Melkman87 const&) = delete;
	// 禁止析构函数
	~Melkman87() {}
	static Melkman87* instance;

public:
	static Melkman87* Instance() {
		if (!instance)
			instance = new Melkman87();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
private:
	Display createDisplay(SimplePolygon& sp, deque<int>& Q, int curIndex);
};
