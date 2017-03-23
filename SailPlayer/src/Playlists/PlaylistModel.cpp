#include "PlaylistModel.hpp"

namespace Playlists
{
	QChar PlaylistModel::SectionSeparator = 0x0001;

	PlaylistModel::PlaylistModel(QObject* parent) : ListModel<Track>(parent)
	{
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
				return item->GetArtistName() + SectionSeparator + QString::number(item->GetAlbumYear()) +  SectionSeparator + item->GetAlbumName();\

//			case IsTrackToPlay:
//				return item->IsTrackToPlay();

//			case IsPlayingRole:
//				return item->IsPlaying();

			default:
				return QVariant();
		}
	}
}
