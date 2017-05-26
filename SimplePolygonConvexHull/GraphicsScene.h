#pragma once

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsEllipseItem>
#include <QPen>
#include "DataStruc.h"


class GraphicsScene : public QGraphicsScene
{
public:
	SimplePolygon &sp;
	Displays &displays;
	GraphicsScene(SimplePolygon &Sp,
		Displays &Displays) : sp(Sp), displays(Displays) {}

private:
	// 用于标记目前是否正在插入点，默认为true
	bool isInsertingPoint = true;

public:
	// 开始插入点，更改状态为正在插入点。
	// 因为开始插入将消除过去的内容，因此所有数据会消除。
	// 会调用clear()，并清除displays和sp中所有数据
	void beginInsert();
	// 中止插入点，更改状态位已经结束插入
	// 只会消除用于显示的数据，不会影响sp中的数据
	// 会调用clear()
	void endInsert();
	// 用于获取当前插入点是否结束
	bool isEndInserting();
	// 用于显示displays
	void display(int step);

protected:
	// 鼠标按键事件处理
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	// 显示多边形上所有的点与线
	// 不调用clear()方法
	void displayPolygon();
	// 显示凸包上的点与线
	// 不调用clear()方法
	void displayConvexHull();
};