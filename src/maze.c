#include <stdlib.h>
#include "debug.h"
#include "maze.h"
#include "init.h"

int grid[GRID_H][GRID_W];

Maze maze;

void InitGrid() {
    for (int y = 0; y < GRID_H; y++) {
        for (int x = 0; x < GRID_W; x++) {
            grid[y][x] = 1;
        }
    }
    LOG_INFO("InitGrid: Initialized all grid cells to %d", grid[0][0]);
}

void ShuffleDir(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int r = rand() % n;
        int t = a[i];
        a[i] = a[r];
        a[r] = t;
    }
}

void Carve(int y, int x) {
    grid[y][x] = 0;

    maze.endY = y;
    maze.endX = x;

    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    int dirs[4] = {0, 1, 2, 3};

    ShuffleDir(dirs, 4);

    for (int i = 0; i < 4; i++) {
        int d = dirs[i];
        int ny = y + dirY[d] * 2;
        int nx = x + dirX[d] * 2;

        if (ny < 1 || nx < 1 || ny >= GRID_H - 1 || nx >= GRID_W - 1) continue;

        if (grid[ny][nx] == 1) {
            grid[y + dirY[d]][x + dirX[d]] = 0;
            Carve(ny, nx);
        }
    }
}