/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Set/widget.h"
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
    QByteArrayData data[19];
    char stringdata0[468];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 29), // "on_eraze_range_button_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "on_eraze_button_clicked"
QT_MOC_LITERAL(4, 62, 24), // "on_insert_button_clicked"
QT_MOC_LITERAL(5, 87, 22), // "on_find_button_clicked"
QT_MOC_LITERAL(6, 110, 26), // "on_find_min_button_clicked"
QT_MOC_LITERAL(7, 137, 30), // "on_find_min_rec_button_clicked"
QT_MOC_LITERAL(8, 168, 26), // "on_find_max_button_clicked"
QT_MOC_LITERAL(9, 195, 30), // "on_find_max_rec_button_clicked"
QT_MOC_LITERAL(10, 226, 23), // "on_clear_button_clicked"
QT_MOC_LITERAL(11, 250, 28), // "on_pre_travel_button_clicked"
QT_MOC_LITERAL(12, 279, 27), // "on_in_travel_button_clicked"
QT_MOC_LITERAL(13, 307, 28), // "on_pos_travel_button_clicked"
QT_MOC_LITERAL(14, 336, 28), // "on_change_dir_button_clicked"
QT_MOC_LITERAL(15, 365, 26), // "on_button_iterator_clicked"
QT_MOC_LITERAL(16, 392, 23), // "on_rcons_button_clicked"
QT_MOC_LITERAL(17, 416, 24), // "on_findLB_button_clicked"
QT_MOC_LITERAL(18, 441, 26) // "on_FindUB_button_2_clicked"

    },
    "Widget\0on_eraze_range_button_clicked\0"
    "\0on_eraze_button_clicked\0"
    "on_insert_button_clicked\0"
    "on_find_button_clicked\0"
    "on_find_min_button_clicked\0"
    "on_find_min_rec_button_clicked\0"
    "on_find_max_button_clicked\0"
    "on_find_max_rec_button_clicked\0"
    "on_clear_button_clicked\0"
    "on_pre_travel_button_clicked\0"
    "on_in_travel_button_clicked\0"
    "on_pos_travel_button_clicked\0"
    "on_change_dir_button_clicked\0"
    "on_button_iterator_clicked\0"
    "on_rcons_button_clicked\0"
    "on_findLB_button_clicked\0"
    "on_FindUB_button_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

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
        case 0: _t->on_eraze_range_button_clicked(); break;
        case 1: _t->on_eraze_button_clicked(); break;
        case 2: _t->on_insert_button_clicked(); break;
        case 3: _t->on_find_button_clicked(); break;
        case 4: _t->on_find_min_button_clicked(); break;
        case 5: _t->on_find_min_rec_button_clicked(); break;
        case 6: _t->on_find_max_button_clicked(); break;
        case 7: _t->on_find_max_rec_button_clicked(); break;
        case 8: _t->on_clear_button_clicked(); break;
        case 9: _t->on_pre_travel_button_clicked(); break;
        case 10: _t->on_in_travel_button_clicked(); break;
        case 11: _t->on_pos_travel_button_clicked(); break;
        case 12: _t->on_change_dir_button_clicked(); break;
        case 13: _t->on_button_iterator_clicked(); break;
        case 14: _t->on_rcons_button_clicked(); break;
        case 15: _t->on_findLB_button_clicked(); break;
        case 16: _t->on_FindUB_button_2_clicked(); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
