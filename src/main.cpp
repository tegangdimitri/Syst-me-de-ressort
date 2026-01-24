#include <SDL3/SDL.h>
#include <iostream>
#include "vector.h"
#include "mai.h"
void drawFilledCircle(SDL_Renderer* renderer,int centreX,int centreY,int radius){
   for(int w = -radius ;w<= radius; w++){
    for(int h = -radius; h <= radius ;h++){
        if(w*w + h*h <= radius*radius){

            SDL_RenderPoint(renderer,centreX + w,centreY + h);
        }
    }
   }
}

void draw(SDL_Renderer* renderer,PVector anchor ,PVector bob){
SDL_SetRenderDrawColor(renderer, 45,197,244,255);
drawFilledCircle (renderer,anchor.x,anchor.y,32);
drawFilledCircle(renderer, bob.x,bob.y,64);
// souris
//SDL_Event event;

/*if(buttons & SDL_BUTTON_LMASK){
    bob.x = mx ;
    bob.y = my ;
    velocity ={0,0};
}*/
}

//PVector bob(350,0),anchor(300,0),velocyty(0,0),gravity(0,0.1);
int main (int argc, char* argv[]){
    // initialisation de SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) { 
        std::cerr << "Erreur SDL_Init: " << SDL_GetError() << std::endl; 
        return 1; 
    } 
    std::cout << "SDL3 initialisé avec succès ! " << std::endl;

    // creation de fenetre
SDL_Window* window = SDL_CreateWindow( 
"Ma Première Fenêtre SDL3",  // Titre 
800, 600,                     // Largeur, Hauteur 
SDL_WINDOW_RESIZABLE          // Options 
 ); 

if (!window) { 
        std::cerr << "Erreur création fenêtre: " << SDL_GetError() << std::endl; 
        SDL_Quit(); 
        return 1; 
    } 

    //Création du renderer (pour dessiner) 
SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr); 
if (!renderer) { 
        std::cerr << "Erreur création renderer: " << SDL_GetError() << std::endl; 
        SDL_DestroyWindow(window); 
        SDL_Quit(); 
        return 1; 
    } 

    //Boucle principale (le cœur qui bat !) 
    bool running = true; 
    SDL_Event event; 
while (running) { 
// Gestion des événements 
while (SDL_PollEvent(&event)) { 
if (event.type == SDL_EVENT_QUIT) { 
                running = false; }
                // clic souris gauche
    if(event.type == SDL_EVENT_MOUSE_BUTTON_DOWN && event.button.button == SDL_BUTTON_LEFT){
    bob.x = event.button.x;
    bob.y = event.button.y ;
            }

            
        } 
// Dessine un fond bleu magnifique 
SDL_SetRenderDrawColor(renderer, 30, 144, 255, 255); 
        SDL_RenderClear(renderer);
//Dessin d'une ligne
SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderLine(renderer,anchor.x,anchor.y,bob.x,bob.y);  
// Point d'accroche
draw(renderer,anchor,bob);
// Affiche le tout 
        SDL_RenderPresent(renderer); 
// Petite pause (pour ne pas cramer le CPU) 
        SDL_Delay(16); // ~60 FPS 
    } 
// Nettoyage (on est bien élevés) 
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window); 
    SDL_Quit(); 
std::cout << "Au revoir ! " << std::endl; 
return 0; 
} 


