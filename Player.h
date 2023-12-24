#pragma
#include <stdio.h>
#include <string.h>
#include "ANSI-color-codes.h"
#define MAx_STR 50

typedef struct 
{
    char name[MAx_STR];
    int num;
    int score;
    int computer;
}Player ;

Player init_player(int computer,int num);
void readLine(char str[]);
void print_player(Player player);