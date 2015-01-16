#include "AudioPlayer.h"

namespace UI
{
	AudioPlayer::AudioPlayer()
	{
		gst_init(NULL, NULL);
	}

	AudioPlayer::~AudioPlayer()
	{
		gst_object_unref (gstream.bus);
		gst_element_set_state (gstream.pipeline, GST_STATE_NULL);
		gst_object_unref (gstream.pipeline);
	}

	void AudioPlayer::play()
	{\
//		gstream.pipeline = gst_parse_launch ("filesrc location=/home/nemo/Music/Ringtones/01 - Pull Me Under.mp3", NULL);
//		gstream.bus = gst_element_get_bus (gstream.pipeline);

//		gst_element_set_state (gstream.pipeline, GST_STATE_PLAYING);
	}
}
