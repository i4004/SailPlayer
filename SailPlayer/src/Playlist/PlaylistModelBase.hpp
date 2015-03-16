#ifndef PLAYLISTMODELBASE_HPP
#define PLAYLISTMODELBASE_HPP

#include <QAbstractListModel>

#include "Track.hpp"

namespace Playlist
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

	class PlaylistModelBase : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit PlaylistModelBase(QObject* parent = 0);
		~PlaylistModelBase();

		// List View methods

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

		// Playlist control

		void AddTracks(QList<Track*> tracks);
		QList<Track*> GetTracks() { return _tracksList; }

	protected:	
		QList<Track*> _tracksList;

		void DeleteTracks();

	private:
		static QChar SectionSeparator;

		QHash<int, QByteArray> _rolesNames;
	};
}

#endif // PLAYLISTMODELBASE_HPP
