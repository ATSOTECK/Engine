#include "Main.h"
#include <stdio.h>

void Engine::onCleanup() {
    fprintf(stderr, "Exiting...");
    
	SDL_FreeSurface(display);
	SDL_FreeSurface(testSurface);
    SDL_FreeSurface(tileSurface);
    //SDL_FreeSurface(yoshiSurface);
    
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