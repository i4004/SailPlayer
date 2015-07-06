#ifndef EQUALIZERCONTROLLER_HPP
#define EQUALIZERCONTROLLER_HPP

#include <QObject>

#include "Equalizer/EqualizerPresetsModel.hpp"

using namespace Equalizer;

class EqualizerController : public QObject
{
	Q_OBJECT

public:
	EqualizerController(EqualizerPresetsModel& equalizerPresetsModel);
	~EqualizerController();

private:
	EqualizerPresetsModel& _model;
};

#endif // EQUALIZERCONTROLLER_HPP
