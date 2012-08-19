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
#include <SDL_ttf.h>
#include <FTGL/ftgl.h>
#include "Main.h"

class TextRender {
public:
    TextRender();
    ~TextRender();
    
    bool initText();
    void renderText(const char *text, float x, float y, float sx, float sy);
    static void createFont(FTGLPixmapFont *font);
    
    FT_Face face;
    
    GLuint program;
    GLuint attributeCoord;
    GLuint uniformTex;
    GLuint uniformColor;
};

#endif
