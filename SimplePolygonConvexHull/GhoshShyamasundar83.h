#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class GhoshShyamasundar83 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	GhoshShyamasundar83() {}
	// ��ֹ��������
	GhoshShyamasundar83(GhoshShyamasundar83 const&) {}
	// ��ֹ��ֵ����
	GhoshShyamasundar83& operator=(GhoshShyamasundar83 const&) {}
	// ��ֹ��������
	~GhoshShyamasundar83() {}
	static GhoshShyamasundar83* instance;

public:
	static GhoshShyamasundar83* Instance() {
		if (!instance)
			instance = new GhoshShyamasundar83();
		return instance;

	}
	void getHalfConvexHull(SimplePolygon &sp, int max, int min);
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
