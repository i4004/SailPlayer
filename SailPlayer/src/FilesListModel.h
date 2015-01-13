#ifndef FILESLISTMODEL_H
#define FILESLISTMODEL_H

#include <QAbstractListModel>
#include <QDir>

#include "Entities/FileInfo.h"
#include "FileInfoFactory.h"

using namespace Entities;

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
	QHash<int, QByteArray> roleNames() const;

	QString GetDirectory() const { return _directoryName; }
	void SetDirectory(QString directoryName);

signals:
	void DirectoryChanged();

private:
	QString _directoryName;
	QList<FileInfo*> _filesList;

	FileInfoFactory _fileInfoFactory;

	void ReadDirectory();
	void Cleanup();
};

#endif // FILESLISTMODEL_H
