//
//  Shape.h
//  Engine
//
//  Created by Skyler Burwell on 8/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Shape_h
#define Engine_Shape_h

#include "Vector.h"
#include "Rect.h"
#include "Color.h"
#include "Value.h"
#include <SDL.h>
#include "SDL_opengl.h"

class Shape {
    int circleAccuracy;
    Color color;
public:
    static Shape shape;
    
    void drawLine(float x1, float y1, float x2, float y2);
    void drawLine(Vector2f pos, Vector2f pos1);
    void drawLine(float x1, float y1, float x2, float y2, Color c);
    void drawLine(Vector2f pos, Vector2f pos1, Color c);
    void drawLine(float x1, float y1, float x2, float y2, Color c, Color c1);
    void drawLine(Vector2f pos, Vector2f pos1, Color c, Color c1);
    
    void drawRectangle(Rect pos, bool outline);
    void drawRectangle(Rect pos, Color c, bool outile);
    void drawRectangle(Rect pos, Color c, Color c1, Color c2, Color c3, bool outile);
    
    void drawRectangle(Rectv pos, bool outline);
    void drawRectangle(Rectv pos, Color c, bool outile);
    void drawRectangle(Rectv pos, Color c, Color c1, Color c2, Color c3, bool outile);
    
    void drawRectangle(Vector2f pos, float width, float height, bool outline);
    void drawRectangle(Vector2f pos, float width, float height, Color c, bool outile);
    void drawRectangle(Vector2f pos, float width, float height, Color c, Color c1, Color c2, Color c3, bool outile);
    
    void drawRectangle(float x, float y, float width, float height, bool outline);
    void drawRectangle(float x, float y, float width, float height, Color c, bool outile);
    void drawRectangle(float x, float y, float width, float height, Color c, Color c1, Color c2, Color c3, bool outile);
    
    void drawPolygon(Vector2f pos, int sides, float radius, Color c, Color c1, Color c2, float rot);
    void drawPolygon(float x, float y, int sides, float radius, Color c, Color c1, Color c2, float rot);
    
    void drawCircle(Vector2f pos, float radius, bool outline);
    void drawCircle(Vector2f pos, float radius, Color c, bool outline);
    void drawCircle(Vector2f pos, float radius, Color c, Color c1, bool outline);
    void drawCircle(Vector2f pos, float radius, Color c, Color c1, Color c2, bool outline);
    
    void drawCircle(float x, float y, float radius, bool outline);
    void drawCircle(float x, float y, float radius, Color c, bool outline);
    void drawCircle(float x, float y, float radius, Color c, Color c1, bool outline);
    void drawCircle(float x, float y, float radius, Color c, Color c1, Color c2, bool outline);
    
    void drawCircle(Vector2f pos, float radius, int accuracy, bool outline);
    void drawCircle(Vector2f pos, float radius, int accuracy, Color c, bool outline);
    void drawCircle(Vector2f pos, float radius, int accuracy, Color c, Color c1, bool outline);
    void drawCircle(Vector2f pos, float radius, int accuracy, Color c, Color c1, Color c2, bool outline);
    
    void drawCircle(float x, float y, float radius, int accuracy, bool outline);
    void drawCircle(float x, float y, float radius, int accuracy, Color c, bool outline);
    void drawCircle(float x, float y, float radius, int accuracy, Color c, Color c1, bool outline);
    void drawCircle(float x, float y, float radius, int accuracy, Color c, Color c1, Color c2, bool outline);
    
    void drawTriangle(Vector2f v, Vector2f v1, Vector2f v2, Color c, Color c1, Color c2, float rot, bool outline);
    void drawTriangle(Vector2f v, Vector2f v1, Vector2f v2, Color c, Color c1, float rot, bool outline);
    void drawTriangle(Vector2f v, Vector2f v1, Vector2f v2, Color c, float rot, bool outline);
    void drawTriangle(Vector2f v, Vector2f v1, Vector2f v2, float rot, bool outline);
    
    Shape() {
        circleAccuracy = 60;
        color = BLUE;
    }
    
    void drawSetCircleAccuracy(int accuracy);
    Value drawGetCircleAccuracy();
    
    void drawSetColor(Color color);
    void drawSetColor(float r, float g, float b);
    Color drawGetColor();
    
    void drawSetAlpha(float alpha);
    Value drawGetAlpha();
};

#endif
