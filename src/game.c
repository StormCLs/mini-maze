#include <SDL3/SDL.h>
#include <stdbool.h>
#include "debug.h"
#include "render.h"

const int targetFPS = 60;
const int frameDelay = 1000 / targetFPS;
Uint32 frameStart;
int frameTime;

bool RunGameLoop(SDL_Renderer *renderer) {
    SDL_Event event;
    bool running = true;
    int frame = 0;
    while(running) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if(event.type == SDL_EVENT_QUIT) {
                return false;
            }
        }
        UpdateFrame(renderer);

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