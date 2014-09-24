TARGET = harbour-sail-player

CONFIG += sailfishapp

SOURCES += \
    src/harbour-sail-player.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    qml/pages/SecondPage.qml \
    rpm/SailPlayer.changes.in \
    rpm/SailPlayer.yaml \
    translations/*.ts \
    qml/pages/DefaultPage.qml \
    qml/controls/Playlist.qml \
    harbour-sail-player.desktop \
    qml/harbour-sail-player.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/harbour-sail-player-de.ts

