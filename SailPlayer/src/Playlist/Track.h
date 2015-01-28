#include <QString>

namespace Playlist
{
	class Track
	{
	public:
		Track(QString name, QString sourceFileName);

	private:
		QString _name;
		QString _sourceFileName;
	};
}
