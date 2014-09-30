TEMPLATE=app
TARGET = SailPlayer.Tests

#TARGETPATH = tests/$$TARGET
#target.path = $$TARGETPATH

#DEPLOYMENT_PATH = tests/$$TARGET

target.path = /tests/$$TARGET
INSTALLS += target

INCLUDEPATH += $$PWD/../include

SOURCES += \
    src/Main.cpp

HEADERS +=
