/****************************************************************************
** Meta object code from reading C++ file 'LevelDisplay.h'
**
** Created: Mon May 5 01:41:10 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "LevelDisplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LevelDisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LevelDisplay[] = {

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
      16,   14,   13,   13, 0x0a,
      45,   14,   13,   13, 0x0a,
      77,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LevelDisplay[] = {
    "LevelDisplay\0\0e\0keyPressReaction(QKeyEvent*)\0"
    "mouseMoveReaction(QMouseEvent*)\0"
    "mouseClickReaction(QMouseEvent*)\0"
};

void LevelDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LevelDisplay *_t = static_cast<LevelDisplay *>(_o);
        switch (_id) {
        case 0: _t->keyPressReaction((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseMoveReaction((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseClickReaction((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LevelDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LevelDisplay::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LevelDisplay,
      qt_meta_data_LevelDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LevelDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LevelDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LevelDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LevelDisplay))
        return static_cast<void*>(const_cast< LevelDisplay*>(this));
    return QObject::qt_metacast(_clname);
}

int LevelDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
