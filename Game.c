#include "Game.h"

void Game(Player player_1, Player player_2, int size){
    Grid grid;
    init_grid(&grid, size);
    int player_turn=1;  //player 1 = 1 //player 2 = 0
    while (grid.num_boxes != 0)
    {
        system("cls");
        printGameName();
        print_player(player_1);
        print_player(player_2);
        Print_grid(&grid);
        system("pause");
        /*
        int choice;
        printf(MAG"1- Start Game\n");
        printf(MAG"2- Back to menu\n");
        do{ 
            printf(BHMAG"Choose: " reset);
            if (scanf("%d", &start) != 1) {
                // Invalid input (not an integer)
                while (getchar() != '\n');  // Clear input buffer
            }
        } while(start != 1 && start != 2);
        */
    }
    // i = (x%grid.no)
    

    int a;
    scanf("%d", &a);

    free_grid(&grid);
}