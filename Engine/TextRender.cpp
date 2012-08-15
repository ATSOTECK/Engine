//
//  TextRender.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "TextRender.h"

void TextRender::renderText(const char *text, float x, float y, float sx, float sy) {
    //const char *p;
    
}

void TextRender::createFont(FTGLPixmapFont *font) {
    font->Attach("~/Library/Fonts/Arial.ttf");
    
    if (font->Error()) {
        Debug::error(Debug::ENGINE, Debug::CRITICAL, "Could not make font!");
        return;
    }
}

void TextRender::renderText(FTPixmapFont font, const char *text) {
    font.Render(text);
}