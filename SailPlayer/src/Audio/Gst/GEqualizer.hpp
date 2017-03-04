#ifndef GEQUALIZER_H
#define GEQUALIZER_H

#include <gst/gst.h>

#include "GEqualizerBand.hpp"

namespace Audio
{
	namespace Gst
	{
		class GEqualizer
		{
		public:
			GEqualizer();

			void SetUp();\

			GstElement* Get() { return _element; }
			bool IsInitialized() { return _element; }

		private:
			static int EqualizerBandsNumber;

			GstElement* _element;

			void SetBands();
		};
	}
}

#endif // GEQUALIZER_H
