#ifndef SAILPLAYERSETTINGS_HPP
#define SAILPLAYERSETTINGS_HPP

#include <QDateTime>
#include <QList>
#include <QSettings>
#include <QString>

#include "Equalizer/EqualizerPreset.hpp"
#include "Playlist/PlaylistEnums.hpp"
#include "Playlist/Track.hpp"

using namespace Equalizer;
using namespace Playlist;

class SailPlayerSettings : public QObject
{
	Q_OBJECT

	// Add files dialog

	Q_PROPERTY(QString defaultAddFilesDirectoryPath READ GetDefaultAddFilesDirectoryPath NOTIFY DefaultAddFilesDirectoryPathChanged)
	Q_PROPERTY(QString lastAddFilesDirectoryPath READ GetLastAddFilesDirectoryPath WRITE SetLastAddFilesDirectoryPath NOTIFY LastAddFilesDirectoryPathChanged)

	// General

	Q_PROPERTY(bool restoreLastPlayingTrack READ GetRestoreLastPlayingTrack WRITE SetRestoreLastPlayingTrack NOTIFY RestoreLastPlayingTrackChanged)
	Q_PROPERTY(bool restoreLastPlayingTrackPosition READ GetRestoreLastPlayingTrackPosition WRITE SetRestoreLastPlayingTrackPosition NOTIFY RestoreLastPlayingTrackPositionChanged)

	// Last.fm

	Q_PROPERTY(bool scrobblingIsEnabled READ GetScrobblingIsEnabled WRITE SetScrobblingIsEnabled NOTIFY ScrobblingIsEnabledChanged)
	Q_PROPERTY(QString lastFmSessionKey READ GetLastFmSessionKey WRITE SetLastFmSessionKey NOTIFY LastFmSessionKeyChanged)

public:
	// Add files dialog

	QString GetDefaultAddFilesDirectoryPath() const { return DefaultAddFilesDirectoryPath; }

	QString GetLastAddFilesDirectoryPath();
	void SetLastAddFilesDirectoryPath(QString value);

	// General

	QList<Track*> GetPlaylist();
	void SetPlaylist(QList<Track*> tracks);

	PlaylistEnums::PlayOrder GetPlayOrder();
	void SetPlayOrder(PlaylistEnums::PlayOrder playOrder);

	int GetLastTrackIndex();
	void SetLastTrackIndex(int currentTrackIndex);

	int GetLastPlayingPosition();
	void SetLastPlayingPosition(int currentPlayingPosition);

	bool GetRestoreLastPlayingTrack();
	void SetRestoreLastPlayingTrack(bool restore);

	bool GetRestoreLastPlayingTrackPosition();
	void SetRestoreLastPlayingTrackPosition(bool restore);

	// Last.fm

	bool GetScrobblingIsEnabled();
	void SetScrobblingIsEnabled(bool enabled);

	QString GetLastFmSessionKey();
	void SetLastFmSessionKey(QString key);

	QMap<QDateTime, Track*> GetCachedTracks();
	void SetCachedTracks(QMap<QDateTime, Track*> tracks);
	void ClearCachedTracks();

	// Equalizer

	QList<EqualizerPreset*> GetEqualizerPresets();
	void SetEqualizerPresets(QList<EqualizerPreset*> presets);
	void ClearEqualizerPresets();

signals:
	// Add files dialog

	void DefaultAddFilesDirectoryPathChanged();
	void LastAddFilesDirectoryPathChanged();

	// General

	void PlayOrderChanged();
	void RestoreLastPlayingTrackChanged();
	void RestoreLastPlayingTrackPositionChanged();

	// Last.fm

	void ScrobblingIsEnabledChanged(bool enabled);
	void LastFmSessionKeyChanged(QString key);

private:
	static QString DefaultAddFilesDirectoryPath;

	QSettings settings;

	Track* GetTrackFromSettings();
	void SetTrackToSettings(Track* track);
};

#endif // SAILPLAYERSETTINGS_HPP
