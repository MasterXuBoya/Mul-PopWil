/****************************************************************************
** Meta object code from reading C++ file 'qchartviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PopWil/qchartviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qchartviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QChartViewer_t {
    QByteArrayData data[14];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QChartViewer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QChartViewer_t qt_meta_stringdata_QChartViewer = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 15),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 7),
QT_MOC_LITERAL(4, 38, 12),
QT_MOC_LITERAL(5, 51, 5),
QT_MOC_LITERAL(6, 57, 9),
QT_MOC_LITERAL(7, 67, 10),
QT_MOC_LITERAL(8, 78, 12),
QT_MOC_LITERAL(9, 91, 14),
QT_MOC_LITERAL(10, 106, 15),
QT_MOC_LITERAL(11, 122, 7),
QT_MOC_LITERAL(12, 130, 17),
QT_MOC_LITERAL(13, 148, 18)
    },
    "QChartViewer\0viewPortChanged\0\0clicked\0"
    "QMouseEvent*\0event\0mouseMove\0mouseWheel\0"
    "QWheelEvent*\0mouseMoveChart\0mouseLeaveChart\0"
    "QEvent*\0mouseMovePlotArea\0mouseLeavePlotArea\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QChartViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x05,
       3,    1,   55,    2, 0x05,
       6,    1,   58,    2, 0x05,
       7,    1,   61,    2, 0x05,
       9,    1,   64,    2, 0x05,
      10,    1,   67,    2, 0x05,
      12,    1,   70,    2, 0x05,
      13,    1,   73,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 8,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 11,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 11,    5,

       0        // eod
};

void QChartViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QChartViewer *_t = static_cast<QChartViewer *>(_o);
        switch (_id) {
        case 0: _t->viewPortChanged(); break;
        case 1: _t->clicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseWheel((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseMoveChart((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->mouseLeaveChart((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseMovePlotArea((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseLeavePlotArea((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QChartViewer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QChartViewer::viewPortChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QChartViewer::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QChartViewer::clicked)) {
                *result = 1;
            }
        }
        {
            typedef void (QChartViewer::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QChartViewer::mouseMove)) {
                *result = 2;
            }
        }
        {
            typedef void (QChartViewer::*_t)(QWheelEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QChartViewer::mouseWheel)) {
                *result = 3;
            }
        }
        {
            typedef void (QChartViewer::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QChartViewer::mouseMoveChart)) {
                *result = 4;
            }
        }
        {
            typedef void (QChartViewer::*_t)(QEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QChartViewer::mouseLeaveChart)) {
                *result = 5;
            }
        }
        {
            typedef void (QChartViewer::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QChartViewer::mouseMovePlotArea)) {
                *result = 6;
            }
        }
        {
            typedef void (QChartViewer::*_t)(QEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QChartViewer::mouseLeavePlotArea)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject QChartViewer::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QChartViewer.data,
      qt_meta_data_QChartViewer,  qt_static_metacall, 0, 0}
};


const QMetaObject *QChartViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QChartViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QChartViewer.stringdata))
        return static_cast<void*>(const_cast< QChartViewer*>(this));
    if (!strcmp(_clname, "ViewPortManager"))
        return static_cast< ViewPortManager*>(const_cast< QChartViewer*>(this));
    return QLabel::qt_metacast(_clname);
}

int QChartViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QChartViewer::viewPortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QChartViewer::clicked(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QChartViewer::mouseMove(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QChartViewer::mouseWheel(QWheelEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QChartViewer::mouseMoveChart(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QChartViewer::mouseLeaveChart(QEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QChartViewer::mouseMovePlotArea(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QChartViewer::mouseLeavePlotArea(QEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
struct qt_meta_stringdata_QViewPortControl_t {
    QByteArrayData data[3];
    char stringdata[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QViewPortControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QViewPortControl_t qt_meta_stringdata_QViewPortControl = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 17),
QT_MOC_LITERAL(2, 35, 0)
    },
    "QViewPortControl\0onViewPortChanged\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QViewPortControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QViewPortControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QViewPortControl *_t = static_cast<QViewPortControl *>(_o);
        switch (_id) {
        case 0: _t->onViewPortChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QViewPortControl::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QViewPortControl.data,
      qt_meta_data_QViewPortControl,  qt_static_metacall, 0, 0}
};


const QMetaObject *QViewPortControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QViewPortControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QViewPortControl.stringdata))
        return static_cast<void*>(const_cast< QViewPortControl*>(this));
    if (!strcmp(_clname, "ViewPortControlBase"))
        return static_cast< ViewPortControlBase*>(const_cast< QViewPortControl*>(this));
    return QLabel::qt_metacast(_clname);
}

int QViewPortControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
