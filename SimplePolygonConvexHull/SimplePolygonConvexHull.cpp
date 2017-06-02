#include "SimplePolygonConvexHull.h"

SimplePolygonConvexHull::SimplePolygonConvexHull(QWidget *parent)
	: QMainWindow(parent), scene(sp, displays), isStop(true), timeInterval(200)
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
	connect(ui.Method, SIGNAL(currentIndexChanged(int)), this, SLOT(methodChanged(int)));
	connect(ui.actionInterval_Time, SIGNAL(triggered()), this, SLOT(setTimeInterval()));
	connect(ui.actionGenerate, SIGNAL(triggered()), this, SLOT(setGenerateNum()));

	ui.Next->setDisabled(true);
	ui.Pre->setDisabled(true);
	ui.ProcessControl->setDisabled(true);
	ui.Pause->setDisabled(true);

	// 设置演示区域
	scene.setSceneRect(-sceneWidth/2, -sceneHeight/2, sceneWidth, sceneHeight);
	ui.graphicsView->setScene(&scene);
	ui.graphicsView->scale(1, -1);

	ui.graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void SimplePolygonConvexHull::Calculate()
{
	// 判断是否结束了插入
	if (!scene.isEndInserting())
	{
		if (sp.points.size() == 0)
			QMessageBox::warning(this, "Warning", "No polygon drawed.");
		else
			QMessageBox::warning(this, "Warning", "The polygon is not completed.");
		return;
	}

	// 对sp和displays进行整理
	sp.normalize();
	displays.clear();
	sp.convexHull.clear();

	killTimer(timerId);

	if (!sp.isLegal())
	{
		QMessageBox::warning(this, "Warning", "The polygon is illegal.");
		return;
	}

	int methodId = ui.Method->currentIndex();
	method = getMethodById(methodId);
	ui.Pause->setText("Start");

	// 如果为只显示结果的模式
	if (ui.Result->isChecked())
	{
		method->getConvexHull(sp);
		ui.ProcessControl->setDisabled(true);
		ui.ProcessControl->setValue(0);
		ui.Next->setDisabled(true);
		ui.Pre->setDisabled(true);
		ui.Pause->setDisabled(true);
		step = 0;
		isStop = true;
	}
	// 如果为显示演示的模式
	else if (ui.Display->isChecked())
	{
		method->getConvexHullForDisplay(sp, displays);
		ui.ProcessControl->setMinimum(-1);
		ui.ProcessControl->setMaximum(displays.size());
		ui.ProcessControl->setValue(-1);
		ui.ProcessControl->setDisabled(false);
		ui.Next->setDisabled(false);
		ui.Pre->setDisabled(false);
		ui.Pause->setDisabled(false);
		step = -1;
		isStop = true;
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
	// 按下的按钮为Start
	if (isStop)
	{
		int size = displays.size();
		if (step >= size)
		{
			step = 0;
			scene.display(step);
			ui.ProcessControl->setValue(0);
		}
		ui.ProcessControl->setDisabled(true);
		ui.Next->setDisabled(true);
		ui.Pre->setDisabled(true);
		timerId = startTimer(timeInterval);
		isStop = false;
		ui.Pause->setText("Pause");
	}
	// 按下的按钮为Stop
	else
	{
		ui.ProcessControl->setDisabled(false);
		ui.Next->setDisabled(false);
		ui.Pre->setDisabled(false);
		killTimer(timerId);
		isStop = true;
		ui.Pause->setText("Continue");
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

void SimplePolygonConvexHull::methodChanged(int k)
{
	// 假设需要一切换方法，就将进度条归0
	// ui.ProcessControl->setValue(0);
}

// 计时器进程
void SimplePolygonConvexHull::timerEvent(QTimerEvent *event)
{
	int size = displays.size();
	if (step < size)
		next();
	else
	{
		ui.ProcessControl->setDisabled(false);
		ui.Next->setDisabled(false);
		ui.Pre->setDisabled(false);
		killTimer(timerId);
		isStop = true;
		ui.Pause->setText("Restart");
	}
}

void SimplePolygonConvexHull::setTimeInterval()
{
	bool ok;
	int temp = QInputDialog::getInt(this, tr("Set display time interval"), tr("Time Interval(ms):"), timeInterval, 10, 20000, 10, &ok);
	if (ok)
		timeInterval = temp;
}

void SimplePolygonConvexHull::setGenerateNum()
{
	bool ok;
	int temp = QInputDialog::getInt(this, tr("Generate a simple polygon"), tr("points' num:"), timeInterval, 5, 2000, 1, &ok);
	if (ok)
	{
		generateSimplePolygon(sp, temp, sceneWidth, sceneHeight);
		scene.endInsert();
		scene.display(-1);
	}
}