/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "sendData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "vector<Mat>"
QT_MOC_LITERAL(4, 33, 6), // "images"
QT_MOC_LITERAL(5, 40, 11), // "vector<int>"
QT_MOC_LITERAL(6, 52, 6), // "labels"
QT_MOC_LITERAL(7, 59, 22), // "on_startButton_pressed"
QT_MOC_LITERAL(8, 82, 21), // "on_stopButton_pressed"
QT_MOC_LITERAL(9, 104, 20), // "on_trainFace_pressed"
QT_MOC_LITERAL(10, 125, 26), // "on_addPersonButton_pressed"
QT_MOC_LITERAL(11, 152, 29), // "on_faceDatabaseButton_pressed"
QT_MOC_LITERAL(12, 182, 29), // "on_controlPanelButton_pressed"
QT_MOC_LITERAL(13, 212, 22), // "on_aboutButton_pressed"
QT_MOC_LITERAL(14, 235, 9), // "showVideo"
QT_MOC_LITERAL(15, 245, 21), // "recieveDataFromFaceDB"
QT_MOC_LITERAL(16, 267, 19) // "recieveDataTraining"

    },
    "MainWindow\0sendData\0\0vector<Mat>\0"
    "images\0vector<int>\0labels\0"
    "on_startButton_pressed\0on_stopButton_pressed\0"
    "on_trainFace_pressed\0on_addPersonButton_pressed\0"
    "on_faceDatabaseButton_pressed\0"
    "on_controlPanelButton_pressed\0"
    "on_aboutButton_pressed\0showVideo\0"
    "recieveDataFromFaceDB\0recieveDataTraining"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x0a /* Public */,
      15,    2,   82,    2, 0x0a /* Public */,
      16,    2,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    2,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< vector<Mat>(*)>(_a[1])),(*reinterpret_cast< vector<int>(*)>(_a[2]))); break;
        case 1: _t->on_startButton_pressed(); break;
        case 2: _t->on_stopButton_pressed(); break;
        case 3: _t->on_trainFace_pressed(); break;
        case 4: _t->on_addPersonButton_pressed(); break;
        case 5: _t->on_faceDatabaseButton_pressed(); break;
        case 6: _t->on_controlPanelButton_pressed(); break;
        case 7: _t->on_aboutButton_pressed(); break;
        case 8: _t->showVideo(); break;
        case 9: _t->recieveDataFromFaceDB((*reinterpret_cast< vector<Mat>(*)>(_a[1])),(*reinterpret_cast< vector<int>(*)>(_a[2]))); break;
        case 10: _t->recieveDataTraining((*reinterpret_cast< vector<Mat>(*)>(_a[1])),(*reinterpret_cast< vector<int>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(vector<Mat> , vector<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendData(vector<Mat> _t1, vector<int> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
