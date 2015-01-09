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
    src/Entities/Album.cpp

OTHER_FILES += \
    qml/controls/Playlist.qml \
    qml/cover/CoverPage.qml \
    qml/pages/DefaultPage.qml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/pages/AddFilesPage.qml \
    qml/Main.qml \
    qml/Cover.qml

TRANSLATIONS += translations/harbour-sail-player-de.ts

HEADERS += \
    src/Entities/Track.h \
    src/Entities/Track.h \
    src/Entities/FileInfo.h \
    src/Entities/Artist.h \
    src/Entities/Album.h \
    src/FilesListModel.h \
    src/FileInfoFactory.h

INCLUDEPATH += $$PWD/include
