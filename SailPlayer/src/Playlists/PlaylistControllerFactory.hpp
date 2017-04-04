#ifndef PLAYLISTCONTROLLERFACTORY_HPP
#define PLAYLISTCONTROLLERFACTORY_HPP

#include "PlaylistController.hpp"

namespace Playlists
{
	class PlaylistControllerFactory: public QObject
	{
		 Q_OBJECT

	public:
		PlaylistControllerFactory();

		Q_INVOKABLE QObject* create();
	};
}
#endif // PLAYLISTCONTROLLERFACTORY_HPP
