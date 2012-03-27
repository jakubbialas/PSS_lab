/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Mar 27 16:52:07 2012
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
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      46,   38,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     122,   38,   11,   11, 0x08,
     162,  157,   11,   11, 0x08,
     203,  197,   11,   11, 0x08,
     237,   38,   11,   11, 0x08,
     267,  197,   11,   11, 0x08,
     303,   38,   11,   11, 0x08,
     336,   11,   11,   11, 0x08,
     365,   11,   11,   11, 0x08,
     393,   11,   11,   11, 0x08,
     423,   11,   11,   11, 0x08,
     454,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_stepSimRadio_clicked()\0"
    "checked\0on_stepSimRadio_toggled(bool)\0"
    "on_simBtn_clicked()\0on_getConfigBtn_clicked()\0"
    "on_manualCoerceRadio_toggled(bool)\0"
    "arg1\0on_coerceEdit_textChanged(QString)\0"
    "value\0on_coerceSilder_valueChanged(int)\0"
    "on_contSimRadio_toggled(bool)\0"
    "on_samplingSlider_valueChanged(int)\0"
    "on_stepCoerceRadio_toggled(bool)\0"
    "on_stepCoerceRadio_clicked()\0"
    "on_impCoerceRadio_clicked()\0"
    "on_nonCoercionRadio_clicked()\0"
    "on_manualCoerceRadio_clicked()\0"
    "addingNewPoint()\0"
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
        case 0: on_stepSimRadio_clicked(); break;
        case 1: on_stepSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_simBtn_clicked(); break;
        case 3: on_getConfigBtn_clicked(); break;
        case 4: on_manualCoerceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: on_coerceEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: on_coerceSilder_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_contSimRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: on_samplingSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_stepCoerceRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: on_stepCoerceRadio_clicked(); break;
        case 11: on_impCoerceRadio_clicked(); break;
        case 12: on_nonCoercionRadio_clicked(); break;
        case 13: on_manualCoerceRadio_clicked(); break;
        case 14: addingNewPoint(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
