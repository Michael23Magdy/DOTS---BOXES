#include "Game.h"
#include <time.h>
#include <stdlib.h>
static const int LINE_BOXES_COVERAGE = 2 ;
static const int LINE_REMAINING_SIDES = 3 ;
void update_grid_squares(Grid *grid , int player_signature,int i,int j,int dir){
    if (i%2) 
        grid->board[i][j + (dir ? -1 : 1)] = player_signature ;

    else 
        grid->board[i + (dir ? -1 : 1)][j] = player_signature ;  
}
int get_random_num(int end){
    return (rand() % end) + 1 ;
}
void Game(Player player_1, Player player_2, int size){
    Grid grid;
    init_grid(&grid, size);
    int is_player1_turn=1;  //player 1 = 1 //player 2 = 0

    srand(time(NULL));


    int dir_array_i[2][LINE_BOXES_COVERAGE][LINE_REMAINING_SIDES] = 
    {
        {{1,1,2}  ,{-2,-1,-1}} ,//down up
        {{0,-1,1},{0,-1,1}}
    } ;
    int dir_array_j[2][LINE_BOXES_COVERAGE][LINE_REMAINING_SIDES] = 
    {
        {{-1,1,0} ,{0,-1,1}},
        {{2,1,1},{-2,-1,-1}} // r l
    } ;
    int line_i_idx , line_j_idx ;
    bool is_turnable = false ;
    int lines_cnt = 2*(size*(size+1)) ;
    int elements_cnt_in_row = 2*size + 1;
    bool is_system_updated = true ;
    while (1)
    {
        if (is_system_updated)
        {
            system("cls");
            printGameName();
            print_player(player_1);
            print_player(player_2);
            Print_grid(&grid);
        }
        else 
            is_system_updated = true ;
        if (grid.num_boxes == 0)
        {
            printWinner();
            system("pause");
            break;
        }
        
        int line_num;
        if (!is_player1_turn && player_2.computer == 1)
            line_num = get_random_num(lines_cnt) ;
        else
            scanf("%d", &line_num);


        if (line_num < 1 || line_num > lines_cnt) 
            {
                printf("invalid line number enter a number between 1 - %d\n",lines_cnt);
                system("pause");
                continue; //pause
            }

        line_i_idx = (2*((line_num-1)/elements_cnt_in_row));
        if (!((line_num-1) % (elements_cnt_in_row) + 1 > size))
            {
                line_j_idx = (2*(line_num%(elements_cnt_in_row))-1);
            }
        else 
            {
                line_i_idx += 1 ;
                line_j_idx = 2*((line_num-1)%(elements_cnt_in_row) - size) ;
            }

        
        if (grid.board[line_i_idx][line_j_idx] == -1 || grid.board[line_i_idx][line_j_idx] == -2 )
            {
                if (is_player1_turn || player_2.computer != 1)
                {
                    printf("this line is taken before\n");
                }
                is_system_updated =false ;
                continue; 
            }
        grid.board[line_i_idx][line_j_idx] = (is_player1_turn ? -1 : -2) ;
        grid.num_lines-- ;
        bool is_vertical_line = line_i_idx % 2 ;
        for (int i = 0; i < LINE_BOXES_COVERAGE; i++)
        {
            bool is_closed = 1 ;
            for (int j = 0; j < LINE_REMAINING_SIDES; j++)
            {
                int tmp_i = line_i_idx + dir_array_i[is_vertical_line][i][j] ;
                int tmp_j = line_j_idx + dir_array_j[is_vertical_line][i][j] ;

                if (tmp_i < 0 || tmp_i >= elements_cnt_in_row||
                    tmp_j < 0 || tmp_j >= elements_cnt_in_row) 
                    {
                        is_closed = 0 ;
                        break;
                    }
                is_closed &= (grid.board[tmp_i][tmp_j] == -1 || grid.board[tmp_i][tmp_j] == -2) ;
            }
            if (is_closed)
            {
                grid.num_boxes-- ;
                is_turnable = true ;
                if (is_player1_turn)
                    {
                        player_1.score++ ;
                        update_grid_squares(&grid,-player_1.num,line_i_idx,line_j_idx,i) ;
                        
                    }
                else 
                    {
                        player_2.score++ ;
                        update_grid_squares(&grid,-player_2.num,line_i_idx,line_j_idx,i) ;
                    }
            }
        }
        if (!is_turnable)
            is_player1_turn = !is_player1_turn ;
        is_turnable = false ;
    }
    free_grid(&grid);
}