/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Mar 28 22:14:12 2012
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
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      36,   11,   11,   11, 0x05,
      59,   11,   11,   11, 0x05,
      80,   11,   11,   11, 0x05,
      98,   11,   11,   11, 0x05,
     115,   11,   11,   11, 0x05,
     133,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     155,  153,   11,   11, 0x08,
     173,  153,   11,   11, 0x08,
     192,  153,   11,   11, 0x08,
     210,  153,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     271,   11,   11,   11, 0x08,
     291,   11,   11,   11, 0x08,
     317,   11,   11,   11, 0x08,
     345,  339,   11,   11, 0x08,
     389,  381,   11,   11, 0x08,
     419,  381,   11,   11, 0x08,
     454,  449,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0loadConfig(const char*)\0"
    "setObject(std::string)\0setSamplingTime(int)\0"
    "startSimulation()\0stopSimulation()\0"
    "resetSimulation()\0stepSimulation(int)\0"
    "y\0drawInput(double)\0drawOutput(double)\0"
    "drawError(double)\0drawControl(double)\0"
    "setObjectsList(std::vector<std::string>)\0"
    "on_simBtn_clicked()\0on_getConfigBtn_clicked()\0"
    "on_resetBtn_clicked()\0value\0"
    "on_samplingSlider_valueChanged(int)\0"
    "checked\0on_contSimRadio_toggled(bool)\0"
    "on_stepSimRadio_toggled(bool)\0arg1\0"
    "on_comboBoxObject_currentIndexChanged(QString)\0"
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
        case 3: startSimulation(); break;
        case 4: stopSimulation(); break;
        case 5: resetSimulation(); break;
        case 6: stepSimulation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: drawInput((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: drawOutput((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: drawError((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: drawControl((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: setObjectsList((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 12: on_simBtn_clicked(); break;
        case 13: on_getConfigBtn_clicked(); break;
        case 14: on_resetBtn_clicked(); break;
        case 15: on_samplingSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: on_contSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: on_stepSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: on_comboBoxObject_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 19;
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
void MainWindow::startSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::stopSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainWindow::resetSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::stepSimulation(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
