//
//  Vector.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Vector.h"

Vector2i::Vector2i(int X, int Y) {x = X; y = Y;}
Vector2i::Vector2i() {Vector2i(0, 0);}

Vector2i newVector2i(int x, int y) {
    Vector2i temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

Vector2f::Vector2f(float X, float Y) {x = X; y = Y;}
Vector2f::Vector2f() {Vector2f(0.0f, 0.0f);}

Vector2f newVector2f(float x, float y) {
    Vector2f temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

Vector2d::Vector2d(double X, double Y) {x = X; y = Y;}
Vector2d::Vector2d() {Vector2i(0.0, 0.0);}

Vector2d newVector2d(double x, double y) {
    Vector2d temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

Vector3i::Vector3i(int X, int Y, int Z) {x = X; y = Y; z = Z;}
Vector3i::Vector3i() {Vector3i(0, 0, 0);}

Vector3i newVector3i(int x, int y, int z) {
    Vector3i temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

Vector3f::Vector3f(float X, float Y, float Z) {x = X; y = Y; z = Z;}
Vector3f::Vector3f() {Vector3f(0.0f, 0.0f, 0.0f);}

Vector3f newVector3f(float x, float y, float z) {
    Vector3f temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

Vector3d::Vector3d(double X, double Y, double Z) {x = X; y = Y; z = Z;}
Vector3d::Vector3d() {Vector3d(0.0, 0.0, 0.0);}

Vector3d newVector3d(double x, double y, double z) {
    Vector3d temp;
    temp.x = x;
    temp.y = y;
    return temp;
}