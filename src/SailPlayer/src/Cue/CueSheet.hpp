#ifndef CUESHEET_HPP
#define CUESHEET_HPP

#include <QMap>

#include "CueFile.hpp"

namespace Cue
{
	class CueSheet
	{
	public:
		CueSheet();
		~CueSheet();

		void AddFile(CueFile* file) { _files.append(file); }
		QList<CueFile*> GetFiles() { return _files; }

		void AddRemark(QString name, QString value) { _remarks.insert(name, value); }
		QMap<QString, QString> GetRemarks() { return _remarks; }

		void SetTitle(QString title) { _title = title; }
		void SetPerformer(QString performer) { _performer = performer; }

		QString GetTitle() { return _title; }
		QString GetPerformer() { return _performer; }

	private:
		QList<CueFile*> _files;
		QMap<QString, QString> _remarks;

		QString _title;
		QString _performer;
	};
}

#endif // CUESHEET_HPP
