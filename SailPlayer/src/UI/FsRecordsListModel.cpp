#include "../Util/FsRecordIconHelper.h"
#include "FsRecordsListModel.h"

using namespace Util;

namespace UI
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

		return _filesList.count();
	}

	QVariant FsRecordsListModel::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid() || index.row() > _filesList.size() - 1)
			return QVariant();

		FsRecordInfo* info = _filesList.at(index.row());

		switch (role)
		{
			case Qt::DisplayRole:

			case RecordNameRole:
				return info->GetName();

			case IsDirectoryRole:
				return info->IsDirectory();

			case RecordIconNameRole:
				return FsRecordIconHelper::GetFsRecordIconName(*info);

			case AbsolutePathRole:
				return info->GetAbsolutePath();

			case FilePathRole:
				return info->GetFilePath();

			case DirPathRole:
				return info->GetDirPath();

			default:
				return QVariant();
		}
	}

	QHash<int, QByteArray> FsRecordsListModel::roleNames() const
	{
		return _rolesNames;
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
		_filesList = _fsRecordsInfoFactory.CreateList(_directoryName);
	}

	void FsRecordsListModel::Cleanup()
	{
		while (!_filesList.isEmpty())
			 delete _filesList.takeFirst();
	}
}
