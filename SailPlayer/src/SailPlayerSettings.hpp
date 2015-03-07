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

//	// Add files dialog

//	Q_PROPERTY(QString defaultAddFilesDirectoryPath READ GetDefaultAddFilesDirectoryPath NOTIFY defaultAddFilesDirectoryPathChanged)
//	Q_PROPERTY(QString lastAddFilesDirectoryPath READ GetLastAddFilesDirectoryPath WRITE SetLastAddFilesDirectoryPath NOTIFY lastAddFilesDirectoryPathChanged)

//	// General

//	Q_PROPERTY(SailPlayer::PlayOrder playOrder READ GetPlayOrder WRITE SetPlayOrder NOTIFY playOrderChanged)
//	Q_PROPERTY(int lastTrackIndex READ GetLastTrackIndex WRITE SetLastTrackIndex)
//	Q_PROPERTY(int lastPlayingPosition READ GetLastPlayingPosition WRITE SetLastPlayingPosition)
//	Q_PROPERTY(bool restoreLastPlayingPosition READ GetRestoreLastPlayingPosition WRITE SetRestoreLastPlayingPosition NOTIFY restoreLastPlayingPositionChanged)

//	// Last.fm

//	Q_PROPERTY(bool scrobblingIsEnabled READ GetScrobblingIsEnabled WRITE SetScrobblingIsEnabled NOTIFY scrobblingIsEnabledChanged)
//	Q_PROPERTY(QString lastFmSessionKey READ GetLastFmSessionKey WRITE SetLastFmSessionKey NOTIFY lastFmSessionKeyChanged)


public:
	static SailPlayerSettings& Default();

	// Add files dialog

	QString GetDefaultAddFilesDirectoryPath() const { return DefaultAddFilesDirectoryPath; }

	QString GetLastAddFilesDirectoryPath();
	void SetLastAddFilesDirectoryPath(QString value);

	// General

	QList<Track*> GetPlaylist();
	void SetPlaylist(QList<Track*> tracks);

	SailPlayer::PlayOrder GetPlayOrder();
	void SetPlayOrder(SailPlayer::PlayOrder playOrder);

	int GetLastTrackIndex();
	void SetLastTrackIndex(int currentTrackIndex);

	int GetLastPlayingPosition();
	void SetLastPlayingPosition(int currentPlayingPosition);

	bool GetRestoreLastPlayingPosition();
	void SetRestoreLastPlayingPosition(bool restore);

	// Last.fm

	bool GetScrobblingIsEnabled();
	void SetScrobblingIsEnabled(bool enabled);

	QString GetLastFmSessionKey();
	void SetLastFmSessionKey(QString key);

	QMap<QDateTime, Track*> GetCachedTracks();
	void SetCachedTracks(QMap<QDateTime, Track*> tracks);

signals:
	// Add files dialog

	void defaultAddFilesDirectoryPathChanged();
	void lastAddFilesDirectoryPathChanged();

	// General

	void playOrderChanged();
	void restoreLastPlayingPositionChanged();

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
