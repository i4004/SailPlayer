TARGET = SailPlayer-dev

# Paths

TARGETPATH = /usr/bin
target.path = $$TARGETPATH
DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH
desktop.path = /usr/share/applications

# Configuration

CONFIG += sailfishapp
QT += core quick qml xml

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

# Files

SOURCES += src/SailPlayer.cpp

DISTFILES += \
    qml/pages/PlaylistPage.qml \
    qml/Cover.qml \
    SailPlayer-dev.desktop \
    qml/Main.qml
