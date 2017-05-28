#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class PreparataShamos85 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	PreparataShamos85() {}
	// ��ֹ��������
	PreparataShamos85(PreparataShamos85 const&) {}
	// ��ֹ��ֵ����
	PreparataShamos85& operator=(PreparataShamos85 const&) {}
	// ��ֹ��������
	~PreparataShamos85() {}
	static PreparataShamos85* instance;

public:
	static PreparataShamos85* Instance() {
		if (!instance)
			instance = new PreparataShamos85();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
private:
	Display createDisplay(SimplePolygon& sp, vector<int>& hull, Point& sopport, int leftIndex, int rightIndex, int curIndex);
};