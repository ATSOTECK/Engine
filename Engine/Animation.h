#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <SDL.h>

class Animation {
	private:
		int currentFrame;
		int frameInc;
		int frameRate;
		long oldTime;

	public:
		int maxFrames;
		bool oscillate;

		Animation();
		void onAnimate();
		void setFrameRate(int rate);
		void setCurrentFrame(int frame);
		int getCurrentFrame();
};

#endif