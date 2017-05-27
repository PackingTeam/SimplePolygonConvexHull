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
	// ���ڱ��Ŀǰ�Ƿ����ڲ���㣬Ĭ��Ϊtrue
	bool isInsertingPoint = true;

public:
	// ��ʼ����㣬����״̬Ϊ���ڲ���㡣
	// ��Ϊ��ʼ���뽫������ȥ�����ݣ�����������ݻ�������
	// �����clear()�������displays��sp����������
	void beginInsert();
	// ��ֹ����㣬����״̬λ�Ѿ���������
	// ֻ������������ʾ�����ݣ�����Ӱ��sp�е�����
	// �����clear()
	void endInsert();
	// ���ڻ�ȡ��ǰ������Ƿ����
	bool isEndInserting();
	// ������ʾdisplays
	void display(int step);

protected:
	// ��갴���¼�����
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	// ��ʾ����������еĵ�����
	// ������clear()����
	void displayPolygon();
	// ��ʾ͹���ϵĵ�����
	// ������clear()����
	void displayConvexHull();
};