/****************************************************************************
** Meta object code from reading C++ file 'GeneralGLWindow.h'
**
** Created: Mon Feb 17 00:34:20 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GeneralGLWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeneralGLWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeneralGLWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   17,   16,   16, 0x05,
      42,   17,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_GeneralGLWindow[] = {
    "GeneralGLWindow\0\0e\0keyPressed(QKeyEvent*)\0"
    "mouseMoved(QMouseEvent*)\0"
};

void GeneralGLWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GeneralGLWindow *_t = static_cast<GeneralGLWindow *>(_o);
        switch (_id) {
        case 0: _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GeneralGLWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GeneralGLWindow::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GeneralGLWindow,
      qt_meta_data_GeneralGLWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneralGLWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneralGLWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneralGLWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralGLWindow))
        return static_cast<void*>(const_cast< GeneralGLWindow*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GeneralGLWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GeneralGLWindow::keyPressed(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GeneralGLWindow::mouseMoved(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
