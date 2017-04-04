#include "DirectorySelectionController.hpp"
#include "DirectorySelectionControllerFactory.hpp"

namespace IO
{
	DirectorySelectionControllerFactory::DirectorySelectionControllerFactory(FsRecordInfoFactory* recordFactory, SailPlayerState* state, SailPlayerSettings* settings)
		: _recordFactory(recordFactory), _state(state), _settings(settings)
	{
	}

	QObject* DirectorySelectionControllerFactory::create()
	{
		return new DirectorySelectionController(_recordFactory);
	}
}
