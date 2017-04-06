#include <QQmlEngine>

#include "ITracksLoader.hpp"

namespace Tracks
{
	ITracksLoader::ITracksLoader()
	{
		QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);
	}
}
