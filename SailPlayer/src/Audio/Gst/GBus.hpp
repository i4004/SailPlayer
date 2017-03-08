#ifndef GBUS_H
#define GBUS_H

#include <QString>

#include <gst/gst.h>

#include "GPipeline.hpp"

namespace Audio
{
	namespace Gst
	{
		class GBus
		{
		public:
			GBus(GPipeline* pipeline);
			virtual ~GBus();

			virtual void OnStreamStart();
			virtual void OnAsyncDone();
			virtual void OnEndOfStream();
			virtual void OnErrorMessage(QString message);

		private:
			static gboolean OnBusCall(GstBus* gstBus, GstMessage* msg, gpointer userData);
		};
	}
}
#endif // GBUS_H
