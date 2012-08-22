//
//  Shape.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/20/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Shape.h"

Shape Shape::shape;

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
    }
    
    drawLine(v, v2, c, c1);
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
    }
}