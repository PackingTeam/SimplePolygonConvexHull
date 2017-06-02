#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class BhattacharyaElGindy84 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	BhattacharyaElGindy84() {}

public:
	// ��ֹ��������
	BhattacharyaElGindy84(BhattacharyaElGindy84 const&) = delete;
	// ��ֹ��ֵ����
	BhattacharyaElGindy84& operator=(BhattacharyaElGindy84 const&) = delete;
	static BhattacharyaElGindy84* Instance() {
		static BhattacharyaElGindy84 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
