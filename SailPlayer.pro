include(common.pri)

TEMPLATE = subdirs
SUBDIRS = SailPlayer SailPlayer.Tests libQtCue libQtCue.Tests

CONFIG += ordered

SailPlayer.depends = libQtCue
libQtCue.Tests.depends = libQtCue
