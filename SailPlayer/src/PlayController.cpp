#include "Audio/AudioPlayerEnums.hpp"
#include "Playlist/PlaylistEnums.hpp"

#include "PlayController.hpp"

#include <QDebug>

using namespace Audio;
using namespace Playlist;

PlayController::PlayController(AudioPlayer& player, PlaylistModel& playlist) : _player(player), _playlist(playlist)
{
	_needToSetStartupPosition = false;

	connect(&_playlist, SIGNAL(CurrentTrackToPlayDataUpdated(QString, int, int)), &_player, SLOT(SetTrackToPlay(QString, int, int)));
	connect(&_player, SIGNAL(StateChanged(AudioPlayerEnums::AudioPlayerState)), &_playlist, SLOT(SetPlayerState(AudioPlayerEnums::AudioPlayerState)));

	connect(&_player, SIGNAL(StreamStarted()), this, SLOT(OnStreamStarted()));
	connect(&_player, SIGNAL(AboutToFinish()), this, SLOT(OnAboutToFinish()));
	connect(&_player, SIGNAL(EndOfStream()), this, SLOT(OnEndOfStream()));
	connect(&_player, SIGNAL(StateChanged(AudioPlayerEnums::AudioPlayerState)), this, SLOT(OnStateChanged(AudioPlayerEnums::AudioPlayerState)));

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

void PlayController::SetStartupData(int trackIndex, int position)
{
	if(trackIndex != -1)
	{
		_needToSetStartupPosition = true;
		_startupPosition = position;
		_playlist.CalculateAndSetTrackToPlay(PlaylistEnums::ByIndex, trackIndex);
		_player.Pause();
	}
}

void PlayController::seek(int position)
{
	_player.SeekInTrack(position);
}

void PlayController::OnStreamStarted()
{
	if(_needToSetStartupPosition)
	{
		_needToSetStartupPosition = false;

		if(_startupPosition != -1)
			_player.SeekInTrack(_startupPosition);

//		needToSetStartupTrackLastFmNowPlaying = true;
	}

	if(_player.IsStreamFromNextTrack() && !_playlist.SetTrackToPlayAndPlayingFromNextTrack())
		_player.Stop();
//			else if(!needToSetStartupTrackLastFmNowPlaying && settings.scrobblingIsEnabled)
//				startScrobbleMotitoring();
}

void PlayController::OnAboutToFinish()
{
	_player.SetNextTrackToPlay(_playlist.RequestNextTrack(), _playlist.GetNextStartPosition(), _playlist.GetNextEndPosition());
}

void PlayController::OnEndOfStream()
{
	_player.Stop();
}

void PlayController::OnStateChanged(AudioPlayerEnums::AudioPlayerState state)
{
//	if(state == AudioPlayerState.Ready)
//			needToSetStartupTrackLastFmNowPlaying = false;

	//			if(state == AudioPlayerState.Playing)
	//			{
	//				if(settings.scrobblingIsEnabled)
	//				{
	//					if(needToSetStartupTrackLastFmNowPlaying)
	//					{
	//						needToSetStartupTrackLastFmNowPlaying = false;
	//						startScrobbleMotitoring();
	//					}

	//					elapseTimer.start();
	//				}
	//			}
	//			else
	//				elapseTimer.stop();

	//		function startScrobbleMotitoring()
	//		{
	//			elapseTimer.startTime = new Date();
	//			scrobbler.sendNowPlaying(playlist.getCurrentPlayingTrack());
	//			elapseTimer.elapsed = 0;
	//			scrobbler.scrobbled = false;
	//		}
}
