#include <SDL3/SDL.h>
#include <stdlib.h>
#include <time.h>
#include "init.h"
#include "debug.h"
#include "game.h"

int main() {
    srand(time(NULL));
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(!InitializeSDLResouces(&window, &renderer)) 
        return 1;

    while (1) {
        if(!RunGameLoop(renderer)) {
            break;
        }
    }
    
    CleanupSDLResources(window,renderer);

    return 0;
}