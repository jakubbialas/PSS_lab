/****************************************************************************
** Meta object code from reading C++ file 'liveplot.h'
**
** Created: Wed Apr 4 13:04:16 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "liveplot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'liveplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LivePlot[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x0a,
      61,   55,    9,    9, 0x0a,
      93,   91,    9,    9, 0x0a,
     124,    9,    9,    9, 0x0a,
     147,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LivePlot[] = {
    "LivePlot\0\0x,y,pen\0"
    "drawPoint(double,double,std::string)\0"
    "y,pen\0drawPoint(double,std::string)\0"
    ",\0addPen(std::string,QwtSymbol*)\0"
    "removePen(std::string)\0resetPen(std::string)\0"
};

const QMetaObject LivePlot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_LivePlot,
      qt_meta_data_LivePlot, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LivePlot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LivePlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LivePlot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LivePlot))
        return static_cast<void*>(const_cast< LivePlot*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int LivePlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: drawPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3]))); break;
        case 1: drawPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 2: addPen((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< QwtSymbol*(*)>(_a[2]))); break;
        case 3: removePen((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: resetPen((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
