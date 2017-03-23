#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>

#include "../Model/IdentityObject.hpp"

using namespace Model;

namespace Playlists
{
	class Playlist : public IdentityObject
	{
	public:
		Playlist(int id, QString name);

		inline QString GetName() { return _name; }
		inline void SetName(QString name) { _name =  name; }

	private:
		QString _name;
	};
}

#endif // PLAYLIST_H
