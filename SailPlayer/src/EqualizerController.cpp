#include "EqualizerController.hpp"

EqualizerController::EqualizerController()
{
}

EqualizerController::~EqualizerController()
{
	DeletePresets();
}

void EqualizerController::SetPresets(QList<EqualizerPreset*> presets)
{
	DeletePresets();
	_presets = presets;
}

void EqualizerController::DeletePresets()
{
	while (!_presets.isEmpty())
		delete _presets.takeFirst();
}
