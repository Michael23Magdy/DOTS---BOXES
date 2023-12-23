#include "Grid.h"
#include <stdio.h>
#include <stdlib.h>

void init_grid(Grid *grid, int size){
    grid->size = size;
    grid->num_boxes = size*size;
    grid->num_lines = (size+1)*size*2;
    int no_elements_row = (size_t)(size+size+1);

    allocate_grid_memory(grid,(size_t)no_elements_row);
    int counter = 1;
    for (int i = 0; i < no_elements_row; i++)
        for (int j = 0; j < no_elements_row; j++)
            if (i%2 != j%2) grid->board[i][j] = counter++;
            else grid->board[i][j] = 0;
            
        
}

void allocate_grid_memory(Grid *grid, size_t size){
    grid->board = (int**)malloc(size*sizeof(int*));
    for (size_t i = 0; i < size; i++)
        grid->board[i] = (int*)malloc(size*sizeof(int));
}

void Print_grid(Grid *grid){
    printf("%d %d\n", grid->size,grid->num_boxes);
    for (int i = 0; i <= 2*grid->size+1; i++){
        for (int j = 0; j < 2*grid->size+1; j++)
            printf("%d", grid->board[i][j]);
        printf("\n");
    }
        
    
}