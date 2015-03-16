#ifndef PLAYCONTROLLER_HPP
#define PLAYCONTROLLER_HPP

#include <QObject>

#include "Audio/AudioPlayer.hpp"
#include "LastFmController.hpp"
#include "Playlist/PlaylistModel.hpp"

using namespace Audio;
using namespace Playlist;

class PlayController : public QObject
{
	Q_OBJECT

public:
	PlayController(AudioPlayer& player, PlaylistModel& playlist, LastFmController& lastFmController);
	~PlayController();

	Q_INVOKABLE void previous();
	Q_INVOKABLE void playPause();
	Q_INVOKABLE void playTrack(int trackIndex);
	Q_INVOKABLE void stop();
	Q_INVOKABLE void seek(int position);
	Q_INVOKABLE void next();

	void SetStartupData(int trackIndex, int position);

public slots:
	void OnStreamStarted();
	void OnAboutToFinish();
	void OnEndOfStream();
	void OnStateChanged(AudioPlayerEnums::AudioPlayerState state);
	void SetScrobblingIsEnabled(bool enabled);

private:
	AudioPlayer& _player;
	PlaylistModel& _playlist;
	LastFmController& _lastFmController;

	bool _needToSetStartupPosition;
	int _startupPosition;
	int _startupTrackIndex;
	bool _needToSetStartupTrackLastFmNowPlaying;
	bool _scrobblingIsEnabled;
	bool _isScrobbled;
	QTimer _elapseTimer;
	int _elapsed;
	QDateTime _trackPlayStartTime;

	void StartScrobbleMotitoring();

private slots:
	void OnElapseTimer();
};

#endif // PLAYCONTROLLER_HPP
