#include "Chain.h"

bool chain_box(Grid *grid, int player_signature, int line_i_idx, int line_j_idx){
    //Print_grid(grid);
    //system("pause");
    int elements_cnt_in_row = 2*grid->size + 1;
    for (int k = 0; k < LINE_BOXES_COVERAGE; k++)
    {
        bool is_vertical_line = line_i_idx % 2 ;
        int i,j;
        if (is_vertical_line) {
            i = line_i_idx;
            j = line_j_idx + line_to_box[k];
        }
        else{
            i = line_i_idx + line_to_box[k];
            j = line_j_idx;
        } 
        if (i < 0 || i >= elements_cnt_in_row||
            j < 0 || j >= elements_cnt_in_row) 
            return 0;
        if (grid->board[i][j] < 0)
            continue;
        
        grid->board[i][j] = player_signature;
        grid->num_boxes--;
        
        bool is_chained = 1;
        for (int k = 0; k < 4; k++)
        {
            int new_line_i = i + box_sides_i[k];
            int new_line_j = j + box_sides_j[k];
            if (grid->board[new_line_i][new_line_j] < 0)
                continue;
            grid->board[new_line_i][new_line_j] = player_signature;
            grid->num_lines--;
            is_chained &= chain_box(grid,player_signature,new_line_i,new_line_j);
            if (!is_chained)
                break;
        }
        
        return is_chained;
    }
    return 0;
}