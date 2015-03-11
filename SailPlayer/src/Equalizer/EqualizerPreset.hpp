#ifndef EQUALIZERPRESET_HPP
#define EQUALIZERPRESET_HPP

#include <QString>
#include <QList>

#include "EqualizerBand.hpp"

namespace Equalizer
{
	class EqualizerPreset
	{
	public:
		EqualizerPreset(QString name);
		~EqualizerPreset();

		QString GetWidth() { return _name; }
		void SetWidth(QString name) { _name = name; }

		void SetBands(QList<EqualizerBand*> bands);
		QList<EqualizerBand*> GetBands() { return _bands; }

	private:
		QString _name;
		QList<EqualizerBand*> _bands;

		void DeleteBands();
	};
}

#endif // EQUALIZERPRESET_HPP
