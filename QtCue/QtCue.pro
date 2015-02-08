TEMPLATE = lib
TARGET = QtCue

#CONFIG += plugin
QT += core

target.path = /usr/share/QtCue/lib
INSTALLS += target

HEADERS += \
    CueSheetParser.hpp

SOURCES += \
    CueSheetParser.cpp
