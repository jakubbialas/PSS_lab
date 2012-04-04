/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 4 13:04:00 2012
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
#include <QtGui/QComboBox>
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
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "liveplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    LivePlot *plot1;
    LivePlot *plot2;
    QTabWidget *tabWidget;
    QWidget *tab_simulation;
    QFrame *simFrame;
    QRadioButton *contSimRadio;
    QRadioButton *stepSimRadio;
    QFrame *stepFrame;
    QLabel *label;
    QLineEdit *stepNoEdit;
    QFrame *samplingFrame;
    QLabel *label_3;
    QSlider *samplingSlider;
    QLabel *samplingLabel;
    QWidget *tab_source;
    QFrame *sourceTypeFrame;
    QRadioButton *stepSourceRadio;
    QRadioButton *manualSourceRadio;
    QRadioButton *impSourceRadio;
    QRadioButton *nonSourceRadio;
    QFrame *sourceValueFrame;
    QLabel *label_2;
    QLineEdit *sourceValueEdit;
    QSlider *sourceValueSilder;
    QWidget *tab_object;
    QPushButton *getConfigBtn;
    QComboBox *comboBoxObject;
    QLabel *label_4;
    QWidget *tab_controller;
    QWidget *tab_feedback;
    QPushButton *simBtn;
    QPushButton *resetBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(768, 340);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        plot1 = new LivePlot(centralWidget);
        plot1->setObjectName(QString::fromUtf8("plot1"));
        plot1->setGeometry(QRect(10, 10, 311, 121));
        plot2 = new LivePlot(centralWidget);
        plot2->setObjectName(QString::fromUtf8("plot2"));
        plot2->setGeometry(QRect(10, 140, 311, 121));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(340, 0, 416, 211));
        tab_simulation = new QWidget();
        tab_simulation->setObjectName(QString::fromUtf8("tab_simulation"));
        simFrame = new QFrame(tab_simulation);
        simFrame->setObjectName(QString::fromUtf8("simFrame"));
        simFrame->setGeometry(QRect(10, 10, 191, 81));
        simFrame->setFrameShape(QFrame::StyledPanel);
        simFrame->setFrameShadow(QFrame::Raised);
        contSimRadio = new QRadioButton(simFrame);
        contSimRadio->setObjectName(QString::fromUtf8("contSimRadio"));
        contSimRadio->setGeometry(QRect(10, 10, 181, 22));
        contSimRadio->setChecked(true);
        stepSimRadio = new QRadioButton(simFrame);
        stepSimRadio->setObjectName(QString::fromUtf8("stepSimRadio"));
        stepSimRadio->setGeometry(QRect(10, 41, 141, 21));
        stepFrame = new QFrame(tab_simulation);
        stepFrame->setObjectName(QString::fromUtf8("stepFrame"));
        stepFrame->setEnabled(false);
        stepFrame->setGeometry(QRect(210, 10, 191, 81));
        stepFrame->setFrameShape(QFrame::StyledPanel);
        stepFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(stepFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 21));
        stepNoEdit = new QLineEdit(stepFrame);
        stepNoEdit->setObjectName(QString::fromUtf8("stepNoEdit"));
        stepNoEdit->setGeometry(QRect(10, 40, 121, 31));
        samplingFrame = new QFrame(tab_simulation);
        samplingFrame->setObjectName(QString::fromUtf8("samplingFrame"));
        samplingFrame->setEnabled(true);
        samplingFrame->setGeometry(QRect(10, 100, 391, 61));
        samplingFrame->setFrameShape(QFrame::StyledPanel);
        samplingFrame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(samplingFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 141, 21));
        samplingSlider = new QSlider(samplingFrame);
        samplingSlider->setObjectName(QString::fromUtf8("samplingSlider"));
        samplingSlider->setGeometry(QRect(10, 30, 371, 31));
        samplingSlider->setMinimum(10);
        samplingSlider->setMaximum(1000);
        samplingSlider->setOrientation(Qt::Horizontal);
        samplingLabel = new QLabel(samplingFrame);
        samplingLabel->setObjectName(QString::fromUtf8("samplingLabel"));
        samplingLabel->setGeometry(QRect(160, 10, 67, 21));
        tabWidget->addTab(tab_simulation, QString());
        tab_source = new QWidget();
        tab_source->setObjectName(QString::fromUtf8("tab_source"));
        sourceTypeFrame = new QFrame(tab_source);
        sourceTypeFrame->setObjectName(QString::fromUtf8("sourceTypeFrame"));
        sourceTypeFrame->setGeometry(QRect(10, 10, 191, 131));
        sourceTypeFrame->setFrameShape(QFrame::StyledPanel);
        sourceTypeFrame->setFrameShadow(QFrame::Raised);
        stepSourceRadio = new QRadioButton(sourceTypeFrame);
        stepSourceRadio->setObjectName(QString::fromUtf8("stepSourceRadio"));
        stepSourceRadio->setGeometry(QRect(10, 10, 141, 22));
        stepSourceRadio->setChecked(true);
        manualSourceRadio = new QRadioButton(sourceTypeFrame);
        manualSourceRadio->setObjectName(QString::fromUtf8("manualSourceRadio"));
        manualSourceRadio->setGeometry(QRect(10, 100, 151, 22));
        impSourceRadio = new QRadioButton(sourceTypeFrame);
        impSourceRadio->setObjectName(QString::fromUtf8("impSourceRadio"));
        impSourceRadio->setGeometry(QRect(10, 40, 151, 22));
        nonSourceRadio = new QRadioButton(sourceTypeFrame);
        nonSourceRadio->setObjectName(QString::fromUtf8("nonSourceRadio"));
        nonSourceRadio->setGeometry(QRect(10, 70, 151, 22));
        stepSourceRadio->raise();
        manualSourceRadio->raise();
        nonSourceRadio->raise();
        impSourceRadio->raise();
        sourceValueFrame = new QFrame(tab_source);
        sourceValueFrame->setObjectName(QString::fromUtf8("sourceValueFrame"));
        sourceValueFrame->setEnabled(false);
        sourceValueFrame->setGeometry(QRect(210, 10, 191, 131));
        sourceValueFrame->setFrameShape(QFrame::StyledPanel);
        sourceValueFrame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(sourceValueFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 121, 21));
        sourceValueEdit = new QLineEdit(sourceValueFrame);
        sourceValueEdit->setObjectName(QString::fromUtf8("sourceValueEdit"));
        sourceValueEdit->setGeometry(QRect(10, 40, 91, 31));
        sourceValueSilder = new QSlider(sourceValueFrame);
        sourceValueSilder->setObjectName(QString::fromUtf8("sourceValueSilder"));
        sourceValueSilder->setGeometry(QRect(140, 10, 31, 111));
        sourceValueSilder->setMaximum(100);
        sourceValueSilder->setSliderPosition(1);
        sourceValueSilder->setTracking(true);
        sourceValueSilder->setOrientation(Qt::Vertical);
        sourceValueSilder->setInvertedAppearance(false);
        sourceValueSilder->setInvertedControls(false);
        tabWidget->addTab(tab_source, QString());
        tab_object = new QWidget();
        tab_object->setObjectName(QString::fromUtf8("tab_object"));
        getConfigBtn = new QPushButton(tab_object);
        getConfigBtn->setObjectName(QString::fromUtf8("getConfigBtn"));
        getConfigBtn->setGeometry(QRect(10, 10, 191, 41));
        comboBoxObject = new QComboBox(tab_object);
        comboBoxObject->setObjectName(QString::fromUtf8("comboBoxObject"));
        comboBoxObject->setGeometry(QRect(10, 90, 191, 41));
        label_4 = new QLabel(tab_object);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 191, 21));
        tabWidget->addTab(tab_object, QString());
        tab_controller = new QWidget();
        tab_controller->setObjectName(QString::fromUtf8("tab_controller"));
        tabWidget->addTab(tab_controller, QString());
        tab_feedback = new QWidget();
        tab_feedback->setObjectName(QString::fromUtf8("tab_feedback"));
        tabWidget->addTab(tab_feedback, QString());
        simBtn = new QPushButton(centralWidget);
        simBtn->setObjectName(QString::fromUtf8("simBtn"));
        simBtn->setGeometry(QRect(350, 220, 191, 41));
        resetBtn = new QPushButton(centralWidget);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));
        resetBtn->setGeometry(QRect(550, 220, 191, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 768, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        contSimRadio->setText(QApplication::translate("MainWindow", "Continous simulation", 0, QApplication::UnicodeUTF8));
        stepSimRadio->setText(QApplication::translate("MainWindow", "Step Simulation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Number of steps", 0, QApplication::UnicodeUTF8));
        stepNoEdit->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Sampling speed(ms):", 0, QApplication::UnicodeUTF8));
        samplingLabel->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_simulation), QApplication::translate("MainWindow", "Simulation", 0, QApplication::UnicodeUTF8));
        stepSourceRadio->setText(QApplication::translate("MainWindow", "Step to 1", 0, QApplication::UnicodeUTF8));
        manualSourceRadio->setText(QApplication::translate("MainWindow", "Manual", 0, QApplication::UnicodeUTF8));
        impSourceRadio->setText(QApplication::translate("MainWindow", "Impuls", 0, QApplication::UnicodeUTF8));
        nonSourceRadio->setText(QApplication::translate("MainWindow", "Step to 0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Set source value", 0, QApplication::UnicodeUTF8));
        sourceValueEdit->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_source), QApplication::translate("MainWindow", "Source", 0, QApplication::UnicodeUTF8));
        getConfigBtn->setText(QApplication::translate("MainWindow", "Get Config", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Chose object:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_object), QApplication::translate("MainWindow", "Object", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_controller), QApplication::translate("MainWindow", "Controller", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_feedback), QApplication::translate("MainWindow", "Feedback", 0, QApplication::UnicodeUTF8));
        simBtn->setText(QApplication::translate("MainWindow", "Start Simulation", 0, QApplication::UnicodeUTF8));
        resetBtn->setText(QApplication::translate("MainWindow", "Reset Simulation", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
