TARGET = harbour-sail-player

CONFIG += sailfishapp

SOURCES += \
    src/harbour-sail-player.cpp

include(sailfishapplication/sailfishapplication.pri)

OTHER_FILES += \
    qml/controls/Playlist.qml \
    qml/cover/CoverPage.qml \
    qml/pages/DefaultPage.qml \
    rpm/SailPlayer.changes.in \
    rpm/SailPlayer.yaml \
    translations/*.ts \
    harbour-sail-player.desktop \
    qml/Main.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/harbour-sail-player-de.ts
