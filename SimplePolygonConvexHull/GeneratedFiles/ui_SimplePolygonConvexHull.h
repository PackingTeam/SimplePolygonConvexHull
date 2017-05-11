/********************************************************************************
** Form generated from reading UI file 'SimplePolygonConvexHull.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEPOLYGONCONVEXHULL_H
#define UI_SIMPLEPOLYGONCONVEXHULL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimplePolygonConvexHullClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimplePolygonConvexHullClass)
    {
        if (SimplePolygonConvexHullClass->objectName().isEmpty())
            SimplePolygonConvexHullClass->setObjectName(QStringLiteral("SimplePolygonConvexHullClass"));
        SimplePolygonConvexHullClass->resize(600, 400);
        menuBar = new QMenuBar(SimplePolygonConvexHullClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SimplePolygonConvexHullClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimplePolygonConvexHullClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SimplePolygonConvexHullClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SimplePolygonConvexHullClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SimplePolygonConvexHullClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SimplePolygonConvexHullClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SimplePolygonConvexHullClass->setStatusBar(statusBar);

        retranslateUi(SimplePolygonConvexHullClass);

        QMetaObject::connectSlotsByName(SimplePolygonConvexHullClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimplePolygonConvexHullClass)
    {
        SimplePolygonConvexHullClass->setWindowTitle(QApplication::translate("SimplePolygonConvexHullClass", "SimplePolygonConvexHull", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SimplePolygonConvexHullClass: public Ui_SimplePolygonConvexHullClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEPOLYGONCONVEXHULL_H
