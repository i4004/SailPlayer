#include "../Util/FsRecordIconHelper.hpp"
#include "FsRecordsListModel.hpp"

using namespace Util;

namespace Models
{
	enum FsRecordsListModelRoles
	{
		RecordNameRole = Qt::UserRole + 1,
		IsDirectoryRole = Qt::UserRole + 2,
		RecordIconNameRole = Qt::UserRole + 3,
		AbsolutePathRole = Qt::UserRole + 4,
		FilePathRole = Qt::UserRole + 5,
		DirPathRole = Qt::UserRole + 6
	};

	FsRecordsListModel::FsRecordsListModel(QObject *parent)
	{
		Q_UNUSED(parent);

		_rolesNames = QAbstractListModel::roleNames();
		_rolesNames.insert(RecordNameRole, QByteArray("name"));
		_rolesNames.insert(IsDirectoryRole, QByteArray("isDirectory"));
		_rolesNames.insert(RecordIconNameRole, QByteArray("iconName"));
		_rolesNames.insert(AbsolutePathRole, QByteArray("absolutePath"));
		_rolesNames.insert(FilePathRole, QByteArray("filePath"));
		_rolesNames.insert(DirPathRole, QByteArray("dirPath"));
	}

	FsRecordsListModel::~FsRecordsListModel()
	{
		Cleanup();
	}

	int FsRecordsListModel::rowCount(const QModelIndex &parent) const
	{
		Q_UNUSED(parent);

		return _fsRecordsList.count();
	}

	QVariant FsRecordsListModel::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid() || index.row() > _fsRecordsList.size() - 1)
			return QVariant();

		FsRecordInfo* item = _fsRecordsList.at(index.row());

		switch (role)
		{
			case Qt::DisplayRole:

			case RecordNameRole:
				return item->GetName();

			case IsDirectoryRole:
				return item->IsDirectory();

			case RecordIconNameRole:
				return FsRecordIconHelper::GetFsRecordIconName(*item);

			case AbsolutePathRole:
				return item->GetAbsolutePath();

			case FilePathRole:
				return item->GetFilePath();

			case DirPathRole:
				return item->GetDirPath();

			default:
				return QVariant();
		}
	}

	void FsRecordsListModel::SetDirectoryPath(QString directoryName)
	{
		if (directoryName == _directoryName)
			return;

		// Processing ".." file name to correctly handle directory-up functionality

		if(directoryName.endsWith("/.."))
		{
			directoryName = directoryName.mid(0, directoryName.indexOf("/.."));

			if(directoryName != "")
				directoryName = directoryName.mid(0, directoryName.lastIndexOf("/"));

			if(directoryName == "")
				directoryName = "/";
		}

		_directoryName = directoryName;

		beginResetModel();

		Cleanup();
		ReadDirectory();

		endResetModel();

		emit DirectoryPathChanged();
	}

	void FsRecordsListModel::ReadDirectory()
	{
		_fsRecordsList = _fsRecordsInfoFactory.CreateList(_directoryName);
	}

	void FsRecordsListModel::Cleanup()
	{
		while (!_fsRecordsList.isEmpty())
			 delete _fsRecordsList.takeFirst();
	}
}
