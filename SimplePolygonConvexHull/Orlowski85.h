#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class Orlowski85 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	Orlowski85() {}
	// ��ֹ��������
	Orlowski85(Orlowski85 const&) {}
	// ��ֹ��ֵ����
	Orlowski85& operator=(Orlowski85 const&) {}
	// ��ֹ��������
	~Orlowski85() {}
	static Orlowski85* instance;

public:
	static Orlowski85* Instance() {
		if (!instance)
			instance = new Orlowski85();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};