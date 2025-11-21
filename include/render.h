#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>

void RenderBackground(SDL_Renderer *renderer);
void RenderPlayer(SDL_Renderer *renderer);
void UpdateFrame(SDL_Renderer *renderer);

#endif