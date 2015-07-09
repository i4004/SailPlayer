#ifndef EQUALIZERCONTROLLER_HPP
#define EQUALIZERCONTROLLER_HPP

#include <QObject>
#include "SailPlayerSettings.hpp"

#include "Equalizer/EqualizerPresetsModel.hpp"

using namespace Equalizer;

class EqualizerController : public QObject
{
	Q_OBJECT

public:
	EqualizerController(EqualizerPresetsModel& equalizerPresetsModel, SailPlayerSettings& settings);
	~EqualizerController();

	static const QList<float> BaseFrequencies;
	static const QList<float> BaseWidths;

	Q_INVOKABLE void addNewPreset(QString name);
	Q_INVOKABLE void savePresets();
	void LoadPresets();

private:
	EqualizerPresetsModel& _model;
	SailPlayerSettings& _settings;
};

#endif // EQUALIZERCONTROLLER_HPP
