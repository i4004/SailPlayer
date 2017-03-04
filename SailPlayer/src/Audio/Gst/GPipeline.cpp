#include "GPipeline.hpp"

namespace Audio
{
	namespace Gst
	{
		GPipeline::GPipeline()
		{
	//		_element = gst_parse_launch("playbin", NULL);
		}

		GPipeline::~GPipeline()
		{
	//		gst_element_set_state(_element, GST_STATE_NULL);
	//		gst_object_unref(GST_OBJECT(_element));
		}


		void GPipeline::SetFileToPlay(QString fullFilePath)
		{
	//		g_object_set(_element, "uri", QString("file://" + fullFilePath).toLocal8Bit().data(), NULL);
		}
	}
}
