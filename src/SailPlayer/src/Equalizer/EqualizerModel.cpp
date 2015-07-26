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

	void EqualizerModel::DeleteBands()
	{
		while (!_bands.isEmpty())
			delete _bands.takeFirst();
	}
}
