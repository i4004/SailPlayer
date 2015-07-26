#ifndef EQUALIZERMODEL_HPP
#define EQUALIZERMODEL_HPP

#include <QAbstractListModel>

#include "EqualizerBand.hpp"

namespace Equalizer
{
	enum EqualizerRoles
	{
		FrequencyRole = Qt::UserRole + 1,
		WidthRole = Qt::UserRole + 2,
		GainRole = Qt::UserRole + 3
	};


	class EqualizerModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit EqualizerModel(QObject* parent = 0);
		~EqualizerModel();

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

		void SetBands(QList<EqualizerBand*> bands);
		QList<EqualizerBand*> GetBands();

	private:
		QHash<int, QByteArray> _rolesNames;
		QList<EqualizerBand*> _bands;

		void DeleteBands();
	};
}

#endif // EQUALIZERMODEL_H
