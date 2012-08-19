//
//  ShaderUtils.h
//  Engine
//
//  Created by Skyler Burwell on 8/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_ShaderUtils_h
#define Engine_ShaderUtils_h

#include <SDL.h>
#include "SDL_opengl.h"
#include "Debug.h"

char* fileRead(const char* filename);

void printLog(GLuint object);
	
GLuint createShader(const char* filename, GLenum type);

#endif
