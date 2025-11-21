#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <stdbool.h>

void InitMazeGame();
bool RunGameLoop(SDL_Renderer *renderer);

#endif