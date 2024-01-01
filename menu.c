#include "menu.h"
#include "Print_Patterns.h"
#include "ANSI-color-codes.h"
#include "Game.h"
#include"file_handling.h"
#include <stdio.h>
#include <stdlib.h>
int get_input(){
    int saved_num;
    do{ 
        printf(BHGRN"Choose saved number (1-5): ");
        if (scanf("%d", &saved_num) != 1) {
            while (getchar() != '\n');  
        }
        } while(!(saved_num <= 5 || saved_num >= 1 || saved_num == -1));
    return saved_num;
}
void menu(TopTenPlayers *top_10){
    // Print menu

    printGameName();
    printf(BHMAG"MENU ( choose a number )\n");
    printf(MAG"1- New Game\n");
    printf(MAG"2- Load Game\n");
    printf(MAG"3- Rankings\n");
    printf(MAG"4- Exit\n");
    
    // Get choice
    int operation ;
    do{ 
        printf(BHMAG"Choose: " reset);
        if (scanf("%d", &operation) != 1) {
            // Invalid input (not an integer)
            while (getchar() != '\n');  // Clear input buffer
        }
    } while(operation != 1 && operation != 2 && operation != 3 && operation != 4);
    //printf("The larger filled circle symbol is: %lc\n", L'\x2B24');
    if(operation <= 2){
        Grid grid ;
        if (operation == 1)
            {
                if (!new_game_menu(&grid,top_10))
                    return ;
            }
        else 
            {
                Player player_one,player_two ;
                int saved_num = get_input() ;

                while(true) 
                {
                    if (saved_num == -1) return;
                    if (load_data(&grid,saved_num,&player_one,&player_two))
                        break;
                    printf("Can't load this file\n") ;
                    saved_num = get_input() ;
                }

                Game(&grid,player_one,player_two,grid.size,top_10);
            }
        free_grid(&grid);

    }
    if(operation == 3){
        if (load_top10_data(top_10))
            print_top_players(top_10) ;
        else 
            printf("Error opening file for reading.\n");

        system("pause") ;
    }

    if(operation == 4){
        // EXIT GAME
        printGoodBye();
        exit(0);
    };
}

bool new_game_menu(Grid *grid,TopTenPlayers *top_10){
    // Input Game Properties
    int game_size;          // min = 2 , max = 6
    int game_mood;          // Human VS Human OR Human VS Computer
    int game_diff = 0;      // 1 for easy - 2 for hard - 0 no computer


    // GAME SIZE
    do{ 
        printf(BHGRN"Choose Game Size (2-6): ");
        if (scanf("%d", &game_size) != 1) {
            // Invalid input (not an integer)
            while (getchar() != '\n');  // Clear input buffer
        }
    } while(game_size < 2 || game_size > 6);


    // GAME MOOD
    printf(BHBLU"Choose Game Mood:\n");
    printf(BLU"1- Human VS Human\n");
    printf(BLU"2- Human VS Computer\n");
    do{ 
        printf(BHBLU"Choose: " reset);
        if (scanf("%d", &game_mood) != 1) {
            // Invalid input (not an integer)
            while (getchar() != '\n');  // Clear input buffer
        }
    } while(game_mood != 1 && game_mood != 2);

    // Players
    
    Player player_1 = init_player(0,1);
    Player player_2 = init_player(game_diff,2);
    
    int start;
    printf(MAG"1- Start Game\n");
    printf(MAG"2- Back to menu\n");
    do{ 
        printf(BHMAG"Choose: " reset);
        if (scanf("%d", &start) != 1) {
            // Invalid input (not an integer)
            while (getchar() != '\n');  // Clear input buffer
        }
    } while(start != 1 && start != 2);


    if (start == 1) {
        init_grid(grid,game_size) ;
        Game(grid,player_1,player_2,game_size,top_10);
        return true ;
    }
    return false ;
}