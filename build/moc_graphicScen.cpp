/****************************************************************************
** Meta object code from reading C++ file 'graphicScen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Application/inc/GUI/Components/graphicScen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicScen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gui__CustomGraphicsScene_t {
    QByteArrayData data[8];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__CustomGraphicsScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__CustomGraphicsScene_t qt_meta_stringdata_gui__CustomGraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 24), // "gui::CustomGraphicsScene"
QT_MOC_LITERAL(1, 25, 15), // "addScalableItem"
QT_MOC_LITERAL(2, 41, 14), // "AGraphicsItem*"
QT_MOC_LITERAL(3, 56, 0), // ""
QT_MOC_LITERAL(4, 57, 17), // "addScalableItemAt"
QT_MOC_LITERAL(5, 75, 3), // "pos"
QT_MOC_LITERAL(6, 79, 15), // "scaleUpSelected"
QT_MOC_LITERAL(7, 95, 17) // "scaleDownSelected"

    },
    "gui::CustomGraphicsScene\0addScalableItem\0"
    "AGraphicsItem*\0\0addScalableItemAt\0pos\0"
    "scaleUpSelected\0scaleDownSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__CustomGraphicsScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    3, 0x0a /* Public */,
       4,    1,   35,    3, 0x0a /* Public */,
       6,    0,   38,    3, 0x0a /* Public */,
       7,    0,   39,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2, QMetaType::QPointF,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gui::CustomGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomGraphicsScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { AGraphicsItem* _r = _t->addScalableItem();
            if (_a[0]) *reinterpret_cast< AGraphicsItem**>(_a[0]) = std::move(_r); }  break;
        case 1: { AGraphicsItem* _r = _t->addScalableItemAt((*reinterpret_cast< const QPointF(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< AGraphicsItem**>(_a[0]) = std::move(_r); }  break;
        case 2: _t->scaleUpSelected(); break;
        case 3: _t->scaleDownSelected(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject gui::CustomGraphicsScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_gui__CustomGraphicsScene.data,
    qt_meta_data_gui__CustomGraphicsScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::CustomGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::CustomGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__CustomGraphicsScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int gui::CustomGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
