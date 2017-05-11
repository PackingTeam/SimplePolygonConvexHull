#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SimplePolygonConvexHull.h"
#include "DataStruc.h"
#include "Commands.h"

class SimplePolygonConvexHull : public QMainWindow
{
	Q_OBJECT

public:
	SimplePolygonConvexHull(QWidget *parent = Q_NULLPTR);

private:
	Ui::SimplePolygonConvexHullClass ui;
	// 用于储存输入的简单多边形
	SimplePolygon sp;
	// 用于储存计算后的结果
	Commands result;
};
