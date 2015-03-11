#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "EqualizerController.hpp"
#include "LastFmController.hpp"
#include "PlayController.hpp"
#include "PlaylistController.hpp"

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
	EqualizerController _equalizerController;

	PlayController* _playController;
	PlaylistController* _playlistController;
	LastFmController* _lastFmController;

	void ExposeComponentsToQml(QQuickView* view);
	void LoadStartupSettings();
	void SaveOnExitSettings();
};

#endif // SAILPLAYERCONTROLLER_HPP
