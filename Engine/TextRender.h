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
//#include <FTGL/ftgl.h>
#include <ft2build.h>
#include <FreeType/freetype.h>
#include <FreeType/ftglyph.h>
#include <FreeType/ftoutln.h>
#include <FreeType/fttrigon.h>
#include FT_FREETYPE_H

#include <vector>
#include <string>

#include <stdexcept>

namespace freetype {
    using std::vector;
    using std::string;
    
    struct fontData {
    public:
        float h;
        GLuint *textures;
        GLuint listBase;
        
        void init(const char *fname, unsigned int h);
        
        void cleanup();
    };
    
    void print(const fontData &ft_font, float x, float y, float angle, const char *fmt, ...);
}

#endif