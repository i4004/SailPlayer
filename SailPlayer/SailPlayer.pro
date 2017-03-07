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
    src/Audio/Gst/GEqualizer.cpp \
    src/Audio/AudioPlayer.cpp \
    src/Audio/AudioPlayerBase.cpp \
    src/Audio/Gst/GBus.cpp \
    src/Audio/Gst/GPipeline.cpp \
    src/Audio/Gst/GAudioPlayer.cpp \
    src/Audio/Gst/GInit.cpp \
    src/Audio/Gst/GAutoSink.cpp \
    src/Audio/Gst/GPlugins.cpp \
    src/Audio/Gst/GElement.cpp

DISTFILES += \
    qml/pages/PlaylistPage.qml \
    qml/Cover.qml \
    qml/Main.qml \
    harbour-sail-player-dev.desktop \
    qml/pages/PlaylistsPage.qml \
    qml/pages/TrackInfoPage.qml

HEADERS += \
    src/SailPlayerController.hpp \
    src/Audio/AudioResource.hpp \
    src/Audio/AudioPlayer.hpp \
    src/Audio/IAudioPlayer.hpp \
    src/Audio/AudioPlayerBase.hpp \
    src/Audio/AudioPlayerEnums.hpp \
    src/Audio/Gst/GBus.hpp \
    src/Audio/Gst/GPipeline.hpp \
    src/Audio/Gst/GEqualizer.hpp \
    src/Audio/Gst/GEqualizerBand.hpp \
    src/Audio/Gst/GAudioPlayer.hpp \
    src/Audio/Gst/GInit.hpp \
    src/Audio/Gst/GAutoSink.hpp \
    src/Audio/Gst/GElement.hpp \
    src/Audio/Gst/GPlugins.hpp
