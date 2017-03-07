import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
	id: page

	SilicaFlickable
	{
		anchors.fill: parent
		contentHeight: column.height

		Column
		{
			id: column

			width: page.width

			PageHeader
			{
				title: qsTr("Track Info")
			}
		}
	}
}
