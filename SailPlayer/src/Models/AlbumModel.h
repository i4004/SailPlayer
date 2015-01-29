#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractListModel>

#include "../Playlist/Track.h"

using namespace Playlist;

namespace Models
{
	class AlbumModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit AlbumModel(QObject* parent = 0);
		~AlbumModel();

		// List View methods

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

		// Info

		QString GetArtistName() { return _artistName; }
		QString GetAlbumName() { return _albumName; }

	private:
		QString _artistName;
		QString _albumName;
		QList<Track*> _tracksList;
		QHash<int, QByteArray> _rolesNames;

		void Cleanup();
	};
}

//Q_DECLARE_METATYPE(Models::AlbumModel)

#endif // ALBUMMODEL_H
