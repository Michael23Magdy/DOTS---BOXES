#pragma once

#include"Grid.h"
#include "stdbool.h"


void save_data(Grid *grid,int file_num,Player *player1,Player *player2);
bool load_data(Grid *grid,int file_num,Player *player1,Player *player2);
