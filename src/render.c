#include <SDL3/SDL.h>

void RenderBackground(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void UpdateFrame(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
    RenderBackground(renderer);
    SDL_RenderPresent(renderer);
}