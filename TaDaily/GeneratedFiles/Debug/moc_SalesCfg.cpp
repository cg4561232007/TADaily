/****************************************************************************
** Meta object code from reading C++ file 'SalesCfg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SalesCfg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SalesCfg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SalesCfg_t {
    QByteArrayData data[7];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SalesCfg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SalesCfg_t qt_meta_stringdata_SalesCfg = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SalesCfg"
QT_MOC_LITERAL(1, 9, 11), // "add_tb_item"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "fromAdd"
QT_MOC_LITERAL(4, 30, 5), // "toAdd"
QT_MOC_LITERAL(5, 36, 8), // "configue"
QT_MOC_LITERAL(6, 45, 7) // "setInfo"

    },
    "SalesCfg\0add_tb_item\0\0fromAdd\0toAdd\0"
    "configue\0setInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SalesCfg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x08 /* Private */,
       4,    0,   43,    2, 0x08 /* Private */,
       5,    0,   44,    2, 0x08 /* Private */,
       6,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,

       0        // eod
};

void SalesCfg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SalesCfg *_t = static_cast<SalesCfg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add_tb_item((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->fromAdd(); break;
        case 2: _t->toAdd(); break;
        case 3: _t->configue(); break;
        case 4: _t->setInfo((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SalesCfg::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SalesCfg::add_tb_item)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SalesCfg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SalesCfg.data,
      qt_meta_data_SalesCfg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SalesCfg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SalesCfg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SalesCfg.stringdata0))
        return static_cast<void*>(const_cast< SalesCfg*>(this));
    return QWidget::qt_metacast(_clname);
}

int SalesCfg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SalesCfg::add_tb_item(const QStringList & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
