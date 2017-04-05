TARGET = harbour-sail-player-dev

# Paths

TARGETPATH = /usr/bin
target.path = $$TARGETPATH
DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH
desktop.path = /usr/share/applications

# Configuration

CONFIG += sailfishapp
QT += core quick qml sql
PKGCONFIG += audioresource gstreamer-1.0

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

# Files

SOURCES += \
    src/Main.cpp \
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
    src/Audio/Gst/GElement.cpp \
    src/Tracks/Track.cpp \
    src/Cue/CueFile.cpp \
    src/Cue/CueTrack.cpp \
    src/Cue/CueIndex.cpp \
    src/Cue/CueSheet.cpp \
    src/Cue/CueSheetParser.cpp \
    src/Cue/CueSheetReader.cpp \
    src/Playlists/Playlist.cpp \
    src/Playlists/PlaylistsModel.cpp \
    src/Playlists/PlaylistsController.cpp \
    src/Playlists/PlaylistFactory.cpp \
    src/Playlists/PlaylistsRepository.cpp \
    src/Database/SqlConnection.cpp \
    src/Database/SailPlayerConnectionManager.cpp \
    src/Database/SailPlayerConnection.cpp \
    src/Registrator.cpp \
    src/State/SailPlayerState.cpp \
    src/Settings/SailPlayerSettings.cpp \
    src/Playlists/PlaylistsControllerFactory.cpp \
    src/Playlists/StatefulPlaylistsController.cpp \
    src/State/SailPlayerStateFactory.cpp \
    src/Playlists/SettingsPlaylistsController.cpp \
    src/IO/FsRecordsListModel.cpp \
    src/IO/FsRecordInfo.cpp \
    src/IO/FsRecordInfoFactory.cpp \
    src/IO/FileHelper.cpp \
    src/IO/DirectorySelectionController.cpp \
    src/IO/DirectorySelectionControllerFactory.cpp \
    src/Playlists/PlaylistModel.cpp \
    src/Playlists/PlaylistController.cpp \
    src/Playlists/PlaylistControllerFactory.cpp \
    src/Tracks/TrackFactory.cpp

DISTFILES += \
    qml/pages/PlaylistPage.qml \
    qml/Cover.qml \
    qml/Main.qml \
    harbour-sail-player-dev.desktop \
    qml/pages/PlaylistsPage.qml \
    qml/pages/TrackInfoPage.qml \
    qml/dialogs/TextItemDialog.qml \
    qml/components/PlaylistsPlaylistItem.qml \
    qml/dialogs/DirectorySelectionDialog.qml

HEADERS += \
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
    src/Audio/Gst/GPlugins.hpp \
    src/Tracks/Track.hpp \
    src/Cue/CueFile.hpp \
    src/Cue/CueTrack.hpp \
    src/Cue/CueFileType.hpp \
    src/Cue/CueIndex.hpp \
    src/Cue/CueSheet.hpp \
    src/Cue/CueSheetParser.hpp \
    src/Cue/CueSheetReader.hpp \
    src/Cue/CueTrackDataType.hpp \
    src/Tracks/ITracksFactory.hpp \
    src/Model/ListModel.hpp \
    src/Playlists/PlaylistsModel.hpp \
    src/Playlists/Playlist.hpp \
    src/Playlists/PlaylistsController.hpp \
    src/Playlists/PlaylistsRepository.hpp \
    src/Database/SqlConnection.hpp \
    src/Database/SailPlayerConnectionManager.hpp \
    src/Database/SailPlayerConnection.hpp \
    src/Model/IdentityObject.hpp \
    src/Registrator.hpp \
    src/State/SailPlayerState.hpp \
    src/Settings/SailPlayerSettings.hpp \
    src/Playlists/PlaylistsControllerFactory.hpp \
    src/Playlists/PlaylistFactory.hpp \
    src/Playlists/StatefulPlaylistsController.hpp \
    src/State/SailPlayerStateFactory.hpp \
    src/Playlists/SettingsPlaylistsController.hpp \
    src/IO/FsRecordsListModel.hpp \
    src/IO/FsRecordInfo.hpp \
    src/IO/FileType.hpp \
    src/IO/FsRecordInfoFactory.hpp \
    src/IO/FileHelper.hpp \
    src/IO/DirectorySelectionController.hpp \
    src/IO/DirectorySelectionControllerFactory.hpp \
    src/Playlists/PlaylistModel.hpp \
    src/Playlists/PlaylistController.hpp \
    src/Playlists/PlaylistControllerFactory.hpp \
    src/Tracks/TrackFactory.hpp
