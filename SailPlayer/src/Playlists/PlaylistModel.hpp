#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include "../Model/ListModel.hpp"
#include "../Tracks/Track.hpp"

using namespace Model;
using namespace Tracks;

namespace Playlists
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
		IsTrackToPlay = Qt::UserRole + 9,
		IsPlayingRole = Qt::UserRole + 10
	};

	class PlaylistModel : public ListModel<Track>
	{
		Q_OBJECT

	public:
		PlaylistModel(QObject* parent = 0);

		QVariant GetItemData(int role, Track* item) const;

	private:
		static QChar SectionSeparator;
	};
}

#endif // PLAYLISTMODEL_H
