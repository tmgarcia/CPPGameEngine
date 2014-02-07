/****************************************************************************
** Meta object code from reading C++ file 'CoolGLWindow.h'
**
** Created: Thu Feb 6 01:43:05 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CoolGLWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CoolGLWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CoolGLWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      34,   25,   13,   13, 0x0a,
      59,   25,   13,   13, 0x0a,
      86,   25,   13,   13, 0x0a,
     112,   25,   13,   13, 0x0a,
     138,   25,   13,   13, 0x0a,
     166,   25,   13,   13, 0x0a,
     193,   25,   13,   13, 0x0a,
     218,   25,   13,   13, 0x0a,
     243,   25,   13,   13, 0x0a,
     268,   25,   13,   13, 0x0a,
     297,   25,   13,   13, 0x0a,
     324,   25,   13,   13, 0x0a,
     353,   25,   13,   13, 0x0a,
     381,   25,   13,   13, 0x0a,
     408,   25,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CoolGLWindow[] = {
    "CoolGLWindow\0\0myUpdate()\0newValue\0"
    "setObjectColorRed(float)\0"
    "setObjectColorGreen(float)\0"
    "setObjectColorBlue(float)\0"
    "setAmbientColorRed(float)\0"
    "setAmbientColorGreen(float)\0"
    "setAmbientColorBlue(float)\0"
    "setLightPositionX(float)\0"
    "setLightPositionY(float)\0"
    "setLightPositionZ(float)\0"
    "setDiffusionIntensity(float)\0"
    "setSpecularColorRed(float)\0"
    "setSpecularColorGreen(float)\0"
    "setSpecularColorBlue(float)\0"
    "setSpecularExponent(float)\0"
    "setApplyLighting(int)\0"
};

void CoolGLWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CoolGLWindow *_t = static_cast<CoolGLWindow *>(_o);
        switch (_id) {
        case 0: _t->myUpdate(); break;
        case 1: _t->setObjectColorRed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->setObjectColorGreen((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->setObjectColorBlue((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->setAmbientColorRed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->setAmbientColorGreen((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->setAmbientColorBlue((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->setLightPositionX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: _t->setLightPositionY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->setLightPositionZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->setDiffusionIntensity((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->setSpecularColorRed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->setSpecularColorGreen((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: _t->setSpecularColorBlue((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->setSpecularExponent((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 15: _t->setApplyLighting((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CoolGLWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CoolGLWindow::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_CoolGLWindow,
      qt_meta_data_CoolGLWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CoolGLWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CoolGLWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CoolGLWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CoolGLWindow))
        return static_cast<void*>(const_cast< CoolGLWindow*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int CoolGLWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
