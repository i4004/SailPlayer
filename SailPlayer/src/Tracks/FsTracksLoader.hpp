#ifndef FSTRACKSLOADER_HPP
#define FSTRACKSLOADER_HPP

#include <QString>

#include "ITracksLoader.hpp"

namespace Tracks
{
	class FsTracksLoader : public ITracksLoader
	{
		Q_OBJECT

	public:
		QList<Track*> Build();

		Q_INVOKABLE void setDirectoryPath(const QString& directoryPath) { _directoryPath = directoryPath; }

	protected:
		inline QString GetDirectoryPath() { return _directoryPath; }

	private:
		QString _directoryPath;
	};
}

#endif // FSTRACKSLOADER_HPP
