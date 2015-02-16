#ifndef CUEINDEX_HPP
#define CUEINDEX_HPP

namespace Cue
{
	class CueIndex
	{
	public:
		CueIndex(int minutes, int seconds, int frames);

		int GetMinutes() { return _minutes; }
		int GetSeconds() { return _seconds; }
		int GetFrames() { return _frames; }

	private:
		int _minutes;
		int _seconds;
		int _frames;
	};
}

#endif // CUEINDEX_HPP
