#ifndef EQUALIZERPRESETSMODEL_HPP
#define EQUALIZERPRESETSMODEL_HPP

#include <QAbstractListModel>

#include "EqualizerPreset.hpp"

namespace Equalizer
{
	enum EqualizerPresetsRoles
	{
		NameRole = Qt::UserRole + 1
	};

	class EqualizerPresetsModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit EqualizerPresetsModel(QObject* parent = 0);
		~EqualizerPresetsModel();

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

		Q_INVOKABLE int getCurrentPresetIndex();
		Q_INVOKABLE QString getCurrentPresetName();

		void AddPreset(EqualizerPreset* preset);
		void SetPresets(QList<EqualizerPreset*> presets);
		bool DeletePreset(int presetIndex);
		bool SetSelectedPreset(int presetIndex);
		bool SetCurrentPresetName(QString name);
		QList<EqualizerPreset*> GetPresets() { return _presets; }

	private:
		QList<EqualizerPreset*> _presets;
		QHash<int, QByteArray> _rolesNames;
		EqualizerPreset* _currentPreset;

		void DeletePresets();
	};
}

#endif // EQUALIZERPRESETSMODEL_HPP
