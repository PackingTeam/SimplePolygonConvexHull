#pragma once

#include "Algorithm.h"

// 该算法假设传入的SimplePolygon中的points序列的第一个点，为最左最下点
class BhattacharyaElGindy84 : Algorithm
{
private:
	// 禁止外部初始化
	BhattacharyaElGindy84() {}
	// 禁止拷贝函数
	BhattacharyaElGindy84(BhattacharyaElGindy84 const&) {}
	// 禁止赋值拷贝
	BhattacharyaElGindy84& operator=(BhattacharyaElGindy84 const&) {}
	// 禁止析构函数
	~BhattacharyaElGindy84() {}
	static BhattacharyaElGindy84* instance;

public:
	static BhattacharyaElGindy84* Instance() {
		if (!instance)
			instance = new BhattacharyaElGindy84();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
