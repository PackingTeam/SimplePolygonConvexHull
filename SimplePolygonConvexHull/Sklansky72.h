#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class Sklansky72 : Algorithm 
{
private:
	// 禁止外部初始化
	Sklansky72() {}
	// 禁止拷贝函数
	Sklansky72(Sklansky72 const&) {}
	// 禁止赋值拷贝
	Sklansky72& operator=(Sklansky72 const&) {}
	// 禁止析构函数
	~Sklansky72() {}
	static Sklansky72* instance;

public:
	static Sklansky72* Instance() {
		if (!instance)
			instance = new Sklansky72();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};