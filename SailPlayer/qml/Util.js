// Adds leading zeros to number
function zeroPad(number, digits)
{
	var num = number + "";

	while(num.length < digits)
	{
		num= '0' + num;
	}

	return num;
}

// Format track duration to format like HH:mm:ss / m:ss
function formatTrackDuration(trackDuration /* track duration in seconds */)
{
	var seconds = trackDuration % 60;
	var totalMinutes = (trackDuration - seconds) / 60;
	var minutes = totalMinutes % 60;
	var hours = (totalMinutes - minutes) / 60;

	return (hours > 0 ? hours + ":" : "")
			+ (minutes > 0 ? (hours > 0 ? Util.zeroPad(minutes, 2) : minutes) + ":" : "")
			+ Util.zeroPad(seconds, 2);
}
