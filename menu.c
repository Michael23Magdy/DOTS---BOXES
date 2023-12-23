#include "menu.h"
#include "Print_Patterns.h"
#include "ANSI-color-codes.h"
#include <stdio.h>
#include <stdlib.h>

void new_game_menu();

void menu(){
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
    printf("The larger filled circle symbol is: %lc\n", L'\x2B24');
    if(operation == 1){
        // NEW GAME
        new_game_menu();
    }
    
    if(operation == 2){
        // Load GAME

    }
    if(operation == 3){
        // VIEW RANKS

    }

    if(operation == 4){
        // EXIT GAME
        printGoodBye();
        exit(0);
    };
}

void new_game_menu(){
    // Input Game Properties
    int game_size;          // min = 2 , max = 7
    int game_mood;          // Human VS Human OR Human VS Computer
    int game_diff = 0;      // 1 for easy - 2 for hard - 0 no computer
    // GAME SIZE
    do{ 
        printf(BHGRN"Choose Game Size (2-7): ");
        if (scanf("%d", &game_size) != 1) {
            // Invalid input (not an integer)
            while (getchar() != '\n');  // Clear input buffer
        }
    } while(game_size < 2 || game_size > 7);


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

    // GAME diff
    if (game_mood==2){
        printf(BHRED"Choose Game Difficulty:\n");
        printf(RED"1- Easy\n");
        printf(RED"2- Hard\n");

        do{ 
            printf(BHRED"Choose: " reset);
            if (scanf("%d", &game_diff) != 1) {
                // Invalid input (not an integer)
                while (getchar() != '\n');  // Clear input buffer
            }
        } while(game_diff != 1 && game_diff != 2);
    }


    
    
    
}