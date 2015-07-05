#ifndef GSTEQUALIZERBANDSTATE_HPP
#define GSTEQUALIZERBANDSTATE_HPP

#include <gst/gst.h>

namespace Audio
{
	typedef struct
	{
		gfloat freq;
		gfloat width;
		gfloat gain;
	} GstEqualizerBandState;
}

#endif // GSTEQUALIZERBANDSTATE_HPP
