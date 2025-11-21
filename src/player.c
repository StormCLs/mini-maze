#include "player.h"
#include "maze.h"

Player player;

void PlayerInit() {
    player.y = maze.startY;
    player.x = maze.startX;
}