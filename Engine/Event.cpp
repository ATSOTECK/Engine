#include "Event.h"

Event::Event() {

}

Event::~Event() {

}

void Event::onEvent(SDL_Event *Event) {
	switch (Event->type) {
		case SDL_ACTIVEEVENT: {
			switch (Event->active.state) {
				case SDL_APPMOUSEFOCUS: {
					if (Event->active.gain) {
						onMouseFocus();
					} else {
						onMouseBlur();
					}
					break;
				}
				case SDL_APPINPUTFOCUS: {
					if (Event->active.gain) {
						onInputFocus();
					} else {
						onInputBlur();
					}
					break;
				}
				case SDL_APPACTIVE: {
					if (Event->active.gain) {
						onRestore();
					} else {
						onMinimize();
					}
					break;
				}
			}
			break;
		}

		case SDL_KEYDOWN: {
			onKeyDown(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
            break;
		}

		case SDL_KEYUP: {
			onKeyUp(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
			break;
		}

		case SDL_MOUSEMOTION: {
			onMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, 
				(Event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, 
				(Event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT))!= 0, 
				(Event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
            break;
		}

		case SDL_MOUSEBUTTONDOWN: {
			switch (Event->button.button) {
				case SDL_BUTTON_LEFT: {
					onLButtonDown(Event->button.x, Event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					onRButtonDown(Event->button.x, Event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					onMButtonDown(Event->button.x, Event->button.y);
					break;
				}
				break;
			}
			break;
		}

		case SDL_MOUSEBUTTONUP: {
			switch (Event->button.button) {
				case SDL_BUTTON_LEFT: {
					onLButtonUp(Event->button.x, Event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					onRButtonUp(Event->button.x, Event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					onMButtonUp(Event->button.x, Event->button.y);
					break;
				}
				break;
			}
			break;
		}

		case SDL_JOYAXISMOTION: {
			onJoyAxis(Event->jaxis.which, Event->jaxis.axis, Event->jaxis.value);
			break;
		}

		case SDL_JOYBALLMOTION: {
			onJoyBall(Event->jball.which, Event->jball.ball, Event->jball.xrel, Event->jball.yrel);
            break;
		}

		case SDL_JOYHATMOTION: {
			onJoyHat(Event->jhat.which, Event->jhat.hat, Event->jhat.value);
			break;
		}

		case SDL_JOYBUTTONDOWN: {
			onJoyButtonDown(Event->jbutton.which, Event->jbutton.button);
			break;
		}

		case SDL_JOYBUTTONUP: {
			onJoyButtonUp(Event->jbutton.which, Event->jbutton.button);
			break;
		}

		case SDL_QUIT: {
			onExit();
			break;
		}

		case SDL_SYSWMEVENT: {
			//.gitnore
			break;
		}

		case SDL_VIDEORESIZE: {
			onResize(Event->resize.w, Event->resize.h);
			break;
		}

		case SDL_VIDEOEXPOSE: {
			onExpose();
			break;
		}

		default: {
			onUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
			break;
		}
	}
}

void Event::onInputFocus() {

}

void Event::onInputBlur() {

}
 
void Event::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {

}
 
void Event::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {

}
 
void Event::onMouseFocus() {

}
 
void Event::onMouseBlur() {

}
 
void Event::onMouseMove(int mX, int mY, int relX, int relY, bool left, bool right, bool middle) {

}
 
void Event::onMouseWheel(bool up, bool down) {    //Not implemented

}
 
void Event::onLButtonDown(int mX, int mY) {

}
 
void Event::onLButtonUp(int mX, int mY) {

}
 
void Event::onRButtonDown(int mX, int mY) {

}
 
void Event::onRButtonUp(int mX, int mY) {

}
 
void Event::onMButtonDown(int mX, int mY) {

}
 
void Event::onMButtonUp(int mX, int mY) {

}
 
void Event::onJoyAxis(Uint8 which, Uint8 axis, Sint16 value) {

}
 
void Event::onJoyButtonDown(Uint8 which, Uint8 button) {

}
 
void Event::onJoyButtonUp(Uint8 which, Uint8 button) {

}
 
void Event::onJoyHat(Uint8 which, Uint8 hat, Uint8 value) {

}
 
void Event::onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel) {

}
 
void Event::onMinimize() {

}
 
void Event::onRestore() {

}
 
void Event::onResize(int w, int h) {

}
 
void Event::onExpose() {

}
 
void Event::onExit() {

}
 
void Event::onUser(Uint8 type, int code, void* data1, void* data2) {

}