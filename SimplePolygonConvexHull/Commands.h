#pragma once

#include "DataStruc.h"

// 颜色枚举类，用于区分点的颜色
enum Color {
	Black, White, Red, Green, Blue, Yellow, Pink, Purple, Grey
};

// 命令抽象类，每一个类都必须重写excute和unexcute两个类
 class Command {
public:
	virtual void excute()=0;
	virtual void unexcute()=0;
};

 typedef vector<Command> Commands;

// 画一条线
class DrawLine : Command{
public:
	Point x, y;
	Color color;
	void excute();
	void unexcute();
};

// 删除一条线
class DeleteLine : Command {
public:
	Point x, y;
	void excute();
	void unexcute();
};

// 画一个区域
class DrawArea : Command {
public:
	vector<Point> points;
	Color color;
	void excute();
	void unexcute();
};

// 删除一个区域
class DeleteArea : Command {
public:
	vector<Point> points;
	void excute();
	void unexcute();
};

// 标记点为各个状态，即用染色来区分点的状态（进一步可以使用PointColoring的子类，来统一各个点染色的意义）
class PointColoring : Command {
public:
	Point x;
	Color color;
	void excute();
	void unexcute();
};