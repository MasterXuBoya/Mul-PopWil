/****************************************************************************
** Meta object code from reading C++ file 'performancetimer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PopWil/performancetimer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'performancetimer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PerformanceTimer_t {
    QByteArrayData data[6];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PerformanceTimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PerformanceTimer_t qt_meta_stringdata_PerformanceTimer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PerformanceTimer"
QT_MOC_LITERAL(1, 17, 7), // "timeout"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "start"
QT_MOC_LITERAL(4, 32, 12), // "timeInterval"
QT_MOC_LITERAL(5, 45, 4) // "stop"

    },
    "PerformanceTimer\0timeout\0\0start\0"
    "timeInterval\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PerformanceTimer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void PerformanceTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PerformanceTimer *_t = static_cast<PerformanceTimer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timeout(); break;
        case 1: _t->start((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PerformanceTimer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PerformanceTimer::timeout)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PerformanceTimer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PerformanceTimer.data,
      qt_meta_data_PerformanceTimer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PerformanceTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PerformanceTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PerformanceTimer.stringdata0))
        return static_cast<void*>(const_cast< PerformanceTimer*>(this));
    return QObject::qt_metacast(_clname);
}

int PerformanceTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PerformanceTimer::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
