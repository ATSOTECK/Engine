//
//  TextRender.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "TextRender.h"

TextRender::TextRender() {
    
}

TextRender::~TextRender() {
    
}

bool TextRender::initText() {
    
    //if (FT_New_Face(Engine::ft, "", 0, &face)) {
    //    Debug::error(Debug::ENGINE, Debug::MILD, "Could not loat font!");
    //    return false;
    //}
    
    //GLuint linkOk = GL_FALSE;
    //GLuint vs, fs;
    //if (vs == cre) {
    //    
    //}
    
    return true;
}

void TextRender::renderText(const char *text, float x, float y, float sx, float sy) {
    //const char *p;
    //FT_GlyphSlot g = face->glyph;
    
    GLuint texture;
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(uniformTex, 0);
    
}

void TextRender::createFont(FTGLPixmapFont *font) {
    font->Attach("~/Library/Fonts/Arial.ttf");
    
    if (font->Error()) {
        Debug::error(Debug::ENGINE, Debug::CRITICAL, "Could not make font!");
        return;
    }
}