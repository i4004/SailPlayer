#include <QQmlContext>
#include <QDebug>

#include "SailPlayer.hpp"
#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController(QQuickView* view, QObject* parent) : QObject(parent)
{
	_playController = new PlayController(_player, _playlist);

	LoadStartupSettings();
	ExposeComponentsToQml(view);
}

SailPlayerController::~SailPlayerController()
{
	SaveOnExitSettings();

	delete _playController;
}

void SailPlayerController::ExposeComponentsToQml(QQuickView* view)
{
	view->rootContext()->setContextProperty("settings", &_settings);
	view->rootContext()->setContextProperty("playlist", &_playlist);
	view->rootContext()->setContextProperty("player", &_player);
	view->rootContext()->setContextProperty("playController", _playController);
}

void SailPlayerController::LoadStartupSettings()
{
	_playlist.SetPlayOrder(_settings.GetPlayOrder());
	_playlist.AddTracks(_settings.GetPlaylist());

	bool restoreLastPlayingPosition = _settings.GetRestoreLastPlayingPosition();
	bool lastTrackIndex = _settings.GetLastTrackIndex();

	if(restoreLastPlayingPosition && lastTrackIndex != -1)
	{
//				needToSetStartupPosition = true;
		_playlist.calculateAndSetTrackToPlay(SailPlayer::ByIndex, lastTrackIndex);
//				player.pause();
	}
}

void SailPlayerController::SaveOnExitSettings()
{
	_settings.SetPlayOrder(_playlist.GetPlayOrder());
	_settings.SetPlaylist(_playlist.GetTracks());
	_settings.SetLastTrackIndex(_playlist.getCurrentTrackIndex());
}
