cmake_minimum_required(VERSION 3.5)

project(XMLParser VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

MESSAGE(STATUS "This is QT_VERSION_MAJOR " ${QT_VERSION_MAJOR})
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Xml)

#set(PROJECT_SOURCES
#        main.cpp
#        MainWindow.cpp
#        MainWindow.h
#        MainWindow.ui
#        BaseStruct.h
#)
set(PROJECT_SOURCES
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        BaseStruct.h
)

set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(XMLParser
#        MANUAL_FINALIZATION
#        ${PROJECT_SOURCES}
#    )
    qt_add_library(XMLParser 
        STATIC
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET XMLParser APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(XMLParser SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(XMLParser
            ${PROJECT_SOURCES}
            config.qrc
        )
    endif()
endif()

target_link_libraries(XMLParser PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(XMLParser PRIVATE Qt${QT_VERSION_MAJOR}::Xml)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.7.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.XMLParser)
endif()
#set_target_properties(XMLParser PROPERTIES
#    ${BUNDLE_ID_OPTION}
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#    MACOSX_BUNDLE TRUE
#    WIN32_EXECUTABLE TRUE
#)
#
#include(GNUInstallDirs)
#install(TARGETS XMLParser
#    BUNDLE DESTINATION .
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(XMLParser)
endif()
