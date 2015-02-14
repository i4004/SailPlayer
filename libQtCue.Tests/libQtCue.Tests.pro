TEMPLATE = app
TARGET = QtCue.Tests

#CONFIG += testcase
#QT += quick testlib qml quick

#LIBS += -L$$OUT_PWD/../libQtCue -lQtCue

#INCLUDEPATH += $$PWD/../libQtCue
INCLUDEPATH += $$PWD/../include

HEADERS += \
    CueSheetParserTests.hpp

SOURCES += \
    CueSheetParserTests.cpp \
    Main.cpp
