//
//  Color.h
//  Engine
//
//  Created by Skyler Burwell on 8/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Color_h
#define Engine_Color_h

struct Color {
    float r, b, g, a;
    Color(float r, float g, float b);
    Color(int r, int g, int b);
    Color();
};

Color newColor(float r, float g, float b);

#ifndef _COLORS
#define _COLORS

#define RED         newColor(255, 0, 0)
#define GREEN       newColor(0, 255, 0)
#define BLUE        newColor(0, 0, 255)
#define WHITE       newColor(255, 255, 255)
#define LIGHT_GREY  newColor(222, 222, 222)
#define GREY        newColor(122, 122, 122)
#define DARK_GREY   newColor(84, 84, 84)
#define BLACK       newColor(0, 0, 0)
#define ORANGE      newColor(255, 140, 0)
#define YELLOW      newColor(255, 255, 0)
#define PINK        newColor(255, 20, 147)
#define AQUA        newColor(0, 206, 209)
#define SKY_BLUE    newColor(244, 116, 205)
#define NAVY_BLUE   newColor(0, 0, 128)
#define BROWN       newColor(139, 69, 19)
#define TAN         newColor(244, 164, 96)
#define PURPLE      newColor(153, 50, 204)

#endif //_COLORS
#endif
