#include "LastFmController.hpp"

LastFmController::LastFmController(LastFmScrobbler& scrobbler, SailPlayerSettings& settings) : _scrobbler(scrobbler), _settings(settings)
{
	connect(&_scrobbler, SIGNAL(Authenticated(QString)), this, SLOT(OnAuthenticated(QString)));

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
	bool result = _scrobbler.AddToCache(playedTrack, playStartTime);

	if(result)
		_settings.SetCachedTracks(_scrobbler.GetCache());

	_scrobbler.ScrobbleTracksFromCache();
}

void LastFmController::OnAuthenticated(QString sessionKey)
{
	_settings.SetLastFmSessionKey(sessionKey);
}

void LastFmController::OnTracksSubmitted()
{
	_settings.SetCachedTracks(_scrobbler.GetCache());
}
