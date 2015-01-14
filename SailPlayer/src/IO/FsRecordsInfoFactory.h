#ifndef FILEINFOFACTORY_H
#define FILEINFOFACTORY_H

#include "FsRecordInfo.h"

namespace IO
{
	class FsRecordsInfoFactory
	{
	public:
		FsRecordInfo* Create(QString fileName);
		QList<FsRecordInfo*> CreateList(QString directoryName);
	};
}

#endif // FILEINFOFACTORY_H
