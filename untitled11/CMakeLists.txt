cmake_minimum_required(VERSION 3.5)

project(untitled11 VERSION 0.1 LANGUAGES CXX)


set (CMAKE_PREFIX_PATH "D:\\other\\QT\\5.12.12\\mingw73_64\\")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(GLOB_RECURSE QRC_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})
set(QRC_SOURCE_FILES qrc.qrc)
SOURCE_GROUP("Resource Files" FILES ${QRC_SOURCE_FILES})

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
        mywidget.cpp
        mywidget.h
        mywidget.ui
        mylavel.cpp
        mylavel.h

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled11
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled11 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(untitled11 SHARED

            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(untitled11
            ${QRC_FILES}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(untitled11 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(untitled11 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled11)
endif()
