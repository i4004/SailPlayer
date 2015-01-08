#include "FilesListModel.h"

FilesListModel::FilesListModel(QObject *parent)
{
}

FilesListModel::~FilesListModel()
{
}

int FilesListModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);

	return filesList.count();
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
	QDir directory(_directoryName);
	QStringList filesList = directory.entryList();

	foreach (QString fileName, filesList)
	{
	}
}
