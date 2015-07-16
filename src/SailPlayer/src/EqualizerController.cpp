#include "Audio/AudioPlayerBase.hpp"

#include "EqualizerController.hpp"

using namespace Audio;

const QList<float> EqualizerController::BaseFrequencies = QList<float>()
	<< 55
	<< 77
	<< 110
	<< 156
	<< 220
	<< 311
	<< 440
	<< 622
	<< 880
	<< 1200
	<< 1800
	<< 2500
	<< 3500
	<< 5000
	<< 7000
	<< 10000
	<< 14000
	<< 20000;

const QList<float> EqualizerController::BaseWidths = QList<float>()
	<< 22
	<< 33
	<< 46
	<< 64
	<< 91
	<< 129
	<< 182
	<< 258
	<< 320
	<< 600
	<< 700
	<< 1000
	<< 1500
	<< 2000
	<< 3000
	<< 4000
	<< 6000
	<< 6000;

EqualizerController::EqualizerController(EqualizerPresetsModel& equalizerPresetsModel, SailPlayerSettings& settings, AudioPlayerBase& player) : _model(equalizerPresetsModel), _settings(settings), _player(player)
{
}

EqualizerController::~EqualizerController()
{
}

void EqualizerController::addNewPreset(QString name)
{
	EqualizerPreset* preset = new EqualizerPreset(name);

	for(int i = 0; i < BaseFrequencies.count(); i++)
	{
		preset->AddBand(new EqualizerBand(BaseFrequencies.at(i), BaseWidths.at(i), 0));
	}

	_model.AddPreset(preset);
}

void EqualizerController::savePresets()
{
	_settings.SetEqualizerPresets(_model.GetPresets());
}

void EqualizerController::deletePreset(int presetIndex)
{
	_model.DeletePreset(presetIndex);
}

void EqualizerController::SetPresets(QList<EqualizerPreset*> presets)
{
	_model.SetPresets(presets);

//	_player.SetEqualizer(_model.GetPresets().first());
}

void EqualizerController::setSelectedPreset(int presetIndex)
{
	if(_model.SetSelectedPreset(presetIndex))
		_settings.SetSelectedEqualizerPresetIndex(_model.getCurrentPresetIndex());
}

