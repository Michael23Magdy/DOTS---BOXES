#pragma once

#include"Player.h"
#include"stdbool.h"
#define MAX_PLAYERS 10

typedef struct {
    Player players_list[MAX_PLAYERS];
    int players_cnt;
    int players_added_cnt ;
} TopTenPlayers;

bool add_player(TopTenPlayers *top10, Player *player);
void print_top_players(TopTenPlayers *top10);
void shift_right(TopTenPlayers *top10, int idx);
int compare_score(const void *a, const void *b);
void sort(TopTenPlayers *top10);

void save_top10_data(TopTenPlayers *top10);
bool load_top10_data(TopTenPlayers *top10);
