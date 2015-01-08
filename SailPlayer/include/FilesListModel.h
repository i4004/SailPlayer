#ifndef FILESLISTMODEL_H
#define FILESLISTMODEL_H

#include <QAbstractListModel>
#include <QDir>

#include "FileInfo.h"

class FilesListModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(QString dir READ GetDirectory() WRITE SetDirectory(QString) NOTIFY DirectoryChanged())

public:
	explicit FilesListModel(QObject *parent = 0);
	~FilesListModel();

	// List View methods

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	QString GetDirectory() const { return _directoryName; }
	void SetDirectory(QString directoryName);

signals:
	void DirectoryChanged();

private:
	QString _directoryName;
	QList<FileInfo> filesList;

	void ReadDirectory();
};

#endif // FILESLISTMODEL_H
