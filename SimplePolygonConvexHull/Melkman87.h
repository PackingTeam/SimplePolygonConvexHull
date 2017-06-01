#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class Melkman87 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	Melkman87() {}
	// ��ֹ��������
	Melkman87(Melkman87 const&) = delete;
	// ��ֹ��ֵ����
	Melkman87& operator=(Melkman87 const&) = delete;
	// ��ֹ��������
	~Melkman87() {}
	static Melkman87* instance;

public:
	static Melkman87* Instance() {
		if (!instance)
			instance = new Melkman87();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
private:
	Display createDisplay(SimplePolygon& sp, deque<int>& Q, int curIndex);
};
