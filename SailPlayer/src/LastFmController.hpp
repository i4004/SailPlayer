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
	~LastFmController();

	Q_INVOKABLE void authenticate(QString userName, QString password);
	Q_INVOKABLE void sendNowPlaying(Track* track, QDateTime trackPlayStartTime);
	Q_INVOKABLE void scrobbleCurrentPlayingTrack();
	Q_INVOKABLE void scrobbleTracksFromCache();
	Q_INVOKABLE void clearCache();

public slots:
	void OnTracksSubmitted();

private:
	LastFmScrobbler& _scrobbler;
	SailPlayerSettings& _settings;

	Track* _currentPlayingTrack;
	QDateTime _currentPlayingTrackPlayStartTime;

	void CleanupCurrentPlayingTrack();
};

#endif // LASTFMCONTROLLER_HPP
