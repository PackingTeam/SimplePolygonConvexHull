#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class BhattacharyaElGindy84 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	BhattacharyaElGindy84() {}
	// ��ֹ��������
	BhattacharyaElGindy84(BhattacharyaElGindy84 const&) {}
	// ��ֹ��ֵ����
	BhattacharyaElGindy84& operator=(BhattacharyaElGindy84 const&) {}
	// ��ֹ��������
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
