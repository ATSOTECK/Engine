//
//  TextRender.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "TextRender.h"

namespace freetype {
    inline int next_p2(int a) {
        int rval = 1;
        
        while (rval < a) {
            rval <<= 1;
        }
        
        return rval;
    }
    
    void makeDisplayList(FT_Face face, char ch, GLuint listBase, GLuint *texBase) {
        if (FT_Load_Glyph(face, FT_Get_Char_Index(face, ch), FT_LOAD_DEFAULT)) {
            throw std::runtime_error("FT_Load_Glyph failed!");
        }
        
        FT_Glyph glyph;
        if (FT_Get_Glyph(face->glyph, &glyph)) {
            throw  std::runtime_error("FT_Get_Glyph failed!");
        }
        
        FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL, 0, 1);
        FT_BitmapGlyph bitmapGlyph = (FT_BitmapGlyph) glyph;
        
        FT_Bitmap &bitmap = bitmapGlyph->bitmap;
        
        int width = next_p2(bitmap.width);
        int height = next_p2(bitmap.rows);
        
        GLubyte *expandedData = new GLubyte [2 * width * height];
        
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                expandedData[2 * (i + j * width)] = 255;
                expandedData[2 * (i + j * width) + 1] = (i >= bitmap.width || j >= bitmap.rows) ? 0 : bitmap.buffer[i + bitmap.width * j];
                //expandedData[2 * (i + j * width)] = expandedData[2 * (i + j * width) + 1] = (i >= bitmap.width || j >= bitmap.rows) ? 0 : bitmap.buffer[i + bitmap.width * j];
            }
        }
        
        glBindTexture(GL_TEXTURE_2D, texBase[ch]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, expandedData);
        
        delete [] expandedData;
        
        glNewList(listBase + ch, GL_COMPILE);
        
        glBindTexture(GL_TEXTURE_2D, texBase[ch]);
        
        glPushMatrix();
        
        glTranslatef(bitmapGlyph->left, 0.0f, 0.0f);
        
        glTranslatef(0.0f, bitmapGlyph->top - bitmap.rows, 0.0f);
        
        float x = (float) bitmap.width / (float) width;
        float y = (float) bitmap.rows / (float) height;
        
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);   glVertex2f(0.0f, bitmap.rows);
            glTexCoord2f(0.0f, y);      glVertex2f(0.0f, 0.0f);
            glTexCoord2f(x, y);         glVertex2f(bitmap.width, 0.0);
            glTexCoord2f(x, 0.0f);      glVertex2f(bitmap.width, bitmap.rows);
        glEnd();
        
        glPopMatrix();
        
        glTranslatef(face->glyph->advance.x >> 6, 0.0f, 0.0f);
        
        glEndList();
        
        FT_Done_Glyph(glyph);
    }
    
    void fontData::init(const char *fname, unsigned int h) {
        textures = new GLuint[128];
        
        this->h = h;
        
        FT_Library library;
        
        if (FT_Init_FreeType(&library)) {
            throw std::runtime_error("FT_Init_FreeType failed");
        }
        
        FT_Face face;
        
        if (FT_New_Face(library, fname, 0, &face)) {
            throw std::runtime_error("FT_New_Face failed (there is probably a problem with your font file)");
        }
        
        FT_Set_Char_Size(face, h << 6, h << 6, 96, 96);
        
        listBase = glGenLists(128);
        glGenTextures(128, textures);
        
        for (unsigned char i = 0; i < 128; i++) {
            makeDisplayList(face, i, listBase, textures);
        }
        
        FT_Done_Face(face);
        
        FT_Done_FreeType(library);
    }
    
    void fontData::cleanup() {
        glDeleteLists(listBase, 128);
        glDeleteTextures(128, textures);
        delete [] textures;
    }
    
    inline void pushScreenCoordinateMatrix() {
        glPushAttrib(GL_TRANSFORM_BIT);
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(viewport[0],viewport[2],viewport[1],viewport[3]);
        glPopAttrib();
    }
    
    inline void popProjectionMatrix() {
        glPushAttrib(GL_TRANSFORM_BIT);
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glPopAttrib();
    }
    
    void print(const fontData &ft_font, float x, float y, float angle, const char *fmt, ...) {
        pushScreenCoordinateMatrix();
        
        GLuint font = ft_font.listBase;
        
        float h = ft_font.h / .63f;
        char text[256];
        va_list ap;
        if (fmt == NULL) {
            *text = 0;
        } else {
            va_start(ap, fmt);
            vsprintf(text, fmt, ap);
            va_end(ap);
        }
        
        const char *startLine = text;
        vector<string> lines;
        const char *c = text;
        for (; *c; c++) {
            if (*c == '\n') {
                string line;
                for (const char *n = startLine; n < c; n++) {
                    line.append(1, *n);
                }
                lines.push_back(line);
                startLine = c + 1;
            }
        }
        
        if (startLine) {
            string line;
            for (const char *n = startLine; n < c; n++) {
                line.append(1, *n);
            }
            lines.push_back(line);
        }
        
        glPushAttrib(GL_LIST_BIT | GL_CURRENT_BIT  | GL_ENABLE_BIT | GL_TRANSFORM_BIT);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);     
        
        glListBase(font);
        
        float modelviewMatrix[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, modelviewMatrix);
        
        for (int i = 0; i < lines.size(); i++) {
            glPushMatrix();
            glLoadIdentity();
            glTranslatef(x, y - (h * i), 0);
            glRotatef(angle, 0, 0, 1);
            glMultMatrixf(modelviewMatrix);
            
            glCallLists(lines[i].length(), GL_UNSIGNED_BYTE, lines[i].c_str());
            
            glPopMatrix();
        }
        
        glPopAttrib();
        
        popProjectionMatrix();
    }
}









