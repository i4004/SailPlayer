#include "EqualizerModel.hpp"

namespace Equalizer
{
	EqualizerModel::EqualizerModel(QObject* parent) : QAbstractListModel(parent)
	{
		_rolesNames = QAbstractListModel::roleNames();
		_rolesNames.insert(FrequencyRole, QByteArray("bandFrequency"));
		_rolesNames.insert(WidthRole, QByteArray("bandWidth"));
		_rolesNames.insert(GainRole, QByteArray("bandGain"));
	}

	EqualizerModel::~EqualizerModel()
	{
		DeleteBands();
	}

	int EqualizerModel::rowCount(const QModelIndex &parent) const
	{
		Q_UNUSED(parent);

		return _bands.count();
	}

	QVariant EqualizerModel::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid() || index.row() >= _bands.count())
			return QVariant();

		EqualizerBand* item = _bands.at(index.row());

		switch (role)
		{
			case Qt::DisplayRole:

			case FrequencyRole:
				return item->GetFrequency();

			case WidthRole:
				return item->GetWidth();

			case GainRole:
				return item->GetGain();

			default:
				return QVariant();
		}
	}

	void EqualizerModel::SetBands(QList<EqualizerBand*> bands)
	{
		beginResetModel();

		DeleteBands();

		foreach (EqualizerBand* band, bands)
		{
			_bands.append(new EqualizerBand(*band));
		}

		endResetModel();
	}

	int EqualizerModel::SetBandData(float frequency, float gain)
	{
		int bandID = -1;

//		beginResetModel();

		for(int i = 0; i < _bands.count(); i++)
		{
			EqualizerBand* band = _bands.at(i);

			if(band->GetFrequency() == frequency)
			{
				band->SetGain(gain);
				bandID = i;
			}
		}

//		endResetModel();

		return bandID;
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
