#pragma once
#include <vector>
#include <cmath>

struct Particle {
    PVector position, velocity, acceleration;
    float mass = 1.0f;
    bool fixed = false;
    Particle(float x=0, float y=0) : position(x,y), velocity(0,0), acceleration(0,0) {}
    void applyForce(const PVector& f) { 
        if(fixed) return; 
        PVector temp=f; 
        temp.div(mass); 
        acceleration.add(temp); 
    }
    void update() { 
        if(fixed) return; 
        velocity.mult(0.99f); 
        velocity.add(acceleration); 
        position.add(velocity); 
        acceleration.mult(0); 
    }
    void show(SDL_Renderer* r) { 
        SDL_SetRenderDrawColor(r, 45,197,244,255); 
        SDL_FRect rect{position.x-5, position.y-5, 10,10}; 
        SDL_RenderFillRect(r,&rect);
    }
};