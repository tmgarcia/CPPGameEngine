/****************************************************************************
** Meta object code from reading C++ file 'OneDCollision.h'
**
** Created: Wed May 21 02:02:23 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "OneDCollision.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OneDCollision.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OneDCollision[] = {

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
      15,   14,   14,   14, 0x08,
      37,   14,   14,   14, 0x08,
      60,   14,   14,   14, 0x08,
      86,   14,   14,   14, 0x08,
     116,   14,   14,   14, 0x08,
     147,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OneDCollision[] = {
    "OneDCollision\0\0redMassChanged(float)\0"
    "blueMassChanged(float)\0restitutionChanged(float)\0"
    "redInitVelocityChanged(float)\0"
    "blueInitVelocityChanged(float)\0"
    "resetParticles()\0"
};

void OneDCollision::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OneDCollision *_t = static_cast<OneDCollision *>(_o);
        switch (_id) {
        case 0: _t->redMassChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->blueMassChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->restitutionChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->redInitVelocityChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->blueInitVelocityChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->resetParticles(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OneDCollision::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OneDCollision::staticMetaObject = {
    { &GuiBase::staticMetaObject, qt_meta_stringdata_OneDCollision,
      qt_meta_data_OneDCollision, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OneDCollision::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OneDCollision::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OneDCollision::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OneDCollision))
        return static_cast<void*>(const_cast< OneDCollision*>(this));
    return GuiBase::qt_metacast(_clname);
}

int OneDCollision::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
