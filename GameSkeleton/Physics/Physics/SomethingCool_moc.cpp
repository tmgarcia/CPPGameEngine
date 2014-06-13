/****************************************************************************
** Meta object code from reading C++ file 'SomethingCool.h'
**
** Created: Fri Jun 13 09:11:36 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SomethingCool.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SomethingCool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SomethingCool[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      24,   14,   14,   14, 0x08,
      32,   14,   14,   14, 0x08,
      47,   14,   14,   14, 0x08,
      69,   14,   14,   14, 0x08,
      97,   14,   14,   14, 0x08,
     126,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SomethingCool[] = {
    "SomethingCool\0\0splash()\0reset()\0"
    "resetSliders()\0dampingChanged(float)\0"
    "splashDampingChanged(float)\0"
    "waveMultiplierChanged(float)\0"
    "springConstantChanged(float)\0"
};

void SomethingCool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SomethingCool *_t = static_cast<SomethingCool *>(_o);
        switch (_id) {
        case 0: _t->splash(); break;
        case 1: _t->reset(); break;
        case 2: _t->resetSliders(); break;
        case 3: _t->dampingChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->splashDampingChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->waveMultiplierChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->springConstantChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SomethingCool::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SomethingCool::staticMetaObject = {
    { &GuiBase::staticMetaObject, qt_meta_stringdata_SomethingCool,
      qt_meta_data_SomethingCool, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SomethingCool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SomethingCool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SomethingCool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SomethingCool))
        return static_cast<void*>(const_cast< SomethingCool*>(this));
    return GuiBase::qt_metacast(_clname);
}

int SomethingCool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GuiBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
