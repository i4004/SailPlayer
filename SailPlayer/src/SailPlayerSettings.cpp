#include "SailPlayerSettings.hpp"

QString SailPlayerSettings::DefaultAddFilesDirectoryPath = "/home/nemo";

QString SailPlayerSettings::GetLastAddFilesDirectoryPath()
{
	return settings.value("AddFilesDialog/DirectoryPath", DefaultAddFilesDirectoryPath).toString();
}

void SailPlayerSettings::SetLastAddFilesDirectoryPath(QString value)
{
	settings.setValue("AddFilesDialog/DirectoryPath", value);

	emit LastAddFilesDirectoryPathChanged();
}

PlaylistEnums::PlayOrder SailPlayerSettings::GetPlayOrder()
{
	return (PlaylistEnums::PlayOrder)settings.value("PlayOrder", PlaylistEnums::RepeatPlaylist).toInt();
}

void SailPlayerSettings::SetPlayOrder(PlaylistEnums::PlayOrder playOrder)
{
	settings.setValue("PlayOrder", playOrder);
}

QList<Track*> SailPlayerSettings::GetPlaylist()
{
	QList<Track*> tracks;
	int size = settings.beginReadArray("Playlist");

	for (int i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);

		tracks.append(GetTrackFromSettings());
	}

	settings.endArray();

	return tracks;
}

void SailPlayerSettings::SetPlaylist(QList<Track*> tracks)
{
	settings.remove("Playlist");
	settings.beginWriteArray("Playlist", tracks.count());

	for(int i = 0; i < tracks.count(); ++i)
	{
		settings.setArrayIndex(i);

		SetTrackToSettings(tracks.at(i));
	}

	settings.endArray();
}

int SailPlayerSettings::GetLastTrackIndex()
{
	return settings.value("LastTrackIndex", -1).toInt();
}

void SailPlayerSettings::SetLastTrackIndex(int currentTrackIndex)
{
	settings.setValue("LastTrackIndex", currentTrackIndex);
}

int SailPlayerSettings::GetLastPlayingPosition()
{
	return settings.value("LastPlayingPosition", -1).toInt();
}

void SailPlayerSettings::SetLastPlayingPosition(int currentPlayingPosition)
{
	settings.setValue("LastPlayingPosition", currentPlayingPosition);
}

bool SailPlayerSettings::GetRestoreLastPlayingPosition()
{
	return settings.value("RestoreLastPlayingPosition", true).toBool();
}

void SailPlayerSettings::SetRestoreLastPlayingPosition(bool restore)
{
	settings.setValue("RestoreLastPlayingPosition", restore);
}

// Last.fm

bool SailPlayerSettings::GetScrobblingIsEnabled()
{
	return settings.value("Last.fm/ScrobblingIsEnabled", true).toBool();
}

void SailPlayerSettings::SetScrobblingIsEnabled(bool enabled)
{
	settings.setValue("Last.fm/ScrobblingIsEnabled", enabled);
}

QString SailPlayerSettings::GetLastFmSessionKey()
{
	return settings.value("Last.fm/SessionKey", "").toString();
}

void SailPlayerSettings::SetLastFmSessionKey(QString key)
{
	settings.setValue("Last.fm/SessionKey", key);

	emit LastFmSessionKeyChanged(key);
}

QMap<QDateTime, Track*> SailPlayerSettings::GetCachedTracks()
{
	QMap<QDateTime, Track*>  tracks;
	int size = settings.beginReadArray("CachedTracksToScrobble");

	for (int i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);

		tracks.insert(QDateTime::fromString(settings.value("PlayingStartTime").toString()), GetTrackFromSettings());
	}

	settings.endArray();

	return tracks;
}

void SailPlayerSettings::SetCachedTracks(QMap<QDateTime, Track*> tracks)
{
	settings.remove("CachedTracksToScrobble");
	settings.beginWriteArray("CachedTracksToScrobble", tracks.count());

	QMap<QDateTime, Track*>::iterator i;
	int index = 0;

	for (i = tracks.begin(); i != tracks.end(); ++i)
	{
		settings.setArrayIndex(index++);

		settings.setValue("PlayingStartTime", i.key().toString());

		SetTrackToSettings(i.value());
	}

	settings.endArray();
}

Track* SailPlayerSettings::GetTrackFromSettings()
{
	return new Track(settings.value("ArtistName").toString(),
					settings.value("AlbumName").toString(),
					settings.value("AlbumYear").toInt(),
					settings.value("TrackNumber").toInt(),
					settings.value("TrackName").toString(),
					settings.value("TrackStartPosition").toInt(),
					settings.value("TrackEndPosition").toInt(),
					settings.value("TrackFileName").toString(),
					settings.value("TrackFullFilePath").toString());
		}

void SailPlayerSettings::SetTrackToSettings(Track* track)
{
	settings.setValue("ArtistName", track->GetArtistName());
	settings.setValue("AlbumName", track->GetAlbumName());
	settings.setValue("AlbumYear", track->GetAlbumYear());
	settings.setValue("TrackNumber", track->GetNumber());
	settings.setValue("TrackName", track->GetName());
	settings.setValue("TrackStartPosition", track->GetStartPosition());
	settings.setValue("TrackEndPosition", track->GetEndPosition());
	settings.setValue("TrackFileName", track->GetFileName());
	settings.setValue("TrackFullFilePath", track->GetFullFilePath());
}
