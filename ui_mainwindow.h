/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Mar 26 17:19:35 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "liveplot.h"
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    LivePlot *coercePlot;
    QwtPlot *responsePlot;
    QFrame *simFrame;
    QRadioButton *contSimRadio;
    QRadioButton *stepSimRadio;
    QFrame *stepFrame;
    QLabel *label;
    QLineEdit *stepNoEdit;
    QFrame *coerceFrame;
    QLabel *label_2;
    QLineEdit *coerceEdit;
    QSlider *coerceSilder;
    QFrame *setCoercionFrame;
    QRadioButton *stepCoerceRadio;
    QRadioButton *manualCoerceRadio;
    QRadioButton *impCoerceRadio;
    QRadioButton *nonCoercionRadio;
    QPushButton *simBtn;
    QPushButton *getConfigBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(724, 465);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        coercePlot = new LivePlot(centralWidget);
        coercePlot->setObjectName(QString::fromUtf8("coercePlot"));
        coercePlot->setGeometry(QRect(20, 10, 311, 121));
        responsePlot = new QwtPlot(centralWidget);
        responsePlot->setObjectName(QString::fromUtf8("responsePlot"));
        responsePlot->setGeometry(QRect(20, 140, 311, 121));
        simFrame = new QFrame(centralWidget);
        simFrame->setObjectName(QString::fromUtf8("simFrame"));
        simFrame->setGeometry(QRect(350, 10, 181, 80));
        simFrame->setFrameShape(QFrame::StyledPanel);
        simFrame->setFrameShadow(QFrame::Raised);
        contSimRadio = new QRadioButton(simFrame);
        contSimRadio->setObjectName(QString::fromUtf8("contSimRadio"));
        contSimRadio->setGeometry(QRect(10, 10, 181, 22));
        stepSimRadio = new QRadioButton(simFrame);
        stepSimRadio->setObjectName(QString::fromUtf8("stepSimRadio"));
        stepSimRadio->setGeometry(QRect(10, 40, 141, 22));
        stepFrame = new QFrame(centralWidget);
        stepFrame->setObjectName(QString::fromUtf8("stepFrame"));
        stepFrame->setEnabled(false);
        stepFrame->setGeometry(QRect(540, 10, 181, 80));
        stepFrame->setFrameShape(QFrame::StyledPanel);
        stepFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(stepFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 17));
        stepNoEdit = new QLineEdit(stepFrame);
        stepNoEdit->setObjectName(QString::fromUtf8("stepNoEdit"));
        stepNoEdit->setGeometry(QRect(10, 40, 111, 27));
        coerceFrame = new QFrame(centralWidget);
        coerceFrame->setObjectName(QString::fromUtf8("coerceFrame"));
        coerceFrame->setGeometry(QRect(540, 100, 171, 151));
        coerceFrame->setFrameShape(QFrame::StyledPanel);
        coerceFrame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(coerceFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 81, 17));
        coerceEdit = new QLineEdit(coerceFrame);
        coerceEdit->setObjectName(QString::fromUtf8("coerceEdit"));
        coerceEdit->setGeometry(QRect(10, 40, 71, 27));
        coerceSilder = new QSlider(coerceFrame);
        coerceSilder->setObjectName(QString::fromUtf8("coerceSilder"));
        coerceSilder->setGeometry(QRect(110, 20, 29, 111));
        coerceSilder->setOrientation(Qt::Vertical);
        setCoercionFrame = new QFrame(centralWidget);
        setCoercionFrame->setObjectName(QString::fromUtf8("setCoercionFrame"));
        setCoercionFrame->setGeometry(QRect(350, 100, 181, 151));
        setCoercionFrame->setFrameShape(QFrame::StyledPanel);
        setCoercionFrame->setFrameShadow(QFrame::Raised);
        stepCoerceRadio = new QRadioButton(setCoercionFrame);
        stepCoerceRadio->setObjectName(QString::fromUtf8("stepCoerceRadio"));
        stepCoerceRadio->setGeometry(QRect(10, 10, 141, 22));
        manualCoerceRadio = new QRadioButton(setCoercionFrame);
        manualCoerceRadio->setObjectName(QString::fromUtf8("manualCoerceRadio"));
        manualCoerceRadio->setGeometry(QRect(10, 100, 151, 22));
        impCoerceRadio = new QRadioButton(setCoercionFrame);
        impCoerceRadio->setObjectName(QString::fromUtf8("impCoerceRadio"));
        impCoerceRadio->setGeometry(QRect(10, 40, 151, 22));
        nonCoercionRadio = new QRadioButton(setCoercionFrame);
        nonCoercionRadio->setObjectName(QString::fromUtf8("nonCoercionRadio"));
        nonCoercionRadio->setGeometry(QRect(10, 70, 151, 22));
        simBtn = new QPushButton(centralWidget);
        simBtn->setObjectName(QString::fromUtf8("simBtn"));
        simBtn->setGeometry(QRect(450, 270, 181, 21));
        getConfigBtn = new QPushButton(centralWidget);
        getConfigBtn->setObjectName(QString::fromUtf8("getConfigBtn"));
        getConfigBtn->setGeometry(QRect(350, 270, 97, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 724, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        contSimRadio->setText(QApplication::translate("MainWindow", "Continous simulation", 0, QApplication::UnicodeUTF8));
        stepSimRadio->setText(QApplication::translate("MainWindow", "Step Simulation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Number of steps", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Set coerce", 0, QApplication::UnicodeUTF8));
        stepCoerceRadio->setText(QApplication::translate("MainWindow", "Step coercion", 0, QApplication::UnicodeUTF8));
        manualCoerceRadio->setText(QApplication::translate("MainWindow", "Manual Coercion", 0, QApplication::UnicodeUTF8));
        impCoerceRadio->setText(QApplication::translate("MainWindow", "Impuls coercion", 0, QApplication::UnicodeUTF8));
        nonCoercionRadio->setText(QApplication::translate("MainWindow", "None coercion", 0, QApplication::UnicodeUTF8));
        simBtn->setText(QApplication::translate("MainWindow", "Simulate", 0, QApplication::UnicodeUTF8));
        getConfigBtn->setText(QApplication::translate("MainWindow", "Get Config", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
