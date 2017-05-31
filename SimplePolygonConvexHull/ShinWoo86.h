#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class ShinWoo86 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	ShinWoo86() {}
	// ��ֹ��������
	ShinWoo86(ShinWoo86 const&) {}
	// ��ֹ��ֵ����
	ShinWoo86& operator=(ShinWoo86 const&) {}
	// ��ֹ��������
	~ShinWoo86() {}
	static ShinWoo86* instance;
	Display createDisplay(SimplePolygon& sp, vector<int>& hull, Point& support, int leftIndex, int rightIndex, int curIndex);

public:
	static ShinWoo86* Instance() {
		if (!instance)
			instance = new ShinWoo86();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};