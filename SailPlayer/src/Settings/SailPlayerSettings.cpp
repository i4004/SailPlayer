#include "SailPlayerSettings.hpp"

namespace Settings
{
	QString SailPlayerSettings::DefaultLastDirectorySelectionPath = "/home/nemo";

	int SailPlayerSettings::GetActivePlaylistID()
	{
		return settings.value("ActivePlaylistID", -1).toInt();
	}

	void SailPlayerSettings::SetActivePlaylistID(int id)
	{
		settings.setValue("ActivePlaylistID", id);
	}

	QString SailPlayerSettings::GetLastDirectorySelectionPath()
	{
		return settings.value("LastDirectorySelectionPath", DefaultLastDirectorySelectionPath).toString();
	}

	void SailPlayerSettings::SetLastDirectorySelectionPath(const QString& value)
	{
		settings.setValue("LastDirectorySelectionPath", value);

		emit LastDirectorySelectionPathChanged();
	}
}
