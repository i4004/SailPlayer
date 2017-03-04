#ifndef GBUS_H
#define GBUS_H

#include <QObject>

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
			~GBus();

		private:
			static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData);
		};
	}
}
#endif // GBUS_H
