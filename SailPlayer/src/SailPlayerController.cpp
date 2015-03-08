#include <QQmlContext>
#include <QDebug>

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController(QQuickView* view)
{
	_playController = new PlayController(_player, _playlist);
	_playlistController = new PlaylistController(_playlist);

	LoadStartupSettings();
	ExposeComponentsToQml(view);
}

SailPlayerController::~SailPlayerController()
{
	delete _playController;

	SaveOnExitSettings();
}

void SailPlayerController::ExposeComponentsToQml(QQuickView* view)
{
	view->rootContext()->setContextProperty("settings", &_settings);
	view->rootContext()->setContextProperty("playlist", &_playlist);
	view->rootContext()->setContextProperty("player", &_player);
	view->rootContext()->setContextProperty("playController", _playController);
	view->rootContext()->setContextProperty("playlistController", _playlistController);
}

void SailPlayerController::LoadStartupSettings()
{
	_playlist.SetPlayOrder(_settings.GetPlayOrder());
	_playlist.AddTracks(_settings.GetPlaylist());

	bool restoreLastPlayingPosition = _settings.GetRestoreLastPlayingPosition();
	int lastTrackIndex = _settings.GetLastTrackIndex();
	int lastPlayingPosition = _settings.GetLastPlayingPosition();

	if(restoreLastPlayingPosition)
		_playController->SetStartupData(lastTrackIndex, lastPlayingPosition);
}

void SailPlayerController::SaveOnExitSettings()
{
	_settings.SetPlayOrder(_playlist.GetPlayOrder());
	_settings.SetPlaylist(_playlist.GetTracks());
	_settings.SetLastTrackIndex(_playlist.GetCurrentTrackIndex());
	_settings.SetLastPlayingPosition(_player.GetCurrentTrackPosition());
}
