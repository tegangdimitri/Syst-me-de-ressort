#pragma once
#include "objet.h"
struct Spring {
    float k, restLength;
    Particle* a;
    Particle* b;
    Spring(float k_, float rest, Particle* a_, Particle* b_) : k(k_), restLength(rest), a(a_), b(b_) {}
    void update() {
        PVector force = b->position - a->position;
        float d = force.mag();
        float x = d - restLength;
        force.normalize();
        force.mult(k*x);
        a->applyForce(force);
        force.mult(-1);
        b->applyForce(force);
    }
    void show(SDL_Renderer* r) {
        SDL_SetRenderDrawColor(r, 255,255,255,255);
        SDL_RenderLine(r, (int)a->position.x, (int)a->position.y, (int)b->position.x, (int)b->position.y);
    }
};