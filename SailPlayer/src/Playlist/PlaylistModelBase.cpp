#include "PlaylistModelBase.hpp"

#ifdef _DEBUG
#include <QDebug>
#endif

namespace Playlist
{
	QChar PlaylistModelBase::SectionSeparator = 0x0001;

	PlaylistModelBase::PlaylistModelBase(QObject* parent) : QAbstractListModel(parent)
	{
		_rolesNames = QAbstractListModel::roleNames();
		_rolesNames.insert(ArtistNameRole, QByteArray("artistName"));
		_rolesNames.insert(AlbumNameRole, QByteArray("albumName"));
		_rolesNames.insert(AlbumYearRole, QByteArray("albumYear"));
		_rolesNames.insert(TrackNumberRole, QByteArray("trackNumber"));
		_rolesNames.insert(TrackNameRole, QByteArray("trackName"));
		_rolesNames.insert(TrackDurationRole, QByteArray("trackDuration"));
		_rolesNames.insert(TrackFileName, QByteArray("trackFileName"));
		_rolesNames.insert(SectionRole, QByteArray("section"));
		_rolesNames.insert(IsTrackToPlay, QByteArray("isTrackToPlay"));
		_rolesNames.insert(IsPlayingRole, QByteArray("isPlaying"));
	}

	PlaylistModelBase::~PlaylistModelBase()
	{
		DeleteTracks();
	}

	int PlaylistModelBase::rowCount(const QModelIndex &parent) const
	{
		#ifdef _DEBUG
		qDebug() << "Begin";
		#endif

		Q_UNUSED(parent);

		return _tracksList.count();

		#ifdef _DEBUG
		qDebug() << "End";
		#endif
	}

	QVariant PlaylistModelBase::data(const QModelIndex &index, int role) const
	{
//		#ifdef _DEBUG
//		qDebug() << "Get data";
//		#endif

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

			case IsTrackToPlay:
				return item->IsTrackToPlay();

			case IsPlayingRole:
				return item->IsPlaying();

			default:
				return QVariant();
		}
	}

	void PlaylistModelBase::AddTracks(QList<Track*> tracks)
	{
		if(tracks.count() == 0)
			return;

		beginInsertRows(QModelIndex(), _tracksList.count(), _tracksList.count() + tracks.count() - 1);
		_tracksList.append(tracks);
		endInsertRows();
	}

	QList<Track*> PlaylistModelBase::GetTracks()
	{
		#ifdef _DEBUG
		qDebug() << "Get playlist tracks";
		#endif

		return _tracksList;
	}

	void PlaylistModelBase::DeleteTracks()
	{
        #ifdef _DEBUG
		qDebug() << "Begin";
        #endif

		while (!_tracksList.isEmpty())
			delete _tracksList.takeFirst();

        #ifdef _DEBUG
		qDebug() << "End";
        #endif
	}
}
