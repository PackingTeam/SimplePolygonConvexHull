#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class Sklansky82 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	Sklansky82() {}

public:
	// ��ֹ��������
	Sklansky82(Sklansky82 const&) = delete;
	// ��ֹ��ֵ����
	Sklansky82& operator=(Sklansky82 const&) = delete;
	static Sklansky82* Instance() {
		static Sklansky82 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
