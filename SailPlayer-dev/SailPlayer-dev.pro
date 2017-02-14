TARGET = SailPlayer-dev

# Paths

TARGETPATH = /usr/bin
target.path = $$TARGETPATH
DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH
desktop.path = /usr/share/applications

# Configuration
CONFIG += sailfishapp

# Files

SOURCES += src/SailPlayer.cpp

OTHER_FILES += \
    qml/Cover.qml \
    qml/SailPlayer-dev.qml \
    qml/pages/FirstPage.qml \
    SailPlayer-dev.desktop

# Icons
SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256
