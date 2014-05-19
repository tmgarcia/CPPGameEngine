/****************************************************************************
** Meta object code from reading C++ file 'MultipleSprings.h'
**
** Created: Mon May 19 11:46:09 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MultipleSprings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MultipleSprings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MultipleSprings[] = {

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
      42,   16,   16,   16, 0x08,
      71,   16,   16,   16, 0x08,
      93,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MultipleSprings[] = {
    "MultipleSprings\0\0restLengthChanged(float)\0"
    "springConstantChanged(float)\0"
    "gravityChanged(float)\0dampingChanged(float)\0"
};

void MultipleSprings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MultipleSprings *_t = static_cast<MultipleSprings *>(_o);
        switch (_id) {
        case 0: _t->restLengthChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->springConstantChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->gravityChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->dampingChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MultipleSprings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MultipleSprings::staticMetaObject = {
    { &GuiBase::staticMetaObject, qt_meta_stringdata_MultipleSprings,
      qt_meta_data_MultipleSprings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MultipleSprings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MultipleSprings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MultipleSprings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MultipleSprings))
        return static_cast<void*>(const_cast< MultipleSprings*>(this));
    return GuiBase::qt_metacast(_clname);
}

int MultipleSprings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
