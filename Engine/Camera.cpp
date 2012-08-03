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
    
    targetX = targetY = NULL;
    
    targetMode = TARGET_MODE_NORMAL;
}

void Camera::onMove(int moveX, int moveY) {
    x += moveX;
    y += moveY;
}

int Camera::getX() {
    if (targetX != NULL) {
        if (targetMode == TARGET_MODE_CENTER) {
            return *targetX - (VIEW_WIDTH / 2);
        }
        
        return *targetX;
    }
    std::cout << "x: " << x << std::endl;
    return x;
}

int Camera::getY() {
    if (targetY != NULL) {
        if (targetMode == TARGET_MODE_CENTER) {
            return *targetY - (VIEW_HEIGHT / 2);
        }
        
        return *targetY;
    }
    std::cout << "y: " << y << std::endl;
    return y;
}

void Camera::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}

void Camera::setTarget(float *x, float*y) {
    targetX = x;
    targetY = y;
}