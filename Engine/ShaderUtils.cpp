//
//  ShaderUtils.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "ShaderUtils.h"

#include <stdio.h>
#include <stdlib.h>
/*
char *fileRead(const char *filename) {
    FILE *in = fopen(filename, "rb");
    
    if (in == NULL) {
        return NULL;
    }
    
    int resSize = BUFSIZ;
    char *res = (char *)malloc(resSize);
    int nbReadTotal = 0;
    
    while (!feof(in) && !ferror(in)) {
        if (nbReadTotal + BUFSIZ > resSize) {
            if (resSize > (1024 * 1024)) {
                break;
            }
            
            resSize *= 2;
            res = (char *)realloc(res, resSize);
        }
        
        char *pRes = res + nbReadTotal;
        nbReadTotal += fread(pRes, 1, BUFSIZ, in);
    }
    
    fclose(in);
    res = (char *)realloc(res, nbReadTotal + 1);
    res[nbReadTotal] = '\0';
    return res;
}

void printLog(GLuint object) {
    GLuint logLength = 0;
    
    if (glIsShader(object)) {
        glGetShaderiv(object, GL_INFO_LOG_LENGTH, &logLength);
    } else if (glIsProgram(object)) {
        glGetProgramiv(object, GL_INFO_LOG_LENGTH, &logLength);
    } else {
        Debug::error(Debug::ENGINE, Debug::MILD, "Not a shder or a program!");
        return;
    }
    
    char *log = (char *)malloc(logLength);
    
    if (glIsShader(object)) {
        glGetShaderInfoLog(object, logLength, NULL, log);
    } else if (glIsProgram(object)) {
        glGetProgramInfoLog(object, logLength, NULL, log);
    }
    
    Debug::info(Debug::ENGINE, "%s", log);
    free(log);
}

GLuint createShader(const char *filename, GLenum type) {
    const GLchar *source = fileRead(filename);
    
    if (source == NULL) {
        Debug::error(Debug::ENGINE, Debug::MILD, "Error opening %s!", filename);
        perror("");
        return 0;
    }
    
    GLuint res = glCreateShader(type);
    const GLchar sources[] = {
#ifdef GL_ES
    }
}
*/








