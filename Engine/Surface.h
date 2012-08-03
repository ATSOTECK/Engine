#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL.h>
#include <iostream>
#include <string.h>

class Surface {
	public:
		Surface();

    static SDL_Surface *onLoad(std::string file);

		static bool onDraw(SDL_Surface *destSurface, SDL_Surface *sourceSurface, int x, int y);
		static bool onDraw(SDL_Surface *destSurface, SDL_Surface *sourceSurface, int x, int y, int x2, int y2, int w, int h);

		static bool setTransparent(SDL_Surface *destSurface, int r, int g, int b);
};

#endif