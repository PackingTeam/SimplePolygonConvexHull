#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class LeeGrahamYao83 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	LeeGrahamYao83() {}

public:
	// ��ֹ��������
	LeeGrahamYao83(LeeGrahamYao83 const&) = delete;
	// ��ֹ��ֵ����
	LeeGrahamYao83& operator=(LeeGrahamYao83 const&) = delete;
	static LeeGrahamYao83* Instance() {
		static LeeGrahamYao83 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
private:
	Display createDisplay(vector<int>& hull, SimplePolygon& sp, int L1, int E1, int L2, int E2, int index);
};
