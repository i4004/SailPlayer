#include <QDir>
#include <fileref.h>
#include <tag.h>
#include <QDebug>

#include "../IO/FsHelper.hpp"

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

		_filesLoadedViaCue.clear();

		foreach (QFileInfo fileInfo, filesInfoList)
		{
			IO::FileType fileType = IO::FsHelper::GetFileType(fileInfo.suffix());

			if(fileType == IO::Cue)
			{
				QList<Track*> newItems = BuildFromCueSheet(fileInfo);
				QList<Track*> itemsToRemove;

				// Removing previously loaded multimedia files used by cuesheet

				foreach (Track* item, items)
					if(_filesLoadedViaCue.contains(item->GetFullFilePath()))
						itemsToRemove.append(item);

				foreach (Track* item, itemsToRemove)
					items.removeOne(item);

				items.append(newItems);
			}
			else
				items.append(Build(fileInfo));
		}

		return items;
	}

	QList<Track*> TracksFactory::Build(QFileInfo fileInfo)
	{
		QList<Track*> items;

		if(_filesLoadedViaCue.contains(fileInfo.absoluteFilePath()))
		{
			_filesLoadedViaCue.removeAll(fileInfo.absoluteFilePath());

			return items;
		}

		FileRef f(fileInfo.absoluteFilePath().toLocal8Bit().data());

		if(!f.isNull() && f.tag())
		{
			Tag* tag = f.tag();
			AudioProperties* properties = f.audioProperties();

			items.append(new Track(QString(tag->artist().toCString(true)),
								   QString(tag->album().toCString(true)),
								   tag->year(),
								   tag->track(),
								   QString(tag->title().toCString(true)),
								   0,
								   properties->length() * 1000, // Length in milliseconds
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
				Track* previousTrack = NULL;
				QString fullFilePath = QDir::isAbsolutePath(currentFile->GetFileName()) ? currentFile->GetFileName() : fileInfo.absolutePath() + "/" + currentFile->GetFileName();

				_filesLoadedViaCue.append(fullFilePath);

				foreach (CueTrack* currentTrack, currentFile->GetTracks())
				{
					QString artist = currentTrack->GetPerformer().isNull() ? cue->GetPerformer() : currentTrack->GetPerformer();
					int albumYear = cue->GetRemarks()["DATE"].toInt();
					QFileInfo mediaFileInfo(fullFilePath);
					CueIndex* dataIndex = GetDataIndex(currentTrack->GetIndexes());

					int startPosition = 0;

					if(dataIndex != NULL)
						startPosition = (dataIndex->GetMinutes() * 60 + dataIndex->GetSeconds()) * 1000 + GetMillisecondsFromCueFrames(dataIndex->GetFrames());

					if(previousTrack != NULL)
						previousTrack->SetEndPosition(startPosition);

					previousTrack = new Track(artist,
											  cue->GetTitle(),
											  albumYear,
											  currentTrack->GetNumber(),
											  currentTrack->GetTitle(),
											  startPosition,
											  0,
											  mediaFileInfo.fileName(),
											  fullFilePath);

					items.append(previousTrack);
				}

				// Calculating end position for final item

				if(previousTrack != NULL)
				{
					FileRef f(fullFilePath.toLocal8Bit().data());

					if(!f.isNull() && f.tag())
					{
						AudioProperties* properties = f.audioProperties();
						previousTrack->SetEndPosition(properties->length() * 1000);
					}
				}
			}

			delete cue;
		}

		return items;
	}

	int TracksFactory::GetMillisecondsFromCueFrames(int frames)
	{
		return 1.0f / 75 * frames * 1000;
	}

	CueIndex* TracksFactory::GetDataIndex(QList<CueIndex*> indexes)
	{
		foreach(CueIndex* index, indexes)
			if(index->GetNumber() == 1)
				return index;

		return NULL;
	}
}
