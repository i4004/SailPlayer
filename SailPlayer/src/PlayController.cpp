#include "Audio/AudioPlayerEnums.hpp"
#include "Playlist/PlaylistEnums.hpp"

#include "PlayController.hpp"

using namespace Audio;
using namespace Playlist;

PlayController::PlayController(AudioPlayer& player, PlaylistModel& playlist, LastFmController& lastFmController) : _player(player), _playlist(playlist), _lastFmController(lastFmController)
{
	_needToSetStartupPosition = false;
	_needToSetStartupTrackLastFmNowPlaying = false;
	_scrobblingIsEnabled = false;
	_isScrobbled = false;
	_elapseTimer.setTimerType(Qt::VeryCoarseTimer);
	_elapseTimer.setInterval(1000);
	_elapsed = 0;

	connect(&_playlist, SIGNAL(CurrentTrackToPlayDataUpdated(QString, int, int)), &_player, SLOT(SetTrackToPlay(QString, int, int)));
	connect(&_player, SIGNAL(StateChanged(AudioPlayerEnums::AudioPlayerState)), &_playlist, SLOT(SetPlayerState(AudioPlayerEnums::AudioPlayerState)));

	connect(&_player, SIGNAL(StreamStarted()), this, SLOT(OnStreamStarted()));
	connect(&_player, SIGNAL(AboutToFinish()), this, SLOT(OnAboutToFinish()));
	connect(&_player, SIGNAL(EndOfStream()), this, SLOT(OnEndOfStream()));
	connect(&_player, SIGNAL(StateChanged(AudioPlayerEnums::AudioPlayerState)), this, SLOT(OnStateChanged(AudioPlayerEnums::AudioPlayerState)));

	connect(&_elapseTimer, SIGNAL(timeout()), this, SLOT(OnElapseTimer()));
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

		_needToSetStartupTrackLastFmNowPlaying = true;
	}

	if(_player.IsStreamFromNextTrack() && !_playlist.SetTrackToPlayAndPlayingFromNextTrack())
		_player.Stop();
	else if(!_needToSetStartupTrackLastFmNowPlaying && _scrobblingIsEnabled)
		StartScrobbleMotitoring();
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
	if(state == AudioPlayerEnums::Ready)
		_needToSetStartupTrackLastFmNowPlaying = false;

	if(state == AudioPlayerEnums::Playing)
	{
		if(_scrobblingIsEnabled)
		{
			if(_needToSetStartupTrackLastFmNowPlaying)
			{
				_needToSetStartupTrackLastFmNowPlaying = false;
				StartScrobbleMotitoring();
			}

			_elapseTimer.start();
		}
	}
	else
		_elapseTimer.stop();
}

void PlayController::SetScrobblingIsEnabled(bool enabled)
{
	_scrobblingIsEnabled = enabled;
}

void PlayController::StartScrobbleMotitoring()
{
	_trackPlayStartTime = QDateTime::currentDateTime();
	_lastFmController.sendNowPlaying(_playlist.GetCurrentPlayingTrack());
	_elapsed = 0;
	_isScrobbled = false;
}

void PlayController::OnElapseTimer()
{
	_elapsed++;
	int currentDuration = _player.GetCurrentDuration();

	// If track duration is more than 5 seconds and is played more than half of track length or more than 4 minutes
	if(!_isScrobbled && currentDuration > 5000 && (_elapsed * 1000 >= currentDuration / 2 || _elapsed >= 2401000))
	{
		_isScrobbled = true;
		_lastFmController.scrobbleTrack(_playlist.GetCurrentPlayingTrack(), _trackPlayStartTime);
	}
}
