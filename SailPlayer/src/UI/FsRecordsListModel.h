#ifndef FILESLISTMODEL_H
#define FILESLISTMODEL_H

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
		Q_PROPERTY(QString directory READ GetDirectory() WRITE SetDirectory(QString) NOTIFY DirectoryChanged())

	public:
		explicit FsRecordsListModel(QObject *parent = 0);
		~FsRecordsListModel();

		// List View methods

		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		QHash<int, QByteArray> roleNames() const;

		QString GetDirectory() const { return _directoryName; }
		void SetDirectory(QString directoryName);

	signals:
		void DirectoryChanged();

	private:
		QString _directoryName;
		QList<FsRecordInfo*> _filesList;
		QHash<int, QByteArray> _rolesNames;

		FsRecordsInfoFactory _fileInfoFactory;

		void ReadDirectory();
		void Cleanup();
	};
}

#endif // FILESLISTMODEL_H
