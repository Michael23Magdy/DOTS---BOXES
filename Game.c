#include "Game.h"

void Game(Player player_1, Player player_2, int size){
    system("cls");
    printGameName();
    Grid grid;
    init_grid(&grid, size);
    grid.board[0][1] = -1;
    grid.board[1][0] = -2;
    grid.board[2][1] = -1;
    grid.board[1][2] = -2;
    grid.board[1][1] = -2;
    Print_grid(&grid);

    int a;
    scanf("%d", &a);

    free_grid(&grid);
}