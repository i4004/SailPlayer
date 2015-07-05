#include "LastFmController.hpp"

LastFmController::LastFmController(LastFmScrobbler& scrobbler, SailPlayerSettings& settings) : _scrobbler(scrobbler), _settings(settings)
{
	_currentPlayingTrack = NULL;

	connect(&_scrobbler, SIGNAL(TracksSubmitted()), this, SLOT(OnTracksSubmitted()));

	_scrobbler.AddToCache(_settings.GetCachedTracks());
}

LastFmController::~LastFmController()
{
	CleanupCurrentPlayingTrack();
}

void LastFmController::authenticate(QString userName, QString password)
{
	_scrobbler.Authenticate(userName, password);
}

void LastFmController::sendNowPlaying(Track* track, QDateTime trackPlayStartTime)
{
	CleanupCurrentPlayingTrack();

	_currentPlayingTrack = new Track(*track);
	_currentPlayingTrackPlayStartTime = trackPlayStartTime;

	_scrobbler.SendNowPlaying(_currentPlayingTrack);
}

void LastFmController::scrobbleCurrentPlayingTrack()
{
	if(_currentPlayingTrack == NULL)
		return;

	bool result = _scrobbler.AddToCache(_currentPlayingTrack, _currentPlayingTrackPlayStartTime);

	if(result)
		_settings.SetCachedTracks(_scrobbler.GetCache());

	_scrobbler.ScrobbleTracksFromCache();

	_currentPlayingTrack = NULL;
}

void LastFmController::scrobbleTracksFromCache()
{
	_scrobbler.ScrobbleTracksFromCache();
}

void LastFmController::clearCache()
{
	_scrobbler.ClearCache();
	_settings.ClearCachedTracks();
}

void LastFmController::OnTracksSubmitted()
{
	_settings.SetCachedTracks(_scrobbler.GetCache());
}

void LastFmController::CleanupCurrentPlayingTrack()
{
	if(_currentPlayingTrack != NULL)
		delete _currentPlayingTrack;
}
