#include "SimplePolygonConvexHull.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SimplePolygonConvexHull w;
	w.show();
	return a.exec();
}
