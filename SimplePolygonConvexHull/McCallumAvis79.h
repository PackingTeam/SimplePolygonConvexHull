#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class McCallumAvis79 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	McCallumAvis79() {}

public:
	// ��ֹ��������
	McCallumAvis79(McCallumAvis79 const&) = delete;
	// ��ֹ��ֵ����
	McCallumAvis79& operator=(McCallumAvis79 const&) = delete;
	static McCallumAvis79* Instance() {
		static McCallumAvis79 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
