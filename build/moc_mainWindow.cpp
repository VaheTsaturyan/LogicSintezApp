/****************************************************************************
** Meta object code from reading C++ file 'mainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Application/inc/GUI/mainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gui__MainWindow_t {
    QByteArrayData data[11];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__MainWindow_t qt_meta_stringdata_gui__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "gui::MainWindow"
QT_MOC_LITERAL(1, 16, 7), // "newFile"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "openFile"
QT_MOC_LITERAL(4, 34, 8), // "saveFile"
QT_MOC_LITERAL(5, 43, 16), // "addProjectDialog"
QT_MOC_LITERAL(6, 60, 5), // "zoomH"
QT_MOC_LITERAL(7, 66, 9), // "eventName"
QT_MOC_LITERAL(8, 76, 12), // "addLogicGate"
QT_MOC_LITERAL(9, 89, 8), // "gateType"
QT_MOC_LITERAL(10, 98, 21) // "updateUndoRedoActions"

    },
    "gui::MainWindow\0newFile\0\0openFile\0"
    "saveFile\0addProjectDialog\0zoomH\0"
    "eventName\0addLogicGate\0gateType\0"
    "updateUndoRedoActions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void gui::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newFile(); break;
        case 1: _t->openFile(); break;
        case 2: _t->saveFile(); break;
        case 3: _t->addProjectDialog(); break;
        case 4: _t->zoomH((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->addLogicGate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->updateUndoRedoActions(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject gui::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_gui__MainWindow.data,
    qt_meta_data_gui__MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int gui::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
