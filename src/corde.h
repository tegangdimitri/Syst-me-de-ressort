#pragma once 
#include "spring.h"
struct Rope {
    std::vector<Particle> nodes;
    std::vector<Spring> springs;
    Rope(int count, float x, float y, float spacing, float k) {
        for(int i=0;i<count;i++) nodes.emplace_back(x, y+i*spacing);
        nodes[0].fixed = true;
        nodes.back().mass = 5.0f;
        for(int i=0;i<count-1;i++) springs.emplace_back(k, spacing, &nodes[i], &nodes[i+1]);
    }
    void update(const PVector& gravity) {
        for(auto& p : nodes) p.applyForce(gravity);
        for(auto& s : springs) s.update();
        for(auto& p : nodes) p.update();
    }
    void show(SDL_Renderer* r) {
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);

    for (int i = 1; i < nodes.size(); i++) {
        SDL_RenderLine(r,
            nodes[i-1].position.x, nodes[i-1].position.y,
            nodes[i].position.x,   nodes[i].position.y);
    }

    nodes.back().show(r);
}

};