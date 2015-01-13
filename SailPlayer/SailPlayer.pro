TEMPLATE=app
TARGET = harbour-sail-player

CONFIG += sailfishapp
QT += declarative

TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH
desktop.path = /usr/share/applications

DEFINES += DEPLOYMENT_PATH=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"

SOURCES += \
    src/Main.cpp \
    src/FilesListModel.cpp \
    src/FileInfoFactory.cpp \
    src/Entities/Track.cpp \
    src/Entities/FileInfo.cpp \
    src/Entities/Artist.cpp \
    src/Entities/Album.cpp \
    src/Util/FileIconHelper.cpp \
    src/Util/FileHelper.cpp

OTHER_FILES += \
    qml/controls/Playlist.qml \
    qml/cover/CoverPage.qml \
    qml/pages/DefaultPage.qml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/Main.qml \
    qml/Cover.qml \
    qml/pages/AddFilesDialog.qml

TRANSLATIONS += translations/harbour-sail-player-de.ts

HEADERS += \
    src/Entities/Track.h \
    src/Entities/Track.h \
    src/Entities/FileInfo.h \
    src/Entities/Artist.h \
    src/Entities/Album.h \
    src/FilesListModel.h \
    src/FileInfoFactory.h \
    src/FileIconHelper.h \
    src/FileType.h \
    src/Entities/FileType.h \
    src/Util/FileIconHelper.h \
    src/Util/FileHelper.h

INCLUDEPATH += $$PWD/include
