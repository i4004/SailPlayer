#ifndef TRACKFACTORY_HPP
#define TRACKFACTORY_HPP

#include "Track.hpp"

namespace Tracks
{
	class TrackFactory
	{
	public:
		Track* Create(int playlistID,
					  const QString& artistName,
					  const QString& albumName,
					  int albumYear,
					  int number,
					  const QString& name,
					  int startPosition /* msec */,
					  int endPosition /* msec */,
					  const QString& fileName,
					  const QString& fullFilePath);

		Track* Create(int id,
					  int playlistID,
					  const QString& artistName,
					  const QString& albumName,
					  int albumYear,
					  int number,
					  const QString& name,
					  int startPosition /* msec */,
					  int endPosition /* msec */,
					  const QString& fileName,
					  const QString& fullFilePath);
	};
}

#endif // TRACKFACTORY_HPP
