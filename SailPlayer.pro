# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = SailPlayer

CONFIG += sailfishapp

SOURCES += src/SailPlayer.cpp

OTHER_FILES += qml/SailPlayer.qml \
    qml/cover/CoverPage.qml \
    qml/pages/SecondPage.qml \
    rpm/SailPlayer.changes.in \
    rpm/SailPlayer.spec \
    rpm/SailPlayer.yaml \
    translations/*.ts \
    SailPlayer.desktop \
    qml/pages/DefaultPage.qml \
    qml/controls/Playlist.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/SailPlayer-de.ts

