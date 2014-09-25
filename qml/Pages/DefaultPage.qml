import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
    id: page

	SilicaListView
	{
		model: ListModel
		{
			ListElement { fruit: "jackfruit" }
			ListElement { fruit: "orange" }
			ListElement { fruit: "lemon" }
			ListElement { fruit: "lychee" }
			ListElement { fruit: "apricots" }
		}
	}
}
