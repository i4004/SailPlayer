#include "Audio/AudioPlayerEnums.hpp"
#include "Playlist/PlaylistEnums.hpp"

#include "PlayController.hpp"

using namespace Audio;
using namespace Playlist;

PlayController::PlayController(AudioPlayer& player, PlaylistModel& playlist) : _player(player), _playlist(playlist)
{
	connect(&_playlist, SIGNAL(CurrentTrackToPlayDataUpdated(QString, int, int)), &_player, SLOT(SetTrackToPlay(QString, int, int)));
	connect(&_player, SIGNAL(StateChanged(AudioPlayerEnums::AudioPlayerState)), &_playlist, SLOT(SetPlayerState(AudioPlayerEnums::AudioPlayerState)));
	//			player.playbackError.connect(messagePage.displayMessage);
}

PlayController::~PlayController()
{
	if(_player.GetCurrentState() == AudioPlayerEnums::Playing)
		_player.Pause();
}

void PlayController::playPause()
{
	AudioPlayerEnums::AudioPlayerState state = _player.GetCurrentState();

	if(state == AudioPlayerEnums::Playing)
		_player.Pause();
	else
	{
		if(state == AudioPlayerEnums::Ready && !_playlist.HasTrackToPlay())
			_playlist.CalculateAndSetTrackToPlay();

		if(_player.HasTrackToPlay())
			_player.Play();
	}
}

void PlayController::stop()
{
	AudioPlayerEnums::AudioPlayerState state = _player.GetCurrentState();

	if(state != AudioPlayerEnums::Ready)
		_player.Stop();
}

void PlayController::previous()
{
	AudioPlayerEnums::AudioPlayerState state = _player.GetCurrentState();

	if(state != AudioPlayerEnums::Ready)
		_player.Stop();

	if(_playlist.CalculateAndSetTrackToPlay(PlaylistEnums::Previous) && state != AudioPlayerEnums::Ready)
		_player.Play();
}

void PlayController::playTrack(int trackIndex)
{
	AudioPlayerEnums::AudioPlayerState state = _player.GetCurrentState();

	if(state != AudioPlayerEnums::Ready)
		_player.Stop();

	if(_playlist.CalculateAndSetTrackToPlay(PlaylistEnums::ByIndex, trackIndex))
		_player.Play();
}

void PlayController::next()
{
	AudioPlayerEnums::AudioPlayerState state = _player.GetCurrentState();

	if(state != AudioPlayerEnums::Ready)
		_player.Stop();

	if(_playlist.CalculateAndSetTrackToPlay(PlaylistEnums::NextWithForce) && state != AudioPlayerEnums::Ready)
		_player.Play();
}

void PlayController::seek(int position)
{
	_player.SeekInTrack(position);
}
