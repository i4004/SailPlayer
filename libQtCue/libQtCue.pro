include(../common.pri)

TEMPLATE = lib
TARGET = QtCue

CONFIG += plugin
QT += core

target.path = /usr/share/$${PACKAGE}/lib
INSTALLS += target

HEADERS += \
    CueSheetParser.hpp

SOURCES += \
    CueSheetParser.cpp
