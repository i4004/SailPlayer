#include "SailPlayerSettings.hpp"

QString SailPlayerSettings::DefaultAddFilesDirectoryPath = "/home/nemo";

SailPlayerSettings& SailPlayerSettings::Default()
{
	static SailPlayerSettings settings;
	return settings;
}

QString SailPlayerSettings::GetLastAddFilesDirectoryPath()
{
	return settings.value("AddFilesDialog/CurrentPath", DefaultAddFilesDirectoryPath).toString();
}

void SailPlayerSettings::SetLastAddFilesDirectoryPath(QString value)
{
	settings.setValue("AddFilesDialog/CurrentPath", value);

	emit lastAddFilesDirectoryPathChanged();
}

QList<Track*> SailPlayerSettings::GetPlaylist()
{
	QList<Track*> tracks;
	int size = settings.beginReadArray("Playlist");

	for (int i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);

		Track* track = new Track(settings.value("ArtistName").toString(),
								settings.value("AlbumName").toString(),
								settings.value("AlbumYear").toInt(),
								settings.value("TrackNumber").toInt(),
								settings.value("TrackName").toString(),
								settings.value("TrackStartPosition").toInt(),
								settings.value("TrackEndPosition").toInt(),
								settings.value("TrackFileName").toString(),
								settings.value("TrackFullFilePath").toString());

		tracks.append(track);
	}

	settings.endArray();

	return tracks;
}

void SailPlayerSettings::SetPlaylist(QList<Track*> tracks)
{
	settings.beginWriteArray("Playlist", tracks.count());

	for(int i = 0; i < tracks.count(); ++i)
	{
		settings.setArrayIndex(i);
		Track* track = tracks.at(i);

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

	settings.endArray();
}

int SailPlayerSettings::GetCurrentTrackIndex()
{
	return settings.value("CurrentTrackIndex", -1).toInt();
}

void SailPlayerSettings::SetCurrentTrackIndex(int currentTrackIndex)
{
	settings.setValue("CurrentTrackIndex", currentTrackIndex);
}

int SailPlayerSettings::GetCurrentPlayingPosition()
{
	return settings.value("CurrentPlayingPosition", -1).toInt();
}

void SailPlayerSettings::SetCurrentPlayingPosition(int currentPlayingPosition)
{
	settings.setValue("CurrentPlayingPosition", currentPlayingPosition);
}

bool SailPlayerSettings::GetRestoreLastPlayingPosition()
{
	return settings.value("RestoreLastPlayingPosition", true).toBool();
}

void SailPlayerSettings::SetRestoreLastPlayingPosition(bool restore)
{
	settings.setValue("RestoreLastPlayingPosition", restore);
}

SailPlayer::PlayOrder SailPlayerSettings::GetCurrentPlayOrder()
{
	return (SailPlayer::PlayOrder)settings.value("CurrentPlayOrder", SailPlayer::RepeatPlaylist).toInt();
}

void SailPlayerSettings::SetCurrentPlayOrder(SailPlayer::PlayOrder playOrder)
{
	settings.setValue("CurrentPlayOrder", playOrder);
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

	emit lastFmSessionKeyChanged();
}
