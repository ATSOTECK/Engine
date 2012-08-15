//
//  FontManager.h
//  Engine
//
//  Created by Skyler Burwell on 8/13/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_FontManager_h
#define Engine_FontManager_h

#include <map>
#include <string>
#include <FTGL/ftgl.h>
#include "Debug.h"

using namespace std;

class FontManager {
public:
    typedef map<string, FTFont*> fontList;
    typedef fontList::const_iterator fontIter;
    
    static FontManager& Instance();
    
    ~FontManager();
    
    FTFont *getFont(const char *fileName, int size);
    
private:
    FontManager(){}
    FontManager(const FontManager&){}
    FontManager& operator = (const FontManager&){return *this;}
    
    fontList fonts;
};

#endif
