/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
<<<<<<< HEAD
** Created: Wed Apr 4 14:23:04 2012
=======
** Created: Tue Apr 3 23:38:09 2012
>>>>>>> zmiana calej klasy source
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
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStackedWidget>
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
    QListWidget *listWidget_sources;
    QComboBox *comboBox_source;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QDoubleSpinBox *doubleSpinBox_amplitude1;
    QLabel *label_2;
    QWidget *page_2;
    QDoubleSpinBox *doubleSpinBox_amplitude2;
    QDoubleSpinBox *doubleSpinBox_frequency2;
    QLabel *label_6;
    QLabel *label_8;
    QWidget *page_3;
    QDoubleSpinBox *doubleSpinBox_amplitude3;
    QDoubleSpinBox *doubleSpinBox_frequency3;
    QDoubleSpinBox *doubleSpinBox_dutycycle3;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton_addSource;
    QPushButton *pushButton_removeSource;
    QWidget *tab_object;
    QPushButton *getConfigBtn;
    QComboBox *comboBoxObject;
    QLabel *label_4;
    QWidget *tab_controller;
    QComboBox *comboBox;
    QLabel *label_5;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_11;
    QWidget *page_4;
    QWidget *tab_feedback;
    QCheckBox *checkBox_feedback;
    QPushButton *simBtn;
    QPushButton *resetBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(768, 339);
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
        tabWidget->setGeometry(QRect(340, 0, 416, 221));
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
        listWidget_sources = new QListWidget(tab_source);
        listWidget_sources->setObjectName(QString::fromUtf8("listWidget_sources"));
        listWidget_sources->setGeometry(QRect(10, 10, 191, 171));
        comboBox_source = new QComboBox(tab_source);
        comboBox_source->setObjectName(QString::fromUtf8("comboBox_source"));
        comboBox_source->setGeometry(QRect(204, 6, 201, 31));
        stackedWidget = new QStackedWidget(tab_source);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(209, 40, 191, 101));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        doubleSpinBox_amplitude1 = new QDoubleSpinBox(page_1);
        doubleSpinBox_amplitude1->setObjectName(QString::fromUtf8("doubleSpinBox_amplitude1"));
        doubleSpinBox_amplitude1->setGeometry(QRect(120, 10, 62, 27));
        label_2 = new QLabel(page_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 11, 101, 21));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        doubleSpinBox_amplitude2 = new QDoubleSpinBox(page_2);
        doubleSpinBox_amplitude2->setObjectName(QString::fromUtf8("doubleSpinBox_amplitude2"));
        doubleSpinBox_amplitude2->setGeometry(QRect(120, 10, 62, 27));
        doubleSpinBox_frequency2 = new QDoubleSpinBox(page_2);
        doubleSpinBox_frequency2->setObjectName(QString::fromUtf8("doubleSpinBox_frequency2"));
        doubleSpinBox_frequency2->setGeometry(QRect(120, 40, 62, 27));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 11, 101, 21));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 42, 101, 20));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        doubleSpinBox_amplitude3 = new QDoubleSpinBox(page_3);
        doubleSpinBox_amplitude3->setObjectName(QString::fromUtf8("doubleSpinBox_amplitude3"));
        doubleSpinBox_amplitude3->setGeometry(QRect(120, 10, 62, 27));
        doubleSpinBox_frequency3 = new QDoubleSpinBox(page_3);
        doubleSpinBox_frequency3->setObjectName(QString::fromUtf8("doubleSpinBox_frequency3"));
        doubleSpinBox_frequency3->setGeometry(QRect(120, 40, 62, 27));
        doubleSpinBox_dutycycle3 = new QDoubleSpinBox(page_3);
        doubleSpinBox_dutycycle3->setObjectName(QString::fromUtf8("doubleSpinBox_dutycycle3"));
        doubleSpinBox_dutycycle3->setGeometry(QRect(120, 70, 62, 27));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 12, 101, 20));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 41, 101, 21));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 72, 101, 20));
        stackedWidget->addWidget(page_3);
        pushButton_addSource = new QPushButton(tab_source);
        pushButton_addSource->setObjectName(QString::fromUtf8("pushButton_addSource"));
        pushButton_addSource->setGeometry(QRect(210, 150, 91, 27));
        pushButton_removeSource = new QPushButton(tab_source);
        pushButton_removeSource->setObjectName(QString::fromUtf8("pushButton_removeSource"));
        pushButton_removeSource->setGeometry(QRect(310, 150, 91, 27));
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
        comboBox = new QComboBox(tab_controller);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 10, 91, 27));
        label_5 = new QLabel(tab_controller);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 12, 67, 21));
        stackedWidget_2 = new QStackedWidget(tab_controller);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 40, 201, 141));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        doubleSpinBox = new QDoubleSpinBox(page);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(101, 10, 91, 27));
        label_11 = new QLabel(page);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(16, 16, 71, 20));
        stackedWidget_2->addWidget(page);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget_2->addWidget(page_4);
        tabWidget->addTab(tab_controller, QString());
        tab_feedback = new QWidget();
        tab_feedback->setObjectName(QString::fromUtf8("tab_feedback"));
        checkBox_feedback = new QCheckBox(tab_feedback);
        checkBox_feedback->setObjectName(QString::fromUtf8("checkBox_feedback"));
        checkBox_feedback->setGeometry(QRect(20, 10, 381, 22));
        tabWidget->addTab(tab_feedback, QString());
        simBtn = new QPushButton(centralWidget);
        simBtn->setObjectName(QString::fromUtf8("simBtn"));
        simBtn->setGeometry(QRect(350, 230, 191, 41));
        resetBtn = new QPushButton(centralWidget);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));
        resetBtn->setGeometry(QRect(550, 230, 191, 41));
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

        tabWidget->setCurrentIndex(4);
        stackedWidget->setCurrentIndex(2);


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
        comboBox_source->clear();
        comboBox_source->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Impuls", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Sinus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Square", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Triangle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Noise", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "Amplitude:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Amplitude:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Frequency:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Amplitude:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Frequency:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Dutycycle:", 0, QApplication::UnicodeUTF8));
        pushButton_addSource->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_removeSource->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_source), QApplication::translate("MainWindow", "Source", 0, QApplication::UnicodeUTF8));
        getConfigBtn->setText(QApplication::translate("MainWindow", "Get Config", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Chose object:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_object), QApplication::translate("MainWindow", "Object", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "P", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "P:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_controller), QApplication::translate("MainWindow", "Controller", 0, QApplication::UnicodeUTF8));
        checkBox_feedback->setText(QApplication::translate("MainWindow", "Enable Feed Back", 0, QApplication::UnicodeUTF8));
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
