#ifndef SAILPLAYERSETTINGS_H
#define SAILPLAYERSETTINGS_H

#include <QString>
#include <QList>
#include <QSettings>

#include "Playlist/Track.h"

using namespace Playlist;

class SailPlayerSettings : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString defaultAddFilesDirectoryPath READ GetDefaultAddFilesDirectoryPath)
	Q_PROPERTY(QString lastAddFilesDirectoryPath READ GetLastAddFilesDirectoryPath WRITE SetLastAddFilesDirectoryPath(QString) NOTIFY LastAddFilesDirectoryPathChanged)

public:
	static SailPlayerSettings& Default();

	QString GetDefaultAddFilesDirectoryPath() const { return DefaultAddFilesDirectoryPath; }
	QString GetLastAddFilesDirectoryPath();
	void SetLastAddFilesDirectoryPath(QString value);

	QList<Track*> GetPlaylist();
	void SetPlaylist(QList<Track*> tracks);

signals:
	void LastAddFilesDirectoryPathChanged();

private:
	static QString DefaultAddFilesDirectoryPath;

	QSettings settings;
};

#endif // SAILPLAYERSETTINGS_H
