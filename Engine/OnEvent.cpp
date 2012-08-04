#include "Main.h"

void Engine::onEvent(SDL_Event *Event) {
	Event::onEvent(Event);
}

void Engine::onExit() {
	running = false;
}

void Engine::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch (sym) {
		case SDLK_ESCAPE:
			running = false;
			break;
            /*
        case SDLK_UP:
            if (Camera::cameraControl.getY() < 0) {
                Camera::cameraControl.onMove(0, 5);
            }
            break;
        case SDLK_DOWN:
            Camera::cameraControl.onMove(0, -5);
            break;
        case SDLK_LEFT:
            if (Camera::cameraControl.getX() < 0) {
                Camera::cameraControl.onMove(5, 0);
            }
            break;
        case SDLK_RIGHT:
            Camera::cameraControl.onMove(-5, 0);
            break;
             */
        case SDLK_LEFT:
            player.moveLeft = true;
            break;
        case SDLK_RIGHT:
            player.moveRight = true;
            break;
        case SDLK_UP:
            player.jump();
            break;
            
        case SDLK_a:
            player2.moveLeft = true;
            break;
        case SDLK_d:
            player2.moveRight = true;
            break;
        case SDLK_w:
            player2.jump();
            break;
		default:
			break;
	}
}

void Engine::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch (sym) {
        case SDLK_LEFT:
            player.moveLeft = false;
            break;
        case SDLK_RIGHT:
            player.moveRight = false;
            break;
            
        case SDLK_a:
            player2.moveLeft = false;
            break;
        case SDLK_d:
            player2.moveRight = false;
            break;
        default:
            break;
    }
}