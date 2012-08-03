//
//  Texture.h
//  Engine
//
//  Created by Skyler Burwell on 8/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Texture_h
#define Engine_Texture_h

#include <SDL.h>
#include "SDL_opengl.h"
#include "SDL_image.h"
#include <iostream>
#include <string.h>

class Texture {
public:
    Texture();
    
    static GLuint createTextureFromSDLSurface(SDL_Surface *surface);
    
    static GLuint loadTexture(std::string file);
    
    static bool onDraw(GLuint texture, int x, int y, int w, int h);
    static bool onDraw(GLuint texture, int x, int y, int w, int h, int x2, int y2, int w2, int h2);
};

#endif
