#include <SDL3/SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debug.h"
#include "render.h"
#include "maze.h"
#include "player.h"
#include "input.h"

const int targetFPS = 60;
const int frameDelay = 1000 / targetFPS;
Uint32 frameStart;
int frameTime;

void InitMazeGame() {
    InitGrid();

    Uint8 sY = (rand() % 10) * 2 + 1;
    Uint8 sX = (rand() % 10) * 2 + 1;

    maze.startY = sY;
    maze.startX = sX;

    Carve(sY, sX);

    grid[maze.startY][maze.startX] = 2;
    LOG_INFO("Spawn point at [%d][%d]", maze.startY, maze.startX);
    
    grid[maze.endY][maze.endX] = 3;
    LOG_INFO("Exit point at [%d][%d]", maze.endY, maze.endX);
    
    LOG_INFO("The maze was succesfully deployed");

    PlayerInit();
}

bool RunGameLoop(SDL_Renderer *renderer) {
    bool running = true;
    int frame = 0;

    InitMazeGame();

    while(running) {
        frameStart = SDL_GetTicks();

        if (!HandleInput()) return false;

        UpdateFrame(renderer);

        if (grid[player.y][player.x] == 3) {
            break;
        }

        frameTime = SDL_GetTicks() - frameStart;
        frame++;

        if((frame % 120) == 0) {
            LOG_INFO("Loop ke-%d", frame / 120);
        }

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return true;
}