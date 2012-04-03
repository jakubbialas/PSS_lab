/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
<<<<<<< HEAD
** Created: Wed Apr 4 14:23:28 2012
=======
** Created: Tue Apr 3 23:38:29 2012
>>>>>>> zmiana calej klasy source
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      36,   11,   11,   11, 0x05,
      59,   11,   11,   11, 0x05,
      85,   80,   11,   11, 0x05,
     119,  108,   11,   11, 0x05,
     162,   11,   11,   11, 0x05,
     181,   11,   11,   11, 0x05,
     214,  212,   11,   11, 0x05,
     257,   11,   11,   11, 0x05,
     275,   11,   11,   11, 0x05,
     293,   11,   11,   11, 0x05,
     310,   11,   11,   11, 0x05,
     328,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     350,  348,   11,   11, 0x08,
     368,  348,   11,   11, 0x08,
     387,  348,   11,   11, 0x08,
     405,  348,   11,   11, 0x08,
     425,   11,   11,   11, 0x08,
     466,   11,   11,   11, 0x08,
     486,   11,   11,   11, 0x08,
     512,   11,   11,   11, 0x08,
     540,  534,   11,   11, 0x08,
     584,  576,   11,   11, 0x08,
     614,  576,   11,   11, 0x08,
     649,  644,   11,   11, 0x08,
     696,  644,   11,   11, 0x08,
     737,  644,   11,   11, 0x08,
     785,   11,   11,   11, 0x08,
     819,   11,   11,   11, 0x08,
     856,  576,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0loadConfig(const char*)\0"
    "setObject(std::string)\0setSamplingTime(int)\0"
    "type\0addSource(std::string)\0name,value\0"
    "setLastSourceParameter(std::string,double)\0"
    "removeLastSource()\0setControllerType(std::string)\0"
    ",\0setControllerParameter(std::string,double)\0"
    "setFeedback(bool)\0startSimulation()\0"
    "stopSimulation()\0resetSimulation()\0"
    "stepSimulation(int)\0y\0drawInput(double)\0"
    "drawOutput(double)\0drawError(double)\0"
    "drawControl(double)\0"
    "setObjectsList(std::vector<std::string>)\0"
    "on_simBtn_clicked()\0on_getConfigBtn_clicked()\0"
    "on_resetBtn_clicked()\0value\0"
    "on_samplingSlider_valueChanged(int)\0"
    "checked\0on_contSimRadio_toggled(bool)\0"
    "on_stepSimRadio_toggled(bool)\0arg1\0"
    "on_comboBoxObject_currentIndexChanged(QString)\0"
    "on_comboBox_currentIndexChanged(QString)\0"
    "on_comboBox_source_currentIndexChanged(QString)\0"
    "on_pushButton_addSource_clicked()\0"
    "on_pushButton_removeSource_clicked()\0"
    "on_checkBox_feedback_toggled(bool)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadConfig((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 1: setObject((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: setSamplingTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: addSource((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: setLastSourceParameter((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: removeLastSource(); break;
        case 6: setControllerType((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 7: setControllerParameter((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: setFeedback((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: startSimulation(); break;
        case 10: stopSimulation(); break;
        case 11: resetSimulation(); break;
        case 12: stepSimulation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: drawInput((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: drawOutput((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: drawError((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: drawControl((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: setObjectsList((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 18: on_simBtn_clicked(); break;
        case 19: on_getConfigBtn_clicked(); break;
        case 20: on_resetBtn_clicked(); break;
        case 21: on_samplingSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: on_contSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: on_stepSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: on_comboBoxObject_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: on_comboBox_source_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: on_pushButton_addSource_clicked(); break;
        case 28: on_pushButton_removeSource_clicked(); break;
        case 29: on_checkBox_feedback_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::loadConfig(const char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::setObject(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::setSamplingTime(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::addSource(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::setLastSourceParameter(std::string _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::removeLastSource()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::setControllerType(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::setControllerParameter(std::string _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::setFeedback(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::startSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void MainWindow::stopSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void MainWindow::resetSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void MainWindow::stepSimulation(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE
