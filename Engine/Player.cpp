//
//  Player.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Player.h"

Player::Player() {
    
}

bool Player::onLoad(std::string file, int width, int height, int maxFrames) {
    if (Entity::onLoad(file, width, height, maxFrames) == false) {
        return false;
    }
    
    return true;
}

void Player::onLoop() {
    Entity::onLoop();
}

void Player::onRender(SDL_Surface *displaySurface) {
    Entity::onRender(displaySurface);
}

void Player::onAnimate() {
    if (speedX != 0) {
        animationControl.maxFrames = 8;
    } else {
        animationControl.maxFrames = 0;
    }
    
    Entity::onAnimate();
}

bool Player::onCollision(Entity *entity) {
    jump();
    
    return true;
}

void Player::onCleanup() {
    Entity::onCleanup();
}