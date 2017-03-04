#include <gst/gst.h>

#include "GInit.hpp"

namespace Audio
{
	namespace Gst
	{
		GInit::GInit()
		{
			gst_init(NULL, NULL);
		}
	}
}
