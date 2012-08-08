//
//  Entity.cpp
//  Engine
//
//  Created by Skyler Burwell on 7/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Entity.h"

std::vector<Entity*> Entity::entityList;

std::vector<EntityCollide> EntityCollide::entityCollideList;

EntityCollide::EntityCollide() {
    entityA = NULL;
    entityB = NULL;
}

Entity::Entity() {
    entitySurface = NULL;
    texture = NULL;
    
    x = y = 0.0f;
    
    width = height = 0;
    
    moveLeft = false;
    moveRight = false;
    
    type = ENTITY_TYPE_GENERIC;
    
    dead = false;
    flags = ENTITY_FLAG_GRAVITY;
    
    speedX = speedY = 0;
    
    accelX = accelY = 0;
    
    maxSpeedX = 10;
    maxSpeedY = 15;
    
    currentFrameColumn = 0;
    currentFrameRow = 0;
    
    collisionX = collisionY = 0;
    
    collisionWidth = collisionHeight = 0;
    
    animState = 0;
    
    canJump = false;
}

Entity::~Entity() {
    
}

bool Entity::onLoad(std::string file, int width, int height, int maxFrames) {
    //if ((entitySurface = Surface::onLoad(file)) == NULL) {
        //return false;
    //}
    
    //Surface::setTransparent(entitySurface, 255, 0, 255);
    
    this->height = height;
    this->width = width;
    
    //SDL_FreeSurface(entitySurface);
    //entitySurface = NULL;
    
    animationControl.maxFrames = maxFrames;
    
    //texture = Texture::createTextureFromSDLSurface(entitySurface);
    texture = Texture::loadTexture(file);
    
    return true;
}

void Entity::onLoop() {
    //we're not moving
    if (moveLeft == false && moveRight == false) {
        stopMove();
    }
    
    if (moveLeft) {
        accelX = -0.5;
    } else if (moveRight) {
        accelX = 0.5;
    }
    
    if (flags & ENTITY_FLAG_GRAVITY) {
        accelY = 0.75f;
    }
    
    speedX += accelX * FrameRate::FPSControl.getSpeedFactor();
    speedY += accelY * FrameRate::FPSControl.getSpeedFactor();
    
    if (speedX > maxSpeedX) {
        speedX = maxSpeedX;
    }
    
    if (speedX < -maxSpeedX) {
        speedX = -maxSpeedX;
    }
    
    if (speedY > maxSpeedY) {
        speedY = maxSpeedY;
    }
    
    if (speedY < -maxSpeedY) {
        speedY = -maxSpeedY;
    }
    
    onAnimate();
    onMove(speedX, speedY);
}

void Entity::onMove(float moveX, float moveY) {
    canJump = false;
    
    if (moveX == 0 && moveY == 0) {
        return;
    }
    
    double newX = 0;
    double newY = 0;
    
    moveX *= FrameRate::FPSControl.getSpeedFactor();
    moveY *= FrameRate::FPSControl.getSpeedFactor();
    
    if (moveX != 0) {
        if (moveX >= 0) {
            newX = FrameRate::FPSControl.getSpeedFactor();
        } else {
            newX = -FrameRate::FPSControl.getSpeedFactor();
        }
    }
    
    if (moveY != 0) {
        if (moveY >= 0) {
            newY = FrameRate::FPSControl.getSpeedFactor();
        } else {
            newY = -FrameRate::FPSControl.getSpeedFactor();
        }
    }
    
    while (true) {
        if (flags & ENTITY_FLAG_GHOST) {
            posValid((int) (x + newX), (int) (y + newY)); //don't care about collisions, but we need to send events to other entities
            
            x += newX;
            y += newY;
        } else {
            if (posValid((int) (x + newX), (int) y)) {
                x += newX;
            } else {
                speedX = 0;
            }
            
            if (posValid((int) x, (int) (y + newY))) {
                y += newY;
            } else {
                if (moveY > 0) {
                    canJump = true;
                }
                
                speedY = 0;
            }
        }
        
        moveX += -newX;
        moveY += -newY;
        
        if (newX > 0 && moveX <= 0) {
            newX = 0;
        }
        
        if (newX < 0 && moveX >= 0) {
            newX = 0;
        }
        
        if (newY > 0 && moveY <= 0) {
            newY = 0;
        }
        
        if (newY < 0 && moveY >= 0) {
            newY = 0;
        }
        
        if (moveX == 0) {
            newX = 0;
        }
        
        if (moveY == 0) {
            newY = 0;
        }
        
        if (moveX == 0 && moveY == 0) {
            break;
        }
        
        if (newX == 0 && newY == 0) {
            break;
        }
    }
}

bool Entity::jump() {
    if (canJump == false) {
        return false;
    }
    
    speedY = -maxSpeedY;
    
    return true;
}

void Entity::stopMove() {
    if (speedX > 0) {
        accelX = -1;
    }
    
    if (speedX < 0) {
        accelX = 1;
    }
    
    if (speedX < 2.0f && speedX > -2.0f) {
        accelX = 0;
        speedX = 0;
    }
}

bool Entity::collides(int otherX, int otherY, int otherW, int otherH) {
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    int tx = (int) this->x + collisionX;
    int ty = (int) this->y + collisionY;
    
    left1 = tx;
    left2 = otherX;
    
    right1 = left1 + width - 1 - collisionWidth;
    right2 = otherX + otherW - 1;
    
    top1 = ty;
    top2 = otherY;
    
    bottom1 = top1 + height - 1 - collisionHeight;
    bottom2 = otherY + otherH - 1;
    
    if (bottom1 < top2) {
        return false;
    }
    
    if (top1 > bottom2) {
        return false;
    }
    
    if (right1 < left2) {
        return false;
    }
    
    if (left1 > right2) {
        return false;
    }
    
    return true;
}

bool Entity::posValid(int newX, int newY) {
    bool positionValid = true;
    
    int startX = (newX + collisionX) / TILE_SIZE;
    int startY = (newY + collisionY) / TILE_SIZE;
    
    int endX = ((newX + collisionX) + width - collisionWidth - 1) / TILE_SIZE;
    int endY = ((newY + collisionY) + height - collisionHeight - 1) /TILE_SIZE;
    
    for (int iY = startY; iY <= endY; iY++) {
        for (int iX = startX; iX <= endX; iX++) {
            Tile *tile = Area::areaControl.getTile(iX * TILE_SIZE, iY * TILE_SIZE);
            
            if (posValidTile(tile) == false) {
                positionValid = false;
            }
            
        }
    }
    
    if (flags & ENTITY_FLAG_MAPONLY) {
        
    } else {
        for (int i = 0; i < entityList.size(); i++) {
            if (posValidEntity(entityList[i], newX, newY) == false) {
                positionValid = false;
            }
        }
    }
    
    return positionValid;
}

bool Entity::posValidTile(Tile *tile) {
    if (tile == NULL) {
        return true;
    }
    
    if (tile->typeID == TILE_TYPE_BLOCK) {
        return false;
    }
    
    return true;
}

bool Entity::posValidEntity(Entity *entity, int newX, int newY) {
    if (this != entity && entity != NULL && entity->dead == false && entity->flags ^ ENTITY_FLAG_MAPONLY && 
        entity->collides(newX + collisionX, newY + collisionY, width - collisionWidth - 1, height - collisionHeight - 1) == true) {
        
        EntityCollide collideEntity;
        
        collideEntity.entityA = this;
        collideEntity.entityB = entity;
        
        EntityCollide::entityCollideList.push_back(collideEntity);
        
        return false;
    }
    
    return true;
}

void Entity::onRender(SDL_Surface *destinationSurface) {
    //if (entitySurface == NULL || destinationSurface == NULL) {
        //return;
    //}
    
    //Surface::onDraw(destinationSurface, entitySurface, x - Camera::cameraControl.getX(), y - Camera::cameraControl.getY(), currentFrameColumn * width, ( currentFrameRow + animationControl.getCurrentFrame()) * height, width, height);
    
    Texture::onDraw(texture, x - Camera::cameraControl.getX(), y - Camera::cameraControl.getY(), 128, 512, currentFrameColumn * width, currentFrameRow + animationControl.getCurrentFrame() * height, width, height);
}

void Entity::renderSprite(Sprite sprite, int frame, int x, int y) {
    
    Texture::onDraw(sprite.getTexture(), x, y, sprite.getTotalWidth(), sprite.getTotalHeight(), 
                    sprite.getCurrentFrame() * sprite.getFrameWidth(), 0, sprite.getFrameWidth(), sprite.getFrameHeight());
}

void Entity::onAnimate() {
    if (moveLeft) {
        currentFrameColumn = 0;
    } else if (moveRight) {
        currentFrameColumn = 1;
    }
    
    animationControl.onAnimate();
}

bool Entity::onCollision(Entity *entity) {
    return true;
}

void Entity::onCleanup() {
    if (entitySurface) {
        SDL_FreeSurface(entitySurface);
    }
    
    entitySurface = NULL;
    
    glDeleteTextures(1, &texture);
}