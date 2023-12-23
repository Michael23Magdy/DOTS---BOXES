#pragma once
#include <stdio.h>
#include "ANSI-color-codes.h"
/*#include <wchar.h>
#include <locale.h>*/
struct Grid
{
    int size;
    int **board;
    int num_boxes;
    int num_lines;
};

void init_grid(Grid *grid, int size);
void allocate_grid_memory(Grid *grid, int size);
void free_grid(Grid *grid);
void Print_grid(Grid *grid);