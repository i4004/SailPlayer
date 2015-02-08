TEMPLATE = subdirs
SUBDIRS = SailPlayer SailPlayer.Tests QtCue QtCue.Tests

CONFIG += ordered

SailPlayer.depends = QtCue
