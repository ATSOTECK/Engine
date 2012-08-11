#include "Main.h"

void Engine::onLoop() {
    
    for (int i = 0; i < Entity::entityList.size(); i++) {
        if (!Entity::entityList[i]) {
            continue;
        }
        
        Entity::entityList[i]->onLoop();
    }
    
    //collision events
    for (int i = 0; i < EntityCollide::entityCollideList.size(); i++) {
        Entity *entityA = EntityCollide::entityCollideList[i].entityA;
        Entity *entityB = EntityCollide::entityCollideList[i].entityB;
        
        if (entityA == NULL || entityB == NULL) {
            continue;
        }
        
        if (entityA->onCollision(entityB)) {
            entityB->onCollision(entityA);
        }
    }
    
    EntityCollide::entityCollideList.clear();
    
    FrameRate::FPSControl.onLoop();
    
    char buffer[255];
    sprintf(buffer, "FPS %d", FrameRate::FPSControl.getFPS());
    SDL_WM_SetCaption(buffer, buffer);
}