#ifndef PLAYLISTSMODEL_H
#define PLAYLISTSMODEL_H

#include "../Model/ListModel.hpp"
#include "../Playlists/Playlist.hpp"

using namespace Model;

namespace Playlists
{
	class PlaylistsModel : public ListModel<Playlist>
	{
		Q_OBJECT

	public:
		PlaylistsModel(QObject* parent = nullptr);
		~PlaylistsModel();

		// Item control

		Playlist* GetItem(int id);

		void RenameItem(int id, QString name);

		bool DeleteItemByID(int id);

		// Service methods
		QVariant GetItemData(int role, Playlist* item) const;
	};
}

#endif // PLAYLISTSMODEL_H
