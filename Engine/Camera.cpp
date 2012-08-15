//
//  Camera.cpp
//  Engine
//
//  Created by Skyler Burwell on 7/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Camera.h"

Camera Camera::cameraControl;

Camera::Camera() {
    x = y = 0;
    pos.x = 0;
    pos.y = 0;
    
    targetX = targetY = NULL;
    targetPos = NULL;
    
    targetMode = TARGET_MODE_NORMAL;
}

void Camera::onMove(int moveX, int moveY) {
    pos.x += moveX;
    pos.y += moveY;
}

void Camera::onMove(Vector2i newPos) {
    onMove(newPos.x, newPos.y);
}

Vector2f Camera::getPosition() {
    if (targetPos != NULL) {
        if (targetMode == TARGET_MODE_CENTER) {
            Vector2f temp;
            temp.x = targetPos->x - (VIEW_WIDTH / 2);
            temp.y = targetPos->y - (VIEW_HEIGHT / 2);
            return temp;
        }
        
        return *targetPos;
    }
    
    Vector2f temp;
    temp.x = pos.x;
    temp.y = pos.y;
    return temp;
}

Vector2f Camera::getNegativePos() {
    Vector2f temp = getPosition();
    
    temp.x *= -1;
    temp.y *= -1;
    
    return temp;
}

int Camera::getX() {
    if (targetPos != NULL) {
        if (targetMode == TARGET_MODE_CENTER) {
            return targetPos->x - (VIEW_WIDTH / 2);
        }
        
        return targetPos->x;
    }
    
    return pos.x;
}

int Camera::getY() {
    if (targetPos != NULL) {
        if (targetMode == TARGET_MODE_CENTER) {
            return targetPos->y - (VIEW_HEIGHT / 2);
        }
        
        return targetPos->y;
    }
    
    return pos.y;
}

void Camera::setPos(int x, int y) {
    this->pos.x = x;
    this->pos.y = y;
}

void Camera::setPos(Vector2i pos) {
    this->pos = pos;
}

void Camera::setTarget(float *x, float*y) {
    targetPos->x = *x;
    targetPos->y = *y;
}

void Camera::setTarget(Vector2f *targetPos) {
    this->targetPos = targetPos;
}