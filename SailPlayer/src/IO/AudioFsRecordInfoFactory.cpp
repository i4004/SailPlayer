#include <QDir>

#include "FileHelper.hpp"
#include "AudioFsRecordInfoFactory.hpp"

namespace IO
{\
	QList<FileType> AudioFsRecordInfoFactory::SupportedFormats = QList<FileType>{Aac, Aiff, Ape, Cue, Flac, Mp3, Mp4, Ogg, M4a, Wav, Wma, Wv};

	QList<FsRecordInfo*> AudioFsRecordInfoFactory::CreateList(const QString& directoryPath)
	{
		QList<FsRecordInfo*> items;
		QDir directory(directoryPath);

		directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::System | QDir::Readable);
		directory.setSorting(QDir::Name | QDir::DirsFirst);

		foreach (QFileInfo entry, directory.entryInfoList())
		{
			if(entry.isDir())
				items.append(CreateList(entry.absoluteFilePath()));
			else if(SupportedFormats.contains(FileHelper::GetFileType(entry.suffix())))
				items.append(Create(entry));
		}

		return items;
	}
}
