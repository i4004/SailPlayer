#ifndef EQUALIZERCONTROLLER_HPP
#define EQUALIZERCONTROLLER_HPP

#include <QObject>

#include "Equalizer/EqualizerPreset.hpp"

using namespace Equalizer;

class EqualizerController : public QObject
{
	Q_OBJECT

public:
	EqualizerController();
	~EqualizerController();

public slots:
	void SetPresets(QList<EqualizerPreset*> presets);

private:
	QList<EqualizerPreset*> _presets;

	void DeletePresets();
};

#endif // EQUALIZERCONTROLLER_HPP
