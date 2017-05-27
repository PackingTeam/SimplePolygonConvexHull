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
	// ���ڴ�ŵ�ǰ�ķ���
	Algorithm *method;
	// ���ڴ洢��ǰ��ʾ����Ϊ�ڼ���
	int step;
	// ���ڴ�Ÿ�����������
	GraphicsScene scene;

	// ���ڲٿ���ʾ����仯�ķ���
	void next();
	void previous();
	void jumpTo(int step);

private slots:
	void Calculate();
	void Pre();
	void Next();
	void ProcessChange(int k);
	void Clear();

};
