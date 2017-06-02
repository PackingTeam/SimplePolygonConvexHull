#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QTextCodec>
#include <QInputDialog>
#include "GraphicsScene.h"
#include "ui_SimplePolygonConvexHull.h"
#include "AlgorithmFactory.h"
#include <iostream>
#include <fstream>

class SimplePolygonConvexHull : public QMainWindow
{
	Q_OBJECT

public:
	SimplePolygonConvexHull(QWidget *parent = Q_NULLPTR);

private:
	Ui::SimplePolygonConvexHullClass ui;
	// ���ڴ�������ļ򵥶����
	SimplePolygon sp;
	// ���ڴ�������ÿһ���Ľ��
	Displays displays;
	// ���ڴ�ŵ�ǰ�ķ���
	Algorithm *method;
	// ���ڴ洢��ǰ��ʾ����Ϊ�ڼ���
	int step;
	// ���ڴ�Ÿ�����������
	GraphicsScene scene;
	// �����жϵ�ǰ�Ƿ���ͣ����
	bool isStop;
	// �����ݴ��ʱ��id
	int timerId;
	// ��ʱ���
	int timeInterval;
	// ���ɵ������
	int generateNum;

	// ���ڲٿ���ʾ����仯�ķ���
	void next();
	void previous();

private slots:
	void Calculate();
	void Pre();
	void Next();
	void ProcessChange(int k);
	void Clear();
	void Pause();
	void Save();
	void Open();
	void methodChanged(int k);
	void setTimeInterval();
	void setGenerateNum();
	void help();
	void displayCounterExample();

protected:
	void timerEvent(QTimerEvent *event);
};
