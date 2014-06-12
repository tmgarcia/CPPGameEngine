/****************************************************************************
** Meta object code from reading C++ file 'TorqueSquare.h'
**
** Created: Thu Jun 12 03:04:50 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TorqueSquare.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TorqueSquare.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TorqueSquare[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      43,   13,   13,   13, 0x08,
      65,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TorqueSquare[] = {
    "TorqueSquare\0\0springConstantChanged(float)\0"
    "dampingChanged(float)\0reset()\0"
};

void TorqueSquare::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TorqueSquare *_t = static_cast<TorqueSquare *>(_o);
        switch (_id) {
        case 0: _t->springConstantChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->dampingChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->reset(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TorqueSquare::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TorqueSquare::staticMetaObject = {
    { &GuiBase::staticMetaObject, qt_meta_stringdata_TorqueSquare,
      qt_meta_data_TorqueSquare, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TorqueSquare::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TorqueSquare::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TorqueSquare::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TorqueSquare))
        return static_cast<void*>(const_cast< TorqueSquare*>(this));
    return GuiBase::qt_metacast(_clname);
}

int TorqueSquare::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GuiBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
