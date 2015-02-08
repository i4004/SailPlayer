#include <fileref.h>
#include <tag.h>

#include "TracksFactory.hpp"

using namespace TagLib;

namespace Playlist
{
	TracksFactory::TracksFactory()
	{
	}

	QList<Track*> TracksFactory::Build(QList<QFileInfo> filesInfoList)
	{
		QList<Track*> items;

		foreach (QFileInfo fileInfo, filesInfoList)
			items.append(Build(fileInfo));

		return items;
	}

	QList<Track*> TracksFactory::Build(QFileInfo fileInfo)
	{
		QList<Track*> items;

		FileRef f(fileInfo.absoluteFilePath().toLocal8Bit().data());

		if(!f.isNull() && f.tag())
		{
			Tag* tag = f.tag();
			AudioProperties *properties = f.audioProperties();

			items.append(new Track(QString(tag->artist().toCString()),
								   QString(tag->album().toCString()),
								   tag->year(),
								   tag->track(),
								   QString(tag->title().toCString()),
								   properties->length(),
								   fileInfo.fileName(),
								   fileInfo.absoluteFilePath()));
		}

		return items;
	}
}
