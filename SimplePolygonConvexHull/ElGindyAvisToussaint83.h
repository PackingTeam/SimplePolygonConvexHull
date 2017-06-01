#pragma once

#include "Algorithm.h"

// ���㷨���贫���SimplePolygon�е�points���еĵ�һ���㣬Ϊ�������µ�
class ElGindyAvisToussaint83 : Algorithm
{
private:
	// ��ֹ�ⲿ��ʼ��
	ElGindyAvisToussaint83() {}
	// ��ֹ��������
	ElGindyAvisToussaint83(ElGindyAvisToussaint83 const&) = delete;
	// ��ֹ��ֵ����
	ElGindyAvisToussaint83& operator=(ElGindyAvisToussaint83 const&) = delete;
	// ��ֹ��������
	~ElGindyAvisToussaint83() {}
	static ElGindyAvisToussaint83* instance;

public:
	static ElGindyAvisToussaint83* Instance() {
		if (!instance)
			instance = new ElGindyAvisToussaint83();
		return instance;

	}
	void getConvexHull(SimplePolygon & sp);
	void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays);
};
