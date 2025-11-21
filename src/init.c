#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include "init.h"
#include "debug.h"

const int WindowSize[2] = {
    TILE * GRID_W,
    TILE * GRID_H
};

bool InitializeSDLResouces(SDL_Window **window, SDL_Renderer **renderer) {
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        LOG_ERROR("SDL_Init error: %s", SDL_GetError());
        return false;
    }
    *window = SDL_CreateWindow (
        "Test",
        WindowSize[0],
        WindowSize[1],
        0
    );

    if(!*window) {
        LOG_ERROR("SDL_CreateWindow error: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer (*window, NULL);

    if(!*renderer) {
        LOG_ERROR("SDL_CreateRenderer error: %s", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    LOG_DEBUG("Initialize SDL resources succesful");

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

    LOG_DEBUG("Clean up SDL resources succesful");
}