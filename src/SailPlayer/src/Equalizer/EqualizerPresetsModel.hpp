#ifndef EQUALIZERPRESETSMODEL_HPP
#define EQUALIZERPRESETSMODEL_HPP

#include <QAbstractListModel>

#include "EqualizerPreset.hpp"

namespace Equalizer
{
	class EqualizerPresetsModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit EqualizerPresetsModel(QObject* parent = 0);
		~EqualizerPresetsModel();

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

		//public slots:
		//	Q_INVOKABLE QList<QObject*> getPresets() { return _presets; }

		void SetPresets(QList<EqualizerPreset*> presets);

	private:
		QList<EqualizerPreset*> _presets;

		void DeletePresets();
	};
}

#endif // EQUALIZERPRESETSMODEL_HPP
