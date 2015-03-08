#ifndef FSRECORDSLISTMODEL_HPP
#define FSRECORDSLISTMODEL_HPP

#include <QAbstractListModel>
#include <QDir>

#include "../IO/FsRecordInfo.hpp"
#include "../IO/FsRecordsInfoFactory.hpp"

using namespace IO;

namespace Models
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
		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

		QString GetDirectoryPath() const { return _directoryName; }
		void SetDirectoryPath(QString directoryName);

	signals:
		void DirectoryPathChanged();

	private:
		QString _directoryName;
		QList<FsRecordInfo*> _fsRecordsList;
		QHash<int, QByteArray> _rolesNames;

		FsRecordsInfoFactory _fsRecordsInfoFactory;

		void ReadDirectory();
		void Cleanup();
	};
}

#endif // FSRECORDSLISTMODEL_HPP
