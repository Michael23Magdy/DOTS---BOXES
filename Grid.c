#include "Grid.h"
#include <stdio.h>
#include <stdlib.h>

void init_grid(Grid *grid, int size){
    grid->size = size;
    grid->num_boxes = size*size;
    grid->num_lines = (size+1)*size*2;
    grid->is_player1_turn = 1 ;
    size_t no_elements_row = (size_t)(size+size+1);

    allocate_grid_memory(grid,size);
    int counter = 1;
    for (int i = 0; i < no_elements_row; i++)
        for (int j = 0; j < no_elements_row; j++)
            if (i%2 != j%2) grid->board[i][j] = counter++;
            else grid->board[i][j] = 0;
            
        
}

void allocate_grid_memory(Grid *grid, int size){
    size_t no_elements_row = (size_t)(size+size+1);
    grid->board = (int**)malloc(no_elements_row*sizeof(int*));
    for (size_t i = 0; i < no_elements_row; i++)
        grid->board[i] = (int*)malloc(no_elements_row*sizeof(int));
}

void free_grid(Grid *grid) {
    int size = grid->size;
    size_t no_elements_row = (size_t)(size+size+1);
    // Free memory for each row
    for (size_t i = 0; i < no_elements_row; ++i) {
        free(grid->board[i]);
    }
    // Free memory for the rows
    free(grid->board);
}

void copy_grid(Grid *src_grid, Grid *dist_grid){
    int elements_cnt_in_row = 2*src_grid->size + 1;
    dist_grid->num_boxes=src_grid->num_boxes;
    dist_grid->num_lines=src_grid->num_lines;
    dist_grid->size=src_grid->size;
        for (int i = 0; i < elements_cnt_in_row; i++)
            for (int j = 0; j < elements_cnt_in_row; j++)
                dist_grid->board[i][j]=src_grid->board[i][j];
}

void Print_grid(Grid *grid){
    //setlocale(LC_CTYPE, "");
    //wchar_t big_circle = 0x2B24;
    //wchar_t middlescore = 0x2605;
    printf("                              ");
    printf(MAG"Boxes left: %d Lines left: %d\n", grid->num_boxes,grid->num_lines);
    for (int i = 0; i <= 2*grid->size; i++){
        if (i%2==0){       //horizontal 
            printf("                              ");
            for (int j = 0; j < 2*grid->size+1; j++)
                if (j%2==0)
                    printf(YELHB"  " reset);
                else 
                    if(grid->board[i][j]>=0)
                        printf("   %02d   ", grid->board[i][j]);
                    else if (grid->board[i][j] == -1)
                        printf(BLUB"        " reset);
                    else if (grid->board[i][j] == -2)
                        printf(REDB"        " reset);
        }      
        else{
            printf("                              ");
            for (int j = 0; j < 2*grid->size+1; j++){
                if (j%2==0){
                    if(grid->board[i][j]>=0)
                    printf("  ");
                    else if (grid->board[i][j] == -1)
                        printf(BLUB"  " reset);
                    else if (grid->board[i][j] == -2)
                        printf(REDB"  " reset);
                }
                else {
                    if(grid->board[i][j]>=0)
                        printf("        ");
                    else if (grid->board[i][j] == -1)
                        printf(BLUHB"        " reset);
                    else if (grid->board[i][j] == -2)
                        printf(REDHB"        " reset);
                }
                    
            }
            printf("\n");
            printf("                              ");
            for (int j = 0; j < 2*grid->size+1; j++){
                if (j%2==0){
                    if(grid->board[i][j]>=0)
                        printf("%02d", grid->board[i][j]);
                    else if (grid->board[i][j] == -1)
                        printf(BLUB"  " reset);
                    else if (grid->board[i][j] == -2)
                        printf(REDB"  " reset);
                }
                else {
                    if(grid->board[i][j]>=0)
                        printf("        ");
                    else if (grid->board[i][j] == -1)
                        printf(BLUHB"        " reset);
                    else if (grid->board[i][j] == -2)
                        printf(REDHB"        " reset);
                }
                    
            }
            printf("\n");
            printf("                              ");
            for (int j = 0; j < 2*grid->size+1; j++){
                if (j%2==0){
                    if(grid->board[i][j]>=0)
                        printf("  ");
                    else if (grid->board[i][j] == -1)
                        printf(BLUB"  " reset);
                    else if (grid->board[i][j] == -2)
                        printf(REDB"  " reset);
                }
                else {
                    if(grid->board[i][j]>=0)
                        printf("        ");
                    else if (grid->board[i][j] == -1)
                        printf(BLUHB"        " reset);
                    else if (grid->board[i][j] == -2)
                        printf(REDHB"        " reset);
                }
            }
        }
        printf("\n");
    }
}