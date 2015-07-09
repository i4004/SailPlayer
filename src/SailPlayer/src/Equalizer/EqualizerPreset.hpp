#ifndef EQUALIZERPRESET_HPP
#define EQUALIZERPRESET_HPP

#include <QObject>
#include <QString>
#include <QList>

#include "EqualizerBand.hpp"

namespace Equalizer
{
	class EqualizerPreset : public QObject
	{
		Q_OBJECT
		Q_PROPERTY(QString text READ GetName WRITE SetName NOTIFY NameChanged)

	public:
		EqualizerPreset(QString name);
		~EqualizerPreset();

		QString GetName() { return _name; }
		void SetName(QString name) { _name = name; }

		void AddBand(EqualizerBand* band);

		void SetBands(QList<EqualizerBand*> bands);
		QList<EqualizerBand*> GetBands() { return _bands; }

	signals:
		void NameChanged();

	private:
		QString _name;
		QList<EqualizerBand*> _bands;

		void DeleteBands();
	};
}

#endif // EQUALIZERPRESET_HPP
