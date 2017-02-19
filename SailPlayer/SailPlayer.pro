TARGET = harbour-sail-player-dev

# Paths

TARGETPATH = /usr/bin
target.path = $$TARGETPATH
DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH
desktop.path = /usr/share/applications

# Configuration

CONFIG += sailfishapp
QT += core quick qml
PKGCONFIG += audioresource

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

# Files

SOURCES += \
    src/Main.cpp \
    src/SailPlayerController.cpp \
    src/Audio/AudioResource.cpp

DISTFILES += \
    qml/pages/PlaylistPage.qml \
    qml/Cover.qml \
    qml/Main.qml \
    harbour-sail-player-dev.desktop

HEADERS += \
    src/SailPlayerController.hpp \
    src/Audio/AudioResource.hpp
