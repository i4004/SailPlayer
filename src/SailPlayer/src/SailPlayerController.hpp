#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "EqualizerController.hpp"
#include "LastFmController.hpp"
#include "PlayController.hpp"
#include "PlaylistController.hpp"

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController(QQuickView* view);
	~SailPlayerController();

private:
	SailPlayerSettings _settings;
	PlaylistModel _playlist;
	LastFmScrobbler _scrobbler;
	EqualizerPresetsModel _equalizerPresetsModel;

	AudioPlayer* _player;
	PlayController* _playController;
	PlaylistController* _playlistController;
	LastFmController* _lastFmController;
	EqualizerController* _equalizerController;

	void ExposeComponentsToQml(QQuickView* view);
	void LoadStartupSettings();
	void SaveOnExitSettings();
};

#endif // SAILPLAYERCONTROLLER_HPP
