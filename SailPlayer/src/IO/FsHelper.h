#ifndef FSHELPER_H
#define FSHELPER_H

#include <QObject>
#include <QString>

#include "FileType.h"

namespace IO
{
	class FsHelper : public QObject
	{
		Q_OBJECT

	public:
		static FileType GetFileType(QString fileName);

		Q_INVOKABLE bool exists(const QString& filePath) const;
	};
}

#endif // FSHELPER_H
