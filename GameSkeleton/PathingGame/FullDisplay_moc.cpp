/****************************************************************************
** Meta object code from reading C++ file 'FullDisplay.h'
**
** Created: Sun Apr 27 23:46:37 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FullDisplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FullDisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FullDisplay[] = {

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
      13,   12,   12,   12, 0x08,
      23,   12,   12,   12, 0x08,
      35,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FullDisplay[] = {
    "FullDisplay\0\0loadObj()\0loadLevel()\0"
    "startCharacter()\0"
};

void FullDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FullDisplay *_t = static_cast<FullDisplay *>(_o);
        switch (_id) {
        case 0: _t->loadObj(); break;
        case 1: _t->loadLevel(); break;
        case 2: _t->startCharacter(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FullDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FullDisplay::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FullDisplay,
      qt_meta_data_FullDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FullDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FullDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FullDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FullDisplay))
        return static_cast<void*>(const_cast< FullDisplay*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FullDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
