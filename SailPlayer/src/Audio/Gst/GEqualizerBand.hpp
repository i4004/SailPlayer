#ifndef GEQUALIZERBAND_HPP
#define GEQUALIZERBAND_HPP

namespace Audio
{
	namespace Gst
	{
		typedef struct
		{
			float Frequency;
			float Width;
			float Gain;
		} GEqualizerBandState;
	}
}

#endif // GEQUALIZERBAND_HPP
