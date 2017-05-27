#include "SimplePolygonConvexHull.h"

SimplePolygonConvexHull::SimplePolygonConvexHull(QWidget *parent)
	: QMainWindow(parent), scene(sp, displays), isStop(true)
{
	step = -1;

	// 绑定事件
	ui.setupUi(this);
	connect(ui.Calculate, SIGNAL(clicked()), this, SLOT(Calculate()));
	connect(ui.Next, SIGNAL(clicked()), this, SLOT(Next()));
	connect(ui.Pre, SIGNAL(clicked()), this, SLOT(Pre()));
	connect(ui.ProcessControl, SIGNAL(valueChanged(int)), this, SLOT(ProcessChange(int)));
	connect(ui.Clear, SIGNAL(clicked()), this, SLOT(Clear()));
	connect(ui.Pause, SIGNAL(clicked()), this, SLOT(Pause()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(Save()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(Open()));

	ui.Next->setDisabled(true);
	ui.Pre->setDisabled(true);
	ui.ProcessControl->setDisabled(true);
	ui.Pause->setDisabled(true);

	// 设置演示区域
	scene.setSceneRect(-sceneWidth/2, -sceneHeight/2, sceneWidth, sceneHeight);
	ui.graphicsView->setScene(&scene);
	ui.graphicsView->scale(1, -1);
}

void SimplePolygonConvexHull::Calculate()
{
	if (!scene.isEndInserting())
	{
		if (sp.points.size() == 0)
			QMessageBox::warning(this, "Warning", "No polygon drawed.");
		else
			QMessageBox::warning(this, "Warning", "The polygon is not completed.");
		return;
	}
	sp.normalize();
	displays.clear();
	sp.convexHull.clear();

	int methodId = ui.Method->currentIndex();
	method = getMethodById(methodId);

	if (ui.Result->isChecked())
	{
		method->getConvexHull(sp);
		ui.ProcessControl->setDisabled(true);
		ui.Next->setDisabled(true);
		ui.Pre->setDisabled(true);
		ui.Pause->setDisabled(true);
		step = 0;
		isStop = true;
	}
	else if (ui.Display->isChecked())
	{
		method->getConvexHullForDisplay(sp, displays);
		ui.ProcessControl->setMinimum(-1);
		ui.ProcessControl->setMaximum(displays.size());
		ui.ProcessControl->setDisabled(false);
		ui.Next->setDisabled(false);
		ui.Pre->setDisabled(false);
		ui.Pause->setDisabled(false);
		step = -1;
		isStop = false;
	}
	scene.display(step);
}
		

void SimplePolygonConvexHull::Pre()
{
	if (step > -1)
		previous();
	else
		QMessageBox::warning(this, "Warning", "No step before.");
}

void SimplePolygonConvexHull::Next() 
{
	int size = displays.size();
	if (step < size)
		next();
	else
		QMessageBox::warning(this, "Warning", "No step after.");
}

void SimplePolygonConvexHull::ProcessChange(int k)
{
	int size = displays.size();
	if (k >= -1 && k <= size)
	{
		step = k;
		scene.display(step);
	}
	else
		QMessageBox::warning(this, "Warning", "The step is out of displays range.");
}

void SimplePolygonConvexHull::Clear()
{
	scene.beginInsert();
	step = -1;
}

void SimplePolygonConvexHull::Pause()
{
	if (!isStop)
	{

	}
	else
	{

	}
}

// 用于操控演示步骤变化的方法
void SimplePolygonConvexHull::next()
{
	step++;
	scene.display(step);
	ui.ProcessControl->setValue(step);
}

void SimplePolygonConvexHull::previous()
{
	step--;
	scene.display(step);
	ui.ProcessControl->setValue(step);
}

void SimplePolygonConvexHull::Save()
{
	if (!scene.isEndInserting())
	{
		if (sp.points.size() == 0)
			QMessageBox::warning(this, "Warning", "No polygon drawed.");
		else
			QMessageBox::warning(this, "Warning", "The polygon is not completed.");
		return;
	}
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Simple Polygon Data"),
		".", tr("Data Files (*.txt)"));
	ofstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (filename.isEmpty())
		return;
	f << sp.toString() << endl;
	f.close();
}

void SimplePolygonConvexHull::Open()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Load Simple Polygon Data"),
		".", tr("Data Files (*.txt)"));
	fstream f(filename.toStdString());
	if (!filename.isEmpty() && !f)
	{
		QMessageBox::warning(this, "Warning", "The path should not contain chinese.");
		return;
	}
	else if (filename.isEmpty())
		return;
	string temp;
	f >> temp;
	sp.setPolygon(temp);
	f.close();

	scene.endInsert();
	scene.display(-1);
}