#include "Player.h"

Player init_player(int computer,int num){
    Player player;
    player.num = num;
    if (player.num == 1)
        printf(BLU"Player %d Name: ", num);
    if (player.num == 2)
        printf(RED"Player %d Name: ", num);
    if (computer == 0)
        readLine(player.name);
    else {
        printf("Computer");
        strcpy(player.name, "Computer\n");
    }
    
    player.score = 0;
    player.computer = computer;

    return player;
}

void print_player(Player player){
    if (player.num == 1)
        printf(BLU"%s :%d\n", player.name, player.score);
    if (player.num == 2)
        printf(RED"%s :%d\n", player.name, player.score);
}

void readLine(char str[])
{
    
    int ch, i=0;
    while((ch=getchar()) == ' ');
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') str[i++] =ch ;
    while((ch=getchar()) != '\n')
    {
        if(i<MAx_STR)
        {
            str[i++]=ch;
        }
    }
    str[i]='\0';
}