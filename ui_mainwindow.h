/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Mar 24 20:23:11 2012
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
#include <QtGui/QCheckBox>
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
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QwtPlot *coercePlot;
    QwtPlot *responsePlot;
    QPushButton *simulateBtn;
    QFrame *stepFrame;
    QLineEdit *noStepsLine;
    QLabel *label;
    QFrame *frame_2;
    QRadioButton *contSimRadio;
    QRadioButton *stepSimRadio;
    QFrame *frame_3;
    QCheckBox *manualCoercBox;
    QSlider *coerceSlider;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(753, 338);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        coercePlot = new QwtPlot(centralWidget);
        coercePlot->setObjectName(QString::fromUtf8("coercePlot"));
        coercePlot->setGeometry(QRect(20, 0, 331, 111));
        responsePlot = new QwtPlot(centralWidget);
        responsePlot->setObjectName(QString::fromUtf8("responsePlot"));
        responsePlot->setGeometry(QRect(20, 120, 331, 111));
        simulateBtn = new QPushButton(centralWidget);
        simulateBtn->setObjectName(QString::fromUtf8("simulateBtn"));
        simulateBtn->setGeometry(QRect(360, 170, 97, 27));
        stepFrame = new QFrame(centralWidget);
        stepFrame->setObjectName(QString::fromUtf8("stepFrame"));
        stepFrame->setEnabled(false);
        stepFrame->setGeometry(QRect(360, 90, 191, 71));
        stepFrame->setFrameShape(QFrame::StyledPanel);
        stepFrame->setFrameShadow(QFrame::Raised);
        noStepsLine = new QLineEdit(stepFrame);
        noStepsLine->setObjectName(QString::fromUtf8("noStepsLine"));
        noStepsLine->setGeometry(QRect(10, 30, 113, 27));
        label = new QLabel(stepFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 17));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(360, 0, 191, 80));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        contSimRadio = new QRadioButton(frame_2);
        contSimRadio->setObjectName(QString::fromUtf8("contSimRadio"));
        contSimRadio->setGeometry(QRect(10, 10, 191, 22));
        stepSimRadio = new QRadioButton(frame_2);
        stepSimRadio->setObjectName(QString::fromUtf8("stepSimRadio"));
        stepSimRadio->setGeometry(QRect(10, 40, 141, 22));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(560, 0, 151, 161));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        manualCoercBox = new QCheckBox(frame_3);
        manualCoercBox->setObjectName(QString::fromUtf8("manualCoercBox"));
        manualCoercBox->setGeometry(QRect(10, 10, 141, 22));
        coerceSlider = new QSlider(frame_3);
        coerceSlider->setObjectName(QString::fromUtf8("coerceSlider"));
        coerceSlider->setGeometry(QRect(10, 50, 29, 91));
        coerceSlider->setOrientation(Qt::Vertical);
        lineEdit_2 = new QLineEdit(frame_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 80, 61, 27));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 60, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 753, 25));
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
        simulateBtn->setText(QApplication::translate("MainWindow", "Simulate", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Number of steps", 0, QApplication::UnicodeUTF8));
        contSimRadio->setText(QApplication::translate("MainWindow", "Continuous simulation", 0, QApplication::UnicodeUTF8));
        stepSimRadio->setText(QApplication::translate("MainWindow", "Step simulation", 0, QApplication::UnicodeUTF8));
        manualCoercBox->setText(QApplication::translate("MainWindow", "Manual coercion", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
