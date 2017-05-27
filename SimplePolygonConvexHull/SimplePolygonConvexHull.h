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
	// 用于储存输入的简单多边形
	SimplePolygon sp;
	// 用于储存计算后每一步的结果
	Displays displays;
	// 用于存放当前的方法
	Algorithm *method;
	// 用于存储当前演示步骤为第几步
	int step;
	// 用于存放各个场景数据
	GraphicsScene scene;

	// 用于操控演示步骤变化的方法
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
