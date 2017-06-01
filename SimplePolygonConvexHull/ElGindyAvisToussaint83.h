#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class ElGindyAvisToussaint83 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	ElGindyAvisToussaint83() {}

public:
	// ��ֹ��������
	ElGindyAvisToussaint83(ElGindyAvisToussaint83 const&) = delete;
	// ��ֹ��ֵ����
	ElGindyAvisToussaint83& operator=(ElGindyAvisToussaint83 const&) = delete;
	static ElGindyAvisToussaint83* Instance() {
		static ElGindyAvisToussaint83 instance;
		return &instance;
	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
