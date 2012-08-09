//
//  Main.h
//  Engine
//
//  Created by Skyler Burwell on 7/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Main_h
#define Engine_Main_h

#include "SDL.h"
#include "SDL_opengl.h"
#include "Surface.h"
#include "Event.h"
//#include "Animation.h"
#include "Entity.h"
#include "Define.h"
#include "Area.h"
#include "Camera.h"
#include "Player.h"
#include "FrameRate.h"
#include "Texture.h"
#include "Debug.h"

class Engine : public Event{
private:
    bool running;
    int version;
    SDL_Surface *display;
    SDL_Surface *testSurface;
    SDL_Surface *tileSurface;
    SDL_Surface *yoshiSurface;
    //Animation yoshi;
    
    Entity entity1;
    Entity entity2;
    
    Player player;
    Player player2;
    
public: 
    Engine();
    
    int onExecute();
    
    //events
    void onEvent(SDL_Event *Event);
    void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
    void onExit();
    
    bool onInit();
    void onLoop();
    void onRender();
    void onCleanup();
};

#endif
