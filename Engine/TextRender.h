//
//  TextRender.h
//  Engine
//
//  Created by Skyler Burwell on 8/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_TextRender_h
#define Engine_TextRender_h

#include <SDL.h>
#include "SDL_opengl.h"
#include <FTGL/ftgl.h>
#include "Debug.h"

struct TextRender {
    void renderText(const char *text, float x, float y, float sx, float sy);
    static void createFont(FTGLPixmapFont *font);
    void renderText(FTGLPixmapFont font, const char *text);
};

#endif
