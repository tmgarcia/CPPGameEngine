/****************************************************************************
** Meta object code from reading C++ file 'ClickBoxComponent.h'
**
** Created: Tue Oct 21 01:58:49 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ClickBoxComponent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClickBoxComponent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClickBoxComponent[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      33,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   48,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClickBoxComponent[] = {
    "ClickBoxComponent\0\0LeftClicked()\0"
    "RightClicked()\0e\0mouseClickReaction(QMouseEvent*)\0"
};

void ClickBoxComponent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClickBoxComponent *_t = static_cast<ClickBoxComponent *>(_o);
        switch (_id) {
        case 0: _t->LeftClicked(); break;
        case 1: _t->RightClicked(); break;
        case 2: _t->mouseClickReaction((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClickBoxComponent::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClickBoxComponent::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClickBoxComponent,
      qt_meta_data_ClickBoxComponent, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClickBoxComponent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClickBoxComponent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClickBoxComponent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClickBoxComponent))
        return static_cast<void*>(const_cast< ClickBoxComponent*>(this));
    if (!strcmp(_clname, "Component"))
        return static_cast< Component*>(const_cast< ClickBoxComponent*>(this));
    return QObject::qt_metacast(_clname);
}

int ClickBoxComponent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ClickBoxComponent::LeftClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ClickBoxComponent::RightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
