#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include "GraphicsScene.h"
#include "ui_SimplePolygonConvexHull.h"
#include "AlgorithmFactory.h"

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
	// ���ڴ�Ÿ�����������
	GraphicsScene scene;
	// ���ڴ�ŵ�ǰ�ķ���
	Algorithm *method;

private slots:
	void Calculate();
	void Pre();
	void Next();
	void ProcessChange(int k);
	void Clear();

};
