#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SimplePolygonConvexHull.h"
#include "DataStruc.h"

class SimplePolygonConvexHull : public QMainWindow
{
	Q_OBJECT

public:
	SimplePolygonConvexHull(QWidget *parent = Q_NULLPTR);

private:
	Ui::SimplePolygonConvexHullClass ui;
	// ���ڴ�������ļ򵥶����
	SimplePolygon sp;
	// ���ڴ�������ÿһ���Ľ��
	Displays displays;

private slots:
	void Calculate();
	void Pre();
	void Next();
	void ProcessChange();
};
