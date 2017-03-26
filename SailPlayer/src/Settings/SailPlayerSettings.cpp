#include "SailPlayerSettings.hpp"

namespace Settings
{
	SailPlayerSettings::SailPlayerSettings()
	{
	}

	int SailPlayerSettings::GetActivePlaylistID()
	{
		return settings.value("ActivePlaylistID", -1).toInt();
	}

	void SailPlayerSettings::SetActivePlaylistID(int id)
	{
		settings.setValue("ActivePlaylistID", id);
	}
}
