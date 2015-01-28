#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

#include "../Playlist/Track.h"

using namespace Playlist;

namespace Models
{
	class PlaylistModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit PlaylistModel(QObject* parent = 0);
		~PlaylistModel();

		// List View methods

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	private:
		QList<Track*> _tracksList;

		void Cleanup();
	};
}

#endif // PLAYLISTMODEL_H
