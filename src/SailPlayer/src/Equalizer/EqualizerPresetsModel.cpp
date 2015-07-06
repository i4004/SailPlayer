#include "EqualizerPresetsModel.hpp"

namespace Equalizer
{
	EqualizerPresetsModel::EqualizerPresetsModel(QObject* parent) : QAbstractListModel(parent)
	{
	}

	EqualizerPresetsModel::~EqualizerPresetsModel()
	{
		DeletePresets();
	}

	int EqualizerPresetsModel::rowCount(const QModelIndex &parent) const
	{
		Q_UNUSED(parent);

		return _presets.count();
	}

	QVariant EqualizerPresetsModel::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid() || index.row() >= _presets.count())
			return QVariant();

		return QVariant();
	}

	void EqualizerPresetsModel::SetPresets(QList<EqualizerPreset*> presets)
	{
		DeletePresets();

		foreach (EqualizerPreset* preset, presets)
			_presets.append(preset);
	}

	void EqualizerPresetsModel::DeletePresets()
	{
		while (!_presets.isEmpty())
			delete _presets.takeFirst();
	}
}
