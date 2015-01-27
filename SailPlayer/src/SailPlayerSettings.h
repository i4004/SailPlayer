#ifndef SAILPLAYERSETTINGS_H
#define SAILPLAYERSETTINGS_H

#include <QString>
#include <QSettings>

class SailPlayerSettings : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString defaultAddFilesDirectoryPath READ GetDefaultAddFilesDirectoryPath)
	Q_PROPERTY(QString lastAddFilesDirectoryPath READ GetLastAddFilesDirectoryPath() WRITE SetLastAddFilesDirectoryPath(QString) NOTIFY LastAddFilesDirectoryPathChanged())

public:
	static SailPlayerSettings& Default();

	QString GetDefaultAddFilesDirectoryPath() const { return DefaultAddFilesDirectoryPath; }
	QString GetLastAddFilesDirectoryPath();
	void SetLastAddFilesDirectoryPath(QString value);

signals:
	void LastAddFilesDirectoryPathChanged();

private:
	static QString DefaultAddFilesDirectoryPath;

	QSettings settings;
};

#endif // SAILPLAYERSETTINGS_H
