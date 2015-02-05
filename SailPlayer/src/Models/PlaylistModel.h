#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

#include "../Playlist/TracksLoader.h"
#include "../Playlist/DirectoryRecursiveMultimediaFilesListFactory.h"
#include "../Playlist/TracksFactory.h"
#include "../Playlist/Track.h"
#include "../SailPlayerSettings.h"

using namespace Playlist;

namespace Models
{
	class PlaylistModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit PlaylistModel(QObject* parent = 0);
		~PlaylistModel();

		// List View methods

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

		// Playlist controls

		Q_INVOKABLE void addTracks(QString directoryPath);

		Q_INVOKABLE void clearPlaylist();

		// Load playlist from settings
		Q_INVOKABLE void loadPlaylist();

		// Save playlist to settings
		Q_INVOKABLE void savePlaylist();

		Q_INVOKABLE QString getTrackToPlayPath();

		Q_INVOKABLE bool forceTrackToPlay(int index);

		// Find next track by order rules and set it to play, default is first track
		Q_INVOKABLE bool setNextTrackToPlay();

		Q_INVOKABLE void toggleSelectTrack(int itemIndex);

		// Mark track to play as playing unmarking previously playing track
		Q_INVOKABLE void setPlayingTrack(bool isPlaying);

		void AddTracks(QList<Track*> tracks);

	signals:
		int	currentTrackDurationUpdated(int duration);

	private:
		static QChar SectionSeparator;

		TracksLoader* _tracksLoader;
		TracksFactory _tracksFactory;
		DirectoryRecursiveMultimediaFilesListFactory _filesFactory;

		SailPlayerSettings _settings;

		QList<Track*> _tracksList;
		QHash<int, QByteArray> _rolesNames;

		// Current playing data

		int _currentTrackIndex;
		Track* _currentTrackToPlay;
		Track* _currentPlayingTrack;

		void Cleanup();
		void SetTrackToPlay(int index);
		bool CalculateNextTrack(int customIndex);
	};
}

#endif // PLAYLISTMODEL_H
