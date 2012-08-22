//
//  Value.h
//  Engine
//
//  Created by Skyler Burwell on 8/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Value_h
#define Engine_Value_h

#include <iostream>
#include <string.h>
#include "Vector.h"

struct Value {
public:
    enum Type {_NONE, _INT, _FLOAT, _DOUBLE, _STRING, _BOOL};
    enum Sign {_ZERO, _POSITIVE, _NEGATIVE};
    int type, sign;
    std::string *s;
    int i;
    float f;
    double d;
    bool b;
    
    Value(std::string *val) {
        s = val;
        i = 0;
        f = 0.0f;
        d = 0.0;
        b = false;
        
        type = _STRING;
        sign = _ZERO;
    }
    
    Value(int val) {
        s = NULL;
        i = val;
        f = 0.0f;
        d = 0.0;
        b = false;
        
        type = _INT;
        
        if (val > 0) {
            sign = _POSITIVE;
        } else {
            sign = _NEGATIVE;
        }
    }
    
    Value(float val) {
        s = NULL;
        i = 0;
        f = val;
        d = 0.0;
        b = false;
        
        type = _FLOAT;
        
        if (val > 0) {
            sign = _POSITIVE;
        } else {
            sign = _NEGATIVE;
        }
    }
    
    Value(double val) {
        s = NULL;
        i = 0;
        f = 0.0f;
        d = val;
        b = false;
        
        type = _DOUBLE;
        
        if (val > 0) {
            sign = _POSITIVE;
        } else {
            sign = _NEGATIVE;
        }
    }
    
    Value(bool val) {
        s = NULL;
        i = 0;
        f = 0.0f;
        d = 0.0;
        b = val;
        
        type = _BOOL;
        sign = _ZERO;
    }
    
    double real() {
        switch (type) {
            case _INT:
                return i;
                break;
            case _FLOAT:
                return f;
                break;
            case _DOUBLE:
                return d;
                break;
            default:
                break;
        }
        
        return NULL;
    }
    
    void getType() {
        
    }
};

#endif
