QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appframe.cpp \
    clipping.cpp \
    elementscombobox.cpp \
    genericobject.cpp \
    house.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    point.cpp \
    readobj.cpp \
    rectangle.cpp \
    rotation3d.cpp \
    scale3d.cpp \
    transformations3d.cpp \
    translation3d.cpp \
    window.cpp

HEADERS += \
    appframe.h \
    clipping.h \
    elementscombobox.h \
    genericobject.h \
    house.h \
    line.h \
    mainwindow.h \
    point.h \
    readobj.h \
    rectangle.h \
    rotation3d.h \
    scale3d.h \
    transformations3d.h \
    translation3d.h \
    window.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
