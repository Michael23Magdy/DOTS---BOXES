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
        printf("Computer\n");
        strcpy(player.name, "Computer");
    }
    
    player.score = 0;
    player.num_moves = 0;
    player.computer = computer;

    return player;
}

void print_player(Player player){
    printf(player.num == 1 ? BLU"%s :%d" : RED"%s :%d", player.name, player.score);
    printf("\n--> Number of moves played: %d\n" reset, player.num_moves);
}

void readLine(char str[])
{
    
    int ch, i=0;
    while((ch=getchar()) == ' ');
    str[i++] =ch ;
    while((ch=getchar()) != '\n')
    {
        if(i<MAX_STR)
        {
            str[i++]=ch;
        }
    }
    str[i]='\0';
}