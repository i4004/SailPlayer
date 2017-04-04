#ifndef SAILPLAYERSETTINGS_H
#define SAILPLAYERSETTINGS_H

#include <QSettings>

namespace Settings
{
	class SailPlayerSettings : public QObject
	{
		Q_OBJECT
		Q_PROPERTY(QString lastDirectorySelectionPath READ GetLastDirectorySelectionPath WRITE SetLastDirectorySelectionPath NOTIFY LastDirectorySelectionPathChanged)

	public:
		int GetActivePlaylistID();
		void SetActivePlaylistID(int id = -1);

		QString GetLastDirectorySelectionPath();
		void SetLastDirectorySelectionPath(const QString& value);

	signals:
		void LastDirectorySelectionPathChanged();

	private:
		static QString DefaultLastDirectorySelectionPath;

		QSettings settings;
	};
}
#endif // SAILPLAYERSETTINGS_H
