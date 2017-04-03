#include "FsRecordsListController.hpp"
#include "FsRecordsListControllerFactory.hpp"

namespace IO
{
	FsRecordsListControllerFactory::FsRecordsListControllerFactory(FsRecordInfoFactory* recordFactory, SailPlayerState* state, SailPlayerSettings* settings)
		: _recordFactory(recordFactory), _state(state), _settings(settings)
	{
	}

	QObject* FsRecordsListControllerFactory::create()
	{
		return new FsRecordsListController(_recordFactory);
	}
}
