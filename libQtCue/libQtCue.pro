include(../common.pri)

TEMPLATE = lib
TARGET = QtCue

CONFIG += plugin
QT += core

target.path = /usr/share/$${PACKAGE}/lib
INSTALLS += target

HEADERS += \
    CueSheetParser.hpp \
    CueSheetReader.hpp \
    CueSheet.hpp

SOURCES += \
    CueSheetParser.cpp \
    CueSheetReader.cpp \
    CueSheet.cpp
