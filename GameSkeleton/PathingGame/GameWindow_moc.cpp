/****************************************************************************
** Meta object code from reading C++ file 'GameWindow.h'
**
** Created: Mon May 5 10:30:34 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x0a,
      43,   12,   11,   11, 0x0a,
      75,   11,   11,   11, 0x0a,
      93,   11,   11,   11, 0x0a,
     117,   11,   11,   11, 0x0a,
     134,   11,   11,   11, 0x0a,
     161,  159,   11,   11, 0x0a,
     186,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameWindow[] = {
    "GameWindow\0\0e\0keyPressReaction(QKeyEvent*)\0"
    "mouseMoveReaction(QMouseEvent*)\0"
    "togglePathNodes()\0togglePathConnections()\0"
    "toggleAllNodes()\0toggleCameraPlayerView()\0"
    "s\0setCharacterSpeed(float)\0update()\0"
};

void GameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameWindow *_t = static_cast<GameWindow *>(_o);
        switch (_id) {
        case 0: _t->keyPressReaction((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseMoveReaction((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->togglePathNodes(); break;
        case 3: _t->togglePathConnections(); break;
        case 4: _t->toggleAllNodes(); break;
        case 5: _t->toggleCameraPlayerView(); break;
        case 6: _t->setCharacterSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->update(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameWindow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameWindow,
      qt_meta_data_GameWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow))
        return static_cast<void*>(const_cast< GameWindow*>(this));
    return QObject::qt_metacast(_clname);
}

int GameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
