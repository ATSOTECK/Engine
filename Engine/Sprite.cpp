//
//  Sprite.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Sprite.h"

std::vector<Sprite> Sprite::spriteList;

Sprite::Sprite() {
    texture = NULL;
    
    totalWidth = 0;
    totalHeight = 0;
    
    frameWidth = 64;
    frameHeight = 64;
    
    currentFrame = 0;
    maxFrames = 0;
    
    spriteXScale = 1.0f;
    spriteYScale = 1.0f;
    
    spriteAngle = 0.0f;
}

GLuint Sprite::getTexture() {
    return texture;
}

void Sprite::setTexture(GLuint newTexture) {
    texture = newTexture;
}

int Sprite::getCurrentFrame() {
    return animationControl.getCurrentFrame();
}

void Sprite::setCurrentFrame(int frame) {
    if (frame < 0 || frame > maxFrames) {
        return;
    }
    currentFrame = frame;
}

Vector2i Sprite::getTotalSize() {
    return totalSize;
}

int Sprite::getTotalWidth() {
    return totalWidth;
}

int Sprite::getTotalHeight() {
    return totalHeight;
}

Vector2i Sprite::getFrameSize() {
    return frameSize;
}

int Sprite::getFrameWidth() {
    return frameWidth;
}

int Sprite::getFrameHeight() {
    return frameHeight;
}

Vector2f Sprite::getSpriteScale() {
    return spriteScale;
}

float Sprite::getSpriteXScale() {
    return spriteXScale;
}

float Sprite::getSpriteYScale() {
    return spriteYScale;
}

void Sprite::setSpriteScale(Vector2f scale) {
    spriteScale.x = scale.x;
    spriteScale.y = scale.y;
}

void Sprite::setSpriteXScale(float xScale) {
    spriteXScale = xScale;
}

void Sprite::setSpriteYScale(float yScale) {
    spriteYScale = yScale;
}

float Sprite::getSpriteAngle() {
    return spriteAngle;
}

void Sprite::setSpriteAngle(float angle) {
    spriteAngle = angle;
}

void Sprite::render(const Frame frame, int column, int x, int y) {
    int _frame;
    
    switch (frame) {
        case AUTO:
            _frame = animationControl.getCurrentFrame();
            break;
        case ZERO:
            _frame = 0;
            break;
        default:
            _frame = (int) frame;
            break;
    }
    
    Texture::onDraw(texture, x, y, totalWidth, totalHeight, column * frameWidth, _frame * frameHeight, frameWidth, frameHeight);
}

void Sprite::render(const Sprite::Frame frame, int column, Vector2i position) {
    render(frame, column, position.x, position.y);
}

void Sprite::loadSprite(std::string file) {
    texture = Texture::loadTexture(file);
    
    //get the width and height of the loaded texture
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &totalWidth);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &totalHeight);
    //Debug::info(Debug::ENGINE, "%s width %i", file.c_str(), totalWidth);
    //Debug::info(Debug::ENGINE, "%s height %i", file.c_str() ,totalHeight);
    
    animationControl.maxFrames = 8;
}

void Sprite::animateSprite() {
    animationControl.onAnimate();
}

