#ifndef INIT_H
#define INIT_H

#include <SDL3/SDL.h>
#include <stdbool.h>

#define TILE 32
#define GRID_H 21
#define GRID_W 21

extern const int WindowSize[2];

bool InitializeSDLResouces(SDL_Window **window, SDL_Renderer **renderer);
void CleanupSDLResources(SDL_Window *window, SDL_Renderer *renderer);

#endif