#include "GAutoSink.hpp"

namespace Audio
{
	namespace Gst
	{
		GAutoSink::GAutoSink()
		{
			_element = gst_element_factory_make("autoaudiosink", NULL);
		}
	}
}
