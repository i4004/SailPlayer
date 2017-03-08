#ifndef IFILESFACTORY_HPP
#define IFILESFACTORY_HPP

#include <QList>
#include <QFileInfo>

namespace IO
{
	class IFilesFactory
	{
	public:
		virtual ~IFilesFactory(){}

		virtual QList<QFileInfo> Build() = 0;
	};
}

#endif // IFILESFACTORY_HPP
