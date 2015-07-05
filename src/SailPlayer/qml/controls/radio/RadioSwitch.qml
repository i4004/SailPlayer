import QtQuick 2.0
import Sailfish.Silica 1.0

Switch
{
	id: item
	property RadioGroup radioGroup

	function check()
	{
		if(radioGroup != null)
		{
			checked = true;

			if(radioGroup.selectedItem != null && radioGroup.selectedItem != item)
				radioGroup.selectedItem.checked = false;

			radioGroup.selectedItem = item
		}
	}

	onClicked: check()
}
