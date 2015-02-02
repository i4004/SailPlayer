#include "PlaylistModel.h"

namespace Models
{
	enum PlaylistModelRoles
	{
		ArtistNameRole = Qt::UserRole + 1,
		AlbumNameRole = Qt::UserRole + 2,
		AlbumYearRole = Qt::UserRole + 3,
		TrackNumberRole = Qt::UserRole + 4,
		TrackNameRole = Qt::UserRole + 5,
		TrackDurationRole = Qt::UserRole + 6,
		SectionRole = Qt::UserRole + 7
	};

	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_tracksLoader = new TracksLoader(_tracksFactory, _filesFactory);

		_rolesNames = QAbstractListModel::roleNames();
		_rolesNames.insert(ArtistNameRole, QByteArray("artistName"));
		_rolesNames.insert(AlbumNameRole, QByteArray("albumName"));
		_rolesNames.insert(AlbumYearRole, QByteArray("albumYear"));
		_rolesNames.insert(TrackNumberRole, QByteArray("trackNumber"));
		_rolesNames.insert(TrackNameRole, QByteArray("trackName"));
		_rolesNames.insert(TrackDurationRole, QByteArray("trackDuration"));
		_rolesNames.insert(SectionRole, QByteArray("section"));
	}

	PlaylistModel::~PlaylistModel()
	{
		Cleanup();

		delete _tracksLoader;
	}

	void PlaylistModel::Cleanup()
	{
		while (!_tracksList.isEmpty())
			 delete _tracksList.takeFirst();
	}

	int PlaylistModel::rowCount(const QModelIndex &parent) const
	{
		Q_UNUSED(parent);

		return _tracksList.count();
	}

	QVariant PlaylistModel::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid() || index.row() >= _tracksList.count())
			return QVariant();

		Track* item = _tracksList.at(index.row());

		switch (role)
		{
			case Qt::DisplayRole:

			case ArtistNameRole:
				return item->GetArtistName();

			case AlbumNameRole:
				return item->GetAlbumName();

			case AlbumYearRole:
				return item->GetAlbumYear();

			case TrackNumberRole:
				return item->GetNumber();

			case TrackNameRole:
				return item->GetName();

			case TrackDurationRole:
				return item->GetDuration();

			case SectionRole:
				return item->GetArtistName() + "|" + QString::number(item->GetAlbumYear()) + "|" + item->GetAlbumName();

			default:
				return QVariant();
		}
	}

	void PlaylistModel::addTracks(QString directoryPath)
	{
		_filesFactory.SetDirectoryPath(directoryPath);
		QList<Track*> tracks = _tracksLoader->Build();

		beginResetModel();

		_tracksList.append(tracks);

		endResetModel();		
	}
}
