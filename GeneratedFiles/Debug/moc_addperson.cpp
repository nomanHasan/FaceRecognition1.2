/****************************************************************************
** Meta object code from reading C++ file 'addperson.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../addperson.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addperson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddPerson_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddPerson_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddPerson_t qt_meta_stringdata_AddPerson = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AddPerson"
QT_MOC_LITERAL(1, 10, 8), // "sendData"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "vector<Mat>"
QT_MOC_LITERAL(4, 32, 6), // "images"
QT_MOC_LITERAL(5, 39, 11), // "vector<int>"
QT_MOC_LITERAL(6, 51, 6), // "labels"
QT_MOC_LITERAL(7, 58, 22), // "on_startButton_pressed"
QT_MOC_LITERAL(8, 81, 21), // "on_stopButton_pressed"
QT_MOC_LITERAL(9, 103, 9) // "showVideo"

    },
    "AddPerson\0sendData\0\0vector<Mat>\0images\0"
    "vector<int>\0labels\0on_startButton_pressed\0"
    "on_stopButton_pressed\0showVideo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddPerson[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   39,    2, 0x08 /* Private */,
       8,    0,   40,    2, 0x08 /* Private */,
       9,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddPerson::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddPerson *_t = static_cast<AddPerson *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< vector<Mat>(*)>(_a[1])),(*reinterpret_cast< vector<int>(*)>(_a[2]))); break;
        case 1: _t->on_startButton_pressed(); break;
        case 2: _t->on_stopButton_pressed(); break;
        case 3: _t->showVideo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddPerson::*_t)(vector<Mat> , vector<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddPerson::sendData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AddPerson::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddPerson.data,
      qt_meta_data_AddPerson,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddPerson::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddPerson::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddPerson.stringdata0))
        return static_cast<void*>(const_cast< AddPerson*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddPerson::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddPerson::sendData(vector<Mat> _t1, vector<int> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
