#include "EqualizerModel.hpp"

namespace Equalizer
{
	EqualizerModel::EqualizerModel(QObject* parent) : QAbstractListModel(parent)
	{
	}

	EqualizerModel::~EqualizerModel()
	{
		DeleteBands();
	}

	void EqualizerModel::SetBands(QList<EqualizerBand*> bands)
	{
		DeleteBands();

		foreach (EqualizerBand* band, bands)
		{
			_bands.append(new EqualizerBand(*band));
		}
	}

	QList<EqualizerBand*> EqualizerModel::GetBands()
	{
		QList<EqualizerBand*> newBands;

		foreach (EqualizerBand* band, _bands)
		{
			newBands.append(new EqualizerBand(*band));
		}

		return newBands;
	}

	void EqualizerModel::DeleteBands()
	{
		while (!_bands.isEmpty())
			delete _bands.takeFirst();
	}
}
