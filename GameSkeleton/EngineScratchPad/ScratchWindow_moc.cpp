/****************************************************************************
** Meta object code from reading C++ file 'ScratchWindow.h'
**
** Created: Mon Aug 4 04:33:03 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ScratchWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScratchWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScratchWindow[] = {

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
      15,   14,   14,   14, 0x08,
      26,   24,   14,   14, 0x0a,
      55,   24,   14,   14, 0x0a,
      86,   24,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ScratchWindow[] = {
    "ScratchWindow\0\0update()\0e\0"
    "keyPressReaction(QKeyEvent*)\0"
    "keyReleaseReaction(QKeyEvent*)\0"
    "mouseMoveReaction(QMouseEvent*)\0"
};

void ScratchWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScratchWindow *_t = static_cast<ScratchWindow *>(_o);
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->keyPressReaction((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->keyReleaseReaction((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseMoveReaction((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ScratchWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ScratchWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ScratchWindow,
      qt_meta_data_ScratchWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScratchWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScratchWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScratchWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScratchWindow))
        return static_cast<void*>(const_cast< ScratchWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ScratchWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
