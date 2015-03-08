#ifndef FILEINFOFACTORY_HPP
#define FILEINFOFACTORY_HPP

#include "FsRecordInfo.hpp"

namespace IO
{
	class FsRecordsInfoFactory
	{
	public:
		FsRecordInfo* Create(QString fileName);
		QList<FsRecordInfo*> CreateList(QString directoryName);
	};
}

#endif // FILEINFOFACTORY_HPP
