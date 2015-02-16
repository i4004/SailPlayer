#include <QDir>
#include <fileref.h>
#include <tag.h>

#include "../IO/FsHelper.hpp"

#include "TracksFactory.hpp"

using namespace TagLib;
//using namespace IO;

namespace Playlist
{
	TracksFactory::TracksFactory()
	{
	}

	QList<Track*> TracksFactory::Build(QList<QFileInfo> filesInfoList)
	{
		QList<Track*> items;

		foreach (QFileInfo fileInfo, filesInfoList)
		{
			IO::FileType fileType = IO::FsHelper::GetFileType(fileInfo.suffix());

			if(fileType == IO::Cue)
				items.append(BuildFromCueSheet(fileInfo));
			else
				items.append(Build(fileInfo));
		}

		return items;
	}

	QList<Track*> TracksFactory::Build(QFileInfo fileInfo)
	{
		QList<Track*> items;

		FileRef f(fileInfo.absoluteFilePath().toLocal8Bit().data());

		if(!f.isNull() && f.tag())
		{
			Tag* tag = f.tag();
			AudioProperties* properties = f.audioProperties();

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

	QList<Track*> TracksFactory::BuildFromCueSheet(QFileInfo fileInfo)
	{
		QList<Track*> items;

		CueSheet* cue = _cueReader.Read(fileInfo.absoluteFilePath());

		if(cue != NULL)
		{
			foreach (CueFile* currentFile, cue->GetFiles())
			{
				foreach (CueTrack* currentTrack, currentFile->GetTracks())
				{
					QString artist = currentTrack->GetPerformer().isNull() ? currentTrack->GetPerformer() : cue->GetPerformer();
					int albumYear = cue->GetRemarks()["DATE"].toInt();
					QString fullFilePath = QDir::isAbsolutePath(currentFile->GetFileName()) ? currentFile->GetFileName() : fileInfo.absolutePath() + "/" + currentFile->GetFileName();
					QFileInfo mediaFileInfo(fullFilePath);

					items.append(new Track(artist,
										   cue->GetTitle(),
										   albumYear,
										   currentTrack->GetNumber(),
										   currentTrack->GetTitle(),
										   666,
										   mediaFileInfo.fileName(),
										   fullFilePath));
				}
			}

			delete cue;
		}

		return items;
	}
}
