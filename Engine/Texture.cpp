//
//  Texture.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Texture.h"
#include <string.h>

Texture::Texture() {
    
}

GLuint Texture::createTextureFromSDLSurface(SDL_Surface *surface) {
    GLuint texture;
    
    //generate a texture object
    glGenTextures(1, &texture);
    //bind the texture object
    glBindTexture(GL_TEXTURE_2D, texture);
    //set the textures stretching properties
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR ); 
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    //edit the texture object's data using the information SDL_Surface gives us
    glTexImage2D(GL_TEXTURE_2D, 0, 3, surface->w, surface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);
    
    return texture;
}

GLuint Texture::loadTexture(std::string file) {
    GLuint texture;
    SDL_Surface *surface;
    void *raw;
    int w, h, i, j, bpp;
    Uint8 *srcPixel, *destPixel;
    Uint32 truePixel;
    GLenum errorCode;
    
    if ((surface = IMG_Load(file.c_str())) == NULL) {
        fprintf(stderr, "Could not load %s!\n", file.c_str());
        return 0;
    }
    
    if (surface->format->BytesPerPixel < 2) {
        fprintf(stderr, "%s is a bad image, not in true color!\n", file.c_str());
        SDL_FreeSurface(surface);
        return 0;
    }
    
    w = surface->w;
    h = surface->h;
    
    raw = (void *) malloc(w * h * 4);
    destPixel = (Uint8 *) raw;
    
    SDL_LockSurface(surface);
    
    bpp = surface->format->BytesPerPixel;
    
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            srcPixel = (Uint8 *) surface->pixels + i * surface->pitch + j * bpp;
            
            switch (bpp) {
                case 1:
                    truePixel = *srcPixel;
                    break;
                case 2:
                    truePixel = *(Uint16 *) srcPixel;
                    break;
                case 3:
                    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                        truePixel = srcPixel[0] << 16 | srcPixel[1] << 8 | srcPixel[2];
                    } else {
                        truePixel = srcPixel[0] | srcPixel[1] << 8 | srcPixel[2] << 16;
                    }
                    break;
                case 4:
                    truePixel = *(Uint32 *)srcPixel;
                    break;
                default:
                    fprintf(stderr, "Image bpp of %d unuseable!\n", bpp);
                    SDL_UnlockSurface(surface);
                    SDL_FreeSurface(surface);
                    free(raw);
                    return 0;
                    break;
            }
            
            SDL_GetRGBA(truePixel, surface->format, &(destPixel[0]), &(destPixel[1]), &(destPixel[2]), &(destPixel[3]));
            destPixel++;
            destPixel++;
            destPixel++;
            destPixel++;
        }
    }
    
    SDL_UnlockSurface(surface);
    SDL_FreeSurface(surface);
    
    while (glGetError()) {
        ;
    }
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    
    errorCode = glGetError();
    if (errorCode != 0) {
        if (errorCode == GL_OUT_OF_MEMORY) {
            fprintf(stderr, "Out of memory!\n");
        }
        
        glDeleteTextures(1, &texture);
        free(raw);
        return 0;
    }
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, w, h, GL_RGBA, GL_UNSIGNED_BYTE, (Uint8 *)raw);
    
    errorCode = glGetError();
    if (errorCode != 0) {
        if (errorCode == GL_OUT_OF_MEMORY) {
            fprintf(stderr, "Out of memory!\n");
        }
        
        glDeleteTextures(1, &texture);
        free(raw);
        return 0;
    }
    
    free(raw);
    return texture;
}

bool Texture::onDraw(GLuint texture, int x, int y, int w, int h) {
    glBegin(GL_QUADS);
        //top left
        glTexCoord2i(0, 0);
        glVertex3f(x, y, 0);
    
        //bottom left
        glTexCoord2i(1, 0);
        glVertex3f(x, y + h, 0);
    
        //bottom right
        glTexCoord2i(1, 1);
        glVertex3f(x + w, y + h, 0);
    
        //top right
        glTexCoord2i(0, 1);
        glVertex3f(x + w, y, 0);
    
    glEnd();
    
    return true;
}

bool Texture::onDraw(GLuint texture, int x, int y, int w, int h, int x2, int y2, int w2, int h2) {
    
    float wRatio = (float)w2 / w;
    float hRatio = (float)h2 / h;
    
    float tx, ty;
    
    tx = (float)x2 / w;
    ty = (float)y2 / h;
    
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    //glMatrixMode(GL_TEXTURE);
    //glLoadIdentity();
    //glMatrixMode(GL_MODELVIEW);
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
    
    glBegin(GL_TRIANGLE_STRIP);
    
        //bottom left
        glTexCoord2f(tx, ty + hRatio);
        glVertex3f(x, y + h2, 0);
    
        //top left
        glTexCoord2f(tx, ty);
        glVertex3f(x, y, 0);
    
        //bottom right
        glTexCoord2f(tx + wRatio, ty + hRatio);
        glVertex3f(x + w2, y + h2, 0);
    
        //top right
        glTexCoord2f(tx + wRatio, ty);
        glVertex3f(x + w2, y, 0);
    
    glEnd();
    
    return true;
}









