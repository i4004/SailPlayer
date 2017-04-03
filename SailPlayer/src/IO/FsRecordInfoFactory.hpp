#ifndef FSRECORDINFOFACTORY_HPP
#define FSRECORDINFOFACTORY_HPP

#include "FsRecordInfo.hpp"

namespace IO
{
	class FsRecordInfoFactory
	{
	public:
		virtual ~FsRecordInfoFactory() {}

		virtual FsRecordInfo* Create(QString fileName);
		virtual QList<FsRecordInfo*> CreateList(QString directoryPath);
	};
}

#endif // FSRECORDINFOFACTORY_HPP
