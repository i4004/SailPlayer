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

	foreach (EqualizerPreset* preset, presets)
		_presets.append((QObject*)preset);
}

void EqualizerController::DeletePresets()
{
	while (!_presets.isEmpty())
		delete _presets.takeFirst();
}
