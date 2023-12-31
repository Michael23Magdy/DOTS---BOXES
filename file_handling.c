#include <stdio.h>
#include <math.h>
#include "Player.h"
#include "Grid.h"
#include <stdbool.h>
#include "file_handling.h"

char file_pathes[5][100] = {
    "saved_data//1.bin",
    "saved_data//2.bin",
    "saved_data//3.bin",
    "saved_data//4.bin",
    "saved_data//5.bin",
};

void save_data(Grid *grid, int file_num, Player *player1, Player *player2) {
    FILE *file = fopen(file_pathes[file_num - 1], "wb+");

    if (file == NULL) {
        printf("Error opening file %s for writing.\n", file_pathes[file_num - 1]);
        return;
    }
    fwrite(grid, sizeof(Grid), 1, file);
    for (int i = 0; i < (2*grid->size + 1); i++)
    {
        fwrite(grid->board[i], sizeof(int) , 2*grid->size + 1, file);
    }
    
    fwrite(player1, sizeof(Player), 1, file);
    fwrite(player2, sizeof(Player), 1, file);

    fclose(file);
}

bool load_data(Grid *grid, int file_num, Player *player1, Player *player2) {
    FILE *file = fopen(file_pathes[file_num - 1], "rb+");

    if (file == NULL) {
        return false;
    }

    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Error setting file pointer");
        fclose(file);
        return false;
    }

    fread(grid, sizeof(Grid), 1, file);
    allocate_grid_memory(grid,grid->size) ;
    for (int i = 0; i < (2*grid->size + 1); i++)
        {
            fread(grid->board[i], sizeof(int) , 2*grid->size + 1, file);
        }

    fread(player1, sizeof(Player), 1, file);
    fread(player2, sizeof(Player), 1, file);

    fclose(file);
    return true;
}
