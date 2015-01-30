#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

#include "AlbumModel.h"
#include "../Playlist/TracksLoader.h"
#include "../Playlist/DirectoryRecursiveMultimediaFilesListFactory.h"
#include "../Playlist/TracksFactory.h"
#include "../Playlist/Track.h"
#include "AlbumModelsFactory.h"
#include <QtQml>

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

		Q_INVOKABLE QObject* getAlbumModel(int index) const;

		// Playlist controls

		Q_INVOKABLE void addTracks(QString directoryPath);

	private:
		TracksLoader* _tracksLoader;
		TracksFactory _tracksFactory;
		DirectoryRecursiveMultimediaFilesListFactory _filesFactory;
		IAlbumModelsFactory* _albumModelsFactory;

		QList<AlbumModel*> _albumsList;
		QHash<int, QByteArray> _rolesNames;

		void Cleanup();
	};
}

#endif // PLAYLISTMODEL_H
