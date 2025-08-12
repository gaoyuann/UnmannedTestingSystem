/****************************************************************************
** Meta object code from reading C++ file 'InstructionManageWindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../InstructionManageWindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InstructionManageWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN23InstructionManageWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto InstructionManageWindow::qt_create_metaobjectdata<qt_meta_tag_ZN23InstructionManageWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "InstructionManageWindow",
        "statusMessageRequested",
        "",
        "message",
        "timeout",
        "onAdd",
        "onEdit",
        "onDelete",
        "onSearch",
        "onProtocolFilterChanged",
        "index",
        "onPageChanged",
        "onPageSizeChanged",
        "gotoFirstPage",
        "gotoPrevPage",
        "gotoNextPage",
        "gotoLastPage"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'statusMessageRequested'
        QtMocHelpers::SignalData<void(const QString &, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Int, 4 },
        }}),
        // Signal 'statusMessageRequested'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'onAdd'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onEdit'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onDelete'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSearch'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onProtocolFilterChanged'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'onPageChanged'
        QtMocHelpers::SlotData<void(int)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'onPageSizeChanged'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'gotoFirstPage'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'gotoPrevPage'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'gotoNextPage'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'gotoLastPage'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<InstructionManageWindow, qt_meta_tag_ZN23InstructionManageWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject InstructionManageWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23InstructionManageWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23InstructionManageWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23InstructionManageWindowE_t>.metaTypes,
    nullptr
} };

void InstructionManageWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<InstructionManageWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->statusMessageRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->statusMessageRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->onAdd(); break;
        case 3: _t->onEdit(); break;
        case 4: _t->onDelete(); break;
        case 5: _t->onSearch(); break;
        case 6: _t->onProtocolFilterChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->onPageChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->onPageSizeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->gotoFirstPage(); break;
        case 10: _t->gotoPrevPage(); break;
        case 11: _t->gotoNextPage(); break;
        case 12: _t->gotoLastPage(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (InstructionManageWindow::*)(const QString & , int )>(_a, &InstructionManageWindow::statusMessageRequested, 0))
            return;
    }
}

const QMetaObject *InstructionManageWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InstructionManageWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23InstructionManageWindowE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InstructionManageWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void InstructionManageWindow::statusMessageRequested(const QString & _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}
QT_WARNING_POP
