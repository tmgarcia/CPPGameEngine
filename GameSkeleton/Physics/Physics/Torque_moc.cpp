/****************************************************************************
** Meta object code from reading C++ file 'Torque.h'
**
** Created: Fri Jun 6 22:14:38 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Torque.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Torque.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Torque[] = {

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
       8,    7,    7,    7, 0x08,
      24,    7,    7,    7, 0x08,
      47,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Torque[] = {
    "Torque\0\0resetParticle()\0sameRadiusChanged(int)\0"
    "radiusChanged(float)\0"
};

void Torque::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Torque *_t = static_cast<Torque *>(_o);
        switch (_id) {
        case 0: _t->resetParticle(); break;
        case 1: _t->sameRadiusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->radiusChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Torque::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Torque::staticMetaObject = {
    { &GuiBase::staticMetaObject, qt_meta_stringdata_Torque,
      qt_meta_data_Torque, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Torque::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Torque::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Torque::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Torque))
        return static_cast<void*>(const_cast< Torque*>(this));
    return GuiBase::qt_metacast(_clname);
}

int Torque::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
