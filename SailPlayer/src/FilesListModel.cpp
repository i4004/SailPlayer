#include "FilesListModel.h"

FilesListModel::FilesListModel(QObject *parent)
{
	Q_UNUSED(parent);
}

FilesListModel::~FilesListModel()
{
}

int FilesListModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);

	_filesList.count();
}

QVariant FilesListModel::data(const QModelIndex &index, int role) const
{
	// TODO
	return QVariant();
}

void FilesListModel::SetDirectory(QString directoryName)
{
	if (directoryName == _directoryName)
		return;

	_directoryName = directoryName;

	ReadDirectory();

	emit DirectoryChanged();
}

void FilesListModel::ReadDirectory()
{
	_filesList = _fileInfoFactory.CreateList(_directoryName);
}
