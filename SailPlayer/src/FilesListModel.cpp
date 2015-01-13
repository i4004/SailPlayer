#include "FilesListModel.h"
#include "Util/FileIconHelper.h"

using namespace Util;

enum
{
	FileNameRole = Qt::UserRole + 1,
	IsDirectoryRole = Qt::UserRole + 2,
	FileIconNameRole = Qt::UserRole + 3
};

FilesListModel::FilesListModel(QObject *parent)
{
	Q_UNUSED(parent);
}

FilesListModel::~FilesListModel()
{
	Cleanup();
}

int FilesListModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);

	return _filesList.count();
}

QVariant FilesListModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || index.row() > _filesList.size() - 1)
		return QVariant();

	FileInfo* info = _filesList.at(index.row());

	switch (role)
	{
		case Qt::DisplayRole:

		case FileNameRole:
			return info->GetFileName();

		case IsDirectoryRole:
			return info->IsDirectory();

		case FileIconNameRole:
			return FileIconHelper::GetFileIconName(*info);

		default:
			return QVariant();
	}
}

QHash<int, QByteArray> FilesListModel::roleNames() const
{
	QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
	roles.insert(FileNameRole, QByteArray("fileName"));
	roles.insert(IsDirectoryRole, QByteArray("isDirectory"));
	roles.insert(FileIconNameRole, QByteArray("fileIconName"));
	return roles;
}

void FilesListModel::SetDirectory(QString directoryName)
{
	if (directoryName == _directoryName)
		return;

	_directoryName = directoryName;

	Cleanup();
	ReadDirectory();

	emit DirectoryChanged();
}

void FilesListModel::ReadDirectory()
{
	_filesList = _fileInfoFactory.CreateList(_directoryName);
}

void FilesListModel::Cleanup()
{
	while (!_filesList.isEmpty())
		 delete _filesList.takeFirst();
}
