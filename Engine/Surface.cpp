#include "Surface.h"
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"

Surface::Surface() {

}

SDL_Surface *Surface::onLoad(std::string file) {
	SDL_Surface *tempSurface = NULL;
	SDL_Surface *returnSurface = NULL;

	if ((tempSurface = IMG_Load(file.c_str())) == NULL) {
		fprintf(stderr, "Could not load %s!\n", file.c_str());
		return NULL;
	}

	returnSurface = SDL_DisplayFormatAlpha(tempSurface);
	SDL_FreeSurface(tempSurface);

	return returnSurface;
}

bool Surface::onDraw(SDL_Surface *destSurface, SDL_Surface *sourceSurface, int x, int y) {
	if (destSurface == NULL || sourceSurface == NULL) {
		fprintf(stderr, "Surface error!\n");
		return false;
	}

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;

	SDL_BlitSurface(sourceSurface, NULL, destSurface, &destRect);

	return true;
}

bool Surface::onDraw(SDL_Surface *destSurface, SDL_Surface *sourceSurface, int x, int y, int x2, int y2, int w, int h) {
	if (destSurface == NULL || sourceSurface == NULL) {
		fprintf(stderr, "Surface error!\n");
		return false;
	}

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;

	SDL_Rect sourceRect;
	sourceRect.x = x2;
	sourceRect.y = y2;
	sourceRect.w = w;
	sourceRect.h = h;

	SDL_BlitSurface(sourceSurface, &sourceRect, destSurface, &destRect);

	return true;
}

bool Surface::setTransparent(SDL_Surface *destSurface, int r, int g, int b) {
	if (destSurface == NULL) {
		fprintf(stderr, "Surface error!\n");
		return false;
	}

	SDL_SetColorKey(destSurface, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(destSurface->format, r, g, b));

	return true;
}