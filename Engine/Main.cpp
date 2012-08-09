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

Debug::Debug() {
    //fileName = "debug.log";
}

void Debug::info(const Debug::Source source, const char *message, ...) {
    //debugFile = fopen(fileName.c_str(), "a+");
    
    char buffer[1024];
    std::string _source;
    
    switch (source) {
        case ENGINE:
            _source = "ENGINE";
            break;
        case SCRIPT:
            _source = "VM";
            break;
        default:
            break;
    }
    
    va_list args;
    va_start(args, message);
    vsprintf(buffer, message, args);
    fprintf(stderr, "[INFO] %s, %s\n", _source.c_str(), buffer);
    va_end(args);
    //fclose(debugFile);
}

void Debug::warning(const Debug::Source source, const char *message, ...) {
    char buffer[1024];
    std::string _source;
    
    switch (source) {
        case ENGINE:
            _source = "ENGINE";
            break;
        case SCRIPT:
            _source = "VM";
            break;
        default:
            break;
    }
    
    va_list args;
    va_start(args, message);
    vsprintf(buffer, message, args);
    fprintf(stderr, "[WARNING] %s, %s", _source.c_str(), buffer);
    va_end(args);
}

void Debug::error(const Debug::Source source, const Debug::Level level, const char *message, ...) {
    char buffer[1024];
    std::string _source, _level;
    
    switch (source) {
        case ENGINE:
            _source = "ENGINE";
            break;
        case SCRIPT:
            _source = "VM";
            break;
        default:
            break;
    }
    
    switch (level) {
        case MILD:
            _level = "MILD";
            break;
        case CRITICAL:
            _level = "CRITICAL";
            break;
        case FATAL:
            _level = "FATAL";
            break;
        default:
            break;
    }
    
    va_list args;
    va_start(args, message);
    vsprintf(buffer, message, args);
    fprintf(stderr, "[ERROR] %s, %s, %s", _source.c_str(), _level.c_str(), message);
    va_end(args);
}

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
