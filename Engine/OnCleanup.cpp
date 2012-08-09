#include "Main.h"
#include <stdio.h>

void Engine::onCleanup() {
    Debug::info(Debug::ENGINE, "Exiting...");
    
	SDL_FreeSurface(display);
    
    for (int i = 0; i < Entity::entityList.size(); i++) {
        if (!Entity::entityList[i]) {
            continue;
        }
        
        Entity::entityList[i]->onCleanup();
    }
    
    Entity::entityList.clear();
    
    Area::areaControl.onCleanup();
    
    
    
	SDL_Quit();
}