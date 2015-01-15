TEMPLATE=app
TARGET = harbour-sail-player

CONFIG += sailfishapp
QT += declarative
QT += multimedia

TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH
desktop.path = /usr/share/applications

DEFINES += DEPLOYMENT_PATH=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"

SOURCES += \
    src/Main.cpp \
    src/Entities/Track.cpp \
    src/Entities/Artist.cpp \
    src/Entities/Album.cpp \
    src/Util/FsRecordIconHelper.cpp \
    src/IO/FsRecordsInfoFactory.cpp \
    src/IO/FsRecordInfo.cpp \
    src/IO/FileHelper.cpp \
    src/UI/FsRecordsListModel.cpp \
    src/UI/AudioPlayer.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    qml/pages/DefaultPage.qml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/Main.qml \
    qml/Cover.qml \
    qml/pages/AddFilesDialog.qml \
    qml/widgets/Playlist.qml

TRANSLATIONS += translations/harbour-sail-player-de.ts

HEADERS += \
    src/Entities/Track.h \
    src/Entities/Track.h \
    src/Entities/Artist.h \
    src/Entities/Album.h \
    src/Util/FsRecordIconHelper.h \
    src/FsRecordsListModel.h \
    src/IO/FsRecordsInfoFactory.h \
    src/IO/FsRecordInfo.h \
    src/IO/FileType.h \
    src/IO/FileHelper.h \
    src/UI/FsRecordsListModel.h \
    src/UI/AudioPlayer.h

INCLUDEPATH += $$PWD/include
