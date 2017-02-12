TARGET = SailPlayer-dev

CONFIG += sailfishapp

SOURCES += src/SailPlayer.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    translations/*.ts

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

DISTFILES += \
    SailPlayer-dev.desktop \
    qml/SailPlayer-dev.qml \
    rpm/SailPlayer-dev.yaml
