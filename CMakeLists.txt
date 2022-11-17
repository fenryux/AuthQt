cmake_minimum_required(VERSION 3.5)

project(AuthQt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(OpenSSL REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        user.h user.cpp
        userdao.h userdao.cpp
        mainwindow.h mainwindow.cpp mainwindow.ui
        authenticationform.h authenticationform.cpp authenticationform.ui
        signupform.h signupform.cpp signupform.ui
        userform.h userform.cpp userform.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AuthQt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(AuthQt SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(AuthQt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(AuthQt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(AuthQt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS AuthQt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AuthQt)
endif()
