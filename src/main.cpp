#include <SDL3/SDL.h>

#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

#include <vector>
#include <cmath>
#include "vector.h"
#include "spring.h"
#include "objet.h"
#include "corde.h"


int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("Simulateur de corde et de ressorts", 800,600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* r = SDL_CreateRenderer(win,nullptr);

    // Setup ImGui
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplSDL3_InitForSDLRenderer(win, r);
    ImGui_ImplSDLRenderer3_Init(r);

    

    Rope rope(20, 200, 50, 15, 0.2f);
    PVector gravity(0,0.15f);

    bool run = true;
    bool mouseDown = false;
    float mx=0,my=0;

    SDL_Event e;

    while(run) {
        while(SDL_PollEvent(&e)) {
            ImGui_ImplSDL3_ProcessEvent(&e);
            if(e.type==SDL_EVENT_QUIT) run=false;
            if(e.type==SDL_EVENT_MOUSE_MOTION){ 
                mx=e.motion.x; 
                my=e.motion.y; 
            }
            if(e.type==SDL_EVENT_MOUSE_BUTTON_DOWN) mouseDown = true;
            if(e.type==SDL_EVENT_MOUSE_BUTTON_UP) mouseDown = false;
        }

        // Interface ImGui
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();


        static float stiffness = 0.2f;
        static float bobMass = 5.0f;
        static float grav = 0.15f;

        ImGui::Begin("Settings");
        ImGui::SliderFloat("Stiffness", &stiffness, 0.01f, 1.0f);
        ImGui::SliderFloat("Bob Mass", &bobMass, 1.0f, 20.0f);
        ImGui::SliderFloat("Gravity", &grav, 0.0f, 1.0f);
        ImGui::Text("Drag the bob with mouse");
        ImGui::End();

        // Apply GUI values
        rope.springs.clear();
        for(int i=0;i<rope.nodes.size()-1;i++)
            rope.springs.emplace_back(stiffness, 15, &rope.nodes[i], &rope.nodes[i+1]);
        rope.nodes.back().mass = bobMass;
        gravity.y = grav;
        for (auto& s : rope.springs)
            s.k = stiffness;
        rope.nodes.back().mass = bobMass;
        gravity.y = grav;

        if(mouseDown){
            rope.nodes.back().position.set(mx,my);
            rope.nodes.back().velocity.set(0,0);
        }

        rope.update(gravity);

        // Render SDL
        SDL_SetRenderDrawColor(r, 112,50,126,255);
        SDL_RenderClear(r);
        rope.show(r);

        // Render ImGui
        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), r);


        SDL_RenderPresent(r);
        SDL_Delay(16);
    }

    // Cleanup
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_Quit();
}
