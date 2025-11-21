#include "debug.h"
#include "maze.h"
#include "init.h"

int grid[GRID_H][GRID_W];

void InitGrid() {
    for (int y = 0; y < GRID_H; y++) {
        for (int x = 0; x < GRID_W; x++) {
            grid[y][x] = 1;
        }
    }
    LOG_INFO("InitGrid: Initialized all grid cells to %d", grid[0][0]);
}

void Carve() {
    
}