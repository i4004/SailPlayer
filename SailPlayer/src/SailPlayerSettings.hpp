#ifndef SAILPLAYERSETTINGS_HPP
#define SAILPLAYERSETTINGS_HPP

#include <QString>
#include <QList>
#include <QSettings>

#include "Playlist/Track.hpp"
#include "Audio/AudioPlayer.hpp"
#include "SailPlayer.hpp"

using namespace Playlist;
using namespace Audio;

class SailPlayerSettings : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString defaultAddFilesDirectoryPath READ GetDefaultAddFilesDirectoryPath)
	Q_PROPERTY(QString lastAddFilesDirectoryPath READ GetLastAddFilesDirectoryPath WRITE SetLastAddFilesDirectoryPath(QString) NOTIFY lastAddFilesDirectoryPathChanged)
	Q_PROPERTY(int currentTrackIndex READ GetCurrentTrackIndex WRITE SetCurrentTrackIndex)
	Q_PROPERTY(int currentPlayingPosition READ GetCurrentPlayingPosition WRITE SetCurrentPlayingPosition)
	Q_PROPERTY(SailPlayer::PlayOrder currentPlayOrder READ GetCurrentPlayOrder WRITE SetCurrentPlayOrder NOTIFY currentPlayOrderChanged)

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

	SailPlayer::PlayOrder GetCurrentPlayOrder();
	void SetCurrentPlayOrder(SailPlayer::PlayOrder playOrder);

signals:
	void lastAddFilesDirectoryPathChanged();
	void currentPlayOrderChanged();

private:
	static QString DefaultAddFilesDirectoryPath;

	QSettings settings;
};

#endif // SAILPLAYERSETTINGS_HPP
