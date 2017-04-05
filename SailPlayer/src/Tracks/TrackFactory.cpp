#include "TrackFactory.hpp"

namespace Tracks
{
	Track* TrackFactory::Create(int id,
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
		return new Track(id, artistName, albumName, albumYear, number, name, startPosition, endPosition, fileName, fullFilePath);
	}
}
