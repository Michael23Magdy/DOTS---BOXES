#pragma once
#include "Game.h"
static const int box_sides_i[] = {-1,1,0,0};
static const int box_sides_j[] = {0,0,-1,1};
static const int line_to_box[] = {-1,1};

bool chain_box(Grid *grid, int player_signature, int line_i_idx, int line_j_idx);