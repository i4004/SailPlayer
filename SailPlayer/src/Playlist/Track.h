#ifndef TRACK_H
#define TRACK_H

#include <QString>

namespace Playlist
{
	class Track
	{
	public:
		Track(QString number, QString name, QString duration, QString sourceFileName);

		QString GetNumber(){ return _number; }
		QString GetName(){ return _name; }
		QString GetDuration(){ return _duration; }
		QString GetSourceFileName(){ return _sourceFileName; }

	private:
		QString _number;
		QString _name;
		QString _duration;
		QString _sourceFileName;
	};
}

#endif // TRACK_H
