#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <QtGui/QApplication>
#include <QMessageBox>
#include <sstream>
#include "coerce.h"
#include "discreteobject.h"

using namespace std;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setLabelText(const QString str);
    void setPlot1aData( double y);
    void setPlot1bData( double y);
    ~MainWindow();

private slots:
    void on_stepSimRadio_clicked();

    void on_stepSimRadio_toggled(bool checked);

    void on_simBtn_clicked();

    void on_getConfigBtn_clicked();

    void on_manualCoerceRadio_toggled(bool checked);

    void on_coerceEdit_textChanged(const QString &arg1);

    void on_coerceSilder_valueChanged(int value);

private:
    DiscreteObject * Object;
    Coerce * coerce;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
