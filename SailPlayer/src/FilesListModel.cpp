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

	// TODO
	return 0;
}

QVariant FilesListModel::data(const QModelIndex &index, int role) const
{
	// TODO
	return QVariant();
}
