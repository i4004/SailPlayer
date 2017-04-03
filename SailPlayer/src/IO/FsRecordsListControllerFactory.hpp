#ifndef FSRECORDSLISTCONTROLLERFACTORY_H
#define FSRECORDSLISTCONTROLLERFACTORY_H

#include <QObject>

#include "FsRecordInfoFactory.hpp"
#include "../Settings/SailPlayerSettings.hpp"
#include "../State/SailPlayerState.hpp"

using namespace Settings;
using namespace State;

namespace IO
{
	class FsRecordsListControllerFactory : public QObject
	{
		 Q_OBJECT

	public:
		FsRecordsListControllerFactory(FsRecordInfoFactory* recordFactory, SailPlayerState* state, SailPlayerSettings* settings);

		Q_INVOKABLE QObject* create();

	private:
		FsRecordInfoFactory* _recordFactory;
		SailPlayerState* _state;
		SailPlayerSettings* _settings;
	};
}
#endif // FSRECORDSLISTCONTROLLERFACTORY_H
