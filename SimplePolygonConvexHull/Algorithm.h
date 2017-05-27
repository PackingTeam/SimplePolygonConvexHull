#pragma once

#include "DataStruc.h"

class Algorithm {
public:
	// ���ڴ�������������㷨����������ʾ����
	virtual void getConvexHull(SimplePolygon & sp) = 0;
	// ������������������㷨��������ʾ����
	virtual void getConvexHullForDisplay(SimplePolygon & sp, Displays & displays) = 0;
	virtual ~Algorithm() {}
};
