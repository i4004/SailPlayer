#ifndef GPIPELINE_H
#define GPIPELINE_H

#include <QString>

#include <gst/gst.h>

namespace Audio
{
	namespace Gst
	{
		class GPipeline
		{
		public:
			GPipeline();
			~GPipeline();

			GstElement* Get() { return _element; }
			bool IsInitialized() { return _element; }

			void SetFileToPlay(QString fullFilePath);

		private:
			GstElement* _element;
		};
	}
}

#endif // GPIPELINE_H
