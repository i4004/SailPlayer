#ifndef CUEINDEX_HPP
#define CUEINDEX_HPP

namespace Cue
{
	class CueIndex
	{
	public:
		CueIndex(int number, int minutes, int seconds, int frames);

		int GetNumber() { return _number; }
		int GetMinutes() { return _minutes; }
		int GetSeconds() { return _seconds; }
		int GetFrames() { return _frames; }

	private:
		int _number;
		int _minutes;
		int _seconds;
		int _frames;
	};
}

#endif // CUEINDEX_HPP
