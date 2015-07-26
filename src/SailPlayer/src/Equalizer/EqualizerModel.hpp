#ifndef EQUALIZERMODEL_HPP
#define EQUALIZERMODEL_HPP

#include <QAbstractListModel>

#include "EqualizerBand.hpp"

namespace Equalizer
{
	class EqualizerModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit EqualizerModel(QObject* parent = 0);
		~EqualizerModel();

	private:
		QList<EqualizerBand*> _bands;

		void DeleteBands();
	};
}

#endif // EQUALIZERMODEL_H
