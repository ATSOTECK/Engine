//
//  Vector.h
//  Engine
//
//  Created by Skyler Burwell on 8/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Vector_h
#define Engine_Vector_h

struct Vector2i {
    int x, y;
    //int width, height;
    Vector2i(int X, int Y);
    Vector2i();
};

struct Vector2f {
    float x, y;
    //float width, height;
    Vector2f(float X, float Y);
    Vector2f();
};

struct Vector2d {
    double x, y;
    //double width, height;
    Vector2d(double X, double Y);
    Vector2d();
};

Vector2i newVector2i(int x, int y);
Vector2f newVector2f(float x, float y);
Vector2d newVector2d(double x, double y);

struct Vector3i {
    int x, y, z;
    int width, height, length;
    Vector3i(int X, int Y, int Z);
    Vector3i();
};

struct Vector3f {
    float x, y, z;
    float width, height, length;
    Vector3f(float X, float Y, float Z);
    Vector3f();
};

struct Vector3d {
    double x, y, z;
    float width, height, length;
    Vector3d(double X, double Y, double Z);
    Vector3d();
};

Vector3i newVector3i(int x, int y, int z);
Vector3f newVector3f(float x, float y, float z);
Vector3d newVector3d(double x, double y, double z);

#endif
