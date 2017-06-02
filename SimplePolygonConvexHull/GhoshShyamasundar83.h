#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class GhoshShyamasundar83 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	GhoshShyamasundar83() {}

public:
	// ��ֹ��������
	GhoshShyamasundar83(GhoshShyamasundar83 const&) = delete;
	// ��ֹ��ֵ����
	GhoshShyamasundar83& operator=(GhoshShyamasundar83 const&) = delete;
	static GhoshShyamasundar83* Instance() {
		static GhoshShyamasundar83 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
