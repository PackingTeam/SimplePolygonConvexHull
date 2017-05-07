#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SimplePolygonConvexHull.h"

class SimplePolygonConvexHull : public QMainWindow
{
	Q_OBJECT

public:
	SimplePolygonConvexHull(QWidget *parent = Q_NULLPTR);

private:
	Ui::SimplePolygonConvexHullClass ui;
};
