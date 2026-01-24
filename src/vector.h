# pragma once
# include <cmath>
 class PVector {
public:
    float x;
    float y;
    PVector(float x_ , float y_) {
        x = x_;
        y = y_;
    }
    void add(PVector v) {
        y = y + v.y;
        x = x + v.x;
    }
// soustraction    
    void sub(PVector v) {
        x = x- v.x;
        y = y- v.y;
    }
// multiplicaion par un scalaire
    void mult(float n) {
        x = x * n;
        y = y * n;
    }
// division par un scalaire
void div(float n) {
        x = x / n;
        y = y / n;
    }
// module
    float mag() {
        return sqrt(x*x + y*y);
    }
// vecteur unitaire
        void normalize() {
        float m = mag();
        if (m != 0) {
            div(m);
            }
    }
};

