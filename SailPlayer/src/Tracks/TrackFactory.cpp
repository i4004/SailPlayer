#include "TrackFactory.hpp"

namespace Tracks
{
	Track* TrackFactory::Create(int playlistID,
								const QString& artistName,
								const QString& albumName,
								int albumYear,
								int number,
								const QString& name,
								int startPosition /* msec */,
								int endPosition /* msec */,
								const QString& fileName,
								const QString& fullFilePath)
	{
		Track* item = new Track();

		item->SetPlaylistID(playlistID);
		item->SetArtistName(artistName);
		item->SetAlbumName(albumName);
		item->SetAlbumYear(albumYear);
		item->SetNumber(number);
		item->SetName(name);
		item->SetStartPosition(startPosition);
		item->SetEndPosition(endPosition);
		item->SetFileName(fileName);
		item->SetFullFilePath(fullFilePath);

		return item;
	}

	Track* TrackFactory::Create(int id,
								int playlistID,
								const QString& artistName,
								const QString& albumName,
								int albumYear,
								int number,
								const QString& name,
								int startPosition /* msec */,
								int endPosition /* msec */,
								const QString& fileName,
								const QString& fullFilePath)
	{
		Track* item = Create(playlistID, artistName, albumName, albumYear, number, name, startPosition, endPosition, fileName, fullFilePath);

		item->SetID(id);

		return item;
	}
}
