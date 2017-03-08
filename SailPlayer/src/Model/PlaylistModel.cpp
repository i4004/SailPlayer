#include "PlaylistModel.hpp"

namespace Model
{
	QChar PlaylistModel::SectionSeparator = 0x0001;

	PlaylistModel::PlaylistModel(QObject* parent) : ListModel<Track>(parent)
	{
		_rolesNames.insert(ArtistNameRole, QByteArray("artistName"));
		_rolesNames.insert(AlbumNameRole, QByteArray("albumName"));
		_rolesNames.insert(AlbumYearRole, QByteArray("albumYear"));
		_rolesNames.insert(TrackNumberRole, QByteArray("trackNumber"));
		_rolesNames.insert(TrackNameRole, QByteArray("trackName"));
		_rolesNames.insert(TrackDurationRole, QByteArray("trackDuration"));
		_rolesNames.insert(TrackFileName, QByteArray("trackFileName"));
		_rolesNames.insert(SectionRole, QByteArray("section"));
//		_rolesNames.insert(IsTrackToPlay, QByteArray("isTrackToPlay"));
//		_rolesNames.insert(IsPlayingRole, QByteArray("isPlaying"));
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
