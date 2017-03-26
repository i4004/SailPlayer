#ifndef SAILPLAYERSTATE_H
#define SAILPLAYERSTATE_H

#include <QObject>

#include "Playlists/Playlist.hpp"

using namespace Playlists;

class SailPlayerState : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool isPlaylistActive READ GetIsPlaylistActive NOTIFY ActivePlaylistChanged)
	Q_PROPERTY(int activePlaylistID READ GetActivePlaylistID NOTIFY ActivePlaylistChanged)
	Q_PROPERTY(QString activePlaylistName READ GetActivePlaylistName NOTIFY ActivePlaylistChanged)

public:
	SailPlayerState();

	// Active playlist

	void SetActivePlaylist(Playlist* playlist);
	bool GetIsPlaylistActive();
	int GetActivePlaylistID();
	QString GetActivePlaylistName();

signals:
	void ActivePlaylistChanged();

private:
	Playlist* _activePlaylist;
};

#endif // SAILPLAYERSTATE_H
