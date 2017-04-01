#ifndef PLAYLISTSCONTROLLERFACTORY_H
#define PLAYLISTSCONTROLLERFACTORY_H

#include <QObject>

#include "../State/SailPlayerState.hpp"
#include "PlaylistFactory.hpp"
#include "PlaylistsRepository.hpp"

using namespace State;

namespace Playlists
{
	class PlaylistsControllerFactory : public QObject
	{
		 Q_OBJECT

	public:
		PlaylistsControllerFactory(PlaylistsRepository* repository, PlaylistFactory* factory, SailPlayerState* state);
		~PlaylistsControllerFactory();

		Q_INVOKABLE QObject* create();

	private:
		PlaylistsRepository* _repository;
		PlaylistFactory* _factory;
		SailPlayerState* _state;
	};
}

#endif // PLAYLISTSCONTROLLERFACTORY_H
