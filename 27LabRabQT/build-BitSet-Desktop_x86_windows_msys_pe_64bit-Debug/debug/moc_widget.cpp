/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../BitSet/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[16];
    char stringdata0[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 23), // "on_enter_button_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 28), // "on_button_get_string_clicked"
QT_MOC_LITERAL(4, 61, 27), // "on_button_get_ULong_clicked"
QT_MOC_LITERAL(5, 89, 31), // "on_button_get_ULongLong_clicked"
QT_MOC_LITERAL(6, 121, 25), // "on_button_get_bit_clicked"
QT_MOC_LITERAL(7, 147, 21), // "on_all_button_clicked"
QT_MOC_LITERAL(8, 169, 21), // "on_any_button_clicked"
QT_MOC_LITERAL(9, 191, 23), // "on_count_button_clicked"
QT_MOC_LITERAL(10, 215, 22), // "on_flip_button_clicked"
QT_MOC_LITERAL(11, 238, 22), // "on_none_button_clicked"
QT_MOC_LITERAL(12, 261, 23), // "on_reset_button_clicked"
QT_MOC_LITERAL(13, 285, 21), // "on_set_button_clicked"
QT_MOC_LITERAL(14, 307, 22), // "on_size_button_clicked"
QT_MOC_LITERAL(15, 330, 22) // "on_test_button_clicked"

    },
    "Widget\0on_enter_button_clicked\0\0"
    "on_button_get_string_clicked\0"
    "on_button_get_ULong_clicked\0"
    "on_button_get_ULongLong_clicked\0"
    "on_button_get_bit_clicked\0"
    "on_all_button_clicked\0on_any_button_clicked\0"
    "on_count_button_clicked\0on_flip_button_clicked\0"
    "on_none_button_clicked\0on_reset_button_clicked\0"
    "on_set_button_clicked\0on_size_button_clicked\0"
    "on_test_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_enter_button_clicked(); break;
        case 1: _t->on_button_get_string_clicked(); break;
        case 2: _t->on_button_get_ULong_clicked(); break;
        case 3: _t->on_button_get_ULongLong_clicked(); break;
        case 4: _t->on_button_get_bit_clicked(); break;
        case 5: _t->on_all_button_clicked(); break;
        case 6: _t->on_any_button_clicked(); break;
        case 7: _t->on_count_button_clicked(); break;
        case 8: _t->on_flip_button_clicked(); break;
        case 9: _t->on_none_button_clicked(); break;
        case 10: _t->on_reset_button_clicked(); break;
        case 11: _t->on_set_button_clicked(); break;
        case 12: _t->on_size_button_clicked(); break;
        case 13: _t->on_test_button_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
