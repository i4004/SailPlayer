#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController();
	~SailPlayerController();

	void ExposeComponentsToQml(QQuickView* view);
};

#endif // SAILPLAYERCONTROLLER_HPP
