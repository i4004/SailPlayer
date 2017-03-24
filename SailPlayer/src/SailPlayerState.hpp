#ifndef SAILPLAYERSTATE_H
#define SAILPLAYERSTATE_H

#include <QObject>

#include "Playlists/Playlist.hpp"

using namespace Playlists;

class SailPlayerState : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool isPlaylistActive READ GetIsPlaylistActive)
	Q_PROPERTY(int activePlaylistID READ GetActivePlaylistID)
	Q_PROPERTY(QString activePlaylistName READ GetActivePlaylistName NOTIFY ActivePlaylistNameChanged)

public:
	SailPlayerState();

	// Active playlist

	void SetActivePlaylist(Playlist* playlist);
	bool GetIsPlaylistActive();
	int GetActivePlaylistID();
	QString GetActivePlaylistName();

signals:
	void ActivePlaylistNameChanged();

private:
	Playlist* _activePlaylist;
};

#endif // SAILPLAYERSTATE_H
