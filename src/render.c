#include <SDL3/SDL.h>
#include "debug.h"
#include "init.h"
#include "render.h"
#include "maze.h"

void RenderBackground(SDL_Renderer *renderer) {
    SDL_FRect rect;

    for (int y = 0; y < GRID_H; y++) {
        for (int x = 0; x < GRID_W; x++) {
            if (grid[y][x] == 1) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White wall
            } else if (grid[y][x] == 0) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black Road
            } else if (grid[y][x] == 2) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Player spawn point
            } else if (grid[y][x] == 3) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // End of the maze
            }

            rect.y = (float)y * TILE;
            rect.x = (float)x * TILE;
            rect.h = (float)TILE;
            rect.w = (float)TILE;

            SDL_RenderFillRect(renderer, &rect);

            if ((y + 1) % GRID_H == 0 && (x + 1) % 10 == 0) {
            }
        }
    }
}

void UpdateFrame(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
    RenderBackground(renderer);
    SDL_RenderPresent(renderer);
}