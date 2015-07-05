#ifndef PLAYLISTFACTORY_HPP
#define PLAYLISTFACTORY_HPP

#include <QFileInfo>

#include "../Cue/CueSheetReader.hpp"

#include "ITracksFactory.hpp"
#include "Track.hpp"

using namespace Cue;

namespace Playlist
{
	class TracksFactory : public ITracksFactory
	{
	public:
		TracksFactory();

		virtual QList<Track*> Build(QList<QFileInfo> filesInfoList);

	private:
		CueSheetReader _cueReader;

		QList<Track*> Build(QFileInfo fileInfo);
		QList<Track*> BuildFromCueSheet(QFileInfo fileInfo);

		int GetMillisecondsFromCueFrames(int frames);
		CueIndex* GetDataIndex(QList<CueIndex*> indexes);

		QList<QString> _filesLoadedViaCue;
	};
}

#endif // PLAYLISTFACTORY_HPP
