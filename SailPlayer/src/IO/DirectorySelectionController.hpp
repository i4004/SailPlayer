#ifndef DIRECTORYSELECTIONCONTROLLER_HPP
#define DIRECTORYSELECTIONCONTROLLER_HPP

#include "FsRecordInfoFactory.hpp"
#include "FsRecordsListModel.hpp"

namespace IO
{
	class DirectorySelectionController : public QObject
	{
		Q_OBJECT
		Q_PROPERTY(QString directoryPath READ GetDirectoryPath() WRITE SetDirectoryPath(QString) NOTIFY DirectoryPathChanged())

	public:
		DirectorySelectionController(FsRecordInfoFactory* recordFactory);

		inline QString GetDirectoryPath() const { return _directoryPath; }
		virtual void SetDirectoryPath(QString directoryPath);

		Q_INVOKABLE QObject* getModel() { return _model; }

	signals:
		void DirectoryPathChanged();

	private:
		QString _directoryPath;

		FsRecordsListModel* _model;
		FsRecordInfoFactory* _recordFactory;

		QString PreprocessDirectoryPath(QString directoryPath);

	};
}
#endif // DIRECTORYSELECTIONCONTROLLER_HPP
