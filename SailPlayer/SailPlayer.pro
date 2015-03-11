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
    src/Audio/AudioPlayer.cpp \
    src/PlayController.cpp \
    src/Playlist/PlaylistHelper.cpp \
    src/IO/FsHelper.cpp \
    src/IO/FsRecordInfo.cpp \
    src/IO/FsRecordsInfoFactory.cpp \
    src/Cue/CueFile.cpp \
    src/Cue/CueIndex.cpp \
    src/Cue/CueSheet.cpp \
    src/Cue/CueSheetParser.cpp \
    src/Cue/CueSheetReader.cpp \
    src/Cue/CueTrack.cpp \
    src/Playlist/DirectoryRecursiveMultimediaFilesListFactory.cpp \
    src/Playlist/TracksFactory.cpp \
    src/Playlist/TracksLoader.cpp \
    src/Models/FsRecordsListModel.cpp \
    src/Util/FsRecordIconHelper.cpp \
    src/Net/LastFmQueryBuilder.cpp \
    src/Net/LastFmRequestBuilder.cpp \
    src/Net/LastFmScrobbler.cpp \
    src/LastFmController.cpp \
    src/PlaylistController.cpp \
    src/Equalizer/EqualizerPreset.cpp \
    src/Equalizer/EqualizerBand.cpp \
    src/EqualizerController.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/Main.qml \
    qml/Cover.qml \
    qml/Util.js \
    qml/pages/MainPage.qml \
    qml/controls/playlist/PlaylistItem.qml \
    qml/controls/playlist/PlaylistSectionHeader.qml \
    qml/controls/PlayOrderControl.qml \
    qml/controls/radio/RadioGroup.qml \
    qml/controls/radio/RadioSwitch.qml \
    qml/controls/PlayerControlPanel.qml \
    qml/controls/InteractionBlocker.qml \
    qml/controls/MessagePageDisplayer.qml \
    qml/controls/NotificationPanel.qml \
    qml/pages/AddFilesDialog.qml \
    qml/pages/ManageTextItemDialog.qml \
    qml/pages/MessagePage.qml \
    qml/pages/settings/LastFmSettings.qml \
    qml/pages/settings/SettingsMain.qml \
    qml/controls/VerticalSpacer.qml \
    qml/pages/equalizer/EqualizerBandsPage.qml \
    qml/pages/equalizer/EqualizerPage.qml

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
    src/Audio/AudioPlayer.hpp \
    src/PlayController.hpp \
    src/Playlist/PlaylistHelper.hpp \
    src/IO/FsHelper.hpp \
    src/IO/FileType.hpp \
    src/IO/FsRecordInfo.hpp \
    src/IO/FsRecordsInfoFactory.hpp \
    src/Cue/CueFile.hpp \
    src/Cue/CueFileType.hpp \
    src/Cue/CueIndex.hpp \
    src/Cue/CueSheet.hpp \
    src/Cue/CueSheetParser.hpp \
    src/Cue/CueSheetReader.hpp \
    src/Cue/CueTrack.hpp \
    src/Cue/CueTrackDataType.hpp \
    src/Playlist/DirectoryRecursiveMultimediaFilesListFactory.hpp \
    src/Playlist/IMultimediaFilesListFactory.hpp \
    src/Playlist/ITracksFactory.hpp \
    src/Playlist/ITracksLoader.hpp \
    src/Playlist/TracksFactory.hpp \
    src/Playlist/TracksLoader.hpp \
    src/Models/FsRecordsListModel.hpp \
    src/Util/FsRecordIconHelper.hpp \
    src/Net/LastFmQueryBuilder.hpp \
    src/Net/LastFmRequestBuilder.hpp \
    src/Net/LastFmScrobbler.hpp \
    src/LastFmController.hpp \
    src/PlaylistController.hpp \
    src/Equalizer/EqualizerPreset.hpp \
    src/Equalizer/EqualizerBand.hpp \
    src/EqualizerController.hpp
