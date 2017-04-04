#include "PlaylistModel.hpp"
#include <QQmlEngine>

namespace Playlists
{
	QChar PlaylistModel::SectionSeparator = 0x0001;

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
//		IsTrackToPlay = Qt::UserRole + 9,
//		IsPlayingRole = Qt::UserRole + 10
	};

	PlaylistModel::PlaylistModel(QObject* parent) : ListModel<Track>(parent)
	{
		QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);

		AddRole(ArtistNameRole, QByteArray("artistName"));
		AddRole(AlbumNameRole, QByteArray("albumName"));
		AddRole(AlbumYearRole, QByteArray("albumYear"));
		AddRole(TrackNumberRole, QByteArray("trackNumber"));
		AddRole(TrackNameRole, QByteArray("trackName"));
		AddRole(TrackDurationRole, QByteArray("trackDuration"));
		AddRole(TrackFileName, QByteArray("trackFileName"));
		AddRole(SectionRole, QByteArray("section"));

//		AddRole(IsTrackToPlay, QByteArray("isTrackToPlay"));
//		AddRole(IsPlayingRole, QByteArray("isPlaying"));
	}

	QVariant PlaylistModel::GetItemData(int role, Track* item) const
	{
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

//			case IsTrackToPlay:
//				return item->IsTrackToPlay();

//			case IsPlayingRole:
//				return item->IsPlaying();

			default:
				return QVariant();
		}
	}
}
