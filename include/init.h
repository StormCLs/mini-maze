#ifndef INIT_H
#define INIT_H

#include <SDL3/SDL.h>
#include <stdbool.h>

bool InitializeSDLResouces(SDL_Window **window, SDL_Renderer **renderer);
void CleanupSDLResources(SDL_Window *window, SDL_Renderer *renderer);

#endif