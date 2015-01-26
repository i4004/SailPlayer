#include "SailPlayerSettings.h"

SailPlayerSettings& SailPlayerSettings::Default()
{
	static SailPlayerSettings settings;
	return settings;
}

QString SailPlayerSettings::GetLastAddFilesDirectoryPath()
{
	return settings.value("AddFilesDialog/CurrentPath", "/home/nemo").toString();
}

void SailPlayerSettings::SetLastAddFilesDirectoryPath(QString value)
{
	return settings.setValue("AddFilesDialog/CurrentPath", value);
}
