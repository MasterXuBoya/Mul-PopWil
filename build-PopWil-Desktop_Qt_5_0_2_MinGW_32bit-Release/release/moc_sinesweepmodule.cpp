/****************************************************************************
** Meta object code from reading C++ file 'sinesweepmodule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PopWil/sinesweepmodule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sinesweepmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SineSweepModule_t {
    QByteArrayData data[7];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SineSweepModule_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SineSweepModule_t qt_meta_stringdata_SineSweepModule = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 20),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 23),
QT_MOC_LITERAL(4, 62, 20),
QT_MOC_LITERAL(5, 83, 21),
QT_MOC_LITERAL(6, 105, 19)
    },
    "SineSweepModule\0on_btn_close_clicked\0"
    "\0on_btn_generate_clicked\0on_btn_clear_clicked\0"
    "on_checkBox_2_clicked\0on_checkBox_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SineSweepModule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08,
       3,    0,   40,    2, 0x08,
       4,    0,   41,    2, 0x08,
       5,    0,   42,    2, 0x08,
       6,    0,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SineSweepModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SineSweepModule *_t = static_cast<SineSweepModule *>(_o);
        switch (_id) {
        case 0: _t->on_btn_close_clicked(); break;
        case 1: _t->on_btn_generate_clicked(); break;
        case 2: _t->on_btn_clear_clicked(); break;
        case 3: _t->on_checkBox_2_clicked(); break;
        case 4: _t->on_checkBox_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SineSweepModule::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SineSweepModule.data,
      qt_meta_data_SineSweepModule,  qt_static_metacall, 0, 0}
};


const QMetaObject *SineSweepModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SineSweepModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SineSweepModule.stringdata))
        return static_cast<void*>(const_cast< SineSweepModule*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SineSweepModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
