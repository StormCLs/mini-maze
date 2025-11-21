#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include "init.h"

bool InitializeSDLResouces(SDL_Window **window, SDL_Renderer **renderer) {
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        return false;
    }
    *window = SDL_CreateWindow (
        "Test",
        320,
        320,
        0
    );

    if(!*window) {
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer (*window, NULL);

    if(!*renderer) {
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }
    return true;
}
void CleanupSDLResources(SDL_Window *window, SDL_Renderer *renderer) {
    if (window) {
        SDL_DestroyWindow(window);
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    SDL_Quit();
}