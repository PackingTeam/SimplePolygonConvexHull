#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class Sklansky72 : Algorithm 
{
private:
	// ��ֹ�ⲿ��ʼ��
	Sklansky72() {}

public:
	// ��ֹ��������
	Sklansky72(Sklansky72 const&) = delete;
	// ��ֹ��ֵ����
	Sklansky72& operator=(Sklansky72 const&) = delete;
	static Sklansky72* Instance() {
		static Sklansky72 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
