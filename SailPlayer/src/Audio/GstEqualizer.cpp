#include "GstEequalizer.hpp"

namespace Audio
{
	int GstEequalizer::EqualizerBandsNumber = 18;

	GstEequalizer::GstEequalizer()
	{
		_element = gst_element_factory_make ("equalizer-nbands", NULL);
	}

	void GstEequalizer::SetUp()
	{
		g_object_set(G_OBJECT(_element), "num-bands", EqualizerBandsNumber, NULL);

		SetBands();
	}

	void GstEequalizer::SetBands()
	{
		gint i;
		GObject *band;

		GstEqualizerBandState equalizerData[] = {
			{ 55.0,   22.0, 0.0},
			{ 77.0,   33.0, 0.0},
			{110.0,   46.0, 0.0},
			{156.0,   64.0, 0.0},
			{220.0,   91.0, 0.0},
			{311.0,   129.0, 0.0},
			{440.0,   182.0, 0.0},
			{622.0,   258.0, 0.0},
			{880.0,   320.0, 0.0},
			{1200.0,   600.0, 0.0},
			{1800.0,   700.0, 0.0},
			{2500.0,   1000.0, 0.0},
			{3500.0,   1500.0, 0.0},
			{5000.0,   2000.0, 0.0},
			{7000.0,   3000.0, 0.0},
			{10000.0,  4000.0, 0.0},
			{14000.0,  6000.0, 0.0},
			{20000.0,  6000.0, 0.0},

//			{ 55.0,   22.0, 0.0},
//			{ 77.0,   33.0, 1.0},
//			{110.0,   46.0, 0.0},
//			{156.0,   64.0, 0.0},
//			{220.0,   91.0, -1.0},
//			{311.0,   129.0, -2.0},
//			{440.0,   182.0, -3.0},
//			{622.0,   258.0, -2.0},
//			{880.0,   320.0, -1.0},
//			{1200.0,   600.0, 0.0},
//			{1800.0,   700.0, 0.0},
//			{2500.0,   1000.0, 0.0},
//			{3500.0,   1500.0, 0.0},
//			{5000.0,   2000.0, 0.0},
//			{7000.0,   3000.0, 0.0},
//			{10000.0,  4000.0, 1.0},
//			{14000.0,  6000.0, 1.0},
//			{20000.0,  6000.0, 1.0},
			};

		for (i = 0; i < EqualizerBandsNumber; i++)
		{
			band = gst_child_proxy_get_child_by_index(GST_CHILD_PROXY(_element), i);
			g_object_set(G_OBJECT(band), "freq", equalizerData[i].freq, "bandwidth", equalizerData[i].width, "gain", equalizerData[i].gain, NULL);

			g_object_unref(G_OBJECT(band));
		}
	}
}
