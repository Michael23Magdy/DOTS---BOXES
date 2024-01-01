#include "Game.h"
#include "Chain.h"
#include <time.h>
#include <stdlib.h>


void update_grid_squares(Grid *grid , int player_signature,int i,int j,int dir){
    if (i%2) 
        grid->board[i][j + (dir ? -1 : 1)] = player_signature ;

    else 
        grid->board[i + (dir ? -1 : 1)][j] = player_signature ;  
}
int get_random_num(int end){
    return (rand() % end) + 1 ;
}
void print_time(clock_t start_time){
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    // Calculate minutes and seconds
    int minutes = (int)(elapsed_time / 60);
    int seconds = (int)(elapsed_time) % 60;
    printf(GRN"Time: %02d:%02d\n" reset, minutes, seconds);
}
void Game(Grid *grid,Player player_1, Player player_2, int size,TopTenPlayers *top_10){

    int is_player1_turn=grid->is_player1_turn;  //player 1 = 1 //player 2 = 0
    printf("%d\n",top_10->players_cnt) ;
    system("pause");

    srand(time(NULL));
    clock_t start_time = clock();

    
    int line_i_idx , line_j_idx ;
    bool is_turnable = true ;
    int lines_cnt = 2*(size*(size+1)) ;
    int elements_cnt_in_row = 2*size + 1;
    bool is_system_updated = true ;

    // Game history
    Player player1_history[grid->num_lines];
    Player player2_history[grid->num_lines];
    int player_turn_histoty[grid->num_lines];
    Grid grid_history[grid->num_lines];
    int current_state = 0;
    int max_state= 0;
    while (true)
    {
        // save move;
        if (is_player1_turn || player_2.computer==0){
            player1_history[current_state] = player_1;
            player2_history[current_state] = player_2;
            player_turn_histoty[current_state] = is_player1_turn;
            init_grid(&grid_history[current_state], size);
            copy_grid(grid,&grid_history[current_state]);
        }
        // if computer choose a valid move print the new grid
        if (is_system_updated)
        {
            system("cls");
            printGameName();
            print_player(player_1);
            print_player(player_2);
            print_time(start_time);
            Print_grid(grid);
        }
        else 
            is_system_updated = true ;

        // if game ended
        if (grid->num_boxes == 0)
        {
            if (player_1.score > player_2.score)
                add_player(top_10,&player_1) ;
            else if (player_2.score > player_1.score)
            {
                if (player_2.computer == 0)
                    add_player(top_10,&player_2) ;
            }
            save_top10_data(top_10);

            if (player_1.score==player_2.score)
                printDraw();
            else if (player_1.score>player_2.score){
                printf(BLU"\n%s is the\n" reset, player_1.name);
                printWinner();
            }
            else if (player_2.computer==0){
                printf(RED"\n%s is the\n" reset, player_2.name);
                printWinner();
            }
            else 
                printLoser();
            system("pause");
            break;
        }
        
        // require input from player
        if (is_player1_turn || player_2.computer==0)
        {
            printf(BMAG"\n0 -> Save Game | -1 -> Exit ");
            printf((current_state>0)?"| -2 -> Undo ":"");
            printf((current_state<max_state)?"| -3 -> Redo":"");
            printf("\nOR Enter %s's move: " reset, is_player1_turn? player_1.name: player_2.name);
        }
        
        
        // take input from player or computer
        int line_num=-10;
        

        if (!is_player1_turn && player_2.computer == 1)
            line_num = get_random_num(lines_cnt) ;
        else
            if (scanf("%d", &line_num) != 1)// Invalid input (not an integer)
                while (getchar() != '\n');  // Clear input buffer 
        
            //scanf("%d", &line_num);
        
        if (line_num==-1) return;   // Exit Game;
        else if (line_num==0) {
            int file_num ;
            do{ 
                printf(BHGRN"Choose saved number (1-5): ");
                if (scanf("%d", &file_num) != 1) {
                    while (getchar() != '\n');  
                }
            } while(file_num > 5 || file_num  < 1);
            grid->is_player1_turn = is_player1_turn ;
            save_data(grid,file_num,&player_1,&player_2) ;
            continue;
        }
        else if (line_num==-2 && current_state>0 || line_num==-3 && current_state<max_state){
            // undo and redo
            current_state+=(line_num==-2)? -1:1;
            player_1 = player1_history[current_state];
            player_2 = player2_history[current_state];
            is_player1_turn = player_turn_histoty[current_state];
            copy_grid(&grid_history[current_state],grid);
            continue;
        }
        
        
        // check line number validity
        if (line_num < 1 || line_num > lines_cnt) 
            {
                printf(RED"invalid line number enter a number between 1 - %d\n" reset,lines_cnt);
                system("pause");
                continue; //pause
            }

        // convert line number to coordinates
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

        // check coordinates validity
        if (grid->board[line_i_idx][line_j_idx] == -1 || grid->board[line_i_idx][line_j_idx] == -2 )
            {
                if (is_player1_turn || player_2.computer == 0)
                {
                    printf(RED "this line is taken before\n" reset);
                }
                is_system_updated =false ;
                continue; 
            }
        
        if (is_player1_turn)
            player_1.num_moves++;
        else
            player_2.num_moves++;
        
        // make move
        grid->board[line_i_idx][line_j_idx] = (is_player1_turn ? -1 : -2) ;
        grid->num_lines-- ;
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
                is_closed &= (grid->board[tmp_i][tmp_j] == -1 || grid->board[tmp_i][tmp_j] == -2) ;
            }
            if (is_closed)
            {
                grid->num_boxes-- ;
                is_turnable = false ;

                bool is_chained=0;
                Grid test_grid;
                init_grid(&test_grid, size);
                
                if (is_player1_turn)
                    {
                        update_grid_squares(grid,-player_1.num,line_i_idx,line_j_idx,i);
                        copy_grid(grid,&test_grid);
                        player_1.score++;
                        printf("%d %d\n", line_i_idx,line_j_idx);
                        is_chained = chain_box(&test_grid,-player_1.num,line_i_idx,line_j_idx);
                        player_1.score += is_chained*(grid->num_boxes - test_grid.num_boxes) ;
                    }
                else 
                    {
                        update_grid_squares(grid,-player_2.num,line_i_idx,line_j_idx,i) ;
                        copy_grid(grid,&test_grid);
                        player_2.score++;
                        printf("%d %d\n", line_i_idx,line_j_idx);
                        is_chained = chain_box(&test_grid,-player_2.num,line_i_idx,line_j_idx);
                        player_2.score += is_chained*(grid->num_boxes - test_grid.num_boxes) ;
                    }
                //Print_grid(&test_grid);
                if (is_chained)
                    copy_grid(&test_grid,grid);
                free_grid(&test_grid);
                //system("pause");
                break;
            }
        }



        if (is_turnable)
            is_player1_turn = !is_player1_turn ;
        is_turnable = true;

        // save move
        if (is_player1_turn || player_2.computer==0){
            current_state++;
            max_state= current_state;
        }
        
    }
    for (int i = 0; i < grid->num_lines; i++)
        free_grid(&grid_history[i]);
}

