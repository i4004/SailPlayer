#ifndef PLAYLISTSCONTROLLERFACTORY_H
#define PLAYLISTSCONTROLLERFACTORY_H

#include "PlaylistsController.hpp"

namespace Playlists
{
	class PlaylistsControllerFactory : public QObject
	{
		 Q_OBJECT

	public:
		PlaylistsControllerFactory(PlaylistsRepository* repository, PlaylistFactory* factory);
		~PlaylistsControllerFactory();

		Q_INVOKABLE QObject* create();

	private:
		PlaylistsRepository* _repository;
		PlaylistFactory* _factory;
	};
}

#endif // PLAYLISTSCONTROLLERFACTORY_H
