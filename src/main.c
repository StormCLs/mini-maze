#include <SDL3/SDL.h>
#include <stdlib.h>
#include "init.h"

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    InitializeSDLResouces(&window, &renderer);
    SDL_Delay(2000);
    CleanupSDLResources(window,renderer);

    return 0;
}