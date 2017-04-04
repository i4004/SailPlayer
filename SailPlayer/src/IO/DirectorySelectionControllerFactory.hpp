#ifndef DIRECTORYSELECTIONCONTROLLERFACTORY_HPP
#define DIRECTORYSELECTIONCONTROLLERFACTORY_HPP

#include <QObject>

#include "FsRecordInfoFactory.hpp"
#include "../Settings/SailPlayerSettings.hpp"
#include "../State/SailPlayerState.hpp"

using namespace Settings;
using namespace State;

namespace IO
{
	class DirectorySelectionControllerFactory : public QObject
	{
		 Q_OBJECT

	public:
		DirectorySelectionControllerFactory(FsRecordInfoFactory* recordFactory, SailPlayerState* state, SailPlayerSettings* settings);

		Q_INVOKABLE QObject* create();

	private:
		FsRecordInfoFactory* _recordFactory;
		SailPlayerState* _state;
		SailPlayerSettings* _settings;
	};
}
#endif // DIRECTORYSELECTIONCONTROLLERFACTORY_HPP
