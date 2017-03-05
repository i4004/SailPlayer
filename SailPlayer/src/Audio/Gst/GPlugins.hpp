#ifndef GPLUGINS_H
#define GPLUGINS_H

#include "GElement.hpp"
#include "GPipeline.hpp"
#include "GEqualizer.hpp"
#include "GAutoSink.hpp"

namespace Audio
{
	namespace Gst
	{
		class GPlugins : public GElement
		{
		public:
			GPlugins(GPipeline* pipeline, GEqualizer* equalizer, GAutoSink* sink);

		private:
			void CreateBin(GEqualizer* equalizer, GAutoSink* sink);
			void LinkPlugins(GPipeline* pipeline, GEqualizer* equalizer, GAutoSink* sink);
		};
	}
}

#endif // GPLUGINS_H
