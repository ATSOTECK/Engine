//
//  Sprite.h
//  Engine
//
//  Created by Skyler Burwell on 8/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Sprite_h
#define Engine_Sprite_h

#include <vector>
#include <SDL.h>
#include "SDL_opengl.h"
#include "Texture.h"
#include "Animation.h"
#include "Vector.h"

class Sprite {
private:
    GLuint texture;
    
    Vector2i totalSize;
    int totalWidth, totalHeight;
    
    Vector2i frameSize;
    int frameWidth, frameHeight;
    
    int currentFrame;
    int maxFrames;
    
    Vector2f spriteScale;
    float spriteXScale, spriteYScale;
    
    float spriteAngle;
    
public:
    static std::vector<Sprite> spriteList;
    
    enum Frame {AUTO, ZERO};
    
    Sprite();
    
    GLuint getTexture();
    void setTexture(GLuint newTexture);
    
    int getCurrentFrame();
    void setCurrentFrame(int frame);
    
    Vector2i getTotalSize();
    int getTotalWidth();
    int getTotalHeight();
    
    Vector2i getFrameSize();
    int getFrameWidth();
    int getFrameHeight();
    
    Vector2f getSpriteScale();
    float getSpriteXScale();
    float getSpriteYScale();
    
    void setSpriteScale(Vector2f scale);
    void setSpriteXScale(float xScale);
    void setSpriteYScale(float yScale);
    
    float getSpriteAngle();
    void setSpriteAngle(float angle);
    
    void render(const Frame frame, int column, int x, int y);
    void render(const Frame frame, int column, Vector2i position);
    
    void loadSprite(std::string file);
    void animateSprite();
    
    Animation animationControl;
};

#endif