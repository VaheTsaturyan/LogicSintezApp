/****************************************************************************
** Meta object code from reading C++ file 'graphicItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Application/inc/GUI/Components/graphicItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gui__AGraphicsItem_t {
    QByteArrayData data[7];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__AGraphicsItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__AGraphicsItem_t qt_meta_stringdata_gui__AGraphicsItem = {
    {
QT_MOC_LITERAL(0, 0, 18), // "gui::AGraphicsItem"
QT_MOC_LITERAL(1, 19, 12), // "scaleChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "scale"
QT_MOC_LITERAL(4, 39, 7), // "scaleUp"
QT_MOC_LITERAL(5, 47, 9), // "scaleDown"
QT_MOC_LITERAL(6, 57, 14) // "setCustomScale"

    },
    "gui::AGraphicsItem\0scaleChanged\0\0scale\0"
    "scaleUp\0scaleDown\0setCustomScale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__AGraphicsItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,    3,

       0        // eod
};

void gui::AGraphicsItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AGraphicsItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->scaleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->scaleUp(); break;
        case 2: _t->scaleDown(); break;
        case 3: _t->setCustomScale((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AGraphicsItem::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AGraphicsItem::scaleChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject gui::AGraphicsItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_gui__AGraphicsItem.data,
    qt_meta_data_gui__AGraphicsItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::AGraphicsItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::AGraphicsItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__AGraphicsItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int gui::AGraphicsItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void gui::AGraphicsItem::scaleChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_gui__AndGraphicsItem_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__AndGraphicsItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__AndGraphicsItem_t qt_meta_stringdata_gui__AndGraphicsItem = {
    {
QT_MOC_LITERAL(0, 0, 20) // "gui::AndGraphicsItem"

    },
    "gui::AndGraphicsItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__AndGraphicsItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void gui::AndGraphicsItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject gui::AndGraphicsItem::staticMetaObject = { {
    QMetaObject::SuperData::link<AGraphicsItem::staticMetaObject>(),
    qt_meta_stringdata_gui__AndGraphicsItem.data,
    qt_meta_data_gui__AndGraphicsItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::AndGraphicsItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::AndGraphicsItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__AndGraphicsItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return AGraphicsItem::qt_metacast(_clname);
}

int gui::AndGraphicsItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AGraphicsItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_gui__OrGraphicsItem_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__OrGraphicsItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__OrGraphicsItem_t qt_meta_stringdata_gui__OrGraphicsItem = {
    {
QT_MOC_LITERAL(0, 0, 19) // "gui::OrGraphicsItem"

    },
    "gui::OrGraphicsItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__OrGraphicsItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void gui::OrGraphicsItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject gui::OrGraphicsItem::staticMetaObject = { {
    QMetaObject::SuperData::link<AGraphicsItem::staticMetaObject>(),
    qt_meta_stringdata_gui__OrGraphicsItem.data,
    qt_meta_data_gui__OrGraphicsItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::OrGraphicsItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::OrGraphicsItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__OrGraphicsItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return AGraphicsItem::qt_metacast(_clname);
}

int gui::OrGraphicsItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AGraphicsItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_gui__NandGraphicsItem_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__NandGraphicsItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__NandGraphicsItem_t qt_meta_stringdata_gui__NandGraphicsItem = {
    {
QT_MOC_LITERAL(0, 0, 21) // "gui::NandGraphicsItem"

    },
    "gui::NandGraphicsItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__NandGraphicsItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void gui::NandGraphicsItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject gui::NandGraphicsItem::staticMetaObject = { {
    QMetaObject::SuperData::link<AGraphicsItem::staticMetaObject>(),
    qt_meta_stringdata_gui__NandGraphicsItem.data,
    qt_meta_data_gui__NandGraphicsItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::NandGraphicsItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::NandGraphicsItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__NandGraphicsItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return AGraphicsItem::qt_metacast(_clname);
}

int gui::NandGraphicsItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AGraphicsItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_gui__NorGraphicsItem_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__NorGraphicsItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__NorGraphicsItem_t qt_meta_stringdata_gui__NorGraphicsItem = {
    {
QT_MOC_LITERAL(0, 0, 20) // "gui::NorGraphicsItem"

    },
    "gui::NorGraphicsItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__NorGraphicsItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void gui::NorGraphicsItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject gui::NorGraphicsItem::staticMetaObject = { {
    QMetaObject::SuperData::link<AGraphicsItem::staticMetaObject>(),
    qt_meta_stringdata_gui__NorGraphicsItem.data,
    qt_meta_data_gui__NorGraphicsItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::NorGraphicsItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::NorGraphicsItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__NorGraphicsItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return AGraphicsItem::qt_metacast(_clname);
}

int gui::NorGraphicsItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AGraphicsItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_gui__NotGraphicsItem_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gui__NotGraphicsItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gui__NotGraphicsItem_t qt_meta_stringdata_gui__NotGraphicsItem = {
    {
QT_MOC_LITERAL(0, 0, 20) // "gui::NotGraphicsItem"

    },
    "gui::NotGraphicsItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gui__NotGraphicsItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void gui::NotGraphicsItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject gui::NotGraphicsItem::staticMetaObject = { {
    QMetaObject::SuperData::link<AGraphicsItem::staticMetaObject>(),
    qt_meta_stringdata_gui__NotGraphicsItem.data,
    qt_meta_data_gui__NotGraphicsItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gui::NotGraphicsItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::NotGraphicsItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gui__NotGraphicsItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return AGraphicsItem::qt_metacast(_clname);
}

int gui::NotGraphicsItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AGraphicsItem::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
