#include <SDL3/SDL.h>
#include <stdbool.h>
#include "input.h"
#include "player.h"
#include "maze.h"

bool HandleInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false;
        }

        PlayerInput(&event);
    }

    return true;
}

void PlayerInput(SDL_Event *event) {
    if (event->type != SDL_EVENT_KEY_DOWN) return;

    SDL_Scancode sc = event->key.scancode;

    int dy = 0, dx = 0;

    if (sc == SDL_SCANCODE_W || sc == SDL_SCANCODE_UP)
        dy = -1;

    else if (sc == SDL_SCANCODE_S || sc == SDL_SCANCODE_DOWN)
        dy = 1;

    else if (sc == SDL_SCANCODE_A || sc == SDL_SCANCODE_LEFT)
        dx = -1;

    else if (sc == SDL_SCANCODE_D || sc == SDL_SCANCODE_RIGHT)
        dx = 1;

    int newY = player.y + dy;
    int newX = player.x + dx;

    if (grid[newY][newX] != 1) {
        player.y = newY;
        player.x = newX;
    }
}
