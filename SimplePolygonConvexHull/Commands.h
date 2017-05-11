#pragma once

#include "DataStruc.h"

// ��ɫö���࣬�������ֵ����ɫ
enum Color {
	Black, White, Red, Green, Blue, Yellow, Pink, Purple, Grey
};

// ��������࣬ÿһ���඼������дexcute��unexcute������
 class Command {
public:
	virtual void excute()=0;
	virtual void unexcute()=0;
};

 typedef vector<Command> Commands;

// ��һ����
class DrawLine : Command{
public:
	Point x, y;
	Color color;
	void excute();
	void unexcute();
};

// ɾ��һ����
class DeleteLine : Command {
public:
	Point x, y;
	void excute();
	void unexcute();
};

// ��һ������
class DrawArea : Command {
public:
	vector<Point> points;
	Color color;
	void excute();
	void unexcute();
};

// ɾ��һ������
class DeleteArea : Command {
public:
	vector<Point> points;
	void excute();
	void unexcute();
};

// ��ǵ�Ϊ����״̬������Ⱦɫ�����ֵ��״̬����һ������ʹ��PointColoring�����࣬��ͳһ������Ⱦɫ�����壩
class PointColoring : Command {
public:
	Point x;
	Color color;
	void excute();
	void unexcute();
};