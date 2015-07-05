#include <QDir>
#include <QDebug>

#include "../IO/FsHelper.hpp"
#include "DirectoryRecursiveMultimediaFilesListFactory.hpp"

namespace Playlist
{
	DirectoryRecursiveMultimediaFilesListFactory::DirectoryRecursiveMultimediaFilesListFactory()
	{
		_supportedFormats.append(Aac);
		_supportedFormats.append(Aiff);
		_supportedFormats.append(Ape);
		_supportedFormats.append(Cue);
		_supportedFormats.append(Flac);
		_supportedFormats.append(Mp3);
		_supportedFormats.append(Mp4);
		_supportedFormats.append(Ogg);
		_supportedFormats.append(M4a);
		_supportedFormats.append(Wav);
		_supportedFormats.append(Wma);
		_supportedFormats.append(Wv);
	}

	QList<QFileInfo> DirectoryRecursiveMultimediaFilesListFactory::Build()
	{
		QList<QFileInfo> items;

		items.append(GetDirectoryFiles(_directoryPath));

		return items;
	}

	QList<QFileInfo> DirectoryRecursiveMultimediaFilesListFactory::GetDirectoryFiles(QString directoryPath)
	{
		QList<QFileInfo> items;
		QDir directory(directoryPath);

		directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::System | QDir::Readable);
		directory.setSorting(QDir::Name | QDir::DirsFirst);

		foreach (QFileInfo entry, directory.entryInfoList())
		{
			if(entry.isDir())
				items.append(GetDirectoryFiles(entry.absoluteFilePath()));
			else if(_supportedFormats.contains(FsHelper::GetFileType(entry.suffix())))
				items.append(entry);
		}

		return items;
	}
}
