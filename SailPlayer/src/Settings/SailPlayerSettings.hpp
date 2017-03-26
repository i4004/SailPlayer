#ifndef SAILPLAYERSETTINGS_H
#define SAILPLAYERSETTINGS_H

#include <QSettings>

namespace Settings
{
	class SailPlayerSettings
	{
	public:
		SailPlayerSettings();

		int GetActivePlaylistID();
		void SetActivePlaylistID(int id = -1);

	private:
		QSettings settings;
	};
}
#endif // SAILPLAYERSETTINGS_H
