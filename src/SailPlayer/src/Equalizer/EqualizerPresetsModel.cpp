#include "EqualizerPresetsModel.hpp"

namespace Equalizer
{
	EqualizerPresetsModel::EqualizerPresetsModel(QObject* parent) : QAbstractListModel(parent)
	{
		_currentPreset = NULL;
		_rolesNames = QAbstractListModel::roleNames();
		_rolesNames.insert(NameRole, QByteArray("presetName"));
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

		EqualizerPreset* item = _presets.at(index.row());

		switch (role)
		{
			case Qt::DisplayRole:

			case NameRole:
				return item->GetName();

			default:
				return QVariant();
		}
	}

	void EqualizerPresetsModel::AddPreset(EqualizerPreset* preset)
	{
		beginResetModel();

		_presets.append(preset);

		endResetModel();
	}

	void EqualizerPresetsModel::SetPresets(QList<EqualizerPreset*> presets)
	{
		beginResetModel();

		DeletePresets();

		foreach (EqualizerPreset* preset, presets)
			_presets.append(preset);

		endResetModel();
	}

	void EqualizerPresetsModel::DeletePreset(int presetIndex)
	{
		beginResetModel();

		EqualizerPreset* _preset = _presets.at(presetIndex);
		_presets.removeOne(_preset);
		delete _preset;

		endResetModel();
	}

	int EqualizerPresetsModel::GetCurrentPresetIndex()
	{
		if(_currentPreset == NULL)
			return -1;

		return _presets.indexOf(_currentPreset);
	}

	void EqualizerPresetsModel::DeletePresets()
	{
		while (!_presets.isEmpty())
			delete _presets.takeFirst();
	}
}
