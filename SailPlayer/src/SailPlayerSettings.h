#ifndef SAILPLAYERSETTINGS_H
#define SAILPLAYERSETTINGS_H

#include <QString>
#include <QSettings>

class SailPlayerSettings : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString lastAddFilesDirectoryPath READ GetLastAddFilesDirectoryPath() WRITE SetLastAddFilesDirectoryPath(QString) NOTIFY LastAddFilesDirectoryPathChanged())

public:
	static SailPlayerSettings& Default();

	QString GetLastAddFilesDirectoryPath();
	void SetLastAddFilesDirectoryPath(QString value);

signals:
	void LastAddFilesDirectoryPathChanged();

private:
	QSettings settings;
};

#endif // SAILPLAYERSETTINGS_H
