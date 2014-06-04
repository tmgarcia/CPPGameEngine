/****************************************************************************
** Meta object code from reading C++ file 'ChaslesTheorem.h'
**
** Created: Tue Jun 3 17:49:40 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChaslesTheorem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChaslesTheorem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChaslesTheorem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      32,   15,   15,   15, 0x08,
      48,   15,   15,   15, 0x08,
      71,   15,   15,   15, 0x08,
      92,   15,   15,   15, 0x08,
     122,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChaslesTheorem[] = {
    "ChaslesTheorem\0\0throwParticle()\0"
    "resetParticle()\0sameRadiusChanged(int)\0"
    "radiusChanged(float)\0angularVelocityChanged(float)\0"
    "throwSpeedChanged(float)\0"
};

void ChaslesTheorem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChaslesTheorem *_t = static_cast<ChaslesTheorem *>(_o);
        switch (_id) {
        case 0: _t->throwParticle(); break;
        case 1: _t->resetParticle(); break;
        case 2: _t->sameRadiusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->radiusChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->angularVelocityChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->throwSpeedChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChaslesTheorem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChaslesTheorem::staticMetaObject = {
    { &GuiBase::staticMetaObject, qt_meta_stringdata_ChaslesTheorem,
      qt_meta_data_ChaslesTheorem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChaslesTheorem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChaslesTheorem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChaslesTheorem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChaslesTheorem))
        return static_cast<void*>(const_cast< ChaslesTheorem*>(this));
    return GuiBase::qt_metacast(_clname);
}

int ChaslesTheorem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GuiBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
