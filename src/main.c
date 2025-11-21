#include <SDL3/SDL.h>
#include <stdlib.h>
#include "init.h"
#include "debug.h"
#include "game.h"

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    InitializeSDLResouces(&window, &renderer);

    while (1) {
        if(!RunGameLoop()) {
            break;
        }
    }
    
    CleanupSDLResources(window,renderer);

    return 0;
}