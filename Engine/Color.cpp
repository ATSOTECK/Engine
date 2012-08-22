//
//  Color.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Color.h"

Color::Color() {
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(float r, float g, float b) {
    this->r = r / 255;
    this->g = g / 255;
    this->b = b / 255;
}

Color::Color(int r, int g, int b) {
    this->r = r / 255;
    this->g = g / 255;
    this->b = b / 255;
}

Color newColor(float r, float g, float b) {
    Color temp;
    temp.r = r;
    temp.g = g;
    temp.b = b;
    return temp;
}