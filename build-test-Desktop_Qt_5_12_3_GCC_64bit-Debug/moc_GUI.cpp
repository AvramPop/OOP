/****************************************************************************
** Meta object code from reading C++ file 'GUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test/GUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUI_t {
    QByteArrayData data[8];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_t qt_meta_stringdata_GUI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "GUI"
QT_MOC_LITERAL(1, 4, 17), // "updateLabelSignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "newLine"
QT_MOC_LITERAL(4, 31, 22), // "launchMessageBoxSignal"
QT_MOC_LITERAL(5, 54, 3), // "str"
QT_MOC_LITERAL(6, 58, 15), // "updateLabelSlot"
QT_MOC_LITERAL(7, 74, 20) // "launchMessageBoxSlot"

    },
    "GUI\0updateLabelSignal\0\0newLine\0"
    "launchMessageBoxSignal\0str\0updateLabelSlot\0"
    "launchMessageBoxSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLabelSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->launchMessageBoxSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateLabelSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->launchMessageBoxSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::updateLabelSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GUI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUI::launchMessageBoxSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUI::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GUI.data,
    qt_meta_data_GUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void GUI::updateLabelSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GUI::launchMessageBoxSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
