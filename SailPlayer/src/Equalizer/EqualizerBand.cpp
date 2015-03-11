#include "EqualizerBand.hpp"

namespace Equalizer
{
	EqualizerBand::EqualizerBand()
	{
	}

	EqualizerBand::EqualizerBand(float frequency, float width, float gain) : _frequency(frequency), _width(width), _gain(gain)
	{
	}
}
