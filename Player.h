#pragma
#include <stdio.h>
#include <string.h>
#include "ANSI-color-codes.h"
#define MAX_STR 50

typedef struct 
{
    char name[MAX_STR];
    int num;
    int num_moves;
    int score;
    int computer;
}Player ;

Player init_player(int computer,int num);
void readLine(char str[]);
void print_player(Player player);