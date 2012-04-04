/****************************************************************************
** Meta object code from reading C++ file 'simulation.h'
**
** Created: Wed Apr 4 13:04:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "simulation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Simulation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      32,   12,   11,   11, 0x05,
      51,   12,   11,   11, 0x05,
      69,   12,   11,   11, 0x05,
      89,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     139,  130,   11,   11, 0x0a,
     163,   11,   11,   11, 0x0a,
     197,   11,   11,   11, 0x0a,
     220,   11,   11,   11, 0x0a,
     241,   11,   11,   11, 0x0a,
     264,   11,   11,   11, 0x0a,
     282,   11,   11,   11, 0x0a,
     299,   11,   11,   11, 0x0a,
     317,   11,   11,   11, 0x0a,
     337,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Simulation[] = {
    "Simulation\0\0y\0drawInput(double)\0"
    "drawOutput(double)\0drawError(double)\0"
    "drawControl(double)\0"
    "setObjectsList(std::vector<std::string>)\0"
    "filename\0loadConfig(const char*)\0"
    "setSourceType(Source::SourceType)\0"
    "setSourceValue(double)\0setSamplingTime(int)\0"
    "setObject(std::string)\0startSimulation()\0"
    "stopSimulation()\0resetSimulation()\0"
    "stepSimulation(int)\0nextStep()\0"
};

const QMetaObject Simulation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Simulation,
      qt_meta_data_Simulation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Simulation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Simulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Simulation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Simulation))
        return static_cast<void*>(const_cast< Simulation*>(this));
    return QObject::qt_metacast(_clname);
}

int Simulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: drawInput((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: drawOutput((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: drawError((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: drawControl((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: setObjectsList((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 5: loadConfig((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 6: setSourceType((*reinterpret_cast< Source::SourceType(*)>(_a[1]))); break;
        case 7: setSourceValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: setSamplingTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: setObject((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 10: startSimulation(); break;
        case 11: stopSimulation(); break;
        case 12: resetSimulation(); break;
        case 13: stepSimulation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: nextStep(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Simulation::drawInput(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Simulation::drawOutput(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Simulation::drawError(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Simulation::drawControl(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Simulation::setObjectsList(std::vector<std::string> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
