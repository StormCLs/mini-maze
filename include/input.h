#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL.h>
#include <stdbool.h>

bool HandleInput();
void PlayerInput(SDL_Event *event);

#endif