#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <QtGui/QApplication>
#include <QMessageBox>
#include <sstream>
#include <QTimer>
#include "coerce.h"
#include "discreteobject.h"
#include "yamlconfigparser.h"

using namespace std;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

//signals to simulation object (setings):
    void loadConfig(const char *);
    void setCoercionType(Coerce::CoercionType);
    void setCoercionValue(double);
    void setObject(std::string);
    void setSamplingTime(int);

//signals to simulation object (simulate):
    void startSimulation();
    void stopSimulation();
    void resetSimulation();
    void stepSimulation(int);

private slots:

//signals from simulation object:
  //draw:
    void drawInput(double y);
    void drawOutput(double y);
    void drawError(double y);
    void drawControl(double y);
  //infos:
    void setObjectsList(std::vector<std::string>);

//buttons:
    void on_simBtn_clicked();
    void on_getConfigBtn_clicked();
    void on_resetBtn_clicked();

//sliders:
    void on_samplingSlider_valueChanged(int value);
    void on_coerceSilder_valueChanged(int value);
    void on_coerceEdit_textChanged(const QString &arg1);

//radios simulation:
    void on_contSimRadio_toggled(bool checked);
    void on_stepSimRadio_toggled(bool checked);

//radios coerce:
    void on_stepCoerceRadio_toggled(bool checked);
    void on_impCoerceRadio_toggled(bool checked);
    void on_nonCoerceRadio_toggled(bool checked);
    void on_manualCoerceRadio_toggled(bool checked);

//object set:
    void on_comboBoxObject_currentIndexChanged(const QString &arg1);


private:
    Ui::MainWindow *ui;

    bool isSimulationStarted;
};

#endif // MAINWINDOW_H
