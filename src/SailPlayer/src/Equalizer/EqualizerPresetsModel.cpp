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

	bool EqualizerPresetsModel::DeletePreset(int presetIndex)
	{
		EqualizerPreset* _preset = _presets.at(presetIndex);

		if(_preset == NULL)
			return false;

		beginResetModel();

		_presets.removeOne(_preset);
		delete _preset;

		endResetModel();

		return true;
	}

	bool EqualizerPresetsModel::SetSelectedPreset(int presetIndex)
	{
		if(_presets.count() == 0)
			return false;

		if(presetIndex < 0 || presetIndex >= _presets.count())
			return false;

		_currentPreset = _presets.at(presetIndex);

		return true;
	}

	bool EqualizerPresetsModel::SetCurrentPresetName(QString name)
	{
		if(_currentPreset == NULL)
			return false;

		beginResetModel();
		_currentPreset->SetName(name);
		endResetModel();

		return true;
	}

	int EqualizerPresetsModel::getCurrentPresetIndex()
	{
		if(_currentPreset == NULL)
			return -1;

		return _presets.indexOf(_currentPreset);
	}

	QString EqualizerPresetsModel::getCurrentPresetName()
	{
		if(_currentPreset == NULL)
			return QString();

		return _currentPreset->GetName();
	}

	EqualizerPreset* EqualizerPresetsModel::GetCurrentPreset()
	{
		if(_currentPreset == NULL)
			return NULL;

		return _currentPreset;
	}

	void EqualizerPresetsModel::DeletePresets()
	{
		while (!_presets.isEmpty())
			delete _presets.takeFirst();
	}
}
