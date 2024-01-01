#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include"top10.h"

int main(){
    TopTenPlayers top_10 ;
    top_10.players_cnt = 0 ;
    top_10.players_added_cnt = 0 ;
    while(1)
    {
        system("cls");
        menu(&top_10);
    }
    return 0;
}