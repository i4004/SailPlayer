TEMPLATE=app
TARGET = harbour-sail-player

CONFIG += link_pkgconfig sailfishapp
QT += core quick qml xml
PKGCONFIG += gstreamer-1.0 glib-2.0 audioresource taglib

TARGETPATH = /usr/bin
target.path = $$TARGETPATH
DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH
desktop.path = /usr/share/applications
DEFINES += DEPLOYMENT_PATH=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"

SOURCES += \
    src/Main.cpp \
    src/SailPlayerController.cpp \
    src/SailPlayerSettings.cpp \
    src/Playlist/Track.cpp \
    src/Models/PlaylistModelBase.cpp \
    src/Models/PlaylistModel.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/Main.qml \
    qml/Cover.qml \
    qml/Util.js \
    qml/pages/MainPage.qml

TRANSLATIONS += translations/harbour-sail-player-de.ts


INCLUDEPATH += $$PWD/include

HEADERS += \
    src/SailPlayerController.hpp \
    src/SailPlayerSettings.hpp \
    src/Playlist/Track.hpp \
    src/Playlist/PlaylistEnums.hpp \
    src/Models/PlaylistModelBase.hpp \
    src/Models/PlaylistModel.hpp
