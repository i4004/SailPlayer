#include "Audio/AudioPlayerEnums.hpp"
#include "Playlist/PlaylistEnums.hpp"

#include "PlayController.hpp"

using namespace Audio;
using namespace Playlist;

PlayController::PlayController(AudioPlayer& player, PlaylistModel& playlist) : _player(player), _playlist(playlist)
{
	connect(&_playlist, SIGNAL(CurrentTrackToPlayDataUpdated(QString, int, int)), &_player, SLOT(SetTrackToPlay(QString, int, int)));
	connect(&_player, SIGNAL(stateChanged(AudioPlayerEnums::AudioPlayerState)), &_playlist, SLOT(setPlayerState(AudioPlayerEnums::AudioPlayerState)));
	//			player.playbackError.connect(messagePage.displayMessage);
}

void PlayController::playPause()
{
//	AudioPlayerEnums::AudioPlayerState state = _player.GetCurrentState();

//	if(state == AudioPlayerEnums::Playing)
//		_player.Pause();
//	else
//	{
//		if(state == AudioPlayerEnums::Ready && !_playlist.hasTrackToPlay())
//			_playlist.CalculateAndSetTrackToPlay();

//		if(_player.hasTrackToPlay())
//			_player.Play();
//	}
}

void PlayController::previous()
{
//	AudioPlayerEnums::AudioPlayerState state = _player.GetCurrentState();

//	if(state != AudioPlayerEnums::Ready)
//		_player.Stop();

//	if(_playlist.CalculateAndSetTrackToPlay(PlaylistEnums::Previous) && state != AudioPlayerEnums::Ready)
//		_player.Play();
}

void PlayController::playTrack(int trackIndex)
{
//	_player.Stop();

//	if(_playlist.CalculateAndSetTrackToPlay(PlaylistEnums::ByIndex, trackIndex))
//		_player.Play();
}

void PlayController::next()
{
//	AudioPlayerEnums::AudioPlayerState state = _player.GetCurrentState();

//	if(state != AudioPlayerEnums::Ready)
//		_player.Stop();

//	if(_playlist.CalculateAndSetTrackToPlay(PlaylistEnums::NextWithForce) && state != AudioPlayerEnums::Ready)
//		_player.Play();
}
