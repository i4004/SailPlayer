import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
    id: page

	SilicaListView
	{
		anchors.fill: parent
		header: PageHeader { title: "Default Playlist"}

		model: ListModel
		{
			ListElement
			{
				artist: "Dream Theater"
				album: "Black Clouds & Silver Linings"
				year: "2009"

				songs:
				[
					ListElement { songName: "A Nightmare To Remember" },
					ListElement { songName: "A Rite Of Passage" }
				]
			}

			ListElement
			{
				artist: "Communic"
				album: "The Bottom Deep"
				year: "2011"

				songs:
				[
					ListElement { songName: "Facing Tomorrow" },
					ListElement { songName: "Denial" }
				]
			}
		}

		delegate: Column
		{
			width: parent.width

			Label
			{
				width: parent.width
				x: Theme.paddingMedium
				text: artist + " - [" + year + "] " + album
				wrapMode: Text.WordWrap
				color: Theme.highlightColor
			}

			Repeater
			{
				width: parent.width

				model: ListModel
				{
					ListElement
					{
						songName: "A Nightmare To Remember"
						trackNumber: "01"
					}

					ListElement
					{
						songName: "A Rite Of Passage"
						trackNumber: "02"
					}

					ListElement
					{
						songName: "Wither"
						trackNumber: "03"
					}
				}

				Label
				{
					width: parent.width
					x: Theme.paddingLarge
					text: trackNumber + " " + songName
					color: Theme.primaryColor
				}
			}
		}

		VerticalScrollDecorator {}
	}
}
