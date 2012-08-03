//
//  Main.cpp
//  Engine
//
//  Created by Skyler Burwell on 7/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Main.h"

Engine::Engine() {
    display = NULL;
	testSurface = NULL;
	tileSurface = NULL;
    yoshiSurface = NULL;
    
	version = 0;
    
	running = true;
}

int Engine::onExecute() {
    if (onInit() == false) {
		return -1;
	}
    
	SDL_Event Event;
	while(running) {
		while(SDL_PollEvent(&Event)) {
			onEvent(&Event);
		}
        
		onLoop();
		onRender();
	}
    
	onCleanup();
    
	return 0;
}

int main(int argc, char *argv[]) {
    Engine engine;
    
    return engine.onExecute();
}
