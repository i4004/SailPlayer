#ifndef FSHELPER_HPP
#define FSHELPER_HPP

#include <QObject>
#include <QString>

#include "FileType.hpp"

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

#endif // FSHELPER_HPP
