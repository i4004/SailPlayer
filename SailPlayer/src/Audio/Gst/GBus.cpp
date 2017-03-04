#include "GBus.hpp"

namespace Audio
{
	namespace Gst
	{
		GBus::GBus(GPipeline* pipeline)
		{
			GstBus* bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline->Get()));

			gst_bus_add_watch(bus, OnBusCall, this);

			gst_object_unref(bus);
		}

		GBus::~GBus()
		{
		}

		gboolean GBus::OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData)
		{
			Q_UNUSED(bus);
			Q_UNUSED(msg);
			Q_UNUSED(userData);

	//		switch (GST_MESSAGE_TYPE (msg))
	//		{
	//			case GST_MESSAGE_EOS:
	//			{
	//				static_cast<AudioPlayerBase*>(userData)->OnEndOfStream();
	//				break;
	//			}

	//			case GST_MESSAGE_ASYNC_DONE:
	//			{
	//				static_cast<AudioPlayerBase*>(userData)->OnAsyncDone();
	//				break;
	//			}

	//			case GST_MESSAGE_STREAM_START:
	//			{
	//				static_cast<AudioPlayerBase*>(userData)->OnStreamStart();
	//				break;
	//			}

	//			case GST_MESSAGE_ERROR:
	//			{
	//				gchar* debug;
	//				GError* error;

	//				gst_message_parse_error (msg, &error, &debug);
	//				g_free (debug);

	//				static_cast<AudioPlayerBase*>(userData)->OnErrorMessage(error->message);
	//				g_error_free (error);
	//				break;
	//			}

	//			default:
	//				break;
	//		}

			return TRUE;
		}
	}
}
