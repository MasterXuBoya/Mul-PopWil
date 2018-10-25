/****************************************************************************
** Meta object code from reading C++ file 'myobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PopWil/myobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyObject_t {
    QByteArrayData data[11];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyObject_t qt_meta_stringdata_MyObject = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyObject"
QT_MOC_LITERAL(1, 9, 7), // "onClick"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 19), // "onMouseUsageChanged"
QT_MOC_LITERAL(4, 38, 10), // "mouseUsage"
QT_MOC_LITERAL(5, 49, 6), // "onSave"
QT_MOC_LITERAL(6, 56, 19), // "onMouseMovePlotArea"
QT_MOC_LITERAL(7, 76, 12), // "QMouseEvent*"
QT_MOC_LITERAL(8, 89, 5), // "event"
QT_MOC_LITERAL(9, 95, 18), // "onChartUpdateTimer"
QT_MOC_LITERAL(10, 114, 17) // "onViewPortChanged"

    },
    "MyObject\0onClick\0\0onMouseUsageChanged\0"
    "mouseUsage\0onSave\0onMouseMovePlotArea\0"
    "QMouseEvent*\0event\0onChartUpdateTimer\0"
    "onViewPortChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       6,    1,   51,    2, 0x0a /* Public */,
       9,    0,   54,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyObject *_t = static_cast<MyObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClick(); break;
        case 1: _t->onMouseUsageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onSave((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onMouseMovePlotArea((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->onChartUpdateTimer(); break;
        case 5: _t->onViewPortChanged(); break;
        default: ;
        }
    }
}

const QMetaObject MyObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyObject.data,
      qt_meta_data_MyObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyObject.stringdata0))
        return static_cast<void*>(const_cast< MyObject*>(this));
    return QObject::qt_metacast(_clname);
}

int MyObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
