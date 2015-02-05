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
		IsTrackToPlay = Qt::UserRole + 10,
		IsPlayingRole = Qt::UserRole + 11
	};

	QChar PlaylistModel::SectionSeparator = 0x0001;

	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_currentTrackIndex= -1;
		_currentTrackToPlay = NULL;
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
		_rolesNames.insert(IsTrackToPlay, QByteArray("isTrackToPlay"));
		_rolesNames.insert(IsPlayingRole, QByteArray("isPlaying"));
	}

	PlaylistModel::~PlaylistModel()
	{		
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

			case IsTrackToPlay:
				return item->IsTrackToPlay();

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

	void PlaylistModel::loadPlaylist()
	{
		AddTracks(_settings.GetPlaylist());
	}

	void PlaylistModel::savePlaylist()
	{
		_settings.SetPlaylist(_tracksList);
	}

	QString PlaylistModel::getTrackToPlayPath()
	{
		if(_currentTrackToPlay == NULL)
			return NULL;

		return _currentTrackToPlay->GetFullFilePath();
	}

	bool PlaylistModel::forceTrackToPlay(int index)
	{
		if(!CalculateNextTrack(index))
			return false;

		SetTrackToPlay(_currentTrackIndex);
	}

	bool PlaylistModel::setNextTrackToPlay()
	{
		if(!CalculateNextTrack(-1))
			return false;

		SetTrackToPlay(_currentTrackIndex);

		return true;
	}

	void PlaylistModel::toggleSelectTrack(int itemIndex)
	{
		Track* track = _tracksList.at(itemIndex);

		track->SetSelected(!track->IsSelected());

		emit dataChanged(index(itemIndex, 0), index(itemIndex, 0), QVector<int>(1, IsSelectedRole));
	}

	void PlaylistModel::setPlayingTrack(bool isPlaying)
	{
		if(_currentPlayingTrack != NULL)
			_currentPlayingTrack->SetPlaying(false);

		_currentPlayingTrack = _currentTrackToPlay;

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

	void PlaylistModel::SetTrackToPlay(int itemIndex)
	{
		if(_currentTrackToPlay != NULL)
			_currentTrackToPlay->SetAsTrackToPlay(false);

		_currentTrackToPlay = _tracksList.at(itemIndex);

		_currentTrackToPlay->SetAsTrackToPlay(true);

		emit dataChanged(index(0, 0), index(_tracksList.count() - 1, 0), QVector<int>(1, IsTrackToPlay));
		emit currentTrackDurationUpdated(_currentTrackToPlay->GetDuration());
	}

	bool PlaylistModel::CalculateNextTrack(int customIndex)
	{
		if(_tracksList.count() == 0)
			return false;

		if(_currentTrackIndex == -1)
			_currentTrackIndex = 0;
		else
		{
			if(customIndex > -1)
				_currentTrackIndex++;
			else
				_currentTrackIndex = customIndex;
		}

		if(_currentTrackIndex >= _tracksList.count())
			_currentTrackIndex = 0;

		return true;
	}
}
