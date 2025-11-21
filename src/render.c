#include <SDL3/SDL.h>
#include "init.h"
#include "render.h"
#include "maze.h"

void RenderBackground(SDL_Renderer *renderer) {
    SDL_FRect rect;

    for (int y = 0; y < GRID_H; y++) {
        for (int x = 0; x < GRID_W; x++) {
            if (grid[y][x] == 1) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Dinding putih
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Jalan hitam
            }

            rect.y = (float)y * TILE;
            rect.x = (float)x * TILE;
            rect.h = (float)TILE;
            rect.w = (float)TILE;

            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void UpdateFrame(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
    RenderBackground(renderer);
    SDL_RenderPresent(renderer);
}