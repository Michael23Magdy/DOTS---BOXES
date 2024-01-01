#pragma once
#include "Player.h"
#include "Grid.h"
#include "Print_Patterns.h"
#include "ANSI-color-codes.h"
#include "file_handling.h"
#include "top10.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Game(Grid *grid, Player player_1 , Player player_2, int size,TopTenPlayers *top_10);
static const int LINE_BOXES_COVERAGE = 2 ;
static const int LINE_REMAINING_SIDES = 3 ;

static const int dir_array_i[2][2][3] = 
{
    {{1,1,2}  ,{-2,-1,-1}} ,//down up
    {{0,-1,1},{0,-1,1}}
} ;
static const int dir_array_j[2][2][3] = 
{
    {{-1,1,0} ,{0,-1,1}},
    {{2,1,1},{-2,-1,-1}} // r l
} ;