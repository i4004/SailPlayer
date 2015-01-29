#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

#include "AlbumModel.h"

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
		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

		Q_INVOKABLE AlbumModel* getAlbumModel(int index);

	private:
		QList<AlbumModel*> _albumsList;
		QHash<int, QByteArray> _rolesNames;

		void Cleanup();
	};
}

#endif // PLAYLISTMODEL_H
