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

bool SailPlayerSettings::GetRestoreLastPlayingTrack()
{
	return settings.value("RestoreLastPlayingTrack", true).toBool();
}

void SailPlayerSettings::SetRestoreLastPlayingTrack(bool restore)
{
	settings.setValue("RestoreLastPlayingTrack", restore);

	emit RestoreLastPlayingTrackChanged();
}

bool SailPlayerSettings::GetRestoreLastPlayingTrackPosition()
{
	return settings.value("RestoreLastPlayingTrackPosition", true).toBool();
}

void SailPlayerSettings::SetRestoreLastPlayingTrackPosition(bool restore)
{
	settings.setValue("RestoreLastPlayingTrackPosition", restore);

	emit RestoreLastPlayingTrackPositionChanged();
}

// Last.fm

bool SailPlayerSettings::GetScrobblingIsEnabled()
{
	return settings.value("Last.fm/ScrobblingIsEnabled", true).toBool();
}

void SailPlayerSettings::SetScrobblingIsEnabled(bool enabled)
{
	settings.setValue("Last.fm/ScrobblingIsEnabled", enabled);

	emit ScrobblingIsEnabledChanged(enabled);
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
	ClearCachedTracks();
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

void SailPlayerSettings::ClearCachedTracks()
{
	settings.remove("CachedTracksToScrobble");
}

// Equalizer

QList<EqualizerPreset*> SailPlayerSettings::GetEqualizerPresets()
{
	QList<EqualizerPreset*> presets;

	int presetsCount = settings.beginReadArray("EqualizerPresets");

	for (int i = 0; i < presetsCount; ++i)
	{
		settings.setArrayIndex(i);

		QString name = settings.value("Name").toString();

		if(name.isNull() || name.isEmpty())
			continue;

		EqualizerPreset* preset = new EqualizerPreset(name);

		int bandsCount = settings.beginReadArray("Bands");

		for (int j = 0; j < bandsCount; ++j)
		{
			settings.setArrayIndex(j);

			preset->AddBand(new EqualizerBand(settings.value("Frequency").toFloat(),
											  settings.value("Gain").toFloat(),
											  settings.value("Width").toFloat()));
		}

		settings.endArray();

		presets.append(preset);
	}

	settings.endArray();

	return presets;
}

void SailPlayerSettings::SetEqualizerPresets(QList<EqualizerPreset*> presets)
{
	ClearEqualizerPresets();
	settings.beginWriteArray("EqualizerPresets", presets.count());

	for(int i = 0; i < presets.count(); ++i)
	{
		EqualizerPreset* preset = presets.at(i);
		QList<EqualizerBand*> bands = preset->GetBands();

		settings.setArrayIndex(i);

		settings.setValue("Name", preset->GetName());

		settings.beginWriteArray("Bands", bands.count());

		for(int j = 0; j < bands.count(); ++j)
		{
			EqualizerBand* band = bands.at(j);

			settings.setArrayIndex(j);

			settings.setValue("Frequency", band->GetFrequency());
			settings.setValue("Gain", band->GetGain());
			settings.setValue("Width", band->GetWidth());
		}

		settings.endArray();
	}

	settings.endArray();
}

void SailPlayerSettings::ClearEqualizerPresets()
{
	settings.remove("EqualizerPresets");
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
