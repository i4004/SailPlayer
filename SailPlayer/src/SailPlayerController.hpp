#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QQuickView>

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController(QQuickView* view, QObject* parent = 0);
	~SailPlayerController();
};

#endif // SAILPLAYERCONTROLLER_HPP
