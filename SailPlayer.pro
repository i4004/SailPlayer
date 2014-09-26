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
    src/harbour-sail-player.cpp

OTHER_FILES += \
    qml/controls/Playlist.qml \
    qml/cover/CoverPage.qml \
    qml/pages/DefaultPage.qml \
    rpm/SailPlayer.changes.in \
    rpm/SailPlayer.yaml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/CoverPage.qml \
    qml/harbour-sail-player.qml

TRANSLATIONS += translations/harbour-sail-player-de.ts
