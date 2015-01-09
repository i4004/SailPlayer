#include <QString>

namespace Entities
{
	class Track
	{
	public:
		Track(QString name, QString number, QString duration);

	private:
		QString _name;
		QString _number;
		QString _duration;
	};
}
