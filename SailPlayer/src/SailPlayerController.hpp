#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "PlayController.hpp"
#include "Playlist/PlaylistController.hpp"

using namespace Audio;
using namespace Models;
using namespace Playlist;

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController(QQuickView* view);
	~SailPlayerController();

private:
	SailPlayerSettings _settings;
	PlaylistModel _playlist;
	AudioPlayer _player;
	LastFmScrobbler _scrobbler;

	PlayController* _playController;
	PlaylistController* _playlistController;

	void ExposeComponentsToQml(QQuickView* view);
	void LoadStartupSettings();
	void SaveOnExitSettings();
};

#endif // SAILPLAYERCONTROLLER_HPP
