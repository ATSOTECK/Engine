//
//  Shape.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/20/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Shape.h"
#include "RealFunctions.h"

Shape Shape::shape;

//lines
void Shape::drawLine(float x1, float y1, float x2, float y2) {
    glEnable(GL_LINE_SMOOTH);
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_LINES);
        glColor3f(color.r, color.g, color.b); glVertex3f(x1, y1, 0.0f);
        glColor3f(color.r, color.g, color.b); glVertex3f(x2, y2, 0.0f);
    glEnd();
    glDisable(GL_LINE_SMOOTH);
    //glEnable(GL_TEXTURE_2D);
}

void Shape::drawLine(Vector2f pos, Vector2f pos1) {
    drawLine(pos.x, pos.y, pos1.x, pos1.y);
}

void Shape::drawLine(float x1, float y1, float x2, float y2, Color c) {
    drawLine(x1, y1, x2, y2, c, c);
}

void Shape::drawLine(Vector2f pos, Vector2f pos1, Color c) {
    drawLine(pos.x, pos.y, pos1.x, pos1.y, c, c);
}

void Shape::drawLine(float x1, float y1, float x2, float y2, Color c, Color c1) {
    glEnable(GL_LINE_SMOOTH);
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_LINES);
        glColor3f(c.r, c.g, c.b);    glVertex3f(x1, y1, 0.0f);
        glColor3f(c1.r, c1.g, c1.b); glVertex3f(x2, y2, 0.0f);
    glEnd();
    glDisable(GL_LINE_SMOOTH);
    //glEnable(GL_TEXTURE_2D);
}

void Shape::drawLine(Vector2f pos, Vector2f pos1, Color c, Color c1) {
    drawLine(pos.x, pos.y, pos1.x, pos1.y, c, c1);
}

//rectangles
void Shape::drawRectangle(Rect pos, bool outline) {
    drawRectangle(pos.x, pos.y, pos.width, pos.height, outline);
}

void Shape::drawRectangle(Rect pos, Color c, bool outile) {
    drawRectangle(pos.x, pos.y, pos.width, pos.height, c, c, c, c, outile);
}

void Shape::drawRectangle(Rect pos, Color c, Color c1, Color c2, Color c3, bool outile) {
    drawRectangle(pos.x, pos.y, pos.width, pos.height, c, c1, c2, c3, outile);
}

void Shape::drawRectangle(Rectv pos, bool outline) {
    drawRectangle(pos.pos.x, pos.pos.y, pos.width, pos.height, outline);
}

void Shape::drawRectangle(Rectv pos, Color c, bool outile) {
    drawRectangle(pos.pos.x, pos.pos.y, pos.width, pos.height, c, c, c, c, outile);
}

void Shape::drawRectangle(Rectv pos, Color c, Color c1, Color c2, Color c3, bool outile) {
    drawRectangle(pos.pos.x, pos.pos.y, pos.width, pos.height, c, c1, c2, c3, outile);
}

void Shape::drawRectangle(Vector2f pos, float width, float height, bool outline) {
    drawRectangle(pos.x, pos.y, width, height, outline);
}

void Shape::drawRectangle(Vector2f pos, float width, float height, Color c, bool outile) {
    drawRectangle(pos.x, pos.y, width, height, c, c, c, c, outile);
}

void Shape::drawRectangle(Vector2f pos, float width, float height, Color c, Color c1, Color c2, Color c3, bool outile) {
    drawRectangle(pos.x, pos.y, width, height, c, c1, c2, c3, outile);
}

void Shape::drawRectangle(float x, float y, float width, float height, bool outline) {
    if (!outline) {
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
            glColor3f(color.r, color.g, color.b); glVertex2f(x, y);
            glColor3f(color.r, color.g, color.b); glVertex2f(x, y + height);
            glColor3f(color.r, color.g, color.b); glVertex2f(x + width, y + height);
            glColor3f(color.r, color.g, color.b); glVertex2f(x + width, y);
        glEnd();
        
        return;
    }
    
    drawLine(x, y, x + width, y);
    drawLine(x, y, x, y + height);
    drawLine(x + width, y, x + width, y + height);
    drawLine(x, y + height, x + width, y + height);
}

void Shape::drawRectangle(float x, float y, float width, float height, Color c, bool outile) {
    drawRectangle(x, y, width, height, c, c, c, c, outile);
}

void Shape::drawRectangle(float x, float y, float width, float height, Color c, Color c1, Color c2, Color c3, bool outline) {
    if (!outline) {
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLES);
            glColor3f(c.r, c.g, c.b);    glVertex2f(x, y);//0
            glColor3f(c3.r, c3.g, c3.b); glVertex2f(x + width, y + height);//3
            glColor3f(c1.r, c1.g, c1.b); glVertex2f(x + width, y);//1
            
            glColor3f(c.r, c.g, c.b);    glVertex2f(x, y);//0
            glColor3f(c2.r, c2.g, c2.b); glVertex2f(x, y + height);//2
            glColor3f(c3.r, c3.g, c3.b); glVertex2f(x + width, y + height);//3
        glEnd();
        
        return;
    }
    
    drawLine(x, y, x, y + height, c, c2);//1
    drawLine(x, y + height, x + width, y + height, c2, c3);//2
    drawLine(x + width, y + height, x + width, y, c3, c1);//3
    drawLine(x + width, y, x, y, c1, c);//4
}

//polygon
void Shape::drawPolygon(Vector2f pos, int sides, float radius, Color c, Color c1, Color c2, float rot) {
    
}

void Shape::drawPolygon(float x, float y, int sides, float radius, Color c, Color c1, Color c2, float rot) {
    
}

//circles
//vector2fs
void Shape::drawCircle(Vector2f pos, float radius, bool outline) {
    drawCircle(pos.x, pos.y, radius, outline);
}

void Shape::drawCircle(Vector2f pos, float radius, Color c, bool outline) {
    drawCircle(pos.x, pos.y, radius, c, outline);
}

void Shape::drawCircle(Vector2f pos, float radius, Color c, Color c1, bool outline) {
    drawCircle(pos.x, pos.y, radius, c, c1, c1, outline);
}

void Shape::drawCircle(Vector2f pos, float radius, Color c, Color c1, Color c2, bool outline) {
    drawCircle(pos.x, pos.y, radius, c, c1, c2, outline);
}

//floats
void Shape::drawCircle(float x, float y, float radius, bool outline) {
    Vector2f pos, pos1;
    for (int i = 0; i < circleAccuracy; i++) {
        pos.x = x;
        pos.y = y;
        pos1.x = x;
        pos1.y = y;
        
        float direction = (360.0f / circleAccuracy) * i;
        
        pos.x += lengthDirX(radius, direction).real();
        pos.y += lengthDirY(radius, direction).real();
        
        direction = (360.0f / circleAccuracy) * (i + 1);
        
        pos1.x += lengthDirX(radius, direction).real();
        pos1.y += lengthDirY(radius, direction).real();
        if (!outline) {
            drawTriangle(newVector2f(x, y), pos, pos1, 0.0f, outline);
        } else {
            drawLine(pos, pos1);
        }
    }
}

void Shape::drawCircle(float x, float y, float radius, Color c, bool outline) {
    drawCircle(x, y, radius, c, c, c, outline);
}

void Shape::drawCircle(float x, float y, float radius, Color c, Color c1, bool outline) {
    drawCircle(x, y, radius, c, c1, c1, outline);
}

void Shape::drawCircle(float x, float y, float radius, Color c, Color c1, Color c2, bool outline) {
    Vector2f pos, pos1;
    for (int i = 0; i < circleAccuracy; i++) {
        pos.x = x;
        pos.y = y;
        pos1.x = x;
        pos1.y = y;
        
        float direction = (360.0f / circleAccuracy) * i;
        
        pos.x += lengthDirX(radius, direction).real();
        pos.y += lengthDirY(radius, direction).real();
        
        direction = (360.0f / circleAccuracy) * (i + 1);
        
        pos1.x += lengthDirX(radius, direction).real();
        pos1.y += lengthDirY(radius, direction).real();
        if (!outline) {
            drawTriangle(newVector2f(x, y), pos, pos1, c, c1, c2, 0.0f, outline);
        } else {
            drawLine(pos, pos1, c, c1);
        }
    }
}

//vector2fs acc
void Shape::drawCircle(Vector2f pos, float radius, int accuracy, bool outline) {
    drawCircle(pos.x, pos.y, radius, accuracy, outline);
}

void Shape::drawCircle(Vector2f pos, float radius, int accuracy, Color c, bool outline) {
    drawCircle(pos.x, pos.y, radius, accuracy, c, outline);
}

void Shape::drawCircle(Vector2f pos, float radius, int accuracy, Color c, Color c1, bool outline) {
    drawCircle(pos.x, pos.y, radius, accuracy, c, c1, c1, outline);
}

void Shape::drawCircle(Vector2f pos, float radius, int accuracy, Color c, Color c1, Color c2, bool outline) {
    drawCircle(pos.x, pos.y, radius, accuracy, c, c1, c2, outline);
}

//floats acc
void Shape::drawCircle(float x, float y, float radius, int accuracy, bool outline) {
    Vector2f pos, pos1;
    for (int i = 0; i < accuracy; i++) {
        pos.x = x;
        pos.y = y;
        pos1.x = x;
        pos1.y = y;
        
        float direction = (360.0f / accuracy) * i;
        
        pos.x += lengthDirX(radius, direction).real();
        pos.y += lengthDirY(radius, direction).real();
        
        direction = (360.0f / accuracy) * (i + 1);
        
        pos1.x += lengthDirX(radius, direction).real();
        pos1.y += lengthDirY(radius, direction).real();
        if (!outline) {
            drawTriangle(newVector2f(x, y), pos, pos1, 0.0f, outline);
        } else {
            drawLine(pos, pos1);
        }
    }
}

void Shape::drawCircle(float x, float y, float radius, int accuracy, Color c, bool outline) {
    drawCircle(x, y, radius, accuracy, c, c, c, outline);
}

void Shape::drawCircle(float x, float y, float radius, int accuracy, Color c, Color c1, bool outline) {
    drawCircle(x, y, radius, accuracy, c, c1, c1, outline);
}

void Shape::drawCircle(float x, float y, float radius, int accuracy, Color c, Color c1, Color c2, bool outline) {
    Vector2f pos, pos1;
    for (int i = 0; i < accuracy; i++) {
        pos.x = x;
        pos.y = y;
        pos1.x = x;
        pos1.y = y;
        
        float direction = (360.0f / accuracy) * i;
        
        pos.x += lengthDirX(radius, direction).real();
        pos.y += lengthDirY(radius, direction).real();
        
        direction = (360.0f / accuracy) * (i + 1);
        
        pos1.x += lengthDirX(radius, direction).real();
        pos1.y += lengthDirY(radius, direction).real();
        if (!outline) {
            drawTriangle(newVector2f(x, y), pos, pos1, c, c1, c2, 0.0f, outline);
        } else {
            drawLine(pos, pos1, c, c1);
        }
    }
}

//triangles
void Shape::drawTriangle(Vector2f v, Vector2f v1, Vector2f v2, Color c, Color c1, Color c2, float rot, bool outline) {
    if (!outline) {
        glEnable(GL_POLYGON_SMOOTH);
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLES);
            glColor3f(c.r, c.g, c.b);    glVertex3f(v.x, v.y, 0.0f);
            glColor3f(c1.r, c1.g, c1.b); glVertex3f(v1.x, v1.y, 0.0f);
            glColor3f(c2.r, c2.g, c2.b); glVertex3f(v2.x, v2.y, 0.0f);
        glEnd();
        glDisable(GL_POLYGON_SMOOTH);
        
        return;
    }
    
    drawLine(v, v1, c, c1);
    drawLine(v1, v2, c1, c2);
    drawLine(v2, v, c2, c);
}

void Shape::drawTriangle(Vector2f v, Vector2f v1, Vector2f v2, Color c, Color c1, float rot, bool outline) {
    drawTriangle(v, v1, v2, c, c1, c1, rot, outline);
}

void Shape::drawTriangle(Vector2f v, Vector2f v1, Vector2f v2, Color c, float rot, bool outline) {
    drawTriangle(v, v1, v2, c, c, c, rot, outline);
}

void Shape::drawTriangle(Vector2f v, Vector2f v1, Vector2f v2, float rot, bool outline) {
    if (!outline) {
        glEnable(GL_POLYGON_SMOOTH);
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLES);
            glColor3f(color.r, color.g, color.b); glVertex3f(v.x, v.y, 0.0f);
            glColor3f(color.r, color.g, color.b); glVertex3f(v1.x, v1.y, 0.0f);
            glColor3f(color.r, color.g, color.b); glVertex3f(v2.x, v2.y, 0.0f);
        glEnd();
        glDisable(GL_POLYGON_SMOOTH);
        
        return;
    }
    
    drawLine(v, v1);
    drawLine(v1, v2);
    drawLine(v2, v);
}




