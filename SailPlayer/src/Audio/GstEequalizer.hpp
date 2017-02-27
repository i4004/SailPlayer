#ifndef GSTEQUALIZER_H
#define GSTEQUALIZER_H

#include <gst/gst.h>

#include "GstEqualizerBandState.hpp"

namespace Audio
{
	class GstEequalizer
	{
	public:
		GstEequalizer();

		void SetUp();\

		GstElement* GetElement() { return _element; }
		bool IsInitialized() { return _element; }

	private:
		static int EqualizerBandsNumber;

		GstElement* _element;

		void SetBands();
	};
}

#endif // GSTEQUALIZER_H
