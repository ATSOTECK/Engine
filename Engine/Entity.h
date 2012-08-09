//
//  Entity.h
//  Engine
//
//  Created by Skyler Burwell on 7/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Entity_h
#define Engine_Entity_h

#include <vector>
#include "SDL_opengl.h"
#include <string.h>
#include "Animation.h"
#include "Surface.h"
#include "Area.h"
#include "Camera.h"
#include "FrameRate.h"
#include "Texture.h"
#include "Sprite.h"

enum entityType {
    ENTITY_TYPE_GENERIC = 0,
    ENTITY_TYPE_PLAYER
};

enum {
    ENTITY_FLAG_NONE = 0,
    ENTITY_FLAG_GRAVITY = 0x00000001, //determines whether or not the entity is affected by gravity
    ENTITY_FLAG_GHOST = 0x00000002, //collides with neither map nor entities
    ENTITY_FLAG_MAPONLY = 0x00000003 //collides with map but not other entites
};

class Entity {
public:
    static std::vector<Entity*> entityList;
    
protected:
    Animation animationControl;
    Sprite sprite;
    SDL_Surface *entitySurface;
    GLuint texture;
    
    float speedX;
    float speedY;
    
    float accelX;
    float accelY;
    
    int currentFrameColumn;
    int currentFrameRow;
    
    int collisionX;
    int collisionY;
    int collisionWidth;
    int collisionHeight;
    
    bool canJump;
    
public:
    float x;
    float y;
    
    int width;
    int height;
    
    int animState;

    bool moveLeft;
    bool moveRight;
    
    int type;
    
    bool dead;
    
    int flags;
    
    float maxSpeedX;
    float maxSpeedY;
    
    Entity();
    virtual ~Entity();
    
    virtual bool onLoad(std::string file, int width, int height, int maxFrames);
    virtual void onLoop();
    virtual void onRender(SDL_Surface *destinationSurface);
    virtual void onCleanup();
    virtual void onAnimate();
    virtual bool onCollision(Entity *entity);
    
    void onMove(float moveX, float moveY);
    void stopMove();
    
    bool collides(int othetX, int otherY, int otherW, int otherH);
    
    bool jump();
    
private:
    bool posValid(int newX, int newY);
    bool posValidTile(Tile *tile);
    bool posValidEntity(Entity *entity, int newX, int newY);
};

class EntityCollide {
public:
    static std::vector<EntityCollide> entityCollideList;
    
    Entity *entityA;
    Entity *entityB;
    
    EntityCollide();
};

#endif
