//
//  RealFunctions.h
//  Engine
//
//  Created by Skyler Burwell on 8/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_RealFunctions_h
#define Engine_RealFunctions_h

#include <math.h>
#include <time.h>
#include "Debug.h"
#include "Vector.h"
#include "Entity.h"
#include "Value.h"
#include <stdarg.h>

Value lengthDirX(Value length, Value dir);
Value lengthDirY(Value length, Value dir);

Value pointDistance(Value x, Value y, Value x1, Value y1);
Value pointDistance(Vector2f pos, Value x1, Value y1);
Value pointDistance(Value x, Value y, Vector2f pos1);
Value pointDistance(Vector2f pos, Vector2f pos1);
Value pointDistance(Vector4f positions);

Value pointDirection(Value x, Value y, Value x1, Value y1);
Value pointDirection(Vector2f pos, Value x1, Value y1);
Value pointDirection(Value x, Value y, Vector2f pos1);
Value pointDirection(Vector2f pos, Vector2f pos1);
Value pointDirection(Vector4f positions);

Value distanceToObj(Entity *thisEntity, Entity *other);
Value distanceToPoint(Entity *thisEntity, Value x, Value y);
Value distanceToPoint(Entity *thisEntity, Vector2f pos);

Value choose(Value arg1, ...);

Value _abs(Value arg);
Value _round(Value arg);
Value _sqrt(Value arg);
Value _sqr(Value arg);
Value _pow(Value arg, Value power);
Value _exp(Value arg); //e to the power of arg

Value _ceil(Value arg);
Value _floor(Value arg);

Value _min(Value arg, ...);
Value _max(Value arg, ...);
Value _mean(Value arg, ...);
Value _median(Value arg, ...);

Value frac(Value arg);
Value sign(Value arg);

Value _sin(Value arg);
Value _cos(Value arg);
Value _tan(Value arg);
Value _csc(Value arg);
Value _sec(Value arg);
Value _cot(Value arg);

Value _log(Value arg);
Value _ln(Value arg);
Value _log2(Value arg);
Value _log10(Value arg);
Value _logn(Value n, Value arg);

Value degToRad(Value arg);
Value radToDeg(Value arg);

Value isReal(Value *arg);
Value isString(Value *arg);
Value isBool(Value *arg);

Value random(Value arg);
Value randomRange(Value arg, Value arg1);

Value irandom(Value arg);
Value irandomRange(Value arg, Value arg1);

void randomSetSeed(Value arg);
Value randomGetSeed(void);
void randomSetRandomSeed(void);

//engine function(s)
void setSeed(void);

#endif
