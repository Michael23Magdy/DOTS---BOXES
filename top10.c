#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "top10.h"

void add_player(TopTenPlayers *top10, Player *player) {
    player->top_players_rank = ++(top10->players_added_cnt) ;
    if (top10->players_cnt < MAX_PLAYERS) {
        {
            top10->players_list[top10->players_cnt++] = *player;
        }

    } else {
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (player->score > top10->players_list[i].score) {
                shift_right(top10, i);
                top10->players_list[i] = *player;
                break;
            }
        }
    }
    sort(top10) ;
}

void print_top_players(TopTenPlayers *top10) {
    printf("Top 10 Players:\n");
    for (int i = 0; i < top10->players_cnt; ++i) {
        printf("%d. %s %d\n", i + 1, top10->players_list[i].name,top10->players_list[i].score);
    }
}

void shift_right(TopTenPlayers *top10, int idx) {
    for (int i = MAX_PLAYERS - 1; i > idx; i--) {
        top10->players_list[i] = top10->players_list[i - 1];
    }
}

int compare_score(const void *a, const void *b) {
    int diff = ((const Player *)b)->score - ((const Player *)a)->score ;
    
    if (!diff)
        return  ((const Player *)a)->top_players_rank - ((const Player *)b)->top_players_rank  ;
    
    return diff ;
}

void sort(TopTenPlayers *top10) {
    qsort(top10->players_list, top10->players_cnt, sizeof(Player), compare_score);
}

void save_top10_data(TopTenPlayers *top10) {
    FILE *file = fopen("saved_data//topPlayers.bin", "wb+");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(top10, sizeof(TopTenPlayers), 1, file);

    fclose(file);
}

bool load_top10_data(TopTenPlayers *top10) {
    FILE *file = fopen("saved_data//topPlayers.bin", "rb+");

    if (file == NULL) {
        return false;
    }

    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Error setting file pointer");
        fclose(file);
        return false;
    }

    fread(top10, sizeof(TopTenPlayers), 1, file);

    fclose(file);
    return true;
}
