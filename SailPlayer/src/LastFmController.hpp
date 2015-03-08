#ifndef LASTFMCONTROLLER_HPP
#define LASTFMCONTROLLER_HPP

#include <QObject>

#include "Net/LastFmScrobbler.hpp"
#include "SailPlayerSettings.hpp"

using namespace Net;

class LastFmController : public QObject
{
	Q_OBJECT

public:
	LastFmController();
	LastFmController(LastFmScrobbler& scrobbler, SailPlayerSettings& settings);

	Q_INVOKABLE void authenticate(QString userName, QString password);
	Q_INVOKABLE void sendNowPlaying(Track* currentPlayingTrack);
	Q_INVOKABLE void scrobbleTrack(Track* playedTrack, QDateTime playStartTime);
	Q_INVOKABLE void scrobbleTracksFromCache();

public slots:
	void OnTracksSubmitted();

private:
	LastFmScrobbler& _scrobbler;
	SailPlayerSettings& _settings;
};

#endif // LASTFMCONTROLLER_HPP
