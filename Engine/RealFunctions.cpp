//
//  RealFunctions.cpp
//  Engine
//
//  Created by Skyler Burwell on 8/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "RealFunctions.h"

unsigned int seed = 0;

Value lengthDirX(Value length, Value dir) {
    return  cos((dir.real() * M_PI) / 180.0f) * length.real();
}

Value lengthDirY(Value length, Value dir) {
    return sin((dir.real() * M_PI) / 180.0f) * length.real();
}

Value pointDistance(Value x, Value y, Value x1, Value y1) {
    float deltax = (x.real() - x1.real());
    float deltay = (y.real() - y1.real());
    
    return sqrtf(powf(deltax, 2) + powf(deltay, 2));
}

Value pointDistance(Vector2f pos, Value x1, Value y1) {
    return pointDistance(pos.x, pos.y, x1, y1);
}

Value pointDistance(Value x, Value y, Vector2f pos1) {
    return pointDistance(x, y, pos1.x, pos1.y);
}

Value pointDistance(Vector2f pos, Vector2f pos1) {
    return pointDistance(pos.x, pos.y, pos1.x, pos1.y);
}

Value pointDistance(Vector4f pos) {
    return pointDistance(pos.x, pos.y, pos.x1, pos.y1);
}

Value _sin(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return sinf(arg.real());
    }
    
    //double
    return sin(arg.real());
}

Value _cos(Value arg) {    
    if (arg.type == Value::_FLOAT) {
        return cosf(arg.real());
    }
    
    //double
    return cos(arg.real());
}

Value _tan(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return tanf(arg.real());
    }
    
    //double
    return tan(arg.real());
}

Value _csc(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return asinf(arg.real());
    }
    
    //double
    return asin(arg.real());
}

Value _sec(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return acosf(arg.real());
    }
    
    //double
    return acos(arg.real());
}

Value _cot(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return atanf(arg.real());
    }
    
    //double
    return atan(arg.real());
}

Value _log(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return logf(arg.real());
    }
    
    //double
    return log(arg.real());
}

Value _ln(Value arg) {
    return _logn(M_E, arg.real());
}

Value _log2(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return log2f(arg.real());
    }
    
    //double
    return log2(arg.real());
}

Value _log10(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return log10f(arg.real());
    }
    
    //double
    return log10(arg.real());
}

Value _logn(Value n, Value arg) {
    if (arg.type == Value::_FLOAT) {
        return (logf(arg.real()) / logf(n.real()));
    }
    
    //double
    return (log(arg.real()) / log(n.real()));
}

Value degToRad(Value arg) {
    return (M_PI / 180) * arg.real();
}

Value radToDeg(Value arg) {
    return (180 / M_1_PI) * arg.real(); 
}

Value _abs(Value arg) {
    if (arg.type == Value::_INT) {
        return abs(arg.real());
    } else if (arg.type == Value::_FLOAT) {
        return fabsf(arg.real());
    }
    
    //double
    return fabs(arg.real());
}

Value _round(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return roundf(arg.real());
    }
    
    //double
    return round(arg.real());
}

Value _sqrt(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return sqrtf(arg.real());
    }
    
    //double
    return sqrt(arg.real());
}

Value _sqr(Value arg) {
    return arg.real() * arg.real();
}

Value _pow(Value arg, Value power) {
    if (arg.type == Value::_FLOAT) {
        return powf(arg.real(), power.real());
    }
    
    //double
    return pow(arg.real(), arg.real());
}

Value _ext(Value arg) {
    return _pow(M_E, arg);
}

Value _frac(Value arg) {
    if (arg.type == Value::_FLOAT) {
        float f = arg.real();
        return Value(f > 0 ? f + truncf(f) : f - truncf(f));
    }
    
    //double
    double d = arg.real();
    return Value(d > 0 ? d + trunc(d) : d - trunc(d));
}

Value sign(Value arg) {
    if (arg.sign == Value::_POSITIVE) {
        return 1;
    } else if (arg.sign == Value::_NEGATIVE) {
        return -1;
    }
    
    //no sign, string or bool
    return 0;
}

Value _ceil(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return ceilf(arg.real());
    }
    
    //double
    return ceil(arg.real());
}

Value _floor(Value arg) {
    if (arg.type == Value::_FLOAT) {
        return floorf(arg.real());
    }
    
    //double
    return floor(arg.real());
}

Value isReal(Value *arg) {
    if (arg->type == Value::_INT || arg->type == Value::_FLOAT || arg->type == Value::_DOUBLE) {
        return true;
    }
    
    return false;
}

Value isString(Value *arg) {
    if (arg->type == Value::_STRING) {
        return true;
    }
    
    return false;
}

Value isBool(Value *arg) {
    if (arg->type == Value::_BOOL) {
        return true;
    }
    
    return false;
}

Value random(Value arg) {
    return (float) ((rand() % 1) * arg.real());
}

Value irandom(Value arg) {
    return rand() % (int) arg.real();
}

Value randomRange(Value arg, Value arg1) {
    float r = (float) ((rand() % 1) * (arg1.real() - arg.real()));
    return r + arg.real();
}

Value irandomRange(Value arg, Value arg1) {
    int r = rand() % (int) (arg1.real() - arg.real());
    return r + (int) arg.real();
}

void randomSetSeet(Value arg) {
    seed = (int) arg.real();
    srand((int) arg.real());
}

void randomSetRandomSeed(void) {
    int r = rand() % RAND_MAX;
    seed = r;
    srand(r);
}

Value randomGetSeed() {
    return (int) seed;
}

/*Value choose(Value arg1, ...) {
va_list args;
va_start(args, arg1);
va_end(args);
}*/

//engine function(s)

void setSeed(void) {
    seed = time(NULL);
    srand(time(NULL));
}