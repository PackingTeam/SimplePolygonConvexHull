#include "GraphicsScene.h"
#include <cmath>

// ��ʼ����㣬����״̬Ϊ���ڲ���㡣
// ��Ϊ��ʼ���뽫������ȥ�����ݣ�����������ݻ�������
// �����clear()�������displays��sp����������
void GraphicsScene::beginInsert()
{
	isInsertingPoint = true;
	sp.clearAll();
	displays.clear();
	clear();
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

// ������ʾdisplays, step<0ֻ��ʾԭ����Σ�step>=display.size()ֻ��ʾԭ����κ�͹��
void GraphicsScene::display(int step)
{
	clear();
	displayPolygon();
	int displays_size = displays.size();
	if (step < 0)
	{
		return;
	}
	else if (step >= displays_size)
	{
		displayConvexHull();
	}
	else
	{
		int size = displays[step].areas.size();
		for (int i = 0; i < size; i++)
		{
			QPolygonF polygon;
			displays[step].areas[i].getQPolygon(polygon);
			QGraphicsPolygonItem *item = new QGraphicsPolygonItem(polygon);

			QPen pen;
			pen.setColor(displays[step].areaColors[i]);
			pen.setWidth(3);
			item->setPen(pen);

			QBrush brush;
			brush.setColor(displays[step].areaColors[i]);
			item->setBrush(brush);

			addItem(item);
		}

		size = displays[step].lines.size();
		for (int i = 0; i < size; i++)
		{
			Line line = displays[step].lines[i];
			QGraphicsLineItem *item;
			if (line.type == SEGMENT)
				item = new QGraphicsLineItem(line.a.x, line.a.y, line.b.x, line.b.y);
			else if (line.type == RAY)
			{
				if (line.b.x - line.a.x > tolerance)
				{
					double x = 2 * sceneWidth;
					double y = (x - line.a.x) / (line.b.x - line.a.x)*(line.b.y - line.a.y) + line.a.y;
					item = new QGraphicsLineItem(line.a.x, line.a.y, x, y);
				}
				else if (line.b.x - line.a.x < -tolerance)
				{
					double x = -2 * sceneWidth;
					double y = (x - line.a.x) / (line.b.x - line.a.x)*(line.b.y - line.a.y) + line.a.y;
					item = new QGraphicsLineItem(line.a.x, line.a.y, x, y);
				}
				else
				{
					if (line.b.y > line.a.y)
					{
						double x = line.a.x;
						double y = 2 * sceneHeight;
						item = new QGraphicsLineItem(line.a.x, line.a.y, x, y);
					}
					else
					{
						double x = line.a.x;
						double y = -2 * sceneHeight;
						item = new QGraphicsLineItem(line.a.x, line.a.y, x, y);
					}
				}
			}
			else if (line.type == LINE)
			{
				if (abs(line.a.x - line.b.x) < tolerance)
				{
					double x = line.a.x;
					double y1 = 2 * sceneHeight;
					double y2 = -2 * sceneHeight;
					item = new QGraphicsLineItem(x, y1, x, y2);
				}
				else
				{
					double x1 = 2 * sceneWidth;
					double y1 = (x1 - line.a.x) / (line.b.x - line.a.x)*(line.b.y - line.a.y) + line.a.y;
					double x2 = -2 * sceneWidth;
					double y2 = (x2 - line.a.x) / (line.b.x - line.a.x)*(line.b.y - line.a.y) + line.a.y;
					item = new QGraphicsLineItem(x1, y1, x2, y2);
				}
			}

			QPen pen;
			pen.setColor(displays[step].lineColors[i]);
			pen.setWidth(2);
			item->setPen(pen);

			addItem(item);
		}

		size = displays[step].points.size();

		for (int i = 0; i < size; i++)
		{
			Point point = displays[step].points[i];
			QGraphicsRectItem *item = new QGraphicsRectItem(point.x - 3, point.y - 3, 6, 6);
			item->setBrush(displays[step].pointColors[i]);
			addItem(item);
		}
	}
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
				Point p(point);
				
				// ������һ�����ڵ�һ���㸽�����򽫶�������ӷ��
				if (sp.points.size() > 1 && abs(p.x - sp.points[0].x) < maxSameDistance && abs(p.y - sp.points[0].y) < maxSameDistance)
				{
					endInsert();
					displayPolygon();
					return;
				}

				sp.points.push_back(p);

				QGraphicsRectItem *item = new QGraphicsRectItem(point.x() - 1, point.y() - 1, 2, 2);
				item->setBrush(Qt::black);
				addItem(item);

				if (sp.points.size() > 1)
				{
					int size = sp.points.size();
					QGraphicsLineItem *item = new QGraphicsLineItem(sp.points[size-2].x, sp.points[size-2].y, sp.points[size-1].x, sp.points[size-1].y);

					QPen pen;
					pen.setColor(Qt::gray);
					pen.setWidth(1);
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
		QGraphicsRectItem *item = new QGraphicsRectItem(p.x - 1, p.y - 1, 2, 2);
		item->setBrush(Qt::black);
		addItem(item);
	}
	
	if (sp.points.size() >= 3)
	{
		QPolygonF polygon;
		sp.getQPolygon(polygon);
		QGraphicsPolygonItem *item = new QGraphicsPolygonItem(polygon);

		QPen pen;
		pen.setColor(Qt::gray);
		pen.setWidth(1);
		item->setPen(pen);

		addItem(item);
	}
	else if (sp.points.size() == 2)
	{
		QGraphicsLineItem *item = new QGraphicsLineItem(sp.points[0].x, sp.points[0].y, sp.points[1].x, sp.points[1].y);

		QPen pen;
		pen.setColor(Qt::gray);
		pen.setWidth(1);
		item->setPen(pen);

		addItem(item);
	}
}

// ��ʾ͹���ϵĵ�����
// ������clear()����
void GraphicsScene::displayConvexHull()
{
	if (sp.convexHull.size() < 3)
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
