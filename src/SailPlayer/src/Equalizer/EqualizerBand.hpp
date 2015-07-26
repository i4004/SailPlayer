#ifndef EQUALIZERBAND_HPP
#define EQUALIZERBAND_HPP

namespace Equalizer
{
	class EqualizerBand
	{
	public:
		EqualizerBand();
		EqualizerBand(float frequency, float width, float gain);
		EqualizerBand(EqualizerBand& band);

		float GetFrequency() { return _frequency; }
		void SetFrequency(float frequency) { _frequency = frequency; }

		float GetWidth() { return _width; }
		void SetWidth(float width) { _width = width; }

		float GetGain() { return _gain; }
		void SetGain(float gain) { _gain = gain; }

	private:
		float _frequency;
		float _width;
		float _gain;
	};
}

#endif // EQUALIZERBAND_HPP
