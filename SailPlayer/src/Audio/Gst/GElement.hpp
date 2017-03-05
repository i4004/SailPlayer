#ifndef GELEMENT_H
#define GELEMENT_H

#include <gst/gst.h>

namespace Audio
{
	namespace Gst
	{
		class GElement
		{
		public:
			GElement();

			GstElement* Get() { return _element; }

		protected:
			GstElement* _element;
		};
	}
}
#endif // GELEMENT_H
