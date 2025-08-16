cmake_minimum_required(VERSION 3.16)

project(UnmannedTestingSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
# 找到 Qt Charts 组件
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts)

    qt_add_executable(UnmannedTestingSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        UnitManageWindow.h UnitManageWindow.cpp UnitManageWindow.ui
        UnitDialog.h UnitDialog.cpp UnitDialog.ui
        DBUtil.h DBUtil.cpp
        config.ini
        ControlStationManageWindow.h ControlStationManageWindow.cpp ControlStationManageWindow.ui
        ControlStationDialog.h ControlStationDialog.cpp
        ControlStationDialog.h ControlStationDialog.cpp ControlStationDialog.ui
        ProtocolManageWindow.h ProtocolManageWindow.cpp ProtocolManageWindow.ui
        ProtocolDialog.h ProtocolDialog.cpp
        ProtocolDialog.h ProtocolDialog.cpp ProtocolDialog.ui
        MessageFormatDialog.h MessageFormatDialog.cpp MessageFormatDialog.ui
        InstructionManageWindow.h InstructionManageWindow.cpp InstructionManageWindow.ui
        InstructionDialog.h InstructionDialog.cpp InstructionDialog.ui
        TestManageWindow.h TestManageWindow.cpp TestManageWindow.ui
        NewTaskWithItemsDialog.h NewTaskWithItemsDialog.cpp NewTaskWithItemsDialog.ui
        TaskDetailWindow.h TaskDetailWindow.cpp TaskDetailWindow.ui
        UserManageWindow.h UserManageWindow.cpp UserManageWindow.ui
        SystemManageWindow.h SystemManageWindow.cpp SystemManageWindow.ui
        UserManageWindow.h UserManageWindow.cpp UserManageWindow.ui
        UserDialog.h UserDialog.cpp UserDialog.ui
        OrgManageWindow.h OrgManageWindow.cpp OrgManageWindow.ui
        PermissionManageWindow.h PermissionManageWindow.cpp PermissionManageWindow.ui
        NewTaskWithItemsDialog.cpp
        NewTaskWithItemsDialog.h
        NewTaskWithItemsDialog.ui
        UserManageWindow.cpp
        TestResultsAnalysisWindow.h TestResultsAnalysisWindow.cpp TestResultsAnalysisWindow.ui
        DataDicWindow.h DataDicWindow.cpp DataDicWindow.ui
        DataDicDialog.h DataDicDialog.cpp DataDicDialog.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET UnmannedTestingSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(UnmannedTestingSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(UnmannedTestingSystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(UnmannedTestingSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(UnmannedTestingSystem PRIVATE Qt6::Core)
target_link_libraries(UnmannedTestingSystem PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Charts
)
target_link_libraries(UnmannedTestingSystem PRIVATE Qt6::Widgets)
target_link_libraries(UnmannedTestingSystem PRIVATE Qt6::Widgets)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.UnmannedTestingSystem)
endif()
set_target_properties(UnmannedTestingSystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS UnmannedTestingSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UnmannedTestingSystem)
endif()
