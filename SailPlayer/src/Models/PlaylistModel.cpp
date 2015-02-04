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
		SectionRole = Qt::UserRole + 8,
		IsSelectedRole = Qt::UserRole + 9,
		IsPlayingRole = Qt::UserRole + 10
	};

	QChar PlaylistModel::SectionSeparator = 0x0001;

	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_currentTrackForPlaying = NULL;
		_currentPlayingTrack = NULL;
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
		_rolesNames.insert(IsSelectedRole, QByteArray("isSelected"));
		_rolesNames.insert(IsPlayingRole, QByteArray("isPlaying"));

		LoadPlaylist();
		setTrackForPlaying(0);
	}

	PlaylistModel::~PlaylistModel()
	{		
		SavePlaylist();
		Cleanup();

		delete _tracksLoader;
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
				return item->GetArtistName() + SectionSeparator + QString::number(item->GetAlbumYear()) +  SectionSeparator + item->GetAlbumName();\

			case IsSelectedRole:
				return item->IsSelected();

			case IsPlayingRole:
				return item->IsPlaying();

			default:
				return QVariant();
		}
	}

	void PlaylistModel::addTracks(QString directoryPath)
	{
		_filesFactory.SetDirectoryPath(directoryPath);
		AddTracks(_tracksLoader->Build());
	}

	void PlaylistModel::clearPlaylist()
	{
		beginResetModel();
		Cleanup();
		endResetModel();
	}

	QString PlaylistModel::getTrackPathForPlaying()
	{
		if(_currentTrackForPlaying == NULL)
			return NULL;

		return _currentTrackForPlaying->GetFullFilePath();
	}

	void PlaylistModel::setTrackForPlaying(int itemIndex)
	{
		if(_tracksList.count() == 0 || itemIndex >= _tracksList.count())
			return;

		_currentTrackForPlaying = _tracksList.at(itemIndex);

		emit dataChanged(index(itemIndex, 0), index(itemIndex, 0));
	}

	void PlaylistModel::toggleSelectTrack(int itemIndex)
	{
		Track* track = _tracksList.at(itemIndex);

		track->SetSelected(!track->IsSelected());

		emit dataChanged(index(itemIndex, 0), index(itemIndex, 0), QVector<int>(1, IsSelectedRole));
	}

	void PlaylistModel::setPlaying(bool isPlaying)
	{
		if(_currentPlayingTrack != NULL)
			_currentPlayingTrack->SetPlaying(false);

		_currentPlayingTrack = _currentTrackForPlaying;

		if(_currentPlayingTrack != NULL)
			_currentPlayingTrack->SetPlaying(isPlaying);

		emit dataChanged(index(0, 0), index(_tracksList.count() - 1, 0), QVector<int>(1, IsPlayingRole));
	}

	void PlaylistModel::AddTracks(QList<Track*> tracks)
	{
		beginResetModel();
		_tracksList.append(tracks);
		endResetModel();
	}

	void PlaylistModel::Cleanup()
	{
		while (!_tracksList.isEmpty())
			delete _tracksList.takeFirst();
	}

	void PlaylistModel::LoadPlaylist()
	{
		AddTracks(_settings.GetPlaylist());
	}

	void PlaylistModel::SavePlaylist()
	{
		_settings.SetPlaylist(_tracksList);
	}
}
