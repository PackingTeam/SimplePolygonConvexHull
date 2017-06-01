#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class ElGindyAvisToussaint83 : Algorithm
{
private:
	// 禁止外部初始化
	ElGindyAvisToussaint83() {}

public:
	// 禁止拷贝函数
	ElGindyAvisToussaint83(ElGindyAvisToussaint83 const&) = delete;
	// 禁止赋值拷贝
	ElGindyAvisToussaint83& operator=(ElGindyAvisToussaint83 const&) = delete;
	static ElGindyAvisToussaint83* Instance() {
		static ElGindyAvisToussaint83 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
