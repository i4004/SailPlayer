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
    src/Util/FsRecordIconHelper.cpp \
    src/IO/FsRecordsInfoFactory.cpp \
    src/IO/FsRecordInfo.cpp \
    src/Audio/AudioResource.cpp \
    src/Audio/AudioPlayer.cpp \
    src/IO/FsHelper.cpp \
    src/Playlist/Track.cpp \
    src/Playlist/TracksFactory.cpp \
    src/Playlist/DirectoryRecursiveMultimediaFilesListFactory.cpp \
    src/Models/FsRecordsListModel.cpp \
    src/Models/PlaylistModel.cpp \
    src/Playlist/TracksLoader.cpp \
    src/Models/PlaylistModelBase.cpp \
    src/Cue/CueSheet.cpp \
    src/Cue/CueSheetParser.cpp \
    src/Cue/CueSheetReader.cpp \
    src/Cue/CueTrack.cpp \
    src/Cue/CueFile.cpp \
    src/Cue/CueIndex.cpp \
    src/Audio/AudioPlayerBase.cpp \
    src/SailPlayerSettings.cpp \
    src/Net/LastFmScrobbler.cpp \
    src/Net/LastFmQueryBuilder.cpp \
    src/Net/LastFmRequestBuilder.cpp \
    src/Playlist/PlaylistHelper.cpp \
    src/SailPlayerController.cpp \
    src/PlayController.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/Main.qml \
    qml/Cover.qml \
    qml/Util.js \
    qml/pages/AddFilesDialog.qml \
    qml/controls/PlayerControlPanel.qml \
    qml/controls/VerticalSpacerMedium.qml \
    qml/controls/PlayOrderControl.qml \
    qml/controls/playlist/PlaylistItem.qml \
    qml/controls/playlist/PlaylistSectionHeader.qml \
    qml/controls/radio/RadioGroup.qml \
    qml/controls/radio/RadioSwitch.qml \
    qml/pages/MainPage.qml \
    qml/pages/SettingsPage.qml \
    qml/pages/MessagePage.qml \
    qml/controls/MessagePageDisplayer.qml \
    qml/pages/EqualizerPage.qml \
    qml/pages/ManageTextItemDialog.qml \
    qml/controls/NotificationPanel.qml \
    qml/controls/InteractionBlocker.qml

TRANSLATIONS += translations/harbour-sail-player-de.ts

HEADERS += \
    src/SailPlayerSettings.hpp \
    src/Util/FsRecordIconHelper.hpp \
    src/Playlist/TracksLoader.hpp \
    src/Playlist/TracksFactory.hpp \
    src/Playlist/Track.hpp \
    src/Playlist/ITracksLoader.hpp \
    src/Playlist/ITracksFactory.hpp \
    src/Playlist/IMultimediaFilesListFactory.hpp \
    src/Playlist/DirectoryRecursiveMultimediaFilesListFactory.hpp \
    src/Models/PlaylistModelBase.hpp \
    src/Models/PlaylistModel.hpp \
    src/Models/FsRecordsListModel.hpp \
    src/IO/FsRecordsInfoFactory.hpp \
    src/IO/FsRecordInfo.hpp \
    src/IO/FsHelper.hpp \
    src/IO/FileType.hpp \
    src/Audio/AudioResource.hpp \
    src/Audio/AudioPlayer.hpp \
    src/Cue/CueSheet.hpp \
    src/Cue/CueSheetParser.hpp \
    src/Cue/CueSheetReader.hpp \
    src/Cue/CueTrack.hpp \
    src/Cue/CueFile.hpp \
    src/Cue/CueTrackDataType.hpp \
    src/Cue/CueFileType.hpp \
    src/Cue/CueIndex.hpp \
    src/Audio/AudioPlayerBase.hpp \
    src/SailPlayer.hpp \
    src/Net/LastFmScrobbler.hpp \
    src/Net/LastFmQueryBuilder.hpp \
    src/Net/LastFmRequestBuilder.hpp \
    src/Playlist/PlaylistHelper.hpp \
    src/SailPlayerController.hpp \
    src/PlayController.hpp

INCLUDEPATH += $$PWD/include
