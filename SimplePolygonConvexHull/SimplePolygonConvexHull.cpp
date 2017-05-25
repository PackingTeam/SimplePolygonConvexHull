#include "SimplePolygonConvexHull.h"

SimplePolygonConvexHull::SimplePolygonConvexHull(QWidget *parent)
	: QMainWindow(parent), scene(sp, displays)
{
	// 绑定事件
	ui.setupUi(this);
	connect(ui.Calculate, SIGNAL(clicked()), this, SLOT(Calculate()));
	connect(ui.Next, SIGNAL(clicked()), this, SLOT(Next()));
	connect(ui.Pre, SIGNAL(clicked()), this, SLOT(Pre()));
	connect(ui.ProcessControl, SIGNAL(valueChanged(int)), this, SLOT(ProcessChange(int)));
	connect(ui.Clear, SIGNAL(clicked()), this, SLOT(Clear()));

	// 设置演示区域
	scene.setSceneRect(-sceneWidth/2, -sceneHeight/2, sceneWidth, sceneHeight);
	ui.graphicsView->setScene(&scene);
	ui.graphicsView->scale(1, -1);
}

void SimplePolygonConvexHull::Calculate()
{
	if (scene.isEndInserting())
	{
		sp.normalize();
		int methodId = ui.Method->currentIndex();
		method = getMethodById(methodId);
		method->getConvexHull(sp);
		scene.display();
	}
	else
	{
		QMessageBox::warning(this, "Warning", "The polygon is not closed.");
	}
}

void SimplePolygonConvexHull::Pre()
{

}

void SimplePolygonConvexHull::Next() 
{

}

void SimplePolygonConvexHull::ProcessChange(int k)
{

}

void SimplePolygonConvexHull::Clear()
{
	scene.beginInsert();
}
