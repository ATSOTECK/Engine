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
    position.x = x;
    position.y = y;
    
    width = height = 0;
    
    moveLeft = false;
    moveRight = false;
    
    type = ENTITY_TYPE_GENERIC;
    
    dead = false;
    flags = ENTITY_FLAG_GRAVITY;
    
    speedX = speedY = 0;
    speed.x = speedX;
    speed.y = speedY;
    
    accelX = accelY = 0;
    acceleration.x = accelX;
    acceleration.y = accelY;
    
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
    //texture = Texture::loadTexture(file);
    
    sprite.loadSprite(file);
    
    return true;
}

void Entity::onLoop() {
    //we're not moving
    if (moveLeft == false && moveRight == false) {
        stopMove();
    }
    
    if (moveLeft) {
        acceleration.x = -0.5;
    } else if (moveRight) {
        acceleration.x = 0.5;
    }
    
    if (flags & ENTITY_FLAG_GRAVITY) {
        acceleration.y = 0.75f;
    }
    
    speed.x += acceleration.x * FrameRate::FPSControl.getSpeedFactor();
    speed.y += acceleration.y * FrameRate::FPSControl.getSpeedFactor();
    
    if (speed.x > maxSpeedX) {
        speed.x = maxSpeedX;
    }
    
    if (speed.x < -maxSpeedX) {
        speed.x = -maxSpeedX;
    }
    
    if (speed.y > maxSpeedY) {
        speed.y = maxSpeedY;
    }
    
    if (speed.y < -maxSpeedY) {
        speed.y = -maxSpeedY;
    }
    
    onAnimate();
    onMove(speed);
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
            posValid((int) (position.x + newX), (int) (position.y + newY)); //don't care about collisions, but we need to send events to other entities
            
            position.x += newX;
            position.y += newY;
        } else {
            if (posValid((int) (position.x + newX), (int) position.y)) {
                position.x += newX;
            } else {
                speed.x = 0;
            }
            
            if (posValid((int) position.x, (int) (position.y + newY))) {
                position.y += newY;
            } else {
                if (moveY > 0) {
                    canJump = true;
                }
                
                speed.y = 0;
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

void Entity::onMove(Vector2f newPosition) {
    onMove(newPosition.x, newPosition.y);
}

bool Entity::jump() {
    if (canJump == false) {
        return false;
    }
    
    speed.y = -maxSpeedY;
    
    return true;
}

void Entity::stopMove() {
    if (speed.x > 0) {
        acceleration.x = -1;
    }
    
    if (speed.x < 0) {
        acceleration.x = 1;
    }
    
    if (speed.x < 2.0f && speed.x > -2.0f) {
        acceleration.x = 0;
        speed.x = 0;
    }
}

bool Entity::collides(int otherX, int otherY, int otherW, int otherH) {
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    int tx = (int) this->position.x + collisionX;
    int ty = (int) this->position.y + collisionY;
    
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

bool Entity::collides(Vector2i otherPosition, Vector2i otherSize) {
    if (collides(otherPosition.x, otherPosition.y, otherSize.x, otherSize.y) == true) {
        return true;
    }
    
    return false;
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

bool Entity::posValid(Vector2i position) {
    if (posValid(position.x, position.y) == true) {
        return true;
    }
    
    return false;
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

bool Entity::posValidEntity(Entity *entity, Vector2i position) {
    if (posValidEntity(entity, position.x, position.y) == true) {
        return true;
    }
    
    return false;
}

void Entity::onRender(SDL_Surface *destinationSurface) {
    //if (entitySurface == NULL || destinationSurface == NULL) {
        //return;
    //}
    
    //Surface::onDraw(destinationSurface, entitySurface, x - Camera::cameraControl.getX(), y - Camera::cameraControl.getY(), currentFrameColumn * width, ( currentFrameRow + animationControl.getCurrentFrame()) * height, width, height);
    
    //Texture::onDraw(texture, x - Camera::cameraControl.getX(), y - Camera::cameraControl.getY(), 128, 512, currentFrameColumn * width, currentFrameRow + animationControl.getCurrentFrame() * height, width, height);
    sprite.render(Sprite::AUTO, currentFrameColumn, position.x - Camera::cameraControl.getX(), position.y - Camera::cameraControl.getY());
    
    //sprite.render(Sprite::AUTO, currentFrameColumn, position.x, position.y - Camera::cameraControl.getY());
    
    Shape::shape.drawLine((position.x) - 32, (position.y - Camera::cameraControl.getY()) - 32, (position.x - Camera::cameraControl.getX()) + 32, (position.y - Camera::cameraControl.getY()) + 32);
}

void Entity::onAnimate() {
    if (moveLeft) {
        currentFrameColumn = 0;
    } else if (moveRight) {
        currentFrameColumn = 1;
    }
    
    sprite.animateSprite();
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