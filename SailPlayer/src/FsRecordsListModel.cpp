#include "FsRecordsListModel.h"
#include "Util/FsRecordIconHelper.h"

using namespace Util;

enum
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
	QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
	roles.insert(RecordNameRole, QByteArray("name"));
	roles.insert(IsDirectoryRole, QByteArray("isDirectory"));
	roles.insert(RecordIconNameRole, QByteArray("iconName"));
	roles.insert(AbsolutePathRole, QByteArray("absolutePath"));
	roles.insert(FilePathRole, QByteArray("filePath"));
	roles.insert(DirPathRole, QByteArray("dirPath"));
	return roles;
}

void FsRecordsListModel::SetDirectory(QString directoryName)
{
	if (directoryName == _directoryName)
		return;

	// Processing ".." file name to correctly handle directory up functioality

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

	emit DirectoryChanged();
}

void FsRecordsListModel::ReadDirectory()
{
	_filesList = _fileInfoFactory.CreateList(_directoryName);
}

void FsRecordsListModel::Cleanup()
{
	while (!_filesList.isEmpty())
		 delete _filesList.takeFirst();

	_filesList.clear();
}

void FsRecordsListModel::refresh()
{
}
