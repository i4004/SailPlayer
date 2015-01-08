#ifndef FILESLISTMODEL_H
#define FILESLISTMODEL_H

#include <QAbstractListModel>

class FilesListModel : public QAbstractListModel
{
	Q_OBJECT

public:
	explicit FilesListModel(QObject *parent = 0);
	~FilesListModel();

	// List View methods

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // FILESLISTMODEL_H
