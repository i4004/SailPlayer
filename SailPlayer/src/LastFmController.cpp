#include "LastFmController.hpp"

LastFmController::LastFmController(LastFmScrobbler& scrobbler, SailPlayerSettings& settings) : _scrobbler(scrobbler), _settings(settings)
{
	connect(&_scrobbler, SIGNAL(TracksSubmitted()), this, SLOT(OnTracksSubmitted()));

	_scrobbler.AddToCache(_settings.GetCachedTracks());
}

void LastFmController::authenticate(QString userName, QString password)
{
	_scrobbler.Authenticate(userName, password);
}

void LastFmController::sendNowPlaying(Track* currentPlayingTrack)
{
	_scrobbler.SendNowPlaying(currentPlayingTrack);
}

void LastFmController::scrobbleTrack(Track* playedTrack, QDateTime playStartTime)
{
	bool result = _scrobbler.AddToCache(new Track(*playedTrack), playStartTime);

	if(result)
		_settings.SetCachedTracks(_scrobbler.GetCache());

	_scrobbler.ScrobbleTracksFromCache();
}

void LastFmController::scrobbleTracksFromCache()
{
	_scrobbler.ScrobbleTracksFromCache();
}

void LastFmController::OnTracksSubmitted()
{
	_settings.SetCachedTracks(_scrobbler.GetCache());
}
