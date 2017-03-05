#include "GBus.hpp"

#ifdef QT_DEBUG
#include <QDebug>
#endif

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

		void GBus::OnStreamStart()
		{
			#ifdef QT_DEBUG
			qDebug() << "Stream started";
			#endif
		}

		void GBus::OnAsyncDone()
		{
			#ifdef QT_DEBUG
			qDebug() << "Async done";
			#endif
		}

		void GBus::OnEndOfStream()
		{
			#ifdef QT_DEBUG
			qDebug() << "End of stream";
			#endif
		}

		void GBus::OnErrorMessage(QString message)
		{
			#ifdef QT_DEBUG
			qDebug() << "Error: " << message;
			#endif
		}

		gboolean GBus::OnBusCall(GstBus* gstBus, GstMessage* msg, gpointer userData)
		{
			Q_UNUSED(gstBus);

			GBus* bus = static_cast<GBus*>(userData);

			switch (GST_MESSAGE_TYPE (msg))
			{

				case GST_MESSAGE_STREAM_START:
				{
					bus->OnStreamStart();
					break;
				}

				case GST_MESSAGE_ASYNC_DONE:
				{
					bus->OnAsyncDone();
					break;
				}

				case GST_MESSAGE_EOS:
				{
					bus->OnEndOfStream();
					break;
				}

				case GST_MESSAGE_ERROR:
				{
					gchar* debug;
					GError* error;

					gst_message_parse_error(msg, &error, &debug);

					bus->OnErrorMessage(error->message);

					g_free (debug);
					g_error_free (error);

					break;
				}

				default:
					break;
			}

			return TRUE;
		}
	}
}
