#ifndef SAILPLAYERSETTINGS_HPP
#define SAILPLAYERSETTINGS_HPP

#include <QDateTime>
#include <QList>
#include <QSettings>
#include <QString>

#include "Audio/AudioPlayer.hpp"
#include "Playlist/Track.hpp"
#include "SailPlayer.hpp"

using namespace Playlist;
using namespace Audio;

class SailPlayerSettings : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString defaultAddFilesDirectoryPath READ GetDefaultAddFilesDirectoryPath)

	// General

	Q_PROPERTY(QString lastAddFilesDirectoryPath READ GetLastAddFilesDirectoryPath WRITE SetLastAddFilesDirectoryPath NOTIFY lastAddFilesDirectoryPathChanged)
	Q_PROPERTY(int currentTrackIndex READ GetCurrentTrackIndex WRITE SetCurrentTrackIndex)
	Q_PROPERTY(int currentPlayingPosition READ GetCurrentPlayingPosition WRITE SetCurrentPlayingPosition)
	Q_PROPERTY(bool restoreLastPlayingPosition READ GetRestoreLastPlayingPosition WRITE SetRestoreLastPlayingPosition NOTIFY restoreLastPlayingPositionChanged)
	Q_PROPERTY(SailPlayer::PlayOrder currentPlayOrder READ GetCurrentPlayOrder WRITE SetCurrentPlayOrder NOTIFY currentPlayOrderChanged)

	// Last.fm
	Q_PROPERTY(bool scrobblingIsEnabled READ GetScrobblingIsEnabled WRITE SetScrobblingIsEnabled NOTIFY scrobblingIsEnabledChanged)
	Q_PROPERTY(QString lastFmSessionKey READ GetLastFmSessionKey WRITE SetLastFmSessionKey NOTIFY lastFmSessionKeyChanged)

public:
	static SailPlayerSettings& Default();

	QString GetDefaultAddFilesDirectoryPath() const { return DefaultAddFilesDirectoryPath; }
	QString GetLastAddFilesDirectoryPath();
	void SetLastAddFilesDirectoryPath(QString value);

	QList<Track*> GetPlaylist();
	void SetPlaylist(QList<Track*> tracks);

	QMap<QDateTime, Track*> GetCachedTracks();
	void SetCachedTracks(QMap<QDateTime, Track*> tracks);

	// General

	int GetCurrentTrackIndex();
	void SetCurrentTrackIndex(int currentTrackIndex);

	int GetCurrentPlayingPosition();
	void SetCurrentPlayingPosition(int currentPlayingPosition);

	bool GetRestoreLastPlayingPosition();
	void SetRestoreLastPlayingPosition(bool restore);

	SailPlayer::PlayOrder GetCurrentPlayOrder();
	void SetCurrentPlayOrder(SailPlayer::PlayOrder playOrder);

	// Last.fm

	bool GetScrobblingIsEnabled();
	void SetScrobblingIsEnabled(bool enabled);

	QString GetLastFmSessionKey();
	void SetLastFmSessionKey(QString key);

signals:
	// General

	void lastAddFilesDirectoryPathChanged();
	void restoreLastPlayingPositionChanged();
	void currentPlayOrderChanged();

	// Last.fm

	void scrobblingIsEnabledChanged();
	void lastFmSessionKeyChanged();

private:
	static QString DefaultAddFilesDirectoryPath;

	QSettings settings;

	Track* GetTrackFromSettings();
	void SetTrackToSettings(Track* track);
};

#endif // SAILPLAYERSETTINGS_HPP
