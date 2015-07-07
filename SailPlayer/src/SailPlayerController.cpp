#include <QQmlContext>

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController(QQuickView* view)
{
	_lastFmController = new LastFmController(_scrobbler, _settings);
	_playlistController = new PlaylistController(_playlist, _settings);
	_playController = new PlayController(_player, _playlist, *_lastFmController);

	LoadStartupSettings();

	connect(&_settings, SIGNAL(LastFmSessionKeyChanged(QString)), &_scrobbler, SLOT(SetSessionKey(QString)));
	connect(&_settings, SIGNAL(ScrobblingIsEnabledChanged(bool)), _playController, SLOT(SetScrobblingIsEnabled(bool)));

	ExposeComponentsToQml(view);
}

SailPlayerController::~SailPlayerController()
{
	delete _playController;
	delete _playlistController;
	delete _lastFmController;

	SaveOnExitSettings();
}

void SailPlayerController::ExposeComponentsToQml(QQuickView* view)
{
	view->rootContext()->setContextProperty("settings", &_settings);
	view->rootContext()->setContextProperty("playlist", &_playlist);
	view->rootContext()->setContextProperty("player", &_player);
	view->rootContext()->setContextProperty("scrobbler", &_scrobbler);
	view->rootContext()->setContextProperty("playController", _playController);
	view->rootContext()->setContextProperty("playlistController", _playlistController);
	view->rootContext()->setContextProperty("lastFmController", _lastFmController);
}

void SailPlayerController::LoadStartupSettings()
{
	_playlist.SetPlayOrder(_settings.GetPlayOrder());
	_playlist.AddTracks(_settings.GetPlaylist());

	_scrobbler.SetSessionKey(_settings.GetLastFmSessionKey());
	_playController->SetScrobblingIsEnabled(_settings.GetScrobblingIsEnabled());
	int lastTrackIndex = _settings.GetLastTrackIndex();

	if(_settings.GetRestoreLastPlayingTrack() && lastTrackIndex < _playlist.rowCount())
	{
		_playController->SetStartupTrackPosition(_settings.GetRestoreLastPlayingTrackPosition() ? _settings.GetLastPlayingPosition() : 0);
		_playController->SetStartupTrack(lastTrackIndex);
	}
}

void SailPlayerController::SaveOnExitSettings()
{
	_settings.SetPlayOrder(_playlist.GetPlayOrder());
	_settings.SetLastTrackIndex(_playlist.GetCurrentTrackIndex());
	_settings.SetLastPlayingPosition(_player.GetCurrentTrackPosition());
}
