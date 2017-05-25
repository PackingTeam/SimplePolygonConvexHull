#include "GraphicsScene.h"

// ��ʼ����㣬����״̬Ϊ���ڲ���㡣
// ��Ϊ��ʼ���뽫������ȥ�����ݣ�����������ݻ�������
// �����clear()�������displays��sp����������
void GraphicsScene::beginInsert()
{
	if (!isInsertingPoint)
	{
		isInsertingPoint = true;
		sp.clearAll();
		displays.clear();
		clear();
	}
}

// ��ֹ����㣬����״̬λ�Ѿ���������
// ֻ������������ʾ�����ݣ�����Ӱ��sp�е�����
// �����clear()
void GraphicsScene::endInsert()
{
	if (isInsertingPoint)
	{
		isInsertingPoint = false;
		clear();
	}
}

// ���ڻ�ȡ��ǰ������Ƿ����
bool GraphicsScene::isEndInserting()
{
	return !isInsertingPoint;
}

// ������ʾdisplays
void GraphicsScene::display()
{
	clear();
	displayPolygon();
	displayConvexHull();
}

// ��갴���¼�����
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	QGraphicsScene::mousePressEvent(event);
	if (!event->isAccepted())
	{
		if (event->button() == Qt::LeftButton) {
			if (isInsertingPoint)
			{
				QPointF point = event->scenePos();
				sp.points.push_back(Point(point));

				QGraphicsRectItem *item = new QGraphicsRectItem(point.x() - 2, point.y() - 2, 4, 4);
				item->setBrush(QColor(0, 0, 0));
				addItem(item);

				if (sp.points.size() > 1)
				{
					int size = sp.points.size();
					QGraphicsLineItem *item = new QGraphicsLineItem(sp.points[size-2].x, sp.points[size-2].y, sp.points[size-1].x, sp.points[size-1].y);

					QPen pen;
					pen.setColor(QColor(0, 0, 0));
					pen.setWidth(2);
					item->setPen(pen);

					addItem(item);
				}
			}
		}
		else if (event->button() == Qt::RightButton)
		{
			if (isInsertingPoint)
			{
				endInsert();
				displayPolygon();
			}
		}
	}
}

// ��ʾ����������еĵ�����
// ������clear()����
void GraphicsScene::displayPolygon()
{
    for (const Point &p : sp.points)
	{
		QGraphicsRectItem *item = new QGraphicsRectItem(p.x - 2, p.y - 2, 4, 4);
		item->setBrush(Qt::black);
		addItem(item);
	}
	
	if (sp.points.size() >= 3)
	{
		QPolygonF polygon;
		sp.getQPolygon(polygon);
		QGraphicsPolygonItem *item = new QGraphicsPolygonItem(polygon);

		QPen pen;
		pen.setColor(Qt::black);
		pen.setWidth(2);
		item->setPen(pen);

		addItem(item);
	}
	else if (sp.points.size() == 2)
	{
		QGraphicsLineItem *item = new QGraphicsLineItem(sp.points[0].x, sp.points[0].y, sp.points[1].x, sp.points[1].y);

		QPen pen;
		pen.setColor(Qt::black);
		pen.setWidth(2);
		item->setPen(pen);

		addItem(item);
	}
}

// ��ʾ͹���ϵĵ�����
// ������clear()����
void GraphicsScene::displayConvexHull()
{
	if (sp.convexHull.size() <= 3)
		return;
	else
	{
		QPolygonF polygon;
		sp.getConvexHullPolygon(polygon);
		QGraphicsPolygonItem *item = new QGraphicsPolygonItem(polygon);

		QPen pen;
		pen.setColor(QColor(Qt::green));
		pen.setWidth(2);
		item->setPen(pen);

		addItem(item);

        for (int id : sp.convexHull)
		{
			Point p = sp.points[id];
			QGraphicsRectItem *item = new QGraphicsRectItem(p.x - 2, p.y - 2, 4, 4);
			item->setBrush(QColor(Qt::green));
			addItem(item);
		}
	}
}