#ifndef PLAYLISTFACTORY_HPP
#define PLAYLISTFACTORY_HPP

#include <QFileInfo>

#include "ITracksFactory.hpp"
#include "Track.hpp"

namespace Playlist
{
	class TracksFactory : public ITracksFactory
	{
	public:
		TracksFactory();

		virtual QList<Track*> Build(QList<QFileInfo> filesInfoList);

	private:
		QList<Track*> Build(QFileInfo fileInfo);
	};
}

#endif // PLAYLISTFACTORY_HPP
