#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class McCallumAvis79 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	McCallumAvis79() {}
	// ��ֹ��������
	McCallumAvis79(McCallumAvis79 const&) {}
	// ��ֹ��ֵ����
	McCallumAvis79& operator=(McCallumAvis79 const&) {}
	// ��ֹ��������
	~McCallumAvis79() {}
	static McCallumAvis79* instance;

public:
	static McCallumAvis79* Instance() {
		if (!instance)
			instance = new McCallumAvis79();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
