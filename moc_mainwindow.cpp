/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Mar 28 11:49:09 2012
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
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      36,   11,   11,   11, 0x05,
      74,   11,   11,   11, 0x05,
      99,   11,   11,   11, 0x05,
     122,   11,   11,   11, 0x05,
     143,   11,   11,   11, 0x05,
     161,   11,   11,   11, 0x05,
     178,   11,   11,   11, 0x05,
     196,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     218,  216,   11,   11, 0x08,
     236,  216,   11,   11, 0x08,
     255,  216,   11,   11, 0x08,
     273,  216,   11,   11, 0x08,
     293,   11,   11,   11, 0x08,
     334,   11,   11,   11, 0x08,
     354,   11,   11,   11, 0x08,
     380,   11,   11,   11, 0x08,
     408,  402,   11,   11, 0x08,
     444,  402,   11,   11, 0x08,
     483,  478,   11,   11, 0x08,
     526,  518,   11,   11, 0x08,
     556,  518,   11,   11, 0x08,
     586,  518,   11,   11, 0x08,
     619,  518,   11,   11, 0x08,
     651,  518,   11,   11, 0x08,
     683,  518,   11,   11, 0x08,
     718,  478,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0loadConfig(const char*)\0"
    "setCoercionType(Coerce::CoercionType)\0"
    "setCoercionValue(double)\0"
    "setObject(std::string)\0setSamplingTime(int)\0"
    "startSimulation()\0stopSimulation()\0"
    "resetSimulation()\0stepSimulation(int)\0"
    "y\0drawInput(double)\0drawOutput(double)\0"
    "drawError(double)\0drawControl(double)\0"
    "setObjectsList(std::vector<std::string>)\0"
    "on_simBtn_clicked()\0on_getConfigBtn_clicked()\0"
    "on_resetBtn_clicked()\0value\0"
    "on_samplingSlider_valueChanged(int)\0"
    "on_coerceSilder_valueChanged(int)\0"
    "arg1\0on_coerceEdit_textChanged(QString)\0"
    "checked\0on_contSimRadio_toggled(bool)\0"
    "on_stepSimRadio_toggled(bool)\0"
    "on_stepCoerceRadio_toggled(bool)\0"
    "on_impCoerceRadio_toggled(bool)\0"
    "on_nonCoerceRadio_toggled(bool)\0"
    "on_manualCoerceRadio_toggled(bool)\0"
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
        case 1: setCoercionType((*reinterpret_cast< Coerce::CoercionType(*)>(_a[1]))); break;
        case 2: setCoercionValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: setObject((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: setSamplingTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: startSimulation(); break;
        case 6: stopSimulation(); break;
        case 7: resetSimulation(); break;
        case 8: stepSimulation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: drawInput((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: drawOutput((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: drawError((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: drawControl((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: setObjectsList((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 14: on_simBtn_clicked(); break;
        case 15: on_getConfigBtn_clicked(); break;
        case 16: on_resetBtn_clicked(); break;
        case 17: on_samplingSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: on_coerceSilder_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: on_coerceEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: on_contSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: on_stepSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: on_stepCoerceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: on_impCoerceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: on_nonCoerceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: on_manualCoerceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: on_comboBoxObject_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 27;
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
void MainWindow::setCoercionType(Coerce::CoercionType _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::setCoercionValue(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::setObject(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::setSamplingTime(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::startSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::stopSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MainWindow::resetSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MainWindow::stepSimulation(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
