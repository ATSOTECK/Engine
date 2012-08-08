//
//  Sprite.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite() {
    texture = NULL;
    
    totalWidth = 0;
    totalHeight = 0;
    
    frameWidth = 0;
    frameHeight = 0;
    
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
    return currentFrame;
}

void Sprite::setCurrentFrame(int frame) {
    currentFrame = frame;
}

int Sprite::getTotalWidth() {
    return totalWidth;
}

int Sprite::getTotalHeight() {
    return totalHeight;
}

int Sprite::getFrameWidth() {
    return frameWidth;
}

int Sprite::getFrameHeight() {
    return frameHeight;
}

float Sprite::getSpriteXScale() {
    return spriteXScale;
}

float Sprite::getSpriteYScale() {
    return spriteYScale;
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







