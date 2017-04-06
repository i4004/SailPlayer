#ifndef FSRECORDINFOFACTORY_HPP
#define FSRECORDINFOFACTORY_HPP

#include "FsRecordInfo.hpp"

namespace IO
{
	class FsRecordInfoFactory
	{
	public:
		virtual ~FsRecordInfoFactory() {}

		virtual FsRecordInfo* Create(const QFileInfo& fileInfo);
		virtual FsRecordInfo* Create(const QString& fileName);
		virtual QList<FsRecordInfo*> CreateList(const QString& directoryPath);
	};
}

#endif // FSRECORDINFOFACTORY_HPP
