#ifndef CUETRACK_HPP
#define CUETRACK_HPP

#include <QString>
#include <QList>

#include "CueTrackDataType.hpp"
#include "CueIndex.hpp"

using namespace Cue::TrackDataType;

namespace Cue
{
	class CueTrack
	{
	public:
		CueTrack(int number, CueTrackDataType dataType);
		~CueTrack();

		void AddIndex(CueIndex* index) { _indexes.append(index); }
		QList<CueIndex*> GetIndexes() { return _indexes; }

		void SetTitle(QString title) { _title = title; }
		void SetPerformer(QString performer) { _performer = performer; }

		int GetNumber(){ return _number; }
		CueTrackDataType GetDataType(){ return _dataType; }
		QString GetTitle() { return _title; }
		QString GetPerformer() { return _performer; }

	private:
		QList<CueIndex*> _indexes;

		int _number;
		CueTrackDataType _dataType;
		QString _title;
		QString _performer;
	};
}

#endif // CUETRACK_HPP
