#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class Sklansky72 : Algorithm 
{
private:
	// ��ֹ�ⲿ��ʼ��
	Sklansky72() {}
	// ��ֹ��������
	Sklansky72(Sklansky72 const&) {}
	// ��ֹ��ֵ����
	Sklansky72& operator=(Sklansky72 const&) {}
	// ��ֹ��������
	~Sklansky72() {}
	static Sklansky72* instance;

public:
	static Sklansky72* Instance() {
		if (!instance)
			instance = new Sklansky72();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};