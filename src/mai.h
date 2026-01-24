# pragma once
#include "vector.h"
PVector bob(550,150) ;
PVector anchor(300,150),velocity(0,0),gravity(0,0.1);

class Spring{
public :   
    float x_anchor ;
    float y_anchor ;
    float len ;
    float k =0.1f;
    Spring(float x,float y, float l){
    PVector anchor(x = x_anchor,y=y_anchor);
        len =l;
    }

};
