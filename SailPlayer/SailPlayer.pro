TEMPLATE=app
TARGET = harbour-sail-player

CONFIG += link_pkgconfig sailfishapp
QT += core quick qml
PKGCONFIG += gstreamer-0.10 glib-2.0 audioresource taglib

TARGETPATH = /usr/bin
target.path = $$TARGETPATH
DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH
desktop.path = /usr/share/applications
DEFINES += DEPLOYMENT_PATH=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"

SOURCES += \
    src/Main.cpp \
    src/Util/FsRecordIconHelper.cpp \
    src/IO/FsRecordsInfoFactory.cpp \
    src/IO/FsRecordInfo.cpp \
    src/Audio/AudioResource.cpp \
    src/Audio/AudioPlayer.cpp \
    src/SailPlayerSettings.cpp \
    src/IO/FsHelper.cpp \
    src/Playlist/Track.cpp \
    src/Playlist/TracksFactory.cpp \
    src/Playlist/DirectoryRecursiveMultimediaFilesListFactory.cpp \
    src/Models/FsRecordsListModel.cpp \
    src/Models/PlaylistModel.cpp \
    src/Playlist/TracksLoader.cpp \
    src/Models/PlaylistModelBase.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/Main.qml \
    qml/Cover.qml \
    qml/Util.js \
    qml/pages/AddFilesDialog.qml \
    qml/pages/DefaultPage.qml \
    qml/controls/PlayerControlPanel.qml \
    qml/controls/PlaylistItem.qml \
    qml/controls/PlaylistSectionHeader.qml \
    qml/controls/VerticalSpacerMedium.qml \
    qml/controls/RadioGroup.qml \
    qml/controls/RadioSwitch.qml \
    qml/controls/PlayOrderControl.qml

TRANSLATIONS += translations/harbour-sail-player-de.ts

HEADERS += \
    src/Util/FsRecordIconHelper.h \
    src/IO/FsRecordsInfoFactory.h \
    src/IO/FsRecordInfo.h \
    src/IO/FileType.h \
    src/Audio/AudioResource.h \
    src/Audio/AudioPlayer.h \
    src/SailPlayerSettings.h \
    src/IO/FsHelper.h \
    src/Playlist/Track.h \
    src/Playlist/TracksFactory.h \
    src/Playlist/IMultimediaFilesListFactory.h \
    src/Playlist/DirectoryRecursiveMultimediaFilesListFactory.h \
    src/Models/FsRecordsListModel.h \
    src/Models/PlaylistModel.h \
    src/Playlist/TracksLoader.h \
    src/Playlist/ITracksFactory.h \
    src/Playlist/ITracksLoader.h \
    src/Models/IAlbumModelsFactory.h \
    src/Models/PlaylistModelBase.h

INCLUDEPATH += $$PWD/include
