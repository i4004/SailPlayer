TEMPLATE = app
TARGET = QtCue.Tests

#CONFIG += testcase
#QT += quick testlib qml quick

#LIBS += -L$$OUT_PWD/../libQtCue -lQtCue

target.path = /opt/tests/libQtCue.Tests
INSTALLS += target

HEADERS += \
    CueSheetParserTests.hpp

SOURCES += \
    CueSheetParserTests.cpp \
    Main.cpp

INCLUDEPATH += $$PWD/../include
