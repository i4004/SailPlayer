#include "SailPlayer.hpp"

#include "PlayController.hpp"

PlayController::PlayController(AudioPlayer& player, PlaylistModel& playlist) : _player(player), _playlist(playlist)
{
	connect(&_playlist, SIGNAL(CurrentTrackToPlayDataUpdated(QString, int, int)), &_player, SLOT(SetTrackToPlay(QString, int, int)));

	//			player.stateChanged.connect(playlist.setPlayerState);
	//			player.playbackError.connect(messagePage.displayMessage);
}

void PlayController::play()
{
}

void PlayController::pause()
{
}

void PlayController::stop()
{
}

void PlayController::previous()
{
}

void PlayController::playTrack(int trackIndex)
{
	_player.Stop();

	if(_playlist.calculateAndSetTrackToPlay(SailPlayer::ByIndex, trackIndex))
		_player.Play();
}

void PlayController::next()
{
}
