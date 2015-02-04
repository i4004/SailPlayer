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
		TrackFileName = Qt::UserRole + 7,
		SectionRole = Qt::UserRole + 8
	};

	QChar PlaylistModel::SectionSeparator = 0x0001;

	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_currentTrack = NULL;
		_tracksLoader = new TracksLoader(_tracksFactory, _filesFactory);

		_rolesNames = QAbstractListModel::roleNames();
		_rolesNames.insert(ArtistNameRole, QByteArray("artistName"));
		_rolesNames.insert(AlbumNameRole, QByteArray("albumName"));
		_rolesNames.insert(AlbumYearRole, QByteArray("albumYear"));
		_rolesNames.insert(TrackNumberRole, QByteArray("trackNumber"));
		_rolesNames.insert(TrackNameRole, QByteArray("trackName"));
		_rolesNames.insert(TrackDurationRole, QByteArray("trackDuration"));
		_rolesNames.insert(TrackFileName, QByteArray("trackFileName"));
		_rolesNames.insert(SectionRole, QByteArray("section"));

		LoadPlaylist();
		setTrackForPlaying(0);
	}

	PlaylistModel::~PlaylistModel()
	{		
		SavePlaylist();
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

			case TrackFileName:
				return item->GetFileName();

			case SectionRole:
				return item->GetArtistName() + SectionSeparator + QString::number(item->GetAlbumYear()) +  SectionSeparator + item->GetAlbumName();

			default:
				return QVariant();
		}
	}

	void PlaylistModel::addTracks(QString directoryPath)
	{
		_filesFactory.SetDirectoryPath(directoryPath);
		AddTracks(_tracksLoader->Build());
	}

	void PlaylistModel::AddTracks(QList<Track*> tracks)
	{
		beginResetModel();
		_tracksList.append(tracks);
		endResetModel();
	}

	void PlaylistModel::LoadPlaylist()
	{
		AddTracks(_settings.GetPlaylist());
	}

	void PlaylistModel::SavePlaylist()
	{
		_settings.SetPlaylist(_tracksList);
	}

	void PlaylistModel::clearPlaylist()
	{
		beginResetModel();
		Cleanup();
		endResetModel();
	}

	QString PlaylistModel::getTrackPathForPlaying()
	{
		if(_currentTrack == NULL)
			return NULL;

		return _currentTrack->GetFullFilePath();
	}

	void PlaylistModel::setTrackForPlaying(int index)
	{
		if(_tracksList.count() == 0 || index >= _tracksList.count())
			return;

		_currentTrack = _tracksList.at(index);
	}
}
