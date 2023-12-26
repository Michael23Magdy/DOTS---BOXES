#pragma once
#include <stdio.h>
#include "ANSI-color-codes.h"
/*#include <wchar.h>
#include <locale.h>*/
typedef struct 
{
    int size;
    int **board;
    int num_boxes;
    int num_lines;
} Grid;

void init_grid(Grid *grid, int size);
void copy_grid(Grid *src_grid, Grid *dist_grid);
void allocate_grid_memory(Grid *grid, int size);
void free_grid(Grid *grid);
void Print_grid(Grid *grid);