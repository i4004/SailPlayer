#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

#include "../Playlist/TracksLoader.h"
#include "../Playlist/DirectoryRecursiveMultimediaFilesListFactory.h"
#include "../Playlist/TracksFactory.h"
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
		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

		// Playlist controls

		Q_INVOKABLE void addTracks(QString directoryPath);

	private:
		static QChar SectionSeparator;

		TracksLoader* _tracksLoader;
		TracksFactory _tracksFactory;
		DirectoryRecursiveMultimediaFilesListFactory _filesFactory;

		QList<Track*> _tracksList;
		QHash<int, QByteArray> _rolesNames;

		void Cleanup();
	};
}

#endif // PLAYLISTMODEL_H
