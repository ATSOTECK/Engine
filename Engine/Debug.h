//
//  Debug.h
//  Engine
//
//  Created by Skyler Burwell on 8/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Debug_h
#define Engine_Debug_h


#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

class Debug {
public:
    enum Source {ENGINE, SCRIPT} dbSource;
    enum Level {MILD, CRITICAL, FATAL} dbLevel;
    
    static FILE *debugFile;
    static std::string fileName;
    
    static void info(const Source source, const char *message, ...);
    static void error(const Source source, const Level level, const char *message, ...);
    static void warning(const Source source, const char *message, ...);
    
    Debug();
};

#endif