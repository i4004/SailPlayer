#ifndef FSRECORDSLISTMODEL_H
#define FSRECORDSLISTMODEL_H

#include <QAbstractListModel>
#include <QDir>

#include "../IO/FsRecordInfo.h"
#include "../IO/FsRecordsInfoFactory.h"

using namespace IO;

namespace UI
{
	class FsRecordsListModel : public QAbstractListModel
	{
		Q_OBJECT
		Q_PROPERTY(QString directoryPath READ GetDirectoryPath() WRITE SetDirectoryPath(QString) NOTIFY DirectoryPathChanged())

	public:
		explicit FsRecordsListModel(QObject *parent = 0);
		~FsRecordsListModel();

		// List View methods

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		QHash<int, QByteArray> roleNames() const;

		QString GetDirectoryPath() const { return _directoryName; }
		void SetDirectoryPath(QString directoryName);

	signals:
		void DirectoryPathChanged();

	private:
		QString _directoryName;
		QList<FsRecordInfo*> _filesList;
		QHash<int, QByteArray> _rolesNames;

		FsRecordsInfoFactory _fsRecordsInfoFactory;

		void ReadDirectory();
		void Cleanup();
	};
}

#endif // FSRECORDSLISTMODEL_H
