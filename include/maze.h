#ifndef MAZE_H
#define MAZE_H

#include "init.h"

typedef struct {
    int startX, startY;
    int endX, endY;
} Maze;

extern int grid[GRID_H][GRID_W];

void InitGrid();

#endif