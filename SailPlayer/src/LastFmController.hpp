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

private:
	LastFmScrobbler& _scrobbler;
	SailPlayerSettings& _settings;
};

#endif // LASTFMCONTROLLER_HPP
