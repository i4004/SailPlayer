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
PKGCONFIG += audioresource gstreamer-1.0

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

# Files

SOURCES += \
    src/Main.cpp \
    src/SailPlayerController.cpp \
    src/Audio/AudioResource.cpp \
    src/Audio/GstEqualizer.cpp \
    src/Audio/GstAudioPlayer.cpp \
    src/Audio/AudioPlayer.cpp \
    src/Audio/AudioPlayerBase.cpp

DISTFILES += \
    qml/pages/PlaylistPage.qml \
    qml/Cover.qml \
    qml/Main.qml \
    harbour-sail-player-dev.desktop

HEADERS += \
    src/SailPlayerController.hpp \
    src/Audio/AudioResource.hpp \
    src/Audio/GstEqualizerBandState.hpp \
    src/Audio/GstEequalizer.hpp \
    src/Audio/GstAudioPlayer.hpp \
    src/Audio/AudioPlayer.hpp \
    src/Audio/IAudioPlayer.hpp \
    src/Audio/AudioPlayerBase.hpp \
    src/Audio/AudioPlayerEnums.hpp
