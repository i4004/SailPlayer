#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QQuickView>

#include "Audio/AudioPlayer.hpp"
#include "Models/PlaylistModel.hpp"
#include "PlayController.hpp"
#include "Playlist/PlaylistController.hpp"
#include "SailPlayerSettings.hpp"

using namespace Audio;
using namespace Models;
using namespace Playlist;

class SailPlayerController
{
public:
	SailPlayerController(QQuickView* view);
	~SailPlayerController();

private:
	SailPlayerSettings _settings;
	PlaylistModel _playlist;
	AudioPlayer _player;
	PlayController* _playController;
	PlaylistController* _playlistController;

	void ExposeComponentsToQml(QQuickView* view);
	void LoadStartupSettings();
	void SaveOnExitSettings();
};

#endif // SAILPLAYERCONTROLLER_HPP
