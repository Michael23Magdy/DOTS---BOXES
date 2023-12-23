#pragma once
#include <stdio.h>
struct Grid
{
    int size;
    int **board;
    int num_boxes;
    int num_lines;
};

void init_grid(Grid *grid, int size);
void allocate_grid_memory(Grid *grid, size_t size);
void Print_grid(Grid *grid);