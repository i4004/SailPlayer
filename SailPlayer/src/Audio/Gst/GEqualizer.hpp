#ifndef GEQUALIZER_H
#define GEQUALIZER_H

#include "GElement.hpp"
#include "GEqualizerBand.hpp"

namespace Audio
{
	namespace Gst
	{
		class GEqualizer : public GElement
		{
		public:
			GEqualizer();

			void SetUp();\

		private:
			static int EqualizerBandsNumber;

			void SetBands();
		};
	}
}

#endif // GEQUALIZER_H
