#ifndef EQUALIZERMODEL_HPP
#define EQUALIZERMODEL_HPP

#include <QAbstractListModel>

namespace Equalizer
{
	class EqualizerModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		explicit EqualizerModel(QObject* parent = 0);
	};
}

#endif // EQUALIZERMODEL_H
