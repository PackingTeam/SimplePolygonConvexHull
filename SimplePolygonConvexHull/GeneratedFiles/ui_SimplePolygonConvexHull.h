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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimplePolygonConvexHullClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionInterval_Time;
    QAction *actionGenerate;
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
    QRadioButton *Result;
    QRadioButton *Display;
    QPushButton *Pause;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSetting;

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
        actionInterval_Time = new QAction(SimplePolygonConvexHullClass);
        actionInterval_Time->setObjectName(QStringLiteral("actionInterval_Time"));
        actionGenerate = new QAction(SimplePolygonConvexHullClass);
        actionGenerate->setObjectName(QStringLiteral("actionGenerate"));
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
        ProcessControl->setGeometry(QRect(750, 5, 160, 22));
        ProcessControl->setOrientation(Qt::Horizontal);
        Calculate = new QPushButton(widget);
        Calculate->setObjectName(QStringLiteral("Calculate"));
        Calculate->setGeometry(QRect(440, 4, 75, 22));
        MethodLabel = new QLabel(widget);
        MethodLabel->setObjectName(QStringLiteral("MethodLabel"));
        MethodLabel->setGeometry(QRect(10, 7, 41, 16));
        Pre = new QPushButton(widget);
        Pre->setObjectName(QStringLiteral("Pre"));
        Pre->setGeometry(QRect(550, 4, 50, 22));
        Next = new QPushButton(widget);
        Next->setObjectName(QStringLiteral("Next"));
        Next->setGeometry(QRect(680, 4, 50, 22));
        Next->setAutoRepeatDelay(300);
        Clear = new QPushButton(widget);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(930, 4, 50, 22));
        Clear->setAutoRepeatDelay(300);
        Result = new QRadioButton(widget);
        Result->setObjectName(QStringLiteral("Result"));
        Result->setGeometry(QRect(300, 7, 61, 16));
        Result->setChecked(true);
        Display = new QRadioButton(widget);
        Display->setObjectName(QStringLiteral("Display"));
        Display->setGeometry(QRect(365, 7, 61, 16));
        Pause = new QPushButton(widget);
        Pause->setObjectName(QStringLiteral("Pause"));
        Pause->setGeometry(QRect(610, 4, 60, 22));
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
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        SimplePolygonConvexHullClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionHelp);
        menuSetting->addAction(actionInterval_Time);
        menuSetting->addAction(actionGenerate);

        retranslateUi(SimplePolygonConvexHullClass);

        QMetaObject::connectSlotsByName(SimplePolygonConvexHullClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimplePolygonConvexHullClass)
    {
        SimplePolygonConvexHullClass->setWindowTitle(QApplication::translate("SimplePolygonConvexHullClass", "SimplePolygonConvexHull", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("SimplePolygonConvexHullClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("SimplePolygonConvexHullClass", "Save", Q_NULLPTR));
        actionExit->setText(QApplication::translate("SimplePolygonConvexHullClass", "Exit", Q_NULLPTR));
        actionInterval_Time->setText(QApplication::translate("SimplePolygonConvexHullClass", "Interval Time", Q_NULLPTR));
        actionGenerate->setText(QApplication::translate("SimplePolygonConvexHullClass", "Generate", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("SimplePolygonConvexHullClass", "Help", Q_NULLPTR));
        Method->clear();
        Method->insertItems(0, QStringList()
         << QApplication::translate("SimplePolygonConvexHullClass", "Sklansky 1972 (wrong)", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "McCallum & Avis 1979", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Lee 1983 - Graham & Yao 1983", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Ghosh & Shyamasundar 1983 (wrong)", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Bhattacharya & ElGindy 1984", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Orlowski 1985", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Preparata & Shamos 1985", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Shin & Woo 1986", Q_NULLPTR)
         << QApplication::translate("SimplePolygonConvexHullClass", "Melkman 1987 (best)", Q_NULLPTR)
        );
        Calculate->setText(QApplication::translate("SimplePolygonConvexHullClass", "Calculate", Q_NULLPTR));
        Calculate->setShortcut(QApplication::translate("SimplePolygonConvexHullClass", "Return", Q_NULLPTR));
        MethodLabel->setText(QApplication::translate("SimplePolygonConvexHullClass", "Method", Q_NULLPTR));
        Pre->setText(QApplication::translate("SimplePolygonConvexHullClass", "Pre", Q_NULLPTR));
        Pre->setShortcut(QApplication::translate("SimplePolygonConvexHullClass", "Left", Q_NULLPTR));
        Next->setText(QApplication::translate("SimplePolygonConvexHullClass", "Next", Q_NULLPTR));
        Next->setShortcut(QApplication::translate("SimplePolygonConvexHullClass", "Right", Q_NULLPTR));
        Clear->setText(QApplication::translate("SimplePolygonConvexHullClass", "Clear", Q_NULLPTR));
        Clear->setShortcut(QApplication::translate("SimplePolygonConvexHullClass", "C", Q_NULLPTR));
        Result->setText(QApplication::translate("SimplePolygonConvexHullClass", "result", Q_NULLPTR));
        Display->setText(QApplication::translate("SimplePolygonConvexHullClass", "display", Q_NULLPTR));
        Pause->setText(QApplication::translate("SimplePolygonConvexHullClass", "Start", Q_NULLPTR));
        Pause->setShortcut(QApplication::translate("SimplePolygonConvexHullClass", "Left", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("SimplePolygonConvexHullClass", "File", Q_NULLPTR));
        menuSetting->setTitle(QApplication::translate("SimplePolygonConvexHullClass", "Setting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SimplePolygonConvexHullClass: public Ui_SimplePolygonConvexHullClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEPOLYGONCONVEXHULL_H
