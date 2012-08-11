#include "Main.h"

void Engine::onRender() {
    glEnable(GL_TEXTURE_2D);
    //clear the screen
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glViewport(0, 0, VIEW_WIDTH, VIEW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, VIEW_WIDTH, VIEW_HEIGHT, 0.0f, -1.0f, 1.0f);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //SDL_FillRect(display, NULL, SDL_MapRGB(display->format, 0, 0, 0));
    
    //render the map
    Area::areaControl.onRender(display, -Camera::cameraControl.getX(), -Camera::cameraControl.getY());
    
    for (int i = 0; i < Entity::entityList.size(); i++) {
        if (!Entity::entityList[i]) {
            continue;
        }
        
        Entity::entityList[i]->onRender(display);
    }

	//SDL_Flip(display);
    //videoInfo = SDL_GetVideoInfo();
    //Debug::info(Debug::ENGINE, "Video mem %i", videoInfo->video_mem);
    SDL_GL_SwapBuffers();
}