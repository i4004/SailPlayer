#include "EqualizerPreset.hpp"

namespace Equalizer
{
	EqualizerPreset::EqualizerPreset(QString name) : _name(name)
	{		
	}

	EqualizerPreset::~EqualizerPreset()
	{
		DeleteBands();
	}

	void EqualizerPreset::SetBands(QList<EqualizerBand*> bands)
	{
		DeleteBands();

		_bands.append(bands);
	}

	void EqualizerPreset::DeleteBands()
	{
		while (!_bands.isEmpty())
			delete _bands.takeFirst();
	}
}
