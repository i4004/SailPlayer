#include "FilesListModel.h"

enum
{
	FilenameRole = Qt::UserRole + 1
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
	case FilenameRole:
		return info->GetFileName();

	default:
		return QVariant();
	}
}

QHash<int, QByteArray> FilesListModel::roleNames() const
{
	QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
	roles.insert(FilenameRole, QByteArray("fileName"));
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
