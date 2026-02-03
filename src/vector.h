#pragma once
#include <cmath>
struct PVector {
    float x, y;
    PVector(float x_=0, float y_=0) : x(x_), y(y_) {}
    void add(const PVector& v) {
         x+=v.x; 
         y+=v.y; 
        }
    void sub(const PVector& v) { 
        x-=v.x; 
        y-=v.y; 
    }
    void mult(float n) {
         x*=n; 
         y*=n; 
        }
    void div(float n) { 
        x/=n; 
        y/=n; 
    }
    float mag() const { 
        return std::sqrt(x*x + y*y); 
    }
    void normalize() { 
        float m=mag(); 
        if(m>0) div(m); 
    }
    void set(float nx, float ny) { 
        x=nx; y=ny; 
    }
    PVector operator-(const PVector& v) const { return {x-v.x, y-v.y}; }
    PVector operator*(float n) const { return {x*n, y*n}; }
};