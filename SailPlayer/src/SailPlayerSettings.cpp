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

	emit LastAddFilesDirectoryPathChanged();
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
								settings.value("TrackDuration").toInt(),
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
		settings.setValue("TrackDuration", track->GetDuration());
		settings.setValue("TrackFileName", track->GetFileName());
		settings.setValue("TrackFullFilePath", track->GetFullFilePath());
	}

	settings.endArray();
}
