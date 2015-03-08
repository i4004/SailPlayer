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
    src/Models/PlaylistModel.cpp \
    src/Audio/AudioResource.cpp \
    src/Audio/AudioPlayerBase.cpp \
    src/Audio/AudioPlayer.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/Main.qml \
    qml/Cover.qml \
    qml/Util.js \
    qml/pages/MainPage.qml \
    qml/controls/playlist/PlaylistItem.qml \
    qml/controls/playlist/PlaylistSectionHeader.qml

TRANSLATIONS += translations/harbour-sail-player-de.ts


INCLUDEPATH += $$PWD/include

HEADERS += \
    src/SailPlayerController.hpp \
    src/SailPlayerSettings.hpp \
    src/Playlist/Track.hpp \
    src/Playlist/PlaylistEnums.hpp \
    src/Models/PlaylistModelBase.hpp \
    src/Models/PlaylistModel.hpp \
    src/Audio/AudioPlayerEnums.hpp \
    src/Audio/GstEqualizerBandState.hpp \
    src/Audio/AudioResource.hpp \
    src/Audio/AudioPlayerBase.hpp \
    src/Audio/AudioPlayer.hpp
