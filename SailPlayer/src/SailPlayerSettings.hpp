#ifndef SAILPLAYERSETTINGS_HPP
#define SAILPLAYERSETTINGS_HPP

#include <QString>
#include <QList>
#include <QSettings>

#include "Playlist/Track.hpp"

using namespace Playlist;

class SailPlayerSettings : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString defaultAddFilesDirectoryPath READ GetDefaultAddFilesDirectoryPath)
	Q_PROPERTY(QString lastAddFilesDirectoryPath READ GetLastAddFilesDirectoryPath WRITE SetLastAddFilesDirectoryPath(QString) NOTIFY LastAddFilesDirectoryPathChanged)
	Q_PROPERTY(int currentTrackIndex READ GetCurrentTrackIndex WRITE SetCurrentTrackIndex)
	Q_PROPERTY(int currentPlayingPosition READ GetCurrentPlayingPosition WRITE SetCurrentPlayingPosition)

public:
	static SailPlayerSettings& Default();

	QString GetDefaultAddFilesDirectoryPath() const { return DefaultAddFilesDirectoryPath; }
	QString GetLastAddFilesDirectoryPath();
	void SetLastAddFilesDirectoryPath(QString value);

	QList<Track*> GetPlaylist();
	void SetPlaylist(QList<Track*> tracks);

	int GetCurrentTrackIndex();
	void SetCurrentTrackIndex(int currentTrackIndex);

	int GetCurrentPlayingPosition();
	void SetCurrentPlayingPosition(int currentPlayingPosition);

signals:
	void LastAddFilesDirectoryPathChanged();

private:
	static QString DefaultAddFilesDirectoryPath;

	QSettings settings;
};

#endif // SAILPLAYERSETTINGS_HPP
