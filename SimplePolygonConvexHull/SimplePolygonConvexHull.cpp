#include "SimplePolygonConvexHull.h"

SimplePolygonConvexHull::SimplePolygonConvexHull(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.Calculate, SIGNAL(clicked()), this, SLOT(Calculate()));
	connect(ui.Next, SIGNAL(clicked()), this, SLOT(Next()));
	connect(ui.Pre, SIGNAL(clicked()), this, SLOT(Pre()));
	connect(ui.ProcessControl, SIGNAL(valueChanged()), this, SLOT(ProcessChange()));
}

void SimplePolygonConvexHull::Calculate()
{

}

void SimplePolygonConvexHull::Pre()
{

}

void SimplePolygonConvexHull::Next() 
{

}

void SimplePolygonConvexHull::ProcessChange()
{

}