//
//  Sprite.h
//  Engine
//
//  Created by Skyler Burwell on 8/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Sprite_h
#define Engine_Sprite_h

#include <SDL.h>
#include "SDL_opengl.h"
#include "Texture.h"
#include "Animation.h"

class Sprite {
private:
    GLuint texture;
    
    int totalWidth, totalHeight;
    int frameWidth, frameHeight;
    
    int currentFrame;
    int maxFrames;
    
    float spriteXScale, spriteYScale;
    
    float spriteAngle;
    
public:
    enum Frame {AUTO, ZERO};
    
    Sprite();
    
    GLuint getTexture();
    void setTexture(GLuint newTexture);
    
    int getCurrentFrame();
    void setCurrentFrame(int frame);
    
    int getTotalWidth();
    int getTotalHeight();
    
    int getFrameWidth();
    int getFrameHeight();
    
    float getSpriteXScale();
    float getSpriteYScale();
    
    void setSpriteXScale(float xScale);
    void setSpriteYScale(float yScale);
    
    float getSpriteAngle();
    void setSpriteAngle(float angle);
    
    void render(const Frame frame, int column, int x, int y);
    
    void loadSprite(std::string file);
    void animateSprite();
    
    Animation animationControl;
};

#endif
