#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int y, x;
} Player;

extern Player player;

void PlayerInit();

#endif