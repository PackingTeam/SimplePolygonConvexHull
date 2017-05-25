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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimplePolygonConvexHullClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionHelp;
    QWidget *centralWidget;
    QWidget *widget;
    QComboBox *Method;
    QSlider *ProcessControl;
    QPushButton *Calculate;
    QLabel *MethodLabel;
    QPushButton *Pre;
    QPushButton *Next;
    QPushButton *Clear;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *SimplePolygonConvexHullClass)
    {
        if (SimplePolygonConvexHullClass->objectName().isEmpty())
            SimplePolygonConvexHullClass->setObjectName(QStringLiteral("SimplePolygonConvexHullClass"));
        SimplePolygonConvexHullClass->resize(1000, 600);
        SimplePolygonConvexHullClass->setMinimumSize(QSize(1000, 600));
        SimplePolygonConvexHullClass->setMaximumSize(QSize(1000, 600));
        actionOpen = new QAction(SimplePolygonConvexHullClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(SimplePolygonConvexHullClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(SimplePolygonConvexHullClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(SimplePolygonConvexHullClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(SimplePolygonConvexHullClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1000, 30));
        Method = new QComboBox(widget);
        Method->setObjectName(QStringLiteral("Method"));
        Method->setGeometry(QRect(57, 5, 220, 20));
        ProcessControl = new QSlider(widget);
        ProcessControl->setObjectName(QStringLiteral("ProcessControl"));
        ProcessControl->setGeometry(QRect(591, 5, 160, 22));
        ProcessControl->setOrientation(Qt::Horizontal);
        Calculate = new QPushButton(widget);
        Calculate->setObjectName(QStringLiteral("Calculate"));
        Calculate->setGeometry(QRect(294, 4, 75, 22));
        MethodLabel = new QLabel(widget);
        MethodLabel->setObjectName(QStringLiteral("MethodLabel"));
        MethodLabel->setGeometry(QRect(10, 5, 41, 16));
        Pre = new QPushButton(widget);
        Pre->setObjectName(QStringLiteral("Pre"));
        Pre->setGeometry(QRect(447, 4, 50, 22));
        Next = new QPushButton(widget);
        Next->setObjectName(QStringLiteral("Next"));
        Next->setGeometry(QRect(500, 4, 50, 22));
        Clear = new QPushButton(widget);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(900, 5, 50, 22));
        Clear->setAutoRepeatDelay(302);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 30, 1000, 547));
        SimplePolygonConvexHullClass->setCentralWidget(centralWidget);
        graphicsView->raise();
        widget->raise();
        menuBar = new QMenuBar(SimplePolygonConvexHullClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SimplePolygonConvexHullClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);

        retranslateUi(SimplePolygonConvexHullClass);

        QMetaObject::connectSlotsByName(SimplePolygonConvexHullClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimplePolygonConvexHullClass)
    {
        SimplePolygonConvexHullClass->setWindowTitle(QApplication::translate("SimplePolygonConvexHullClass", "SimplePolygonConvexHull", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("SimplePolygonConvexHullClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("SimplePolygonConvexHullClass", "Save", Q_NULLPTR));
        actionExit->setText(QApplication::translate("SimplePolygonConvexHullClass", "Exit", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("SimplePolygonConvexHullClass", "Help", Q_NULLPTR));
        Method->clear();
        Method->insertItems(0, QStringList()
         << QApplication::translate("SimplePolygonConvexHullClass", "Sklansky 1972", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "McCallum & Avis 1979", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Sklansky 1982", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "ElGindy, Avis & Toussaint 1983", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Lee 1983 - Graham & Yao 1983", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Ghosh & Shyamasundar 1983", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Bhattacharya & ElGindy 1984", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Orlowski 1985", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Preparata & Shamos 1985", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Shin & Woo 1986", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Melkman 1987", Q_NULLPTR)
        );
        Calculate->setText(QApplication::translate("SimplePolygonConvexHullClass", "Calculate", Q_NULLPTR));
        MethodLabel->setText(QApplication::translate("SimplePolygonConvexHullClass", "Method", Q_NULLPTR));
        Pre->setText(QApplication::translate("SimplePolygonConvexHullClass", "Pre", Q_NULLPTR));
        Next->setText(QApplication::translate("SimplePolygonConvexHullClass", "Next", Q_NULLPTR));
        Clear->setText(QApplication::translate("SimplePolygonConvexHullClass", "Clear", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("SimplePolygonConvexHullClass", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SimplePolygonConvexHullClass: public Ui_SimplePolygonConvexHullClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEPOLYGONCONVEXHULL_H
