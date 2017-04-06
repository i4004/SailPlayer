#ifndef AUDIOFSRECORDINFOFACTORY_HPP
#define AUDIOFSRECORDINFOFACTORY_HPP

#include "../IO/FileType.hpp"
#include "FsRecordInfoFactory.hpp"

namespace IO
{
	class AudioFsRecordInfoFactory : public FsRecordInfoFactory
	{
	public:
		QList<FsRecordInfo*> CreateList(const QString& directoryPath);

	private:
		static QList<FileType> SupportedFormats;

		QList<QFileInfo> GetDirectoryFilesInfo(const QString& directoryPath);
	};
}

#endif // AUDIOFSRECORDINFOFACTORY_HPP
