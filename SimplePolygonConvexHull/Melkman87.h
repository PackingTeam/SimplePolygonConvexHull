#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class Melkman87 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	Melkman87() {}

public:
	// ��ֹ��������
	Melkman87(Melkman87 const&) = delete;
	// ��ֹ��ֵ����
	Melkman87& operator=(Melkman87 const&) = delete;
	static Melkman87* Instance() {
		static Melkman87 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
private:
	Display createDisplay(SimplePolygon& sp, deque<int>& Q, int curIndex);
};
