/****************************************************************************
** Meta object code from reading C++ file 'AngularVelocity.h'
**
** Created: Tue Jun 3 00:01:35 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "AngularVelocity.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AngularVelocity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AngularVelocity[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      33,   16,   16,   16, 0x08,
      52,   16,   16,   16, 0x08,
      73,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AngularVelocity[] = {
    "AngularVelocity\0\0throwParticle()\0"
    "retrieveParticle()\0radiusChanged(float)\0"
    "angularVelocityChanged(float)\0"
};

void AngularVelocity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AngularVelocity *_t = static_cast<AngularVelocity *>(_o);
        switch (_id) {
        case 0: _t->throwParticle(); break;
        case 1: _t->retrieveParticle(); break;
        case 2: _t->radiusChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->angularVelocityChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AngularVelocity::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AngularVelocity::staticMetaObject = {
    { &GuiBase::staticMetaObject, qt_meta_stringdata_AngularVelocity,
      qt_meta_data_AngularVelocity, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AngularVelocity::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AngularVelocity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AngularVelocity::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AngularVelocity))
        return static_cast<void*>(const_cast< AngularVelocity*>(this));
    return GuiBase::qt_metacast(_clname);
}

int AngularVelocity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GuiBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
