//
//  FontManager.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/13/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "FontManager.h"

//FTTextureFont* myFont = FontManager::Instance().getFont("arial.ttf", 72);

typedef map<string, FTFont*> fontList;
typedef fontList::const_iterator fontIter;

FontManager& FontManager::Instance() {
    static FontManager fm;
    return fm;
}

FontManager::~FontManager() {
    fontIter font;
    for (font = fonts.begin(); font != fonts.end(); font++) {
        delete (*font).second;
    }
    
    fonts.clear();
}

FTFont *FontManager::getFont(const char *fileName, int size) {
    /*
    char buffer[256];
    sprintf(buffer, "%s%i", fileName, size);
    string fontKey = string(buffer);
    
    fontIter result = fonts.find(fontKey);
    if (result != fonts.end()) {
        Debug::info(Debug::ENGINE, "Found font %s in list!", fileName);
        return result->second;
    }
    
    //FTFont *font = new FTTextureFont(fileName);
    
    
    string fullName = path + string(fileName);
    
    if (!font->Attach(fullName.c_str())) {
        Debug::error(Debug::ENGINE, Debug::CRITICAL, "Font %s failed to open!", fullName.c_str());
        delete font;
        return NULL;
    }
    
    if (!font->FaceSize(size)) {
        Debug::error(Debug::ENGINE, Debug::MILD, "Font %s failed to set face size!", fileName);
        delete font;
        return NULL;
    }
    
    fonts[fontKey] = font;
    
    return font;
     */
}