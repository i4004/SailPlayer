import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"

ApplicationWindow
{
	initialPage: Component { DefaultPage { } }
	cover: Qt.resolvedUrl("qml/cover/CoverPage.qml")
}
