/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Apr 4 13:04:15 2012
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
      59,   11,   11,   11, 0x05,
      80,   11,   11,   11, 0x05,
     114,   11,   11,   11, 0x05,
     137,   11,   11,   11, 0x05,
     155,   11,   11,   11, 0x05,
     172,   11,   11,   11, 0x05,
     190,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     212,  210,   11,   11, 0x08,
     230,  210,   11,   11, 0x08,
     249,  210,   11,   11, 0x08,
     267,  210,   11,   11, 0x08,
     287,   11,   11,   11, 0x08,
     328,   11,   11,   11, 0x08,
     348,   11,   11,   11, 0x08,
     374,   11,   11,   11, 0x08,
     402,  396,   11,   11, 0x08,
     446,  438,   11,   11, 0x08,
     476,  438,   11,   11, 0x08,
     511,  506,   11,   11, 0x08,
     558,  438,   11,   11, 0x08,
     591,  438,   11,   11, 0x08,
     623,  438,   11,   11, 0x08,
     655,  438,   11,   11, 0x08,
     690,  506,   11,   11, 0x08,
     730,  396,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0loadConfig(const char*)\0"
    "setObject(std::string)\0setSamplingTime(int)\0"
    "setSourceType(Source::SourceType)\0"
    "setSourceValue(double)\0startSimulation()\0"
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
    "on_stepSourceRadio_toggled(bool)\0"
    "on_impSourceRadio_toggled(bool)\0"
    "on_nonSourceRadio_toggled(bool)\0"
    "on_manualSourceRadio_toggled(bool)\0"
    "on_sourceValueEdit_textChanged(QString)\0"
    "on_sourceValueSilder_valueChanged(int)\0"
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
        case 3: setSourceType((*reinterpret_cast< Source::SourceType(*)>(_a[1]))); break;
        case 4: setSourceValue((*reinterpret_cast< double(*)>(_a[1]))); break;
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
        case 18: on_contSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: on_stepSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: on_comboBoxObject_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: on_stepSourceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: on_impSourceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: on_nonSourceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: on_manualSourceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: on_sourceValueEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: on_sourceValueSilder_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
void MainWindow::setSourceType(Source::SourceType _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::setSourceValue(double _t1)
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
