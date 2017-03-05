#ifndef GPIPELINE_H
#define GPIPELINE_H

#include <QString>

#include "GElement.hpp"

namespace Audio
{
	namespace Gst
	{
		class GPipeline : public GElement
		{
		public:
			GPipeline();
			~GPipeline();

			void SetFileToPlay(QString fullFilePath);

//			virtual void OnAboutToFinish();
		};
	}
}

#endif // GPIPELINE_H
