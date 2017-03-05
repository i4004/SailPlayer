#include "GPlugins.hpp"

namespace Audio
{
	namespace Gst
	{
		GPlugins::GPlugins(GPipeline* pipeline, GEqualizer* equalizer, GAutoSink* sink)
		{
			CreateBin(equalizer, sink);
			LinkPlugins(pipeline, equalizer, sink);
		}

		void GPlugins::CreateBin(GEqualizer* equalizer, GAutoSink* sink)
		{
			_element = gst_bin_new("plugins");
			gst_bin_add_many(GST_BIN(_element), equalizer->Get(), sink->Get(), NULL);
		}

		void GPlugins::LinkPlugins(GPipeline* pipeline, GEqualizer* equalizer, GAutoSink* sink)
		{
			if (!gst_element_link_many(equalizer->Get(), sink->Get(), NULL))
				qFatal("GPlugins failed to link elements");

			// Connecting pipeline with other plugins

			GstPad* pad = gst_element_get_static_pad(equalizer->Get(), "sink");
			GstPad* ghostPad = gst_ghost_pad_new("sink", pad);

			gst_pad_set_active(ghostPad, TRUE);
			gst_element_add_pad(_element, ghostPad);
			g_object_set(GST_OBJECT(pipeline->Get()), "audio-sink", _element, NULL);

			// CLeanup

			gst_object_unref(pad);
		}
	}
}
