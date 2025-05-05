void drawAndMoveBlob(char board[100][1000] , int& row , int& col , int startCol , int endCol , int &direction , int & isJumping){
    
    if (col <= startCol) {
        direction = 1; 
    } else if (col >= endCol) {
        direction = 2; 
    }

    if (direction == 1) {
        if(!isJumping){
            row--;
            col++;
            isJumping =1;
        } else {
            row++;
            col++;
            isJumping =0;
        }
        
    } else if (direction == 2) {
        if(!isJumping){
            row--;
            col--;
            isJumping =1;
        } else {
            row++;
            col--;
            isJumping =0;
        }
        
    }



    if (direction == 1) {
        board[row][col+3] = '|';
        board[row][col+4] = '_';
        board[row][col+5] = '|';

        board[row][col+8] = '|';
        board[row][col+9] = '_';
        board[row][col+10] = '|';

        board[row-1][col] = '`';
        board[row-1][col+2] = '\\';
        board[row-1][col+3] = '_';
        board[row-1][col+4] = '_';
        board[row-1][col+5] = '_';
        board[row-1][col+6] = '_';
        board[row-1][col+7] = '_';
        board[row-1][col+8] = '_';
        board[row-1][col+9] = '_';
        board[row-1][col+10] = '_';
        board[row-1][col+11] = '/';

    
        board[row-2][col+1] = '/';
        board[row-2][col+2] = '|';
        board[row-2][col+3] = ' ';
        board[row-2][col+4] = ' ';
        board[row-2][col+5] = ' ';
        board[row-2][col+6] = ' ';
        board[row-2][col+7] = '_';
        board[row-2][col+8] = '_';
        board[row-2][col+9] = '_';
        board[row-2][col+10] = ' ';
        board[row-2][col+11] = '|';
 
        
        board[row-3][col+2] = '|';
        board[row-3][col+3] = ' ';
        board[row-3][col+4] = ' ';
        board[row-3][col+5] = ' ';
        board[row-3][col+6] = ' ';
        board[row-3][col+7] = 'O';
        board[row-3][col+8] = ' ';
        board[row-3][col+9] = 'O';
        board[row-3][col+10] = ' ';
        board[row-3][col+11] = '|';
        board[row-3][col+12] = '/';

        board[row-4][col+3] = '/';
        board[row-4][col+4] = ' ';
        board[row-4][col+5] = ' ';
        board[row-4][col+6] = ' ';
        board[row-4][col+7] = ' ';
        board[row-4][col+8] = ' ';
        board[row-4][col+9] = ' ';
        board[row-4][col+10] = '\\';
        board[row-4][col+13] = '|';
        
        board[row-5][col+4] = '_';
        board[row-5][col+5] = '_';
        board[row-5][col+6] = '_';
        board[row-5][col+7] = '_';
        board[row-5][col+8] = '_';
        board[row-5][col+9] = '_';
    
    
    }
    
    
    else if (direction == 2) {
    
        
        board[row][col+3] = '|';
        board[row][col+4] = '_';
        board[row][col+5] = '|';

        board[row][col+8] = '|';
        board[row][col+9] = '_';
        board[row][col+10] = '|';

        board[row-1][col+2] = '\\';
        board[row-1][col+3] = '_';
        board[row-1][col+4] = '_';
        board[row-1][col+5] = '_';
        board[row-1][col+6] = '_';
        board[row-1][col+7] = '_';
        board[row-1][col+8] = '_';
        board[row-1][col+9] = '_';
        board[row-1][col+10] = '_';
        board[row-1][col+11] = '/';

        board[row-1][col+13] = '`';
    

        board[row-2][col+2] = '|';
        board[row-2][col+3] = ' ';
        board[row-2][col+4] = '_';
        board[row-2][col+5] = '_';
        board[row-2][col+6] = '_';
        board[row-2][col+7] = ' ';
        board[row-2][col+8] = ' ';
        board[row-2][col+9] = ' ';
        board[row-2][col+10] = ' ';
        board[row-2][col+11] = '|';
        board[row-2][col+12] = '\\';

        
        board[row-3][col+1] = '\\';
        board[row-3][col+2] = '|';
        board[row-3][col+3] = ' ';
        board[row-3][col+4] = 'O';
        board[row-3][col+5] = ' ';
        board[row-3][col+6] = 'O';
        board[row-3][col+7] = ' ';
        board[row-3][col+8] = ' ';
        board[row-3][col+9] = ' ';
        board[row-3][col+10] = ' ';
        board[row-3][col+11] = '|';

        board[row-4][col] = '|';
        board[row-4][col+3] = '/';
        board[row-4][col+4] = ' ';
        board[row-4][col+5] = ' ';
        board[row-4][col+6] = ' ';
        board[row-4][col+7] = ' ';
        board[row-4][col+8] = ' ';
        board[row-4][col+9] = ' ';
        board[row-4][col+10] = '\\';
        
        board[row-5][col+4] = '_';
        board[row-5][col+5] = '_';
        board[row-5][col+6] = '_';
        board[row-5][col+7] = '_';
        board[row-5][col+8] = '_';
        board[row-5][col+9] = '_';
    


    }

}